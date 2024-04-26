#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "includes.h"
#include <array>

/* ================ GAME OBJECT ============================================ */
/*   I am putting these Notes in because of it's sheer size it's important that 
 *   You understand these things that I will be writing down 
 *
 * - This Object is many lines of code more than many others that I've already done
 * - There's Many Unfound Portions in this object that the community 
 *   does not know about 
 *
 * - I'm doing this mental suffering for all of you to have this object and I will for 
 *   Now be reverse engineering the smaller pices of this object so that Eventually the 
 *   bigger chunks of code will be solved by either me or someone else.
 * 
 * - There were many additional things added in 2.2 That make this object super bulky
 *   which might be why Nobody has ever tackled writing in it's code before until now. 
 *   I've wanted to now undertake such a massive feat. To prove that the impossible is 
 *   possible in order to encourage others to get off their ass and help me.
 * 
 * - Any fields that were not guessed or known about or were not listed will not be done 
 *   until later 
 * 
 * - Some Fields may require me to use other external tools and experimentation to find them
 * 
 * - Some Code may require me to ask robtop since or other people since my other friend quit.
 *   But who knows... 
 * 
 * - 254 Functions Total 
 * 
 * - Functions that were skipped are marked By Reason, Complexity measured by using Ghidra's 
 *   ComputeCyclomaticComplexity script and lines of code 
 *
 * - I encourage anyone to start reversing this object for me due to it's sheer size. 
 */

enum GameObjectType {
};

/* TODO */
class PlayerObject;

/* Temporary home for now TODO: GJSpriteColor Unless Wylie has done that one already... */
class GJSpriteColor{
public:
    int	m_colorID;	
    int	m_defaultColorID;	
    float m_opacity;	
    cocos2d::ccHSVValue *m_hsv;	

    bool m_usesHsv;
};


class GameObject : public CCSpritePlus {
public:
	
	/* 254 FUNCTIONS WHAT THE FUCK... */

