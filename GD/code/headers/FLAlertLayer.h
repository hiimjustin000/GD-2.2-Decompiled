#ifndef __FLALERTLAYER_H__
#define __FLALERTLAYER_H__

#include "includes.h"

/* TODO */
class ScrollingLayer : public cocos2d::CCLayerColor{

};

class FLAlertLayerProtocol;


class FLAlertLayer : public cocos2d::CCLayerColor {
    
public:
    cocos2d::CCMenu* m_buttonMenu;
	FLAlertLayerProtocol* m_alertProtocol;
	cocos2d::CCNode* m_scene;
	bool m_reverseKeyBack;
	cocos2d::ccColor3B m_color;
	cocos2d::CCLayer* m_mainLayer;
	int m_ZOrder;
	bool m_noElasticity;
	cocos2d::ccColor3B m_color2;
	ButtonSprite* m_button1;
	ButtonSprite* m_button2;
	ScrollingLayer* m_scrollingLayer;
	int m_controlConnected;
	bool m_containsBorder;
	bool m_noAction;
	int m_joystickConnected;
	bool m_forcePrioRegistered;



    bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
    void ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
    void ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);

    static FLAlertLayer* create(FLAlertLayerProtocol *delegate,const char *title,const std::string &desc,const char *btn1,const char *btn2, float width,bool scroll,float height,float textScale);
	static FLAlertLayer* create(FLAlertLayerProtocol* delegate, char const* title, const std::string &desc, char const* btn1, char const* btn2, float width);
	static FLAlertLayer* create(char const* title, const std::string& desc, char const* btn);

	void incrementForcePrio();


    void keyDown(cocos2d::enumKeyCodes keycodes);
	void onBtn1(cocos2d::CCObject *pSender);
	void onBtn2(cocos2d::CCObject *pSender);

	void show();

	void onEnter();
	void registerWithTouchDispatcher();

};


#endif // __FLALERTLAYER_H__