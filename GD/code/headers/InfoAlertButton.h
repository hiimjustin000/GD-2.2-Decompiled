#ifndef __INFOALERTLAYER_H__
#define __INFOALERTLAYER_H__

#include "includes.h"



/* There's nothing too special about this popup other than it's the ('i') button in the corners.... */
class InfoAlertButton: public CCMenuItemSpriteExtra {
public:
    /* This is a placeholder variable for now it likely corresponds to a 
     * lower class object like CCMenuItemSpriteExtra that hasn't been uncovered yet...
     it's offset is 0x117 to anyone that wants to go out and find it... */
    bool m_show; 
    
    std::string m_title;
    std::string m_desc;
    float m_textScale;
    bool m_scroll;

    InfoAlertButton(): m_title(""), m_desc(""), m_textScale(0.0), m_scroll(false){}
    void activate();
    static InfoAlertButton* create(std::string title, std::string desc, float scale);
    bool init(std::string title, std::string desc, float scale);

};

#endif // __INFOALERTLAYER_H__