	void addColorSprite(std::string p0);
    void addColorSpriteToParent(bool p0);
    void addColorSpriteToSelf();
    void addCustomBlackChild(std::string p0, float p1, bool p2);
   	cocos2d::CCSprite* addCustomChild(std::string pszSpriteFrameName, cocos2d::CCPoint pos, int zOrder);
    cocos2d::CCSprite* addCustomColorChild(std::string customColor);
    void addEmptyGlow();
    void addGlow(std::string p0);
    cocos2d::CCSprite* addInternalChild(cocos2d::CCSprite* sprite, std::string frameName, cocos2d::CCPoint pos, int zOrder);
    cocos2d::CCSprite* addInternalCustomColorChild(std::string p0, cocos2d::CCPoint p1, int p2);
    cocos2d::CCSprite* addInternalGlowChild(std::string p0, cocos2d::CCPoint p1);
    void addNewSlope01(bool p0);
    void addNewSlope01Glow(bool p0);
    void addNewSlope02(bool p0);
    void addNewSlope02Glow(bool p0);
    void addRotation(float p0, float p1);
    void addRotation(float p0);
    void addToColorGroup(int p0);
    void addToCustomScaleX(float p0);
    void addToCustomScaleY(float p0);
    void addToOpacityGroup(int p0);
    void addToTempOffset(double p0, double p1);
    void assignUniqueID();
    bool belongsToGroup(int groupID);
    cocos2d::CCRect calculateOrientedBox();
    bool canChangeCustomColor();
    bool canChangeMainColor();
    bool canChangeSecondaryColor();
    bool canRotateFree();
    TodoReturn colorForMode(int p0, bool p1);
    void commonInteractiveSetup();
    void commonSetup();
    TodoReturn copyGroups(GameObject* p0);
    TodoReturn createAndAddParticle(int p0, char const* p1, int p2, cocos2d::tCCPositionType p3);
    TodoReturn createColorGroupContainer(int p0);
    void createGlow(std::string p0);
    void createGroupContainer(int p0);
    void createOpacityGroupContainer(int group);
    TodoReturn createSpriteColor(int p0);
    static GameObject* createWithFrame(char const* frame);
    static GameObject* createWithKey(int p0);
    void deselectObject();
    void destroyObject();
    void determineSlopeDirection();
    bool didScaleXChange();
    bool didScaleYChange();
    TodoReturn dirtifyObjectPos();
    TodoReturn dirtifyObjectRect();
    void disableObject();
    bool dontCountTowardsLimit();
    void duplicateAttributes(GameObject* p0);
    TodoReturn duplicateColorMode(GameObject* p0);
    void duplicateValues(GameObject* p0);
    TodoReturn editorColorForCustomMode(int p0);
    TodoReturn editorColorForMode(int p0);
    void fastRotateObject(float rotation);
    TodoReturn getActiveColorForMode(int p0, bool p1);
    const char* getBallFrame(int p0);
    TodoReturn getBoundingRect();
    TodoReturn getBoxOffset();
    TodoReturn getColorFrame(std::string p0);
    int getColorIndex();
    TodoReturn getColorKey(bool p0, bool p1);
    int getCustomZLayer();
    std::string getGlowFrame(std::string p0);
    TodoReturn getGroupDisabled();
    int getGroupID(int p0);
    TodoReturn getGroupString();
    TodoReturn getLastPosition();
    TodoReturn getMainColor();
    TodoReturn getMainColorMode();
    TodoReturn getObjectDirection();
    TodoReturn getObjectRadius();
    TodoReturn getObjectRectDirty();
    TodoReturn getObjectRectPointer();
    int getObjectZLayer();
    int getObjectZOrder();
    TodoReturn getOrientedRectDirty();
    TodoReturn getOuterObjectRect();
    TodoReturn getParentMode();
    TodoReturn getRelativeSpriteColor(int p0);
    TodoReturn getScalePosDelta();
    TodoReturn getSecondaryColor();
    TodoReturn getSecondaryColorMode();
    TodoReturn getSlopeAngle();
    TodoReturn getStartPos();
    TodoReturn getType();
    TodoReturn getUnmodifiedPosition();
    TodoReturn groupColor(cocos2d::ccColor3B const& p0, bool p1);
    TodoReturn groupOpacityMod();
    TodoReturn groupWasDisabled();
    TodoReturn groupWasEnabled();
    TodoReturn hasSecondaryColor();
    bool ignoreEditorDuration();
    TodoReturn ignoreEnter();
    TodoReturn ignoreFade();
    bool init(char const* p0);
    bool isBasicEnterEffect(int p0);
    bool isBasicTrigger();
    bool isColorObject();
    bool isColorTrigger();
    bool isConfigurablePortal();
    bool isEditorSpawnableTrigger();
    bool isFacingDown();
    bool isFacingLeft();
    bool isSettingsObject();
    bool isSpawnableTrigger();
    bool isSpecialObject();
    bool isSpeedObject();
    bool isStoppableTrigger();
    bool isTrigger();
    void loadGroupsFromString(std::string p0);
    TodoReturn makeInvisible();
    TodoReturn makeVisible();
    static GameObject* objectFromVector(std::vector<std::string>& p0, std::vector<void*>& p1, GJBaseGameLayer* p2, bool p3);
    TodoReturn opacityModForMode(int p0, bool p1);
    TodoReturn parentForZLayer(int p0, bool p1, int p2);
    TodoReturn perspectiveColorFrame(char const* p0, int p1);
    TodoReturn perspectiveFrame(char const* p0, int p1);
    void playDestroyObjectAnim(GJBaseGameLayer* p0);
    TodoReturn playPickupAnimation(cocos2d::CCSprite* p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, bool p9, float p10, float p11);
    TodoReturn playPickupAnimation(cocos2d::CCSprite* p0, float p1, float p2, float p3, float p4);
    void playShineEffect();
    TodoReturn quickUpdatePosition();
    TodoReturn quickUpdatePosition2();
    TodoReturn removeColorSprite();
    TodoReturn removeGlow();
    TodoReturn reorderColorSprite();
    TodoReturn resetColorGroups();
    TodoReturn resetGroupDisabled();
    TodoReturn resetGroups();
    TodoReturn resetMainColorMode();
    TodoReturn resetMID();
    TodoReturn resetMoveOffset();
    TodoReturn resetRScaleForced();
    TodoReturn resetSecondaryColorMode();
    void setAreaOpacity(float p0, float p1, int p2);
    void setCustomZLayer(int p0);
    void setDefaultMainColorMode(int p0);
    void setDefaultSecondaryColorMode(int p0);
    void setGlowOpacity(unsigned char p0);
    void setLastPosition(cocos2d::CCPoint const& p0);
    void setMainColorMode(int p0);
    void setSecondaryColorMode(int p0);
    TodoReturn setupColorSprite(int p0, bool p1);
    TodoReturn setupPixelScale();
    TodoReturn setupSpriteSize();
    TodoReturn shouldBlendColor(GJSpriteColor* p0, bool p1);
    TodoReturn shouldLockX();
    TodoReturn shouldNotHideAnimFreeze();
    TodoReturn shouldShowPickupEffects();
    TodoReturn slopeFloorTop();
    TodoReturn slopeWallLeft();
    TodoReturn slopeYPos(cocos2d::CCRect p0);
    TodoReturn slopeYPos(float p0);
    TodoReturn slopeYPos(GameObject* p0);
    TodoReturn spawnDefaultPickupParticle(GJBaseGameLayer* p0);
    TodoReturn updateBlendMode();
    TodoReturn updateCustomColorType(short p0);
    void updateCustomScaleX(float p0);
    void updateCustomScaleY(float p0);
    TodoReturn updateHSVState();
    TodoReturn updateIsOriented();
    TodoReturn updateMainColor();
    TodoReturn updateMainColorOnly();
    TodoReturn updateMainOpacity();
    void updateObjectEditorColor();
    TodoReturn updateSecondaryColor();
    TodoReturn updateSecondaryColorOnly();
    TodoReturn updateSecondaryOpacity();
    TodoReturn updateStartPos();
    TodoReturn updateUnmodifiedPositions();
    TodoReturn usesFreezeAnimation();
    TodoReturn usesSpecialAnimation();
    virtual void update(float p0);
    virtual void setScaleX(float p0);
    virtual void setScaleY(float p0);
    virtual void setScale(float p0);
    virtual void setPosition(cocos2d::CCPoint const& p0);
    virtual void setVisible(bool p0);
    virtual void setRotation(float p0);
    virtual void setRotationX(float p0);
    virtual void setRotationY(float p0);
    virtual void setOpacity(unsigned char p0);
    virtual bool initWithTexture(cocos2d::CCTexture2D* p0);
    virtual void setChildColor(cocos2d::ccColor3B const& p0);
    virtual void setFlipX(bool p0);
    virtual void setFlipY(bool p0);
    virtual void firstSetup();
    virtual void customSetup();
    virtual void setupCustomSprites(std::string p0);
    virtual TodoReturn addMainSpriteToParent(bool p0);
    virtual void resetObject();
    virtual void triggerObject(GJBaseGameLayer* p0, int p1, std::vector<int> const* p2);
    virtual void activateObject();
    virtual void deactivateObject(bool p0);
    virtual TodoReturn transferObjectRect(cocos2d::CCRect& p0);
    virtual cocos2d::CCRect const& getObjectRect();
    virtual cocos2d::CCRect getObjectRect(float p0, float p1);
    virtual TodoReturn getObjectRect2(float p0, float p1);
    virtual TodoReturn getObjectTextureRect();
    virtual cocos2d::CCPoint getRealPosition();
    virtual void setStartPos(cocos2d::CCPoint p0);
    virtual TodoReturn updateStartValues();
    virtual void customObjectSetup(std::vector<std::string>& p0, std::vector<void*>& p1);
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
    virtual TodoReturn claimParticle();
    virtual TodoReturn unclaimParticle();
    virtual TodoReturn particleWasActivated();
    virtual bool isFlipX();
    virtual bool isFlipY();
    virtual void setRScaleX(float p0);
    virtual void setRScaleY(float p0);
    virtual void setRScale(float p0);
    virtual TodoReturn getRScaleX();
    virtual TodoReturn getRScaleY();
    virtual void setRRotation(float p0);
    virtual void triggerActivated(float p0);
    virtual void setObjectColor(cocos2d::ccColor3B const& p0);
    virtual void setGlowColor(cocos2d::ccColor3B const& p0);
    virtual TodoReturn restoreObject();
    virtual TodoReturn animationTriggered();
    virtual void selectObject(cocos2d::ccColor3B p0);
    virtual TodoReturn activatedByPlayer(PlayerObject* p0);
    virtual TodoReturn hasBeenActivatedByPlayer(PlayerObject* p0);
    virtual TodoReturn hasBeenActivated();
    virtual TodoReturn getOrientedBox();
    virtual TodoReturn updateOrientedBox();
    virtual TodoReturn getObjectRotation();
    virtual TodoReturn updateMainColor(cocos2d::ccColor3B const& p0);
    virtual TodoReturn updateSecondaryColor(cocos2d::ccColor3B const& p0);
    virtual int addToGroup(int p0);
    virtual void removeFromGroup(int p0);
    virtual TodoReturn saveActiveColors();
    virtual TodoReturn spawnXPosition();
    virtual bool canAllowMultiActivate();
    virtual TodoReturn blendModeChanged();
    virtual TodoReturn updateParticleColor(cocos2d::ccColor3B const& p0);
    virtual TodoReturn updateParticleOpacity(unsigned char p0);
    virtual TodoReturn updateMainParticleOpacity(unsigned char p0);
    virtual TodoReturn updateSecondaryParticleOpacity(unsigned char p0);
    virtual bool canReverse();
    virtual bool isSpecialSpawnObject();
    virtual bool canBeOrdered();
    virtual TodoReturn getObjectLabel();
    virtual void setObjectLabel(cocos2d::CCLabelBMFont* p0);
    virtual TodoReturn shouldDrawEditorHitbox();
    virtual TodoReturn getHasSyncedAnimation();
    virtual bool getHasRotateAction();
    virtual bool canMultiActivate(bool p0);
    virtual TodoReturn updateTextKerning(int p0);
    virtual TodoReturn getTextKerning();
    virtual void setObjectRectDirty(bool p0);
    virtual void setOrientedRectDirty(bool p0);
    virtual void setType(GameObjectType p0);


