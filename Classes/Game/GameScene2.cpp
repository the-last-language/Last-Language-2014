#include "GameScene2.h"
#include "GameScene1.h"
#include "GameScene3.h"
#include "GameScene1Obj1.h"
#include "MenuScene.h"
#include "RoomScene0201.h"
#include "RoomScene0202.h"
#include "RoomScene0203.h"
#include "../Pause/PauseScene.h"
USING_NS_CC;

Scene* GameScene2::createScene()
{
    auto scene = Scene::create();
    
    auto layer = GameScene2::create();

    scene->addChild(layer);

    return scene;
}


bool GameScene2::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	UserDefault::getInstance()->setIntegerForKey("LASTPLAYED", 2);
	UserDefault::getInstance()->flush();
	initBG();
	initObj1();//시작한 방으로 돌아가기.
	initObj2();//잡방 1
	initObj3();//잡방 2
	initObj4();//잡방 3
	initObj5();//중앙홀로 가기
	//initObj6();//
	initExit();

    
    
    return true;
}

void GameScene2::initObj1()//시작한 방으로 가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg1_0.png", "data/game1/object/bg1_0_on.png", CC_CALLBACK_1(GameScene2::callObj1Content, this));
	item_1->setPosition(880, 640-415);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene2::initObj2()//잡방 1
{
	auto item_2 = MenuItemImage::create("data/game1/object/bg1_1.png", "data/game1/object/bg1_1_on.png", CC_CALLBACK_1(GameScene2::callObj2Content, this));
	item_2->setPosition(95, 640-415);
	auto menu_2 = Menu::create(item_2, NULL);
	menu_2->setPosition(Vec2::ZERO);
	this->addChild(menu_2); 
}

void GameScene2::initObj3()//잡방2.
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg1_2.png",	"data/game1/object/bg1_2_on.png", CC_CALLBACK_1(GameScene2::callObj3Content, this));
	item_1->setPosition(355, 640-395);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene2::initObj4()//잡방3.
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg1_3.png",	"data/game1/object/bg1_3_on.png", CC_CALLBACK_1(GameScene2::callObj4Content, this));
	item_1->setPosition(715, 640-395);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene2::initObj5()//중앙홀로 가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg1_4.png",	"data/game1/object/bg1_4_on.png", CC_CALLBACK_1(GameScene2::callObj5Content, this));
	item_1->setPosition(490, 640-370);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}


void GameScene2::initExit()
{
 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(GameScene2::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

//배경 불러오기 : 따로 배경 스크롤 되는게 아니라서 최하단 스프라이트로 불러온다.
void GameScene2::initBG()
{
//	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("data/game1/bg1.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

}

void GameScene2::callObj1Content(Ref * pSender)//처음 방으로 돌아가기
{
	Director::getInstance()->replaceScene(GameScene1::createScene());
}

void GameScene2::callObj2Content(Ref * pSender)//잡방1.
{
	Director::getInstance()->replaceScene(RoomScene0201::createScene());
}

void GameScene2::callObj3Content(Ref * pSender)//잡방2.
{
	Director::getInstance()->replaceScene(RoomScene0202::createScene());
}

void GameScene2::callObj4Content(Ref * pSender)//잡방3.
{
	Director::getInstance()->replaceScene(RoomScene0203::createScene());
}

void GameScene2::callObj5Content(Ref * pSender)//중앙홀로 나아가기.
{
	Director::getInstance()->replaceScene(GameScene3::createScene());
}

void GameScene2::menuCloseCallback(Ref* pSender)
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
