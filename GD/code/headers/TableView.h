#ifndef __TABLEVIEW_H__
#define __TABLEVIEW_H__

#include "includes.h"


enum CellAction{
};


class CCIndexPath : public cocos2d::CCObject {
public:
	CCIndexPath() {}
	// virtual ~CCIndexPath();

	static CCIndexPath* CCIndexPathWithSectionRow(int _x, int _y);
	void operator=(CCIndexPath* other);


    /* Idk what else to call these just yet... */
    int m_x;
    int m_y;
};


class TableViewCellDelegate {
	virtual void cellPerformedAction(TableViewCell*, int, CellAction, cocos2d::CCNode*);
	virtual void getSelectedCellIdx();
	virtual void shouldSnapToSelected();
};


enum TableViewCellEditingStyle{
};

class TableViewDataSource {
	virtual int numberOfRowsInSection(unsigned int, TableView*) { return 0; }
	virtual unsigned int numberOfSectionsInTableView(TableView*) { return 0; }
	virtual void TableViewCommitCellEditingStyleForRowAtIndexPath(TableView*, TableViewCellEditingStyle style, CCIndexPath&) {}
	virtual TableViewCell* cellForRowAtIndexPath(CCIndexPath&, TableView*) { return nullptr; }
};



class TableViewCell : public cocos2d::CCLayer {
	// ~TableViewCell();
public:
	TableViewCell() {};
	TableViewCell(const char *name, float width, float height){
		m_width = width;
		m_height = height;
  		m_x = 0;
  		m_y = 0;
		m_backgroundLayer = cocos2d::CCLayerColor::create({0, 0, 0, 0},width,height);
		addChild(m_backgroundLayer, -1);
  		m_mainLayer = cocos2d::CCLayer::create();
  		m_name = name;
		m_unknownThing = 0;
		m_tableView = nullptr;
	};
	
	void updateVisibility();

	bool m_unknown;
	TableView* m_tableView;
	CCIndexPath m_indexPath;
	int m_x; /* was m_unknown2 they correspond to CCIndexPath */
	int m_y; /* was m_unknown3 they correspond to CCIndexPath */
	int m_unknownThing; // "don't even know if this is an int, it's always set to 0" - Bindings
	std::string m_name;
	float m_width;
	float m_height;
	cocos2d::CCLayerColor* m_backgroundLayer;
	cocos2d::CCLayer* m_mainLayer;
	BoomListType m_listType;
};




class TableView : public CCScrollLayerExt, public CCScrollLayerExtDelegate {

public:
    TableView(){}
    TableView(cocos2d::CCRect rect);

	static TableView* create(
        TableViewDelegate* viewDelegate, 
        TableViewDataSource* source, 
        TableViewCellDelegate* delegate, 
        cocos2d::CCRect rect
    );

	void cancelAndStoleTouch(cocos2d::CCTouch*, cocos2d::CCEvent*);
	TableViewCell* cellForRowAtIndexPath(CCIndexPath& idx);
	TableViewCell* cellForTouch(cocos2d::CCTouch*);
	int checkBoundaryOfCell(cocos2d::CCPoint&, float);
	int checkBoundaryOfCell(TableViewCell*);
	void checkBoundaryOfContent(float);
	TodoReturn checkFirstCell(TableViewCell*);
	TodoReturn checkLastCell(TableViewCell*);
	TodoReturn claimTouch(cocos2d::CCTouch*);
	TodoReturn deleteTableViewCell(TableViewCell*);
	TodoReturn dequeueReusableCellWithIdentifier(char const*);
	TodoReturn initTableViewCells();
	bool isDuplicateIndexPath(CCIndexPath&);
	bool isDuplicateInVisibleCellArray(CCIndexPath*);
	void reloadData();
	TodoReturn removeIndexPathFromPathAddedArray(CCIndexPath&);
	TodoReturn scrollToIndexPath(CCIndexPath&);
	TodoReturn touchFinish(cocos2d::CCTouch*);

	virtual void onEnter();
	virtual void onExit();
	virtual bool ccTouchBegan(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void ccTouchMoved(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void ccTouchEnded(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void ccTouchCancelled(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void registerWithTouchDispatcher();
	virtual void scrollWheel(float, float);
	virtual void scrllViewWillBeginDecelerating(CCScrollLayerExt*) {}
	virtual void scrollViewDidEndDecelerating(CCScrollLayerExt*) {}
	virtual void scrollViewTouchMoving(CCScrollLayerExt*);
	virtual void scrollViewDidEndMoving(CCScrollLayerExt*) {}

	bool m_touchOutOfBoundary;
	cocos2d::CCTouch* m_touchStart;
	cocos2d::CCPoint m_touchStartPosition2;
	cocos2d::CCPoint m_unknown2;
	cocos2d::CCPoint m_touchPosition2;
	void* m_idk;
	bool m_touchMoved;
	cocos2d::CCArray* m_cellArray;
	cocos2d::CCArray* m_array2;
	cocos2d::CCArray* m_array3;
	TableViewDelegate* m_tableDelegate;
	TableViewDataSource* m_dataSource;
	TableViewCellDelegate* m_cellDelegate;
	int m_unused2;
	void* m_unused3;
	int m_unused4;
	float m_touchLastY;
	bool m_cancellingTouches;
};





#endif // __TABLEVIEW_H__
