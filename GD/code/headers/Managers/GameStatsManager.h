#ifndef __GAMESTATSMANAGER_H__
#define __GAMESTATSMANAGER_H__

#include "..\includes.h"


enum StatKey {

};

enum ShopType {
	kShopTypeUnknown = 4
};

/* I'm not making Reversing this class object an absolute priority 
 * so this one is a free for all to any that wants to do it
 * I've only skimmed through some of it... 
 */

class GameStatsManager : public cocos2d::CCNode {
	// virtual ~GameStatsManager();
public:
	static GameStatsManager* sharedState();

	int accountIDForIcon(int, UnlockType);
	TodoReturn addSimpleSpecialChestReward(std::string, UnlockType, int, bool);
	void addSpecialRewardDescription(std::string, std::string);
	TodoReturn addStoreItem(int, int, int, int, ShopType);
	TodoReturn areChallengesLoaded();
	TodoReturn areRewardsLoaded();
	void awardCurrencyForLevel(GJGameLevel* level);
	TodoReturn awardDiamondsForLevel(GJGameLevel* level);
	TodoReturn awardSecretKey();
	TodoReturn checkAchievement(char const*);
	TodoReturn checkCoinAchievement(GJGameLevel* level);
	void checkCoinsForLevel(GJGameLevel* level);
	TodoReturn claimListReward(GJLevelList* list);
	TodoReturn collectReward(GJRewardType type, GJRewardItem* item);
	TodoReturn collectVideoReward(int);
	void completedChallenge(GJChallengeItem* challengeItem);
	void completedDailyLevel(GJGameLevel* level);
	void completedDemonLevel(GJGameLevel* level);
	void completedLevel(GJGameLevel* level);
	void completedMapPack(GJMapPack* mapPack);
	void completedStarLevel(GJGameLevel* level);
	TodoReturn countSecretChests(GJRewardType rewardType);
	TodoReturn countUnlockedSecretChests(GJRewardType rewardType);
	TodoReturn createSecretChestItems();
	TodoReturn createSecretChestRewards();
	TodoReturn createSpecialChestItems();
	TodoReturn createStoreItems();
	void dataLoaded(DS_Dictionary* dsdict);
	void encodeDataTo(DS_Dictionary* dsdict);
	void firstSetup();
	TodoReturn generateItemUnlockableData();
	int getAwardedCurrencyForLevel(GJGameLevel*);
	TodoReturn getAwardedDiamondsForLevel(GJGameLevel*);
	TodoReturn getBaseCurrency(int, bool, int);
	int getBaseCurrencyForLevel(GJGameLevel*);
	TodoReturn getBaseDiamonds(int);
	TodoReturn getBonusDiamonds(int);
	GJChallengeItem* getChallenge(int);
	TodoReturn getChallengeKey(GJChallengeItem*);
	int getCollectedCoinsForLevel(GJGameLevel*);
	TodoReturn getCompletedMapPacks();
	TodoReturn getCurrencyKey(GJGameLevel*);
	TodoReturn getDailyLevelKey(int);
	TodoReturn getDemonLevelKey(GJGameLevel*);
	std::string getGauntletRewardKey(int);
	TodoReturn getItemKey(int, int);
	int getItemUnlockState(int, UnlockType);
	int getItemUnlockStateLite(int, UnlockType);
	std::string getLevelKey(GJGameLevel*);
	std::string getLevelKey(int, bool, bool, bool);
	TodoReturn getListRewardKey(GJLevelList*);
	char const* getMapPackKey(int);
	TodoReturn getNextVideoAdReward();
	TodoReturn getPathRewardKey(int);
	GJChallengeItem* getQueuedChallenge(int);
	TodoReturn getRewardForSecretChest(int);
	TodoReturn getRewardForSpecialChest(std::string);
	TodoReturn getRewardItem(GJRewardType);
	TodoReturn getRewardKey(GJRewardType, int);
	GJChallengeItem* getSecondaryQueuedChallenge(int);
	TodoReturn getSecretChestForItem(int, UnlockType);
	TodoReturn getSecretCoinKey(char const*);
	TodoReturn getSpecialChestKeyForItem(int, UnlockType);
	TodoReturn getSpecialRewardDescription(std::string, bool);
	TodoReturn getSpecialUnlockDescription(int, UnlockType, bool);
	TodoReturn getStarLevelKey(GJGameLevel*);
	int getStat(char const*);
	TodoReturn getStatFromKey(StatKey);
	TodoReturn getStoreItem(int, int);
	TodoReturn getStoreItem(int);
	int getTotalCollectedCurrency();
	int getTotalCollectedDiamonds();
	bool hasClaimedListReward(GJLevelList*);
	bool hasCompletedChallenge(GJChallengeItem*);
	bool hasCompletedDailyLevel(int);
	bool hasCompletedDemonLevel(GJGameLevel*);
	bool hasCompletedGauntletLevel(int);
	bool hasCompletedLevel(GJGameLevel* level) {
		return m_completedLevels->objectForKey(this->getLevelKey(level)) != nullptr;
	}
	bool hasCompletedMainLevel(int levelID) {
		return m_completedLevels->objectForKey(this->getLevelKey(levelID, false, false, false)) != nullptr;
	}
	bool hasCompletedMapPack(int);
	bool hasCompletedOnlineLevel(int);
	bool hasCompletedStarLevel(GJGameLevel*);
	bool hasPendingUserCoin(char const*);
	bool hasRewardBeenCollected(GJRewardType, int);
	bool hasSecretCoin(char const*);
	bool hasUserCoin(char const*);
	TodoReturn incrementActivePath(int);
	TodoReturn incrementChallenge(GJChallengeType, int);
	TodoReturn incrementStat(char const*, int);
	TodoReturn incrementStat(char const*);
	bool isGauntletChestUnlocked(int);
	bool isItemEnabled(UnlockType, int);
	bool isItemUnlocked(UnlockType, int);
	bool isPathChestUnlocked(int);
	bool isPathUnlocked(StatKey);
	bool isSecretChestUnlocked(int);
	bool isSecretCoin(std::string);
	bool isSecretCoinValid(std::string);
	bool isSpecialChestLiteUnlockable(std::string);
	bool isSpecialChestUnlocked(std::string);
	bool isStoreItemUnlocked(int);
	TodoReturn keyCostForSecretChest(int);
	TodoReturn logCoins();
	TodoReturn markLevelAsCompletedAndClaimed(GJGameLevel*);
	TodoReturn postLoadGameStats();
	TodoReturn preProcessReward(GJRewardItem*);
	TodoReturn preSaveGameStats();
	TodoReturn processChallengeQueue(int);
	TodoReturn purchaseItem(int);
	TodoReturn recountSpecialStats();
	TodoReturn recountUserCoins(bool);
	TodoReturn registerRewardsFromItem(GJRewardItem*);
	TodoReturn removeChallenge(int);
	TodoReturn removeErrorFromSpecialChests();
	TodoReturn removeQueuedChallenge(int);
	TodoReturn removeQueuedSecondaryChallenge(int);
	TodoReturn resetChallengeTimer();
	TodoReturn resetPreSync();
	TodoReturn resetSpecialChest(std::string);
	TodoReturn resetSpecialStatAchievements();
	TodoReturn resetUserCoins();
	TodoReturn restorePostSync();
	void setAwardedBonusKeys(int);
	void setStarsForMapPack(int, int);
	void setStat(char const*, int);
	void setStatIfHigher(char const*, int);
	TodoReturn setupIconCredits();
	TodoReturn shopTypeForItemID(int);
	TodoReturn shouldAwardSecretKey();
	TodoReturn starsForMapPack(int);
	TodoReturn storeChallenge(int, GJChallengeItem*);
	TodoReturn storeChallengeTime(int);
	TodoReturn storePendingUserCoin(char const*);
	TodoReturn storeQueuedChallenge(int, GJChallengeItem*);
	TodoReturn storeRewardState(GJRewardType, int, int, std::string);
	TodoReturn storeSecondaryQueuedChallenge(int, GJChallengeItem*);
	TodoReturn storeSecretCoin(char const*);
	void storeUserCoin(char const*);
	TodoReturn tempClear();
	void toggleEnableItem(UnlockType, int, bool);
	TodoReturn tryFixPathBug();
	TodoReturn trySelectActivePath();
	TodoReturn uncompleteLevel(GJGameLevel*);
	TodoReturn unlockGauntletChest(int);
	TodoReturn unlockPathChest(int);
	TodoReturn unlockSecretChest(int);
	TodoReturn unlockSpecialChest(std::string);
	TodoReturn updateActivePath(StatKey);
	std::string usernameForAccountID(int);
	TodoReturn verifyPathAchievements();
	TodoReturn verifyUserCoins();

