#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

void AppDelegate::initGLContextAttrs()
{

    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

static int register_all_packages()
{
    return 0;
}

bool AppDelegate::applicationDidFinishLaunching() {

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
	if (!glview) {
		glview = GLViewImpl::create("Monkey Adventure");
		director->setOpenGLView(glview);
		// For Android 
		glview->setFrameSize(480,800);
		
		// For IOS
		//glview->setFrameSize(320, 480);
		//glview->setFrameSize(640,960);
		//glview->setFrameSize(640, 1136);
		//glview->setFrameSize(750, 1334);
	//	glview->setFrameSize(1242, 2208);
		//glview->setFrameSize(480, 800);

		glview->setFrameZoomFactor(.8f);
	}
	director->setDisplayStats(false);
	director->getOpenGLView()->setDesignResolutionSize(480, 800, ResolutionPolicy::FIXED_HEIGHT);
    register_all_packages();

    auto scene = HelloWorld::createScene();


    director->runWithScene(scene);


    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}


void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}
