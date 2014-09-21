#include "Mission1.h"
#include "MissionDialog.h"
#include "MenuScene.h"
#include "KoreanUTF8.h"
#include "Game/RoomScene0501.h"
USING_NS_CC;

Scene* Mission1::createScene()
{
    auto scene = Scene::create();
    
    auto layer = Mission1::create();

    scene->addChild(layer);

    return scene;
}


bool Mission1::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	srand(time(NULL));
	int ran = rand()%2 + 1;

	if(UserDefault::getInstance()->getIntegerForKey("Mission1") ==0)
	{
		
		UserDefault::getInstance()->setIntegerForKey("Mission1", ran);
		UserDefault::getInstance()->flush();
	}
	else
	{
		ran =UserDefault::getInstance()->getIntegerForKey("Mission1");
	}
	
	//배경 지정.
	int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1");
	//ran = 2;
	auto sprite1_1= Sprite::create("data/game1/mission/1_1.png");
	if (ran == 2)
	{
		sprite1_1 = Sprite::create("data/game1/mission/1_2.png");
		
	}
	sprite1_1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite1_1, 0);

	std::string wires_str = UserDefault::getInstance()->getStringForKey("item_wire1");

	auto label_wire = Label::createWithTTF((UTF8("사용가능한 전선의 수 : ")),"data/fonts/GodoB.ttf",30);
	label_wire->setPosition(Point(615,640-360));
	this->addChild(label_wire);

	auto label_wire_cnt = Label::createWithTTF((UTF8(wires_str.c_str())),"data/fonts/GodoB.ttf",30);
	label_wire_cnt->setPosition(Point(800,640-360));
	this->addChild(label_wire_cnt);

	
	int w1_1 = 393, w1_2 = 163;

	auto item_1 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m01, this));
	if(UserDefault::getInstance()->getIntegerForKey("m01") == 1)
	{
		item_1 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m01, this));
	}
	else if(wires == 0)
	{
		item_1 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_1->setPosition(w1_1, 640-110);
	if(ran == 2)
		item_1->setPosition(w1_2, 640-110);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 

	auto item_2 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m02, this));
	if(UserDefault::getInstance()->getIntegerForKey("m02") == 1)
	{
		item_2 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m02, this));
	}
	else if(wires == 0)
	{
		item_2 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_2->setPosition(w1_1+36, 640-110);
	if(ran == 2)
		item_2->setPosition(w1_2+36, 640-110);
	auto menu_2 = Menu::create(item_2, NULL);
	menu_2->setPosition(Vec2::ZERO);
	this->addChild(menu_2); 

	auto item_3 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m03, this));
	if(UserDefault::getInstance()->getIntegerForKey("m03") == 1)
	{
		item_3 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m03, this));
	}
	else if(wires == 0)
	{
		item_3 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_3->setPosition(w1_1+36+35, 640-110);
	if(ran == 2)
		item_3->setPosition(w1_2+36+35, 640-110);
	auto menu_3 = Menu::create(item_3, NULL);
	menu_3->setPosition(Vec2::ZERO);
	this->addChild(menu_3); 

	auto item_4 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m04, this));
	if(UserDefault::getInstance()->getIntegerForKey("m04") == 1)
	{
		item_4 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m04, this));
	}
	else if(wires == 0)
	{
		item_4 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_4->setPosition(w1_1+36+36+38, 640-110);
	if(ran == 2)
		item_4->setPosition(w1_2+36+36+38, 640-110);
	auto menu_4 = Menu::create(item_4, NULL);
	menu_4->setPosition(Vec2::ZERO);
	this->addChild(menu_4); 


	int w2_1 = 625, w2_2 = 625;

	auto item_5 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m05, this));
	if(UserDefault::getInstance()->getIntegerForKey("m05") == 1)
	{
		item_5 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m05, this));
	}
	else if(wires == 0)
	{
		item_5 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_5->setPosition(w2_1, 640-110);
	if(ran == 2)
		item_5->setPosition(w2_2, 640-110);
	auto menu_5 = Menu::create(item_5, NULL);
	menu_5->setPosition(Vec2::ZERO);
	this->addChild(menu_5); 

	auto item_6 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m06, this));
	if(UserDefault::getInstance()->getIntegerForKey("m06") == 1)
	{
		item_6 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m06, this));
	}
	else if(wires == 0)
	{
		item_6 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_6->setPosition(w2_1+36, 640-110);
	if(ran == 2)
		item_6->setPosition(w2_2+36, 640-110);
	auto menu_6 = Menu::create(item_6, NULL);
	menu_6->setPosition(Vec2::ZERO);
	this->addChild(menu_6); 

	auto item_7 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m07, this));
	if(UserDefault::getInstance()->getIntegerForKey("m07") == 1)
	{
		item_7 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m07, this));
	}
	else if(wires == 0)
	{
		item_7 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_7->setPosition(w2_1+36+35, 640-110);
	if(ran == 2)
		item_7->setPosition(w2_2+36+35, 640-110);
	auto menu_7 = Menu::create(item_7, NULL);
	menu_7->setPosition(Vec2::ZERO);
	this->addChild(menu_7); 

	auto item_8 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m08, this));
	if(UserDefault::getInstance()->getIntegerForKey("m08") == 1)
	{
		item_8 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m08, this));
	}
	else if(wires == 0)
	{
		item_8 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_8->setPosition(w2_1+36+36+38, 640-110);
	if(ran == 2)
		item_8->setPosition(w2_2+36+36+38, 640-110);
	auto menu_8 = Menu::create(item_8, NULL);
	menu_8->setPosition(Vec2::ZERO);
	this->addChild(menu_8); 


	int w3_1 = 163, w3_2 = 393;

	auto item_9 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m09, this));
	if(UserDefault::getInstance()->getIntegerForKey("m09") == 1)
	{
		item_9 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m09, this));
	}
	else if(wires == 0)
	{
		item_9 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_9->setPosition(w3_1, 640-192);
	if(ran == 2)
		item_9->setPosition(w3_2, 640-192);
	auto menu_9 = Menu::create(item_9, NULL);
	menu_9->setPosition(Vec2::ZERO);
	this->addChild(menu_9); 

	auto item_10 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m10, this));
	if(UserDefault::getInstance()->getIntegerForKey("m10") == 1)
	{
		item_10 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m10, this));
	}
	else if(wires == 0)
	{
		item_10 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_10->setPosition(w3_1+36, 640-192);
	if(ran == 2)
		item_10->setPosition(w3_2+36, 640-192);
	auto menu_10 = Menu::create(item_10, NULL);
	menu_10->setPosition(Vec2::ZERO);
	this->addChild(menu_10); 

	auto item_11 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m11, this));
	if(UserDefault::getInstance()->getIntegerForKey("m11") == 1)
	{
		item_11 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m11, this));
	}
	else if(wires == 0)
	{
		item_11 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_11->setPosition(w3_1+36+35, 640-192);
	if(ran == 2)
		item_11->setPosition(w3_2+36+35, 640-192);
	auto menu_11 = Menu::create(item_11, NULL);
	menu_11->setPosition(Vec2::ZERO);
	this->addChild(menu_11); 

	auto item_12 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m12, this));
	if(UserDefault::getInstance()->getIntegerForKey("m12") == 1)
	{
		item_12 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m12, this));
	}
	else if(wires == 0)
	{
		item_12 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_12->setPosition(w3_1+36+36+38, 640-192);
	if(ran == 2)
		item_12->setPosition(w3_2+36+36+38, 640-192);
	auto menu_12 = Menu::create(item_12, NULL);
	menu_12->setPosition(Vec2::ZERO);
	this->addChild(menu_12); 
	

	int w4_1 = 625, w4_2 = 625;

	auto item_13 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m13, this));
	if(UserDefault::getInstance()->getIntegerForKey("m13") == 1)
	{
		item_13 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m13, this));
	}
	else if(wires == 0)
	{
		item_13 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_13->setPosition(w4_1, 640-192);
	if(ran == 2)
		item_13->setPosition(w4_2, 640-192);
	auto menu_13 = Menu::create(item_13, NULL);
	menu_13->setPosition(Vec2::ZERO);
	this->addChild(menu_13); 

	auto item_14 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m14, this));
	if(UserDefault::getInstance()->getIntegerForKey("m14") == 1)
	{
		item_14 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m14, this));
	}
	else if(wires == 0)
	{
		item_14 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_14->setPosition(w4_1+36, 640-192);
	if(ran == 2)
		item_14->setPosition(w4_2+36, 640-192);
	auto menu_14 = Menu::create(item_14, NULL);
	menu_14->setPosition(Vec2::ZERO);
	this->addChild(menu_14); 

	auto item_15 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m15, this));
	if(UserDefault::getInstance()->getIntegerForKey("m15") == 1)
	{
		item_15 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m15, this));
	}
	else if(wires == 0)
	{
		item_15 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_15->setPosition(w4_1+36+35, 640-192);
	if(ran == 2)
		item_15->setPosition(w4_2+36+35, 640-192);
	auto menu_15 = Menu::create(item_15, NULL);
	menu_15->setPosition(Vec2::ZERO);
	this->addChild(menu_15); 

	auto item_16 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire_on.png", CC_CALLBACK_1(Mission1::m16, this));
	if(UserDefault::getInstance()->getIntegerForKey("m16") == 1)
	{
		item_16 = MenuItemImage::create("data/game1/mission/1_wire_on.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::m16, this));
	}
	else if(wires == 0)
	{
		item_16 = MenuItemImage::create("data/game1/mission/1_wire.png",	"data/game1/mission/1_wire.png", CC_CALLBACK_1(Mission1::nothing, this));
	}
	item_16->setPosition(w4_1+36+36+38, 640-192);
	if(ran == 2)
		item_16->setPosition(w4_2+36+36+38, 640-192);
	auto menu_16 = Menu::create(item_16, NULL);
	menu_16->setPosition(Vec2::ZERO);
	this->addChild(menu_16); 

	auto item_on = MenuItemImage::create("data/game1/mission/1_button.png",	"data/game1/mission/1_button_on.png", CC_CALLBACK_1(Mission1::result, this));

	item_on->setPosition(280, 640-365);
	auto menu_on = Menu::create(item_on, NULL);
	menu_on->setPosition(Vec2::ZERO);
	this->addChild(menu_on); 

	initCancel();
    
    return true;
}

void Mission1::initCancel()
{
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(Mission1::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}


void Mission1::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

	Director::getInstance()->replaceScene(RoomScene0501::createScene());
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void Mission1::nothing(Ref* pSender)
{
}

void Mission1::m01(Ref* pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("m01") == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("m01", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m01", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}
void Mission1::m02(Ref* pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("m02") == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("m02", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m02", 1);
		UserDefault::getInstance()->flush();

		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}
void Mission1::m03(Ref* pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("m03") == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("m03", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m03", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}
void Mission1::m04(Ref* pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("m04") == 1)
	{

		UserDefault::getInstance()->setIntegerForKey("m04", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m04", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}

void Mission1::m05(Ref* pSender)
{
		if(UserDefault::getInstance()->getIntegerForKey("m05") == 1)
	{

		UserDefault::getInstance()->setIntegerForKey("m05", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m05", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}
void Mission1::m06(Ref* pSender)
{
		if(UserDefault::getInstance()->getIntegerForKey("m06") == 1)
	{

		UserDefault::getInstance()->setIntegerForKey("m06", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m06", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}
void Mission1::m07(Ref* pSender)
{
		if(UserDefault::getInstance()->getIntegerForKey("m07") == 1)
	{

		UserDefault::getInstance()->setIntegerForKey("m07", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m07", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}
void Mission1::m08(Ref* pSender)
{
		if(UserDefault::getInstance()->getIntegerForKey("m08") == 1)
	{

		UserDefault::getInstance()->setIntegerForKey("m08", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m08", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}

void Mission1::m09(Ref* pSender)
{
		if(UserDefault::getInstance()->getIntegerForKey("m09") == 1)
	{

		UserDefault::getInstance()->setIntegerForKey("m09", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m09", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}
void Mission1::m10(Ref* pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("m10") == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("m10", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();

	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m10", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}
void Mission1::m11(Ref* pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("m11") == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("m11", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();

	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m11", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}
void Mission1::m12(Ref* pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("m12") == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("m12", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m12", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}

void Mission1::m13(Ref* pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("m13") == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("m13", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m13", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}
void Mission1::m14(Ref* pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("m14") == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("m14", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m14", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}
void Mission1::m15(Ref* pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("m15") == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("m15", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();

	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m15", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}
void Mission1::m16(Ref* pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("m16") == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("m16", 0);
		UserDefault::getInstance()->flush();
		
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") + 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("m16", 1);
		UserDefault::getInstance()->flush();
		int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1") - 1;
		UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
		UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission1::createScene());
}

void Mission1::result(Ref* pSender)
{
	int a[16];
	a[0] = (UserDefault::getInstance()->getIntegerForKey("m01"));
	a[1] = (UserDefault::getInstance()->getIntegerForKey("m02"));
	a[2] = (UserDefault::getInstance()->getIntegerForKey("m03"));
	a[3] = (UserDefault::getInstance()->getIntegerForKey("m04"));

	a[4] = (UserDefault::getInstance()->getIntegerForKey("m05"));
	a[5] = (UserDefault::getInstance()->getIntegerForKey("m06"));
	a[6] = (UserDefault::getInstance()->getIntegerForKey("m07"));
	a[7] = (UserDefault::getInstance()->getIntegerForKey("m08"));

	a[8] = (UserDefault::getInstance()->getIntegerForKey("m09"));
	a[9] = (UserDefault::getInstance()->getIntegerForKey("m10"));
	a[10] = (UserDefault::getInstance()->getIntegerForKey("m11"));
	a[11] = (UserDefault::getInstance()->getIntegerForKey("m12"));

	a[12] = (UserDefault::getInstance()->getIntegerForKey("m13"));
	a[13] = (UserDefault::getInstance()->getIntegerForKey("m14"));
	a[14] = (UserDefault::getInstance()->getIntegerForKey("m15"));
	a[15] = (UserDefault::getInstance()->getIntegerForKey("m16"));

	int i;
	if(UserDefault::getInstance()->getIntegerForKey("Mission1") == 1)
	{
		int b[16] = {1,1,1,0,1,1,0,0,1,1,0,0,1,0,0,0};
		for ( i = 0 ; i < 16 ; i ++)
		{
			if ( a[i] != b[i])
			{
				break;
			}
		}
		if(i != 16)
		{
			UserDefault::getInstance()->setIntegerForKey("mission_result", 2);
			UserDefault::getInstance()->flush();
			Director::getInstance()->replaceScene(RoomScene0501::createScene());
			Director::getInstance()->pushScene(MissionDialog::createScene());
		}
		else
		{
			UserDefault::getInstance()->setIntegerForKey("mission_result", 3);
			UserDefault::getInstance()->flush();
			UserDefault::getInstance()->setIntegerForKey("Mission1_complete", 1);
			UserDefault::getInstance()->flush();
			Director::getInstance()->replaceScene(RoomScene0501::createScene());
			Director::getInstance()->pushScene(MissionDialog::createScene());
			
		}
	}
	else if(UserDefault::getInstance()->getIntegerForKey("Mission1") == 2)
	{
		int b[16] = {1,0,0,0,0,1,1,0,1,1,0,0,0,1,0,0};
		for ( i = 0 ; i < 16 ; i ++)
		{
			if ( a[i] != b[i])
			{
				break;
			}
		}
		if(i != 16)
		{
			UserDefault::getInstance()->setIntegerForKey("mission_result", 2);
			UserDefault::getInstance()->flush();
			Director::getInstance()->replaceScene(RoomScene0501::createScene());
			Director::getInstance()->pushScene(MissionDialog::createScene());
		}
		else
		{
			UserDefault::getInstance()->setIntegerForKey("mission_result", 3);
			UserDefault::getInstance()->flush();
			UserDefault::getInstance()->setIntegerForKey("Mission1_complete", 1);
			UserDefault::getInstance()->flush();
			Director::getInstance()->replaceScene(RoomScene0501::createScene());
			Director::getInstance()->pushScene(MissionDialog::createScene());
			
		}
	}

}