    int m_innerSectionIndex;
    int m_outSectionIndex;
    int m_middleSectionIndex;
    bool m_hasExtendedCollision;
    cocos2d::ccColor3B m_color;

    CCSprite *m_glowSprite;

    bool field17_0x225;

    float field21_0x229;

    std::string m_particleString;
    bool m_particleUseObjectColor;

    float field38_0x240;

    double m_rotationX;
    double m_rotationY;

    float m_realXPosition;
    float m_realYPosition;

    /* Not sure what to name this one other than it confuses me :( */
    bool m_horizonalOffsetOnly;

    CCObject *m_orientedBox;
    bool m_boxCalculated;


    CCSprite *m_glow;

	/* 2 more objects should go here I belive... */

    cocos2d::CCSprite *field101_0x294;
    std::string m_claimParitcle;
 

    cocos2d::CCPoint *field107_0x2a0;


    bool field134_0x2be;

    bool m_objectRectDirty; /* Created by retype action */
    bool m_orientedRectDirty; /* Created by retype action */
    bool m_isChild;

    int m_linkedGroup;

	bool m_hasChildren;
    cocos2d::CCSprite *m_colorSprite;


    int m_unqiueID;
    GameObjectType m_objectType; /* Created by retype action */


    double m_realPositionX;
    double m_realPositionY;
    cocos2d::CCPoint *m_startPos;
    cocos2d::CCPoint *m_startPosition;

