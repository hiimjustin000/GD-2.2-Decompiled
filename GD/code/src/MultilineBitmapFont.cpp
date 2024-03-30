#include "../headers/includes.h"
#include "TextArea.h"

/* NOTE: These functions have all changed since 2.1 and have different functionality to it */

/* TODO: */
/* MultilineBitmapFont::createWithFont */

/* TODO: */
/* MultilineBitmapFont::initWithFont */

/* TODO: Rename m_coloredText to specialDescriptors? */




void  MultilineBitmapFont::moveSpecialDescriptors(int pos,int size){
  	TextStyleSection *section;
  	for (unsigned int i = 0; i < m_coloredText->count(); i++){
    	section = (TextStyleSection *)m_coloredText->objectAtIndex(i);
    	auto end = section->m_end;
    	if (pos < section->m_start) {
    		section->m_start -= size;
    	  	if (end != -1) {
    	    	section->m_start = section->m_end - size;
    	  	}
   		}
    	else if ((end != -1) && (pos < end)){ 
			section->m_start = section->m_end - size;
		}
  	}
}



std::string MultilineBitmapFont::readColorInfo(std::string str){
	size_t pos, pos1;
	std::string newStr = "";
	int num;
	TextStyleSection* section;
	while (true){
		/* <c */
		pos = str.find("<c");
		if (pos == std::string::npos){
			/* <i */
			pos = str.find("<i"); 
			if (pos == std::string::npos){
				/* <s */
				pos = str.find("<s");
				if (pos == std::string::npos){
					/* <d */
					pos = str.find("<d");
					if (pos == std::string::npos)
						break;
					
          			num = atoi(str.substr(pos + 2, 3).c_str());
          			str = str.replace(pos, 6, "");
          			moveSpecialDescriptors(pos, 6);
          			// this->m_coloredText;
          			section = TextStyleSection::createDelaySection(pos, num / 100.0);

				} else {
       			   	int shakeX = atoi(str.substr(pos + 2, 1).c_str());
       			   	int shakeY = atoi(str.substr(pos + 3, 2).c_str());
       			   	str = str.replace(pos, 6, "");
       			   	moveSpecialDescriptors(pos, 6);
       			   	pos1 = str.find("</s>",0);
       			   	if (pos1 == std::string::npos)
						break;
       			   	str = str.replace(pos1, 4, "");
       			   	moveSpecialDescriptors(pos1 , 4);
       			   	// m_textSyles = this->m_coloredText;
       			   	section = TextStyleSection::createShakeSection(pos, pos1 - 1, shakeX, shakeY);
       			}
			
			} else {
				int instantSec = atoi(str.substr(pos + 2, 3).c_str());
          		str = str.replace(pos, 6, "");
				pos1 = str.find("</i>",0);
        		if (pos1 == std::string::npos) 
					break;
				str = str.replace(pos1,4,"");
				moveSpecialDescriptors(pos1,4);
        		// m_textSyles = this->m_coloredText;
        		section = TextStyleSection::createInstantSection(pos, pos1 - 1, instantSec / 100.0);
			}
		} else {
			char a = str.at(pos + 2);
      		str = str.replace(pos, 4, "");
      		moveSpecialDescriptors(pos, 4);
      		pos1 = str.find("</c>",0);
			if (pos1 == std::string::npos)
				break;

			cocos2d::ccColor3B color;
	
			/* I'll use switch blocks on most of these 
			since there's many of these even though 
			it's showing me if statements on ghidra... */
	
			switch(a) {
				case 'b': {
					color = {0x52, 0x4a, 0xe1};
					break;
				} 
				case 'g': {
					color = {0xe3, 0x40, 0x48};
					break;
				}
				case 'l': {
					color = {0xab, 0x60, 0xef};
					break;
				}
				case 'j': {
					color = {0x32, 200, 0xff};
					break;
				}
				case 'y': {
					color = {0xff, 0xff, 0x00};
					break;
				}
				case 'o': {
        			color = {0xa5, 0xff, 0x4b};
					break;
				}
				case 'r': {
          			color = {0xff, 0x5a, 0x00};
					break;
				}
				case 'a': {
					color = {0x96, 0x32, 0xff};
					break;
				}
				case 'c': {
					color = {0xff, 0xff, 0x96};
					break;
				}
				case 'f': {
					color = {0x96, 0xff, 0xff};
					break;
				}
				case 'p': {
					color = {0xff, 0xff, 0xff};
					break;
				}
			}
			section = TextStyleSection::createColoredSection(color, pos, pos1 - 1);	
			}
			/* Append our section to the stack... */
			m_coloredText->addObject(section);
		}
	return str;
}

/* Sets the Opacity of m_instantText */
void MultilineBitmapFont::setOpacity(unsigned char opacity){
  	for (unsigned int i = 0; i < m_instantText->count(); i++) {
    	(reinterpret_cast<cocos2d::CCSprite*>(m_instantText->objectAtIndex(i)))->setOpacity(opacity);
  	}
  	cocos2d::CCSprite::setOpacity(opacity);
}


