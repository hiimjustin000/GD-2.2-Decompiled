#include "includes.h"



/* TODO: CCMenuItemSpriteExtra::activate() has FMOD Stuff I haven't reversed yet... */

CCMenuItemSpriteExtra* CCMenuItemSpriteExtra::create(
        cocos2d::CCNode* normalSprite,
        cocos2d::CCNode* selectedSprite,
        cocos2d::CCObject* target,
        cocos2d::SEL_MenuHandler selector
    ){
    CCMenuItemSpriteExtra* obj = new CCMenuItemSpriteExtra;
    if (obj != nullptr && obj->init(normalSprite, selectedSprite, target, selector)) {
        obj->autorelease();
        return obj;
    }
    CC_SAFE_DELETE(obj);
    return nullptr;
};

// Intellisense is having Issues with giving me this one...
CCMenuItemSpriteExtra* CCMenuItemSpriteExtra::create(
        cocos2d::CCNode* normalSprite,
        cocos2d::CCObject* target,
        cocos2d::SEL_MenuHandler selector
) {
    return CCMenuItemSpriteExtra::create(normalSprite, nullptr, target, selector);
}



bool CCMenuItemSpriteExtra::init(
        cocos2d::CCNode* normalSprite, 
        cocos2d::CCNode* selectedSprite, 
        cocos2d::CCObject* target, 
        cocos2d::SEL_MenuHandler selector){
    
    if (cocos2d::CCMenuItemSprite::initWithNormalSprite(
        normalSprite,selectedSprite,nullptr,target,selector)){
        // UNKNOWN
        // this->field_0x13c = 0x3f800000; 
        normalSprite->setAnchorPoint(CCPointMake(0.5, 0.5));
        setContentSize(
            CCSizeMake(
                normalSprite->getContentSize().width * normalSprite->getScaleX(), 
                normalSprite->getContentSize().height * normalSprite->getScaleY()
            )
        );
        normalSprite->setPosition(
            normalSprite->getParent()->convertToNodeSpace(normalSprite->getPosition())
        );
        m_animationEnabled = true;
        // this->field280_0x138 = 0x3fa147ae; Unknown
        return true;
    }
    return false;
}




