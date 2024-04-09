#include "includes.h"

class ListCell : public TableViewCell
{
public:
	ListCell(char const* name, float width, float height);

	void loadFromObject(cocos2d::CCObject*, int, int, int);
	void updateBGColor(int color);

	virtual bool init();
	virtual void draw();

	cocos2d::ccColor4B m_lineColor;
};
