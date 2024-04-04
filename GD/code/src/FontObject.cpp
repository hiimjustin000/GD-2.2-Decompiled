#include "includes.h"



FontObject *FontObject::createWithConfigFile(const char *fileName, float _Size){
    /* Fun Fact: FontObject is 0x4e4 bytes large (That's massive!) */
    FontObject* fo = new FontObject;
    if (fo->initWithConfigFile(fileName, _Size)){
        fo->autorelease();
        return fo;
    }
    CC_SAFE_DELETE(fo);
    return nullptr;
}


int FontObject::getFontWidth(int _unkWidth){
    /* Wanted to ensure I had the math correctly done */
    return (m_textObject.m_kerning + _unkWidth) * 4;
}

bool FontObject::initWithConfigFile(const char* fileName, float _Size){
    this->parseConfigFile(fileName, _Size);
    return true;
}

/* NOTE This Function Felt rather Confusing to me... */

void FontObject::parseConfigFile(char const* fileName, float _Size){
    char* cStr = (char*)(cocos2d::CCString::createWithContentsOfFile(fileName)->getCString());
    auto arr = cocos2d::CCArray::create();
    char* tok = strtok(cStr, "\n");

    while ((tok != nullptr && (tok = strtok(cStr,"\n")))){
        arr->addObject(cocos2d::CCString::create(tok));
    }
    

    for (unsigned int i = 0; i < arr->count(); i++){
        cocos2d::CCString* ccStr = reinterpret_cast<cocos2d::CCString*>(arr->objectAtIndex(i));
        std::string info(ccStr->getCString());
        /* SEE: CCLabelBMFomt.cpp , Ghidra made this part really confusing but it seems this is it... */

        if (info.substr(0 , strlen("chars")) != "chars"){
            if (info.substr(0, strlen("char")) != "char"){
                /* NOTE: Memory Leak on Robtop's end? arr2 is never released... */
                cocos2d::CCArray* arr2 = cocos2d::CCArray::create();
                char* cinfo = (char*)ccStr->getCString();
                cinfo = strtok(cinfo, "=");

                while (cinfo != nullptr && strtok(cinfo, "=")){
                    arr2->addObject(cocos2d::CCString::create(cinfo));
                }

                std::string x2(reinterpret_cast<cocos2d::CCString*>(arr2->objectAtIndex(0))->getCString());
                int size = atoi(x2.substr(x2.find(" ", 0)).data());

                int m_widths[300];
                m_widths[charcode] = charwidth + xAdvance;

                /* I will temporary simplify this for now...*/
                m_textObject.m_kerning = reinterpret_cast<cocos2d::CCString*>(arr2->objectAtIndex(3))->intValue() + reinterpret_cast<cocos2d::CCString*>(arr2->objectAtIndex(7))->intValue();
            }
        }
        arr->release();
    }
}