	virtual bool init();

	bool m_usePlayerStatsCCDictionary; // This one actually belongs to CCNode at 0x107 

	cocos2d::CCString* m_trueString;
	cocos2d::CCDictionary* m_allStoreItems;
	cocos2d::CCDictionary* m_storeItems;
	cocos2d::CCDictionary* m_allTreasureRoomChests;
	cocos2d::CCDictionary* m_allTreasureRoomChestItems;
	cocos2d::CCDictionary* m_allSpecialChests;
	cocos2d::CCDictionary* m_allSpecialChestItems;
	std::unordered_map<int, std::string> m_specialRewardDescriptions; //todo: is std::string std::string
	std::unordered_map<int, std::string> m_createSpecialChestItemsMap; //todo: is std::string std::string
	cocos2d::CCDictionary* m_specialChestsLite;
	cocos2d::CCArray* m_storeItemArray;
	cocos2d::CCDictionary* m_rewardItems;
	cocos2d::CCDictionary* m_dailyChests;
	cocos2d::CCDictionary* m_worldAdvertChests;
	cocos2d::CCDictionary* m_activeChallenges;
	cocos2d::CCDictionary* m_upcomingChallenges;
	double m_challengeTime;
	cocos2d::CCDictionary* m_playerStats;
	std::unordered_map<int, int> m_playerStatsRandMap;
	std::unordered_map<int, int> m_playerStatsSeedMap;
	cocos2d::CCDictionary* m_completedLevels;
	cocos2d::CCDictionary* m_verifiedUserCoins;
	cocos2d::CCDictionary* m_pendingUserCoins;
	cocos2d::CCDictionary* m_purchasedItems;
	cocos2d::CCDictionary* m_onlineCurrencyScores;
	cocos2d::CCDictionary* m_mainCurrencyScores;
	cocos2d::CCDictionary* m_gauntletCurrencyScores;
	cocos2d::CCDictionary* m_timelyCurrencyScores;
	cocos2d::CCDictionary* m_onlineStars;
	cocos2d::CCDictionary* m_timelyStars;
	cocos2d::CCDictionary* m_gauntletDiamondScores;
	cocos2d::CCDictionary* m_timelyDiamondScores;
	cocos2d::CCDictionary* m_unusedCurrencyAwardDict;
	cocos2d::CCDictionary* m_challengeDiamonds;
	cocos2d::CCDictionary* m_completedMappacks;
	cocos2d::CCDictionary* m_completedLists;
	cocos2d::CCDictionary* m_weeklyChest;
	cocos2d::CCDictionary* m_treasureRoomChests;
	// geode::SeedValueSRV m_bonusKey;
	cocos2d::CCDictionary* m_miscChests;
	cocos2d::CCDictionary* m_enabledItems;
	bool m_unkBoolIncrementStat;
	cocos2d::CCDictionary* m_unkDict;
	cocos2d::CCDictionary* m_unlockedItems;
	std::map<int, UnlockType> m_accountIDForIcon;
	std::map<int, std::string> m_usernameForAccountID;
	bool m_GS29;
	int m_activePath;
};


#endif // __GAMESTATSMANAGER_H__
