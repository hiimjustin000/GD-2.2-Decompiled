#ifndef ENDLEVELLAYER_H
#define ENDLEVELLAYER_H

#include "../includes.h"

class EndLevelLayer : public GJDropDownLayer {

public:
	static EndLevelLayer* create(PlayLayer*);

	void coinEnterFinished(cocos2d::CCPoint);
	void coinEnterFinishedO(cocos2d::CCObject*);
	void currencyEnterFinished();
	void diamondEnterFinished();
	TodoReturn getCoinString();
	const char* getEndText();
	void goEdit();
	bool init(PlayLayer*);
	void onEdit(cocos2d::CCObject* sender);
	void onEveryplay(cocos2d::CCObject* sender);
	void onLevelLeaderboard(cocos2d::CCObject* sender);
	void onMenu(cocos2d::CCObject* sender);
	void onReplay(cocos2d::CCObject* sender);
	void playCoinEffect(float);
	void playCurrencyEffect(float);
	void playDiamondEffect(float);
	void playEndEffect();
	void playStarEffect(float);
	TodoReturn starEnterFinished();
	TodoReturn tryShowBanner(float);

	virtual void keyBackClicked();
	virtual void keyDown(cocos2d::enumKeyCodes);
	virtual void customSetup();
	virtual void showLayer(bool);
	virtual void enterAnimFinished() {}
	virtual void keyUp(cocos2d::enumKeyCodes) {}

	PlayLayer* m_playLayer;
	bool m_unknown1;
	bool m_unknown2;
	bool m_unknown3;
	bool m_unknown4;
	bool m_unknown5;
	int m_unknown6;
	cocos2d::CCArray* m_coinsToAnimate;
};




#endif // ENDLEVELLAYER_H
