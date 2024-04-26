#include "includes.h"




/* I will be posting complexities of functions from ghidra's own
 * built-in scripts to show their difficulty so if I skip over any 
 * of them, you'll know why */

void GameObject::activateObject()
{
    return;
}



void GameObject::activatedByPlayer(PlayerObject* playerObject){
    /* NOOP */
};

/* complexity: 363 */
void GameObject::addColorSprite(std::string p0)
{
    return;
}

/* Unknown Fields */
void GameObject::addColorSpriteToParent(bool p0)
{
    return;
}


void GameObject::addColorSpriteToSelf()
{
    /* if we are indeed the parent we must exit... */
    if (this == reinterpret_cast<GameObject *>(getParent())) return;
    m_isChild = true;
    m_colorSprite->removeFromParentAndCleanup(false);
    addChild(m_colorSprite, m_show ? 100 : -100);
    m_colorSprite->setScale(1);
    m_colorSprite->setRotation(0);
    auto contentSize = getContentSize();
    m_colorSprite->setPosition(CCPointMake(contentSize.width * 0.5, contentSize.height * 0.5));
}

/* Unknown Fields */
void GameObject::addCustomBlackChild(std::string p0, float p1, bool p2)
{
    return;
}


cocos2d::CCSprite* GameObject::addCustomChild(std::string pszSpriteFrameName, cocos2d::CCPoint pos, int zOrder)
{
    cocos2d::CCSprite* sprite = cocos2d::CCSprite::createWithSpriteFrameName(pszSpriteFrameName.c_str());
    sprite->setPosition(convertToNodeSpace(pos) + pos);
    addChild(sprite, zOrder);
    return sprite;
}



cocos2d::CCSprite * GameObject::addCustomColorChild(std::string customColor)
{
  
    if (m_colorSprite != nullptr) {
        m_colorSprite->removeFromParent();
        if (m_colorSprite != nullptr) {
            m_colorSprite->release();
        } 
        m_colorSprite = nullptr;
    }
    createSpriteColor(2);
    m_colorSprite = cocos2d::CCSprite::createWithSpriteFrameName(customColor.c_str());
    m_colorSprite->retain();
    m_colorSprite->setPosition(getPosition());
    return m_colorSprite;
}


void __thiscall GameObject::addEmptyGlow()
{
    createGlow("emptyGlow.png");
    if (m_glow != nullptr) m_glow->setDontDraw(true);
}

/* complexity: 105 , numerous if statements that should be switch blocks... :( , 300+ lines of code */
void GameObject::addGlow(std::string p0){}


cocos2d::CCSprite* GameObject::addInternalChild(cocos2d::CCSprite* sprite, std::string frameName, cocos2d::CCPoint pos, int zOrder)
{
    cocos2d::CCSprite* new_sprite = cocos2d::CCSprite::createWithSpriteFrameName(frameName.c_str());
    new_sprite->setPosition(sprite->convertToNodeSpace(pos) + pos);
    sprite->addChild(new_sprite,zOrder);
    return new_sprite;
}


cocos2d::CCSprite * GameObject::addInternalCustomColorChild(std::string frameName, cocos2d::CCPoint pos, int zOrder)
{

    if (m_colorSprite == nullptr) return nullptr;
    m_colorSprite = cocos2d::CCSprite::createWithSpriteFrameName(frameName.c_str());
    m_colorSprite->setPosition(m_colorSprite->convertToNodeSpace(pos) + pos);
    m_colorSprite->addChild(m_colorSprite, zOrder);
    return m_colorSprite;
}


cocos2d::CCSprite * GameObject::addInternalGlowChild(std::string frameName, cocos2d::CCPoint pos)
{
    if (m_glow == nullptr) return nullptr;
    m_glow = cocos2d::CCSprite::createWithSpriteFrameName(frameName.c_str());
    m_glow->setPosition(m_glow->convertToNodeSpace(pos) + pos);
    m_glow->addChild(m_glow, -1);
    return m_glow;
}


/*  complexity: 8, Too Many Unknown Fields and data to work with at the moment... */
/* Unknown Return: GameObject::addMainSpriteToParent(bool p0){}; */


