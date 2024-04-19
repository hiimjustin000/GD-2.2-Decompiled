#include "GJDropDownLayer.h"

/* Thanks Wylie :D */

class GJListLayer; /* TODO */

GJDropDownLayer::GJDropDownLayer() {
	m_endPosition = CCPointMake(0, 0);
	m_startPosition = CCPointMake(0, 0);
	m_buttonMenu = nullptr;
	m_listLayer = nullptr;
	m_controllerEnabled = false;
	m_internalLayer = nullptr;
	m_hidden = false;
	m_delegate = nullptr;
}

GJDropDownLayer::~GJDropDownLayer() {
	cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->decrementForcePrio(2);
}

void GJDropDownLayer::disableUI() {
	m_buttonMenu->setTouchEnabled(false);
}

void GJDropDownLayer::enableUI() {
	m_buttonMenu->setTouchEnabled(true);
}

void GJDropDownLayer::draw() {
	if (getOpacity())
		draw();
}

void GJDropDownLayer::enterLayer() {
	enableUI();
	showLayer(false);
}

void GJDropDownLayer::exitLayer(cocos2d::CCObject* p) {
	setKeypadEnabled(false);
	cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->setForcePrio(false);
	disableUI();
	hideLayer(false);
}

void GJDropDownLayer::hideLayer(bool instantHide) {
	if (m_hidden) {
		if (m_delegate)
			m_delegate->dropDownLayerWillClose();
	}

	m_internalLayer->stopAllActions();

	if (instantHide) {
		m_internalLayer->setPosition(m_startPosition);
		setOpacity(0);
		layerHidden();
	}
	else {
		auto action = cocos2d::CCEaseInOut::create(cocos2d::CCMoveTo::create(0.5, m_startPosition), 2.);
		auto callback = cocos2d::CCCallFunc::create(this, callfunc_selector(GJDropDownLayer::exitLayer));
		auto seq = cocos2d::CCSequence::create(action, callback);
		m_internalLayer->runAction(seq);
		runAction(cocos2d::CCFadeTo::create(0.5, 0));
	}
}

void GJDropDownLayer::registerWithTouchDispatcher() {
	cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -500, true);
}

void GJDropDownLayer::keyBackClicked() {
	exitLayer(nullptr);
}

void GJDropDownLayer::layerHidden() {
	setVisible(false);
	if (m_hidden)
		removeFromParentAndCleanup(true);
}

void GJDropDownLayer::layerVisible() {
	setVisible(true);
}

void GJDropDownLayer::showLayer(bool instant) {
	m_internalLayer->stopAllActions();
	layerVisible();

	if (instant) {
		m_internalLayer->setPosition(m_endPosition);
		setOpacity(125);
		enterAnimFinished();
	}
	else {
		auto action = cocos2d::CCEaseInOut::create(cocos2d::CCMoveTo::create(0.5f, m_endPosition), 2.f);
		auto callback = cocos2d::CCCallFunc::create(this, callfunc_selector(GJDropDownLayer::enterLayer));
		m_internalLayer->runAction(cocos2d::CCSequence::create(action, callback));
		setOpacity(0);
		runAction(cocos2d::CCFadeTo::create(0.5f, 125));
	}
}

GJDropDownLayer* GJDropDownLayer::create(const char* title, float height) {
	auto pRet = new GJDropDownLayer();

	if (pRet && pRet->init(title, height)) {
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

GJDropDownLayer* GJDropDownLayer::create(const char* title) {
	return GJDropDownLayer::create(title, 220);
}

bool GJDropDownLayer::init(const char* title) {
	return init(title, 220);
}


bool GJDropDownLayer::init(const char* title, float height) {
	cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->incrementForcePrio(2);

	if (!initWithColor({ 0, 0, 0, 125 }))
		return false;

	setTouchEnabled(true);
	setKeypadEnabled(true);
	setKeyboardEnabled(true);

	auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
	
	m_internalLayer = cocos2d::CCLayer::create();
	addChild(m_internalLayer);

	m_endPosition = CCPointMake(0, 0);
	m_startPosition = CCPointMake(0, winSize.height);

	m_internalLayer->setPosition(m_startPosition);

	m_listLayer = GJListLayer::create(nullptr, title, cocos2d::ccc4(0, 0, 0, 180), 356.0, height); // it shows -76 in decomp but 0xB4 in asm so i guess its 0xB4 :P
	m_internalLayer->addChild(m_listLayer);

	m_listLayer->setPosition(CCPointMake((winSize.width - 356.0) * 0.5, (((winSize.height - height) * 0.5) - 10.0) + 5.0));

	auto spr = cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
	auto btn = CCMenuItemSpriteExtra::create(spr, nullptr, this, menu_selector(GJDropDownLayer::exitLayer)); // not sure about GJDropDownLayer::exitLayer, again &stru_274.st_value
	btn->setSizeMult(1.6);

	m_buttonMenu = cocos2d::CCMenu::create(btn);
	m_buttonMenu->setPosition(CCPointMake((winSize.width * 0.5) + 178.0, (winSize.height * 0.5) - (height * 0.5)));

	//that doesnt make sense wtf

	auto director = cocos2d::CCDirector::sharedDirector();
	m_buttonMenu->setPosition(CCPointMake(director->getScreenLeft() + 24, director->getScreenTop() - 23));

	m_internalLayer->addChild(m_buttonMenu, 10);

	auto chain1 = cocos2d::CCSprite::createWithSpriteFrameName("chain_01_001.png");
	m_internalLayer->addChild(chain1, -1);
	chain1->setAnchorPoint({ 0.5, 0.0 });
	chain1->setPosition({ (winSize.width * 0.5) - 156.0, height + m_listLayer->getPosition().y + 12.0 });
	chain1->setTag(0);

	auto chain2 = cocos2d::CCSprite::createWithSpriteFrameName("chain_01_001.png");
	m_internalLayer->addChild(chain2, -1);
	chain2->setAnchorPoint(CCPointMake(0.5, 0.0));
	chain2->setPosition(CCPointMake((winSize.width * 0.5) + 156.0, height + m_listLayer->getPosition().y + 12.0));
	chain2->setTag(1);

	m_hidden = false;
	hideLayer(true);
	m_hidden = true;

	customSetup();

	if (PlatformToolbox::isControllerConnected() && !m_controllerEnabled)
		GameToolbox::addBackButton(m_internalLayer, btn);

	return true;
}
