#include "includes.h"

class GJComment : public cocos2d::CCNode
{
public:
	std::string m_commentString;
	std::string m_userName;
	int m_commentID;
	int m_userID;
	int m_likeCount;
	int m_levelID;
	bool m_isSpam;
	int m_accountID;
	std::string m_uploadDate;
	bool m_commentDeleted;
	int m_percentage;
	int m_modBadge;
	cocos2d::ccColor3B m_color;
	bool m_hasLevelID;
	bool m_unkMultiplayerBool;
	GJUserScore* m_userScore;

	GJComment();
	static GJComment* create();
	static GJComment* create(cocos2d::CCDictionary*);
	virtual bool init();

	// These don't seem to exist anymore this was likely an 
	// optimization on Robtop's end...
	// int getUserID();
	// int getAccountID();
	// int getPercentage();
	// int getBadge();
	// cocos2d::ccColor3B getColour();
	// std::string getUsername();
	// std::string getComment();
};