/* Unknown Subclass field at 0x1d7 */
void GameObject::addNewSlope01(bool p0)
{
    return;
}


void GameObject::addNewSlope01Glow(bool dontDraw)
{  
  
    if (m_glow == nullptr) return;
    if (dontDraw) m_glow->setDontDraw(true);
    
    cocos2d::CCSprite* sprite = cocos2d::CCSprite::createWithSpriteFrameName(getGlowFrame("blockOutline_14new_001.png").c_str());
    sprite->setRotation(-45);
    m_glow->addChild(sprite);
    /* It's probably this but IDK about what it's CCPoint is or where it's coming form... */
    sprite->setPosition(sprite->convertToNodeSpace(m_glow->getAnchorPoint()));
}

/* Same Problem as addNewSlope01 we don't know what 0x1d7 is supposed to be... */
void GameObject::addNewSlope02(bool p0)
{
    return;
}


void GameObject::addNewSlope02Glow(bool dontDraw)
{
    if (m_glow == nullptr) return;
    if (dontDraw) m_glow->setDontDraw(true);
    
    cocos2d::CCSprite* sprite = cocos2d::CCSprite::createWithSpriteFrameName(getGlowFrame("blockOutline_15new_001.png").c_str());
    sprite->setRotation(-26.5);
    m_glow->addChild(sprite);
    /* It's probably this but IDK about what it's CCPoint is or where it's coming form... */
    sprite->setPosition(sprite->convertToNodeSpace(m_glow->getAnchorPoint()));
}



void GameObject::addRotation(float rotationX, float rotationY)
{
    setRotationX(getRotationX() + rotationX);
    setRotationY(getRotationY() + rotationY);
}


/* unknown part at line 13: 
 * if (*(float *)((int)&sub + 0x34) == *(float *)((int)&sub + 0x38)) { 
 *
 * TODO: Ask Robtop 
 */
void GameObject::addRotation(float p0)
{
    return;
}


void __thiscall GameObject::addToColorGroup(int color)
{
    if ((m_colorGroupCount < 10) && ((color - 1) < 9999)) {
        createColorGroupContainer(10);
        for (int i = 0; i < m_colorGroupCount; i++){
            if (m_colorGroupContainer->operator[](i) == color) 
                break;
        }
        m_colorGroupCount++;
    }
}

void __thiscall GameObject::addToCustomScaleX(float scaleX)
{
    // field_0x2bc = true; Unknown
    m_objectRectDirty = true;
    m_realXPosition += scaleX;
    m_scaleX += scaleX;
}


void GameObject::addToCustomScaleY(float scaleY)
{
    // field_0x2bc = true; Unknown
    m_objectRectDirty = true;
    m_realYPosition += scaleY;
    m_scaleY += scaleY;
}



int GameObject::addToGroup(int groupNumber)
{
    if ((this->m_groupsCount < 10) && (groupNumber - 1 < 9999)) {
        createGroupContainer(10);
        int i = 0;
        while (true) {
            if (m_groupsCount <= i) {
                m_groupContainer->operator[](m_groupsCount) = groupNumber;
                m_groupsCount += 1;
                return 1;
            }
            if (m_groupContainer->operator[](i) == groupNumber) break;
            i++;
        }
        return -1;
    }
    return 0;
}


void __thiscall GameObject::addToOpacityGroup(int _opacity)
{

    if ((m_opacityGroupCount < 10) && (_opacity - 1 < 9999)) {
        createOpacityGroupContainer(10);
        for (int i = 0; i < m_opacityGroupCount; i + 1) {
            if (m_opacityGroupContainer[i] == _opacity) 
                return;
        }
        m_opacityGroupContainer[m_opacityGroupCount] = _opacity;
        m_opacityGroupCount += 1;
    }
}



void GameObject::addToTempOffset(double x, double y)
{  
    if (!m_horizonalOffsetOnly)
        m_realPositionX += x;
    m_realPositionY += y;
}


void GameObject::animationTriggered()
{
  /* NOOP */
}


static int GLOBAL_MID;

