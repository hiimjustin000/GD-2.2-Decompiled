#include "includes.h"


bool FLAlertLayer::ccTouchBegan(cocos2d::CCTouch * touch, cocos2d::CCEvent * event)
{    
    if (((m_joystickConnected == -1) && (m_buttonMenu != nullptr) && (m_buttonMenu->ccTouchBegan(touch, event) != 0))) {
        m_joystickConnected = touch->getID();
    }
    else if (((m_scrollingLayer != nullptr) && (m_controlConnected == -1)) && (m_scrollingLayer->ccTouchBegan(touch,event) != 0)) {
        m_controlConnected = touch->getID();
    }
    return true;
}


// TODO
// void FLAlertLayer::ccTouchCancelled(CCTouch *touch,CCEvent *event)

// {
//   int *piVar1;
  
//   if (touch->field449_0x1e8 == event->field52_0x34) {
//     piVar1 = touch->field410_0x1b8;
//   }
//   else {
//     if (touch->field444_0x1e0 != event->field52_0x34) {
//       return;
//     }
//     piVar1 = touch->field443_0x1dc;
//   }
//   (**(code **)(*piVar1 + 0x1c4))();
//   return;
// }

void FLAlertLayer::ccTouchEnded(cocos2d::CCTouch *touch,cocos2d::CCEvent *event){
    if (m_joystickConnected == touch->getID()) {
        m_buttonMenu->ccTouchEnded(touch,event);
        m_joystickConnected = -1;
    }
    else if (m_controlConnected == touch->getID()) {
        m_scrollingLayer->ccTouchEnded(touch, event);
        m_controlConnected = -1;
    }
}


void FLAlertLayer::ccTouchMoved(cocos2d::CCTouch *touch,cocos2d::CCEvent *event)
{
    if (m_joystickConnected != touch->getID()) {
        if (m_controlConnected != touch->getID()) {
            return;
        }
        // m_buttonMenu = m_scrollingLayer;
    }
    m_buttonMenu->ccTouchMoved(touch, event);
}

FLAlertLayer * FLAlertLayer::create(FLAlertLayerProtocol *delegate,const char *title, const std::string &desc,const char *btn1,const char *btn2, float width,bool scroll,float height,float textScale){
    FLAlertLayer* layer = new FLAlertLayer;
    // if (layer->init(delegate, title, desc , btn1, btn2, width, scroll, height, textScale)){
    //     layer->autorelease();
    //     return layer;
    // }
    CC_SAFE_DELETE(layer);
    return nullptr;
};

FLAlertLayer* create(char const* title, const std::string& desc, char const* btn) {
	return FLAlertLayer::create(nullptr, title, desc, btn, nullptr, 300.0);
}

/* Decompiled by Alphalaneous */
void FLAleartLayer::show() {
    CCDirector* director = CCDirector::sharedDirector();

    unsigned int opacity;
    int zOrder;

    CCScaleTo* scaleTo = CCScaleTo::create(0.5, 1.0);
    CCEaseElasticOut* easeElasticOut =   CCEaseElasticOut::create((CCActionInterval*)scaleTo, 0.6);
    CCFadeTo* fadeTo;

    CCScene* runningScene;
    CCScene* nextScene;

    if(m_noElasticity) {
        runningScene = director->m_pRunningScene;
        nextScene = (CCScene*) m_scene;
        if(nextScene == nullptr) {
            zOrder = runningScene->getHighestChildZ() + 1;
            if(zOrder < 105){
                zOrder = 105;
            }
            m_ZOrder = zOrder;
            nextScene = runningScene;
        }
        if(m_ZOrder == 0) {
            m_ZOrder = 105;
        }
        nextScene->addChild(this, m_ZOrder);
        this->setKeypadEnabled(true);
        return;
    }

    opacity = this->getOpacity();

    m_mainLayer->setScale(0.1f);
    m_mainLayer->runAction(easeElasticOut);

    runningScene = director->m_pRunningScene;
    nextScene = (CCScene*) m_scene;

    if(nextScene == nullptr) {
        zOrder = runningScene->getHighestChildZ() + 1;
        if(zOrder < 105) {
            zOrder = 105;
        }
        m_ZOrder = zOrder;
        nextScene = runningScene;
    }
    if(m_ZOrder == 0) {
        m_ZOrder = 105;
    }
    
    nextScene->addChild(this, zOrder);

    this->setOpacity(0);

    fadeTo = CCFadeTo::create(0.14, opacity);
    this->runAction(fadeTo);
    this->setKeypadEnabled(true);
}


