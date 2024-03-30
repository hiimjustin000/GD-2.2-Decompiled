#ifndef __LOCALLEVELMANAGER_H__
#define __LOCALLEVELMANAGER_H__
#include "../includes.h"
#include <map>


class LocalLevelManager : public GManager {
	// virtual ~LocalLevelManager();
public:

	static LocalLevelManager* sharedState();
	inline static LocalLevelManager* get() {
        return LocalLevelManager::sharedState();
    }

	cocos2d::CCDictionary* getAllLevelsInDict();
	cocos2d::CCArray* getAllLevelsWithName(std::string name);
	TodoReturn getCreatedLevels(int);
	TodoReturn getCreatedLists(int);
	cocos2d::CCDictionary* getLevelsInNameGroups();
	std::string getMainLevelString(int);
	void markLevelsAsUnmodified();
	void moveLevelToTop(GJGameLevel*);
	void reorderLevels();
	TodoReturn tryLoadMainLevelString(int);
	TodoReturn updateLevelOrder();
	TodoReturn updateLevelRevision();

	virtual bool init();
	void encodeDataTo(DS_Dictionary* dsdict);
	bool dataLoaded(DS_Dictionary* dsdict);
	bool firstLoad();

	cocos2d::CCArray* m_localLevels;
	cocos2d::CCArray* m_localLevelLists; /* m_localLevelLists */
	std::map<int, std::string> m_mainLevels;
};


#endif // __LOCALLEVELMANAGER_H__
