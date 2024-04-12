#include "includes.h"

GJFriendRequest *GJFriendRequest::create()
{
    GJFriendRequest *fr = new GJFriendRequest;
    if (fr != nullptr && fr->init())
    {
        fr->autorelease();
        return fr;
    }
    CC_SAFE_DELETE(fr);
    return nullptr;
}

GJFriendRequest *GJFriendRequest::create(cocos2d::CCDictionary *dict)
{
    
    auto FR = create();
    FR->m_requestID = dict->valueForKey("32")->intValue();
    FR->m_fromAccountID = dict->valueForKey("33")->intValue();
    FR->m_toAccountID = dict->valueForKey("34")->intValue();    
    FR->m_comment = LevelTools::base64DecodeString(dict->valueForKey("35")->getCString());
    FR->m_isRead = dict->valueForKey("36")->getCString() != nullptr;
    FR->m_age = dict->valueForKey("37")->getCString();
    return FR;
}

bool GJFriendRequest::init()
{
    return true;
}