void GameObject::assignUniqueID(){
    this->m_unqiueID = GLOBAL_MID;
    //  what is this bullshit ;-; 
    //  *(int *)((int)&this->sub + 0x30) = GLOBAL_MID;
    // Maybe it's this?
    setTag(GLOBAL_MID);
    GLOBAL_MID++;
}



bool GameObject::belongsToGroup(int groupID)
{
    if (0 < m_groupsCount) {
        for (int i = 0; i < m_groupsCount; i++) {
            if (m_groupContainer->operator[](i) == groupID) 
                return true;
        }
    }
    return false;
}


/* Unknown Return: GameObject::blendModeChanged(){}; */


cocos2d::CCRect GameObject::calculateOrientedBox(){
    m_boxCalculated = true;
    updateOrientedBox();
    return getObjectRect();
};

bool GameObject::canAllowMultiActivate(){
    return false;
}

bool GameObject::canBeOrdered(){
    return false;
}

bool GameObject::canChangeCustomColor(){
    return canChangeMainColor() | canChangeSecondaryColor();
}

bool GameObject::canChangeMainColor(){
    return m_mainColor->m_defaultColorID != 0;
}

bool GameObject::canChangeSecondaryColor(){
    return m_detailColor->m_defaultColorID != 0;
}


bool GameObject::canMultiActivate(bool unk){
    return false;
}


bool GameObject::canReverse(){
    return false;
}


bool GameObject::canRotateFree(){
    /* What the fuck is this code Robtop? -_- */
    return ((m_objectType < 0x1a) && ((1 << (m_objectType & 0xff) & 0x2200001U))) && m_isNoTouch;
}

/* complexity: 18 , I am not doing this yet, too many unknown fields, However feel free to do it before I get to it if you must... */
/* Unknown Return: GameObject::claimParticle(){}; */

/* Unknown Class members are preventing me from doing this one... */
/* Unknown Return: GameObject::colorForMode(int p0, bool p1){}; */

/* Unknown Class Members */
void GameObject::commonInteractiveSetup()
{
}

/* Unknown Class Members */
void GameObject::commonSetup()
{
}


void GameObject::copyGroups(GameObject *object)
{
    if (object->m_groupsCount >= 1) {
        for (int i = 0; i < object->m_groupsCount; i = i + 1) {
            addToGroup(getGroupID(i));
        }
    }
}

/* TODO: There's some objects I have not Reversed yet in this one... */
/* Unknown Return: GameObject::createAndAddParticle(int p0, char const* p1, int p2, cocos2d::tCCPositionType p3){}; */

void __thiscall GameObject::createColorGroupContainer(int group)
{
    if (m_colorGroupContainer) {
        m_colorGroupContainer = new std::array<short, 10>;
        for (int i; i < group; i++){
            m_colorGroupContainer->operator[](i) = 0;
        }
    }
}


void GameObject::createGlow(std::string frameName)
{
    if (m_glow != nullptr) {
        m_glow->release();
        m_glow->removeMeAndCleanup();
        m_glow = nullptr;
    }
    m_glow = cocos2d::CCSprite::createWithSpriteFrameName(frameName.c_str());
    m_glow->retain();
    m_glow->setPosition(getPosition());
    m_glow->setOpacity(0xff);
}

void GameObject::createGroupContainer(int group)
{
    if (m_groupContainer) {
        m_groupContainer = new std::array<short, 10>;
        for (int i; i < group; i++){
            m_groupContainer->operator[](i) = 0;
        }
    }
}



void GameObject::createOpacityGroupContainer(int group)
{
    if (m_groupContainer) {
        m_groupContainer = new std::array<short, 10>;
        for (int i; i < group; i++){
            m_groupContainer->operator[](i) = 0;
        }
    }
}

/* TODO: GJSpriteColor */
/* Unknown Return: GameObject::createSpriteColor(int p0){}; */


GameObject * GameObject::createWithFrame(const char *frame)
{
    /* 0x488 */
    auto gameObject = new GameObject;
    if (gameObject != nullptr && gameObject->init(frame)) {
        gameObject->autorelease();
        return gameObject;
    }
    CC_SAFE_DELETE(gameObject);
    return nullptr;
}

