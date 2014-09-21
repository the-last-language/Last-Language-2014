#include "GameScene1Obj1.h"
#include "MenuScene.h"
#include "KoreanUTF8.h"

USING_NS_CC;

Scene* GameScene1Obj1::createScene()
{
    auto scene = Scene::create();
    
    auto layer = GameScene1Obj1::create();

    scene->addChild(layer);

    return scene;
}


bool GameScene1Obj1::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF(UTF8("Object TEST.\n그냥 일반적인 컴퓨터.\n지금은 고장남.\n아마 접속콘솔로 쓰일듯."),"data/fonts/GodoB.ttf",30);
	label->setPosition(Point(480,320));
	this->addChild(label);
    
	initCancel();
    
    return true;
}

void GameScene1Obj1::initCancel()
{
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(GameScene1Obj1::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}


void GameScene1Obj1::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    //Director::getInstance()->end();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(MenuScene::createScene());
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
