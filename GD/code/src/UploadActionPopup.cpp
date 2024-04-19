
#include "includes.h"


UploadActionPopup* UploadActionPopup::create(UploadPopupDelegate* delegate, std::string str){
    UploadActionPopup* popup = new UploadActionPopup;
    if (popup != nullptr && popup->init(delegate, str)){
        popup->autorelease();
        return popup;
    }
    CC_SAFE_DELETE(popup);
    return nullptr;
}

void UploadActionPopup::closePopup(){
    setKeypadEnabled(true);
    removeFromParentAndCleanup(true);
}

bool UploadActionPopup::init(UploadPopupDelegate* delegate, std::string str){
  
    if (initWithColor(cocos2d::ccc4(0, 0 , 0, 0x96))){
        incrementForcePrio();

        m_delegate = delegate;

        /* Enable Touchpad and Keypad */
        setTouchEnabled(true);
        setKeypadEnabled(true);

        /* winSize will be needed throught this function... */    
        cocos2d::CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

        m_mainLayer = cocos2d::CCLayer::create();
        addChild(m_mainLayer);
        cocos2d::extension::CCScale9Sprite * scaleSprite = cocos2d::extension::CCScale9Sprite::create("GJ_square02.png", CCRectMake(0.0, 0.0, 80.0, winSize.height));
        scaleSprite->setContentSize(CCSizeMake(200.0f, 100.0f));
        m_mainLayer->addChild(scaleSprite, -1);
        
        scaleSprite->setPosition(CCPointMake(winSize.width * 0.5, winSize.height * 0.5));
        m_buttonMenu = cocos2d::CCMenu::create();
        m_mainLayer->addChild(m_buttonMenu, 10);
        
        m_textArea = TextArea::create(str,"chatFont.fnt", 1.0f, 400.0f, CCPointMake(0.5f, 1.0f), 20.0f, false);
        m_mainLayer->addChild(m_textArea);
        m_textArea->setPosition(CCPointMake(winSize.width * 0.5f, winSize.height * 0.5f - 20.0f));
        m_textArea->setScale(0.8);
        m_joystickConnected = -1;

        m_loadingCircle->m_layer = m_mainLayer;
        m_loadingCircle = this->m_loadingCircle;
        m_loadingCircle->m_needsRendering = false;
        m_loadingCircle->setScale(.7);
        m_loadingCircle->show();

        m_loadingCircle->m_sprite->setPosition(CCPointMake(winSize.width * 0.5f, winSize.height * 0.5f + 14.0));
        m_loadingCircle->m_sprite = cocos2d::CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png" );
        m_loadingCircle->m_sprite->setScale(.8f);

        m_menuItemSpriteExtra = CCMenuItemSpriteExtra::create(m_loadingCircle->m_sprite,nullptr, this, static_cast<cocos2d::SEL_MenuHandler>(onClose));
        m_menuItemSpriteExtra->setSizeMult(1.6f);
        m_menuItemSpriteExtra->setPosition(m_buttonMenu->convertToNodeSpace(CCPointMake((winSize.width * 0.5f - 100.0f) + 5.0f, (winSize.height * 0.5f + 50.0f) - 5.0f  )));
        return true;
    }
    return false;
}


void UploadActionPopup::keyBackClicked()
{
    onClose(nullptr);
}

void UploadActionPopup::onClose(cocos2d::CCObject *sender)
{
    if (m_delegate != nullptr) m_delegate->onClosePopup(this);
    closePopup();
}



void UploadActionPopup::showFailMessage(std::string message)
{
    cocos2d::CCSprite* sprite = cocos2d::CCSprite::createWithSpriteFrameName("exMark_001.png");
    sprite->setPosition(m_loadingCircle->m_sprite->getPosition());
    m_mainLayer->addChild(sprite);
    m_loadingCircle->fadeAndRemove();
    m_textArea->setString(message); 
    m_succeeded = false;
}



void UploadActionPopup::showSuccessMessage(std::string message)
{
    cocos2d::CCSprite* sprite = cocos2d::CCSprite::createWithSpriteFrameName("exMark_001.png");
    sprite->setPosition(m_loadingCircle->m_sprite->getPosition());
    m_mainLayer->addChild(sprite);
    m_loadingCircle->fadeAndRemove();
    m_textArea->setString(message); 
    m_succeeded = true;
}


