#ifndef __MULTILINEBITMAPFONT_H__
#define __MULTILINEBITMAPFONT_H__

#include "includes.h"


/* NOTE: Some fields are Commented out since this code has changed a lot since 2.1 */
class MultilineBitmapFont : public cocos2d::CCSprite
{
public:
	// float m_fFontWidth[300];
	// cocos2d::CCArray* m_pColouredTextArray; // ColoredSection*
	// cocos2d::CCArray* m_pInstantTextArray;  // InstantSection*
	// cocos2d::CCArray* m_pDelayedTextArray;  // DelayedSection*
	// cocos2d::CCArray* m_pLetterArray;	    // cocos2d::CCSprite*
	// float m_fHalfScaledFontWidth;
	// bool m_bUnkScaleBool;
	// int unk;
	// cocos2d::CCSize m_obTextureSize;
	// cocos2d::CCPoint m_obPosition;
	// float m_fContentSizeScaleMod;
	// bool m_bTagsDisabled;

	// cocos2d::CCArray* m_letters; /* cocos2d::CCArray<TextStyleSection> */
	cocos2d::CCArray *m_coloredText;
    cocos2d::CCArray *m_instantText;
    cocos2d::CCArray *m_delayedText;
    int field1705_0x6b8;
    char field1706_0x6bc;

    float m_textHeight;
    float m_textWidth;
    cocos2d::CCPoint m_position;

    cocos2d::CCPoint m_textPosition;
    bool m_colorEnabled;


	/* TODO */
	static MultilineBitmapFont* create(const char* fontName, int* str, float scale, float width, cocos2d::CCPoint anchorPoint, bool bColourEnabled);

	/* TODO */
	static MultilineBitmapFont* createWithFont(const char* fontName, std::string str, float scale, float width, cocos2d::CCPoint anchorPoint, int lineSpace, bool bColourEnabled);
	

	std::string readColorInfo(std::string);
	void moveSpecialDescriptors (int pos, int size);
	void setOpacity(unsigned char);
	virtual bool initWithFont(const char* fontName, int* str, float scale, float width, cocos2d::CCPoint anchorPoint, bool bColourEnabled);
	std::string stringWithMaxWidth(std::string, float, float);

	/* To keep everything from breaking */

};



#endif // __MULTILINEBITMAPFONT_H__