/* TODO : MultilineBitmapFont::stringWithMaxWidth */

// void MultilineBitmapFont::moveSpecialDescriptors(int tStart, int tSize)
// {

// 	for (int i = 0; i < m_pColouredTextArray->count(); ++i)
// 	{
// 		ColoredSection* section = m_pColouredTextArray->objectAtIndex(i);
// 		if (section->m_nStart <= tStart && section->m_nEnd <= tStart)
// 			continue;
		
// 		section->m_nStart -= tSize;
// 		section->m_nEnd -= tSize;
// 	}

// 	for (int i = 0; i < m_pInstantTextArray->count(); ++i)
// 	{
// 		InstantSection* section = m_pInstantTextArray->objectAtIndex(i);
// 		if (section->m_nStart <= tStart && section->m_nEnd <= tStart)
// 			continue;
		
// 		section->m_nStart -= tSize;
// 		section->m_nEnd -= tSize;
// 	}
// }

// void MultilineBitmapFont::setOpacity(unsigned __int8 opacity)
// {
// 	for (int i = 0; i < m_pLetterArray->count(); ++i)
// 	{
// 		static_cast<cocos2d::CCSprite*>(m_pLetterArray->objectAtIndex(i))->setOpacity(opacity);
// 	}
// 	this->setOpacity(opacity);
// }

// MultilineBitmapFont* MultilineBitmapFont::create(const char* fontName, int* str, float scale, float width, cocos2d::CCPoint anchorPoint, bool tagsDisabled)
// {
// 	auto pRet = new MultilineBitmapFont;

// 	if (pRet && pRet->initWithFont(fontName, str, scale, width, anchorPoint, tagsDisabled))
// 	{
// 		pRet->autorelease();
// 		return pRet;
// 	}

// 	CC_SAFE_DELETE(pRet);
// 	return nullptr;
// }

// bool MultilineBitmapFont::initWithFont(const char* fontName, int* str, float scale, float width, cocos2d::CCPoint anchorPoint, bool tagsDisabled)
// {
// 	bool init = this->init(); // inititialising CCSprite Stuff
// 	if (init)
// 	{
// 		std::string modifiedStr = str;
// 		m_bTagsDisabled = tagsDisabled;

// 		cocos2d::CCDirector* director = cocos2d::CCDirector::sharedDirector();
// 		float scaledWidth = width * director->getContentScaleFactor();

// 		m_pColouredTextArray = cocos2d::CCArray::create();
// 		m_pColouredTextArray->retain();

// 		m_pInstantTextArray = cocos2d::CCArray::create();
// 		m_pInstantTextArray->retain();

// 		m_pDelayedTextArray = cocos2d::CCArray::create();
// 		m_pDelayedTextArray->retain();

// 		m_pLetterArray = cocos2d::CCArray::create();
// 		m_pLetterArray->retain();

// 		FontObject* font = BitmapFontCache::sharedFontCache()->fontWithConfigFile(fontName, scale);

// 		for (int i = 0; i < 300; i++)
// 			m_fFontWidth[i] = font->getFontWidth(i);

// 		if (!m_bTagsDisabled)
// 			modifiedStr = this->readColorInfo(str);

// 		float yPos = 0.0f;
// 		int strPos = 0;
// 		int loops = 0;
// 		while (modifiedStr)
// 		{
// 			modifiedStr = this->stringWithMaxWidth(modifiedStr, scaledWidth, scale);

// 			cocos2d::CCLabelBMFont* label = cocos2d::CCLabelBMFont::create(modifiedStr, fontName);
// 			label->setPosition({ 0.0f, yPos });
// 			label->setScale(scale);

// 			if (m_fContentSizeScaleMod < label->getContentSize().width * label->getScale())
// 				m_fContentSizeScaleMod = label->getContentSize().width * label->getScale();

// 			label->setAnchorPoint(anchorPoint);

// 			if (label->getAnchorPoint().x == 0.5f)
// 			{
// 				label->setAnchorPoint({ 0.0f, label->getAnchorPoint().y });
// 				cocos2d::CCPoint pos = label->getPosition();

// 				label->setPosition({ roundf(pos.x - (label->getContentSize().width / 2)), pos.y });
// 			}

// 			if (label->getAnchorPoint().y == 0.5f)
// 			{
// 				label->setAnchorPoint({ label->getAnchorPoint().x, 0.0f });
// 				cocos2d::CCPoint pos = label->getPosition();

// 				label->setPosition({ pos.x, roundf(pos.y - (label->getContentSize().height / 2)) });
// 			}

			
// 			std::size_t strSize = modifiedStr.size();
// 			int currentIdx = strPos + strSize; // names may change

// 			while (m_pColouredTextArray->count())
// 			{
// 				ColoredSection* section = m_pColouredTextArray->objectAtIndex(0);

