#include "../includes.h"
#include "../delegates.h"
// #include "GD\cocos2d\cocos-headers\cocos2dx\cocos2d.h"
#include <cocos-ext.h>

#pragma once 

class GameLevelManager : public cocos2d::CCNode
{

	/* TODO Update Class Members and names... */
	cocos2d::CCDictionary* m_pMainLevels;
	cocos2d::CCDictionary* m_pSettings;
	cocos2d::CCDictionary* m_pSavedLevels; /* 0x140 */
	cocos2d::CCDictionary* m_pUnkDict; /* m_pUnkDict could be correlated to 0x1c0 */
	cocos2d::CCDictionary* m_pFollowedCreators; 
	cocos2d::CCDictionary* m_pDownloadedLevels; /* 0x138 */
	cocos2d::CCDictionary* m_pLikes; /* 0x13c */
	cocos2d::CCDictionary* m_pRatedLevels; /*  */
	cocos2d::CCDictionary* m_pRatedDemons;
	cocos2d::CCDictionary* m_pReportedLevels; /* 0x148 */
	cocos2d::CCDictionary* m_pSavedLevelFolders; /* 0x150 or 0x14c */
	cocos2d::CCDictionary* m_pLocalLevelFolders; /* 0x150 or 0x14c */
	cocos2d::CCDictionary* m_pDailyLevels; /* 0x154 */
	cocos2d::CCDictionary* m_pMapPackDict; /* 0x1b4 */
	int m_nStoredDailyTimer;
	int m_nStoredDailyID;
	int m_nActiveDailyID;
	DWORD unk6;
	int m_nStoredWeeklyTimer;
	int m_nStoredWeeklyID;
	int m_nActiveWeeklyID;
	cocos2d::CCDictionary* m_pGauntletLevels; /* 0x1b8 */
	cocos2d::CCDictionary* m_pUnkFilterMember;
	DWORD unk5;
	DWORD UnkFilterMemberValue;
	DWORD unk3;
	DWORD unk4;
	DWORD unk2;
	cocos2d::CCDictionary* m_pTimerDict; /* 0x198 */
	cocos2d::CCDictionary* m_pUsernameDict;
	cocos2d::CCDictionary* m_pUserIDDict; 
	cocos2d::CCDictionary* m_pAccountIDDict; /* 0x1a4 */
	cocos2d::CCDictionary* m_pOnlineLevelsDict;
	cocos2d::CCDictionary* m_pPageInfoDict;
	cocos2d::CCDictionary* m_pUnkDict2;
	cocos2d::CCDictionary* m_pSavedPacksDict;
	cocos2d::CCDictionary* m_pSavedGauntletsDict;
	cocos2d::CCDictionary* m_pDLObject; /* 0x1bc */
	cocos2d::CCDictionary* m_pLevelManagerDict;
	cocos2d::CCDictionary* m_pUserInfoDict; /* 0x1c4 */
	cocos2d::CCDictionary* m_pFriendRequestsDict; /* 0x1a8 ?? */
	cocos2d::CCDictionary* m_pUserMessageDict; /* 0x1cc */
	cocos2d::CCDictionary* m_pUserReplyDict; /* 0x1d0 */
	std::string m_sSearchKey;
	std::string m_sUnkString2;
	LeaderboardState m_eLeaderboardState;
	bool m_bUnkEditLevelLayerOnBack;

	// some of these delegates may be incorrect, i found these at 3am and havent double checked them

	OnlineListDelegate* m_pOnlineListDelegate;
	LevelDownloadDelegate* m_pLevelDownloadDelegate;
	LevelCommentDelegate* m_pLevelCommentDelegate;
	CommentUploadDelegate* m_pCommentUploadDelegate;
	LevelUploadDelegate* m_pLevelUploadDelegate;
	LevelUpdateDelegate* m_pLevelUpdateDelegate;
	LeaderboardManagerDelegate* m_pLeaderboardManagerDelegate;
	LevelDeleteDelegate* m_pLevelDeleteDelegate;
	UserInfoDelegate* m_pUserInfoDelegate;
	LevelManagerDelegate* m_pLevelManagerDelegate;
	void* m_pUnkDelegate;
	FriendRequestDelegate* m_pFriendRequestDelegate;
	MessageListDelegate* m_pMessageListDelegate;
	DownloadMessageDelegate* m_pDownloadMessageDelegate;
	UploadMessageDelegate* m_pUploadMessageDelegate;
	GJRewardDelegate* m_pGJRewardDelegate;
	GJChallengeDelegate* m_pGJChallengeDelegate;
	GJDailyLevelDelegate* m_pGJDailyLevelDelegate;
	MusicDownloadDelegate* m_pMusicDownloadDelegate;
	int m_nUnkDownload;
	DWORD unk;
	std::string m_sUnkString;
	bool b_NetworkTested;


