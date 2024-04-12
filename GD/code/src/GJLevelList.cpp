#include "includes.h"

/* Feel Free to reverse engineer any of the functions that I haven't added yet there puzzles I have chosen to ignore for right now - Calloc */

void GJLevelList::addLevelToList(GJGameLevel *level)
{
    while (level->m_levelID_Random - level->m_levelID_Seed) {
        if (m_completedLevels == m_levels) {
            m_completedLevels.emplace_back(level->m_levelID_Random - level->m_levelID_Seed);
            updateLevelsString();
            m_snapShots->setObject(level->getListSnapshot(), GameToolbox::intToString(level->m_levelID_Random - level->m_levelID_Seed));
            m_k47 = true;
            break;
        }
    }
}

bool GJLevelList::canEncode()
{
    return true;
}

int GJLevelList::completedLevels()
{
    int i = 0;
    while (m_levels != m_completedLevels) {
        // Commented out to prevent Intellisense from Screaming at me because we didn't do GameStatsManager yet... :/
        // if (GameStatsManager::sharedState()->hasCompletedOnlineLevel(m_levels[i])){
        //     i += 1;
        // }
    }
    return i;
}


GJLevelList* GJLevelList::create(){
    GJLevelList* list = new GJLevelList;
    if (list != nullptr && list->init()) {
       list->autorelease();
    }
    CC_SAFE_DELETE(list);
    return nullptr;
}


GJLevelList * GJLevelList::create(cocos2d::CCDictionary *dict)
{
    GJLevelList* list = create();
    list->m_listID = dict->valueForKey("1")->intValue();
    list->m_listName = dict->valueForKey("2")->getCString();
    list->m_listDesc = dict->valueForKey("3")->getCString();
    list->m_listVersion = dict->valueForKey("5")->intValue();
    list->m_accountID = dict->valueForKey("49")->intValue();
    list->m_creatorName = dict->valueForKey("50")->getCString();
    list->m_downloads = dict->valueForKey("10")->intValue();
    list->m_likes = dict->valueForKey("14")->intValue();
    list->m_difficulty = dict->valueForKey("7")->intValue();
    list->m_uploadDate = dict->valueForKey("28")->intValue();
    list->m_updateDate = dict->valueForKey("29")->intValue();
    list->m_diamonds = dict->valueForKey("55")->intValue();
    list->m_levelsToClaim = dict->valueForKey("56")->intValue();
    list->m_featured = dict->valueForKey("19")->boolValue();
    list->parseListLevels(dict->valueForKey("51")->getCString());
    return list;
}

GJLevelList * GJLevelList::createWithCoder(DS_Dictionary *dsdict)
{
    GJLevelList *list = create();
    list->dataLoaded(dsdict);
    return list;
}

void GJLevelList::dataLoaded(DS_Dictionary *dsdict)
{ 
    m_listID =  dsdict->getIntegerForKey("k1");
    m_folder = dsdict->getIntegerForKey("k84");
    m_listName = dsdict->getStringForKey("k2");
    m_listDesc = dsdict->getStringForKey("k3");
    m_creatorName = dsdict->getStringForKey("k5");
    m_accountID = dsdict->getIntegerForKey("k60");
    m_difficulty = dsdict->getIntegerForKey("k7");
    m_downloads = dsdict->getIntegerForKey("k11");
    m_friendsOnly = dsdict->getBoolForKey("k15");
    m_likes = dsdict->getIntegerForKey("k22");
    m_listType = dsdict->getIntegerForKey("k21");
    m_listVersion  = dsdict->getIntegerForKey("k16");
    m_unkBool = dsdict->getBoolForKey("k79");
    m_unlisted = dsdict->getBoolForKey("k94");
    m_listRevision = dsdict->getIntegerForKey("k46");
    m_k47 = dsdict->getBoolForKey("k47");
    m_listOrder = dsdict->getIntegerForKey("k83");
    m_uploaded = dsdict->getBoolForKey("k82");
    m_featured = dsdict->getBoolForKey("k27");
    m_uploadDate = dsdict->getIntegerForKey("k98");
    m_updateDate = dsdict->getIntegerForKey("k99");
    m_original = dsdict->getIntegerForKey("k42");
    m_k100 = dsdict->getBoolForKey("k100");
    m_diamonds = dsdict->getIntegerForKey("k113");
    m_levelsToClaim = dsdict->getIntegerForKey("k114");
    auto snapShots = dsdict->getDictForKey("k97", false);
    if (m_snapShots != snapShots) {
        if (snapShots != nullptr) {
            m_snapShots->retain();
    }
    if (m_snapShots != nullptr) {
        m_snapShots->release();
    }
    m_snapShots = snapShots;
    parseListLevels(dsdict->getStringForKey("k96"));
    }
}

/* member function "GJLevelList::duplicateListLevels" may not be redeclared outside its class C/C++(392) */
void GJLevelList::duplicateListLevels(GJLevelList *list){
	cocos2d::CCArray* _levels = list->getListLevelsArray(nullptr);
	for (unsigned int i = 0; i < _levels->count(); i++) {
	    addLevelToList(reinterpret_cast<GJGameLevel *>(_levels->objectAtIndex(i)));
	}
}

