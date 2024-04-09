#include "includes.h"



void GameCell::draw(){
    auto size = CCSizeMake(m_width, m_height);
    cocos2d::ccDrawColor4B(0, 0, 0, 75);
    glLineWidth(2.0f);
    cocos2d::ccDrawLine(CCPointMake(1.0, size.width), CCPointMake(size.width - 1.0, size.height));
}


bool GameCell::init()
{
    m_smartTemplate = nullptr;
    return true;
}


void GameCell::loadFromString(std::string str)
{
    /* cleanup previous children inside of our GameCell... */
    m_mainLayer->removeAllChildrenWithCleanup(true);
    /* Supply a Promo URL to the other games depening on the name of the given string */
    if (str == "gj"){
        m_url = "https://play.google.com/store/apps/details?id=com.robtopx.geometryjump";        
    } else if (str == "gjl"){
        m_url = "https://play.google.com/store/apps/details?id=com.robtopx.geometryjumplite";
    } else if (str == "gjm"){
        m_url = "https://play.google.com/store/apps/details?id=com.robtopx.geometrydashmeltdown";
    } else if (str == "gjw"){
        m_url = "https://play.google.com/store/apps/details?id=com.robtopx.geometrydashworld";
    } else if (str == "gjz"){
        m_url = "https://play.google.com/store/apps/details?id=com.robtopx.geometrydashsubzero";
    } else {
        m_url = cocos2d::CCString::createWithFormat("https://www.robtopgames.com/download/%s%i", str.c_str(), 0)->getCString();
    }
    /* create our promotion on top of the mainLayer */
    CCMenuItemSpriteExtra* promo = CCMenuItemSpriteExtra::create(cocos2d::CCSprite::create(cocos2d::CCString::createWithFormat("promo_%s.png", str.c_str())->getCString()), nullptr, static_cast<cocos2d::SEL_MenuHandler>(onTouch));
    promo->m_animationEnabled = false;
    promo->m_colorEnabled = true;
    m_mainLayer->addChild(cocos2d::CCMenu::create(promo, 0));
    m_mainLayer->setPosition(CCPointMake(m_width * 0.5, m_height * 0.5));
}


void GameCell::onTouch(cocos2d::CCObject* sender){
    cocos2d::CCApplication::sharedApplication()->openURL(m_url.c_str());
}


/* NOTE: for function `GameCell::updateBGColor` I was saved by a Macro named ccc3 Thank goodness... 
 * Ghidra did not understand this shit and still had to figure out a way to depack it... 
 * Something like this as a macro would solve my problem next time: 
 * ```c++
 * // depacks an integer to a `ccColor3B` structure
 * #define Int2ccColor3B(color) cocos2d::ccc3((color >> 8) & 0xFF, (color >> 16) & 0xFF, color >> 24)
 * ``` 
 */

void GameCell::updateBGColor(int color){
    m_backgroundLayer->setColor(
        (color & 1) ? cocos2d::ccc3(color >> 8 & 0xFF, color >> 16 & 0xFF, color >> 24) : cocos2d::ccWHITE
    );
    m_backgroundLayer->setOpacity(0xFF);
}

