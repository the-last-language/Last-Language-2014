#include "GameScene3.h"
#include "GameScene4.h"
#include "GameScene1Obj1.h"
#include "MenuScene.h"
#include "../Pause/PauseScene.h"
#include "RoomScene0401.h"
#include "RoomScene0402.h"
#include"RoomScene04Final.h"
#include "Game/Dialog.h"

USING_NS_CC;

Scene* GameScene4::createScene()
{
    auto scene = Scene::create();
    
    auto layer = GameScene4::create();

    scene->addChild(layer);

    return scene;
}


bool GameScene4::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	UserDefault::getInstance()->setIntegerForKey("LASTPLAYED", 4);
	UserDefault::getInstance()->flush();
	initBG();
	initObj1();//복도로 가기.
	initObj2();//왼쪽
	initObj3();//왼쪽
	initObj4();//탄약창고
	//initObj5();//전선 줍기
	initExit();

    
    
    return true;
}

void GameScene4::initObj1()//중앙홀로 가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/back.png", "data/game1/object/back_on.png", CC_CALLBACK_1(GameScene4::callObj1Content, this));
	item_1->setPosition(480, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene4::initObj2()//TV방.
{
	auto item_2 = MenuItemImage::create("data/game1/object/bg4_0.png", "data/game1/object/bg4_0_on.png", CC_CALLBACK_1(GameScene4::callObj2Content, this));
	item_2->setPosition(105, 640-370);
	auto menu_2 = Menu::create(item_2, NULL);
	menu_2->setPosition(Vec2::ZERO);
	this->addChild(menu_2); 
}

void GameScene4::initObj3()//유류창고로
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg4_1.png",	"data/game1/object/bg4_1_on.png", CC_CALLBACK_1(GameScene4::callObj3Content, this));
	item_1->setPosition(285, 640-365);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene4::initObj4()//탄약창고(미니게임)
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg4_2.png",	"data/game1/object/bg4_2_on.png", CC_CALLBACK_1(GameScene4::callObj4Content, this));
	item_1->setPosition(860, 640-370);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene4::initExit()
{
 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(GameScene4::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void GameScene4::initBG()
{
//	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("data/game1/bg4.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

}

//복도로 가기
void GameScene4::callObj1Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene3::createScene());
}

//TV방
void GameScene4::callObj2Content(Ref * pSender)
{
	Director::getInstance()->pushScene(RoomScene0402::createScene());
}


void GameScene4::callObj3Content(Ref * pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("Mission1_complete") != 1)
	{
		UserDefault::getInstance()->setIntegerForKey("Dialog", 16);
		UserDefault::getInstance()->flush();
	
		Director::getInstance()->pushScene(Dialog::createScene());
		//Director::getInstance()->pushScene(GameScene1Obj1::createScene());
	}
	else
	{
		Director::getInstance()->pushScene(RoomScene04Final::createScene());
	}
}
//탄약창고(미니게임)
void GameScene4::callObj4Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(RoomScene0401::createScene());
}

//일시정지 메뉴 가기
void GameScene4::menuCloseCallback(Ref* pSender)
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