/* Hell no, I am not ready to do this one...  complexity: 216, 600+ lines of code */
GameObject* GameObject::createWithKey(int key)
{
}


void GameObject::customObjectSetup(std::vector<std::string>& p0, std::vector<void*>& p1)
{
    /* NOOP */
}

/* complexity: 967 , 3600+ lines of code... ;-; */
void GameObject::customSetup()
{

}

/* complexity: 7 , Unknown Class Members 45 lines of code */
void GameObject::deactivateObject(bool p0)
{

}


void GameObject::deselectObject()
{
    this->m_isSelected = false;
    updateObjectEditorColor();
}

/* 2 Unknown Class variables */
void GameObject::destroyObject()
{
//   this->field_0x33a = 1;
//   this->field_0x292 = 1;
    setOpacity(0);
}


/* Unknown Class Members, complexity: 23, Lines of code 120 */
/* Unknown Return: GameObject::determineSlopeDirection(){}; */

/* Robtop, I think Think the math is not nessesary but feel free to enlighten me on why this is here - Calloc */

bool GameObject::didScaleXChange()
{
    return (this->m_scaleX * 10000.0) - (this->m_currentScaleX * 10000.0) != 0;
}

bool GameObject::didScaleYChange()
{
    return (this->m_scaleY * 10000.0) - (this->m_currentScaleY * 10000.0) != 0;
}

// 2 Unknown Class Members
// void __thiscall GameObject::dirtifyObjectPos(GameObject *this)
// {
//   this->field133_0x2bd = true;
//   this->field134_0x2be = true;
// }


void GameObject::dirtifyObjectRect()
{
    m_objectRectDirty = true;
    m_orientedRectDirty = true;
}


void GameObject::disableObject() {
    destroyObject();
    triggerActivated(0.f);
}


bool GameObject::dontCountTowardsLimit()
{
    return this->m_objectID == 0x1f;
}


void __thiscall GameObject::duplicateAttributes(GameObject *object)
{
    m_zOrder = object->getObjectZOrder();
    setCustomZLayer(object->getObjectZLayer());
    m_editorLayer = object->m_editorLayer;
    m_editorLayer2 = object->m_editorLayer2;
    m_isDontFade = object->m_isDontFade;
    m_isHighDetail = object->m_isHighDetail;
    m_isIceBlock = object->m_isIceBlock;
    m_isDontEnter = object->m_isDontEnter;
    m_isNoTouch = object->m_isNoTouch;
    m_isGripSlope = object->m_isGripSlope;
    m_hasNoEffects = object->m_hasNoEffects;
    m_isPassable = object->m_isPassable;
    m_hasNoGlow = object->m_hasNoGlow;
    m_isHide = object->m_isHide;
    m_isNonStickX = object->m_isNonStickX;
    m_isNonStickY = object->m_isNonStickY;
    m_isDontBoostY = object->m_isDontBoostY;
    m_isExtraSticky = object->m_isExtraSticky;
    m_isScaleStick = object->m_isScaleStick;
    m_isDontBoostX = object->m_isDontBoostX;
    m_hasNoParticles = object->m_hasNoParticles;
    m_hasNoAudioScale = object->m_hasNoAudioScale;
}   

/* Unknown Class Members, complexity: 6 , lines of code: 53 */
/* Unknown Return: GameObject::duplicateColorMode(GameObject* p0){}; */


void __thiscall GameObject::duplicateValues(GameObject *object)
{
    if (getRotationX() == getRotationY()) {
        this->setRotation(object->getRotation());
    }
    else {
        setRotationX(getRotationX());
        setRotationY(getRotationY());
    }
    setFlipX(object->isFlipX());
    setFlipY(object->isFlipY());
    duplicateColorMode(object);
    this->m_zOrder = object->m_zOrder;
    setCustomZLayer(object->getCustomZLayer());
    this->m_isDontFade = object->m_isDontFade;
    this->m_isDontEnter = object->m_isDontEnter;
    this->m_hasNoEffects = object->m_hasNoEffects;

    for (int i = 0; i < object->m_groupsCount; i++) {
        addToGroup(object->getGroupID(i));
    }
    // I think this is it?...
    updateCustomScaleX(object->m_scaleX);
    updateCustomScaleY(object->m_scaleY);
}


