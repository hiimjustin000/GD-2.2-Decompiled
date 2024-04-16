#ifndef __GJUINODE_H__
#define __GJUINODE_H__

#include "../includes.h"

/* Some information is out of reach at the moment as I am still determining names... */

class GJUINode : public cocos2d::CCNode {
	// virtual ~GJUINode();

public:
	static GJUINode* create(UIButtonConfig& config);

	TodoReturn activeRangeTouchTest(cocos2d::CCPoint);
	TodoReturn activeTouchTest(cocos2d::CCPoint);
	TodoReturn getButtonScale();
	TodoReturn getOpacity();
	TodoReturn highlightButton(int);
	bool init(UIButtonConfig& config);
	void loadFromConfig(UIButtonConfig& config);
	TodoReturn resetState();
	void saveToConfig(UIButtonConfig& config);
	void setOpacity(unsigned char value);
	TodoReturn toggleHighlight(int, bool);
	void toggleModeB(bool toggle);
	TodoReturn touchEnded();
	TodoReturn touchTest(cocos2d::CCPoint);
	TodoReturn updateButtonFrames();
	TodoReturn updateButtonPositions();
	TodoReturn updateButtonScale(float);
	TodoReturn updateDeadzone(int);
	TodoReturn updateDragRadius(float);
	TodoReturn updateHeight(float);
	TodoReturn updateRangePos(cocos2d::CCPoint);
	void updateSize(float width, float height);
    void updateWidth(float);

	virtual void draw();


};


#endif // __GJUINODE_H__