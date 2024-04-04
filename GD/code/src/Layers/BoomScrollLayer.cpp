#include <ctime>
#include "includes.h"

#ifdef WIN32
    #define clock_gettime(base, spec) timespec_get(spec, base)
#endif


void BoomScrollLayer::addPage(CCLayer *layer,int pageNum)
{
    unsigned int pageCount;

    if (pageNum > m_pages->count()) {
        pageNum = m_pages->count();
    }
    m_pages->insertObject(layer, pageNum & ~(pageNum >> 0x1f));
    updatePages();
    moveToPage(m_currentPage);
}

void BoomScrollLayer::addPage(CCLayer *layer)
{
    addPage(layer, m_pages->count());
}

void BoomScrollLayer::cancelAndStoleTouch(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    cocos2d::CCSet *set = new cocos2d::CCSet();
    set->addObject(touch);
    set->autorelease();
    m_cancellingTouch = true;
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->touchesCancelled(set, event);
    m_cancellingTouch = false;
    claimTouch(touch);
}


bool BoomScrollLayer::ccTouchBegan(cocos2d::CCTouch *touch,cocos2d::CCEvent *event )
{
    if (m_rect.containsPoint(cocos2d::CCDirector::sharedDirector()->convertToGL(touch->getLocationInView()))) {
        if (this->m_touch == nullptr) {
            this->m_touch = touch;
            /* there's a few unknown feilds I am leaving out due to how unkown they are... */
            /* I would assume it's this on windows?... */
            timespec* spec;
            
            this->m_time = spec->tv_sec + spec->tv_nsec / 1000000000.0;
        }
        else {
          return false;
        }
    }
    return true;
}

void BoomScrollLayer::ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    if ((this->m_cancellingTouch == false) && (this->m_touch == touch)) {
        this->m_touch = nullptr;
        selectPage(m_currentPage);
    }
}

void __thiscall BoomScrollLayer::claimTouch(cocos2d::CCTouch *touch)
{
    auto touchdispatcher = cocos2d::CCDirector::sharedDirector()->getTouchDispatcher();
    auto handler = reinterpret_cast<cocos2d::CCTargetedTouchHandler*>(touchdispatcher->findHandler(this));
    auto claimedTouches = handler->getClaimedTouches();
    if (!claimedTouches->containsObject(touch)) {
        claimedTouches->addObject(touch);
    }   
}

/* TODO: */
/* BoomScrollLayer::create(cocos2d::CCArray*, int, bool, cocos2d::CCArray*, DynamicScrollDelegate*) */

/* Had a Theory Robtop was using a macro here 
 * so that is what I will do for these sections of code... */
#define BoomScrollLayer_GETPAGENUM(pageNum, count) \
    if (pageNum < 1){\
        for (; pageNum < 0; pageNum += count){} \
    } else {\
        pageNum = pageNum % count; \
    }


cocos2d::CCLayer * BoomScrollLayer::getPage(int pageNum)
{
    /* update signal perhaps? */
    if (m_unkBool) {
        BoomScrollLayer_GETPAGENUM(pageNum, m_pages->count());
    }
    /* it should be this because I wouldn't expect robtop to reinterpret_case<> 
     * all of these if this is not true I would vomit. */
    return reinterpret_cast<CCLayer *>(m_pages->objectAtIndex(pageNum));
}

int BoomScrollLayer::getRelativePageForNum(int pageNum)
{
    unsigned int total = getTotalPages();
    BoomScrollLayer_GETPAGENUM(pageNum, m_pages->count());
    return pageNum;
}

cocos2d::CCPoint BoomScrollLayer::getRelativePosForPage(int page)
{
    return CCPointMake(page * (getContentSize().width - m_width), 0.0);
}

unsigned int BoomScrollLayer::getTotalPages()
{
    return (!m_unkBool) ? m_pages->count() : m_pages2->count();
}


