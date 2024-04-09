#ifndef __GAMECELL_H__
#define __GAMECELL_H__

#include "includes.h"

/* Documented by Calloc */

class GameCell : public TableViewCell {
public:
	/// @brief Creates a new `GameCell` Under the following attributes
	/// @param name the name of the cell
	/// @param width the width of the cell 
	/// @param height the height of the cell
	GameCell(char const* name, float width, float height);

	/// @brief Used to create a promotion from a given String Name
	/// @param str the nickname/key string for the url to load/promote 
	void loadFromString(std::string str);
	
	/// @brief the event that happens where the `GameCell` has been Clicked
	/// @param sender a dummy object to run the event on through with
	void onTouch(cocos2d::CCObject* sender);

	/// @brief Used to alter the background color of the `GameCell`
	/// @param color the color to update the gamecell with
	void updateBGColor(int color);

	virtual bool init();
	virtual void draw();

	/* m_smartTemplate may have been Wylite's missing object in the previous version... */

	GJSmartTemplate * m_smartTemplate;	
	std::string m_url;
};


#endif // __GAMECELL_H__
