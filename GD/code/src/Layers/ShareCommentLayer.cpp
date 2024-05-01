#include "includes.h"


ShareCommentLayer* ShareCommentLayer::create(std::string title, int charLimit, CommentType type, int ID, std::string desc){
    ShareCommentLayer* scl = new ShareCommentLayer;
    if (scl != nullptr && scl->init(title, charLimit, type, ID, desc)){
        scl->autorelease();
        return scl;
    }
    CC_SAFE_DELETE(scl);
    return nullptr;
};


/* Not sure if I wrote init() function correctly :/ it's very big... */

bool ShareCommentLayer::init(std::string title, int charLimit, CommentType type, int ID, std::string desc)
{
    if (!FLAlertLayer::init(150)){
        return false;
    }
    m_charlimit = charLimit;
    m_ID = ID;
    m_type = type;

    cocos2d::CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

    auto GJsquare = cocos2d::extension::CCScale9Sprite::create("GJ_square01.png",CCRectMake(0.0,0.0,80.0,80.0));
    GJsquare->setOpacity(0xff);

    float x, y, width, height;

    /* I'm Little Confused by this section so any help with it would be appreciated */
    if (m_type == kCommentTypeFriendRequestType) {
        x = -5.0;
        height = 60.0;
        width = 40.0;
        y = 160.0;
    } else {
        width = 0.0;
        y = 270.0;
        height = 60.0;
        if (m_type == kCommentTypeUnknown2) {
            height = 180.0;
        }
        x = 7.0;
        if (m_type != kCommentTypeUnknown2) {
            width = 80.0;
            y = 135.0;
        }
    }
    
    GJsquare->setContentSize(CCSizeMake(400.0, y));
    m_mainLayer->addChild(GJsquare, -1);
    GJsquare->setPosition(CCPointMake(winSize.width * 0.5, height + winSize.height * 0.5));
    
    m_font = cocos2d::CCLabelBMFont::create(title.c_str(),"bigFont.fnt");
    y *= 0.5;

    m_font->setPosition(CCPointMake(winSize.width,(y + winSize.height) - 16.0));
    m_mainLayer->addChild(m_font);
    m_font->setScale(.6f);

    if (m_type == kCommentTypeFriendRequestType){
        auto username = GameLevelManager::sharedState()->tryGetUsername(m_ID);
        if (username.length() != 0) {
            if (username != "-") {
                auto goldFont = cocos2d::CCLabelBMFont::create(("Send friend request to " + username).c_str(),"goldFont.fnt");
                goldFont->setPosition(CCPointMake(0.0,-20.0) + m_font->getPosition());
                m_mainLayer->addChild(goldFont);
                goldFont->setScale(.6f);
            }
        }
    }
    m_joystickConnected = -1;
    m_buttonMenu = cocos2d::CCMenu::create();
    m_buttonMenu = m_buttonMenu;
    m_mainLayer->addChild(m_buttonMenu,10);
    if (m_type == kCommentTypeLevelType){
        auto infoAlert = InfoAlertButton::create(
                            "Comment Rules",
                            /* "Like when will that ever happen?" - Shrek */
                            "1. Do <cr>not</c> spam.\n"\
                            "2. Do <cr>not</c> harass other players.\n"
                            "3. Do <cr>not</c> post inappropriate or controversial content.\n"
                            "4. Do <cr>not</c> try to bypass these rules.\n"
                            "<cy>These rules and their enforcement are entirely at Elder Moderators\' discretion.</c>",
                            1.0
        );
          
        m_buttonMenu->addChild(infoAlert);
        infoAlert->setPosition(m_buttonMenu->convertToNodeSpace(m_buttonMenu->convertToWorldSpace(CCPointMake((winSize.width - 200.0) + 4.0, (y + winSize.height) - 4.0))));

        if (m_ID > 0) {
            auto onBtn = cocos2d::CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
            auto offBtn = cocos2d::CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
            onBtn->setScale(0.6f);
            offBtn->setScale(0.6f);
            auto menuItemToggler = CCMenuItemToggler::create(offBtn, onBtn, this, menu_selector(onPercent));
            m_buttonMenu->addChild(menuItemToggler);

            menuItemToggler->convertToNodeSpace
                (m_buttonMenu->convertToNodeSpace(infoAlert->convertToWorldSpace(CCPointMake((winSize.width - 200.0) + 20.0, (winSize.height - y) + 20.0))));
            menuItemToggler->setSizeMult(1.5f);

            m_font = cocos2d::CCLabelBMFont::create("%","chatFont.fnt");
            m_mainLayer->addChild(m_font);
            m_font->setAnchorPoint(CCPointMake(0.0,0.5));
            m_font->setPosition(CCPointMake((onBtn->getContentSize().width * 0.5) * 0.6 + 4.0, 0.0) + CCPointMake(0.0,0.5));
            m_font->setScale(0.8);
            updatePercentLabel();
        }
    }
    else if (m_type == kCommentTypeUnknown2) {
        auto resetButton = CCMenuItemSpriteExtra::create(cocos2d::CCSprite::createWithSpriteFrameName("GJ_resetBtn_001.png"),nullptr, this, menu_selector(onClear));
        m_buttonMenu->addChild(resetButton);
        auto pos = CCPointMake((winSize.width - 200.0) + 18.0 ,  (y + winSize.width) - 18.0);
        resetButton->setPosition(m_buttonMenu->convertToNodeSpace(m_mainLayer->convertToWorldSpace(pos)));
    }
    auto buttons = cocos2d::CCArray::create();
    std::string titleMessage = "";
    if (m_type == kCommentTypeUnknown2) {
        titleMessage = "Save";
    } else if (m_type == kCommentTypeUnknown3) {
        titleMessage = "Create";
    }

    auto CancelButton = CCMenuItemSpriteExtra::create(ButtonSprite::create("Cancel"), nullptr, this, menu_selector(onClose));
    m_buttonMenu->addChild(CancelButton);
    buttons->addObject(CancelButton);

    auto SubmitButton = CCMenuItemSpriteExtra::create(ButtonSprite::create("Submit"), nullptr, this, menu_selector(onShare));
    m_buttonMenu->addChild(CancelButton);
    buttons->addObject(CancelButton);
    float winPointX = winSize.width;
    float winPointY = winSize.height - y;
    cocos2d::CCPoint mainLayerPos = m_mainLayer->getPosition();
    auto point = CCPointMake(winPointX, winPointY + 24.0 + mainLayerPos.y);
    GameToolbox::alignItemsHorisontally(buttons,15.0, m_buttonMenu->convertToNodeSpace(point),false);
    auto rect = CCRectMake(winSize.width + x, winSize.height, winSize.width, winSize.height);
    auto square02b = cocos2d::extension::CCScale9Sprite::create("square02b_001.png",CCRectMake(0.0,0.0,80.0,80.0), rect);
    square02b->setOpacity(100);
    square02b->setContentSize(CCSizeMake(360.0,height));
    m_mainLayer->addChild(square02b,1);
    // IDK Whats going on here... I left these in to show the code from ghidra as it still is confusing me greatly...
    // square02b->setPosition(square02b, rect.origin);

    /* TODO */
    /*
      uStack_5b = 0;
  uStack_5a = 0;
  square02b->vtable->cocos2d_extension_CCScale9Sprite_setColor)
            (square02b,(CCRect *)&descText);
  std::basic_string::basic_string
            ((basic_string *)auStack_bc,
             " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,-!?:;)(/\\\"\'`*=+-_% []<>|@&^#{}%$~"
            );
  m_allowedChars = (basic_string *)&m_allowedChars;
  if (*(int *)&m_type == 5) {
    std::basic_string::assign(m_allowedChars,"Insert List Name");
    titleMessage = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    m_allowedChars = (basic_string *)auStack_bc;
  }
  else if (*(int *)&m_type == 2) {
    titleMessage = "[Optional Message]";
  }
  else {
    titleMessage = "Insert comment";
  }
  std::basic_string::assign(m_allowedChars,titleMessage);
  m_textInput =
       CCTextInputNode::create
                 (360.0,height - 10.0,(char *)m_allowedChars,"Thonburi",0x18,(char *)0x0);
  m_textInput = m_textInput;
  m_textInput->m_filterProfanity = false;
  m_mainLayer = (sub).FLAleartLayer.m_mainLayer;
  m_mainLayer->vtable->cocos2d_CCNode_addChild)(m_mainLayer,m_textInput,0x14);
  m_textInput->m_delegate = (TextInputDelegate *)&field4_0x1f0;
    m_textInput->sub).vtable)->cocos2d_CCNode_setPosition)
            (m_textInput,&CStack_9c);
  m_allowedChars = (basic_string *)(auStack_bc + 4);
  m_textInput = m_textInput;
  std::basic_string::basic_string(m_allowedChars,(basic_string *)auStack_bc);
  CCTextInputNode::setAllowedChars(m_textInput,m_allowedChars);
  _descText = (basic_string *)(auStack_b4 + 4);
  std::basic_string::~basic_string(m_allowedChars);
  m_textInput->m_maxLabelLength = m_charlimit;
  std::basic_string::basic_string((basic_string *)auStack_b4,"");
  cocos2d::CCPoint::CCPoint((CCPoint *)&descText,0.5,0.5);
  tArea = TextArea::create((basic_string *)auStack_b4,"chatFont.fnt",1.0,295.0,
                           (CCPoint *)(CCPoint *)&descText,20.0,true);
  std::basic_string::~basic_string((basic_string *)auStack_b4);
  CCTextInputNode::addTextArea(m_textInput,tArea);
  local_c8 = (_ccColor3B *)CONCAT13(local_c8._3_1_,0xc8c8c8);
  CCTextInputNode::setLabelPlaceholderColor(m_textInput,local_c8);
  charLimitAsStr = cocos2d::CCString::createWithFormat("%i",m_charlimit);
  titleMessage = cocos2d::CCString::getCString(charLimitAsStr);
  _font = cocos2d::CCLabelBMFont::create(titleMessage,"chatFont.fnt");
  m_label = _font;
  m_mainLayer = (sub).FLAleartLayer.m_mainLayer;
  m_mainLayer->vtable->cocos2d_CCNode_addChild)(m_mainLayer,_font,2);
  _font = m_label;
  _call = (code *)_font->vtable->cocos2d_CCNode_setAnchorPoint;
  cocos2d::CCPoint::CCPoint((CCPoint *)(basic_string *)&descText,1.0,0.5);
  (*_call)(_font,(basic_string *)&descText);
  m_label->vtable->cocos2d_CCNode_getPosition)
            (m_label,(winPoint.x + 200.0) - 10.0,(y + winPoint.y) - 14.0);
  std::basic_string::basic_string(_descText,desc);
  updateDescText(this,_descText);
  std::basic_string::~basic_string(_descText);
  if (*(int *)(desc->_M_length - 0xc) != 0) {
    m_textInput = m_textInput;
    std::basic_string::basic_string((basic_string *)&descText,desc);
    CCTextInputNode::setString(m_textInput,(basic_string *)&descText);
    std::basic_string::~basic_string((basic_string *)&descText);
  }
  std::basic_string::~basic_string((basic_string *)auStack_bc);
  std::basic_string::~basic_string((basic_string *)(local_c4 + 4));
  std::basic_string::~basic_string((basic_string *)local_c4);
__EXIT_INIT:*/
    return true;
}

