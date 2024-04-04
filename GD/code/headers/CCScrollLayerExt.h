/*
 *  There's a few simillarities so I wanted to point out this source 
 *  CCScrollLayerExt.h
 * SEE: https://github.com/jandujar/cocos2d-x-extensions/blob/74c5f0c883f3c2fd85b53e194b4f6c4170b5784a/extensions/CCScrollLayerExt/CCScrollLayerExt.h
 * 
 *  Modified by Robtop 
 *  Reverse Engineered by Calloc 
 *  Discovered by Acaruso
 */

#ifndef _CCSCROLLLAYER_EXT_H
#define _CCSCROLLLAYER_EXT_H

#include "includes.h"


class CCContentLayer : public cocos2d::CCLayerColor {
public:
	inline CCContentLayer() {}
	~CCContentLayer();
	static CCContentLayer* create(cocos2d::ccColor4B const&, float, float);
	virtual void setPosition(cocos2d::CCPoint const&);
};


class CCScrollLayerExtDelegate {	
public:
	virtual void scrollViewWillBeginDecelerating(CCScrollLayerExt*) {}
	virtual void scrollViewDidEndDecelerating(CCScrollLayerExt*) {}
	virtual void scrollViewTouchMoving(CCScrollLayerExt*) {}
	virtual void scrollViewDidEndMoving(CCScrollLayerExt*) {}
	virtual void scrollViewTouchBegin(CCScrollLayerExt*) {}
	virtual void scrollViewTouchEnd(CCScrollLayerExt*) {}
};


/* Help with missing functions in CCScrollLayerExt.cpp would be appreciated */

class CCScrollLayerExt : public cocos2d::CCLayer {
public:
	CCScrollLayerExt(){}
	CCScrollLayerExt(cocos2d::CCRect rect);

	TodoReturn constraintContent();
	TodoReturn doConstraintContent(bool);
	float getMaxY();
	float getMinY();
	void moveToTop();
	void moveToTopWithOffset(float);
	void scrollingEnd();
	void scrollLayer(float);
	void setContentLayerSize(cocos2d::CCSize);
	void setContentOffset(cocos2d::CCPoint, bool);
	TodoReturn updateIndicators(float);

	virtual void visit();
	virtual bool ccTouchBegan(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void ccTouchMoved(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void ccTouchEnded(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void ccTouchCancelled(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void registerWithTouchDispatcher();
	virtual void preVisitWithClippingRect(cocos2d::CCRect);
	virtual void postVisit();


	cocos2d::CCTouch* m_touch;
	cocos2d::CCPoint m_touchPosition;
	cocos2d::CCPoint m_touchStartPosition;
	cocos2d::cc_timeval m_timeValue;
	bool m_touchDown;
	bool m_notAtEndOfScroll;
	cocos2d::CCLayerColor* m_verticalScrollbar;
	cocos2d::CCLayerColor* m_horizontalScrollbar;
	CCScrollLayerExtDelegate* m_delegate;
	CCContentLayer* m_contentLayer;
	bool m_cutContent;
	bool m_vScrollbarVisible;
	bool m_hScrollbarVisible;
	bool m_disableHorizontal;
	bool m_disableVertical;
	bool m_disableMovement;
	float m_scrollLimitTop;
	float m_scrollLimitBottom;
	float m_peekLimitTop;
	float m_peekLimitBottom;
};

#endif
