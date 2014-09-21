#include "RoomScene0401.h"
#include "GameScene4.h"
#include "../mission/Mission0.h"
#include "MenuScene.h"
#include "../Pause/PauseScene.h"
#include "Game/Dialog.h"

USING_NS_CC;

Scene* RoomScene0401::createScene()
{
    auto scene = Scene::create();
    
    auto layer = RoomScene0401::create();

    scene->addChild(layer);

    return scene;
}


bool RoomScene0401::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	UserDefault::getInstance()->setIntegerForKey("LASTPLAYED", 401);
	UserDefault::getInstance()->flush();
	initBG();
	initObj1();//복도로 나가기
	initObj2();//미니게임
	initObj3();//칩 획득
	initObj4();//전선 획득.
	initExit();

    
    
    return true;
}

void RoomScene0401::initObj1()//복도로 나가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/back.png", "data/game1/object/back_on.png", CC_CALLBACK_1(RoomScene0401::callObj1Content, this));
	item_1->setPosition(480, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene0401::initObj2()//미니게임. Mission0
{
	int r = UserDefault::getInstance()->getIntegerForKey("Mission0_complete") ;
	auto item_1 = MenuItemImage::create("data/game1/object/room0401_0.png", "data/game1/object/room0401_0_on.png", CC_CALLBACK_1(RoomScene0401::callObj2Content, this));
	if(r== 1)
	{
		item_1 = MenuItemImage::create("data/game1/object/room0401_0.png", "data/game1/object/room0401_0.png", CC_CALLBACK_1(RoomScene0401::nothing, this));
	}
	item_1->setPosition(545, 640-315);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene0401::initObj3()//칩을 얻는다.
{
	int r = UserDefault::getInstance()->getIntegerForKey("item_room0401_1") ;
	auto item_1 = MenuItemImage::create("data/game1/object/room0401_1.png", "data/game1/object/room0401_1_on.png", CC_CALLBACK_1(RoomScene0401::callObj3Content, this));
	if(r== 1)
	{
		item_1 = MenuItemImage::create("data/game1/object/room0401_1.png", "data/game1/object/room0401_1.png", CC_CALLBACK_1(RoomScene0401::nothing, this));
	}
	item_1->setPosition(815, 640-270);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene0401::initObj4()//전선을 얻는다.
{
	int r = UserDefault::getInstance()->getIntegerForKey("item_room0401_2") ;
	auto item_1 = MenuItemImage::create("data/game1/object/room0401_2.png", "data/game1/object/room0401_2_on.png", CC_CALLBACK_1(RoomScene0401::callObj4Content, this));
	if(r== 1)
	{
		item_1 = MenuItemImage::create("data/game1/object/room0401_2.png", "data/game1/object/room0401_2.png", CC_CALLBACK_1(RoomScene0401::nothing, this));
	}
	item_1->setPosition(640, 640-170);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}


void RoomScene0401::initExit()
{
 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(RoomScene0401::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void RoomScene0401::initBG()
{
//	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("data/game1/bg4-1.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

}

//복도로 나가기
void RoomScene0401::callObj1Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene4::createScene());
}

void RoomScene0401::callObj2Content(Ref * pSender)
{
	//Director::getInstance()->replaceScene(RoomScene0401::createScene());
	Director::getInstance()->replaceScene(Mission0::createScene());
	//Director::getInstance()->replaceScene(RoomScene0401::createScene());
}
void RoomScene0401::callObj3Content(Ref * pSender)
{
	UserDefault::getInstance()->setIntegerForKey("Dialog", 9);
	UserDefault::getInstance()->flush();
	
	UserDefault::getInstance()->setIntegerForKey("chip_011", 1);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("chip_014", 1);
	UserDefault::getInstance()->flush();
	//Director::getInstance()->replaceScene(RoomScene0401::createScene());
	UserDefault::getInstance()->setIntegerForKey("item_room0401_1", 1);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(RoomScene0401::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
	
}

void RoomScene0401::callObj4Content(Ref * pSender)
{
	int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1");
	UserDefault::getInstance()->setIntegerForKey("Dialog", 10);
	UserDefault::getInstance()->flush();
	
	wires += 4;
	UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
	UserDefault::getInstance()->flush();
	//Director::getInstance()->replaceScene(RoomScene0401::createScene());
	UserDefault::getInstance()->setIntegerForKey("item_room0401_2", 1);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(RoomScene0401::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
	
}




//일시정지 메뉴 가기
void RoomScene0401::menuCloseCallback(Ref* pSender)
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

void RoomScene0401::nothing(Ref* pSender)
{
}