void ShareCommentLayer::keyBackClicked()
{
    onClose(nullptr);
}


void  ShareCommentLayer::onClear(cocos2d::CCObject *sender)
{
    updateDescText("");
    m_textInput->setString("");
}

void ShareCommentLayer::onClose(cocos2d::CCObject *sender)
{
    /* Close IME and filter any profanity that is being sent by the user... */
    m_textInput->onClickTrackNode(false);
    m_textInput->setKeypadEnabled(false);
    removeFromParentAndCleanup(true);
}

void ShareCommentLayer::onClosePopup(UploadActionPopup *popup)
{
    popup->closePopup();
    if (popup == m_uploadPopUp) {
        m_uploadPopUp = nullptr;
    }
    if (m_close) {
        onClose(nullptr);
    }
}

void ShareCommentLayer::onPercent(cocos2d::CCObject *sender)
{
    m_sharePercent = m_sharePercent ^ 1;
    updatePercentLabel();
}



void ShareCommentLayer::onShare(cocos2d::CCObject *sender)
{
    /* I optimized these to a switchblocks (which is how it likely is supposed to be) becase ghidra sucked at this so hard. */
    switch(m_type) {
        case kCommentTypeFriendRequestType : {   
            m_delegate = GameLevelManager::sharedState()->m_unkDelegate;
   
            if (GameLevelManager::sharedState()->uploadFriendRequest(m_ID, m_descriptionText)){
               m_uploadActionPopup = UploadActionPopup::create(this, "Sending...");
               m_uploadActionPopup->show();
            }
        }
        /* Not Sure if this part is setup like this but I wrote it this way due to my own confusion of the code formation being produced by ghidra */

        case kCommentTypeLobbyComment: {
            GJMultiplayerManager::sharedState()->uploadComment(m_descriptionText, m_ID);
        }

        case kCommentKeyTypeLevelType: {
            GameLevelManager::sharedState()->uploadLevelComment(m_ID, m_descriptionText, m_sharePercent ? (m_percent ? m_percent : 0) : 0);
        }

        case kCommentKeyTypeUserType: {
            GameLevelManager::sharedState()->uploadAccountComment(m_descriptionText);
        }
    }
    onClose(nullptr);
}

