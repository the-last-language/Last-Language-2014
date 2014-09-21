#include "GameScene2.h"
#include "GameScene3.h"
#include "GameScene4.h"
#include "GameScene5.h"
#include "GameScene1Obj1.h"
#include "MenuScene.h"
#include "game/Dialog.h"
#include "../Pause/PauseScene.h"
#include "Ending/EndScene1.h"
#include "Ending/EndSceneBad.h"

USING_NS_CC;

Scene* GameScene3::createScene()
{
    auto scene = Scene::create();
    
    auto layer = GameScene3::create();

    scene->addChild(layer);

    return scene;
}


bool GameScene3::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	int m1 = UserDefault::getInstance()->getIntegerForKey("Mission0_complete") ;
	UserDefault::getInstance()->setIntegerForKey("LASTPLAYED", 3);
	UserDefault::getInstance()->flush();
	initBG();
	initObj1();//복도로 가기.
	initObj2();//왼쪽
	if(m1 == 1)
	{
		initObj3();//오른쪽
	}
	initObj4();//엘리베이터
	//initObj5();//전선 줍기
	initExit();

    
    
    return true;
}

void GameScene3::initObj1()//복도로 가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/back.png", "data/game1/object/back_on.png", CC_CALLBACK_1(GameScene3::callObj1Content, this));
	item_1->setPosition(480, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene3::initObj2()//왼쪽으로 가기
{
	auto item_2 = MenuItemImage::create("data/game1/object/bg3_0.png", "data/game1/object/bg3_0_on.png", CC_CALLBACK_1(GameScene3::callObj2Content, this));
	item_2->setPosition(90, 270);
	auto menu_2 = Menu::create(item_2, NULL);
	menu_2->setPosition(Vec2::ZERO);
	this->addChild(menu_2); 
}

void GameScene3::initObj3()//오른쪽으로 가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg3_1.png",	"data/game1/object/bg3_1_on.png", CC_CALLBACK_1(GameScene3::callObj3Content, this));
	item_1->setPosition(890, 280);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene3::initObj4()//엘리베이터
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg3_2.png",	"data/game1/object/bg3_2_on.png", CC_CALLBACK_1(GameScene3::callObj4Content, this));
	item_1->setPosition(480, 425);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene3::initExit()
{
 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(GameScene3::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void GameScene3::initBG()
{
	int m1 = UserDefault::getInstance()->getIntegerForKey("Mission0_complete") ;
//	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("data/game1/bg3.png");
	if (m1 == 1)
	{
		sprite1 = Sprite::create("data/game1/bg3-1.png");
	}
	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

}

//복도로 가기
void GameScene3::callObj1Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene2::createScene());
}

//칩을 주워라
void GameScene3::callObj2Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene4::createScene());
}

//전선을 주워라
void GameScene3::callObj3Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene5::createScene());
}

void GameScene3::callObj4Content(Ref * pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("Mission2_complete") != 1)
	{
		UserDefault::getInstance()->setIntegerForKey("Dialog",20);
		UserDefault::getInstance()->flush();
	
		Director::getInstance()->pushScene(Dialog::createScene());
	}
	else
	{
		if(UserDefault::getInstance()->getIntegerForKey("failcnt") >= 20)
		{
			Director::getInstance()->pushScene(EndSceneBad::createScene());
		}
		else
		{
			Director::getInstance()->pushScene(EndScene1::createScene());
		}
	}
}

//일시정지 메뉴 가기
void GameScene3::menuCloseCallback(Ref* pSender)
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
