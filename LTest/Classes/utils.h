#include "cocos2d.h"
#include "pugixml.hpp"

using namespace pugi;
using namespace std;
using namespace cocos2d;

string GetXmlPath(const std::string& objectName);

void CreateXmlDocument(const char* file, xml_document & retDoc);
