#ifndef __TEXTSTYLESECTION_H__
#define __TEXTSTYLESECTION_H__

#include "includes.h"

typedef enum TextStyleType
{
    kTextStyleSectionDefault = 0,
    kTextStyleSectionColoredSection = 1,
    kTextStyleSectionInstantSection = 2,
    kTextStyleSectionShakeSection = 3,
    kTextStyleSectionDelaySection = 4
} TextStyleType;

/* NOTE: DelaySection & InstantSection have been merged in 2.2 to 
 * TextStyleSection */

class TextStyleSection : public cocos2d::CCObject
{
public:
    TextStyleType m_style;
    int m_start;
    int m_end;
    cocos2d::ccColor3B m_color;
    float m_instant;
    float m_delay;
    int m_shakeX;
    int m_shakeY;

    TextStyleSection();

    /* static calls */
    /* NOTE I put _ infront of unconfirmed parameters */
    static TextStyleSection *create(int _start, int _end, TextStyleType style);
    static TextStyleSection *createColoredSection(cocos2d::ccColor3B color, int _start, int _end);
    static TextStyleSection *createDelaySection(int _start, float delay);
    static TextStyleSection *createInstantSection(int _start, int _end, float _instant);
    static TextStyleSection *createShakeSection(int _start, int _end, int shakeX, int shakeY);
    /* non-static */
    bool init(int _start, int _end, TextStyleType style);
};

#endif // __TEXTSTYLESECTION_H__