#ifndef UPLOADACTIONPOPUP_H
#define UPLOADACTIONPOPUP_H

#include "includes.h"

class UploadPopupDelegate {
    public:
	    virtual void onClosePopup(UploadActionPopup*) {}
};

class UploadActionPopup : public FLAlertLayer {
	// virtual ~UploadActionPopup();
public:

	static UploadActionPopup* create(UploadPopupDelegate* delegate, std::string str);

	void closePopup();
	bool init(UploadPopupDelegate* delegate, std::string str);
	void onClose(cocos2d::CCObject* sender);
	void showFailMessage(std::string message);
	void showSuccessMessage(std::string message);
	virtual void keyBackClicked();
    UploadPopupDelegate * m_delegate;
    TextArea *	m_textArea;	
    LoadingCircle *	m_loadingCircle;
    CCMenuItemSpriteExtra *	m_menuItemSpriteExtra;
    bool m_succeeded;
};

#endif // UPLOADACTIONPOPUP_H
