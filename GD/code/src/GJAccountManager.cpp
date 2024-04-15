#include "../headers/includes.h"



/* TODO: Start uncommenting and updating & repairing broken functions */

void GJAccountManager::addDLToActive(const char *tag, cocos2d::CCObject * obj){
    m_activeDownloads->setObject(obj, tag);
}

void GJAccountManager::addDLToActive(const char *tag){
    addDLToActive(tag, cocos2d::CCNode::create());
}

bool GJAccountManager::dataLoaded(DS_Dictionary *dsdict){
  m_username = dsdict->getStringForKey("GJA_001");
  m_accountID = dsdict->getIntegerForKey("GJA_003");
  m_password =  dsdict->getStringForKey("GJA_002");
  m_GJP2 = dsdict->getStringForKey("GJA_005");
  if (m_password.length() != 0 && m_GJP2.length() == 0) {
    m_GJP2 = getShaPassword(m_password);
  }
  return true;
}


void GJAccountManager::encodeDataTo(DS_Dictionary *dsdict){
    dsdict->setStringForKey("GJA_001",m_username);
    dsdict->setIntegerForKey("GJA_003",m_accountID);
    dsdict->setStringForKey("GJA_005",m_GJP2);
}

/* This ones a noop */
void GJAccountManager::firstSetup(){
    return;
}


void GJAccountManager::getAccountBackupURL(){
    if (isDLActive("burl_account")) {
        addDLToActive("burl_account");
        ProcessHttpRequest(
            "https://www.boomlings.com/database/getAccountURL.php",
            cocos2d::CCString::createWithFormat(
                    "accountID=%i&type=1&secret=%s", 
                    m_accountID, 
                    cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString()
            )->getCString(),
            "AccountBackupURL", 
            kGJHttpTypeGetAccountBackupURL
        );
    } 
}


void GJAccountManager::getAccountSyncURL(){
    if (!isDLActive("surl_account")) {
        addDLToActive("surl_account");
        ProcessHttpRequest(
            "https://www.boomlings.com/database/getAccountURL.php", 
            cocos2d::CCString::createWithFormat(
                "accountID=%i&type=2&secret=%s", 
                m_accountID, 
                cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString()
            )->getCString(),
            "AccountSyncURL", 
            kGJHttpTypeGetAccountSyncURL
        );
    }
}   


std::string GJAccountManager::getShaPassword(std::string password){
    unsigned char hash[41];
    std::string finalhash;
    /* This implementation should be fine for right now I have no complaints whatsoever... */
    password += cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'m',"I29","fmAn",'x','g',"Ts")->getCString();
    rtsha1::calc(password.c_str(), password.size(), hash);
    rtsha1::toHexString(hash, finalhash.data());
    return finalhash;
}

bool GJAccountManager::isDLActive(const char *tag){
    return getDLObject(tag); //i think this works?
}


cocos2d::CCObject *GJAccountManager::getDLObject(const char *tag){
    return m_activeDownloads->objectForKey(tag);
}



void GJAccountManager::removeDLFromActive(const char *tag)
{
    m_activeDownloads->removeObjectForKey(tag);
}

void GJAccountManager::setPlayerName(std::string username)
{
    m_username = username;
}

void GJAccountManager::setPlayerPassword(std::string password)
{
    m_password = password;
}

void GJAccountManager::setPlayerAccountID(int accountID)
{
    m_accountID = accountID;
    m_accountIDRand = rand();
    m_accountIDSeed = m_accountIDRand + m_accountID;
}

int GJAccountManager::getPlayerAccountID()
{
    return m_accountIDSeed - m_accountIDRand;
}

std::string GJAccountManager::getPlayerName()
{
    return m_username;
}

std::string GJAccountManager::getPlayerPassword()
{
    return m_password;
}

// std::string GJAccountManager::getGJP()
// {
//     return cocos2d::ZipUtils::base64EncodeEnc(m_sPlayerPassword, Globals::XORAccountPassword);
// }

void GJAccountManager::encodeDataTo(DS_Dictionary *_dict)
{
    _dict->setStringForKey("GJA_002", m_password);
    _dict->setStringForKey("GJA_001", m_username);
    /* _dict->setIntegerForKey("GJA_003", m_nPlayerAccountID); if we were still in 2.1... */
    _dict->setStringForKey("GJA_005", m_GJP2);
}

/* TODO: Fix GManager::dataLoaded() to void return type ? */

bool GJAccountManager::dataLoaded(DS_Dictionary *_dict)
{
    m_password = _dict->getStringForKey("GJA_002");
    m_username = _dict->getStringForKey("GJA_001");
    m_GJP2 = _dict->getIntegerForKey("GJA_005");
    return true;
}

// void GJAccountManager::firstSetup() {}

