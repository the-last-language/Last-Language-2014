#include "GameScene3.h"
#include "GameScene5.h"
#include "GameScene1Obj1.h"
#include "MenuScene.h"
#include "../Pause/PauseScene.h"
#include "RoomScene0501.h"
#include "RoomScene0502.h"
#include "RoomScene0402.h"
#include "Game/Dialog.h"

USING_NS_CC;

Scene* GameScene5::createScene()
{
    auto scene = Scene::create();
    
    auto layer = GameScene5::create();

    scene->addChild(layer);

    return scene;
}


bool GameScene5::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	UserDefault::getInstance()->setIntegerForKey("LASTPLAYED", 5);
	UserDefault::getInstance()->flush();
	initBG();
	initObj1();//복도로 가기.
	initObj2();//환풍구 -> 이벤트 씬
	initObj3();//방1
	initObj4();//방2
	initObj5();//쓰레기통
	initExit();

    
    
    return true;
}

void GameScene5::initObj1()//중앙홀로 가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/back.png", "data/game1/object/back_on.png", CC_CALLBACK_1(GameScene5::callObj1Content, this));
	item_1->setPosition(480, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene5::initObj2()//환풍구. 일단 대화창.
{
	auto item_2 = MenuItemImage::create("data/game1/object/bg5_0.png", "data/game1/object/bg5_0_on.png", CC_CALLBACK_1(GameScene5::callObj2Content, this));
	item_2->setPosition(210, 640-445);
	auto menu_2 = Menu::create(item_2, NULL);
	menu_2->setPosition(Vec2::ZERO);
	this->addChild(menu_2); 
}

void GameScene5::initObj3()//사무실로
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg5_1.png",	"data/game1/object/bg5_1_on.png", CC_CALLBACK_1(GameScene5::callObj3Content, this));
	item_1->setPosition(335, 640-325);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene5::initObj4()//탄약창고(미니게임)
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg5_2.png",	"data/game1/object/bg5_2_on.png", CC_CALLBACK_1(GameScene5::callObj4Content, this));
	item_1->setPosition(860, 640-370);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene5::initObj5()//쓰레기통
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg5_5.png",	"data/game1/object/bg5_5_on.png", CC_CALLBACK_1(GameScene5::callObj5Content, this));
	if(UserDefault::getInstance()->getIntegerForKey("item_bg5_0") == 1)
	{
		item_1 = MenuItemImage::create("data/game1/object/bg5_5.png",	"data/game1/object/bg5_5.png", CC_CALLBACK_1(GameScene5::nothing, this));
	}
	item_1->setPosition(540, 640-345);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene5::initExit()
{
 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(GameScene5::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void GameScene5::initBG()
{
//	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("data/game1/bg5.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

}

//복도로 가기
void GameScene5::callObj1Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene3::createScene());
}

//환풍구. 일단 이벤트.
void GameScene5::callObj2Content(Ref * pSender)
{
	UserDefault::getInstance()->setIntegerForKey("Dialog", 13);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(GameScene5::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
}

//사무실
void GameScene5::callObj3Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(RoomScene0502::createScene());
}
//탄약창고(미니게임)
void GameScene5::callObj4Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(RoomScene0501::createScene());
}
//쓰레기 줍기
void GameScene5::callObj5Content(Ref * pSender)
{
	int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1");
	UserDefault::getInstance()->setIntegerForKey("Dialog", 12);
	UserDefault::getInstance()->flush();
	wires += 3;
	UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
	UserDefault::getInstance()->setIntegerForKey("item_bg5_0", 1);
	UserDefault::getInstance()->setIntegerForKey("chip_009", 1);
	UserDefault::getInstance()->setIntegerForKey("chip_012", 1);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(GameScene5::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
}

void GameScene5::nothing(Ref * pSender)
{
}

//일시정지 메뉴 가기
void GameScene5::menuCloseCallback(Ref* pSender)
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
