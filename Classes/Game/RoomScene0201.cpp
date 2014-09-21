#include "RoomScene0201.h"
#include "GameScene2.h"
#include "GameScene1Obj1.h"
#include "MenuScene.h"
#include "../Pause/PauseScene.h"

USING_NS_CC;

Scene* RoomScene0201::createScene()
{
    auto scene = Scene::create();
    
    auto layer = RoomScene0201::create();

    scene->addChild(layer);

    return scene;
}


bool RoomScene0201::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	UserDefault::getInstance()->setIntegerForKey("LASTPLAYED", 201);
	UserDefault::getInstance()->flush();
	initBG();
	initObj1();//복도로 나가기
	//initObj2();//칩 줍기
	//initObj3();//전선 줍기
	initExit();

    
    
    return true;
}

void RoomScene0201::initObj1()//복도로 나가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/back.png", "data/game1/object/back_on.png", CC_CALLBACK_1(RoomScene0201::callObj1Content, this));
	item_1->setPosition(480, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}


void RoomScene0201::initExit()
{
 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(RoomScene0201::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void RoomScene0201::initBG()
{
//	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("data/game1/bg2.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

}

//복도로 나가기
void RoomScene0201::callObj1Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene2::createScene());
}



//일시정지 메뉴 가기
void RoomScene0201::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

		Director::getInstance()->pushScene(PauseScene::createScene());


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
