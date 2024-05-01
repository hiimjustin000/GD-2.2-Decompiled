#ifndef __SHARECOMMENTLAYER_H__
#define __SHARECOMMENTLAYER_H__

#include "includes.h"


class UploadActionDelegate{
    virtual void uploadActionFinished(int, int) {}
	virtual void uploadActionFailed(int, int) {}
}; 

// 0x1f4	0x4	void *	void *	m_delegate	Created by retype action
// 0x1f8	0x4	UploadActionPopup *	UploadActionPopup *	m_uploadActionPopup	
// 0x1fc	0x4	int	int	m_charlimit	
// 0x200	0x4	int	int	m_ID	
// 0x204	0x4	CommentType	typedef CommentType dword	m_type	
// 0x208	0x4	CCTextInputNode *	CCTextInputNode *	m_commentInput	
// 0x20c	0x4	basic_string *	basic_string *	m_descriptionText	Created by retype action
// 0x210	0x4	basic_string *	basic_string *	m_allowedChars	
// 0x214	0x4	CCLabelBMFont *	CCLabelBMFont *	m_label	
// 0x218	0x4	CCLabelBMFont *	CCLabelBMFont *	m_font	
// 0x21c	0x4	UploadActionPopup *	UploadActionPopup *	m_uploadPopup	
// 0x220	0x1	bool	bool	m_close	
// 0x221	0x1	bool	bool	m_sharePercent	
// 0x222	0x1	??	undefined		
// 0x223	0x1	??	undefined		
// 0x224	0x4	int	int	m_percent	
// 0x228	0x4	undefined4	undefined4		



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
    int m_ID; /* Has something to do with the new verses mode feature coming soon... */
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
