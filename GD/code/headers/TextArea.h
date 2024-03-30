#ifndef __TEXTAREA_H__
#define __TEXTAREA_H__

#include "includes.h"



class TextArea : public cocos2d::CCTextFieldTTF {
public:
    bool m_disableColor;
    MultilineBitmapFont *m_label;
    float m_maxWidth;
    
    std::string m_fontFile;
    float m_lineSpace;
    bool m_onTimer;
    cocos2d::CCPoint m_align;
    bool m_fadeFinished;
    float m_fontScale;
    float m_textHeight;
    float m_textWidth;
    cocos2d::CCPoint m_textPosition;

    cocos2d::CCDictionary* m_dict;

    TextArea():   
            m_disableColor(false),
            m_label(nullptr),
            m_maxWidth(0.0),
            m_fontFile(""),
            m_lineSpace(0.0),
            m_onTimer(false),
            m_align(CCPointMake(0.0, 0.0)),
            m_fadeFinished(false),
            m_fontScale(0.0),
            m_textHeight(0.0),
            m_textWidth(0.0),
            m_textPosition(CCPointMake(0.0, 0.0)){
    }

    void colorAllCharactersTo(cocos2d::_ccColor3B); /* TODO */

    static TextArea* create(std::string str, const char *font,float scale,float width, cocos2d::CCPoint anchor, float lineHeight, bool disableColor);

    /* noop */
    void draw();

    bool init(std::string str, char const* font, float scale, float width, cocos2d::CCPoint anchor, float lineHeight, bool disableColor);
    virtual void keyBackClicked();

    void levelUploadFailed(GJGameLevel* level);
    void setString (std::string str);

    void colorAllCharactersTo(cocos2d::ccColor3B color);
    void colorAllLabels(cocos2d::ccColor3B color);

    void fadeInCharacters(float, float);
    void fadeOut(float opacity);
    void fadeOutAndRemove();
    /* TODO Has an unsolvable field currently... */
    void finishFade();
    void hideAll();

    void setIgnoreColorCode(bool value);
    void setOpacity(unsigned char opacity);
    void showAll();

    void stopAllCharacterActions();

    /* TODO */
    void update(float);
};

#endif // __TEXTAREA_H__