// void GJAccountManager::onLoginAccountCompleted(std::string _response, std::string tag)
// {
//     removeDLFromActive(tag.c_str());
//     if (stoi(_response) == AccountError::kAccountErrorAccountDisabled || stoi(_response) == AccountError::kAccountErrorLinkedToDifferentSteamAccount || stoi(_response) == AccountError::kAccountErrorGeneric)
//     {
//     errorLabel:
//         if (!m_pLoginAccountDelegate)
//             return;
//         return m_pLoginAccountDelegate->loginAccountFailed(static_cast<AccountError>(std::stoi(_response)));
//     }
//     cocos2d::CCArray *resArr = RobTop::splitToCCArray(_response, ",");
//     if (resArr->count() <= 2)
//         goto errorLabel;

//     int accountID = resArr->stringAtIndex(0)->intValue();
//     int playerID = resArr->stringAtIndex(1)->intValue();

//     if (accountID <= 0 || playerID <= 0)
//         goto errorLabel;

//     if (m_pLoginAccountDelegate)
//         m_pLoginAccountDelegate->loginAccountFinished(accountID, playerID);
// }

// void GJAccountManager::onRegisterAccountCompleted(std::string _response, std::string tag)
// {
//     removeDLFromActive(tag.c_str());
//     if (stoi(_response) != 1)
//     {
//         if (!m_pRegisterAccountDelegate)
//             return;
//         return m_pRegisterAccountDelegate->registerAccountFailed(static_cast<AccountError>(stoi(_response)));
//     }
//     else if (!m_pRegisterAccountDelegate)
//         return;
//     return m_pRegisterAccountDelegate->registerAccountFinished();
// }

// void GJAccountManager::onBackupAccountCompleted(std::string _response, std::string tag)
// {
//     removeDLFromActive(tag.c_str());
//     if (stoi(_response) == AccountError::kAccountErrorGeneric)
//     {
//     error_label:
//         if (!m_pBackupAccountDelegate)
//             return;
//         return m_pBackupAccountDelegate->backupAccountFailed(static_cast<BackupAccountError>(stoi(_response)));
//     }
//     else if (stoi(_response) == BackupAccountError::kBackupAccountErrorLoginFailed)
//     {
//         GameLevelManager::sharedState()->makeTimeStamp(tag.c_str());
//         LocalLevelManager::sharedState()->markLevelsAsUnmodified();
//         goto error_label;
//     }
//     else
//     {
//         m_sPlayerPassword = "0";
//         if (!m_pAccountDelegate)
//             return;
//         m_pAccountDelegate->accountStatusChanged();

//         if (!m_pBackupAccountDelegate)
//             return;
//         return m_pBackupAccountDelegate->backupAccountFinished();
//     }
// }

// void GJAccountManager::onUpdateAccountSettingsCompleted(std::string _response, std::string tag)
// {
//     removeDLFromActive(tag.c_str());
//     if (stoi(_response) == -1)
//     {
//         if (!m_pAccountSettingsDelegate)
//             return;
//         return m_pAccountSettingsDelegate->updateSettingsFailed();
//     }
//     else
//     {
//         if (!m_pAccountSettingsDelegate)
//             return;
//         return m_pAccountSettingsDelegate->updateSettingsFinished();
//     }
// }

// void GJAccountManager::onGetAccountSyncURLCompleted(std::string _response, std::string tag) 
// {
//     removeDLFromActive(tag.c_str());
//     if (stoi(_response) != -1)
//     {
//         std::string endpoint = cocos2d::CCString::createWithFormat("%s/database/accounts/syncGJAccountNew.php", _response)->m_sString;
//         bool synced = syncAccount(endpoint);
//         if (!synced)
//         {
//             if (!m_pSyncAccountDelegate)
//                 return;
//             return m_pSyncAccountDelegate->syncAccountFailed(BackupAccountError::kBackupAccountErrorGeneric);
//         }
//     }
//     else
//     {
//         if (!m_pBackupAccountDelegate)
//             return;
//         return m_pBackupAccountDelegate->backupAccountFailed(BackupAccountError::kBackupAccountErrorGeneric);
//         //this is a bug that RobTop left in, bugfixed version can be found in the comment below 
//         //  if (!m_pSyncAccountDelegate)
//         //      return;
//         //  return m_pSyncAccountDelegate->syncAccountFailed(BackupAccountError::kBackupAccountErrorGeneric);
//     }
// }

void GJAccountManager::onGetAccountBackupURLCompleted(std::string response, std::string tag)
{
    removeDLFromActive(tag.c_str());
    if (response != "-1")
    {
        if (!backupAccount(cocos2d::CCString::createWithFormat("%s/database/accounts/backupGJAccountNew.php", response)->getCString()))
        {
            error_label:
                if (!m_backupDelegate)
                    return;
                return m_backupDelegate->backupAccountFailed(BackupAccountError::kBackupAccountErrorGeneric);
        }
    }
    else
        goto error_label;
}

