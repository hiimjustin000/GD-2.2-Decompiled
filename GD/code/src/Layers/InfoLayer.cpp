#include "includes.h"

void InfoLayer::updateUserScoreFinished(){
    if (m_canUpdateScore != false) {
        m_canUpdateScore = false;
        GameLevelManager::sharedState()->getLevelComments(
            getID(), m_page, m_itemCount, 
            GameManager::sharedState()->getGameVariable("0069"), 
            m_commentkeytype);
    }
}

void InfoLayer::commentUploadFinished(int ID)
{
  int _ID;
  GameManager *GM;
  
  if ((this->m_score == NULL) && (ID == getID())) {
    GameManager::sharedState()->setGameVariable(GM,"0069",false);
    updateCommentModeButtons();
    loadPage(0,false);
  }
}
