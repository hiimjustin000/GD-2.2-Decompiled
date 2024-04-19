
#pragma once 

#include "includes.h"

enum GJErrorCode {
};



class GJDailyLevelDelegate {
	virtual void dailyStatusFinished(GJTimedLevelType type) {}
	virtual void dailyStatusFailed(GJTimedLevelType type, GJErrorCode error) {}
};

class LevelDownloadDelegate {
	virtual void levelDownloadFinished(GJGameLevel* level) {}
	virtual void levelDownloadFailed(int ID) {}
};


class DailyLevelPage : public FLAlertLayer, FLAlertLayerProtocol, GJDailyLevelDelegate, LevelDownloadDelegate {
	// virtual ~DailyLevelPage();

	static DailyLevelPage* create(GJTimedLevelType);

	TodoReturn claimLevelReward(DailyLevelNode*, GJGameLevel*, cocos2d::CCPoint);
	TodoReturn createDailyNode(GJGameLevel*, bool, float, bool);
	TodoReturn createNodeIfLoaded();
	TodoReturn downloadAndCreateNode();
	TodoReturn exitDailyNode(DailyLevelNode*, float);
	TodoReturn getDailyTime();
	TodoReturn getDailyTimeString(int);
	bool init(GJTimedLevelType);
	void onClose(cocos2d::CCObject* sender);
	void onTheSafe(cocos2d::CCObject* sender);
	TodoReturn refreshDailyPage();
	TodoReturn skipDailyLevel(DailyLevelNode*, GJGameLevel*);
	TodoReturn tryGetDailyStatus();

	void updateTimers(float);

	virtual void registerWithTouchDispatcher();
	virtual void keyBackClicked();
	virtual void show();
	virtual void FLAlert_Clicked(FLAlertLayer*, bool) {}
	virtual void dailyStatusFinished(GJTimedLevelType);
	virtual void dailyStatusFailed(GJTimedLevelType, GJErrorCode);
	virtual void levelDownloadFinished(GJGameLevel*);
	virtual void levelDownloadFailed(int);

	cocos2d::CCLabelBMFont* m_timeLabel;
	LoadingCircle* m_timeCircle;
	LoadingCircle* m_nodeCircle;
	bool m_gettingDailyStatus;
	DailyLevelNode* m_dailyNode;
	bool m_downloadStarted;
	GJTimedLevelType m_type;
	int m_downloadLevelID;
};


