#include "utils.h"

using namespace pugi;
using namespace std;
using namespace cocos2d;

string GetXmlPath(const std::string& objectName)
{
	string xmlFile = objectName + ".xml"; 
	xmlFile = CCFileUtils::sharedFileUtils()->fullPathForFilename(xmlFile.c_str());
	return xmlFile;
}

void CreateXmlDocument(const char* file, xml_document & retDoc)
{
	unsigned char *buffer = 0;
	unsigned long bufferSize = 0;
	buffer = CCFileUtils::sharedFileUtils()->getFileData(file,"r", &bufferSize);

	retDoc.load_buffer(buffer, bufferSize);
	delete[] buffer;
}

void MakeString(string& dest, size_t src)
{
	stringstream ss;
	ss << src;
	dest = ss.str();
}

void MakeString(string& dest, float src)
{
	stringstream ss;
	ss << src;
	dest = ss.str();
}

bool IsFileAvailable(const std::string& path)
{
	if(CCFileUtils::sharedFileUtils()->isFileExist(path))
		return true;
	return false;
}