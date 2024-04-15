#include "includes.h"


GJStoreItem * GJStoreItem::create(int listingID,int itemID,int itemType,int cost, ShopType shopType){
    GJStoreItem* item = new GJStoreItem;
    if (item != nullptr && item->init(listingID, itemID, itemType, cost, shopType)){
        item->autorelease();
        return item;
    }
    CC_SAFE_DELETE(item);
    return nullptr;
}


std::string GJStoreItem::getCurrencyKey()
{
    return (this->m_shopType == kShopTypeUnknown) ? "29": "14";
}


bool GJStoreItem::init(int listingID, int itemID, int itemType, int cost, ShopType shopType)
{
    /* I will Optimize this later... NOTE: Most of These should all be considered as inline functions */
    int i;
    if (cocos2d::CCNode::init()) {
        this->m_listingID = listingID;
        this->m_itemID = itemID;
        i = rand() * 4.656613e-10 * 1000.0;
        this->m_listingIDRand = i;
        this->m_listingIDSeed = i + listingID;
        this->m_itemType = itemType;
        i = rand() * 4.656613e-10 * 1000.0;
        this->m_itemIDRand = i;
        this->m_itemIDSeed = i + itemID;
        this->m_cost = cost;
        i = rand() * 4.656613e-10 * 1000.0;
        this->m_itemTypeRand = i;
        this->m_itemTypeSeed = i + itemType;
        i = rand() * 4.656613e-10 * 1000.0;
        this->m_costRand = i;
        this->m_costSeed = i + cost;
        this->m_shopType = shopType;
        return true;
    }
    return false;
}
