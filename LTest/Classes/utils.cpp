#include "utils.h"

string GetXmlPath(const std::string& objectName)
{
	//string lol = objectName + ".xml" ;
	string xmlFile = objectName + ".xml"; 
	return CCFileUtils::sharedFileUtils()->fullPathForFilename(xmlFile.c_str());
}

void CreateXmlDocument(const char* file, xml_document & retDoc)
{
	unsigned char *buffer = 0;
	unsigned long bufferSize = 0;
	buffer = CCFileUtils::sharedFileUtils()->getFileData(file,"r", &bufferSize);

	retDoc.load_buffer(buffer, bufferSize);
	delete[] buffer;
}
