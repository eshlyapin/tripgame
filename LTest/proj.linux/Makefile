EXECUTABLE = LTest

INCLUDES = -I.. -I../Classes

SOURCES = main.cpp \
        ../Classes/AppDelegate.cpp \
        ../Classes/GameObject.cpp \
        ../Classes/GameObjectLoader.cpp \
        ../Classes/GameMenu.cpp \
        ../Classes/GameScreen.cpp \
        ../Classes/HUD.cpp \
        ../Classes/InputLayer.cpp \
        ../Classes/inventory.cpp \
        ../Classes/Log.cpp \
        ../Classes/ObjectFactory.cpp \
        ../Classes/ObjectState.cpp \
        ../Classes/ObjectStrategy.cpp \
        ../Classes/pugixml.cpp \
        ../Classes/utils.cpp

COCOS_ROOT = ../../..
include $(COCOS_ROOT)/cocos2dx/proj.linux/cocos2dx.mk

SHAREDLIBS += -lcocos2d
COCOS_LIBS = ../../../lib/linux/debug/libcocos2d.so

$(TARGET): $(OBJECTS) $(STATICLIBS) $(COCOS_LIBS) $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_LINK)$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

$(OBJ_DIR)/%.o: %.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

$(OBJ_DIR)/%.o: ../%.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@
$@