// 				if (section->m_nStart < strPos || section->m_nStart > currentIdx)
// 					break;

// 				if (section->m_nEnd <= currentIdx)
// 					m_pColouredTextArray->removeObjectAtIndex(0, 1);
// 				else
// 					section->m_nStart = (section->m_nEnd = currentIdx) + 1;

// 				int pos = section->m_nStart - strPos;
// 				int limit = section->m_nEnd - strPos;

// 				if (pos == 1)
// 					pos = 0;

// 				while (pos <= limit)
// 				{
// 					cocos2d::CCSprite* child = label->getChildByTag(pos);

// 					if (child)
// 						child->setColor(section->m_cColour);
// 					++pos;
// 				}
// 			}

// 			while (m_pInstantTextArray->count())
// 			{
// 				ColoredSection* section = m_pInstantTextArray->objectAtIndex(0);

// 				if (section->m_nStart < strPos || section->m_nStart > currentIdx)
// 					break;

// 				if (section->m_nEnd <= currentIdx)
// 					m_pInstantTextArray->removeObjectAtIndex(0, 1);
// 				else
// 					section->m_nStart = (section->m_nEnd = currentIdx) + 1;

// 				int pos = section->m_nStart - strPos;
// 				int limit = section->m_nEnd - strPos;

// 				if (pos == 1)
// 					pos = 0;

// 				while (pos <= limit)
// 				{
// 					cocos2d::CCSprite* child = label->getChildByTag(pos);

// 					if (child)
// 						child->m_bVisible = true;
// 					++pos;
// 				}
// 			}

// 			while (m_pDelayedTextArray->count())
// 			{
// 				ColoredSection* section = m_pDelayedTextArray->objectAtIndex(0);

// 				if (section->m_nStart < strPos || section->m_nStart > currentIdx)
// 					break;

// 					m_pDelayedTextArray->removeObjectAtIndex(0, 1);

// 					int pos = section->m_nStart - strPos;
// 					if (pos == 1)
// 						pos = 0;

// 					if (!label->getChildByTag(pos))
// 					{
// 						cocos2d::CCSprite* child = label->getChildByTag(pos - 1);
// 						if (child)
// 							child->m_fDelay = section->m_fDelay;
// 					}
// 			}

// 			addChild(label);

// 			for (size_t i = 0; i < label->getChildrenCount(); i++)
// 				m_pLetterArray->addObject(label->getChildren()->objectAtIndex(i));
			
// 			modifiedStr = modifiedStr.erase(0, strLen);
// 			strPos += strLen;
// 			++loops;
// 		}

// 		m_pColouredTextArray->release();
// 		m_pInstantTextArray->release();

// 		m_obTextureSize.width = (loops - 1) * anchorPoint.y;
// 		m_obTextureSize.height = scaledWidth + 0.0f;

// 		float x = 0.0f;

// 		if (anchorPoint.x != 0.0f)
// 		{
// 			if (anchorPoint.x != 1.0f)
// 				x = m_obTextureSize.height / 2;
// 		}

// 		m_obPosition = { x, m_obTextureSize.width };
// 	}
// 	return init;
// }

// std::string MultilineBitmapFont::stringWithMaxWidth(std::string str, float scaledFontWidth, float scale)
// {
// 	int pos = 0;
// 	float fontWidthScale = 0.0f, unk = 0.0f;

// 	std::string str2;

// 	while (pos < str.size() && fontWidthScale < (2 * scaledFontWidth))
// 	{
// 		float fontWidth = m_fFontWidth[str.at(pos)];
// 		std::string ch = str.substr(pos, 1);

// 		if (ch == "\n")
// 		{
// 			fontWidthScale += scale * fontWidth;
// 			pos = 1000;
// 			str2.append(" ");
// 			break;
// 		}

// 		if (ch != '\xE2' && str.at(0) == ' ')
// 		{
// 			unk = fontWidthScale * (fontWidth * scale);
// 		}

// 		str2 += ch;
// 		++pos;

// 		fontWidthScale += scale * fontWidth;
// 	}

// 	float half = scaledFontWidth / 2;

// 	if (!m_bUnkScaleBool && fontWidthScale < (2 * scaledFontWidth))
// 		m_fHalfScaledFontWidth = (fontWidthScale / 2) - unk;

// 	if (half > m_fHalfScaledFontWidth)
// 		m_fHalfScaledFontWidth = half;

// 	if (str.size() > pos)
// 	{
// 		int temp = 0, temp2 = pos;

// 		while (temp <= str.size())
// 		{
// 			if (temp2 <= 0)
// 				break;

// 			if (str2.at(temp2 - 1) == ' ')
// 				break;

// 			++temp;
// 			--temp2;
// 		}

// 		if (pos - temp > 1)
// 			str2 = str2.substr(0, str2.size() - temp);
// 	}
// 	return cocos2d::CCString::create(str2)->m_sString;
// }
