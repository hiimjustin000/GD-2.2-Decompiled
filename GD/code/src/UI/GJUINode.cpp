#include "includes.h"






void GJUINode::saveToConfig(UIButtonConfig *config)
{ 
  config->m_width = (int)this->m_width;
  config->m_height = (int)this->m_height;
  pGVar1 = this;
  getButtonScale(this);
  config->m_buttonScale = (float)pGVar1;
  iVar2 = getOpacity(this);
  config->m_dragRadius = this->m_dragRadius;
  config->m_deadZone = (int)this->m_deadZone;
  config->m_toggle = this->m_modeB;
  pcVar4 = (code *)((this->CCNode).vtable)->cocos2d_CCNode_getPosition;
  config->m_opacity = iVar2;
  pCVar3 = (CCPoint *)(*pcVar4)(this);
  cocos2d::CCPoint::operator=(&config->m_pos,pCVar3);
  config->m_visible = this->m_visible;
  config->m_noMove = this->m_noMove;
  return;
}