#include "includes.h"


AccountLoginLayer* AccountLoginLayer::create(std::string lastUsername){
    AccountLoginLayer* layer =  new AccountLoginLayer;
    if (layer != nullptr && layer->init(lastUsername)){
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

cocos2d::extension::CCScale9Sprite * AccountLoginLayer::createTextBackground(cocos2d::CCPoint position, const char *text, cocos2d::CCSize contentSize)
{
    cocos2d::extension::CCScale9Sprite *textBackground = cocos2d::extension::CCScale9Sprite::create("square02_small.png",CCRectMake(0.0f, 0.0f, 40.0f, 40.0f));
    textBackground->setContentSize(contentSize);
    addChild(textBackground);
    textBackground->setOpacity(100);
    textBackground->setPosition(position);
    return textBackground;
}

CCTextInputNode* AccountLoginLayer::createTextInput(cocos2d::CCPoint position,cocos2d::CCSize size,char *caption,int fontSize)
{
    CCTextInputNode *textInput = CCTextInputNode::create(size.width, size.height + 10.0, caption, "Thonburi", 0x18, "bigFont.fnt");
    addChild(textInput, 0x14);
    textInput->setMaxLabelScale(0.8f);
    textInput->m_delegate = reinterpret_cast<TextInputNodeDelegate*>(this);
    textInput->setTag(fontSize);
    textInput->setPosition(position);
    textInput->m_textField->setVisible(true);
    textInput->setLabelPlaceholderColor(cocos2d::ccc3(0xf0, 0xaa, 0x78));
    textInput->setLabelPlaceholderScale(0.5);
    return textInput;
}

cocos2d::CCLabelBMFont * AccountLoginLayer::createTextLabel(cocos2d::CCPoint position, char *labelStr, cocos2d::CCSize size)
{
    auto font = cocos2d::CCLabelBMFont::create(labelStr,"bigFont.fnt");
    font->setAnchorPoint(CCPointMake(0.0, 0.0));
    font->setPosition(CCPointMake(size.width * 0.5, size.height * 0.5 + 1.0) + position);
    font->setScale(0.4);
    addChild(font);
    return font;
}

void AccountLoginLayer::disableNodes()
{
    m_usernameInput->onClickTrackNode(false);
    m_passwordInput->onClickTrackNode(false);
}


void AccountLoginLayer::FLAlert_Clicked(FLAlertLayer *flalert, bool unk)
{ 
    /* did we login already? and if so, exit... TODO: Find a call that fills the unknown boolean... */
    if (flalert->getTag() == 2) onClose(this);
}

void AccountLoginLayer::hideLoadingUI()
{
    toggleUI(true);
    m_loadingUI->setVisible(false);
}


bool AccountLoginLayer::init(std::string lastUsername){
    if (!cocos2d::CCLayerColor::initWithColor(cocos2d::ccc4(0x96, 0, 0, 0))) 
        return false;

    incrementForcePrio();
    setTouchEnabled(true);
    setKeypadEnabled(true);
    
    m_noElasticity = true;
    cocos2d::CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    m_mainLayer = cocos2d::CCLayer::create();
    addChild(m_mainLayer);

    cocos2d::extension::CCScale9Sprite* square = cocos2d::extension::CCScale9Sprite::create("GJ_square01.png", CCRectMake(0.0,0.0, 80.0, 80.0));
    square->setOpacity(0xff);
    square->setContentSize(CCSizeMake(400, 300));
    
    m_mainLayer->addChild(square, -1);
    auto winPoint = CCPointMake(winSize.width * 0.5, winSize.height * 0.5);
    square->setPosition(winPoint);
    
    auto LoginFnt = cocos2d::CCLabelBMFont::create("Login", "bigFont.fnt");
    LoginFnt->setPosition(CCPointMake(winPoint.x, (winPoint.y + 150.0) - 16.0));
    m_mainLayer->addChild(LoginFnt);
    LoginFnt->setScale(60.0f);

    m_joystickConnected = -1;

    m_buttonMenu = cocos2d::CCMenu::create();
    m_mainLayer->addChild(m_buttonMenu,10);
    cocos2d::CCArray* array = cocos2d::CCArray::create();

    auto CancelButton = CCMenuItemSpriteExtra::create(ButtonSprite::create("Cancel"), nullptr, this, menu_selector(onClose));
    m_buttonMenu->addChild(CancelButton);
    array->addObject(CancelButton);
    

    auto LoginButton = CCMenuItemSpriteExtra::create(ButtonSprite::create("Login"), nullptr, this, menu_selector(onSubmit));
    m_buttonMenu->addChild(LoginButton);
    array->addObject(LoginButton);


    GameToolbox::alignItemsHorisontally(array, 15.0, m_buttonMenu->convertToNodeSpace(CCPointMake(winPoint.x , (winPoint.y - 150.0) + 22.0 + m_mainLayer->getPosition().y)), false);
    
    cocos2d::CCSize boxSize = CCSizeMake(300.0, 30.0);
    cocos2d::CCPoint boxPoint = CCPointMake(winPoint.x, winPoint.y + 80.0);

    /* Username */

    createTextBackground(boxPoint, "Username:", boxSize);
    m_usernameLabel = createTextLabel(boxPoint, "Username:", boxSize);
    m_usernameInput = createTextInput(boxPoint, boxSize, "Username", 1);
    m_usernameInput->setAllowedChars(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    m_usernameInput->m_maxLabelLength = 16;
    
    if (lastUsername.length() != 0) {
        m_usernameInput->setString(LastUsername);
    }
  
    /* Password */

    createTextBackground(boxPoint + CCPointMake(0.0,-50.0), "Password:", boxSize);
    m_passwordLabel = createTextLabel(boxPoint, "Password:", boxSize);
    m_passwordInput = createTextInput( boxPoint , boxSize, "Password", 2);
    m_passwordInput->setAllowedChars(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_");
    m_passwordInput->m_maxLabelLength = 20;
    m_passwordInput->m_usePasswordChar = true;
    m_passwordInput->setMaxLabelScale(1.0);

    array->removeAllObjects();

    CCMenuItemSpriteExtra* ForgotUsernameButton = CCMenuItemSpriteExtra::create(ButtonSprite::create("Forgot Username",0x78,0,0.8,true,"goldFont.fnt","GJ_button_05.png",25.0), nullptr, this, menu_selector(onForgotUser));
    m_buttonMenu->addChild(ForgotUsernameButton);
    CCMenuItemSpriteExtra* ForgotPasswordButton = CCMenuItemSpriteExtra::create(ButtonSprite::create("Forgot Password",0x78,0,0.8,true,"goldFont.fnt","GJ_button_05.png",25.0), nullptr, this, menu_selector(onForgotPassword));
    m_buttonMenu->addChild(ForgotPasswordButton);
    
    array->addObject(ForgotUsernameButton);
    array->addObject(ForgotPasswordButton);
    
    m_buttonMenu->convertToNodeSpace(CCPointMake(winPoint.x, (winPoint.y - 45.0) +  m_mainLayer->getPosition().y));

    m_loadingUI = LoadingCircle::create();
    /* TODO: Rename Loading Circle Class members */
    m_loadingUI->m_layer = m_mainLayer;
    m_loadingUI->m_needsRendering = true;
    m_loadingUI->retain();
    m_loadingUI->show();
    m_loadingUI->setVisible(false);
    m_loadingUI->m_sprite->setPosition(CCPointMake(winSize.width * 0.5, winSize.height * 0.5));
    return true;
}





void AccountLoginLayer::keyBackClicked()
{
    onClose(nullptr);
}

void AccountLoginLayer::loginAccountFinished(int accountID, int playerID)
{ 
    GJAccountManager::sharedState()->linkToAccount(m_username, m_password, accountID, playerID);
    auto successStr = cocos2d::CCString::createWithFormat("Thank you for logging in.\nYou have now linked your account:\n<cg>%s</c>" ,
                       m_usernameInput->getString())->getCString();
    hideLoadingUI();
    /* I guess this works? */
    auto successPopup = FLAlertLayer::create(this, "Login Success", successStr, "OK", nullptr, 320.0);
    successPopup->setTag(2);
    successPopup->show();
}

void AccountLoginLayer::onClose(cocos2d::CCObject* pSender)
{
    disableNodes();
    setKeypadEnabled(false);
    removeFromParentAndCleanup(true);
}


void AccountLoginLayer::onForgotPassword(cocos2d::CCObject* pSender)
{
    cocos2d::CCApplication::sharedApplication()->openURL("https://www.boomlings.com/database/accounts/lostpassword.php");
}

void AccountLoginLayer::onForgotUser(cocos2d::CCObject* pSender){
    cocos2d::CCApplication::sharedApplication()->openURL("https://www.boomlings.com/database/accounts/lostusername.php");
}

void AccountLoginLayer::onSubmit(cocos2d::CCObject *pSender)
{
    resetLabels();
    disableNodes();
    m_username = m_usernameInput->getString();
    m_password = m_passwordInput->getString();

    AccountError error = kAccountErrorUnknown;

    if (m_username.length() < 3) {
        error = kAccountErrorUsernameTooShort;
    }
    else if (m_password.length() > 5) {
        auto GJAM = GJAccountManager::sharedState();
        GJAM->m_accountLoginDelegate = this;
        auto gjp2 = GJAM->getShaPassword(m_password);
        if (GJAccountManager::sharedState()->loginAccount(m_username, gjp2)){
            showLoadingUI();
        }   
        else {
            loginAccountFailed(kAccountErrorGeneric);
        }
    } else {
        error = kAccountErrorPasswordTooShort;
    }
    updateLabel(error);
}

void AccountLoginLayer::registerWithTouchDispatcher()
{
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-500,true);
}

void AccountLoginLayer::resetLabel(int ID)
{
    switch(ID) {
        case 1: {
            m_usernameLabel->setString("Username:");
            m_usernameLabel->updateDisplayedColor(cocos2d::ccWHITE);
            break;
        }
        case 2: {
            m_passwordLabel->setString("Password:");
            m_passwordLabel->updateDisplayedColor(cocos2d::ccWHITE);
            break;
        }
        default: 
            break;
    }
}

void AccountLoginLayer::resetLabels()
{
    resetLabel(1);
    resetLabel(2);
}

void AccountLoginLayer::showLoadingUI()
{
    disableNodes();
    toggleUI(false);
    m_loadingUI->setVisible(true);
}

void AccountLoginLayer::textInputClosed(CCTextInputNode *textInput)
{
    auto str = textInput->getString();
    resetLabel(textInput->getTag());
    switch(textInput->getTag()){
        case 1:
            if (str.length() <= 2) updateLabel(kAccountErrorUsernameTooShort);
            break;
        case 2:
            if (str.length() <= 5) updateLabel(kAccountErrorPasswordTooShort);
            break;
        default: 
            break;
    }
}

void AccountLoginLayer::toggleUI(bool enable)
{
    //   (**(code **)(**(int **)&field_0x1b8 + 0x274))(); Unknown Call
    m_usernameInput->setTouchEnabled(enable);
    m_passwordInput->setTouchEnabled(enable);
    setTouchEnabled(enable);
    setKeypadEnabled(enable);
}

void AccountLoginLayer::updateLabel(AccountError error)
{
    switch(error) {
        
        /* -13 */
        case kAccountErrorLinkedToDifferentSteamAccount:
            m_usernameLabel->setString("Already linked to different Steam account");
            m_usernameLabel->updateDisplayedColor(cocos2d::ccWHITE);
            break;
        
        /* -12 */
        case kAccountErrorAccountDisabled:
            m_usernameLabel->setString("Account has been disabled");
            m_usernameLabel->updateDisplayedColor(cocos2d::ccWHITE);
            m_passwordLabel->setString("Contact RobTop Support for more info");
            m_passwordLabel->updateDisplayedColor(cocos2d::ccWHITE);
            break;

        /* -10 */
        case kAccountErrorLinkedToDifferentAccount:
            m_usernameLabel->setString("Already linked to different account");
            m_usernameLabel->updateDisplayedColor(cocos2d::ccWHITE);
            break;

        /* -9 */
        case kAccountErrorUsernameTooShort:
            m_usernameLabel->setString("Too short. Minimum 3 characters");
            m_usernameLabel->updateDisplayedColor(cocos2d::ccWHITE);
            break;

        /* -8 */
        case kAccountErrorPasswordTooShort:
            m_passwordLabel->setString("Too short. Minimum 6 characters");
            m_passwordLabel->updateDisplayedColor(cocos2d::ccWHITE);
            break;

        /* -1 */
        default:
            m_usernameLabel->setString("Login failed");
            m_usernameLabel->updateDisplayedColor(cocos2d::ccWHITE);
            break;
    }
}
