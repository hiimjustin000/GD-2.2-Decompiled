#ifndef __CCCIRCLEWAVE_H__
#define __CCCIRCLEWAVE_H__

#include "includes.h"

/* Multiple things will be place into this file due to how small the circles are... */


enum CircleMode{
    kCircleModeUnknown = 0,
};


class CCCircleWaveDelegate {
    public: 
        virtual void circleWaveWillBeRemoved(CCCircleWave* cw){};
};

/* Documented and provided to me by Acuroso 
 * Some additional information / smaller 
 * portions of documentation was povided by me */


/// @brief Circle wave effect used in various places in the game.
class CCCircleWave : public cocos2d::CCNode {
public:

    ~CCCircleWave() {
        CC_SAFE_RELEASE(m_target);
    }
    
    CCCircleWave() {
        m_target = nullptr;
        m_width = 0.0f;
        m_radius = 0.0f;
        m_opacity = 0.0f;
        m_position = cocos2d::CCPoint();
        m_circleMode = static_cast<CircleMode>(0);
        m_lineWidth = 0;
        m_opacityMod = 0.0f;
        m_blendAdditive = false;
        m_delegate = nullptr;
    }

    /// @brief Create circle wave.
    /// @param startRadius Circle start radius.
    /// @param endRadius Circle end radius.
    /// @param duration Effect duration.
    /// @param scaleMode Scale animation mode.
    /// @param easeMode Easing animation mode.
    /// @return Circle wave.
    static CCCircleWave* create(
        float startRadius,
        float endRadius,
        float duration,
        bool scaleMode,
        bool easeMode
    );

    /// @brief Create circle wave. Easing animaton mode is set to `true`.
    /// @details Inlined on Windows.
    /// @param startRadius Circle start radius.
    /// @param endRadius Circle end radius.
    /// @param duration Effect duration.
    /// @param scaleMode Scale animation mode.
    /// @return Circle wave.
    static CCCircleWave* create(
        float startRadius,
        float endRadius,
        float duration,
        bool scaleMode
    ) {
        return create(startRadius, endRadius, duration, scaleMode, true);
    }

    /// @brief Set default values.
    /// @details Private method. Inlined on Windows.
    /// @param radius Circle start radius.
    void baseSetup(float radius) {
        m_radius = radius;
        m_opacity = 255.0f;
        m_opacityMod = 1.0f;
        m_color = cocos2d::ccWHITE;
        m_circleMode = static_cast<CircleMode>(0);
        m_target = nullptr;
        m_lineWidth = 2;
        m_blendAdditive = true;
    }

    /// @brief Move to or follow a target object.
    /// @param target Target object.
    /// @param noFollow Update position once only. Do not follow.
    void followObject(cocos2d::CCNode* target, bool noFollow);

    /// @brief Initialize circle wave.
    /// @param startRadius Circle start radius.
    /// @param endRadius Circle end radius.
    /// @param duration Effect duration.
    /// @param scaleMode Scale animation mode.
    /// @param easeMode Easing animation mode.
    /// @return Whether the initialization was successful.
    bool init(
        float startRadius,
        float endRadius,
        float duration,
        bool scaleMode,
        bool easeMode
    );

    /// @brief Update the effect's position.
    /// @param delta Delta time.
    void updatePosition(float delta);

    /// @brief sets a new position
    /// @param position sets the position of m_position 
    virtual void setPosition(cocos2d::CCPoint const& position);

    /// @brief Determines if CCCirclewave Needs Removal...
    virtual void removeMeAndCleanup();
    
    /// @brief Renders CircleWave
    virtual void draw();

    /// @brief Updates the Tween Action and sets the position of itself if a target for it exists 
    /// @param value 
    /// @param key Either opacity or radius can be 
    /// chosen and it will set either the opacity or raidius depending on what is chosen
    virtual void updateTweenAction(float value, char const* key);

    float getWidth() const { return m_width; }
    void setWidth(float var) { m_width = var; }

    float getRadius() const { return m_radius; }
    void setRadius(float var) { m_radius = var; }

    float getOpacity() const { return m_opacity; }
    void setOpacity(float var) { m_opacity = var; }

    cocos2d::ccColor3B getColor() const { return m_color; }
    void setColor(cocos2d::ccColor3B var) { m_color = var; }

    CircleMode getCircleMode() const { return m_circleMode; }
    void setCircleMode(CircleMode var) { m_circleMode = var; }

    int getLineWidth() const { return m_lineWidth; }
    void setLineWidth(int var) { m_lineWidth = var; }

    float getOpacityMod() const { return m_opacityMod; }
    void setOpacityMod(float var) { m_opacityMod = var; }

    bool getBlendAdditive() const { return m_blendAdditive; }
    void setBlendAdditive(bool var) { m_blendAdditive = var; }

    /// @brief Obtains the CCCircleWaveDelegate 
    /// @return Returns the Obtained delegate
    CCCircleWaveDelegate* getDelegate() const { return m_delegate; }
    void setDelegate(CCCircleWaveDelegate* delegate) { m_delegate = delegate; }

    cocos2d::CCNode* m_target;
    float m_width;
    float m_radius;
    float m_opacity;
    cocos2d::ccColor3B m_color;
    cocos2d::CCPoint m_position;
    CircleMode m_circleMode;
    int m_lineWidth;
    float m_opacityMod;
    bool m_blendAdditive;
    CCCircleWaveDelegate* m_delegate;
};


// class CCCircleWave : public cocos2d::CCNode {
// public:
//     CCCircleWave();

// 	static CCCircleWave* create(float form, float to, float duration, bool enableSequence, bool easeOut);
// 	static CCCircleWave* create(float form, float to, float duration, bool enableSequence);

// 	void baseSetup(float rform);
// 	void followObject(CCNode *sprite, bool dontSchedule);
// 	bool init(float form,float to,float duration, bool enableSequence, bool easeOut);
// 	void updatePosition(float);

// 	virtual void setPosition(cocos2d::CCPoint const& pos);
// 	virtual void removeMeAndCleanup();
// 	virtual void draw();
// 	virtual void updateTweenAction(float, char const*);


//     cocos2d::CCNode *m_followObject;
    
//     /* pad of 0x4 */

//     float m_rForm;
//     float m_oForm;
//     cocos2d::ccColor3B m_color;
//     cocos2d::CCPoint m_position;
//     int m_filled;
//     int m_lineWidth;
//     float m_unkFloat;
//     bool m_blendFunc;

//     /* 3 unknown fields or just padding... */

//     CCCircleWaveDelegate *m_delegate;

// };



/* Currently stuck... Contact me on discord at .calloc if you know how to fix 
 * "Low-level Error: Field field272_0x130 does not fit in structure CCCircleAlert"
 */
class CCCircleAlert : public CCCircleWave {
public:
	static CCCircleAlert* create(float, float, float);

	bool init(float, float, float);
};


#endif // __CCCIRCLEWAVE_H__