	/* TODO: Alter Fieldnames...*/
	/* 0x158 0x4 int */ int	m_dailyTimeLeft	;
	/* 0x15c 0x4 int */ int	m_dailyID;
	/* 0x160 0x4 int */ int	m_weeklyTimeLeft;	
	/* 0x164 0x4 int */ int	m_weeklyID;
	/* 0x168 0x4 int */ int	m_weeklyIDUnk;
	/* 0x16c 0x4 int */ int	m_eventTimeLeft;	
	/* 0x170 0x4 int */ int	m_eventID;
	/* 0x174 0x4 int */ int	m_eventIDUnk;	

	/* TODO : ReOrganize this shit from A-Z... */

	bool isFollowingUser(int ID);
	

	static GameLevelManager* sharedState();
	const char* getDiffKey (int Diff);
	void handleIt(bool success, std::string _response,std::string _tag, GJHttpType httpType);
	void getLevelComments(int ID, int page, int total, int mode, CommentKeyType keytype);
	const char* getCommentKey (int ID, int page, int mode, CommentKeyType keytype);
	const char* getAccountCommentKey(int accountID, int page);
	void getAccountComments(int accountID,int page,int total);
	
	bool isDLActive (const char * DLKey);
	void addDLToActive(const char *_tag);
	void addDLToActive(cocos2d::CCNode* obj , const char *_tag);
	void removeDLFromActive(const char* _tag);
	void cleanupDailyLevels();


	const char* getFriendRequestKey(bool sent, int page);
	void getFriendRequests(bool sent, int page, int total);

	const char* getGauntletKey(int key);
	const char* getGauntletSearchKey(int searchKey);
	void getGauntlets();

	/* TODO turn levelType Variable back into a GJTimedLevelType once figured out...*/
	void getGJDailyLevelState(int levelType);
	const char* getUserInfoKey(int targetAccountID);
	void getGJUserInfo(int targetAccountID);
	const char* getLenKey(int Len);	

	void getLevelSaveData();

	const char* getMapPackKey(int pack);

	int accountIDForUserID(int accountID);

	// const char* getLevelKey(int levelID);
	bool hasDownloadedLevel(int levelID);

	const char* getPostCommentsKey(int seconds_left);
	const char* getRateStarsKey(int key);
	const char* getReportKey(int levelID);
	bool hasReportedLevel(int levelID);
	void markLevelAsReported(int levelID); /* TODO (Calloc): Reverse Engineer markLevelAsReported() */
	void reportLevel(int levelID);
	void getUsers (GJSearchObject * searhObject);

	void getTopArtists(int page,int total);
	const char* getTopArtistsKey(int key);

	void getUserList(UserListType listType);

	const char* getMessagesKey (bool sent, int page);
	void getUserMessages(bool getSent, int page, int total);

	/* TODO: Wrtie all of getBasePostString() */
	static std::string getBasePostString();

	void ProcessHttpRequest(std::string endpoint, std::string params, std::string tag, GJHttpType httpType);
	void performNetworkTest();

	void onProcessHttpRequestCompleted (cocos2d::extension::CCHttpClient * client, cocos2d::extension::CCHttpResponse * response);

	int accountIDForUserID(int accountID);
	const char* getLevelKey(int levelID);
	bool areGauntletsLoaded();

	std::string getNextLevelName(std::string &levelName);
	const char* getMessageKey(bool, int);

	void blockUser(int accountID);

	/* All on-Callbacks... it's the definition of hell...*/
	// void on * Completed(std::string response, std::string tag);
	// There's about 49 of them total...
	