/*  complexity: 2 , Reason: Unknown Globals , Lines: 27 */
/* Unknown Return: GameObject::editorColorForCustomMode(int p0){}; */

/* complexity: 13, Reason: Unknown Class Member if Statements Should be switch blocks... , Lines: 80 */
/* Unknown Return: GameObject::editorColorForMode(int p0){}; */


void GameObject::fastRotateObject(float roataion)
{
    m_rotationX += roataion;
    m_rotationY += roataion;
    addRotation(roataion);
    if ((m_objectType != 7) && (m_boxCalculated == false)) {
        calculateOrientedBox();
    }
}


void GameObject::firstSetup()
{
    /* NOOP */
}

/* complexity: 1, Reason: Unknown Class Members , Lines: 230 */
/* GameObject::GameObject() */

/* complexity: 8, Reason: Unknown Class Members, Lines: 64 */
/* Unknown Return: GameObject::getActiveColorForMode(int p0, bool p1){}; */


/* The Random Pluse thingys from stero madness and many other Robtop levels... */

const char * GameObject::getBallFrame(int _ID){
    return cocos2d::CCString::createWithFormat("rod_ball_%02d_001.png", (_ID < 3) ? _ID & ~(_ID >> 0x1f) : 3)->getCString();
}


/* complexity: 3, Reason: Unknown Class Members, Slight Complexity on one part, Lines: 31*/
/* Unknown Return: GameObject::getBoundingRect(){}; */


/* complexity: 7, Reason: Unknown Class Members, Lines: 41 */
/* Unknown Return: GameObject::getBoxOffset(){}; */

/* complexity: 3, Reason: Unknown Function with Unknown std functions , Lines: 23 */
/* Unknown Return: GameObject::getColorFrame(std::string p0){}; */


int GameObject::getColorIndex()
{
    switch(m_objectID) {
        case 744: 
            return 1003;
        case 30: 
            return 1001;
        case 105: 
            return 1004;
        case 29: 
            return 1000;
        case 900: 
            return 1009;
        case 915: 
            return 1002;
        case 899: 
            return m_targetColor;
        default: 
            return 0;
    }
}

/* complexity: 13, Reason: Unknown Class Members and Heavy Complex parts, Lines: 139 */
/* Unknown Return: GameObject::getColorKey(bool p0, bool p1){}; */


int GameObject::getCustomZLayer()
{
    return m_customZLayer;
}

/* Same Issue as the other Frame thingy... */
/* Unknown Return: GameObject::getGlowFrame(std::string p0){}; */

/* Unknown Return Type */
/* 
undefined __thiscall GameObject::getGroupDisabled(GameObject *this)
  return this->m_groupDisabled;
}
*/


int GameObject::getGroupID(int groupID){
    if (groupID < 10) {
        if (m_groupContainer != nullptr) {
            return m_groupContainer->operator[](groupID);
        }
    }
    
    m_groupContainer = nullptr;
    
    return 0;
};


/* I will do this one later... - Calloc */
/* Unknown Return: GameObject::getGroupString(){}; */


bool GameObject::getHasRotateAction()
{
  return false;
}


/* Unknown Return: GameObject::getHasSyncedAnimation(){}; */


/* Unknown Return: GameObject::getLastPosition(){}; */


/* Unknown Return: GameObject::getMainColor(){}; */


/* Unknown Return: GameObject::getMainColorMode(){}; */


/* Unknown Return: GameObject::getObjectDirection(){}; */


/* Unknown Return: GameObject::getObjectLabel(){}; */


/* Unknown Return: GameObject::getObjectRadius(){}; */

cocos2d::CCRect const& GameObject::getObjectRect()
{
    return;
}


cocos2d::CCRect GameObject::getObjectRect(float p0, float p1)
{
    return;
}



/* Unknown Return: GameObject::getObjectRect2(float p0, float p1){}; */


