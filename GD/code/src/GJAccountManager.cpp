#include "../headers/includes.h"

// GJAccountManager::GJAccountManager() 
// {
// }

// NOTE: Being Redone due to update in Code..



void GJAccountManager::addDLToActive(const char *tag, cocos2d::CCObject * obj){
    m_activeDownloads->setObject(obj, tag);
}

void GJAccountManager::addDLToActive(const char *tag){
    addDLToActive(tag, cocos2d::CCNode::create());
}

void GJAccountManager::dataLoaded(DS_Dictionary *dsdict){
  m_username = dsdict->getStringForKey("GJA_001");
  m_accountID = dsdict->getIntegerForKey(dsdict,"GJA_003");
  m_password =  dsdict->getStringForKey(dsdict,"GJA_002");
  m_GJP2 = dsdict->getStringForKey(dsdict,"GJA_005");
  if (m_password.len() != 0 && m_GJP2.length() == 0) {
    m_GJP2 = getShaPassword(m_password);
  }
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
        auto secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        std::string postData = cocos2d::CCString::createWithFormat("accountID=%i&type=1&secret=%s",m_accountID, secret)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getAccountURL.php",postData,"AccountBackupURL", 0x36);
    } 
}


void GJAccountManager::getAccountSyncURL(){
    if (!isDLActive("surl_account")) {
        addDLToActive("surl_account");
        const char* secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfd","2893",'g','b',"7")->getCString();
        std::string postData = cocos2d::CCString::createWithFormat("accountID=%i&type=2&secret=%s", m_accountID, secret)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/getAccountURL.php", postData ,"AccountSyncURL", 0x37);
    }
}   


std::string GJAccountManager::getShaPassword(std::string password){
    std::string hash;
    std::string final_hash;
    password += cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'m',"I29","fmAn",'x','g',"Ts")->getCString();
    rtsha1::calc(password.c_str(), password.len(), hash.c_str());
    rtsha1::toHexString(hash.c_str(), final_hash.data());
    return final_hash;
}

bool GJAccountManager::isDLActive(const char *tag){
    return getDLObject(tag); //i think this works?
}


cocos2d::CCObject *GJAccountManager::getDLObject(const char *tag){
    return m_pDLObject->objectForKey(tag);
}






// void GJAccountManager::removeDLFromActive(const char *tag)
// {
//     m_pDLObject->removeObjectForKey(tag);
// }

// void GJAccountManager::setPlayerName(std::string _username)
// {
//     m_sPlayerUsername = _username;
// }

// void GJAccountManager::setPlayerPassword(std::string _password)
// {
//     m_sPlayerPassword = _password;
// }

// void GJAccountManager::setPlayerAccountID(int _accountID)
// {
//     m_nPlayerAccountID = _accountID;
//     m_nPlayerAccountIDRand = rand();
//     m_nPlayerAccountIDSeed = m_nPlayerAccountIDRand + m_nPlayerAccountID;
// }

// int GJAccountManager::getPlayerAccountID()
// {
//     return m_nPlayerAccountIDSeed - m_nPlayerAccountIDRand;
// }

// std::string GJAccountManager::getPlayerName()
// {
//     return m_sPlayerUsername;
// }

// std::string GJAccountManager::getPlayerPassword()
// {
//     return m_sPlayerPassword;
// }

// std::string GJAccountManager::getGJP()
// {
//     return cocos2d::ZipUtils::base64EncodeEnc(m_sPlayerPassword, Globals::XORAccountPassword);
// }

// void GJAccountManager::encodeDataTo(DS_Dictionary *_dict)
// {
//     _dict->setStringForKey("GJA_002", m_sPlayerPassword);
//     _dict->setStringForKey("GJA_001", m_sPlayerUsername);
//     /* _dict->setIntegerForKey("GJA_003", m_nPlayerAccountID); if we were still in 2.1... */
//     _dict->setStringForKey("GJA_005", m_sGJP2);
// }

// void GJAccountManager::dataLoaded(DS_Dictionary *_dict)
// {
//     m_sPlayerPassword = _dict->getStringForKey("GJA_002");
//     m_sPlayerUsername = _dict->getStringForKey("GJA_001");
//     m_nPlayerAccountID = _dict->getIntegerForKey("GJA_003");
// }

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

// void GJAccountManager::onGetAccountBackupURLCompleted(std::string _response, std::string tag)
// {
//     removeDLFromActive(tag.c_str());
//     if (stoi(_response) != -1)
//     {
//         std::string endpoint = cocos2d::CCString::createWithFormat("%s/database/accounts/backupGJAccountNew.php", _response)->m_sString;
//         bool backedUp = backupAccount(endpoint);
//         if (!backedUp)
//         {
//         error_label:
//             if (!m_pBackupAccountDelegate)
//                 return;
//             return m_pBackupAccountDelegate->backupAccountFailed(BackupAccountError::kBackupAccountErrorGeneric);
//         }
//     }
//     else
//         goto error_label;
// }

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

// bool GJAccountManager::syncAccount(std::string _endpoint)
// {
//     bool synced = false;
//     const char* tag = "sync_account";
//     if (!isDLActive(tag))
//     {
//         addDLToActive(tag);
//         std::string params = cocos2d::CCString::createWithFormat("userName=%s&password=%s&secret=%s&gameVersion=%i&binaryVersion=%i&gdw=%i", 
//             m_sPlayerUsername, 
//             m_sPlayerPassword, 
//             "Wmfv3899gc9", 
//             21, 
//             35, 
//             0)->m_sString;

//         ProcessHttpRequest(_endpoint, params, tag, GJHttpType::kGJHttpTypeSyncAccount);
//         synced = true;
//     }
//     return synced;
// }

// GJAccountManager* GJAccountManager::sharedState()
// {
//     if (g_accountManager == nullptr)
//     {
//         g_accountManager = new GJAccountManager();
//         g_accountManager->init();
//     }
//     return g_accountManager;
// }

// bool GJAccountManager::init()
// {
//    bool init = cocos2d::CCNode::init();
//    if (init) {
//        m_pDLObject = cocos2d::CCDictionary::create();
//        m_pDLObject->retain();
//    }
//    return init;
// }


// void GJAccountManager::linkToAccount(std::string _username, std::string _password, int _accountID, int _playerID)
// {
//     GameManager* GM = GameManager::sharedState();

//     setPlayerName(_username);
//     setPlayerPassword(_password);
//     setPlayerAccountID(_accountID);

//     GM->setPlayerName(_username);
//     GM->setPlayerID(_playerID);

//     if (m_pAccountDelegate)
//         m_pAccountDelegate->accountStatusChanged();
//     GM->accountStatusChanged();
// }

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
//         *
//         * // parse mappacks
//         *
//         *
//         *
//         *
//         * // parse levels
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


