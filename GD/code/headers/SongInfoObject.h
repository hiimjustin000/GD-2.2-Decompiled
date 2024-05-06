#ifndef __SONGINFOOBJECT_H__
#define __SONGINFOOBJECT_H__

#include "includes.h"
#include <map>
#include <vector>
#include <string>

class SongInfoObject : public cocos2d::CCNode
{
public:
	int m_songID;
	std::string m_songName;	
	std::string m_artistName;	
	std::string m_youtubeVideo;	
	std::string m_youtubeChannel;	
	std::string m_songUrl;
	int m_artistID;
	float m_fileSize;	
	bool m_UnknownSong;	
	bool m_isVerified;
	bool m_isBanned;
	int m_priority;

	std::map<int, std::vector<std::string>> m_tags;
	std::string m_tag;

	SongInfoObject():
		m_songID(0),
  		m_songName(""),
  		m_artistName(""),
  		m_youtubeVideo(""),
  		m_youtubeChannel(""),
  		m_songUrl(""),
  		m_artistID(0),
  		m_fileSize(0.0),
  		m_UnknownSong(false),
  		m_isVerified(false),
  		m_isBanned(false),
//   *(undefined4 *)&	field16_0x130 = 0;
//   *(undefined4 *)&	field_0x134 = 0;
  		m_priority(-1),
		m_tag("")
	{};


	static SongInfoObject* create(
		int songID, 
		std::string songName, 
		std::string artistName, 
		int artistID, 
		float filesize, 
		std::string youtubeVideo, 
		std::string youtubeChannel, 
		std::string url, 
		int priority
	);
	void addTags(std::string tagData);
	virtual bool canEncode();
	static SongInfoObject* create(int songID);
	static SongInfoObject* create(cocos2d::CCDictionary* dict);
	static SongInfoObject* createWithCoder(DS_Dictionary* dsdict);
	bool containsTag(int tagID);
	
	void encodeWithCoder(DS_Dictionary* dsdict);



	bool init(
		int songID,
		std::string songName,
		std::string artistName,
        int artistID,
		float filesize,
		std::string youtubeVideo,
		std::string youtubeChannel,
        std::string url,
		int priority
	);


};

#endif // __SONGINFOOBJECT_H__
