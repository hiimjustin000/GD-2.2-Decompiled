#include "includes.h"


CCContentLayer * CCContentLayer::create(cocos2d::ccColor4B const&color, float _width,float _height){
    auto contentLayer = new CCContentLayer;
    if (contentLayer != nullptr && contentLayer->initWithColor(color, _width, _height)) {
        contentLayer->autorelease();
        return contentLayer;
    }
    CC_SAFE_DELETE(contentLayer);
    return nullptr;
}



CCScrollLayerExt::CCScrollLayerExt(cocos2d::CCRect rect){
    m_touchPosition = cocos2d::CCPointZero;
    m_touchStartPosition = cocos2d::CCPointZero;
    m_cutContent = true;
    m_disableMovement = false;
    setTouchEnabled(true);
    m_disableVertical = false;
    m_disableHorizontal = false;
    setContentSize(rect.size);
    setPosition(rect.origin);
    m_vScrollbarVisible = false;
    // Unknown...
    // *(undefined4 *)&m_AlreadyVisited = 0x42480000;
    // *(undefined4 *)((int)&this[1].vtable + 3) = 0x42480000;

    m_hScrollbarVisible = false;
    m_delegate = nullptr;
    m_scrollLimitBottom = 0.0;
    m_scrollLimitTop = 0.0;
    m_touch = nullptr;
    // Dear Robtop Why do this a second time?
    m_touchPosition = cocos2d::CCPointZero;
    m_touchStartPosition = cocos2d::CCPointZero;
    m_touchDown = false;
    m_notAtEndOfScroll = false;
    
    m_contentLayer = CCContentLayer::create({0x80, 0x80, 0x80, 0}, rect.size.width, 0.0);
    m_contentLayer->setAnchorPoint(cocos2d::CCPointZero);
    addChild(m_contentLayer);

    m_verticalScrollbar = nullptr;

    auto size = CCSizeMake(4.0f, (rect.size.height * rect.size.height) / m_contentLayer->getContentSize().height);
    m_verticalScrollbar = cocos2d::CCLayerColor::create({50, 50, 50, 180}, size.width, size.height);
    m_verticalScrollbar->setPosition(
        CCPointMake(
            getContentSize().width - size.height * 0.5, 
            getContentSize().height - size.height * 0.5
        )
    );

    m_verticalScrollbar->setVisible(true);
    auto horSize = CCSizeMake(rect.size.width * rect.size.width / m_contentLayer->getContentSize().width, 4.0);
    m_horizontalScrollbar = cocos2d::CCLayerColor::create({50, 50, 50, 180}, horSize.width, horSize.height);
    m_horizontalScrollbar->setPosition(CCPointMake(horSize.width * 0.5,horSize.height * 0.5));
    m_horizontalScrollbar->setTouchEnabled(false);
    addChild(m_horizontalScrollbar);
    schedule(static_cast<cocos2d::SEL_SCHEDULE>(updateIndicators), 0);
}


bool CCScrollLayerExt::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    bool movement;
    cocos2d::CCRect rect;
    if (m_disableMovement == false) {
        m_touch = touch;
        auto touchLoc = m_touch->getLocationInView();
        m_touchPosition = convertToNodeSpace(cocos2d::CCDirector::sharedDirector()->convertToGL(touchLoc));
        rect.origin = cocos2d::CCPointZero;
        rect.size = getContentSize();
        if (rect.containsPoint(touchLoc)) {
            m_contentLayer->stopAllActions();
            cocos2d::CCTime::gettimeofdayCocos2d(&m_timeValue, nullptr);
            m_touchDown = true;
            movement = m_disableMovement ^ true;
        }
        return movement;
    }
    return false;
}

void CCScrollLayerExt::ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    constraintContent();
    this->m_touchPosition = cocos2d::CCPointZero;
}


void CCScrollLayerExt::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    /* Incomplete due to lack of definitions */
    auto gl = cocos2d::CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
    if (touch == m_touch){
        cocos2d::CCTime::gettimeofdayCocos2d(&m_timeValue, nullptr);
        /* TODO: Fix cocosHeaders to include cppDistance */
        // cocos2d::cppDistance();
    }
}



float CCScrollLayerExt::getMaxY()
{
    return m_scrollLimitBottom;
}

float CCScrollLayerExt::getMinY()
{
    return (m_contentLayer->getContentSize().height < getContentSize().height ) ? m_contentLayer->getContentSize().height:  getContentSize().height;
}


void CCScrollLayerExt::postVisit(){
    glDisable(0xc11);
}

void CCScrollLayerExt::preVisitWithClippingRect(cocos2d::CCRect clippingRect){
    if (isVisible()) {
        postVisit();
        /* I think this is what it's referring to, Haven't made a vtable in ghidra for CCEGLView yet... */
        auto point = getParent()->convertToWorldSpace(getPosition());
        cocos2d::CCEGLView::sharedOpenGLView()->setScissorInPoints(
            point.x, point.y, clippingRect.size.width, clippingRect.size.height);
    }
}

void CCScrollLayerExt::registerWithTouchDispatcher()
{
  cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(nullptr /* Unknown Object in class at this->field_0x108... help in finding it would be deelpy apperciated */, -0x80,false);
}

void CCScrollLayerExt::scrollingEnd()
{
    this->m_contentLayer->stopAllActions();
    this->m_delegate->scrollViewWillBeginDecelerating(this);
    this->m_notAtEndOfScroll = false;
}
