#ifndef MULTIPLAYERLAYER_H
#define MULTIPLAYERLAYER_H

#include "../includes.h"

class MultiplayerLayer : public cocos2d::CCLayer {
public:
    MultiplayerLayer(){}
    static MultiplayerLayer * MultiplayerLayer::create();
    static MultiplayerLayer * MultiplayerLayer::scene();
    virtual void keyBackClicked();
    bool init();
    void onBack(cocos2d::CCObject* pSender);
    void onBtn1(cocos2d::CCObject* pSender);
    void onBtn2(cocos2d::CCObject* pSender);
    /* MultiplayerLayer has no Class members... */
};



#endif // MULTIPLAYERLAYER_H
