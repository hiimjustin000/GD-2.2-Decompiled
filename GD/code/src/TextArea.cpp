#include "includes.h"


void TextArea::colorAllCharactersTo(cocos2d::ccColor3B color){
    cocos2d::CCObject *_line;
    cocos2d::CCArray* line;
    
    CCARRAY_FOREACH(m_label->getChildren(), _line){
        line = reinterpret_cast<cocos2d::CCArray*>(_line);
        arrayMakeObjectsPerformSelectorWithObject(line, setColor, color, cocos2d::CCSprite*);
    }
}

void TextArea::colorAllLabels(cocos2d::ccColor3B color){
    arrayMakeObjectsPerformSelectorWithObject(m_label->m_delayedText, updateDisplayedColor, color, cocos2d::CCLabelBMFont*);
}

TextArea* TextArea::create(std::string str, const char *font,float scale,float width, cocos2d::CCPoint anchor, float lineHeight,bool disableColor){
    TextArea* obj = new TextArea;
    if (obj != nullptr && obj->init(str, font, scale, width, anchor , lineHeight, disableColor)){
        obj->autorelease();
        return obj;
    }
    CC_SAFE_DELETE(obj);
    return nullptr;
}

/* noop */
void TextArea::draw(){
    return;
}

/* belongs to Dialouge objects or NPCs */
void TextArea::fadeInCharacters(float _x, float _y){
    if (m_dict != nullptr){
        m_dict->release();
        m_dict = nullptr;
    }
    m_dict = cocos2d::CCDictionary::create();
    bool _update = false;
    m_dict->retain();

    for (unsigned int i = 0; i < m_label->getChildrenCount(); i++){
        /* TODO... it's a pretty deep function... */
    }
    _update ?  this->scheduleUpdate() : this->unscheduleUpdate();
}


void TextArea::fadeOut(float opacity){
    stopAllActions();
    stopAllCharacterActions();
    runAction((cocos2d::CCActionTween::create(opacity, "opacity", getOpacity(), 0)));
}


void TextArea::fadeOutAndRemove(){
    fadeOut(0.3);
    this->runAction(
        cocos2d::CCSequence::create(
            cocos2d::CCDelayTime::create(0.3), 
            cocos2d::CCCallFunc::create(
                this, /* unknown */ nullptr), 0)
            );
}




/* if anyone would like to figure out field_0x23c be my guest... */

// void __thiscall TextArea::finishFade(TextArea *this)

// {
//   undefined4 *puVar1;
  
//   this->m_fadeFinished = true;
//   puVar1 = this->field526_0x23c;
//   if (puVar1 != (undefined4 *)0x0) {
                                            
//     (**(code **)*puVar1)(puVar1,this);
//     return;
//   }
//   return;
// }




void TextArea::hideAll(){
    stopAllCharacterActions();
    setOpacity(0);
}

bool TextArea::init(std::string str, const char *font, float scale, float width, cocos2d::CCPoint anchor,
               float lineHeight, bool disableColor)
{

    if (cocos2d::CCSprite::init())
    {
        m_maxWidth = width;
        m_align = anchor;
        m_fontFile = font;
        m_fontScale = scale;
        m_lineSpace = lineHeight;
        m_disableColor = disableColor;
        setString(str);
        return true;
    }
    return false;
}

void TextArea::setIgnoreColorCode(bool value)
{
    m_disableColor = value;
    if (m_label != nullptr) {
        m_label->m_colorEnabled = value;
    }
}

void TextArea::setOpacity(unsigned char opacity){
    cocos2d::CCSprite::setOpacity(opacity);
    /* Also set bitmap's opacity of all the lines and letters... */
    m_label->setOpacity(opacity);
}




void TextArea::setString(std::string str){
    bool empty = str == "";
    if (empty){
        empty = str.length() == 0;
    }
    if (empty){
        str.assign(" ");
    }

    if (m_label != nullptr){
        hideAll();
        /* On windows this is false for some reason and on Android this is set to true... */
        m_label->removeAllChildrenWithCleanup(true);
        /* Clean out all other callbacks... */
        m_label->removeFromParentAndCleanup(true);
        m_label = nullptr;
    }

    /* NOTE: On windows this call would be MultilineBitmapFont::create() */
    m_label = MultilineBitmapFont::createWithFont(m_fontFile.c_str(), str, m_fontScale, m_maxWidth, m_align, m_lineSpace, m_disableColor);
    /* Set our data to TextArea... */
    m_align = m_label->m_position;
    m_textWidth = m_label->m_textWidth;
    m_textHeight = m_label->m_textHeight;

    setTextureRect(CCRectMake(0.0, 0.0, m_textWidth, m_textHeight));
    
    m_label->addChild(m_label, 1);
    m_maxWidth = m_textWidth * m_align.x;
    m_fontScale = m_textHeight;
    m_align = CCPointMake(m_maxWidth, m_fontScale * m_align.y);
    m_label->setPosition(m_align);
}



/* TextArea::showAll() */

void TextArea::showAll(){
    stopAllCharacterActions();
    setOpacity(0xff);
    m_fadeFinished = true;
    return;
}




/* NOTE: TextArea's Children Are CCLabelBMFonts... */
/*  I'm going to simplify this function for you since 
    I do not feel like going all the way down to _ccArray* 
    Like the Ghidra's decompiler is showing me. 

    It was likely an Optimization by Robtop or the Compiler. 

    UPDATE: it's actually a macro...
*/


/* shoutouts to acaruso for help with understanding this one... */
void TextArea::stopAllCharacterActions(){
    cocos2d::CCArray *chrArray, *lines = m_label->getChildren();
    cocos2d::CCObject* line;
    CCARRAY_FOREACH(lines, line){
        chrArray = reinterpret_cast<cocos2d::CCLabelBMFont*>(line)->getChildren();
        arrayMakeObjectsPerformSelector(chrArray, stopAllActions, cocos2d::CCSprite*);
    }
}


/* TODO: TextArea::update(float) it's just More tricky shit... */



