#include "includes.h"

/* Surpised that there wasn't anything else going on with this function */

void InfoAlertButton::activate(){
    if (m_show) {
        FLAlertLayer::create(nullptr, m_title.c_str(), m_desc.c_str(),"OK", nullptr, 430.0, m_scroll, 0.0, m_textScale)->show();
    }
}

InfoAlertButton* InfoAlertButton::create(std::string title, std::string desc, float scale){
    InfoAlertButton* btn = new InfoAlertButton;
    if (btn != nullptr && btn->init(title, desc, scale)){
        btn->autorelease();
        return btn;
    }
    CC_SAFE_RELEASE(btn);
    return nullptr;
}

bool InfoAlertButton::init(std::string title, std::string desc, float scale)
{
    cocos2d::CCSprite* infoIcon = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
    infoIcon->setScale(scale);
    if (CCMenuItemSpriteExtra::init(infoIcon, nullptr, nullptr ,nullptr)) {
        setSizeMult(1.5);
        m_title = title;
        m_desc = desc;
        return true;
    }
    return false;
}
