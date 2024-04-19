#include "includes.h"
using cocos2d::SEL_CallFunc;
using cocos2d::SEL_MenuHandler;


class GJDropDownLayerDelegate {
public:
	virtual void dropDownLayerWillClose(GJDropDownLayer*);
};

class GJListLayer;

class GJDropDownLayer : public cocos2d::CCLayerColor {
	GJDropDownLayer();
	~GJDropDownLayer();

	bool init(const char* title, float height);
	bool init(const char* title);
	virtual void disableUI();
	void enableUI();
	void draw();
	virtual void exitLayer(cocos2d::CCObject* obj);
	virtual void hideLayer(bool instantHide);
	void showLayer(bool instantShow);
	void keyBackClicked();
	void layerHidden();
	void registerWithTouchDispatcher();
	void enterLayer();
	void layerVisible();
	void enterAnimFinished() {}
	void customSetup() {}
	GJDropDownLayer* create(const char* title, float height);
	GJDropDownLayer* create(const char* title);

	bool ccTouchBegan() { return true; }
	void ccTouchCancelled() {}
	void ccTouchEnded() {}
	void ccTouchMoved() {}


	cocos2d::CCPoint m_endPosition; /* Fun Fact: Robtop calls this one inPos_ which is less readable than endPosition, Cry about it... ;-; */
	cocos2d::CCPoint m_startPosition;
	cocos2d::CCMenu* m_buttonMenu;
	GJListLayer* m_listLayer;
	bool m_controllerEnabled;
	cocos2d::CCLayer* m_internalLayer; /* Robtop Freebie from his Twitch Stream https://yewtu.be/watch?v=eBcUC9lYLdI at: 12:18 */
	bool m_hidden;
	GJDropDownLayerDelegate* m_delegate;
};