void GJLevelList::encodeWithCoder(DS_Dictionary *dsdict)
{   
    dsdict->setIntegerForKey("kCEK", 0xc);
    dsdict->setIntegerForKey("k1", m_listID);
    dsdict->setStringForKey("k2", m_listName);
    dsdict->setStringForKey("k3", m_listDesc);
    dsdict->setStringForKey("k5", m_creatorName);
    dsdict->setIntegerForKey("k60", m_accountID);
    dsdict->setIntegerForKey("k7", m_difficulty);
    dsdict->setIntegerForKey("k11", m_downloads);
    dsdict->setIntegerForKey("k15", m_friendsOnly);
    dsdict->setIntegerForKey("k22", m_likes);
    dsdict->setIntegerForKey("k21", m_listType);
    dsdict->setIntegerForKey("k16", m_listVersion);
    dsdict->setBoolForKey("k79", m_unkBool);
    dsdict->setBoolForKey("k94", m_unlisted);
    dsdict->setIntegerForKey("k46", m_listRevision);
    dsdict->setBoolForKey("k47", m_k47);
    dsdict->setIntegerForKey("k83", m_listOrder);
    dsdict->setStringForKey("k96", m_levelsString);
    dsdict->setBoolForKey("k82", m_uploaded);
    dsdict->setBoolForKey("k27", m_featured);
    dsdict->setIntegerForKey("k42", m_original);
    dsdict->setIntegerForKey("k98", m_uploadDate);
    dsdict->setIntegerForKey("k99", m_updateDate);
    dsdict->setIntegerForKey("k113", m_diamonds);
    dsdict->setIntegerForKey("k114", m_levelsToClaim);
    dsdict->setBoolForKey("k100", m_k100);
    dsdict->setDictForKey("k97", m_snapShots);
}


/* TODO: Solve this "goto" puzzle generated by ghidra. It's bullshit and I don't like it... */

std::string GJLevelList::frameForListDifficulty(int diff, DifficultyIconType type)
{
    char *imageFMT;
    DifficultyIconType _diff;
    if (diff == 0) {
        if (type == 2) {
            imageFMT = "diffIcon_auto_btn_001.png";
        }
        else {
          imageFMT = "difficulty_auto_btn_001.png";
        }
        return imageFMT;
    }
    if (diff < 0xb) {
        if (diff < 6) {
        B:
            if (type != 2) {
                if (diff < 6) goto C;
                goto D;
            }
        }
        else {
            if (diff < 8) {
                diff = diff + 1;
            }
            else {
                if (diff != 8) goto B;
                diff = 6;
            }
            if (type != 2) {
                D:
                    if (type != 1) goto C;
                        return cocos2d::CCString::createWithFormat("difficulty_%02d_btn2_001.png", diff)->getCString();
                    goto F;
            }
        }
    return cocos2d::CCString::createWithFormat("diffIcon_%02d_btn_001.png", diff)->getCString();
  }
  else {
    diff = 0;
    if (type == 2){ 
        return cocos2d::CCString::createWithFormat("diffIcon_%02d_btn_001.png", diff)->getCString();
    }
    C:
        return cocos2d::CCString::createWithFormat("difficulty_%02d_btn_001.png", diff)->getCString();
    }
F:
    return cocos2d::CCString::createWithFormat(imageFMT, diff)->getCString();
}

/* If anyone wants to do this one, feel free, it's a long maze of hell with std::map which is hard to solve in ghidra... */
/* void GJLevelList::getListLevelsArray(CCArray *levels) */


std::string GJLevelList::getUnpackedDescription()
{
    return (m_listDesc != "") ? LevelTools::base64DecodeString(m_listDesc) : "";
}

void GJLevelList::handleStatsConflict(GJLevelList *levelList)
{
    if (m_listOrder >= levelList->m_listOrder || m_listOrder < levelList->m_listOrder) {
        m_listOrder = levelList->m_listOrder;
    }
}

/* Has Another Dirty maze to solve */
/* GJLevelList::hasMatchingLevels(GJLevelList*) */

static int GLOBAL_MID;

bool __thiscall GJLevelList::init(){
    if (cocos2d::CCNode::init()) {
        auto dict = cocos2d::CCDictionary::create();
        if (this->m_snapShots != dict) {
            if (dict != nullptr) {
                dict->retain();
            }
            if (this->m_snapShots != nullptr) {
                this->m_snapShots->release();
            }
            this->m_snapShots = dict;
        }
        this->m_M_ID = GLOBAL_MID;
        GLOBAL_MID++;
        return true;
    }
    return false;
}

// Unknown Methods 
// int __thiscall GJLevelList::orderForLevel(int ID)
// {
//     auto d = this->m_completedLevels.data();
//     int i = 0;
//     while ((this->m_completedLevels != this->m_levels && (d = d[i] , d++, d != ID))) {
//         i++;
//     }
//     return iVar2;
// }


/* I will try and do the rest of these in the future... */
