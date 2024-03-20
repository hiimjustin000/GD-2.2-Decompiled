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
        m_buttonMenu = m_scrollingLayer;
    }
    m_buttonMenu->ccTouchMoved(touch, event);
}

FLAlertLayer * FLAlertLayer::create(FLAlertLayerProtocol *delegate,const char *title, const std::string &desc,const char *btn1,const char *btn2, float width,bool scroll,float height,float textScale){
    FLAlertLayer* layer = new FLAlertLayer;
    if (layer->init(delegate, title, desc , btn1, btn2, width, scroll, height, textScale)){
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
};

FLAlertLayer* FLAlertLayer::create(char const* title, const std::string& desc, char const* btn) {
	return FLAlertLayer::create(nullptr, title, desc, btn, nullptr, 300.0);
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
 * I wouldn't say they are big, but rather a nightmarish puzzle that I don't want to deal with at the moment */


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


/*
void __thiscall FLAlertLayer::onBtn1(FLAlertLayer *this,CCObject *param_1)

{
  CCDirector *pCVar1;
  CCTouchDispatcher *this_00;
  undefined4 *puVar2;
  
  pCVar1 = cocos2d::CCDirector::sharedDirector();
  this_00 = (CCTouchDispatcher *)(*(code *)pCVar1->vtable->cocos2d_CCDirector_getKeypadDispatcher )()
  ;
  cocos2d::CCTouchDispatcher::unregisterForcePrio(this_00,(CCObject *)this);
  puVar2 = (undefined4 *)this->m_alertProtocol;
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(puVar2,this,0);
//   (*(code *)this->vtable->cocos2d_CCNode_removeFromParentAndCleanup)(this,1);
//   return;
// }
*/


void FLAlertLayer::onBtn2(cocos2d::CCObject *pSender){
 
    FLAlertLayerProtocol *puVar2;
  
    auto touchdispatcher = (cocos2d::CCTouchDispatcher*)cocos2d::CCDirector::sharedDirector()->getKeypadDispatcher();
    /* Another Unidentified Function... */
    // touchdispatcher->unregisterForcePrio(this);
    // puVar2 = this->m_alertProtocol;
    // if (puVar2 != (FLAlertLayerProtocol *)0x0) {
    //     (***(code ***)puVar2)(puVar2,this,1);
    // }
                                    
    // removeFromParentAndCleanup(1);
    return;
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
    /* There's a problem with HJFod's CocosHeaders based on delegate names because Guess what? They all overlap when they shouldn't that's a NONO!!! 
	So these will all be empty until they are repaired... */
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
