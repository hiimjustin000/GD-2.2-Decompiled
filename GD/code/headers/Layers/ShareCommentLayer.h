#ifndef __SHARECOMMENTLAYER_H__
#define __SHARECOMMENTLAYER_H__

#include "includes.h"

/* a delegate */
class UploadActionDelegate{
    virtual void uploadActionFinished(int, int) {}
	virtual void uploadActionFailed(int, int) {}
}; 


/* ShareCommentLayer has multiple uses including 
 * - Friend Requests
 * - Level Comments
 * - Profile Comments
 * - Multiplayer Lobby 
 * These all play a role in posting and sharing comments in geometry dash
 */
class ShareCommentLayer : public FLAlertLayer, public TextInputDelegate, public UploadActionDelegate, public UploadPopupDelegate { 

public:
    ShareCommentLayer(){}
    static ShareCommentLayer* create(std::string title, int charLimit, CommentType type, int ID, std::string desc);

	bool init(std::string title, int charLimit, CommentType type, int ID, std::string desc);

    void onClear(cocos2d::CCObject *sender);
   	void onClose(cocos2d::CCObject* sender);
	void onPercent(cocos2d::CCObject* sender);
	void onShare(cocos2d::CCObject* sender);
	void updateCharCountLabel();
	void updateDescText(std::string desc);
	void updatePercentLabel();

	virtual void registerWithTouchDispatcher();
	virtual void keyBackClicked();
	virtual void textInputOpened(CCTextInputNode* textInput) {}
	virtual void textInputClosed(CCTextInputNode* textInput);
	virtual void textChanged(CCTextInputNode* textInput);
	virtual void uploadActionFinished(int ID, int unk);
	virtual void uploadActionFailed(int ID, int unk);
	virtual void onClosePopup(UploadActionPopup* popup);


    void *m_delegate; /* delegate */

    UploadActionPopup *m_uploadActionPopup;

    int m_charlimit;
    int m_ID;
    CommentType m_type; /* Type of comment we're going to be sharing */
    CCTextInputNode *m_textInput; /* Main Text Input */
    std::string m_descriptionText; /* Comment Text Input This is what get sent to our GameLevelManager */

    cocos2d::CCLabelBMFont *m_font; /* Font Object */
    UploadActionPopup *m_uploadPopUp; /* Popup */

    bool m_close; /* Signal to tell the Object to close/shutdown */

    bool m_sharePercent; /* Likely Has-Percent or played level Not Sure... */

    int m_percent; /* Level percent if we were playing a level */

};


#endif // __SHARECOMMENTLAYER_H__
