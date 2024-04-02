#include "includes.h"

CCCircleWave * CCCircleWave::create(    
        float startRadius,
        float endRadius,
        float duration,
        bool scaleMode,
        bool easeMode)
{
    CCCircleWave *obj = new CCCircleWave;
    if (obj != nullptr && obj->init(startRadius, endRadius, duration,scaleMode, easeMode))
    {
        obj->autorelease();
        return obj;
    }
    CC_SAFE_DELETE(obj);
    return nullptr;
}

/* Ghidra's implementation is kept because of how much of a cornmaze this function is... */

void CCCircleWave::draw() {
    unsigned int opacity;
    float rform;
    int i;

    if (m_blendAdditive != false) {
        cocos2d::ccGLBlendFunc(2, 1);
    }

    if (m_opacityMod != 0) {
        glLineWidth(m_lineWidth);
    }

    rform = m_radius * m_opacity;
    if (rform == 0.0 || rform < 0.0 != rform) {
        opacity = 0x00;
    }
    else if (-1 < (rform < 255.0) << 0x1f)
    {
        opacity = 0xff;
    } else {
        opacity = static_cast<unsigned int>((0 < rform * rform & 0xff));
    }
    cocos2d::ccDrawColor4B(m_color.r, m_color.g, m_color.b, opacity);
    
    rform = m_radius;
    if (((rform < 10.0) << 0x1f) < 0) {
        opacity = 10;
    }
    else if (((rform < 20.0) << 0x1f) < 0) {
        opacity = 0xf;
    }
    else if (((rform < 40.0) << 0x1f) < 0) {
        opacity = 0x14;
    }
    else {
        i = (rform < 200.0) << 0x1f;
        if (i < 0) {
            opacity = 0x1e;
        }
        if (-1 < i) {
            opacity = 0x32;
        }
    }
    if (m_opacityMod == 0) {
        // Likely Robtop added so it's commented out otherwise my Intellisense complains that I don't have it...
        /* TODO: fork cocos headers */
        // cocos2d::ccDrawFilledCircle(m_position, rform, 0.0, opacity);
    }
    else {
        cocos2d::ccDrawCircle(m_position, rform, 0.0, opacity, false);
    }
    if (m_blendAdditive)
    {
        cocos2d::ccGLBlendFunc(1, 3);
    }
}


void CCCircleWave::followObject(cocos2d::CCNode* target, bool noFollow)
{
    if (m_target != nullptr) {
        m_target->release();
    }
    m_target = target;
    m_target->retain();
    unschedule(static_cast<cocos2d::SEL_SCHEDULE>(updatePosition));
    if (!noFollow) {
        schedule(static_cast<cocos2d::SEL_SCHEDULE>(updatePosition));
    }
    setPosition(m_target->getPosition());
}



bool  CCCircleWave::init( 
    float startRadius, 
    float endRadius,
    float duration, 
    bool scaleMode, 
    bool easeMode
)
{

    baseSetup(startRadius);
    if (scaleMode) {
        m_radius = 0.0;
        cocos2d::CCDirector::sharedDirector()->getActionManager()->addAction(
            /* pAction */
            cocos2d::CCSpawn::create(
                cocos2d::CCActionTween::create(duration,"radius", m_radius, endRadius), 
                cocos2d::CCSequence::create(
                    cocos2d::CCActionTween::create(duration * 0.5f,"opacity", m_radius, 255.0f),  
                    cocos2d::CCActionTween::create(duration * 0.5f,"opacity",255.0f, 0.0f), 
                    cocos2d::CCCallFunc::create(this, /* (_func_void_CCObject_ptr *)0x104 Unknown*/ nullptr ), 
                    nullptr
                ), 
                nullptr
            ), 
            /* pTarget */
            this, 
            /* Paused */
            false
        );
    }
    else {
        cocos2d::CCSequence *seq;
        auto interval = cocos2d::CCActionTween::create(duration,"radius", m_radius, endRadius);
        auto interval2 = cocos2d::CCActionTween::create(duration,"opacity", m_radius, 0.0);
        if (easeMode){
            seq = cocos2d::CCSequence::create(
                cocos2d::CCSpawn::create(
                    cocos2d::CCEaseOut::create(interval, 0x40000000), 
                    cocos2d::CCEaseOut::create(interval2, 0x40000000), 
                    nullptr
                ), 
                cocos2d::CCCallFunc::create(this, /* (_func_void_CCObject_ptr *)0x104 Unknown*/ nullptr ), 
                nullptr 
            );
        } else {
            seq = cocos2d::CCSequence::create(
                cocos2d::CCSpawn::create(interval,interval2,0), 
                cocos2d::CCCallFunc::create(this, /* (_func_void_CCObject_ptr *)0x104 Unknown*/ nullptr ), 
                nullptr
            );
        }
        cocos2d::CCDirector::sharedDirector()->getActionManager()->addAction(seq, this, false);
    }
    return true;
}


void CCCircleWave::removeMeAndCleanup() {
    if (m_delegate != nullptr) {
        return m_delegate->circleWaveWillBeRemoved(this);
    }
}

void CCCircleWave::setPosition(cocos2d::CCPoint const& position)
{
    m_position = position;
}



void CCCircleWave::updatePosition(float delta) {
    /* TODO: fix to include the delta variable somewhere... */
    if (m_target != nullptr) {
        setPosition(m_target->getPosition());
    }
}

void CCCircleWave::updateTweenAction(float value, const char *key)
{
    if (std::string(key) == "opacity") {
        this->m_opacity = value;
    }
    else if (std::string(key) == "radius") {
        this->m_radius = value;
    }
    if (this->m_target != nullptr) {
        setPosition(m_target->getPosition());
    }
}


/* TODO "CCAlertCircle" Currently stuck SEE: CCCircle.h for more info... */