	void onUploadLevelCompleted(std::string response, std::string tag);
	void onGetOnlineLevelsCompleted(std::string response, std::string tag);
	void onGetMapPacksCompleted(std::string response, std::string tag);
	void onDownloadLevelCompleted(std::string response, std::string tag);
	void onUpdateLevelCompleted(std::string response, std::string tag);
	void onRateStarsCompleted(std::string response, std::string tag);
	void onDeleteServerLevelCompleted(std::string response, std::string tag);
	void onSetLevelStarsCompleted(std::string response, std::string tag);
	void onSetLevelFeaturedCompleted(std::string response, std::string tag);
	void onUpdateUserScoreCompleted(std::string response, std::string tag);
	void onGetLeaderboardScoresCompleted(std::string response, std::string tag);
	void onGetLevelCommentsCompleted(std::string response, std::string tag);
	void onUploadCommentCompleted(std::string response, std::string tag);
	void onDeleteCommentCompleted(std::string response, std::string tag);
	void onLikeItemCompleted(std::string response, std::string tag);
	void onRestoreItemsCompleted(std::string response, std::string tag);
	void onSubmitUserInfoCompleted(std::string response, std::string tag);
	void onReportLevelCompleted(std::string response, std::string tag);
	void onUpdateDescriptionCompleted(std::string response, std::string tag);
	void onGetAccountCommentsCompleted(std::string response, std::string tag);
	void onGetGJUserInfoCompleted(std::string response, std::string tag);
	void onGetFriendRequestsCompleted(std::string response, std::string tag);
	void onUploadFriendRequestCompleted(std::string response, std::string tag);
	void onDeleteFriendRequestCompleted(std::string response, std::string tag);
	void onAcceptFriendRequestCompleted(std::string response, std::string tag);
	void onReadFriendRequestCompleted(std::string response, std::string tag);
	void onRemoveFriendCompleted(std::string response, std::string tag);
	void onBlockUserCompleted(std::string response, std::string tag);
	void onUnblockUserCompleted(std::string response, std::string tag);
	void onGetUserListCompleted(std::string response, std::string tag);
	void onGetUserMessagesCompleted(std::string response, std::string tag);
	void onDownloadUserMessageCompleted(std::string response, std::string tag);
	void onDeleteUserMessagesCompleted(std::string response, std::string tag);
	void onUploadUserMessageCompleted(std::string response, std::string tag);
	void onGetUsersCompleted(std::string response, std::string tag);
	void onBanUserCompleted(std::string response, std::string tag);
	void onRequestUserAccessCompleted(std::string response, std::string tag);
	void onGetLevelSaveDataCompleted(std::string response, std::string tag);
	void onSuggestLevelStarsCompleted(std::string response, std::string tag);
	void onGetGJRewardsCompleted(std::string response, std::string tag);
	void onGetGJChallengesCompleted(std::string response, std::string tag);
	void onGetGJDailyLevelStateCompleted(std::string response, std::string tag);
	void onRateDemonCompleted(std::string response, std::string tag);
	void onGetLevelLeaderboardCompleted(std::string response, std::string tag);
	void onGetGauntletsCompleted(std::string response, std::string tag);
	void onGetTopArtistsCompleted(std::string response, std::string tag);
	void onGetLevelListsCompleted(std::string response, std::string tag);
	void onUploadLevelListCompleted(std::string response, std::string tag);
	void onDeleteServerLevelListCompleted(std::string response, std::string tag);
	void onGetNewsCompleted(std::string response, std::string tag);

	
	char * getDeleteCommentKey (int levelID, int commentID, int Ctype)
	void deleteComment (int commentID, CommentType Ctype, int levelID);
	void acceptFriendRequest (int targetAccountID, int requestID);
	void resetStoredUserInfo(int);

	void followUser (int ID);

	/* I know that CCObject is not the final class name for the return however it's a subclass of that specific return object... */
	cocos2d::CCObject* friendRequestFromAccountID(int accountID);
	
	const char* getLevelDownloadKey(int levelID, bool _isGauntlet);
	const char* getLevelListKey(int listID);

	

	void deleteServerLevel(int levelID);
	void downloadUserMessage (int messageID, bool isSender);


	int getDailyID(GJTimedLevelType timedleveltype);
	int getDailyTimer(GJTimedLevelType timedleveltype);

	void getOnlineLevels(GJSearchObject* query);

	cocos2d::CCArray* getCompletedLevels(bool unknown_filter);

	void getLevelLists(GJSearchObject *searchObject);


	/* -- could be an inline function... -- */
	/* I orginally thought this was for eldermods banning users but it turns out they have a 
 	secondary application for comment banning that us ordarny people will never see... - Calloc */
	void banUser(int userID);
};
