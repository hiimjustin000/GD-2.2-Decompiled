
#include "includes.h"


int GameStatsManager::accountIDForIcon(int p0, UnlockType p1)
{
    return;
}



/* Unknown Return: GameStatsManager::addSimpleSpecialChestReward(std::string p0, UnlockType p1, int p2, bool p3){}; */

void GameStatsManager::addSpecialRewardDescription(std::string p0, std::string p1)
{
    return;
}



/* Unknown Return: GameStatsManager::addStoreItem(int p0, int p1, int p2, int p3, ShopType p4){}; */


/* Unknown Return: GameStatsManager::areChallengesLoaded(){}; */


/* Unknown Return: GameStatsManager::areRewardsLoaded(){}; */

void GameStatsManager::awardCurrencyForLevel(GJGameLevel* p0)
{
    return;
}



/* Unknown Return: GameStatsManager::awardDiamondsForLevel(GJGameLevel* p0){}; */


/* Unknown Return: GameStatsManager::awardSecretKey(){}; */


/* Unknown Return: GameStatsManager::checkAchievement(char const* p0){}; */


/* Unknown Return: GameStatsManager::checkCoinAchievement(GJGameLevel* p0){}; */

void GameStatsManager::checkCoinsForLevel(GJGameLevel* p0)
{
    return;
}



/* Unknown Return: GameStatsManager::claimListReward(GJLevelList* p0){}; */


/* Unknown Return: GameStatsManager::collectReward(GJRewardType p0, GJRewardItem* p1){}; */


/* Unknown Return: GameStatsManager::collectVideoReward(int p0){}; */

void GameStatsManager::completedChallenge(GJChallengeItem* p0)
{
    return;
}


void GameStatsManager::completedDailyLevel(GJGameLevel* p0)
{
    return;
}


void GameStatsManager::completedDemonLevel(GJGameLevel* p0)
{
    return;
}


void GameStatsManager::completedLevel(GJGameLevel* p0)
{
    return;
}


void GameStatsManager::completedMapPack(GJMapPack* p0)
{
    return;
}


void GameStatsManager::completedStarLevel(GJGameLevel* p0)
{
    return;
}



/* Unknown Return: GameStatsManager::countSecretChests(GJRewardType p0){}; */


/* Unknown Return: GameStatsManager::countUnlockedSecretChests(GJRewardType p0){}; */

 
void GameStatsManager::createSecretChestItems(){

    cocos2d::CCArray* SpecialItems = cocos2d::CCArray::create();

    for (int x = 0x1a; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL,  0, 5, 0, 0, 0, 0, 0, 0));
    }

    for (int x = 0x10; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL,  0,10,0,0,0,0,0,0));
    }

    for (int x = 8; x > 0; x--){
        SpecialItems->addObject( GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0x14, 0, 0, 0, 0, 0, 0));
    }
    SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0x1e,0,0,0,0,0,0));
    for (int x = 0x14; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0x32,0,0,0,0,0,0,0));
    }
    for (int x = 0x14; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 100, 0, 0, 0, 0, 0, 0, 0));
    }
    for (int x = 0xe; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 200,0,0,0,0,0,0,0));
    }
    for (int x = 8; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 300,0,0,0,0,0,0,0));
    }
    for (int x = 4; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 500,0,0,0,0,0,0,0));
    }
    SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 1000,0,0,0,0,0,0,0));
    for (int x = 10; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 100,5,0,0,0,0,0,0));
    }
    int y = 2;
    while( true ) {
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 200,10,0,0,0,0,0,0));
        if (y == 1) break;
        y = 1;
    }
    for (int x = 6; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,1,1,0,0,0,0));
    }
    for (int x = 3; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,1,2,0,0,0,0));
    }
    SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,1,3,0,0,0,0));
    for (int x = 6; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,2,1,0,0,0,0));
    }
    for (int x = 3; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,2,2,0,0,0,0));
    }
    SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,2,3,0,0,0,0));
    for (int x = 6; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,3,1,0,0,0,0));
    }

    for (int x = 3; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,3,2,0,0,0,0));
    }
    SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,3,3,0,0,0,0));
    for (int x = 6; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,4,1,0,0,0,0));
    }

    for (int x = 3; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,4,2,0,0,0,0));
    }
  
    SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,4,3,0,0,0,0));
    for (int x = 6; x > 0; x--){
        SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,5,1,0,0,0,0));
    }
    // TODO:
    // pbVar14 = (basic_string *)0x3;
    // do {
    //     SpecialItems->addObject(GJRewardItem::createSpecial(kGJRewardTypeXL, 0,0,5,2,0,0,0,0));
    //      pbVar14 = (basic_string *)((int)&pbVar14[-1]._M_p + 3);
    // } while (pbVar14 != (basic_string *)0x0);
    
}


