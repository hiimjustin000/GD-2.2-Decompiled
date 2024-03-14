#ifndef __SHARECOMMENTLAYER_H__
#define __SHARECOMMENTLAYER_H__

#include "includes.h"


class UploadActionPopup; /* TODO */

class ShareCommentLayer :public FLAlertLayer, TextInputDelegate, UploadActionDelegate, UploadPopupDelegate { 

    /* NOTE: Unknown CCPoints (Currently...)*/
    cocos2d::CCPoint field434_0x1b8;
    cocos2d::CCPoint field443_0x1c8;

    void *m_delegate; /* delegate */

    UploadActionPopup *m_uploadActionPopup;

    int m_commentID; /* Has something to do with the new verses mode feature coming soon... */
    int m_commentType; /* Type of comment we're going to be sharing */
    CCTextInputNode *m_textInput; /* Main Text Input */
    std::string m_descriptionText; /* Comment Text Input This is what get sent to our GameLevelManager */

    cocos2d::CCLabelBMFont *m_font; /* Font Object */
    UploadActionPopup *m_uploadPopUp; /* Popup */

    bool m_close; /* Signal to tell the Object to close/shutdown */

    bool m_unkpercent; /* Likely Has-Percent or played level Not Sure... */

    int m_percent; /* Level percent if we were playing a level */


    
};


#endif // __SHARECOMMENTLAYER_H__
