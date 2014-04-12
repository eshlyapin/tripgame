#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"
#include "ScreenFactory.h"

pugi::xml_document ScreenFactory::doc;

USING_NS_CC;

/*int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)*/
int main()
{
    //UNREFERENCED_PARAMETER(hPrevInstance);
    //UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
    AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName("LTest");
    eglView->setFrameSize(480, 320);
    return CCApplication::sharedApplication()->run();
}