/* Unknown Return: GameStatsManager::createSecretChestRewards(){}; */


/* Unknown Return: GameStatsManager::createSpecialChestItems(){}; */


void GameStatsManager::createStoreItems()
{ 
    if (this->m_allStoreItems == nullptr) {
        this->m_allStoreItems = cocos2d::CCDictionary::create();
        this->m_storeItems->retain();
        this->m_storeItems = cocos2d::CCDictionary::create();
        this->m_storeItems->retain();
        this->m_storeItemArray = cocos2d::CCArray::create();
        addStoreItem(0x22,0x4f,1,500,0);
        addStoreItem(1,0x4d,1,1000,0);
        addStoreItem(2,0x56,1,1000,0);
        addStoreItem(3,0x49,1,1000,0);
        addStoreItem(4,0x66,1,1000,0);
        addStoreItem(5,0x6b,1,1000,0);
        addStoreItem(6,0x1b,4,2000,0);
        addStoreItem(7,0x19,6,2000,0);
        addStoreItem(8,0x17,6,0x9c4,0);
        addStoreItem(9,0x14,5,1000,0);
        addStoreItem(10,0x13,5,0x5dc,0);
        addStoreItem(0xb,0x15,7,500,0);
        addStoreItem(0xc,2,9,2000,0);
        addStoreItem(0xd,0xc,8,3000,0);
        addStoreItem(0xe,8,0xb,7000,0);
        addStoreItem(0xf,0xb,0xb,7000,0);
        addStoreItem(0x10,0x12,7,2000,1);
        addStoreItem(0x11,0x5e,1,3000,1);
        addStoreItem(0x12,0x55,1,0x9c4,1);
        addStoreItem(0x13,0x60,1,2000,1);
        addStoreItem(0x14,4,0xc,1000,1);
        addStoreItem(0x15,0xe,8,3000,1);
        addStoreItem(0x16,0x15,6,4000,1);
        addStoreItem(0x17,3,9,3000,1);
        addStoreItem(0x18,0x19,5,2000,1);
        addStoreItem(0x19,0xd,0xb,10000,1);
        addStoreItem(0x1a,0x23,2,1000,0);
        addStoreItem(0x1b,0x24,2,1000,0);
        addStoreItem(0x1c,0x27,2,1000,1);
        addStoreItem(0x1d,0x28,2,1000,1);
        addStoreItem(0x1e,0x27,3,1000,0);
        addStoreItem(0x20,0x20,3,1000,1);
        addStoreItem(0x21,0x29,3,1000,1);
        addStoreItem(0x23,5,10,4000,0);
        addStoreItem(0x24,6,10,4000,0);
        addStoreItem(0x25,7,10,4000,1);
        addStoreItem(0x26,0x75,1,4000,2);
        addStoreItem(0x27,0x76,1,2000,2);
        addStoreItem(0x28,0x77,1,2000,2);
        addStoreItem(0x29,0x78,1,4000,2);
        addStoreItem(0x2a,0x79,1,2000,2);
        addStoreItem(0x2b,0x7a,1,2000,2);
        addStoreItem(0x2c,0x7b,1,6000,2);
        addStoreItem(0x2d,0x7c,1,8000,2);
        addStoreItem(0x2e,0x7d,1,4000,2);
        addStoreItem(0x2f,0x7e,1,2000,2);
        addStoreItem(0x30,0x7f,1,6000,2);
        addStoreItem(0x31,0x80,1,8000,2);
        addStoreItem(0x32,0x81,1,6000,2);
        addStoreItem(0x33,0x82,1,4000,2);
        addStoreItem(0x34,0x83,1,4000,2);
        addStoreItem(0x35,0x84,1,4000,2);
        addStoreItem(0x36,0x85,1,8000,2);
        addStoreItem(0x37,0x86,1,6000,2);
        addStoreItem(0x38,0x87,1,6000,2);
        addStoreItem(0x39,0x1e,5,4000,2);
        addStoreItem(0x3a,0x1f,5,6000,2);
        addStoreItem(0x3b,0x20,5,6000,2);
        addStoreItem(0x3c,0x21,5,2000,2);
        addStoreItem(0x3d,0x22,5,4000,2);
        addStoreItem(0x3e,0x23,5,8000,2);
        addStoreItem(0x3f,0x24,5,6000,2);
        addStoreItem(0x40,0x25,5,2000,2);
        addStoreItem(0x41,0x26,5,2000,2);
        addStoreItem(0x42,0x24,4,2000,2);
        addStoreItem(0x43,0x25,4,2000,2);
        addStoreItem(0x44,0x26,4,6000,2);
        addStoreItem(0x45,0x27,4,2000,2);
        addStoreItem(0x46,0x28,4,4000,2);
        addStoreItem(0x47,0x29,4,4000,2);
        addStoreItem(0x48,0x2a,4,6000,2);
        addStoreItem(0x49,0x2b,4,2000,2);
        addStoreItem(0x4a,0x2c,4,6000,2);
        addStoreItem(0x4b,0x2d,4,8000,2);
        addStoreItem(0x4c,0x2e,4,4000,2);
        addStoreItem(0x4d,0x2f,4,6000,2);
        addStoreItem(0x4e,0x30,4,4000,2);
        addStoreItem(0x4f,0x1d,6,6000,2);
        addStoreItem(0x50,0x1e,6,6000,2);
        addStoreItem(0x51,0x1f,6,4000,2);
        addStoreItem(0x52,0x20,6,6000,2);
        addStoreItem(0x53,0x21,6,4000,2);
        addStoreItem(0x54,0x22,6,2000,2);
        addStoreItem(0x55,0x23,6,2000,2);
        addStoreItem(0x56,0x18,7,2000,2);
        addStoreItem(0x57,0x19,7,4000,2);
        addStoreItem(0x58,0x1a,7,2000,2);
        addStoreItem(0x59,0x1b,7,2000,2);
        addStoreItem(0x5a,0x1c,7,6000,2);
        addStoreItem(0x5b,0x1d,7,6000,2);
        addStoreItem(0x5c,0x1e,7,4000,2);
        addStoreItem(0x5d,0x1f,7,6000,2);
        addStoreItem(0x5e,0x20,7,2000,2);
        addStoreItem(0x5f,0x21,7,6000,2);
        addStoreItem(0x60,0x12,8,2000,2);
        addStoreItem(0x61,0x13,8,6000,2);
        addStoreItem(0x62,0x14,8,2000,2);
        addStoreItem(99,0x15,8,4000,2);
        addStoreItem(100,0x16,8,6000,2);
        addStoreItem(0x65,0x17,8,2000,2);
        addStoreItem(0x66,0x18,8,6000,2);
        addStoreItem(0x67,0x19,8,4000,2);
        addStoreItem(0x68,0xb,9,4000,2);
        addStoreItem(0x69,0xc,9,6000,2);
        addStoreItem(0x6a,0xd,9,4000,2);
        addStoreItem(0x6b,0xe,9,8000,2);
        addStoreItem(0x6c,0xf,9,2000,2);
        addStoreItem(0x6d,0x10,9,6000,2);
        addStoreItem(0x6f,0x8c,1,3000,0);
        addStoreItem(0x70,0x6d,1,4000,0);
        addStoreItem(0x71,0x71,1,4000,0);
        addStoreItem(0x72,0x28,5,4000,0);
        addStoreItem(0x73,0x23,7,4000,0);
        addStoreItem(0x74,0x21,2,1000,0);
        addStoreItem(0x75,0x1c,3,1000,0);
        addStoreItem(0x76,0x88,1,5000,1);
        addStoreItem(0x77,0x6e,1,5000,1);
        addStoreItem(0x78,0x10,0xb,15000,1);
        addStoreItem(0x79,6,0xc,25000,5);
        addStoreItem(0x7a,7,0xc,25000,5);
        addStoreItem(0x7b,8,0xc,25000,5);
        addStoreItem(0x7c,9,0xc,25000,5);
        addStoreItem(0x7d,10,0xc,25000,5);
        addStoreItem(0x7e,0xb,0xc,25000,5);
        addStoreItem(0x7f,0xc,0xc,25000,5);
        addStoreItem(0x80,0xd,0xc,25000,5);
        addStoreItem(0x81,0xe,0xc,25000,5);
        addStoreItem(0x82,0xf,0xc,25000,5);
        addStoreItem(0x83,0xa2,1,3000,0);
        addStoreItem(0x84,0x28,6,0xdac,0);
        addStoreItem(0x85,0x54,2,0x5dc,0);
        addStoreItem(0x86,0x68,3,2000,0);
        addStoreItem(0x87,7,0xd,5000,0);
        addStoreItem(0x88,0x61,2,0x9c4,0);
        addStoreItem(0x89,0x21,8,0xdac,0);
        addStoreItem(0x8a,0x12,9,4000,0);
        addStoreItem(0x8b,0x39,5,3000,0);
        addStoreItem(0x8c,0x31,3,0x9c4,0);
        addStoreItem(0x8d,0x26,7,5000,0);
        addStoreItem(0x8e,0xbf,1,3000,0);
        addStoreItem(0x8f,99,2,0x5dc,0);
        addStoreItem(0x90,0x58,3,2000,0);
        addStoreItem(0x91,0xe5,1,5000,1);
        addStoreItem(0x92,0x56,3,0x5dc,1);
        addStoreItem(0x93,0x3a,4,4000,1);
        addStoreItem(0x94,0x53,6,3000,1);
        addStoreItem(0x95,0x2d,8,0xdac,1);
        addStoreItem(0x96,0xc,0xd,6000,1);
        addStoreItem(0x97,0xce,1,2000,1);
        addStoreItem(0x98,0x5e,2,1000,1);
        addStoreItem(0x99,0x3c,5,0x9c4,1);
        addStoreItem(0x9a,0x6b,5,3000,1);
        addStoreItem(0x9b,0x45,9,5000,1);
        addStoreItem(0x9c,0x4d,4,4000,1);
        addStoreItem(0x9d,0x31,2,1000,1);
        addStoreItem(0x9e,0x46,3,1000,1);
        addStoreItem(0x9f,0x89,4,4000,1);
        addStoreItem(0xa0,0x1b,0xd,6000,1);
        addStoreItem(0xa1,0xe1,1,3000,1);
        addStoreItem(0xa2,0x55,3,0x5dc,1);
        addStoreItem(0xa3,0x4e,7,0x9c4,1);
        addStoreItem(0xa4,0x3a,9,0xdac,1);
        addStoreItem(0xa5,0x68,6,0x9c4,1);
        addStoreItem(0xa6,0xa8,1,5000,3);
        addStoreItem(0xa7,0xe6,1,6000,3);
        addStoreItem(0xa8,0xfd,1,7000,3);
        addStoreItem(0xa9,0x166,1,6000,3);
        addStoreItem(0xaa,0x7e,4,7000,3);
        addStoreItem(0xab,0x6f,4,6000,3);
        addStoreItem(0xac,0x90,4,5000,3);
        addStoreItem(0xad,0xa4,4,7000,3);
        addStoreItem(0xae,0x40,5,5000,3);
        addStoreItem(0xaf,0x31,5,6000,3);
        addStoreItem(0xb0,0x6b,6,6000,3);
        addStoreItem(0xb1,0x88,6,5000,3);
        addStoreItem(0xb2,0x56,6,7000,3);
        addStoreItem(0xb3,0x4d,7,7000,3);
        addStoreItem(0xb4,0x55,7,6000,3);
        addStoreItem(0xb5,0x44,7,5000,3);
        addStoreItem(0xb6,0x34,8,6000,3);
        addStoreItem(0xb7,0x44,8,7000,3);
        addStoreItem(0xb8,0x32,9,6000,3);
        addStoreItem(0xb9,0x38,9,6000,3);
        addStoreItem(0xba,6,0xd,6000,3);
        addStoreItem(0xbb,0x10,0xc,40000,3);
        addStoreItem(0xbc,0x11,0xc,2000,4);
        addStoreItem(0xbd,0xb5,1,300,4);
        addStoreItem(0xbe,0xba,1,500,4);
        addStoreItem(0xbf,0xc4,1,400,4);
        addStoreItem(0xc0,0xcb,1,600,4);
        addStoreItem(0xc1,0xfa,1,300,4);
        addStoreItem(0xc2,0x107,1,600,4);
        addStoreItem(0xc3,0x13a,1,400,4);
        addStoreItem(0xc4,0x1a5,1,500,4);
        addStoreItem(0xc5,0x1bb,1,600,4);
        addStoreItem(0xc6,0x1c2,1,500,4);
        addStoreItem(199,0x1d7,1,400,4);
        addStoreItem(200,0x42,4,500,4);
        addStoreItem(0xc9,0x51,4,600,4);
        addStoreItem(0xca,0x7d,4,500,4);
        addStoreItem(0xcb,0x81,4,400,4);
        addStoreItem(0xcc,0x83,4,500,4);
        addStoreItem(0xcd,0xa8,4,600,4);
        addStoreItem(0xce,0x35,5,600,4);
        addStoreItem(0xcf,0x62,5,300,4);
        addStoreItem(0xd0,0x70,5,500,4);
        addStoreItem(0xd1,0x71,5,400,4);
        addStoreItem(0xd2,0x74,5,500,4);
        addStoreItem(0xd3,0x2d,6,500,4);
        addStoreItem(0xd4,0x34,6,500,4);
        addStoreItem(0xd5,100,6,600,4);
        addStoreItem(0xd6,0x8c,6,600,4);
        addStoreItem(0xd7,0x95,6,600,4);
        addStoreItem(0xd8,0x38,7,400,4);
        addStoreItem(0xd9,0x41,7,300,4);
        addStoreItem(0xda,0x4b,7,500,4);
        addStoreItem(0xdb,0x57,7,400,4);
        addStoreItem(0xdc,0x22,8,500,4);
        addStoreItem(0xdd,0x33,8,500,4);
        addStoreItem(0xde,0x3f,8,600,4);
        addStoreItem(0xdf,0x37,5,300,4);
        addStoreItem(0xe0,0x1d,9,500,4);
        addStoreItem(0xe1,0x36,9,300,4);
        addStoreItem(0xe2,0x3c,9,400,4);
        addStoreItem(0xe3,0x41,9,300,4);
        addStoreItem(0xe4,10,0xd,500,4);
        addStoreItem(0xe5,0x1e,0xd,500,4);
        addStoreItem(0xe6,0x28,0xd,600,4);
        addStoreItem(0xe7,5,0xe,600,4);
        addStoreItem(0xe8,0x4d,2,100,4);
        addStoreItem(0xe9,0x47,2,100,4);
        addStoreItem(0xea,0x40,2,100,4);
        addStoreItem(0xeb,100,2,100,4);
        addStoreItem(0xec,0x59,3,100,4);
        addStoreItem(0xed,0x6a,3,100,4);
        addStoreItem(0xee,0x2b,3,100,4);
        addStoreItem(0xef,0x48,3,100,4);
        addStoreItem(0xf0,0x62,2,100,4);
        addStoreItem(0xf1,0x4d,3,100,4);
        addStoreItem(0xf2,0x4a,2,100,4);
        addStoreItem(0xf3,0x3b,3,100,4);
        addStoreItem(0xf4,0x12,0xc,15000,3);
        addStoreItem(0xf5,0x13,0xc,15000,3);
        addStoreItem(0xf6,0x14,0xc,15000,3);
        addStoreItem(0xf7,2,0xf,20000,3);
        addStoreItem(0xf8,3,0xf,20000,3);
        addStoreItem(0xf9,4,0xf,20000,3);
        addStoreItem(0xfa,5,0xf,20000,3);
        addStoreItem(0xfb,6,0xf,20000,3);
        addStoreItem(0xfc,0x12,0xb,0x5dc,4);
        addStoreItem(0xfd,0x13,0xb,15000,3);
        addStoreItem(0xfe,0x1d1,1,400,4);
        addStoreItem(0xff,0x3e,4,500,4);
        addStoreItem(0x100,0x3f,4,300,4);
        addStoreItem(0x101,0x51,5,500,4);
        addStoreItem(0x102,0x4e,6,300,4);
        addStoreItem(0x103,0x50,6,400,4);
        addStoreItem(0x104,0x50,7,300,4);
        addStoreItem(0x105,0x52,7,500,4);
        addStoreItem(0x106,0x31,8,500,4);
        addStoreItem(0x107,0x3e,8,300,4);
        addStoreItem(0x108,0x40,9,500,4);
        addStoreItem(0x109,0x42,9,500,4);
        addStoreItem(0x10a,0x29,0xd,400,4);
        addStoreItem(0x10b,0x2a,0xd,500,4);
        addStoreItem(0x10c,0x1cf,1,400,4);
        addStoreItem(0x10d,0x1d0,1,500,4);
        addStoreItem(0x10e,0xb9,1,6000,3);
        addStoreItem(0x10f,0xbe,1,5000,3);
        addStoreItem(0x110,0x41,5,5000,3);
        addStoreItem(0x111,0x36,5,5000,3);
        addStoreItem(0x112,0x5f,6,7000,3);
        addStoreItem(0x113,0x8d,6,500,4);
        addStoreItem(0x114,0x16,9,400,4);
        addStoreItem(0x115,0x122,1,400,4);
        addStoreItem(0x116,0x168,1,6000,3);
        addStoreItem(0x117,0x50,4,6000,3);
        addStoreItem(0x118,0x57,4,400,4);
        addStoreItem(0x119,0x1c8,1,400,4);
        addStoreItem(0x11a,0x1e0,1,5000,3);
        addStoreItem(0x11b,0x84,6,6000,3);
        addStoreItem(0x11c,0x1de,1,400,4);
        addStoreItem(0x11d,0x1da,1,300,4);
    } 

}   