/* Unknown Return: GameObject::getObjectRectDirty(){}; */


/* Unknown Return: GameObject::getObjectRectPointer(){}; */


/* Unknown Return: GameObject::getObjectRotation(){}; */


/* Unknown Return: GameObject::getObjectTextureRect(){}; */


/* Unknown Return: GameObject::getObjectZLayer(){}; */


/* Unknown Return: GameObject::getObjectZOrder(){}; */


/* Unknown Return: GameObject::getOrientedBox(){}; */


/* Unknown Return: GameObject::getOrientedRectDirty(){}; */


/* Unknown Return: GameObject::getOuterObjectRect(){}; */


/* Unknown Return: GameObject::getParentMode(){}; */


/* Unknown Return: GameObject::getRScaleX(){}; */


/* Unknown Return: GameObject::getRScaleY(){}; */

cocos2d::CCPoint GameObject::getRealPosition()
{
    return;
}



/* Unknown Return: GameObject::getRelativeSpriteColor(int p0){}; */

// std::string GameObject::getSaveString(GJBaseGameLayer* p0)
// {
//     return;
// }



/* Unknown Return: GameObject::getScalePosDelta(){}; */


/* Unknown Return: GameObject::getSecondaryColor(){}; */


/* Unknown Return: GameObject::getSecondaryColorMode(){}; */


/* Unknown Return: GameObject::getSlopeAngle(){}; */


/* Unknown Return: GameObject::getStartPos(){}; */


/* Unknown Return: GameObject::getTextKerning(){}; */


/* Unknown Return: GameObject::getType(){}; */


/* Unknown Return: GameObject::getUnmodifiedPosition(){}; */


/* Unknown Return: GameObject::groupColor(cocos2d::ccColor3B const& p0, bool p1){}; */


/* Unknown Return: GameObject::groupOpacityMod(){}; */


/* Unknown Return: GameObject::groupWasDisabled(){}; */


/* Unknown Return: GameObject::groupWasEnabled(){}; */


/* Unknown Return: GameObject::hasBeenActivated(){}; */


/* Unknown Return: GameObject::hasBeenActivatedByPlayer(PlayerObject* p0){}; */


/* Unknown Return: GameObject::hasSecondaryColor(){}; */

bool GameObject::ignoreEditorDuration()
{
    return;
}



/* Unknown Return: GameObject::ignoreEnter(){}; */


/* Unknown Return: GameObject::ignoreFade(){}; */

bool GameObject::init(char const* p0)
{
    return;
}


bool GameObject::initWithTexture(cocos2d::CCTexture2D* p0)
{
    return;
}


bool GameObject::isBasicEnterEffect(int p0)
{
    return;
}


bool GameObject::isBasicTrigger()
{
    return;
}


bool GameObject::isColorObject()
{
    return;
}


bool GameObject::isColorTrigger()
{
    return;
}


bool GameObject::isConfigurablePortal()
{
    return;
}


bool GameObject::isEditorSpawnableTrigger()
{
    return;
}


bool GameObject::isFacingDown()
{
    return;
}


bool GameObject::isFacingLeft()
{
    return;
}


bool GameObject::isFlipX()
{
    return;
}


bool GameObject::isFlipY()
{
    return;
}


bool GameObject::isSettingsObject()
{
    return;
}


bool GameObject::isSpawnableTrigger()
{
    return;
}


bool GameObject::isSpecialObject()
{
    return;
}


bool GameObject::isSpecialSpawnObject()
{
    return;
}


bool GameObject::isSpeedObject()
{
    return;
}


bool GameObject::isStoppableTrigger()
{
    return;
}


bool GameObject::isTrigger()
{
    return;
}


void GameObject::loadGroupsFromString(std::string p0)
{
    return;
}



/* Unknown Return: GameObject::makeInvisible(){}; */


/* Unknown Return: GameObject::makeVisible(){}; */

GameObject* GameObject::objectFromVector(std::vector<std::string>& p0, std::vector<void*>& p1, GJBaseGameLayer* p2, bool p3)
{
    return;
}



