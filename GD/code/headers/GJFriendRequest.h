#ifndef __GJFRIENDREQUEST_H__
#define __GJFRIENDREQUEST_H__

#include "includes.h"

class GJFriendRequest : public cocos2d::CCNode {
public:
	  static GJFriendRequest* create();
	  static GJFriendRequest* create(cocos2d::CCDictionary*);
	  virtual bool init();

    int	m_requestID;
    int	m_fromAccountID;	
 	  int	m_toAccountID;
    std::string	m_comment;
    std::string	m_age;	
    bool m_isRead;
};



#endif // __GJFRIENDREQUEST_H__
