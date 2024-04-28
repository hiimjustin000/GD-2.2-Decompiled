#ifndef __LEVELFEATURELAYER_H__
#define __LEVELFEATURELAYER_H__

/* What We have in here may be the Code to Robtop's Feature sender thingy 
 * as seen on his twitch stream : https://youtube.com/watch?v=eBcUC9lYLdI
 * the way I was able to figure that out was due to the numbers cruched on 
 * the placeholder for Some Strange reason I had found it in the android copy 
 * of the game so I thought it would be funny if I reverse engineered it.
 * 
 * This code might be useful to someone making a gdps server btw. 
 * - Calloc */

#include "../includes.h"


/// @brief This might Be Robtop's Feature tool for when he is detimining 
// if a level is going to be featured or not
class LevelFeatureLayer : public FLAlertLayer {
public:

    LevelFeatureLayer():
        m_label(nullptr), 
        m_levelID(0),
        m_place(0),
        m_epicCoin(nullptr){}


	  /// @brief  Creates a Level Feature level
	  /// @param ID the levelID of the level Robtop Wants to feature...
	  /// @return `LevelFeatureLayer*`
	  static LevelFeatureLayer* create(int ID);

	  /// @brief Initalizes The LevelFeatureLayer
	  /// @param ID The ID of the Level
	  /// @return true if init was sucessful, False if Failure...
	  bool init(int ID);
	
    /// @brief Closes Robtop's Feature Layer...
    void keyBackClicked();
    
    /// @brief Closes Robtop's Feature Layer...
    /// @param sender 
    void onClose(cocos2d::CCObject* sender);
	
    /// @brief Moves Robtop's Cursor down by 1
    /// @param sender 
    void onDown(cocos2d::CCObject* sender);
    

	  /// @brief Moves Robtop's Cursor down by 10
	  /// @param sender 
    void onDown2(cocos2d::CCObject* sender);
	
    /// @brief Removes the Values of the given level
	  /// @param sender 
    void onRemoveValues(cocos2d::CCObject* sender);
	
    /// @brief Sets the level to only being epic
	  /// @param sender 
	  void onSetEpicOnly(cocos2d::CCObject* sender);
    
	  /// @brief Sets a Level To being Featured
	  /// @param sender 
	  void onSetFeatured(cocos2d::CCObject* sender);

	  /// @brief Toggles Epic Feature Rating on and off 
	  /// @param sender 
	  void onToggleEpic(cocos2d::CCObject* sender);

	  /// @brief Moves Robtop's Cursor Feature cusor up by 1 
	  /// @param sender a dummy object
	  void onUp(cocos2d::CCObject* sender);

    /// @brief Moves Robtop's Cursor Feature cusor up by 1 
	  /// @param sender a dummy object
	  void onUp2(cocos2d::CCObject* sender);

    /* Seems Robtop has the ability to alter the amount of stars a level has, Pretty neat shit robtop :) */

    /// @brief Updates a given amount of stars on the label class member TBH I'm not sure what it does...
    void updateStars();

    /* I'm so confident that I will share the offsets of this one... */

    cocos2d::CCLabelBMFont * m_label; // 0x1f0	
    int	m_levelID; // 0x1f4	
    unsigned int m_place; // 0x1f8	
    bool m_epic; // 0x1fc	
    cocos2d::CCSprite *	m_epicCoin; // 0x200	

};

#endif // __LEVELFEATURELAYER_H__
