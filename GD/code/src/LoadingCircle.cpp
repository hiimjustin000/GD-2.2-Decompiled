#include <includes.h>

LoadingCircle *LoadingCircle::create()
{
    LoadingCircle *dis = new LoadingCircle();
    dis->m_sprite = nullptr;
    dis->m_unkInt = 0;
    dis->m_needsRendering = false;
    if (dis->init())
    {
        dis->autorelease();
        return dis;
    }
    CC_SAFE_DELETE(dis);
    return nullptr;
}

bool LoadingCircle::init()
{
    if (initWithColor(0.0))
    {
        m_sprite = cocos2d::CCSprite::create("loadingCircle.png");
        /* I think this works? */
        auto nextpos = cocos2d::CCDirector::sharedDirector()->getWinSize();
        m_sprite->setPosition(cocos2d::CCPoint(nextpos.width, nextpos.height));
        // m_sprite->setBlendFunc(0x302, 1);
        addChild(m_sprite);
    }
    return true;
}

void LoadingCircle::draw()
{
    /* It had to be written this way otherwise we would be caught in a dead-loop */
    if (m_needsRendering)
        cocos2d::CCLayerColor::draw();
}

void LoadingCircle::fadeAndRemove()
{
    m_sprite->stopActionByTag(0);
    m_sprite->runAction(cocos2d::CCSequence::create(cocos2d::CCFadeTo::create(0x3e99999a, nullptr), cocos2d::CCCallFunc::create(this, (_func_void_CCObject_ptr *)0x104 /*Unknown Call...*/), 0));
    if (m_needsRendering)
    {
        stopActionByTag(1);
        runAction(cocos2d::CCFadeTo::create(0x3e99999a, 0));
    }
}

void LoadingCircle::registerWithTouchDispatcher()
{
    cocos2d::CCTouchDispatcher::addTargetedDelegate(cocos2d::CCDirector::sharedDirector()->getKeypadDispatcher(), m_touchDelegate, -0x7fffffff /* <<<- Robtop Why? */, true);
}


void LoadingCircle::show(LoadingCircle *this)
{
    /* Unknown Part */
    //   pCVar1 = cocos2d::CCDirector::sharedDirector();
    //   pCVar2 = pCVar1->field201_0xcc;
    //   if (*(CCDirector_vtable **)&this->field_0x1bc != (CCDirector_vtable *)0x0) {
    //     pCVar2 = *(CCDirector_vtable **)&this->field_0x1bc;
    //   }
    //   (**(code **)(pCVar2->copyWithZone + 0xe0))(pCVar2,this,0x69);
    cocos2d::CCFadeTo *fadeTo;
    if (m_rendered != false)
    {
        setOpacity(0);
        fadeTo = cocos2d::CCFadeTo::create(0x3ecccccd, /* (CCActionInterval)0x96 Unknown */ nullptr);
        fadeTo->getTag(fadeTo, 1);
        runAction(fadeTo);
    }
    m_sprite->runAction(cocos2d::CCRepeatForever::create(cocos2d::CCRotateBy::create(0x3f800000.f, 0x43b40000.f)));
    m_sprite->setOpacity(0);
    fadeTo = cocos2d::CCFadeTo::create(0x3ecccccd, /* (CCActionInterval)0xc8 Unknown*/ nullptr);
    fadeTo->getTag(0);
    m_sprite->runAction(fadeTo);
}
