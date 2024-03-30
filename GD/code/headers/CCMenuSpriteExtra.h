#ifndef __CCMENUSPRITEEXTRA_H__
#define __CCMENUSPRITEEXTRA_H__

#include "includes.h"


enum class MenuAnimationType{
    Scale,
};


// vim: set syntax=cpp:

/* Header data was provided by Acaruso */

/// @brief Menu item sprite with custom animation.
class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite {
public:
    ~CCMenuItemSpriteExtra() {}
    
    CCMenuItemSpriteExtra() {
        m_animationEnabled = false;
        m_colorEnabled = false;
        m_clickSound = "";
        m_selectSound = "";
        m_baseScale = 0.0f;
        m_colorDip = (200.0f / 255.0f);
        m_scaleMultiplier = 1.0f;
        m_volume = 1.0f;
        m_destPosition = cocos2d::CCPoint();
        m_selectAnimDuration = 0.3f;
        m_unselectAnimDuration = 0.4f;
        m_animationType = MenuAnimationType::Scale;
        m_startPosition = cocos2d::CCPoint();
        m_unknown4 = 0;
    }

    /// @brief Create menu item sprite.
    /// @param normalSprite Normal sprite.
    /// @param selectedSprite Selected sprite.
    /// @param target Target for selector.
    /// @param selector Selector.
    /// @return Menu item sprite.
    static CCMenuItemSpriteExtra* create(
        cocos2d::CCNode* normalSprite,
        cocos2d::CCNode* selectedSprite,
        cocos2d::CCObject* target,
        cocos2d::SEL_MenuHandler selector
    );

    /// @brief Create menu item sprite.
    /// @details Geode addition.
    /// @param normalSprite Normal sprite.
    /// @param target Target for selector.
    /// @param selector Selector.
    /// @return Menu item sprite.
    static CCMenuItemSpriteExtra* create(
        cocos2d::CCNode* normalSprite,
        cocos2d::CCObject* target,
        cocos2d::SEL_MenuHandler selector
    );
    // {
    //     return CCMenuItemSpriteExtra::create(normalSprite, nullptr, target, selector);
    // };



    /// @brief Initialize menu item sprite.
    /// @param normalSprite Normal sprite.
    /// @param selectedSprite Selected sprite.
    /// @param target Target for selector.
    /// @param selector Selector.
    /// @return Whether the initialization was successful.
    bool init(
        cocos2d::CCNode* normalSprite,
        cocos2d::CCNode* selectedSprite,
        cocos2d::CCObject* target,
        cocos2d::SEL_MenuHandler selector
    );

    /// @brief Trivial setter for m_fSizeMult.
    /// @details Inlined on windows.
    void setSizeMult(float var) {
        m_fSizeMult = var;
    }

    /// @brief Set animation type to use.
    /// @details Inlined on Windows.
    /// @param animationType Animation type.
    void useAnimationType(MenuAnimationType animationType) {
        m_startPosition = getNormalImage()->getPosition();
        m_animationType = animationType;
    }

    virtual void activate();
    virtual void selected();
    virtual void unselected();

    float getScaleVar() const { return m_scaleMultiplier; }
    void setScaleVar(float var) { m_scaleMultiplier = var; }

    float getOriginalScale() const { return m_baseScale; }
    void setOriginalScale(float var) { m_baseScale = var; }

    bool getShouldAnimate() const { return m_animationEnabled; }
    void setShouldAnimate(bool var) { m_animationEnabled = var; }

    bool getDarkenClick() const { return m_colorEnabled; }
    void setDarkenClick(bool var) { m_colorEnabled = var; }

    float getVolume() const { return m_volume; }
    void setVolume(float var) { m_volume = var; }

    std::string getClickSound() const { return m_clickSound; }
    void setClickSound(std::string var) { m_clickSound = var; }


	float m_fSizeMult; // 0x128


    float m_scaleMultiplier; ///< RT: m_scaleVar
    float m_baseScale; ///< RT: m_originalScale
    bool m_animationEnabled; ///< RT: m_shouldAnimate
    bool m_colorEnabled; ///< RT: m_darkenClick
    float m_volume;
    std::string m_clickSound;
    std::string m_selectSound;
    float m_colorDip;
    cocos2d::CCPoint m_destPosition; ///< Unused?
    float m_selectAnimDuration;
    float m_unselectAnimDuration;
    MenuAnimationType m_animationType;
    cocos2d::CCPoint m_startPosition;
    int m_unknown4; ///< Unused?
};





#endif // __CCMENUSPRITEEXTRA_H__