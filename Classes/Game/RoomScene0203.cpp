#include "RoomScene0203.h"
#include "GameScene2.h"
#include "GameScene1Obj1.h"
#include "MenuScene.h"
#include "../Pause/PauseScene.h"
#include "Dialog.h"

USING_NS_CC;

Scene* RoomScene0203::createScene()
{
    auto scene = Scene::create();
    
    auto layer = RoomScene0203::create();

    scene->addChild(layer);

    return scene;
}


bool RoomScene0203::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	UserDefault::getInstance()->setIntegerForKey("LASTPLAYED", 203);
	UserDefault::getInstance()->flush();
	initBG();
	initObj1();//복도로 나가기
	initObj2();//왼쪽 관물대-전선.
	initObj3();//총기-단어칩
	initExit();

    
    
    return true;
}

void RoomScene0203::initObj1()//복도로 나가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/back.png", "data/game1/object/back_on.png", CC_CALLBACK_1(RoomScene0203::callObj1Content, this));
	item_1->setPosition(480, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}


void RoomScene0203::initExit()
{
 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(RoomScene0203::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void RoomScene0203::initBG()
{
//	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("data/game1/bg2-2.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

}

//복도로 나가기
void RoomScene0203::callObj1Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene2::createScene());
}
void RoomScene0203::callObj2Content(Ref * pSender)//왼쪽 관물대-전선
{
	int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1");
	UserDefault::getInstance()->setIntegerForKey("Dialog", 7);
	UserDefault::getInstance()->flush();
	
	wires += 1;
	UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_room0203_0", 1);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(RoomScene0203::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
}
void RoomScene0203::callObj3Content(Ref * pSender)//총기걸이-단어칩
{
	UserDefault::getInstance()->setIntegerForKey("Dialog", 8);
	UserDefault::getInstance()->flush();
	
	UserDefault::getInstance()->setIntegerForKey("chip_005", 1);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("chip_006", 1);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_room0203_1", 1);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(RoomScene0203::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
}

void RoomScene0203::nothing(Ref* pSender)
{
}

void RoomScene0203::initObj2()//왼쪽 관물대 - 전선.
{
	auto item_1 = MenuItemImage::create("data/game1/object/room0203_0.png", "data/game1/object/room0203_0_on.png", CC_CALLBACK_1(RoomScene0203::callObj2Content, this));
	if(UserDefault::getInstance()->getIntegerForKey("item_room0203_0") == 1)
	{
		item_1 = MenuItemImage::create("data/game1/object/room0203_0.png", "data/game1/object/room0203_0.png", CC_CALLBACK_1(RoomScene0203::nothing, this));
	}
	item_1->setPosition(60, 640-270);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene0203::initObj3()//총기걸이. - 단어칩
{
	auto item_2 = MenuItemImage::create("data/game1/object/room0203_1.png", "data/game1/object/room0203_1_on.png", CC_CALLBACK_1(RoomScene0203::callObj3Content, this));
	if(UserDefault::getInstance()->getIntegerForKey("item_room0203_1") == 1)
	{
		item_2 = MenuItemImage::create("data/game1/object/room0203_1.png", "data/game1/object/room0203_1.png", CC_CALLBACK_1(RoomScene0203::nothing, this));
	}
	item_2->setPosition(270, 640-315);
	auto menu_2 = Menu::create(item_2, NULL);
	menu_2->setPosition(Vec2::ZERO);
	this->addChild(menu_2); 
}

//일시정지 메뉴 가기
void RoomScene0203::menuCloseCallback(Ref* pSender)
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
