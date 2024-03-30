#ifndef __CCMENUITEMTOGGLER_H__
#define __CCMENUITEMTOGGLER_H__

#include "includes.h"


class CCMenuItemToggler : public cocos2d::CCMenuItem{
public: 
    CCMenuItemToggler() {}
	// virtual ~CCMenuItemToggler();

	static CCMenuItemToggler* create(
		cocos2d::CCNode* normalSprite,
        cocos2d::CCNode* selectedSprite,
        cocos2d::CCObject* target,
        cocos2d::SEL_MenuHandler selector
	);

	static CCMenuItemToggler* createWithSize(const char* spr1, const char* spr2, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback, float scale) {
		auto sprOff = cocos2d::CCSprite::createWithSpriteFrameName(spr1);
		auto sprOn = cocos2d::CCSprite::createWithSpriteFrameName(spr2);

		sprOff->setScale(scale);
		sprOn->setScale(scale);

		return create(sprOff, sprOn, target, callback);
	}

	static CCMenuItemToggler* createWithStandardSprites(cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback, float scale) {
		auto sprOff = cocos2d::CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
		auto sprOn = cocos2d::CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");

		sprOff->setScale(scale);
		sprOn->setScale(scale);

		return create(sprOff, sprOn, target, callback);
	}


	CCMenuItemSpriteExtra * CCMenuItemToggler::activeItem();


	bool init(
		        cocos2d::CCNode* normalSprite,
        cocos2d::CCNode* selectedSprite,
        cocos2d::CCObject* target,
        cocos2d::SEL_MenuHandler selector
	);
	void normalTouch(cocos2d::CCObject* sender);
	void selectedTouch(cocos2d::CCObject* sender);
	void setSizeMult(float value);
	void toggle(bool toggle);

	bool isToggled() {
		return m_toggled;
	}
	bool isOn() {
		return m_toggled;
	}
	void setClickable(bool on) {
		m_notClickable = !on;
	}
	void toggleWithCallback(bool on) {
		this->activate();
		this->toggle(on);
	}

	virtual void activate();
	virtual void selected();
	virtual void unselected();
	virtual void setEnabled(bool);

	CCMenuItemSpriteExtra* m_offButton;
	CCMenuItemSpriteExtra* m_onButton;
	bool m_toggled;
	bool m_notClickable;
};


#endif // __CCMENUITEMTOGGLER_H__