#include "includes.h"


bool GJMultiplayerManager::init()
{
    if (cocos2d::CCNode::init())
    {
        m_DLObject = cocos2d::CCDictionary::create();
        m_DLObject->retain();
        m_unkDict3 = cocos2d::CCDictionary::create();
        m_unkDict3->retain();
        m_unkDict2 = cocos2d::CCDictionary::create();
        m_unkDict2->retain();
        m_unkDict3 = cocos2d::CCDictionary::create();
        m_unkDict3->retain();
    }
    return false;
}

void GJMultiplayerManager::addDLToActive(const char *key, cocos2d::CCObject *dummyObject)
{
    m_DLObject->setObject(dummyObject, std::string(key));
}

void GJMultiplayerManager::addDLToActive(const char *key)
{
    addDLToActive(key, cocos2d::CCNode::create());
}

bool GJMultiplayerManager::isDLActive(const char *key)
{
    return m_DLObject->objectForKey(key);
}

/* TODO */

// void __thiscall
// GJMultiplayerManager::createAndAddComment(GJMultiplayerManager *this,std::string key2,int param_ 2)

// {
//   GJAccountManager *AM;
//   CCString *this_00;
//   char *_p2;
//   std::string bStack_24;
//   int iStack_20;
//   int local_1c;

//   _p2 = *(char **)key2;
//   local_1c = __stack_chk_guard;
//   bStack_24 = key2;
//   iStack_20 = param_2;
//   AM = GJAccountManager::sharedState();
//   this_00 = cocos2d::CCString::createWithFormat
//                       ("2~%s~8~%i~9~7 minutes~6~-1",_p2,AM->m_accountID - AM->m_unkInt1);
//   _p2 = cocos2d::CCString::getCString(this_00);
//   std::std::string::std::string(&bStack_24,_p2,(size_t)&iStack_20);
//   std::std::string::std::string((std::string *)&iStack_20,&bStack_24);
//   addComment(this,iStack_20,param_2);
//   std::std::string::~std::string((std::string *)&iStack_20);
//   if (*(int **)(this + 1) != (int *)0x0) {
//     (**(code **)(**(int **)(this + 1) + 0xc))();
//   }
//   std::std::string::~std::string(&bStack_24);
//   if (local_1c != __stack_chk_guard) {
//                               /* WARNING: Subroutine does not return */
//     __stack_chk_fail();
//   }
//   return;
// }

bool GJMultiplayerManager::exitLobby(int gameID)
{
    const char *tag = cocos2d::CCString::createWithFormat("%i_exitLobby", gameID)->getCString();
    bool dlactive = isDLActive(tag);
    if (!dlactive)
    {
        addDLToActive(tag);
        std::string postData = getBasePostString();
        auto secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfv", "3899", 'g', 'c', "9")->getCString(pCVar1);
        postData += cocos2d::CCString::createWithFormat("&gameID=%i&secret=%s", gameID, secret)->getCString();
        ProcessHttpRequest("https://www.geometrydash.com/database/exitMPLobby.php", postData, std::string(tag), (GJHttpType)0x3a);
    }
    return dlactive;
}

// TODO
// void GJMultiplayerManager::firstSetup(void)
// {

// }

/* GJMultiplayerManager::getBasePostString() */

// TODO

// std::string __thiscall GJMultiplayerManager::getBasePostString(GJMultiplayerManager *this)

// {
//   GJAccountManager *pGVar1;
//   std::string local_18;
//   int local_14;

//   local_14 = __stack_chk_guard;
//   local_18 = (std::string)this;
//   GameLevelManager::sharedState();
//   GameLevelManager::getBasePostString();
//   std::std::string::operator+=((std::string *)this,(std::string *)"&username=");
//   pGVar1 = GJAccountManager::sharedState();
//   std::std::string::std::string(&local_18,&pGVar1->m_username);
//   std::std::string::operator+=((std::string *)this,(std::string *)local_18);
//   std::std::string::~std::string(&local_18);
//   if (local_14 != __stack_chk_guard) {
//                               /* WARNING: Subroutine does not return */
//     __stack_chk_fail();
//   }
//   return (std::string)this;
// }

/*
uint __thiscall
GJMultiplayerManager::getLastCommentIDForGame(GJMultiplayerManager *this,int commentID)

{
  CCArray *this_00;
  uint uVar1;
  uint uVar2;
  CCObject *pCVar3;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  uint uVar4;

  this_00 = (CCArray *)
            cocos2d::CCDictionary::objectForKey(this->m_unkDict1,CONCAT44(unaff_r5,unaff_r4));
  if ((this_00 != (CCArray *)0x0) && (uVar1 = cocos2d::CCArray::count(this_00), uVar1 != 0)) {
    uVar4 = 0;
    uVar1 = 0;
    while (uVar2 = cocos2d::CCArray::count(this_00), uVar4 < uVar2) {
      pCVar3 = cocos2d::CCArray::objectAtIndex(this_00,uVar4);
      uVar4 = uVar4 + 1;
      if ((int)uVar1 < (int)pCVar3[8].m_uReference) {
        uVar1 = pCVar3[8].m_uReference;
      }
    }
    return uVar1;
  }
  return 0



/* GJMultiplayerManager::handleIt(bool, std::std::string<char, std::char_traits<char>,
   std::allocator<char> >, std::std::string<char, std::char_traits<char>, std::allocator<char> >,
   GJHttpType) */