void GameStatsManager::dataLoaded(DS_Dictionary* p0)
{   
    return;
}   


void GameStatsManager::encodeDataTo(DS_Dictionary* p0)
{   
    return;
}


void GameStatsManager::firstSetup()
{
    return;
}



/* Unknown Return: GameStatsManager::generateItemUnlockableData(){}; */

int GameStatsManager::getAwardedCurrencyForLevel(GJGameLevel* p0)
{
    return;
}



/* Unknown Return: GameStatsManager::getAwardedDiamondsForLevel(GJGameLevel* p0){}; */


/* Unknown Return: GameStatsManager::getBaseCurrency(int p0, bool p1, int p2){}; */

int GameStatsManager::getBaseCurrencyForLevel(GJGameLevel* p0)
{
    return;
}



/* Unknown Return: GameStatsManager::getBaseDiamonds(int p0){}; */


/* Unknown Return: GameStatsManager::getBonusDiamonds(int p0){}; */

GJChallengeItem* GameStatsManager::getChallenge(int p0)
{
    return;
}



/* Unknown Return: GameStatsManager::getChallengeKey(GJChallengeItem* p0){}; */

int GameStatsManager::getCollectedCoinsForLevel(GJGameLevel* p0)
{
    return;
}



/* Unknown Return: GameStatsManager::getCompletedMapPacks(){}; */


