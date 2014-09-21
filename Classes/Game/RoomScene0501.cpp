#include "RoomScene0501.h"
#include "GameScene5.h"
#include "../mission/Mission1.h"
#include "MenuScene.h"
#include "../Pause/PauseScene.h"
#include "Game/Dialog.h"

USING_NS_CC;

Scene* RoomScene0501::createScene()
{
    auto scene = Scene::create();
    
    auto layer = RoomScene0501::create();

    scene->addChild(layer);

    return scene;
}


bool RoomScene0501::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	UserDefault::getInstance()->setIntegerForKey("LASTPLAYED", 501);
	UserDefault::getInstance()->flush();
	initBG();
	initObj1();//복도로 나가기
	initObj2();//미니게임 Mission1
	initObj3();//대화 이벤트
	initObj4();//전선 획득.
	initExit();

    
    
    return true;
}

void RoomScene0501::initObj1()//복도로 나가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/back.png", "data/game1/object/back_on.png", CC_CALLBACK_1(RoomScene0501::callObj1Content, this));
	item_1->setPosition(480, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene0501::initObj2()//미니게임. Mission1
{
	int r = UserDefault::getInstance()->getIntegerForKey("Mission1_complete") ;
	auto item_1 = MenuItemImage::create("data/game1/object/room0501_0.png", "data/game1/object/room0501_0_on.png", CC_CALLBACK_1(RoomScene0501::callObj2Content, this));
	if(r== 1)
	{
		item_1 = MenuItemImage::create("data/game1/object/room0501_0.png", "data/game1/object/room0501_0.png", CC_CALLBACK_1(RoomScene0501::nothing, this));
	}
	item_1->setPosition(255, 640-300);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene0501::initObj3()//대화이벤트.
{

	auto item_1 = MenuItemImage::create("data/game1/object/room0501_0.png", "data/game1/object/room0501_0_on.png", CC_CALLBACK_1(RoomScene0501::callObj3Content, this));
	item_1->setPosition(565, 640-380);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene0501::initObj4()//전선을 얻는다.
{
	int r = UserDefault::getInstance()->getIntegerForKey("item_room0501_1") ;
	auto item_1 = MenuItemImage::create("data/game1/object/room0501_1.png", "data/game1/object/room0501_1_on.png", CC_CALLBACK_1(RoomScene0501::callObj4Content, this));
	if(r== 1)
	{
		item_1 = MenuItemImage::create("data/game1/object/room0501_1.png", "data/game1/object/room0501_1.png", CC_CALLBACK_1(RoomScene0501::nothing, this));
	}
	item_1->setPosition(875, 640-580);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}


void RoomScene0501::initExit()
{
 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(RoomScene0501::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void RoomScene0501::initBG()
{
//	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("data/game1/bg5-1.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

}

//복도로 나가기
void RoomScene0501::callObj1Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene5::createScene());
}

void RoomScene0501::callObj2Content(Ref * pSender)
{
	//Director::getInstance()->replaceScene(RoomScene0501::createScene());
	Director::getInstance()->replaceScene(Mission1::createScene());
	//Director::getInstance()->replaceScene(RoomScene0501::createScene());
}
void RoomScene0501::callObj3Content(Ref * pSender)
{
	UserDefault::getInstance()->setIntegerForKey("Dialog", 14);
	UserDefault::getInstance()->flush();
	
	Director::getInstance()->replaceScene(RoomScene0501::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
	
}

void RoomScene0501::callObj4Content(Ref * pSender)
{
	int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1");
	UserDefault::getInstance()->setIntegerForKey("Dialog", 15);
	UserDefault::getInstance()->flush();
	
	wires += 5;
	UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
	UserDefault::getInstance()->flush();
	//Director::getInstance()->replaceScene(RoomScene0501::createScene());
	UserDefault::getInstance()->setIntegerForKey("item_room0501_1", 1);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(RoomScene0501::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
	
}




//일시정지 메뉴 가기
void RoomScene0501::menuCloseCallback(Ref* pSender)
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

void RoomScene0501::nothing(Ref* pSender)
{
}