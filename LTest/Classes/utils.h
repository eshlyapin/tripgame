#include "cocos2d.h"
#include "pugixml.hpp"
#include <string>

std::string GetXmlPath(const std::string& objectName);

void CreateXmlDocument(const char* file, pugi::xml_document& retDoc);