/* Unknown Return: GameStatsManager::getCurrencyKey(GJGameLevel* p0){}; */


/* Unknown Return: GameStatsManager::getDailyLevelKey(int p0){}; */


/* Unknown Return: GameStatsManager::getDemonLevelKey(GJGameLevel* p0){}; */

std::string GameStatsManager::getGauntletRewardKey(int p0)
{
    return;
}



/* Unknown Return: GameStatsManager::getItemKey(int p0, int p1){}; */

int GameStatsManager::getItemUnlockState(int p0, UnlockType p1)
{
    return;
}


int GameStatsManager::getItemUnlockStateLite(int p0, UnlockType p1)
{
    return;
}


std::string GameStatsManager::getLevelKey(GJGameLevel* p0)
{
    return;
}


std::string GameStatsManager::getLevelKey(int p0, bool p1, bool p2, bool p3)
{
    return;
}



/* Unknown Return: GameStatsManager::getListRewardKey(GJLevelList* p0){}; */

char const* GameStatsManager::getMapPackKey(int p0)
{
    return;
}



/* Unknown Return: GameStatsManager::getNextVideoAdReward(){}; */


/* Unknown Return: GameStatsManager::getPathRewardKey(int p0){}; */

GJChallengeItem* GameStatsManager::getQueuedChallenge(int p0)
{
    return;
}



