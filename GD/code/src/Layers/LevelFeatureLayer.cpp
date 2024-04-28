#include "includes.h"



LevelFeatureLayer* LevelFeatureLayer::create(int ID)
{
    LevelFeatureLayer* obj = new LevelFeatureLayer;
    if (obj != nullptr && obj->init(ID)){
        obj->autorelease();
        return obj;
    }
    CC_SAFE_DELETE(obj);
    return nullptr;
}


bool LevelFeatureLayer::init(int ID)
{
    if (!FLAlertLayer::init(ID)){
        return false;
    }
    m_levelID = ID;

    /* This was my hint that this maybe Robtop's Secret tool... */
    m_place = 25032;
    
    cocos2d::CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    auto square = cocos2d::extension::CCScale9Sprite::create("GJ_square01.png", CCRectMake(0.0f,0.0f,80.0f, 80.0f));
    square->setContentSize(CCSizeMake(360.0, 180.0));
    m_mainLayer->addChild(square,-1);
    square->setPosition(CCPointMake(winSize.width * 0.5, winSize.height * 0.5));
    

    auto setFeaturedFont = cocos2d::CCLabelBMFont::create("Set Featured","bigFont.fnt");
    setFeaturedFont->setPosition(CCPointMake(winSize.width * 0.5, (winSize.height * 0.5 + 90.0) - 20.0));
    m_mainLayer->addChild(setFeaturedFont);

    m_buttonMenu = cocos2d::CCMenu::create();
    m_mainLayer->addChild(m_buttonMenu, 10);
    
    auto buttons = cocos2d::CCArray::create();

    auto onCloseButton = CCMenuItemSpriteExtra::create(ButtonSprite::create("Cancel"), nullptr, this, menu_selector(onClose));
    m_buttonMenu->addChild(onCloseButton);
    buttons->addObject(onCloseButton);


    auto SetFeatureButton = CCMenuItemSpriteExtra::create
                           ( ButtonSprite::create("Submit"), nullptr, this, menu_selector(onSetFeatured));
    m_buttonMenu->addChild(SetFeatureButton);

    GameToolbox::alignItemsHorisontally(buttons, 15.0, m_buttonMenu->convertToNodeSpace(CCPointMake(winSize.width * 0.5, (winSize.height * 0.5 - 90.0) + 25.0)), false);
    
    auto EpicOnlySprite = ButtonSprite::create("Epic\nOnly");
    EpicOnlySprite->setScale(40.f);

    auto EpicOnly = CCMenuItemSpriteExtra::create(EpicOnlySprite, nullptr, this, menu_selector(onSetEpicOnly));   
    m_buttonMenu->addChild(EpicOnly);
    EpicOnly->setPosition(EpicOnly->getPosition() + CCPointMake(0.0, 90.0));

    m_label = cocos2d::CCLabelBMFont::create("0","bigFont.fnt");
    m_mainLayer->addChild(m_label);
    auto winPos = CCPointMake(winSize.width * 0.5, winSize.height * 0.5);
    m_label->setPosition(winPos); 

    auto upButton = CCMenuItemSpriteExtra::create(cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png"), nullptr, this, menu_selector(onUp));
    m_buttonMenu->addChild(upButton);
    upButton->setSizeMult(1.5f);


    auto downButton = CCMenuItemSpriteExtra::create(cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png"), nullptr, this, menu_selector(onDown));
    m_buttonMenu->addChild(downButton);

    downButton->setPosition(m_buttonMenu->convertToNodeSpace(CCPointMake(winPos.x - 100.f, winPos.y)));
    downButton->setRotation(-90.f);
    downButton->setSizeMult(1.5f);
    
    
    auto downButton2 = CCMenuItemSpriteExtra::create(cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png"), nullptr, this, menu_selector(onDown2));
    m_buttonMenu->addChild(downButton2);
    downButton2->setPosition(m_buttonMenu->convertToNodeSpace(CCPointMake(winPos.x - 150.f, winPos.y)));
    downButton2->setRotation(-90.f);
    downButton2->setSizeMult(1.5f);


    auto upButton2 = CCMenuItemSpriteExtra::create(cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png"), nullptr, this, menu_selector(onDown2));
    m_buttonMenu->addChild(upButton2);
    upButton2->setPosition(m_buttonMenu->convertToNodeSpace(CCPointMake(winPos.x + 150.f, winPos.y)));
    upButton2->setRotation(90.f);
    upButton2->setSizeMult(1.5f); 


    auto deleteButton = CCMenuItemSpriteExtra::create(cocos2d::CCSprite::createWithSpriteFrameName("GJ_deleteBtn_001.png"), nullptr, this, menu_selector(onRemoveValues));
    m_buttonMenu->addChild(upButton2);
    upButton2->setPosition(m_buttonMenu->convertToNodeSpace(CCPointMake(winSize.width * 0.5 + 180.f, winSize.height * 0.5 + 90.f)));
    upButton2->setSizeMult(1.6f); 



    m_epicCoin = cocos2d::CCSprite::createWithSpriteFrameName("GJ_epicCoin_001.png");
    auto epicCoinButton = CCMenuItemSpriteExtra::create(m_epicCoin, nullptr, this, menu_selector(onToggleEpic));
    m_buttonMenu->addChild(upButton2);
    upButton2->setPosition(m_buttonMenu->convertToNodeSpace(CCPointMake(winSize.width * 0.5 - 180.f, winSize.height * 0.5 + 90.f)));
    upButton2->setRotation(90.f);
    upButton2->setSizeMult(1.5f); 
    
    
    m_epic = false;
    
    m_epicCoin->setColor(cocos2d::ccc3(50, 50, 50));
    return true;
}

void LevelFeatureLayer::keyBackClicked()
{
    onClose(nullptr);
}

void LevelFeatureLayer::onClose(cocos2d::CCObject *sender){
    setKeypadEnabled(false);
    removeFromParentAndCleanup(true);
}


void LevelFeatureLayer::onDown(cocos2d::CCObject *sender)
{
    unsigned int newpos = m_place - 1;
    m_place = newpos & ~(newpos >> 0x1f);
    updateStars();
}

void LevelFeatureLayer::onDown2(cocos2d::CCObject *sender)
{
    unsigned int newpos = m_place - 10;
    m_place = newpos & ~(newpos >> 0x1f);
    updateStars();
}


void LevelFeatureLayer::onRemoveValues(cocos2d::CCObject *sender)
{
    GameLevelManager::sharedState()->setLevelFeatured(m_levelID, -1, false);
    onClose(nullptr);
}


void LevelFeatureLayer::onSetEpicOnly(cocos2d::CCObject *sender)
{
    GameLevelManager::sharedState()->setLevelFeatured(m_levelID, -2, m_epic);
    onClose(nullptr);
}

void LevelFeatureLayer::onSetFeatured(cocos2d::CCObject *sender)
{
    if (m_place) {
        GameLevelManager::sharedState()->setLevelFeatured(m_levelID, m_place, m_epic);
        onClose(nullptr);
    }
}

void LevelFeatureLayer::onToggleEpic(cocos2d::CCObject *sender)
{
    m_epic = m_epic ^ 1;
    m_epicCoin->setColor(m_epic ? cocos2d::ccc3(0x32, 0x32, 0x32) : cocos2d::ccWHITE);
}

void LevelFeatureLayer::onUp(cocos2d::CCObject* sender)
{
    m_place += 1;
    updateStars();
}


void LevelFeatureLayer::onUp2(cocos2d::CCObject* sender)
{
    m_place += 10;
    updateStars();
}


void LevelFeatureLayer::updateStars()
{
    m_label->setString(cocos2d::CCString::createWithFormat("%i",m_place)->getCString());
}