/* Unknown Return: GameObject::opacityModForMode(int p0, bool p1){}; */


/* Unknown Return: GameObject::parentForZLayer(int p0, bool p1, int p2){}; */


/* Unknown Return: GameObject::particleWasActivated(){}; */


/* Unknown Return: GameObject::perspectiveColorFrame(char const* p0, int p1){}; */


/* Unknown Return: GameObject::perspectiveFrame(char const* p0, int p1){}; */

void GameObject::playDestroyObjectAnim(GJBaseGameLayer* p0)
{
    return;
}



/* Unknown Return: GameObject::playPickupAnimation(cocos2d::CCSprite* p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, bool p9, float p10, float p11){}; */


/* Unknown Return: GameObject::playPickupAnimation(cocos2d::CCSprite* p0, float p1, float p2, float p3, float p4){}; */

void GameObject::playShineEffect()
{
    return;
}



/* Unknown Return: GameObject::quickUpdatePosition(){}; */


/* Unknown Return: GameObject::quickUpdatePosition2(){}; */


/* Unknown Return: GameObject::removeColorSprite(){}; */

void GameObject::removeFromGroup(int p0)
{
    return;
}



/* Unknown Return: GameObject::removeGlow(){}; */


/* Unknown Return: GameObject::reorderColorSprite(){}; */


/* Unknown Return: GameObject::resetColorGroups(){}; */


/* Unknown Return: GameObject::resetGroupDisabled(){}; */


/* Unknown Return: GameObject::resetGroups(){}; */


/* Unknown Return: GameObject::resetMID(){}; */


/* Unknown Return: GameObject::resetMainColorMode(){}; */


/* Unknown Return: GameObject::resetMoveOffset(){}; */

void GameObject::resetObject()
{
    return;
}



/* Unknown Return: GameObject::resetRScaleForced(){}; */


/* Unknown Return: GameObject::resetSecondaryColorMode(){}; */


/* Unknown Return: GameObject::restoreObject(){}; */


/* Unknown Return: GameObject::saveActiveColors(){}; */

void GameObject::selectObject(cocos2d::ccColor3B p0)
{
    return;
}


void GameObject::setAreaOpacity(float p0, float p1, int p2)
{
    return;
}


void GameObject::setChildColor(cocos2d::ccColor3B const& p0)
{
    return;
}


void GameObject::setCustomZLayer(int p0)
{
    return;
}


void GameObject::setDefaultMainColorMode(int p0)
{
    return;
}


void GameObject::setDefaultSecondaryColorMode(int p0)
{
    return;
}


void GameObject::setFlipX(bool p0)
{
    return;
}


void GameObject::setFlipY(bool p0)
{
    return;
}


void GameObject::setGlowColor(cocos2d::ccColor3B const& p0)
{
    return;
}


void GameObject::setGlowOpacity(unsigned char p0)
{
    return;
}


void GameObject::setLastPosition(cocos2d::CCPoint const& p0)
{
    return;
}


void GameObject::setMainColorMode(int p0)
{
    return;
}


void GameObject::setObjectColor(cocos2d::ccColor3B const& p0)
{
    return;
}


void GameObject::setObjectLabel(cocos2d::CCLabelBMFont* p0)
{
    return;
}


void GameObject::setObjectRectDirty(bool p0)
{
    return;
}


void GameObject::setOpacity(unsigned char p0)
{
    return;
}


void GameObject::setOrientedRectDirty(bool p0)
{
    return;
}


void GameObject::setPosition(cocos2d::CCPoint const& p0)
{
    return;
}


void GameObject::setRRotation(float p0)
{
    return;
}


void GameObject::setRScale(float p0)
{
    return;
}


void GameObject::setRScaleX(float p0)
{
    return;
}


void GameObject::setRScaleY(float p0)
{
    return;
}


void GameObject::setRotation(float p0)
{
    return;
}


void GameObject::setRotationX(float p0)
{
    return;
}


void GameObject::setRotationY(float p0)
{
    return;
}


void GameObject::setScale(float p0)
{
    return;
}


void GameObject::setScaleX(float p0)
{
    return;
}


void GameObject::setScaleY(float p0)
{
    return;
}