void GJMultiplayerManager::handleIt(bool success, std::string response, std::string tag, int httpType)
{

    if (response == "")
    {
        response = "-1";
    }
    switch (httpType){
        case 0x39:
            onJoinLobbyCompleted(response, tag);
            break;
        case 0x3a:
            onExitLobbyCompleted(response, tag);
            break;
        case 0xd:
            onUploadCommentCompleted(response, tag);
        default:
            break;
    }
}


void  GJMultiplayerManager::handleItDelayed(bool success,std::string response,std::string tag, int httpType)

{
    GJHttpResult* httpResult = GJHttpResult::create(true, response,tag, (GJHttpType)httpType);
    httpResult->retain();
    // Unknown...
    // FTA = cocos2d::CCDelayTime::create(extraout_s0);
    //   local_28 = 0;
    //   local_2c = (basic_string)((int)handleItND + 1);
    // pCVar1 = cocos2d::CCCallFuncND::create((CCObject *)this,handleItND + 1,0,httpResult);
    //   pCVar2 = (CCObject *)cocos2d::CCSequence::create((CCFiniteTimeAction *)FTA,pCVar1,0);
    //   cocos2d::CCActionManager::addAction
    // (*(CCActionManager **)&this->field_0xdc,pCVar2,(CCObject *)this,0);
}


/* GJMultiplayerManager::handleItND(cocos2d::CCNode*, void*) */

// void __thiscall GJMultiplayerManager::handleItND(GJMultiplayerManager *this,CCNode *node,void *p2 )

// {
//   bool success;
//   undefined auStack_2c [4];
//   undefined auStack_28 [4];
//   int local_24;
  
//   local_24 = __stack_chk_guard;
//   success = *(bool *)((int)p2 + 0x106);
//   std::basic_string::basic_string((basic_string *)auStack_2c,(basic_string *)((int)p2 + 0x108));
//   std::basic_string::basic_string((basic_string *)auStack_28,(basic_string *)((int)p2 + 0x10c));
//   handleIt(this,success,(basic_string)auStack_2c,(basic_string)auStack_28,
//            *(GJHttpType *)((int)p2 + 0x110));
//   std::basic_string::~basic_string((basic_string *)auStack_28);
//   std::basic_string::~basic_string((basic_string *)auStack_2c);
//   cocos2d::CCObject::release((CCObject *)p2);
//   if (local_24 != __stack_chk_guard) {
//                               /* WARNING: Subroutine does not return */
//     __stack_chk_fail();
//   }
//   return;
// }


/* GJMultiplayerManager::joinLobby(int) */

bool GJMultiplayerManager::joinLobby(int gameID)
{
    const char* DLKey = cocos2d::CCString::createWithFormat("%i_joinLobby",gameID)->getCString();
    bool dlActive = isDLActive(DLKey);
    if (!dlActive) {
      addDLToActive(DLKey);
      std::string postData = getBasePostString();
      auto secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'W',"mfv","3899",'g','c',"9")->getCString();
      postData += cocos2d::CCString::createWithFormat("&gameID=%i&lastCommentID=%i&secret=%s",gameID,getLastCommentIDForGame(gameID),secret)->getCString();
      ProcessHttpRequest("https://www.geometrydash.com/database/joinMPLobby.php",postData, DLKey, (GJHttpType)0x39);
    }
}



static GJMultiplayerManager* GLOBAL_GJMULTIPLAYERMANAGER;

GJMultiplayerManager * GJMultiplayerManager::sharedState(){

    if (GLOBAL_GJMULTIPLAYERMANAGER == nullptr) {
        GLOBAL_GJMULTIPLAYERMANAGER = new GJMultiplayerManager;
        GLOBAL_GJMULTIPLAYERMANAGER->m_DLObject = nullptr;
        GLOBAL_GJMULTIPLAYERMANAGER->m_unkDict3 = nullptr;
        GLOBAL_GJMULTIPLAYERMANAGER->m_unkDict2 = nullptr;
        GLOBAL_GJMULTIPLAYERMANAGER->m_unkDict1 = nullptr;
        GLOBAL_GJMULTIPLAYERMANAGER->init();
    } 
    return GLOBAL_GJMULTIPLAYERMANAGER;
}



/* Nice Manager :) - Calloc */