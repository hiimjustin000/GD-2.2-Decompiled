#ifndef __UIBUTTONCONFIG_H__
#define __UIBUTTONCONFIG_H__

#include "../includes.h"

class UIButtonConfig {
public:
    UIButtonConfig(){}
	void reset();
	void resetOneBtn();
	int	m_width;
    int	m_height;
    int	m_deadZone;
    float m_buttonScale;	
    int	m_opacity;
    float m_dragRadius;	
    bool m_toggle;
    bool m_visible;	
	cocos2d::CCPoint m_pos;	
    bool m_isJump;
    bool m_fillsScreen;	
    bool m_noMove;
};

#endif // __UIBUTTONCONFIG_H__