    bool m_hasNoAudioScale;

    float field222_0x33c;


    float m_currentScaleX;
    float m_currentScaleY;

    float field233_0x350;


    short field242_0x35c;

	/* Two more unknown short objects go here maybe? */

    short m_enterChannel;
    short m_objectMaterial;

    bool m_hasNoGlow;
    int m_targetColor;
    int m_objectID;


    short field267_0x380;
    bool m_isDontEnter; /* Created by retype action */
    bool m_isDontFade; /* Created by retype action */
    bool m_hasNoEffects;
    bool m_hasNoParticles;

    int m_unkZOrder;

    bool m_show;

    bool field287_0x398;
    int m_property53;


    float m_slopeDirection;


    GJSpriteColor *m_mainColor;
    GJSpriteColor *m_detailColor;

    int m_unkZLayer;

    int m_customZLayer;
    int m_zOrder;

    bool m_isSelected;


    bool m_hasGroupParent;
    bool m_hasAreaParent;
    float m_scaleX;
    float m_scaleY;

    std::array<short, 10>* m_groupContainer;
    short m_groupsCount;

    std::array<short, 10>* m_colorGroupContainer;
    short m_colorGroupCount;

    std::array<short, 10>m_opacityGroupContainer;
    short m_opacityGroupCount;
    short m_editorLayer;
    short m_editorLayer2;
    int field359_0x40c;


