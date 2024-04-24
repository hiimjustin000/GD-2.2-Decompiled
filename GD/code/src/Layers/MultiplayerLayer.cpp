#include "includes.h"

/* Likely A Loding Transition Class of some kind? */

MultiplayerLayer* MultiplayerLayer::create(){
    MultiplayerLayer* MPL = new MultiplayerLayer;
    if (MPL != nullptr && MPL->init()){
        MPL->autorelease();
        return MPL;
    }
    CC_SAFE_DELETE(MPL);
    return nullptr;
}

bool MultiplayerLayer::init(){
{
    cocos2d::CCDirector* director = cocos2d::CCDirector::sharedDirector();
    if (director != nullptr) {
        setContentSize(director->getWinSize());
        m_bTouchEnabled = false;
        m_bAccelerometerEnabled = false;
    }
    return false;
};


void MultiplayerLayer::keyBackClicked()
{
    onBack(nullptr);
}

void MultiplayerLayer::onBack(cocos2d::CCObject *pSender)
{
    setKeypadEnabled(false);
    cocos2d::CCDirector::sharedDirector()->replaceScene(cocos2d::CCTransitionFade::create(0.5, CreatorLayer::scene()));
}

void MultiplayerLayer::onBtn1(cocos2d::CCObject *pSender)
{ 
    // UNKNOWN CALL: (*(code *)pSender->vtable[0xd].cocos2d_CCObject_delete_CCObject)(pSender,0);
    cocos2d::CCDirector::sharedDirector()->replaceScene(cocos2d::CCTransitionFade::create(0.5, /* MPLobbyLayer::scene(0)  TODO: MPLobbyLayer */  nullptr   ));
}

void MultiplayerLayer::onBtn2(cocos2d::CCObject *pSender)
{
    setKeypadEnabled(false);
    cocos2d::CCDirector::sharedDirector()->replaceScene(cocos2d::CCTransitionFade::create(0.5, /* MPLobbyLayer::scene(-1)  TODO: MPLobbyLayer */  nullptr   ));
}



cocos2d::CCScene * MultiplayerLayer::scene()
{  
    cocos2d::CCScene* scene = cocos2d::CCScene::create();
    AppDelegate::get()->m_runningScene = scene;
    scene->addChild(create());
    return scene;
}


