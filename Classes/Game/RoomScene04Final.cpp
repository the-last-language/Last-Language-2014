#include "RoomScene04Final.h"
#include "GameScene4.h"
#include "../mission/Mission2.h"
#include "MenuScene.h"
#include "../Pause/PauseScene.h"
#include "Game/Dialog.h"

USING_NS_CC;

Scene* RoomScene04Final::createScene()
{
    auto scene = Scene::create();
    
    auto layer = RoomScene04Final::create();

    scene->addChild(layer);

    return scene;
}


bool RoomScene04Final::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	UserDefault::getInstance()->setIntegerForKey("LASTPLAYED", 403);
	UserDefault::getInstance()->flush();
	initBG();
	initObj1();//복도로 나가기
	initObj2();//미니게임
	initObj3();//대화1
	initObj4();//대화2
	initExit();

    
    
    return true;
}

void RoomScene04Final::initObj1()//복도로 나가기
{
	auto item_1 = MenuItemImage::create("data/game1/object/back.png", "data/game1/object/back_on.png", CC_CALLBACK_1(RoomScene04Final::callObj1Content, this));
	item_1->setPosition(480, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene04Final::initObj2()//미니게임. Mission2
{
	int r = UserDefault::getInstance()->getIntegerForKey("Mission2_complete") ;
	auto item_1 = MenuItemImage::create("data/game1/object/room04Final_0.png", "data/game1/object/room04Final_0_on.png", CC_CALLBACK_1(RoomScene04Final::callObj2Content, this));
	if(r== 1)
	{
		item_1 = MenuItemImage::create("data/game1/object/room04Final_0.png", "data/game1/object/room04Final_0.png", CC_CALLBACK_1(RoomScene04Final::nothing, this));
	}
	item_1->setPosition(125, 640-305);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene04Final::initObj3()//대화1.
{

	auto item_1 = MenuItemImage::create("data/game1/object/room04Final_1.png", "data/game1/object/room04Final_1_on.png", CC_CALLBACK_1(RoomScene04Final::callObj3Content, this));

	item_1->setPosition(230, 640-280);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void RoomScene04Final::initObj4()//대화2.
{

	auto item_1 = MenuItemImage::create("data/game1/object/room04Final_2.png", "data/game1/object/room04Final_2_on.png", CC_CALLBACK_1(RoomScene04Final::callObj4Content, this));
	item_1->setPosition(335, 640-395);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}


void RoomScene04Final::initExit()
{
 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(RoomScene04Final::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void RoomScene04Final::initBG()
{
//	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("data/game1/bg4-3.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

}

//복도로 나가기
void RoomScene04Final::callObj1Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene4::createScene());
}

void RoomScene04Final::callObj2Content(Ref * pSender)
{
	//Director::getInstance()->replaceScene(RoomScene04Final::createScene());
	Director::getInstance()->replaceScene(Mission2::createScene());
	//Director::getInstance()->replaceScene(RoomScene04Final::createScene());
}
void RoomScene04Final::callObj3Content(Ref * pSender)
{
	UserDefault::getInstance()->setIntegerForKey("Dialog", 21);
	UserDefault::getInstance()->flush();

	Director::getInstance()->pushScene(Dialog::createScene());
	
}

void RoomScene04Final::callObj4Content(Ref * pSender)
{

	UserDefault::getInstance()->setIntegerForKey("Dialog", 22);
	UserDefault::getInstance()->flush();

	Director::getInstance()->pushScene(Dialog::createScene());
	
}




//일시정지 메뉴 가기
void RoomScene04Final::menuCloseCallback(Ref* pSender)
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

void RoomScene04Final::nothing(Ref* pSender)
{
}