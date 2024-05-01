#include "includes.h"
// Blame my Poor Ass .vscode settings -_-
#include "cocos2dx/support/zip_support/ZipUtils.h"


/* 
I was able to possibly figure out the calls
for  (code**)(in_r1->field0_0x0 + 0x1bc) 
but I want to know how to solve for it as 
they're not in the vtables and I had to think 
logically about where everything goes...

0x1bc encodeDataTo
0x1c0 dataloaded
0x1c4 firstload

Update: it's a vtable... -_-

*/

std::string GManager::getcompressedString(){
    return cocos2d::ZipUtils::compressString(getSaveString(), false, 0);
}

std::string GManager::getSaveString(){
    DS_Dictionary* dsdict = new DS_Dictionary;
    encodeDataTo(dsdict);
    std::string saveString = dsdict->saveRootSubDictToString();
    delete dsdict;
    return saveString;
}


bool GManager::init(){
    m_setup = true;
    m_saved = false;
    return true;
}

bool GManager::load() {
   return loadDataFromFile(m_fileName);
}

bool GManager::loadDataFromFile(std::string fileName){
    bool loadedData = true;
    std::string backup;
    /* I Think Robtop should've made dsdict into a RAII variable TBH... - Calloc */
    DS_Dictionary *dsdict = new DS_Dictionary();
    if (!tryLoadData(dsdict, fileName)) {
        backup = fileName + "2.dat";
        /* Create a backup */
        if (tryLoadData(dsdict, backup)) {
            dsdict->copyFile(backup.c_str(), fileName.c_str());
        }
        else {
            /* Failed the second time so now try loading the backup file */
            loadedData = tryLoadData(dsdict, fileName + ".dat.bak");
        }
        if (!loadedData) {
            firstLoad();
        }
    }
    loadedData = dataLoaded(dsdict);
    delete dsdict;
    return loadedData;
}


bool GManager::loadFromCompressedString(std::string compressedStr){
    return loadFromString(cocos2d::ZipUtils::decompressString(compressedStr, false, 0));
}

bool GManager::loadFromString(std::string data){
    DS_Dictionary *dsdict = new DS_Dictionary();
    if (dsdict->loadRootSubDictFromString(data)) {
        auto loaded = dataLoaded(dsdict);
        delete dsdict;
        return loaded;
    }
    delete dsdict;
    return false;
}

void GManager::save(){
    saveGMTo(m_fileName);
}


bool GManager::saveData(DS_Dictionary *dsdict, std::string fileName){
    return dsdict->saveRootSubDictToCompressedFile(fileName.c_str());
}

void GManager::saveGMTo(std::string fileName){
    DS_Dictionary *dsdict = new DS_Dictionary();
    encodeDataTo(dsdict);
    m_saved = saveData(dsdict, fileName);
    delete dsdict;
}

void GManager::setup(){
    m_setup = true;
    load();
}

bool GManager::tryLoadData(DS_Dictionary *dsdict, std::string data){
    return dsdict->loadRootSubDictFromCompressedFile(data.c_str());
}