/* Unknown Return: GameStatsManager::getRewardForSecretChest(int p0){}; */


/* Unknown Return: GameStatsManager::getRewardForSpecialChest(std::string p0){}; */


/* Unknown Return: GameStatsManager::getRewardItem(GJRewardType p0){}; */


/* Unknown Return: GameStatsManager::getRewardKey(GJRewardType p0, int p1){}; */

GJChallengeItem* GameStatsManager::getSecondaryQueuedChallenge(int p0)
{
    return;
}



/* Unknown Return: GameStatsManager::getSecretChestForItem(int p0, UnlockType p1){}; */


/* Unknown Return: GameStatsManager::getSecretCoinKey(char const* p0){}; */


/* Unknown Return: GameStatsManager::getSpecialChestKeyForItem(int p0, UnlockType p1){}; */


/* Unknown Return: GameStatsManager::getSpecialRewardDescription(std::string p0, bool p1){}; */


/* Unknown Return: GameStatsManager::getSpecialUnlockDescription(int p0, UnlockType p1, bool p2){}; */


/* Unknown Return: GameStatsManager::getStarLevelKey(GJGameLevel* p0){}; */

int GameStatsManager::getStat(char const* p0)
{
    return;
}



/* Unknown Return: GameStatsManager::getStatFromKey(StatKey p0){}; */


