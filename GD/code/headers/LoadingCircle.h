#ifndef __LOADINGCIRCLE_H__
#define __LOADINGCIRCLE_H__

#pragma once 
#include <cocos2d.h>
#include <includes.h>


class LoadingCircle: public cocos2d::CCNode, cocos2d::CCLayerColor , cocos2d::CCLayerRGBA, cocos2d::CCTouchDelegate {
public:
    cocos2d::CCTouchDelegate* m_touchDelegate;
    /* Unknown amount of offsets */

    cocos2d::CCSprite* m_sprite;
    cocos2d::CCLayer* m_layer;
    bool m_needsRendering;
    
    /* There's currently probelms with my ide hence the subclass functions being moved here... */
    
    static LoadingCircle* create();
    void addChild(cocos2d::CCNode *child);
    void draw();
    void fadeAndRemove();
    bool init();
    bool initWithColor(float);
    void registerWithTouchDispatcher();
    cocos2d::CCAction* runAction(cocos2d::CCAction *action);
    void show();
    void stopActionByTag(int tag);
};




#endif // __LOADINGCIRCLE_H__
