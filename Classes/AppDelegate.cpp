#include "AppDelegate.h"
#include "MenuScene.h"
#include "KoreanUTF8.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::createWithRect(UTF8("최후의 언어"), Rect(0,0,960,640));
        director->setOpenGLView(glview);
    }

    director->setDisplayStats(false);

    director->setAnimationInterval(1.0 / 60);

    auto scene = MenuScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

}