/* Unknown Return: GameStatsManager::getStoreItem(int p0, int p1){}; */


/* Unknown Return: GameStatsManager::getStoreItem(int p0){}; */

int GameStatsManager::getTotalCollectedCurrency()
{
    return;
}


int GameStatsManager::getTotalCollectedDiamonds()
{
    return;
}


bool GameStatsManager::hasClaimedListReward(GJLevelList* p0)
{
    return;
}


bool GameStatsManager::hasCompletedChallenge(GJChallengeItem* p0)
{
    return;
}


bool GameStatsManager::hasCompletedDailyLevel(int p0)
{
    return;
}


bool GameStatsManager::hasCompletedDemonLevel(GJGameLevel* p0)
{
    return;
}


bool GameStatsManager::hasCompletedGauntletLevel(int p0)
{
    return;
}


bool GameStatsManager::hasCompletedMapPack(int p0)
{
    return;
}


bool GameStatsManager::hasCompletedOnlineLevel(int p0)
{
    return;
}


bool GameStatsManager::hasCompletedStarLevel(GJGameLevel* p0)
{
    return;
}


bool GameStatsManager::hasPendingUserCoin(char const* p0)
{
    return;
}


bool GameStatsManager::hasRewardBeenCollected(GJRewardType p0, int p1)
{
    return;
}


