#include "RoomScene0502.h"
#include "GameScene5.h"
#include "../mission/Mission1.h"
#include "MenuScene.h"
#include "../Pause/PauseScene.h"
#include "Game/Dialog.h"

USING_NS_CC;

Scene* RoomScene0502::createScene()
{
    auto scene = Scene::create();
    
    auto layer = RoomScene0502::create();

    scene->addChild(layer);

    return scene;
}


bool RoomScene0502::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	UserDefault::getInstance()->setIntegerForKey("LASTPLAYED", 502);
	UserDefault::getInstance()->flush();
	initBG();
	initObj1();//복도로 나가기
	initObj2();//미니게임 Mission1
	initObj3();//대화 이벤트
	initObj4();//전선 획득.
	initExit();

    
    
    return true;
}

void RoomScene0502::initObj1()//복도로 나가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/back.png", "data/game1/object/back_on.png", CC_CALLBACK_1(RoomScene0502::callObj1Content, this));
	item_1->setPosition(480, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene0502::initObj2()//사물함
{
	int r = UserDefault::getInstance()->getIntegerForKey("item_room0502_0") ;
	auto item_1 = MenuItemImage::create("data/game1/object/room0502_0.png", "data/game1/object/room0502_0_on.png", CC_CALLBACK_1(RoomScene0502::callObj2Content, this));
	if(r== 1)
	{
		item_1 = MenuItemImage::create("data/game1/object/room0502_0.png", "data/game1/object/room0502_0.png", CC_CALLBACK_1(RoomScene0502::nothing, this));
	}
	item_1->setPosition(45, 640-380);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene0502::initObj3()//대화이벤트.
{

	auto item_1 = MenuItemImage::create("data/game1/object/room0502_1.png", "data/game1/object/room0502_1_on.png", CC_CALLBACK_1(RoomScene0502::callObj3Content, this));
	item_1->setPosition(490, 640-430);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene0502::initObj4()//칩을 얻다..
{
	int r = UserDefault::getInstance()->getIntegerForKey("item_room0502_1") ;
	auto item_1 = MenuItemImage::create("data/game1/object/room0502_2.png", "data/game1/object/room0502_2_on.png", CC_CALLBACK_1(RoomScene0502::callObj4Content, this));
	if(r== 1)
	{
		item_1 = MenuItemImage::create("data/game1/object/room0502_2.png", "data/game1/object/room0502_2.png", CC_CALLBACK_1(RoomScene0502::nothing, this));
	}
	item_1->setPosition(860, 640-325);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}


void RoomScene0502::initExit()
{
 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(RoomScene0502::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void RoomScene0502::initBG()
{
//	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("data/game1/bg5-2.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

}

//복도로 나가기
void RoomScene0502::callObj1Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene5::createScene());
}

void RoomScene0502::callObj2Content(Ref * pSender)
{
	UserDefault::getInstance()->setIntegerForKey("Dialog",17);
	UserDefault::getInstance()->flush();
	
	UserDefault::getInstance()->setIntegerForKey("chip_008", 1);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("chip_010", 1);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_room0502_0", 1);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(RoomScene0502::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
}
void RoomScene0502::callObj3Content(Ref * pSender)
{
	UserDefault::getInstance()->setIntegerForKey("Dialog", 18);
	UserDefault::getInstance()->flush();
	
	Director::getInstance()->replaceScene(RoomScene0502::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
	
}

void RoomScene0502::callObj4Content(Ref * pSender)
{
	UserDefault::getInstance()->setIntegerForKey("Dialog",17);
	UserDefault::getInstance()->flush();
	
	UserDefault::getInstance()->setIntegerForKey("chip_013", 1);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("chip_007", 1);
	UserDefault::getInstance()->flush();
	//Director::getInstance()->replaceScene(RoomScene0502::createScene());
	UserDefault::getInstance()->setIntegerForKey("item_room0502_1", 1);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(RoomScene0502::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
	
}




//일시정지 메뉴 가기
void RoomScene0502::menuCloseCallback(Ref* pSender)
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

void RoomScene0502::nothing(Ref* pSender)
{
}