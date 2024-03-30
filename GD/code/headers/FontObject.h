#ifndef __FONTOBJECT_H__
#define __FONTOBJECT_H__

#include "includes.h"


/* TODO: Move to a sperate file called TextGameObject.h if anyone wants to reverse it feel free - Calloc */
class TextGameObject : public GameObject {
public:
    int m_kerning;

};


class FontObject : public cocos2d::CCObject {
public:
    TextGameObject m_textObject;
    
    /* TODO Unless someone else would like to reverse these functions... */
    static FontObject* createWithConfigFile(char const* fileName, float _Size);
    bool initWithConfigFile(const char* fileName, float _Size);
    void parseConfigFile(char const* fileName, float _Size);
    int getFontWidth(int _unkWidth);
    
};



#endif // __FONTOBJECT_H__