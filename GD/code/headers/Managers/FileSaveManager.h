#ifndef __FILESAVEMANAGER_H__
#define __FILESAVEMANAGER_H__

#include "../includes.h"

class FileSaveManager : GManager {
public:
    FileSaveManager():
        m_fileSaveDict(nullptr)
	{}
    
	virtual cocos2d::CCDictionary* getStoreData();
	virtual bool loadDataFromFile(char const* fileName);
	virtual bool init();
	virtual void firstLoad();
	static FileSaveManager* sharedState();


    cocos2d::CCDictionary* m_fileSaveDict;
};


#endif // __FILESAVEMANAGER_H__