void ShareCommentLayer::registerWithTouchDispatcher(){
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -500, false);
}

void ShareCommentLayer::textChanged(CCTextInputNode *textInputNode)
{ 
  updateDescText(textInputNode->getString());
}

void ShareCommentLayer::textInputClosed(CCTextInputNode *textInput)
{
    m_descriptionText = textInput->getString();
    updateDescText(m_descriptionText);
}

void ShareCommentLayer::textInputOpened(CCTextInputNode *textInput)
{
  /* NOOP */
}

void ShareCommentLayer::updateCharCountLabel()
{
// TODO: Has Unknown Color Names / Globals being used.... 
//   size_t _strlen = this->m_descriptionText.length();


//   if (((_strlen < m_charlimit * 0.7) << 0x1f) < 0) {
//     m_label->updateDisplayedOpacity)(0x7d);
   
//         m_label->updateDisplayedColor;
//   }
//   else {
//     if (-1 < (_strlen < m_charlimit * 0.9) << 0x1f) {
//         m_label->updateDisplayedOpacity(m_label,0xff);
//         // TODO:
//         // m_label->updateDisplayedColor(DAT_0098bbee);
//       goto LAB_00426dc2;
//     }
    
   
//         m_label->updateDisplayedColor;
//   }
//   puVar2 = &DAT_0098bbeb;
// LAB_00426dc2:
//   (*UNRECOVERED_JUMPTABLE)(m_label,puVar2);
 
//     m_label->setString;
//     auto s = cocos2d::CCString::createWithFormat("%i",m_charlimit - _strlen)->getCString(this_00);
//                     /* WARNING: Could not recover jumptable at 0x00426de6. Too many branches */
//                     /* WARNING: Treating indirect jump as call */
//   (*UNRECOVERED_JUMPTABLE)(m_label,pcVar1);
//   return;
}



