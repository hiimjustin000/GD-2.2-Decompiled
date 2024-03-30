#include "includes.h"




CCMenuItemSpriteExtra * CCMenuItemToggler::activeItem()
{
    return (m_toggled) ? m_onButton: m_offButton;
}


CCMenuItemToggler* CCMenuItemToggler::create(
        cocos2d::CCNode* normalSprite,
        cocos2d::CCNode* selectedSprite,
        cocos2d::CCObject* target,
        cocos2d::SEL_MenuHandler selector
    ){
    CCMenuItemToggler* obj = new CCMenuItemToggler;
    if (obj != nullptr && obj->init(normalSprite, selectedSprite, target, selector)) {
        obj->autorelease();
        return obj;
    }
    CC_SAFE_DELETE(obj);
    return nullptr;
};



bool CCMenuItemToggler::init(cocos2d::CCNode *normalSprite, cocos2d::CCNode *selectedSprite, cocos2d::CCObject *target, cocos2d::SEL_MenuHandler selector){
    if (cocos2d::CCMenuItem::initWithTarget(target,selector)){
        m_offButton =  CCMenuItemSpriteExtra::create(normalSprite,nullptr, this, static_cast<cocos2d::SEL_MenuHandler>(normalTouch));
        m_onButton = CCMenuItemSpriteExtra::create(selectedSprite,nullptr, this, static_cast<cocos2d::SEL_MenuHandler>(selectedTouch));
        addChild(m_offButton);
        addChild(m_onButton);
        auto point = CCPointMake(0.5, 0.5);
        m_offButton->getNormalImage()->setAnchorPoint(point);
        m_onButton->getNormalImage()->setAnchorPoint(point);
        m_offButton->setPosition(m_offButton->getNormalImage()->convertToNodeSpace(point));
        m_onButton->setPosition(m_onButton->getNormalImage()->convertToNodeSpace(point));
        this->m_notClickable = false;
        toggle(false);
        return true;
    }
    return false;
}




void CCMenuItemToggler::normalTouch(CCObject *sender)
{
    if (!m_notClickable) {
        toggle(true);
    }
}

void CCMenuItemToggler::selectedTouch(CCObject *sender)
{
    if (!m_notClickable) {
        toggle(false);
    }
}



void CCMenuItemToggler::setEnabled(bool value){
    cocos2d::CCMenuItem::setEnabled(value);
    m_offButton->setEnabled(value);
    m_onButton->setEnabled(value);
    return;
}


void CCMenuItemToggler::setSizeMult(float value)
{
    m_offButton->setSizeMult(value);
    m_onButton->setSizeMult(value);
    toggle(m_toggled);
}


void CCMenuItemToggler::toggle(bool toggle)
{
    m_toggled = toggle;
    m_offButton->setVisible(!toggle);
    m_onButton->setVisible(toggle);
    auto size = activeItem()->getContentSize();
    setContentSize(size);
    auto _position = CCPointMake(size.width * 0.5,size.height * 0.5);
    m_offButton->setPosition(_position);
    m_onButton->setPosition(_position);
}   