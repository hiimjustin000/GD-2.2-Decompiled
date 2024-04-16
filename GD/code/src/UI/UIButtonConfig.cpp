#include "includes.h"


void UIButtonConfig::reset(){
    m_toggle = false;
    m_width = 0x118;
    m_height = 0x78;
    m_deadZone = 0;
    m_buttonScale = 1.0;
    m_opacity = 0xff;
    m_dragRadius = 10.0;
    m_pos = CCPointMake(95.0,36.0);
    m_isJump = false;
    m_fillsScreen = false;
    m_visible = false;
    m_noMove = false;
}


void UIButtonConfig::resetOneBtn()
{
    reset();
    m_width = 200;
    m_height = 200;
    cocos2d::CCPoint pos = CCPointMake(95.0,36.0);

    /* Robtop, What is this supposed to do? */
    m_pos = CCPointMake(pos.x, pos.y + 60.0 + 100.0);

    /* Maybe it's actually this? 
     * m_pos = CCPointMake(pos.x  + 60.0, pos.y + 100.0)
     */
}
