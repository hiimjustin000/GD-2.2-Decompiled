#ifndef __GJMULTIPLAYERMANAGER_H__
#define __GJMULTIPLAYERMANAGER_H__
#pragma once
#include "../includes.h"


/* this is likely for the upcomming verses mode for geometry dash 
 * Some of these params are iffy right now so I'm putting an underscore
 * on the fronts of some of these */

class GJMultiplayerManager: public GManager, public cocos2d::CCNode {
public:
    cocos2d::CCDictionary* m_DLObject;
    cocos2d::CCDictionary* m_unkDict1;
    cocos2d::CCDictionary* m_unkDict2;
    cocos2d::CCDictionary* m_unkDict3;


    static GJMultiplayerManager* sharedState();

    /* TODO */
    void addComment(std::string param_1,int param_2);

    void addDLToActive(const char *key, cocos2d::CCObject *dummyObject);
    void addDLToActive(const char *key);

    /* Comming Soon */
    bool dataLoaded(DS_Dictionary* dsdict) override;
    /* Comming Soon */
    void encodeDataTo(DS_Dictionary* dsdict) override;

    /* HTTP Function */
    bool exitLobby(int gameID);
    /* HTTP Function */
    bool joinLobby(int gameID);


    /* Comming Soon */
    void firstSetup();

    /* TODO */
    int getLastCommentIDForGame(int commentID);



    bool isDLActive(const char* key);
    
    /* Static function ? */
    std::string getBasePostString();

    void ProcessHttpRequest(std::string endpoint, std::string params, std::string tag, GJHttpType httpType);
    void uploadComment(std::string _descriptionText,std::string _commentID);
    // Temporary INT param for now I literally wrote this all at 3AM 
    // void handleIt(bool success, std::string _response, std::string _tag, GJHttpType httpType);
    void handleIt(bool success, std::string response, std::string tag, int httpType);

    void handleItDelayed(bool success,std::string response,std::string tag, int httpType);

    void onJoinLobbyCompleted(std::string response, std::string tag);
    void onExitLobbyCompleted(std::string response, std::string tag);
    void onUploadCommentCompleted(std::string response, std::string tag);

    bool init();
};



#endif // __GJMULTIPLAYERMANAGER_H__
