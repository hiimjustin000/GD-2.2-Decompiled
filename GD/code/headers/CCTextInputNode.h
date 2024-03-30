#ifndef __CCTEXTINPUTNODE_H__
#define __CCTEXTINPUTNODE_H__

#include "includes.h"


// TODO: Reverse Engineer TextArea and move it to TextArea.h ...
// class TextArea : public cocos2d::CCTextFieldTTF {
// 	std::string m_textStr;
// 	cocos2d::CCArray* m_labels;
// 	const char* getString();
// };


class CCTextInputNode;

/* NOTE: I think these are virtual - Calloc */
class TextInputNodeDelegate {
public:
	virtual void textChanged(CCTextInputNode* textInputNode);
	virtual void enterPressed(CCTextInputNode* textInputNode);
	virtual bool allowTextInput(CCTextInputNode* textInputNode);
	virtual bool textInputClosed(CCTextInputNode* textInputNode);
	virtual bool textInputOpened(CCTextInputNode* textInputNode);
	virtual void textInputReturn(CCTextInputNode* textInputNode);
	virtual void textInputShouldOffset(CCTextInputNode* textInputNode, float offSet);
};




class CCTextInputNode : public cocos2d::CCLayer, cocos2d::CCIMEDelegate, cocos2d::CCTextFieldDelegate
{
	// bool m_bFinishedTypingMaybe;
	// std::string m_sText;
	// int m_Unk;
	// bool m_bIME;
	// std::string m_sAllowedChars;
	// float m_fMaxLabelWidth;
	// float m_fMaxLabelScale;
	// float m_fPlaceholderScale;
	// cocos2d::ccColor3B m_cPlaceholderColour;
	// cocos2d::ccColor3B m_cColour;
	// cocos2d::CCLabelBMFont* m_pBlinkLabel;
	// cocos2d::CCTextFieldTTF* m_pTextField;
	// TextInputDelegate* m_pDelegate;
	// int m_nCharLength;
	// cocos2d::CCLabelBMFont* m_pPlaceholderLabel;
	// bool m_bUnk;
	// bool m_bShowPlaceholder;
	// bool m_bForceOffset; /* 0x18e */
	// void* m_pTextArea; /* Should Be TextArea 0x190 */
	
	bool m_numberInput;
	bool m_doubleInput;
	std::string m_caption;
	int m_unknown1;
	bool m_selected;
	bool m_unknown2;
	float m_fontValue1;
	float m_fontValue2;
	bool m_isChatFont;
	std::string m_allowedChars;
	float m_maxLabelWidth;
	float m_maxLabelScale;
	float m_placeholderScale;
	cocos2d::ccColor3B m_placeholderColor;
	cocos2d::ccColor3B m_textColor;
	cocos2d::CCLabelBMFont* m_cursor;
	cocos2d::CCTextFieldTTF* m_textField;
	TextInputNodeDelegate* m_delegate;
	int m_maxLabelLength;
	cocos2d::CCLabelBMFont* m_placeholderLabel;
	bool m_filterSwearWords;
	bool m_usePasswordChar;
	bool m_forceOffset;
	TextArea* m_textArea;
	int m_unknown5;	
	int m_unknown4;	
	cocos2d::CCTexture2D *	m_SomeTexture;


	/* TODO: Find correct homes for these members ... */
	cocos2d::CCTextFieldDelegate* m_textFieldDelegate;
	cocos2d::ccColor3B m_cColor;


	void addTextArea(TextArea *tArea);
	bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	bool init(float width, float height, const char *caption, const char *FieldfontName, int fontSize, const char *LabelfontName);
	void forceOffset();
	std::string getString();
	bool keyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo *keyboard);
	void keyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo *pSender);

	bool onClickTrackNode(bool isKeyboardOpen);


	bool onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF* tField);
	bool onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF* tField);

	void setString(std::string cstr);
	void setMaxLavelScale(float v);
	void setMaxLavelWidth(float v);
	
	void refreshLabel();
	void setLabelNormalColor(cocos2d::ccColor3B color);

	void setDelegate(TextInputNodeDelegate* delegate);

	bool textChanged();
	void updateBlinkLabel();
	void updateBlinkLabelToChar(int blinkLabel);
	void updateCursorPosition(cocos2d::CCPoint point, cocos2d::CCRect rect);
	void updateDefaultFontValues(std::string fontName);
	void updateLabel(std::string label);

	
};


#endif // __CCTEXTINPUTNODE_H__