void FLAlertLayer::incrementForcePrio(){

    
    if (m_forcePrioRegistered == false) {
        m_forcePrioRegistered = true;
        auto dispatcher = reinterpret_cast<cocos2d::CCTouchDispatcher*>(cocos2d::CCDirector::sharedDirector()->getKeyboardDispatcher());
        // Not Avalibe Function Maybe Robtop added? 
        // cocos2d::CCTouchDispatcher::registerForcePrio(dispatcher,(int)this,2,func);        
    }

    return;
}

/* I'll deal with the inits later in the future unless someone wants to go ahead and handle them for me... 
 * I wouldn't say they are being but rather a nightmarish puzzle that I don't want to deal with at the moment */


void FLAlertLayer::keyDown(cocos2d::enumKeyCodes keycodes){
    if ((keycodes == 0x20) && (!this->m_noAction)){
        return;
    }
    else if (keycodes != 0x3ef) {
        cocos2d::CCLayer::keyDown(keycodes);
    } else {
        onBtn2(nullptr);
    }
}


void FLAlertLayer::onBtn1(CCObject *sender)
{
    /* TODO: (Calloc) add unregisterForcePrio to cocosheaders in CCTouchDispatcher.h it doesn't exist in hjfod's version */ 
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->unregisterForcePrio(this);
    if (m_alertProtocol != nullptr) {
        m_alertProtocol->FLAlert_Clicked(this, false);
    }
    removeFromParentAndCleanup(true);
}



void FLAlertLayer::onBtn2(cocos2d::CCObject *sender)
{
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->unregisterForcePrio(this);
    if (m_alertProtocol != nullptr) {
        m_alertProtocol->FLAlert_Clicked(this, false);
    }
    removeFromParentAndCleanup(true);
}


/* FLAlertLayer::onEnter() */

/* Tiny Macro to prevent Intellisense from screaming at me. */
#ifndef TODO
    #define TODO nullptr
#endif /* TODO */

void FLAlertLayer::onEnter()
{

    auto director = cocos2d::CCDirector::sharedDirector();
    if (m_bTouchEnabled) {
        registerWithTouchDispatcher();
    }
    /* There's a problem with HJFod's CocosHeaders based on delegate names currently so these will all be empty temporarly... */
    cocos2d::CCNode::onEnter();
    if (m_bAccelerometerEnabled) {
        director->getAccelerometer()->setDelegate(TODO /* FIX CLASS MEMBER NAMES!!! */);
    }
    if (m_bKeypadEnabled) {
        director->getKeypadDispatcher()->addDelegate(TODO /* FIX CLASS MEMBER NAMES!!! */);
    }
    if (m_bKeyboardEnabled) {
        director->getKeyboardDispatcher()->addDelegate(TODO /* FIX CLASS MEMBER NAMES!!! */);
    }
    if (m_bMouseEnabled) {
        director->getMouseDispatcher()->addDelegate(TODO /* FIX CLASS MEMBER NAMES!!! */);
    }
    return;
}


void FLAlertLayer::registerWithTouchDispatcher(){
    auto dispatcher = cocos2d::CCDirector::sharedDirector()->getKeypadDispatcher();
    /* Problem... Another Unknown function in cocos headers */
    // cocos2d::CCTouchDispatcher::addPrioTargetedDelegate(dispatcher,(CCTouchDelegate *)&this->m_delegate,-0x1f5,true);
}
