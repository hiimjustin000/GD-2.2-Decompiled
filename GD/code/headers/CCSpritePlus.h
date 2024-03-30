#ifndef __CCSPRITEPLUS_H__
#define __CCSPRITEPLUS_H__

#include "includes.h"

/* Core Component in all GameObjects */
class CCSpritePlus : public cocos2d::CCSprite {

public:
	cocos2d::CCArray* m_followers;
	CCSpritePlus* m_followingSprite;
	bool m_hasFollower;
	bool m_propagateScaleChanges;
	bool m_propagateFlipChanges;

	void addFollower(cocos2d::CCNode* sprite);
	
    static CCSpritePlus* createWithSpriteFrame(cocos2d::CCSpriteFrame* frame);
    static CCSpritePlus* createWithSpriteFrameName(char const*);
	void followSprite(CCSpritePlus* sprite);
    
	
    cocos2d::CCSprite * getFollower();
    bool initWithSpriteFrameName(char *name);
    bool initWithTexture (cocos2d::CCTexture2D * texture);
    void removeFollower(cocos2d::CCNode* sprite);
    
    /* -- overrides -- */

    void setFlipX(bool value);
    void setFlipY(bool value);
    void setPosition(cocos2d::CCPoint const &pos);
	void setRotation(float fRotation);
    void setRotationX(float fRotationX);
    void setRotationY(float fRotationY);
    void setScale(float fScale);
    void setScaleX(float fScaleX);
    void setScaleY(float fScaleY);

    void stopFollow();
};

#endif // __CCSPRITEPLUS_H__