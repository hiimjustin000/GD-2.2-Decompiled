#include "includes.h"
class AchievementManager: public cocos2d::CCNode
{
public:
	cocos2d::CCDictionary* m_platformAchievements;
	cocos2d::CCDictionary* m_achievements;
	cocos2d::CCArray* m_allAchievementsSorted;
	cocos2d::CCArray* m_allAchievements;
	cocos2d::CCDictionary* m_achievementUnlocks;
	cocos2d::CCDictionary* m_unAchieved;
	int m_order;
	bool m_dontNotify;
	
	// virtual ~AchievementManager();

	static AchievementManager* sharedState();
	const char* achievementForUnlock(int _ID, UnlockType type);
	void AchievementManager::addAchievement(std::string identifier, std::string title, std::string achievedDescription, std::string unachievedDescription, std::string icon, int limits);
	void addManualAchievements();
	bool areAchievementsEarned(cocos2d::CCArray* arr);
	virtual void checkAchFromUnlock(char const*);
	void dataLoaded(DS_Dictionary* dsdict);
	void encodeDataTo(DS_Dictionary* dsdict);
	void firstSetup();
	cocos2d::CCDictionary* getAchievementRewardDict();
	cocos2d::CCDictionary* getAchievementsWithID(char const* ID);
	cocos2d::CCArray* getAllAchievements();
	cocos2d::CCArray* getAllAchievementsSorted(bool);
	bool isAchievementAvailable(std::string achievement);
	bool isAchievementEarned(const char *achievement)
	int limitForAchievement(std::string);
	void notifyAchievement(const char* title,const char* achievedDescription, const char* icon);
	void notifyAchievementWithID(char const* ID);
	float percentageForCount(int a, int b);
	int percentForAchievement(char *achievement);
	void reportAchievementWithID(char *achievement,int percent,bool levelCompleted);
	void reportPlatformAchievementWithID(char const* ID, int _report);
	void resetAchievement(char const* achievementName);
	void resetAchievements();
	// virtual...
	// void setup();
	void storeAchievementUnlocks();

	virtual bool init();
}

