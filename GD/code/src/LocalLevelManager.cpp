#include "includes.h"

/* TODO: virtual bool LocalLevelManager::dataLoaded(DS_Dictionary *dsdict) */

void LocalLevelManager::encodeDataTo(DS_Dictionary *dsdict)
{
    dsdict->setArrayForKey("LLM_01", m_localLevels);
    dsdict->setIntegerForKey("LLM_02", 41);
    dsdict->setArrayForKey("LLM_03", m_localLevelLists);
}

bool LocalLevelManager::firstLoad()
{
    auto _arr = cocos2d::CCArray::create();
    if (m_localLevels != _arr){
        if (_arr != nullptr){
            _arr->retain();
        }
        if (m_localLevels != nullptr){
            m_localLevels->release();
        }
        m_localLevels = _arr;
    }
    _arr = cocos2d::CCArray::create();
    if (m_localLevelLists != _arr){
        if (_arr != nullptr){
            _arr->retain();
        }
        if (m_localLevelLists != nullptr){
            m_localLevelLists->release();
        }
        m_localLevelLists = _arr;
    }
    return true;
}



cocos2d::CCDictionary * LocalLevelManager::getAllLevelsInDict()
{
    GJGameLevel* level;
    cocos2d::CCDictionary *allLevels;
    allLevels = cocos2d::CCDictionary::create();
    for (unsigned int i = 0; i < m_localLevels->count(); i++){
        level = reinterpret_cast<GJGameLevel*>(m_localLevels->objectAtIndex(i));
        if (level != nullptr) {
            allLevels->setObject(level, level->m_levelName);
        }
    }
    return allLevels;
}


cocos2d::CCArray* LocalLevelManager::getAllLevelsWithName(std::string name){
    GJGameLevel* level;
    cocos2d::CCArray *level_arr = cocos2d::CCArray::create();
    for (unsigned int i = 0; i < m_localLevels->count(); i++){
        level = reinterpret_cast<GJGameLevel*>(m_localLevels->objectAtIndex(i));
        if (level->m_levelName == name){
            level_arr->addObject(level);
        }
    }
    return level_arr;
}


/* TODO */
// coco2d::CCArray * LocalLevelManager::getCreatedLevels(int _amount)
// {

//     if (_amount < 1) {
//       return m_localLevels;
//     }
//     for (unsigned int i = 0; i < m_localLevels->count(); i++){
//         level = reinterpret_cast<GJGameLevel*>(m_localLevels->objectAtIndex(i));
//     }
//     // _arr = cocos2d::CCArray::create();
//     // if (this->m_localLevels != nullptr) {
//     //   p_Var1 = this->m_localLevels->data;
//     //   uVar2 = p_Var1->num;
//     //   if (uVar2 != 0) {
//     //     ppCVar3 = (CCObject **)p_Var1[1].num;
//     //     ppCVar4 = ppCVar3;
//     //     while (ppCVar4 <= ppCVar3 + uVar2 + 0x3fffffff) {
//     //       ppCVar5 = ppCVar4 + 1;
//     //       obj = *ppCVar4;
//     //       if (obj == 0x0) {
//     //         return _arr;
//     //       }
//     //       ppCVar4 = ppCVar5;
//     //       if (obj[0x11].m_nTag == param_1) {
//     //         cocos2d::CCArray::addObject(_arr,obj);
//     //       }
//     //     }
//     //   }
//     // }
//     return _arr;
// }






cocos2d::CCDictionary * LocalLevelManager::getLevelsInNameGroups()
{
    GJGameLevel* level;
    cocos2d::CCArray* _arr;
    cocos2d::CCDictionary *localdict;
    localdict = cocos2d::CCDictionary::create();
    for (unsigned int i = 0; i < m_localLevels->count(); i++){
        level = reinterpret_cast<GJGameLevel*>(m_localLevels->objectAtIndex(i));
        _arr = (cocos2d::CCArray*)localdict->objectForKey(level->m_levelName);
        if (_arr == nullptr) {
            localdict->setObject(cocos2d::CCArray::create(), level->m_levelName);
        }
        _arr->addObject(level);
    }
    return localdict;
}



std::string LocalLevelManager::getMainLevelString(int _ID)
{
    tryLoadMainLevelString(_ID);
    // TODO: I DON'T UNDERSTAND THIS! 
    // if (!m_mainLevels.count())
    //     return "";
    return m_mainLevels[_ID];
}

bool LocalLevelManager::init(){
    m_fileName = "CCLocalLevels.dat";
    setup();
    return true;
}


void LocalLevelManager::markLevelsAsUnmodified(){
    GJGameLevel* level;
    for (unsigned int i = 0; i < m_localLevels->count(); i++){
        level = reinterpret_cast<GJGameLevel*>(m_localLevels->objectAtIndex(i));
        level->m_hasBeenModified = false;
    }
}

void LocalLevelManager::moveLevelToTop(GJGameLevel *level)
{
    if ((level != (GJGameLevel *)0x0) && (m_localLevels->containsObject(level))) {
        level->retain();
        this->m_localLevels->removeObject(level, true);
        m_localLevels->insertObject(level, 0);
        level->release();
        updateLevelOrder();
    }
}


int levelCompare(GJGameLevel *a, GJGameLevel *b)
{
    return a->m_levelIndex - b->m_levelIndex;
}


void LocalLevelManager::reorderLevels(){
    cocos2d::ccArray *low_level_arr;
    if (m_localLevels->count()) {
        low_level_arr = this->m_localLevels->data;
        qsort(low_level_arr, low_level_arr->num, 4, reinterpret_cast<_CoreCrtNonSecureSearchSortCompareFunction>(levelCompare));
    }

}

static LocalLevelManager* GLOBAL_LOCALLEVELMANAGER;


LocalLevelManager *LocalLevelManager::sharedState(){
    if (GLOBAL_LOCALLEVELMANAGER != nullptr){
        GLOBAL_LOCALLEVELMANAGER = new LocalLevelManager;
        GLOBAL_LOCALLEVELMANAGER->init();
    }
    return GLOBAL_LOCALLEVELMANAGER;
}