bool GameStatsManager::hasSecretCoin(char const* p0)
{
    return;
}


bool GameStatsManager::hasUserCoin(char const* p0)
{
    return;
}



/* Unknown Return: GameStatsManager::incrementActivePath(int p0){}; */


/* Unknown Return: GameStatsManager::incrementChallenge(GJChallengeType p0, int p1){}; */


/* Unknown Return: GameStatsManager::incrementStat(char const* p0, int p1){}; */


/* Unknown Return: GameStatsManager::incrementStat(char const* p0){}; */

bool GameStatsManager::init()
{
    return;
}


bool GameStatsManager::isGauntletChestUnlocked(int p0)
{
    return;
}


bool GameStatsManager::isItemEnabled(UnlockType p0, int p1)
{
    return;
}


bool GameStatsManager::isItemUnlocked(UnlockType p0, int p1)
{
    return;
}


bool GameStatsManager::isPathChestUnlocked(int p0)
{
    return;
}


bool GameStatsManager::isPathUnlocked(StatKey p0)
{
    return;
}


bool GameStatsManager::isSecretChestUnlocked(int p0)
{
    return;
}


bool GameStatsManager::isSecretCoin(std::string p0)
{
    return;
}


bool GameStatsManager::isSecretCoinValid(std::string p0)
{
    return;
}


bool GameStatsManager::isSpecialChestLiteUnlockable(std::string p0)
{
    return;
}


bool GameStatsManager::isSpecialChestUnlocked(std::string p0)
{
    return;
}


bool GameStatsManager::isStoreItemUnlocked(int p0)
{
    return;
}



/* Unknown Return: GameStatsManager::keyCostForSecretChest(int p0){}; */


/* Unknown Return: GameStatsManager::logCoins(){}; */


/* Unknown Return: GameStatsManager::markLevelAsCompletedAndClaimed(GJGameLevel* p0){}; */


