#pragma once
#include "includes.h"


class DailyLevelNode : public cocos2d::CCNode, FLAlertLayerProtocol {
	// virtual ~DailyLevelNode();

	static DailyLevelNode* create(GJGameLevel* level, DailyLevelPage* page, bool);

	bool init(GJGameLevel* level, DailyLevelPage* page, bool);
	void onClaimReward(cocos2d::CCObject* sender);
	void onSkipLevel(cocos2d::CCObject* sender);
	void showSkipButton();
	void updateTimeLabel(std::string);

	virtual void FLAlert_Clicked(FLAlertLayer*, bool);

	GJGameLevel* m_level;
	DailyLevelPage* m_page;
	cocos2d::CCLabelBMFont* m_timeLabel;

	CCMenuItemSpriteExtra* m_skipButton;
	bool m_unkBool;
	bool m_needsDownloading;
};

