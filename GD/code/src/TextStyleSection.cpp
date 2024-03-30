#include "includes.h"




TextStyleSection* TextStyleSection::create(int _start, int _end, TextStyleType style){
    TextStyleSection* tss = new TextStyleSection;
    tss->m_style = kTextStyleSectionDefault;
    tss->m_start = 0;
    tss->m_end = 0;
    if (tss->init(_start, _end, style)) {
        tss->autorelease();
        return tss;
    }
    CC_SAFE_DELETE(tss);
    return nullptr;
}


TextStyleSection* TextStyleSection::createColoredSection(cocos2d::ccColor3B color,int _start,int _end){
    TextStyleSection* tss = create(_start, _end, kTextStyleSectionColoredSection);
    tss->m_color = color;
    return tss;
};

TextStyleSection * TextStyleSection::createDelaySection(int _start, float delay){
    TextStyleSection *tss = create(_start, -1, kTextStyleSectionDelaySection);
    tss->m_delay = delay;
    return tss;
}

TextStyleSection* TextStyleSection::createInstantSection(int _start, int _end,float _instant){
  TextStyleSection *tss = create(_start, _end, kTextStyleSectionInstantSection);
  tss->m_instant = _instant;
  return tss;
}

TextStyleSection * TextStyleSection::createShakeSection(int _start, int _end, int shakeX, int shakeY){
  TextStyleSection *tss = create(_start, _end, kTextStyleSectionShakeSection);
  tss->m_shakeX = shakeX;
  tss->m_shakeY = shakeY;
  return tss;
}

bool TextStyleSection::init(int _start, int _end, TextStyleType style){
    m_start = _start;
    m_end = _end;
    m_style = style;
    return true;
}