/* Unknown Return: GameStatsManager::postLoadGameStats(){}; */


/* Unknown Return: GameStatsManager::preProcessReward(GJRewardItem* p0){}; */


/* Unknown Return: GameStatsManager::preSaveGameStats(){}; */


/* Unknown Return: GameStatsManager::processChallengeQueue(int p0){}; */


/* Unknown Return: GameStatsManager::purchaseItem(int p0){}; */


/* Unknown Return: GameStatsManager::recountSpecialStats(){}; */


/* Unknown Return: GameStatsManager::recountUserCoins(bool p0){}; */


/* Unknown Return: GameStatsManager::registerRewardsFromItem(GJRewardItem* p0){}; */


/* Unknown Return: GameStatsManager::removeChallenge(int p0){}; */


/* Unknown Return: GameStatsManager::removeErrorFromSpecialChests(){}; */


/* Unknown Return: GameStatsManager::removeQueuedChallenge(int p0){}; */


/* Unknown Return: GameStatsManager::removeQueuedSecondaryChallenge(int p0){}; */


/* Unknown Return: GameStatsManager::resetChallengeTimer(){}; */


/* Unknown Return: GameStatsManager::resetPreSync(){}; */


/* Unknown Return: GameStatsManager::resetSpecialChest(std::string p0){}; */


/* Unknown Return: GameStatsManager::resetSpecialStatAchievements(){}; */


/* Unknown Return: GameStatsManager::resetUserCoins(){}; */


/* Unknown Return: GameStatsManager::restorePostSync(){}; */

void GameStatsManager::setAwardedBonusKeys(int p0)
{
    return;
}


void GameStatsManager::setStarsForMapPack(int p0, int p1)
{
    return;
}


void GameStatsManager::setStat(char const* p0, int p1)
{
    return;
}


void GameStatsManager::setStatIfHigher(char const* p0, int p1)
{
    return;
}



/* Unknown Return: GameStatsManager::setupIconCredits(){}; */

GameStatsManager* GameStatsManager::sharedState()
{
    return;
}



/* Unknown Return: GameStatsManager::shopTypeForItemID(int p0){}; */


/* Unknown Return: GameStatsManager::shouldAwardSecretKey(){}; */


/* Unknown Return: GameStatsManager::starsForMapPack(int p0){}; */


/* Unknown Return: GameStatsManager::storeChallenge(int p0, GJChallengeItem* p1){}; */


/* Unknown Return: GameStatsManager::storeChallengeTime(int p0){}; */


/* Unknown Return: GameStatsManager::storePendingUserCoin(char const* p0){}; */


/* Unknown Return: GameStatsManager::storeQueuedChallenge(int p0, GJChallengeItem* p1){}; */


/* Unknown Return: GameStatsManager::storeRewardState(GJRewardType p0, int p1, int p2, std::string p3){}; */


/* Unknown Return: GameStatsManager::storeSecondaryQueuedChallenge(int p0, GJChallengeItem* p1){}; */


/* Unknown Return: GameStatsManager::storeSecretCoin(char const* p0){}; */

void GameStatsManager::storeUserCoin(char const* p0)
{
    return;
}



/* Unknown Return: GameStatsManager::tempClear(){}; */

void GameStatsManager::toggleEnableItem(UnlockType p0, int p1, bool p2)
{
    return;
}



/* Unknown Return: GameStatsManager::tryFixPathBug(){}; */


/* Unknown Return: GameStatsManager::trySelectActivePath(){}; */


/* Unknown Return: GameStatsManager::uncompleteLevel(GJGameLevel* p0){}; */


/* Unknown Return: GameStatsManager::unlockGauntletChest(int p0){}; */


/* Unknown Return: GameStatsManager::unlockPathChest(int p0){}; */


/* Unknown Return: GameStatsManager::unlockSecretChest(int p0){}; */


/* Unknown Return: GameStatsManager::unlockSpecialChest(std::string p0){}; */


/* Unknown Return: GameStatsManager::updateActivePath(StatKey p0){}; */

std::string GameStatsManager::usernameForAccountID(int p0)
{
    return;
}



/* Unknown Return: GameStatsManager::verifyPathAchievements(){}; */


/* Unknown Return: GameStatsManager::verifyUserCoins(){}; */
