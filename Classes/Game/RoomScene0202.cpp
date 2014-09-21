#include "RoomScene0202.h"
#include "GameScene2.h"
#include "GameScene1Obj1.h"
#include "MenuScene.h"
#include "../Pause/PauseScene.h"
#include "Dialog.h"

USING_NS_CC;

Scene* RoomScene0202::createScene()
{
    auto scene = Scene::create();
    
    auto layer = RoomScene0202::create();

    scene->addChild(layer);

    return scene;
}


bool RoomScene0202::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	UserDefault::getInstance()->setIntegerForKey("LASTPLAYED", 202);
	UserDefault::getInstance()->flush();
	initBG();
	initObj1();//복도로 나가기
	initObj2();//가운데 서랍장 = 칩
	initObj3();//왼쪽 침대 = 전선
	initExit();

    
    
    return true;
}

void RoomScene0202::initObj1()//복도로 나가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/back.png", "data/game1/object/back_on.png", CC_CALLBACK_1(RoomScene0202::callObj1Content, this));
	item_1->setPosition(480, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}


void RoomScene0202::initExit()
{
 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(RoomScene0202::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void RoomScene0202::initBG()
{
//	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("data/game1/bg2-1.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

}

void RoomScene0202::initObj2()//가운데 서랍장
{
	auto item_1 = MenuItemImage::create("data/game1/object/room0202_0.png", "data/game1/object/room0202_0_on.png", CC_CALLBACK_1(RoomScene0202::callObj2Content, this));
	if(UserDefault::getInstance()->getIntegerForKey("item_room0202_0") == 1)
	{
		item_1 = MenuItemImage::create("data/game1/object/room0202_0.png", "data/game1/object/room0202_0.png", CC_CALLBACK_1(RoomScene0202::nothing, this));
	}
	item_1->setPosition(490, 640-340);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene0202::initObj3()//왼쪽 침대.
{
	auto item_2 = MenuItemImage::create("data/game1/object/room0202_1.png", "data/game1/object/room0202_1_on.png", CC_CALLBACK_1(RoomScene0202::callObj3Content, this));
	if(UserDefault::getInstance()->getIntegerForKey("item_room0202_1") == 1)
	{
		item_2 = MenuItemImage::create("data/game1/object/room0202_1.png", "data/game1/object/room0202_1.png", CC_CALLBACK_1(RoomScene0202::nothing, this));
	}
	item_2->setPosition(195, 640-455);
	auto menu_2 = Menu::create(item_2, NULL);
	menu_2->setPosition(Vec2::ZERO);
	this->addChild(menu_2); 
}


//복도로 나가기
void RoomScene0202::callObj1Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene2::createScene());
}
void RoomScene0202::callObj2Content(Ref * pSender)//가운데 서랍장 = 칩
{
	UserDefault::getInstance()->setIntegerForKey("Dialog", 5);
	UserDefault::getInstance()->flush();
	
	UserDefault::getInstance()->setIntegerForKey("item_room0202_0", 1);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("chip_003", 1);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("chip_004", 1);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(RoomScene0202::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
}
void RoomScene0202::callObj3Content(Ref * pSender)//침대 = 전선
{
	int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1");
	UserDefault::getInstance()->setIntegerForKey("Dialog", 6);
	UserDefault::getInstance()->flush();
	
	
	wires += 3;
	UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_room0202_1", 1);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(RoomScene0202::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
}

void RoomScene0202::nothing(Ref* pSender)
{
}

//일시정지 메뉴 가기
void RoomScene0202::menuCloseCallback(Ref* pSender)
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
