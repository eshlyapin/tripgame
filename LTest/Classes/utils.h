#include "cocos2d.h"
#include "pugixml.hpp"
#include <string>

std::string GetXmlPath(const std::string& objectName);

void CreateXmlDocument(const char* file, pugi::xml_document& retDoc);

void MakeString(std::string&, size_t);

void MakeString(std::string&, float);

bool IsFileAvailable(const std::string& path);