void GameObject::setSecondaryColorMode(int p0)
{
    return;
}


void GameObject::setStartPos(cocos2d::CCPoint p0)
{
    return;
}


void GameObject::setType(GameObjectType p0)
{
    return;
}


void GameObject::setVisible(bool p0)
{
    return;
}



/* Unknown Return: GameObject::setupColorSprite(int p0, bool p1){}; */

void GameObject::setupCustomSprites(std::string p0)
{
    return;
}



/* Unknown Return: GameObject::setupPixelScale(){}; */


/* Unknown Return: GameObject::setupSpriteSize(){}; */


/* Unknown Return: GameObject::shouldBlendColor(GJSpriteColor* p0, bool p1){}; */


/* Unknown Return: GameObject::shouldDrawEditorHitbox(){}; */


/* Unknown Return: GameObject::shouldLockX(){}; */


/* Unknown Return: GameObject::shouldNotHideAnimFreeze(){}; */


/* Unknown Return: GameObject::shouldShowPickupEffects(){}; */


/* Unknown Return: GameObject::slopeFloorTop(){}; */


/* Unknown Return: GameObject::slopeWallLeft(){}; */


/* Unknown Return: GameObject::slopeYPos(cocos2d::CCRect p0){}; */


/* Unknown Return: GameObject::slopeYPos(float p0){}; */


/* Unknown Return: GameObject::slopeYPos(GameObject* p0){}; */


/* Unknown Return: GameObject::spawnDefaultPickupParticle(GJBaseGameLayer* p0){}; */


/* Unknown Return: GameObject::spawnXPosition(){}; */


/* Unknown Return: GameObject::transferObjectRect(cocos2d::CCRect& p0){}; */

void GameObject::triggerActivated(float p0)
{
    return;
}


void GameObject::triggerObject(GJBaseGameLayer* p0, int p1, std::vector<int> const* p2)
{
    return;
}



/* Unknown Return: GameObject::unclaimParticle(){}; */

void GameObject::update(float p0)
{
    return;
}



/* Unknown Return: GameObject::updateBlendMode(){}; */


/* Unknown Return: GameObject::updateCustomColorType(short p0){}; */

void GameObject::updateCustomScaleX(float p0)
{
    return;
}


void GameObject::updateCustomScaleY(float p0)
{
    return;
}



/* Unknown Return: GameObject::updateHSVState(){}; */


/* Unknown Return: GameObject::updateIsOriented(){}; */


/* Unknown Return: GameObject::updateMainColor(){}; */


/* Unknown Return: GameObject::updateMainColor(cocos2d::ccColor3B const& p0){}; */


/* Unknown Return: GameObject::updateMainColorOnly(){}; */


/* Unknown Return: GameObject::updateMainOpacity(){}; */


/* Unknown Return: GameObject::updateMainParticleOpacity(unsigned char p0){}; */

void GameObject::updateObjectEditorColor()
{
    return;
}



/* Unknown Return: GameObject::updateOrientedBox(){}; */


/* Unknown Return: GameObject::updateParticleColor(cocos2d::ccColor3B const& p0){}; */


/* Unknown Return: GameObject::updateParticleOpacity(unsigned char p0){}; */


/* Unknown Return: GameObject::updateSecondaryColor(){}; */


/* Unknown Return: GameObject::updateSecondaryColor(cocos2d::ccColor3B const& p0){}; */


/* Unknown Return: GameObject::updateSecondaryColorOnly(){}; */


/* Unknown Return: GameObject::updateSecondaryOpacity(){}; */


/* Unknown Return: GameObject::updateSecondaryParticleOpacity(unsigned char p0){}; */


/* Unknown Return: GameObject::updateStartPos(){}; */


/* Unknown Return: GameObject::updateStartValues(){}; */


/* Unknown Return: GameObject::updateTextKerning(int p0){}; */


/* Unknown Return: GameObject::updateUnmodifiedPositions(){}; */


/* Unknown Return: GameObject::usesFreezeAnimation(){}; */


/* Unknown Return: GameObject::usesSpecialAnimation(){}; */
