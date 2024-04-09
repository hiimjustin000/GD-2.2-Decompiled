#include "includes.h"

void ListCell::draw()
{
    auto size = CCSizeMake(m_width, m_height);
    cocos2d::ccDrawColor4B(m_lineColor.r, m_lineColor.g, m_lineColor.b, m_lineColor.a);
    glLineWidth(2.0f);
    cocos2d::ccDrawLine(CCPointMake(1.0, size.width), CCPointMake(size.width - 1.0, size.height));
}

bool ListCell::init(){
    return true;
}

/* -- NOOPS -- */
void ListCell::loadFromObject(cocos2d::CCObject *unkObj, int unkInt1, int unkInt2, int unkInt3){}
void ListCell::updateBGColor(int color){}