void GJAccountManager::handleIt(bool requestSentSuccessfully, std::string response, std::string tag, GJHttpType httpType){
    std::string serverResponse = requestSentSuccessfully ? response: "-1";
    switch (httpType) {
        case GJHttpType::kGJHttpTypeLoginAccount:
            onLoginAccountCompleted(serverResponse, tag);
            break;
        case GJHttpType::kGJHttpTypeRegisterAccount:
            onRegisterAccountCompleted(serverResponse, tag);
            break;
        case GJHttpType::kGJHttpTypeGetAccountBackupURL:
            onGetAccountBackupURLCompleted(serverResponse, tag);
            break;
        case GJHttpType::kGJHttpTypeGetAccountSyncURL:
            onGetAccountSyncURLCompleted(serverResponse, tag);
            break;
        case GJHttpType::kGJHttpTypeUpdateAccountSettings:
            onUpdateAccountSettingsCompleted(serverResponse, tag);
            break;
        case GJHttpType::kGJHttpTypeSyncAccount:
            onSyncAccountCompleted(serverResponse, tag);
            break;
        case GJHttpType::kGJHttpTypeBackupAccount:
            onBackupAccountCompleted(serverResponse, tag);
            break;
        default:
            return;
    }
}



bool  GJAccountManager::syncAccount(std::string syncURL)
{  
    if (!isDLActive("sync_account")) {
        addDLToActive("sync_account");
        ProcessHttpRequest(
            syncURL,
            GameLevelManager::sharedState()->getBasePostString() + cocos2d::CCString::createWithFormat("&secret=%s",cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfv","3899",'g','c',"9")->getCString())->getCString() ,
            "SyncAccount", 
            kGJHttpTypeSyncAccount
        );
        return true;
    }
    return false;
}


static GJAccountManager* GLOBAL_GJACCOUNTMANAGER;

GJAccountManager* GJAccountManager::sharedState()
{
    if (GLOBAL_GJACCOUNTMANAGER == nullptr)
    {
        GLOBAL_GJACCOUNTMANAGER = new GJAccountManager();
        GLOBAL_GJACCOUNTMANAGER->init();
    }
    return GLOBAL_GJACCOUNTMANAGER;
}

bool GJAccountManager::init()
{
   if (cocos2d::CCNode::init()) {
       m_activeDownloads = cocos2d::CCDictionary::create();
       m_activeDownloads->retain();
       return true;
   }
   return false;
}


void GJAccountManager::linkToAccount(std::string username, std::string password, int accountID, int playerID)
{
    GameManager* GM = GameManager::sharedState();

    setPlayerName(username);
    setPlayerPassword(password);
    setPlayerAccountID(accountID);

    // TODO: GameManager
    // GM->setPlayerName(username);
    // GM->setPlayerID(playerID);

    if (m_accountDelegate)
        m_accountDelegate->accountStatusChanged();
    GM->accountStatusChanged();
}

// void GJAccountManager::onSyncAccountCompleted(std::string _response, std::string tag)
// {
//     removeDLFromActive(tag.c_str());
//     if (_response != "-1" || _response != "-2")
//     {
//         cocos2d::CCArray* saveData = RobTop::splitToCCArray(_reqsponse, ";");
//         GameManager* GM = GameManager::sharedState();
//         AchievementManager* AM = AchievementManager::sharedState();
//         AM->m_bNotifiedAchievement = true;

//         GM->loadFromCompressedString(saveData->stringAtIndex(0)->m_sString);
//         GM->loadFromCompressedString(saveData->stringAtIndex(1)->m_sString);

//         int gameVersion = saveData->stringAtIndex(2)->m_sString;
//         int binaryVersion = saveData->stringAtIndex(3)->m_sString;

//         std::string completedLevels = saveData->stringAtIndex(4)->m_sString;
//         if(strlen(completedLevels) > 0x28)
//             std::string decompressedLevels = cocos2d::ZipUtils::decompressString(completedLevels.substr(0x14), false, 0xB);

//         std::string completedMappacks = saveData->stringAtIndex(5)->m_sString;
//         if (strlen(completedMappacks) > 0x28)
//             std::string decompressedMappacks = cocos2d::ZipUtils::decompressString(completedMappacks.substr(0x14), false, 0xB);

//         /*
//         * too lazy, will do these later
//         * TODO: (Calloc) (Looks Like Wylie Left me quite a bit of a chore) Tunrs out these are all going to be different manager iteractions
//         * 
//         * 
//         * 
//         * 
//         */

//         if (m_pSyncAccountDelegate)
//             m_pSyncAccountDelegate->syncAccountFinished();
//         return;
//     }
//     if (m_pAccountDelegate)
//         m_pAccountDelegate->accountStatusChanged();

//     if (m_pSyncAccountDelegate)
//         m_pSyncAccountDelegate->syncAccountFailed(static_cast<BackupAccountError>(_response);
// }


