#ifndef __BOOMSCROLLLAYER_H__
#define __BOOMSCROLLLAYER_H__


#include "../includes.h"

/* TODO */
class ExtendedLayer;


class DynamicScrollDelegate {
	virtual void updatePageWithObject(cocos2d::CCObject* p0, cocos2d::CCObject* p1) {}
};

class BoomScrollLayerDelegate {
public:
	virtual void scrollLayerScrollingStarted(BoomScrollLayer*);
	virtual void scrollLayerScrolledToPage(BoomScrollLayer*, int);
	virtual void scrollLayerMoved(cocos2d::CCPoint);
	virtual void scrollLayerWillScrollToPage(BoomScrollLayer*, int);
};


class BoomScrollLayer : public cocos2d::CCLayer {

public:
	static BoomScrollLayer* create(cocos2d::CCArray*, int, bool, cocos2d::CCArray*, DynamicScrollDelegate*);
	static BoomScrollLayer* create(cocos2d::CCArray*, int, bool);

	void addPage(cocos2d::CCLayer*, int);
	void addPage(cocos2d::CCLayer*);
	void cancelAndStoleTouch(cocos2d::CCTouch*, cocos2d::CCEvent*);
	TodoReturn claimTouch(cocos2d::CCTouch*);
	cocos2d::CCLayer* getPage(int);
	int getRelativePageForNum(int);
	cocos2d::CCPoint getRelativePosForPage(int);
	unsigned int getTotalPages();
	bool init(cocos2d::CCArray*, int, bool, cocos2d::CCArray*, DynamicScrollDelegate*);
	TodoReturn instantMoveToPage(int);
	TodoReturn moveToPage(int);
	TodoReturn moveToPageEnded();
	TodoReturn pageNumberForPosition(cocos2d::CCPoint);
	TodoReturn positionForPageWithNumber(int);
	TodoReturn quickUpdate();
	TodoReturn removePage(cocos2d::CCLayer*);
	TodoReturn removePageWithNumber(int);
	TodoReturn repositionPagesLooped();
	TodoReturn selectPage(int);
	void setDotScale(float);
	void setPagesIndicatorPosition(cocos2d::CCPoint);
	TodoReturn setupDynamicScrolling(cocos2d::CCArray*, DynamicScrollDelegate*);
	TodoReturn togglePageIndicators(bool);
	TodoReturn updateDots(float);
	TodoReturn updatePages();

	virtual void visit();
	virtual bool ccTouchBegan(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void ccTouchMoved(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void ccTouchEnded(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void ccTouchCancelled(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void registerWithTouchDispatcher();

    cocos2d::CCArray* m_pageIndicators;
    int m_unkInt;
    float m_unkFloat;
    int PAD;
    bool m_loopedPages;
    DynamicScrollDelegate* m_dynamicScrollDelegate;
    cocos2d::CCArray *m_pages2;
	bool m_unkBool;
	int m_time; /* I belive it is this? */
	bool m_cancellingTouch;
	cocos2d::CCTouch *m_touch;
    cocos2d::CCArray *m_pages;
    cocos2d::CCPoint m_extendedPos;
	ExtendedLayer *m_extendedLayer;
	cocos2d::CCRect m_rect;

	BoomScrollLayerDelegate *m_boomScrollLayerDelegate;
    bool m_running;
    bool m_PageVisible;

	float field61_0x1ac;
    int field62_0x1b0;
    float field63_0x1b4;
    bool field64_0x1b8;
    
    cocos2d::CCPoint m_pagesIndicatorPosition;
	int m_currentPage;
    float m_width; 
	float m_height; /* I think? */
	bool m_visited;
};
