#include "includes.h"

cocos2d::CCDictionary* FileSaveManager::getStoreData()
{
    return nullptr;
}

bool FileSaveManager::init()
{
    m_fileName = "CCData.dat";
    return true;
}

/* Robtop, why this? You could've just used std::string and things would be fine... */

bool FileSaveManager::loadDataFromFile(const char* fileName)
{
    return GManager::loadDataFromFile(fileName);
}


void FileSaveManager::firstLoad()
{
    m_fileSaveDict = getStoreData();
    m_fileSaveDict->retain();
    auto fsKeys = m_fileSaveDict->allKeys();
    for (unsigned int i = 0; i < fsKeys->count(); i++) {
        auto keyDict = reinterpret_cast<cocos2d::CCDictionary*>(m_fileSaveDict->objectForKey(reinterpret_cast<cocos2d::CCString*>(fsKeys->objectAtIndex(i))->getCString()));
        std::string category = reinterpret_cast<cocos2d::CCString*>(keyDict->objectForKey("category"))->getCString();
        if (category != "group") {
            cocos2d::CCArray* keys = keyDict->allKeys();
            for (unsigned int j = 0;  j < keys->count(); j++) {
                cocos2d::CCObject* object = (m_fileSaveDict->objectForKey(reinterpret_cast<cocos2d::CCString*>(fsKeys->objectAtIndex(i))->getCString()));
      
                if ((object != nullptr) &&
                    (dynamic_cast<cocos2d::CCDictionary*>(object))) {
                    m_fileSaveDict->setObject(object, category);
          
                }
            }
            m_fileSaveDict->removeObjectForKey(category);
        }
    }
}


static FileSaveManager* GLOBAL_FILESAVEMANAGER;

FileSaveManager* FileSaveManager::sharedState()
{
    if (GLOBAL_FILESAVEMANAGER == nullptr){
        GLOBAL_FILESAVEMANAGER = new FileSaveManager;
        GLOBAL_FILESAVEMANAGER->init();
    }
    return GLOBAL_FILESAVEMANAGER;
}