void ShareCommentLayer::updateDescText(std::string desc)
{
    m_descriptionText = desc;
    updateCharCountLabel();
}


void __thiscall ShareCommentLayer::updatePercentLabel()
{
    /* NOTE: This Color not be right, I was blindly guessing due to DAT_0098bbe8 being unknown to me... (likely a ccColor3B?)  */
    /* TODO: Geode Mod to find out what m_font's color is? */
    if (m_sharePercent == false) {
        m_font->updateDisplayedOpacity(0x7d);
        m_font->updateDisplayedColor(cocos2d::ccBLACK);
        m_font->setString("%");
    }
    
    else {
        m_font->updateDisplayedOpacity(0xff);
        m_font->updateDisplayedColor(cocos2d::ccBLACK);
        m_font->setString(cocos2d::CCString::createWithFormat("%i%%",m_percent)->getCString());
    }
}


void ShareCommentLayer::uploadActionFailed(int ID,int status)
{
    if ((ID == m_ID) && (m_uploadActionPopup != nullptr)) {
        m_uploadActionPopup->showFailMessage("Failed. Please try again later.");
    }
}
void ShareCommentLayer::uploadActionFinished(int ID, int status)
{
    if ((ID == m_ID) && (m_uploadActionPopup != nullptr)) {
        m_uploadActionPopup->showSuccessMessage("Friend request sent!");
        m_close = true;
    }
}

