#include <includes.h>

void GameManager::accountStatusChanged(){
    // if (this->m_pMenuLayer != NULL) {
    //     // MenuLayer::updateUserProfileButton(this->);
    // }
}

void GameManager::fadeInMenuMusic(){

}

/* This Function Place an Extreme importance with internal game variables as this function helps 
 * obtain many internal settings - Calloc 
 * */
bool GameManager::getGameVariable(char * _key){
    return m_valueKeeper->valueForKey(_key)->boolValue();
}

int GameManager::getIntGameVariable(const char* Key){
    return m_valueKeeper->valueForKey(cocos2d::CCString::createWithFormat("%s%s","gv_",Key)->getCString())->intValue();
}




/* -- RSV Values -- 
 * They are primarly used for geometry dash's rng patterns in game */

void GameManager::setHasRatingPower(int hasRatingPower){
    /* TODO: Figure out what class member really belongs to hasRatingPower 
     * Might have something to do with moderator status... */
    m_hasRatingPower = m_hasRatingPower;
    m_hasRatingPower_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_hasRatingPower_Random = m_hasRatingPower_Seed + m_hasRatingPower;
}

void GameManager::setPlayerBall(int playerBall){
    m_playerBall = m_playerBall;
    m_playerBall_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerBall_Random = m_playerBall_Seed + m_playerBall;
}

void GameManager::setPlayerBird(int playerBird){
    m_playerBird = m_playerBird;
    m_playerBird_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerBird_Random = m_playerBird_Seed + m_playerBird;
}

void GameManager::setPlayerColor(int playerColor){
    m_playerColor = m_playerColor;
    m_playerColor_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerColor_Random = m_playerColor_Seed + m_playerColor;
}

void GameManager::setPlayerColor2(int playerColor2){
    m_playerColor2 = m_playerColor2;
    m_playerColor2_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerColor2_Random = m_playerColor2_Seed + m_playerColor2;
}

void GameManager::setPlayerColor3(int playerGlowColor){
    m_playerGlowColor = m_playerGlowColor;
    m_playerGlowColor_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerGlowColor_Random = m_playerGlowColor_Seed + m_playerGlowColor;
}

void GameManager::setPlayerDart(int playerDart){
    m_playerDart = m_playerDart;
    m_playerDart_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerDart_Random = m_playerDart_Seed + m_playerDart;
}

void GameManager::setPlayerDeathEffect(int playerDeathEffect){
    m_playerDeathEffect = m_playerDeathEffect;
    m_playerDeathEffect_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerDeathEffect_Random = m_playerDeathEffect_Seed + m_playerDeathEffect;
}

void GameManager::setPlayerFrame(int playerFrame){
    m_playerFrame = m_playerFrame;
    m_playerFrame_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerFrame_Random = m_playerFrame_Seed + m_playerFrame;
}

void GameManager::setPlayerJetpack(int playerJetpack){
    m_playerJetpack = m_playerJetpack;
    m_playerJetpack_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerJetpack_Random = m_playerJetpack_Seed + m_playerJetpack;
}

void GameManager::setPlayerRobot(int playerRobot){
    m_playerRobot = m_playerRobot;
    m_playerRobot_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerRobot_Random = m_playerRobot_Seed + m_playerRobot;
}

void GameManager::setPlayerShip(int playerShip){
    m_playerShip = m_playerShip;
    m_playerShip_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerShip_Random = m_playerShip_Seed + m_playerShip;
}

void GameManager::setPlayerShipStreak(int playerShipStreak){
    m_playerShipStreak = m_playerShipStreak;
    m_playerShipStreak_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerShipStreak_Random = m_playerShipStreak_Seed + m_playerShipStreak;
}

void GameManager::setPlayerSpider(int playerSpider){
    m_playerSpider = m_playerSpider;
    m_playerSpider_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerSpider_Random = m_playerSpider_Seed + m_playerSpider;
}

void GameManager::setPlayerStreak(int playerStreak){
    m_playerStreak = m_playerStreak;
    m_playerStreak_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerStreak_Random = m_playerStreak_Seed + m_playerStreak;
}

void GameManager::setPlayerSwing(int playerSwing){
    m_playerSwing = m_playerSwing;
    m_playerSwing_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerSwing_Random = m_playerSwing_Seed + m_playerSwing;
}

void GameManager::setPlayerUserID(int playerUserID){
    m_playerUserID = m_playerUserID;
    m_playerUserID_Seed = (int)((float)rand() / 32767.0) * 1000.0;
    m_playerUserID_Random = m_playerUserID_Seed + m_playerUserID;
}