    bool m_isNoTouch;


    cocos2d::CCPoint *m_lastPosition;


    bool m_isHighDetail;


    GJEffectManager *m_effectManager;


    bool m_isPassable;
    bool m_isHide;
    bool m_isNonStickX;
    bool m_isNonStickY;
    bool m_isIceBlock;
    bool m_isGripSlope;
    bool m_isScaleStick;
    bool m_isExtraSticky;
    bool m_isDontBoostY;
    bool m_isDontBoostX;


    int m_ordValue;
    int m_property156;
	// bool m_bUnk3;
	// bool m_bIsBlueMaybe;
	// float m_fUnk2;
	// float m_fUnk;
	// float m_fUnk3;
	// float m_fUnk4;
	// bool m_bUnk;
	// float m_fAnimSpeed2;
	// bool m_bIsEffectObject;
	// bool m_bRandomisedAnimStart;
	// float m_fAnimSpeed;
	// bool m_bBlackChild;
	// bool m_bUnkOutlineMaybe;
	// float m_fBlackChildOpacity;
	// bool field_21C;
	// bool m_bEditor;
	// bool m_bGroupDisabled;
	// bool m_bColourOnTop;
	// // GJSpriteColor* m_pMainColourMode;
	// // GJSpriteColor* m_pSecondaryColourMode;
	// bool m_bCol1;
	// bool m_bCol2;
	// cocos2d::CCSize m_obPos;
	// float m_fUnkRotationField;
	// bool m_bTintTrigger;
	// bool m_bIsFlipX;
	// bool m_bIsFlipY;
	// cocos2d::CCPoint m_obBoxOffset;
	// bool m_bIsOriented;
	// cocos2d::CCPoint m_obBoxOffset2;
	// OBB2D* m_pObjectOBB2D;
	// bool m_bOriented;
	// cocos2d::CCSprite* m_pGlowSprite;
	// bool m_bNotEditor;
	// cocos2d::CCAction* m_pAction;
	// bool m_bUnk1;
	// bool m_bRunActionWithTag;
	// bool m_bObjectPoweredOn;
	// cocos2d::CCSize m_obObjectSize;
	// bool m_bTrigger;
	// bool m_bActive;
	// bool m_bAnimationFinished;
	// cocos2d::CCParticleSystemQuad* m_pParticleSystem;
	// std::string m_sEffectPlistName;
	// bool m_bParticleAdded;
	// bool m_bHasParticles;
	// bool m_bUnkCustomRing;
	// cocos2d::CCPoint m_obPortalPosition;
	// bool m_bUnkParticleSystem;
	// cocos2d::CCRect m_obObjectTextureRect;
	// bool m_bTextureRectDirty;
	// float m_fRectXCenterMaybe;
	// cocos2d::CCRect m_obObjectRect2;
	// bool m_bIsObjectRectDirty;
	// bool m_bIsOrientedRectDirty;
	// bool m_bHasBeenActivated;
	// bool m_bHasBeenActivatedP2;
	// BYTE PAD2[8];
	// bool m_bObjectRectDirty;
	// bool m_bOrientedRectDirty;
	// bool m_bUniqueActivated;
	// bool m_bActivated;
	// bool m_bCollectable;
	// bool m_bPulseToBPM;
	// bool m_bCanRotateFree;
	// int m_nLinkedGroupID;
	// bool m_bRotationTrigger;
	// int m_nCustomRotationSpeed;
	// bool m_bDisableRotation;
	// bool m_bIsMainColBlack;
	// bool field_2CA;
	// bool m_bBlending;
	// bool m_bBlending2;
	// bool m_bUnk2;
	// bool field_2CE;
	// cocos2d::CCSprite* m_pColourSprite;
	// bool m_bIgnoreScreenCheck;
	// float m_fRadius;
	// bool m_bSnappedRotation;
	// cocos2d::CCSize m_obScaleMod;
	// int m_nUniqueID;
	// // GameObjectType m_eGameObjectType;
	// int m_nSectionIdx;
	// bool m_bTouchTriggered;
	// bool m_bSpawnTriggered;
	// cocos2d::CCPoint m_obStartPos;
	// std::string m_sTextureFrameName;
	// bool m_bUseAudioScale;
	// bool m_bSleeping;
	// float m_fRotation;
	// cocos2d::CCSize m_obStartScale;
	// bool m_bStartFlipX;
	// bool m_bStartFlipY;
	// bool m_bShouldHide;
	// float m_fSpawnXPosition;
	// bool m_bInvisible;
	// float m_fEnterAngle;
	// int m_eActiveEnterEffect;
	// int m_nParentMode;
	// bool m_bDisableGlow;
	// int m_nColourIdx;
	// float m_fScale;
	// int m_nObjectID;
	// bool m_bDontTransform;
	// bool m_bDefaultDontFade;
	// bool m_bIgnoreEnter;
	// bool m_bIgnoreFade;
	// bool m_bDontFadeTinted;
	// bool m_bTintObject;
	// bool m_bDetailColourObject;
	// bool m_bDontEnter;
	// bool m_bDontFade;
	// bool m_bStateVar;
	// int m_nDefaultZOrder;
	// bool m_bPortal;
	// bool m_bLockColourAsChild;
	// bool m_bCustomAudioScale;
	// int m_fMinAudioScale;
	// int m_fMaxAudioScale;
	// bool m_bUnkParticleSystem2;
	// int m_nSecretCoinID;
	// int m_unkUnusedSaveStringKey53;
	// bool m_bInvisibleMode;
	// bool m_bGlowUserBackgroundColour;
	// bool m_bUseSpecialLight;
	// bool m_bOrbOrPad;
	// float m_fGlowOpacityMod;
	// bool m_bUpSlope;
	// int m_eSlopeType;
	// float m_fSlopeAngle;
	// bool m_bHazardousSlope;
	// float dword18C;
	// // GJSpriteColor* m_pColour1;
	// // GJSpriteColor* m_pColour2;
	// bool m_bBlendingBatchNode;
	// int m_nDefaultZLayer;
	// int m_nZLayer;
	// int m_nZOrder;
	// std::string m_sText;
	// bool m_bSpecialObject;
	// bool m_bObjectSelected2;
	// bool m_bObjectSelected;
	// int m_nGlobalClickCounter;
	// cocos2d::CCPoint m_obUnk2;
	// bool dword1BC;
	// bool field_3AD;
	// float m_fMultiScaleMultiplier;
	// std::vector<short> m_nGroupContainer;
	// int m_nGroupCount;
	// std::vector<short> m_nColourGroupContainer;
	// int m_nColourGroupCount;
	// std::vector<short> m_nOpacityGroupContainer;
	// int m_nOpacityGroupCount;
	// int m_nEditorLayer1;
	// int m_nEditorLayer2;
	// int m_nGroupDisabled;
	// bool dword1EC;
	// bool m_bUseCustomContentSize;
	// bool field_3DE;
	// cocos2d::CCSize m_obUnkSize;
	// cocos2d::CCPoint m_obLastPosition;
	// bool m_bDidUpdateLastPosition;
	// bool m_bUpdateLastPos;
	// BYTE PAD3[4];
	// bool m_bSyncedAnimation;
	// int m_eLavaBubbleColourID;
	// bool dword210;
	// bool field_401;
	// bool field_402;
	// bool field_403;
	// bool dword214;
	// bool m_bSpawnObject;
	// bool m_bHasObjectCount;
	// int m_nAnimFrame;
	// bool m_bHighDetail;
	// void* m_pMainColourSprite;
	// void* m_pSecondaryColourSprite;
	// GJEffectManager* m_pEffectManager;
	// bool dword22C;
	// bool m_bIsDecoration;
	// bool m_bOptimisedGroup;
	// bool field_41F;
	// bool dword230;
	// int m_eZagColour;
	// bool m_bMultiActivate;
	// cocos2d::_ccColor3B m_Colour;
};

#endif // GAMEOBJECT_H

#endif // __GAMEOBJECT_H__
