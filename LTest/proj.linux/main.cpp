#include "../Classes/AppDelegate.h"
#include "cocos2d.h"
#include "CCEGLView.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include "Log.h"

USING_NS_CC;

int main(int argc, char **argv)
{
    // create the application instance
    Logger.log(Log::Prioritiy_INFO, "All right");
    AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setFrameSize(480, 320);
    return CCApplication::sharedApplication()->run();
}
