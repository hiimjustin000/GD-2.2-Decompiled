#include "includes.h"

/* NOTE: not all of this has changed since 2.1 however I am giving this a name change to match up with geode's work... 
 * Unless Wylie Says otherwise when I go to merge it to his future 2.2 repo... - Calloc */

GJComment::GJComment()
{
	m_commentID = 0;
	m_userID = 0;
	m_likeCount = 0;
	m_levelID = 0;
	m_commentString = "";
	m_userName = "";
	m_isSpam = false;
	m_userID = 0;
	m_uploadDate = "";
	m_commentDeleted = false;
	m_percentage = 0;
	m_modBadge = 0; /* Should've been called an authority - Calloc */
	/* text Colors by default should be set to white... */
	m_color = cocos2d::ccWHITE;
	m_hasLevelID = false;
	m_userScore = nullptr;
}

GJComment* GJComment::create()
{
	auto pRet = new GJComment;

	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}


bool GJComment::init()
{
	m_commentString = "";
	m_uploadDate = "";
	return true;
}

// Removed since 2.2 I left this in here to show what has died...
// int GJComment::getAccountID()
// {
// 	return m_accountID;
// }

// int GJComment::getUserID() 
// {
// 	return m_userID;
// }

// int GJComment::getPercentage()
// {
// 	return m_percentage;
// }

// int GJComment::getBadge()
// {
// 	return m_modBadge;
// }

// cocos2d::ccColor3B GJComment::getColour()
// {
// 	return m_color;
// }

// std::string GJComment::getUsername()
// {
// 	return m_userName;
// }

// std::string GJComment::getComment()
// {
// 	return m_commentString;
// }

GJComment* GJComment::create(cocos2d::CCDictionary* dict)
{
	GJComment* comment = create();
	/* One major change was that base64 content is now being decoded here... */
	comment->m_commentString = LevelTools::base64DecodeString(dict->valueForKey("2")->m_sString);
	comment->m_userID = dict->valueForKey("3")->intValue();
	comment->m_likeCount = dict->valueForKey("4")->intValue();
	comment->m_commentID = dict->valueForKey("6")->intValue();
	comment->m_isSpam = dict->valueForKey("7")->boolValue();
	comment->m_accountID = dict->valueForKey("8")->intValue();
	comment->m_uploadDate = dict->valueForKey("9")->getCString();
	comment->m_percentage = dict->valueForKey("10")->intValue();
	comment->m_modBadge = dict->valueForKey("11")->intValue();
	comment->m_levelID = dict->valueForKey("1")->intValue();

	if (comment->m_levelID != 0){
		comment->m_hasLevelID = true;
	}

	/* is the user a Mod? */
	if (comment->m_modBadge > 0)
	{
		cocos2d::CCArray* colArr = RobTop::splitToCCArray(dict->valueForKey("12")->m_sString, ",");
		/* does the user have colored comments? */
		if (colArr->count() > 2) {
			comment->m_color.r = colArr->stringAtIndex(0)->intValue();
			comment->m_color.g = colArr->stringAtIndex(1)->intValue();
			comment->m_color.b = colArr->stringAtIndex(2)->intValue();
		}
	}

	return comment;
}
