#include "Mission2.h"
#include "MissionDialog.h"
#include "game/RoomScene04Final.h"

USING_NS_CC;

Scene* Mission2::createScene()
{
    auto scene = Scene::create();
    
    auto layer = Mission2::create();

    scene->addChild(layer);

    return scene;
}


bool Mission2::init()
{
	if ( !LayerColor::initWithColor(Color4B(255,255,255,255)) )
    {
        return false;
    }
	
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("data/game1/mission/2_0.png");

	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite, 0);

	int x = 210, y = 300;
	initSlot();
	initItems();
	initCancel();
	initButton();

    return true;
}

void Mission2::nothing(Ref* pSender)
{
	
}

void Mission2::initSlot()
{
	int now1 = UserDefault::getInstance()->getIntegerForKey("slot_01_now");
	int now2 = UserDefault::getInstance()->getIntegerForKey("slot_02_now");
	int now3 = UserDefault::getInstance()->getIntegerForKey("slot_03_now");
	int now4 = UserDefault::getInstance()->getIntegerForKey("slot_04_now");
	int now5 = UserDefault::getInstance()->getIntegerForKey("slot_05_now");
	int now6 = UserDefault::getInstance()->getIntegerForKey("slot_06_now");
	auto item_1 = MenuItemImage::create("data/game1/mission/chips/slot_empty.png",	"data/game1/mission/chips/slot_on.png", CC_CALLBACK_1(Mission2::s01, this));
	switch(now1)
	{
	case 1:
		item_1 = MenuItemImage::create("data/game1/mission/chips/001.png",	"data/game1/mission/chips/001_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 2:
		item_1 = MenuItemImage::create("data/game1/mission/chips/002.png",	"data/game1/mission/chips/002_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 3:
		item_1 = MenuItemImage::create("data/game1/mission/chips/003.png",	"data/game1/mission/chips/003_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 4:
		item_1 = MenuItemImage::create("data/game1/mission/chips/004.png",	"data/game1/mission/chips/004_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 5:
		item_1 = MenuItemImage::create("data/game1/mission/chips/005.png",	"data/game1/mission/chips/005_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 6:
		item_1 = MenuItemImage::create("data/game1/mission/chips/006.png",	"data/game1/mission/chips/006_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 7:
		item_1 = MenuItemImage::create("data/game1/mission/chips/007.png",	"data/game1/mission/chips/007_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 8:
		item_1 = MenuItemImage::create("data/game1/mission/chips/008.png",	"data/game1/mission/chips/008_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 9:
		item_1 = MenuItemImage::create("data/game1/mission/chips/009.png",	"data/game1/mission/chips/009_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 10:
		item_1 = MenuItemImage::create("data/game1/mission/chips/010.png",	"data/game1/mission/chips/010_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 11:
		item_1 = MenuItemImage::create("data/game1/mission/chips/011.png",	"data/game1/mission/chips/011_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 12:
		item_1 = MenuItemImage::create("data/game1/mission/chips/012.png",	"data/game1/mission/chips/012_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 13:
		item_1 = MenuItemImage::create("data/game1/mission/chips/013.png",	"data/game1/mission/chips/013_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	case 14:
		item_1 = MenuItemImage::create("data/game1/mission/chips/014.png",	"data/game1/mission/chips/014_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	default:
		item_1 = MenuItemImage::create("data/game1/mission/chips/slot_empty.png",	"data/game1/mission/chips/slot_on.png", CC_CALLBACK_1(Mission2::s01, this));
		break;
	}
	item_1->setPosition(277, 640-86);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 

	auto item_2 = MenuItemImage::create("data/game1/mission/chips/slot_empty.png",	"data/game1/mission/chips/slot_on.png", CC_CALLBACK_1(Mission2::s02, this));
	switch(now2)
	{
	case 1:
		item_2 = MenuItemImage::create("data/game1/mission/chips/001.png",	"data/game1/mission/chips/001_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 2:
		item_2 = MenuItemImage::create("data/game1/mission/chips/002.png",	"data/game1/mission/chips/002_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 3:
		item_2 = MenuItemImage::create("data/game1/mission/chips/003.png",	"data/game1/mission/chips/003_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 4:
		item_2 = MenuItemImage::create("data/game1/mission/chips/004.png",	"data/game1/mission/chips/004_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 5:
		item_2 = MenuItemImage::create("data/game1/mission/chips/005.png",	"data/game1/mission/chips/005_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 6:
		item_2 = MenuItemImage::create("data/game1/mission/chips/006.png",	"data/game1/mission/chips/006_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 7:
		item_2 = MenuItemImage::create("data/game1/mission/chips/007.png",	"data/game1/mission/chips/007_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 8:
		item_2 = MenuItemImage::create("data/game1/mission/chips/008.png",	"data/game1/mission/chips/008_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 9:
		item_2 = MenuItemImage::create("data/game1/mission/chips/009.png",	"data/game1/mission/chips/009_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 10:
		item_2 = MenuItemImage::create("data/game1/mission/chips/010.png",	"data/game1/mission/chips/010_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 11:
		item_2 = MenuItemImage::create("data/game1/mission/chips/011.png",	"data/game1/mission/chips/011_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 12:
		item_2 = MenuItemImage::create("data/game1/mission/chips/012.png",	"data/game1/mission/chips/012_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 13:
		item_2 = MenuItemImage::create("data/game1/mission/chips/013.png",	"data/game1/mission/chips/013_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	case 14:
		item_2 = MenuItemImage::create("data/game1/mission/chips/014.png",	"data/game1/mission/chips/014_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	default:
		item_2 = MenuItemImage::create("data/game1/mission/chips/slot_empty.png",	"data/game1/mission/chips/slot_on.png", CC_CALLBACK_1(Mission2::s02, this));
		break;
	}
	item_2->setPosition(476, 640-86);
	auto menu_2 = Menu::create(item_2, NULL);
	menu_2->setPosition(Vec2::ZERO);
	this->addChild(menu_2); 

	auto item_3 = MenuItemImage::create("data/game1/mission/chips/slot_empty.png",	"data/game1/mission/chips/slot_on.png", CC_CALLBACK_1(Mission2::s03, this));
	switch(now3)
	{
	case 1:
		item_3 = MenuItemImage::create("data/game1/mission/chips/001.png",	"data/game1/mission/chips/001_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 2:
		item_3 = MenuItemImage::create("data/game1/mission/chips/002.png",	"data/game1/mission/chips/002_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 3:
		item_3 = MenuItemImage::create("data/game1/mission/chips/003.png",	"data/game1/mission/chips/003_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 4:
		item_3 = MenuItemImage::create("data/game1/mission/chips/004.png",	"data/game1/mission/chips/004_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 5:
		item_3 = MenuItemImage::create("data/game1/mission/chips/005.png",	"data/game1/mission/chips/005_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 6:
		item_3 = MenuItemImage::create("data/game1/mission/chips/006.png",	"data/game1/mission/chips/006_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 7:
		item_3 = MenuItemImage::create("data/game1/mission/chips/007.png",	"data/game1/mission/chips/007_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 8:
		item_3 = MenuItemImage::create("data/game1/mission/chips/008.png",	"data/game1/mission/chips/008_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 9:
		item_3 = MenuItemImage::create("data/game1/mission/chips/009.png",	"data/game1/mission/chips/009_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 10:
		item_3 = MenuItemImage::create("data/game1/mission/chips/010.png",	"data/game1/mission/chips/010_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 11:
		item_3 = MenuItemImage::create("data/game1/mission/chips/011.png",	"data/game1/mission/chips/011_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 12:
		item_3 = MenuItemImage::create("data/game1/mission/chips/012.png",	"data/game1/mission/chips/012_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 13:
		item_3 = MenuItemImage::create("data/game1/mission/chips/013.png",	"data/game1/mission/chips/013_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	case 14:
		item_3 = MenuItemImage::create("data/game1/mission/chips/014.png",	"data/game1/mission/chips/014_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	default:
		item_3 = MenuItemImage::create("data/game1/mission/chips/slot_empty.png",	"data/game1/mission/chips/slot_on.png", CC_CALLBACK_1(Mission2::s03, this));
		break;
	}
	item_3->setPosition(690, 640-86);
	auto menu_3 = Menu::create(item_3, NULL);
	menu_3->setPosition(Vec2::ZERO);
	this->addChild(menu_3); 

	auto item_4 = MenuItemImage::create("data/game1/mission/chips/slot_empty.png",	"data/game1/mission/chips/slot_on.png", CC_CALLBACK_1(Mission2::s04, this));
	switch(now4)
	{
	case 1:
		item_4 = MenuItemImage::create("data/game1/mission/chips/001.png",	"data/game1/mission/chips/001_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 2:
		item_4 = MenuItemImage::create("data/game1/mission/chips/002.png",	"data/game1/mission/chips/002_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 3:
		item_4 = MenuItemImage::create("data/game1/mission/chips/003.png",	"data/game1/mission/chips/003_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 4:
		item_4 = MenuItemImage::create("data/game1/mission/chips/004.png",	"data/game1/mission/chips/004_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 5:
		item_4 = MenuItemImage::create("data/game1/mission/chips/005.png",	"data/game1/mission/chips/005_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 6:
		item_4 = MenuItemImage::create("data/game1/mission/chips/006.png",	"data/game1/mission/chips/006_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 7:
		item_4 = MenuItemImage::create("data/game1/mission/chips/007.png",	"data/game1/mission/chips/007_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 8:
		item_4 = MenuItemImage::create("data/game1/mission/chips/008.png",	"data/game1/mission/chips/008_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 9:
		item_4 = MenuItemImage::create("data/game1/mission/chips/009.png",	"data/game1/mission/chips/009_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 10:
		item_4 = MenuItemImage::create("data/game1/mission/chips/010.png",	"data/game1/mission/chips/010_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 11:
		item_4 = MenuItemImage::create("data/game1/mission/chips/011.png",	"data/game1/mission/chips/011_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 12:
		item_4 = MenuItemImage::create("data/game1/mission/chips/012.png",	"data/game1/mission/chips/012_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 13:
		item_4 = MenuItemImage::create("data/game1/mission/chips/013.png",	"data/game1/mission/chips/013_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	case 14:
		item_4 = MenuItemImage::create("data/game1/mission/chips/014.png",	"data/game1/mission/chips/014_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	default:
		item_4 = MenuItemImage::create("data/game1/mission/chips/slot_empty.png",	"data/game1/mission/chips/slot_on.png", CC_CALLBACK_1(Mission2::s04, this));
		break;
	}
	item_4->setPosition(277, 640-155);
	auto menu_4 = Menu::create(item_4, NULL);
	menu_4->setPosition(Vec2::ZERO);
	this->addChild(menu_4); 

	auto item_5 = MenuItemImage::create("data/game1/mission/chips/slot_empty.png",	"data/game1/mission/chips/slot_on.png", CC_CALLBACK_1(Mission2::s05, this));
	switch(now5)
	{
	case 1:
		item_5 = MenuItemImage::create("data/game1/mission/chips/001.png",	"data/game1/mission/chips/001_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 2:
		item_5 = MenuItemImage::create("data/game1/mission/chips/002.png",	"data/game1/mission/chips/002_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 3:
		item_5 = MenuItemImage::create("data/game1/mission/chips/003.png",	"data/game1/mission/chips/003_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 4:
		item_5 = MenuItemImage::create("data/game1/mission/chips/004.png",	"data/game1/mission/chips/004_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 5:
		item_5 = MenuItemImage::create("data/game1/mission/chips/005.png",	"data/game1/mission/chips/005_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 6:
		item_5 = MenuItemImage::create("data/game1/mission/chips/006.png",	"data/game1/mission/chips/006_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 7:
		item_5 = MenuItemImage::create("data/game1/mission/chips/007.png",	"data/game1/mission/chips/007_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 8:
		item_5 = MenuItemImage::create("data/game1/mission/chips/008.png",	"data/game1/mission/chips/008_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 9:
		item_5 = MenuItemImage::create("data/game1/mission/chips/009.png",	"data/game1/mission/chips/009_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 10:
		item_5 = MenuItemImage::create("data/game1/mission/chips/010.png",	"data/game1/mission/chips/010_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 11:
		item_5 = MenuItemImage::create("data/game1/mission/chips/011.png",	"data/game1/mission/chips/011_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 12:
		item_5 = MenuItemImage::create("data/game1/mission/chips/012.png",	"data/game1/mission/chips/012_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 13:
		item_5 = MenuItemImage::create("data/game1/mission/chips/013.png",	"data/game1/mission/chips/013_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	case 14:
		item_5 = MenuItemImage::create("data/game1/mission/chips/014.png",	"data/game1/mission/chips/014_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	default:
		item_5 = MenuItemImage::create("data/game1/mission/chips/slot_empty.png",	"data/game1/mission/chips/slot_on.png", CC_CALLBACK_1(Mission2::s05, this));
		break;
	}
	item_5->setPosition(476, 640-155);
	auto menu_5 = Menu::create(item_5, NULL);
	menu_5->setPosition(Vec2::ZERO);
	this->addChild(menu_5); 

	auto item_6 = MenuItemImage::create("data/game1/mission/chips/slot_empty.png",	"data/game1/mission/chips/slot_on.png", CC_CALLBACK_1(Mission2::s06, this));
	switch(now6)
	{
	case 1:
		item_6 = MenuItemImage::create("data/game1/mission/chips/001.png",	"data/game1/mission/chips/001_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 2:
		item_6 = MenuItemImage::create("data/game1/mission/chips/002.png",	"data/game1/mission/chips/002_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 3:
		item_6 = MenuItemImage::create("data/game1/mission/chips/003.png",	"data/game1/mission/chips/003_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 4:
		item_6 = MenuItemImage::create("data/game1/mission/chips/004.png",	"data/game1/mission/chips/004_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 5:
		item_6 = MenuItemImage::create("data/game1/mission/chips/005.png",	"data/game1/mission/chips/005_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 6:
		item_6 = MenuItemImage::create("data/game1/mission/chips/006.png",	"data/game1/mission/chips/006_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 7:
		item_6 = MenuItemImage::create("data/game1/mission/chips/007.png",	"data/game1/mission/chips/007_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 8:
		item_6 = MenuItemImage::create("data/game1/mission/chips/008.png",	"data/game1/mission/chips/008_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 9:
		item_6 = MenuItemImage::create("data/game1/mission/chips/009.png",	"data/game1/mission/chips/009_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 10:
		item_6 = MenuItemImage::create("data/game1/mission/chips/010.png",	"data/game1/mission/chips/010_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 11:
		item_6 = MenuItemImage::create("data/game1/mission/chips/011.png",	"data/game1/mission/chips/011_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 12:
		item_6 = MenuItemImage::create("data/game1/mission/chips/012.png",	"data/game1/mission/chips/012_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 13:
		item_6 = MenuItemImage::create("data/game1/mission/chips/013.png",	"data/game1/mission/chips/013_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	case 14:
		item_6 = MenuItemImage::create("data/game1/mission/chips/014.png",	"data/game1/mission/chips/014_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	default:
		item_2 = MenuItemImage::create("data/game1/mission/chips/slot_empty.png",	"data/game1/mission/chips/slot_on.png", CC_CALLBACK_1(Mission2::s06, this));
		break;
	}
	item_6->setPosition(690, 640-155);
	auto menu_6 = Menu::create(item_6, NULL);
	menu_6->setPosition(Vec2::ZERO);
	this->addChild(menu_6); 
}

void Mission2::initItems()
{
	auto item_1 = MenuItemImage::create("data/game1/mission/chips/001.png",	"data/game1/mission/chips/001_on.png", CC_CALLBACK_1(Mission2::c01, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_001") == 0)
	{
			item_1 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_001") == 2)
	{
			item_1 = MenuItemImage::create("data/game1/mission/chips/001_on.png",	"data/game1/mission/chips/001.png", CC_CALLBACK_1(Mission2::c01, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_001") == 3)
	{
			item_1 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_1->setPosition(160, 640-300);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 

	auto item_2 = MenuItemImage::create("data/game1/mission/chips/002.png",	"data/game1/mission/chips/002_on.png", CC_CALLBACK_1(Mission2::c02, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_002") == 0)
	{
			item_2 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_002") == 2)
	{
			item_2 = MenuItemImage::create("data/game1/mission/chips/002_on.png",	"data/game1/mission/chips/002.png", CC_CALLBACK_1(Mission2::c02, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_002") == 3)
	{
			item_2 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_2->setPosition(450, 640-300);
	auto menu_2 = Menu::create(item_2, NULL);
	menu_2->setPosition(Vec2::ZERO);
	this->addChild(menu_2); 

	auto item_3 = MenuItemImage::create("data/game1/mission/chips/003.png",	"data/game1/mission/chips/003_on.png", CC_CALLBACK_1(Mission2::c03, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_003") == 0)
	{
			item_3 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_003") == 2)
	{
			item_3 = MenuItemImage::create("data/game1/mission/chips/003_on.png",	"data/game1/mission/chips/003.png", CC_CALLBACK_1(Mission2::c03, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_003") == 3)
	{
		item_3 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_3->setPosition(160, 640-340);
	auto menu_3 = Menu::create(item_3, NULL);
	menu_3->setPosition(Vec2::ZERO);
	this->addChild(menu_3); 

	auto item_4 = MenuItemImage::create("data/game1/mission/chips/004.png",	"data/game1/mission/chips/004_on.png", CC_CALLBACK_1(Mission2::c04, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_004") == 0)
	{
			item_4 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_004") == 2)
	{
			item_4 = MenuItemImage::create("data/game1/mission/chips/004_on.png",	"data/game1/mission/chips/004.png", CC_CALLBACK_1(Mission2::c04, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_004") == 3)
	{
			item_4 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_4->setPosition(450, 640-340);
	auto menu_4 = Menu::create(item_4, NULL);
	menu_4->setPosition(Vec2::ZERO);
	this->addChild(menu_4); 

	auto item_5 = MenuItemImage::create("data/game1/mission/chips/005.png",	"data/game1/mission/chips/005_on.png", CC_CALLBACK_1(Mission2::c05, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_005") == 0)
	{
			item_5 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_005") == 2)
	{
			item_5 = MenuItemImage::create("data/game1/mission/chips/005_on.png",	"data/game1/mission/chips/005.png", CC_CALLBACK_1(Mission2::c05, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_005") == 3)
	{
			item_5 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_5->setPosition(160, 640-380);
	auto menu_5 = Menu::create(item_5, NULL);
	menu_5->setPosition(Vec2::ZERO);
	this->addChild(menu_5); 

	auto item_6 = MenuItemImage::create("data/game1/mission/chips/006.png",	"data/game1/mission/chips/006_on.png", CC_CALLBACK_1(Mission2::c06, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_006") == 0)
	{
			item_6 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_006") == 2)
	{
			item_6 = MenuItemImage::create("data/game1/mission/chips/006_on.png",	"data/game1/mission/chips/006.png", CC_CALLBACK_1(Mission2::c06, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_006") == 3)
	{
			item_6 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_6->setPosition(450, 640-380);
	auto menu_6 = Menu::create(item_6, NULL);
	menu_6->setPosition(Vec2::ZERO);
	this->addChild(menu_6); 

	auto item_7 = MenuItemImage::create("data/game1/mission/chips/007.png",	"data/game1/mission/chips/007_on.png", CC_CALLBACK_1(Mission2::c07, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_007") == 0)
	{
			item_7 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_007") == 2)
	{
			item_7 = MenuItemImage::create("data/game1/mission/chips/007_on.png",	"data/game1/mission/chips/007.png", CC_CALLBACK_1(Mission2::c07, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_007") == 3)
	{
			item_7 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_7->setPosition(160, 640-420);
	auto menu_7 = Menu::create(item_7, NULL);
	menu_7->setPosition(Vec2::ZERO);
	this->addChild(menu_7); 

	auto item_8 = MenuItemImage::create("data/game1/mission/chips/008.png",	"data/game1/mission/chips/008_on.png", CC_CALLBACK_1(Mission2::c08, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_008") == 0)
	{
			item_8 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_008") == 2)
	{
			item_8 = MenuItemImage::create("data/game1/mission/chips/008_on.png",	"data/game1/mission/chips/008.png", CC_CALLBACK_1(Mission2::c08, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_008") == 3)
	{
			item_8 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_8->setPosition(450, 640-420);
	auto menu_8 = Menu::create(item_8, NULL);
	menu_8->setPosition(Vec2::ZERO);
	this->addChild(menu_8);

	auto item_9 = MenuItemImage::create("data/game1/mission/chips/009.png",	"data/game1/mission/chips/009_on.png", CC_CALLBACK_1(Mission2::c09, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_009") == 0)
	{
			item_9 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_009") == 2)
	{
			item_9 = MenuItemImage::create("data/game1/mission/chips/009_on.png",	"data/game1/mission/chips/009.png", CC_CALLBACK_1(Mission2::c09, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_009") == 3)
	{
			item_9 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_9->setPosition(160, 640-460);
	auto menu_9 = Menu::create(item_9, NULL);
	menu_9->setPosition(Vec2::ZERO);
	this->addChild(menu_9); 

	auto item_10 = MenuItemImage::create("data/game1/mission/chips/010.png",	"data/game1/mission/chips/010_on.png", CC_CALLBACK_1(Mission2::c10, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_010") == 0)
	{
			item_10 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_010") == 2)
	{
			item_10 = MenuItemImage::create("data/game1/mission/chips/010_on.png",	"data/game1/mission/chips/010.png", CC_CALLBACK_1(Mission2::c10, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_010") == 3)
	{
		item_10 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_10->setPosition(450, 640-460);
	auto menu_10 = Menu::create(item_10, NULL);
	menu_10->setPosition(Vec2::ZERO);
	this->addChild(menu_10); 

	auto item_11 = MenuItemImage::create("data/game1/mission/chips/011.png",	"data/game1/mission/chips/011_on.png", CC_CALLBACK_1(Mission2::c11, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_011") == 0)
	{
			item_11 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_011") == 2)
	{
			item_11 = MenuItemImage::create("data/game1/mission/chips/011_on.png",	"data/game1/mission/chips/011.png", CC_CALLBACK_1(Mission2::c11, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_011") == 3)
	{
		item_11 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_11->setPosition(160, 640-500);
	auto menu_11 = Menu::create(item_11, NULL);
	menu_11->setPosition(Vec2::ZERO);
	this->addChild(menu_11); 

	auto item_12 = MenuItemImage::create("data/game1/mission/chips/012.png",	"data/game1/mission/chips/012_on.png", CC_CALLBACK_1(Mission2::c12, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_012") == 0)
	{
			item_12 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_012") == 2)
	{
			item_12 = MenuItemImage::create("data/game1/mission/chips/012_on.png",	"data/game1/mission/chips/012.png", CC_CALLBACK_1(Mission2::c12, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_012") == 3)
	{
		item_12 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_12->setPosition(450, 640-500);
	auto menu_12 = Menu::create(item_12, NULL);
	menu_12->setPosition(Vec2::ZERO);
	this->addChild(menu_12); 

	auto item_13 = MenuItemImage::create("data/game1/mission/chips/013.png",	"data/game1/mission/chips/013_on.png", CC_CALLBACK_1(Mission2::c13, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_013") == 0)
	{
			item_13 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_013") == 2)
	{
			item_13 = MenuItemImage::create("data/game1/mission/chips/013_on.png",	"data/game1/mission/chips/013.png", CC_CALLBACK_1(Mission2::c13, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_013") == 3)
	{
			item_13 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_13->setPosition(160, 640-540);
	auto menu_13 = Menu::create(item_13, NULL);
	menu_13->setPosition(Vec2::ZERO);
	this->addChild(menu_13); 

	auto item_14 = MenuItemImage::create("data/game1/mission/chips/014.png",	"data/game1/mission/chips/014_on.png", CC_CALLBACK_1(Mission2::c14, this));
	if(UserDefault::getInstance()->getIntegerForKey("chip_014") == 0)
	{
			item_14 = MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_014") == 2)
	{
			item_14 = MenuItemImage::create("data/game1/mission/chips/014_on.png",	"data/game1/mission/chips/014.png", CC_CALLBACK_1(Mission2::c14, this));
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_014") == 3)
	{
			item_14 =  MenuItemImage::create("",	"", CC_CALLBACK_1(Mission2::nothing, this));
	}
	item_14->setPosition(450, 640-540);
	auto menu_14 = Menu::create(item_14, NULL);
	menu_14->setPosition(Vec2::ZERO);
	this->addChild(menu_14); 
}

void Mission2::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
	offOtherChip();
	UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(RoomScene04Final::createScene());
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void Mission2::initCancel()
{
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(Mission2::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void Mission2::initButton()
{

	auto closeItem = MenuItemImage::create(
                                           "data/game1/mission/chips/button_off.png",
                                           "data/game1/mission/chips/button_on.png",
										   CC_CALLBACK_1(Mission2::b01, this));
    
	closeItem->setPosition(780, 640-320);
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void Mission2::c01(cocos2d::Ref* pSender)
{
	
	if(UserDefault::getInstance()->getIntegerForKey("chip_001") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_001", 2);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 1);
	UserDefault::getInstance()->flush();
	
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_001") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_001", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c02(cocos2d::Ref* pSender)
{
	
	if(UserDefault::getInstance()->getIntegerForKey("chip_002") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 2);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_002", 2);
		UserDefault::getInstance()->flush();
		
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_002") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_002", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c03(cocos2d::Ref* pSender)
{

	if(UserDefault::getInstance()->getIntegerForKey("chip_003") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 3);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_003", 2);
		UserDefault::getInstance()->flush();
		
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_003") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_003", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c04(cocos2d::Ref* pSender)
{
	if(UserDefault::getInstance()->getIntegerForKey("chip_004") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 4);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_004", 2);
		UserDefault::getInstance()->flush();
		
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_004") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_004", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c05(cocos2d::Ref* pSender)
{
	
	if(UserDefault::getInstance()->getIntegerForKey("chip_005") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 5);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_005", 2);
		UserDefault::getInstance()->flush();
		
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_005") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_005", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c06(cocos2d::Ref* pSender)
{
	
	if(UserDefault::getInstance()->getIntegerForKey("chip_006") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 6);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_006", 2);
		UserDefault::getInstance()->flush();
		
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_006") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_006", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c07(cocos2d::Ref* pSender)
{
	
	if(UserDefault::getInstance()->getIntegerForKey("chip_007") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 7);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_007", 2);
		UserDefault::getInstance()->flush();
		
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_007") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_007", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c08(cocos2d::Ref* pSender)
{
	
	if(UserDefault::getInstance()->getIntegerForKey("chip_008") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 8);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_008", 2);
		UserDefault::getInstance()->flush();
		
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_008") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_008", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c09(cocos2d::Ref* pSender)
{
	
	if(UserDefault::getInstance()->getIntegerForKey("chip_009") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 9);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_009", 2);
		UserDefault::getInstance()->flush();
		
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_009") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_009", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c10(cocos2d::Ref* pSender)
{
	
	if(UserDefault::getInstance()->getIntegerForKey("chip_010") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 10);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_010", 2);
		UserDefault::getInstance()->flush();
		
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_010") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_010", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c11(cocos2d::Ref* pSender)
{
	
	if(UserDefault::getInstance()->getIntegerForKey("chip_011") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 11);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_011", 2);
		UserDefault::getInstance()->flush();
		
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_011") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_011",1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c12(cocos2d::Ref* pSender)
{
	
	if(UserDefault::getInstance()->getIntegerForKey("chip_012") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 12);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_012", 2);
		UserDefault::getInstance()->flush();
		
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_012") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_012",1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c13(cocos2d::Ref* pSender)
{
	
	if(UserDefault::getInstance()->getIntegerForKey("chip_013") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 13);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_013", 2);
		UserDefault::getInstance()->flush();
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_013") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_013", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::c14(cocos2d::Ref* pSender)
{
	
	if(UserDefault::getInstance()->getIntegerForKey("chip_014") == 1)
	{
		offOtherChip();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 14);
	UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_014", 2);
		UserDefault::getInstance()->flush();
	}
	else if(UserDefault::getInstance()->getIntegerForKey("chip_014") == 2)
	{
		UserDefault::getInstance()->setIntegerForKey("chip_014", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
	UserDefault::getInstance()->flush();
	}
	Director::getInstance()->replaceScene(Mission2::createScene());
}

void Mission2::s01(cocos2d::Ref* pSender)
{
	int chip_now = UserDefault::getInstance()->getIntegerForKey("chip_now");
	int this_now = UserDefault::getInstance()->getIntegerForKey("slot_01_now");
	
	
	switch(this_now)
	{
	case 1:
			UserDefault::getInstance()->setIntegerForKey("chip_001", 1 );
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("chip_002", 1 );
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("chip_003", 1 );
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("chip_004", 1 );
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("chip_005", 1 );
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("chip_006", 1 );
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("chip_007", 1 );
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("chip_008", 1 );
			break;
		case 9 :
			UserDefault::getInstance()->setIntegerForKey("chip_009", 1);
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("chip_010", 1);
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("chip_011", 1);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("chip_012", 1);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("chip_013", 1);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("chip_014", 1);
			break;
		default:
			break;
		}

		UserDefault::getInstance()->setIntegerForKey("slot_01_now", chip_now);
		UserDefault::getInstance()->flush();
		switch(chip_now)
		{
		case 1:
			UserDefault::getInstance()->setIntegerForKey("chip_001", 3 );
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("chip_002", 3 );
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("chip_003", 3 );
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("chip_004", 3 );
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("chip_005", 3 );
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("chip_006", 3 );
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("chip_007", 3 );
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("chip_008", 3 );
			break;
		case 9 :
			UserDefault::getInstance()->setIntegerForKey("chip_009", 3 );
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("chip_010", 3 );
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("chip_011", 3);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("chip_012", 3);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("chip_013", 3);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("chip_014", 3);
			break;
		default:
			UserDefault::getInstance()->setIntegerForKey("slot_01_now", 0);
			break;
		}
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
		UserDefault::getInstance()->flush();

	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::s02(cocos2d::Ref* pSender)
{
	int chip_now = UserDefault::getInstance()->getIntegerForKey("chip_now");
	int this_now = UserDefault::getInstance()->getIntegerForKey("slot_02_now");
	
	
	switch(this_now)
	{
	case 1:
			UserDefault::getInstance()->setIntegerForKey("chip_001", 1 );
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("chip_002", 1 );
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("chip_003", 1 );
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("chip_004", 1 );
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("chip_005", 1 );
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("chip_006", 1 );
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("chip_007", 1 );
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("chip_008", 1 );
			break;
		case 9 :
			UserDefault::getInstance()->setIntegerForKey("chip_009", 1);
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("chip_010", 1);
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("chip_011", 1);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("chip_012", 1);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("chip_013", 1);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("chip_014", 1);
			break;
		default:
			break;
		}

		UserDefault::getInstance()->setIntegerForKey("slot_02_now", chip_now);
		UserDefault::getInstance()->flush();
		switch(chip_now)
		{
		case 1:
			UserDefault::getInstance()->setIntegerForKey("chip_001", 3 );
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("chip_002", 3 );
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("chip_003", 3 );
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("chip_004", 3 );
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("chip_005", 3 );
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("chip_006", 3 );
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("chip_007", 3 );
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("chip_008", 3 );
			break;
		case 9 :
			UserDefault::getInstance()->setIntegerForKey("chip_009", 3 );
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("chip_010", 3 );
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("chip_011", 3);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("chip_012", 3);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("chip_013", 3);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("chip_014", 3);
			break;
		default:
			UserDefault::getInstance()->setIntegerForKey("slot_02_now", 0);
			break;
		}
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
		UserDefault::getInstance()->flush();

	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::s03(cocos2d::Ref* pSender)
{
	int chip_now = UserDefault::getInstance()->getIntegerForKey("chip_now");
	int this_now = UserDefault::getInstance()->getIntegerForKey("slot_03_now");
	
	
	switch(this_now)
	{
	case 1:
			UserDefault::getInstance()->setIntegerForKey("chip_001", 1 );
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("chip_002", 1 );
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("chip_003", 1 );
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("chip_004", 1 );
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("chip_005", 1 );
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("chip_006", 1 );
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("chip_007", 1 );
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("chip_008", 1 );
			break;
		case 9 :
			UserDefault::getInstance()->setIntegerForKey("chip_009", 1);
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("chip_010", 1);
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("chip_011", 1);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("chip_012", 1);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("chip_013", 1);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("chip_014", 1);
			break;
		default:
			break;
		}

		UserDefault::getInstance()->setIntegerForKey("slot_03_now", chip_now);
		UserDefault::getInstance()->flush();
		switch(chip_now)
		{
		case 1:
			UserDefault::getInstance()->setIntegerForKey("chip_001", 3 );
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("chip_002", 3 );
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("chip_003", 3 );
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("chip_004", 3 );
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("chip_005", 3 );
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("chip_006", 3 );
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("chip_007", 3 );
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("chip_008", 3 );
			break;
		case 9 :
			UserDefault::getInstance()->setIntegerForKey("chip_009", 3 );
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("chip_010", 3 );
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("chip_011", 3);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("chip_012", 3);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("chip_013", 3);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("chip_014", 3);
			break;
		default:
			UserDefault::getInstance()->setIntegerForKey("slot_03_now", 0);
			break;
		}
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
		UserDefault::getInstance()->flush();

	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::s04(cocos2d::Ref* pSender)
{
	int chip_now = UserDefault::getInstance()->getIntegerForKey("chip_now");
	int this_now = UserDefault::getInstance()->getIntegerForKey("slot_04_now");
	
	
	switch(this_now)
	{
	case 1:
			UserDefault::getInstance()->setIntegerForKey("chip_001", 1 );
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("chip_002", 1 );
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("chip_003", 1 );
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("chip_004", 1 );
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("chip_005", 1 );
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("chip_006", 1 );
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("chip_007", 1 );
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("chip_008", 1 );
			break;
		case 9 :
			UserDefault::getInstance()->setIntegerForKey("chip_009", 1);
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("chip_010", 1);
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("chip_011", 1);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("chip_012", 1);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("chip_013", 1);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("chip_014", 1);
			break;
		default:
			break;
		}

		UserDefault::getInstance()->setIntegerForKey("slot_04_now", chip_now);
		UserDefault::getInstance()->flush();
		switch(chip_now)
		{
		case 1:
			UserDefault::getInstance()->setIntegerForKey("chip_001", 3 );
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("chip_002", 3 );
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("chip_003", 3 );
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("chip_004", 3 );
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("chip_005", 3 );
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("chip_006", 3 );
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("chip_007", 3 );
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("chip_008", 3 );
			break;
		case 9 :
			UserDefault::getInstance()->setIntegerForKey("chip_009", 3 );
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("chip_010", 3 );
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("chip_011", 3);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("chip_012", 3);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("chip_013", 3);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("chip_014", 3);
			break;
		default:
			UserDefault::getInstance()->setIntegerForKey("slot_04_now", 0);
			break;
		}
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
		UserDefault::getInstance()->flush();

	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::s05(cocos2d::Ref* pSender)
{
	int chip_now = UserDefault::getInstance()->getIntegerForKey("chip_now");
	int this_now = UserDefault::getInstance()->getIntegerForKey("slot_05_now");
	
	
	switch(this_now)
	{
	case 1:
			UserDefault::getInstance()->setIntegerForKey("chip_001", 1 );
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("chip_002", 1 );
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("chip_003", 1 );
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("chip_004", 1 );
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("chip_005", 1 );
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("chip_006", 1 );
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("chip_007", 1 );
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("chip_008", 1 );
			break;
		case 9 :
			UserDefault::getInstance()->setIntegerForKey("chip_009", 1);
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("chip_010", 1);
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("chip_011", 1);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("chip_012", 1);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("chip_013", 1);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("chip_014", 1);
			break;
		default:
			break;
		}

		UserDefault::getInstance()->setIntegerForKey("slot_05_now", chip_now);
		UserDefault::getInstance()->flush();
		switch(chip_now)
		{
		case 1:
			UserDefault::getInstance()->setIntegerForKey("chip_001", 3 );
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("chip_002", 3 );
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("chip_003", 3 );
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("chip_004", 3 );
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("chip_005", 3 );
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("chip_006", 3 );
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("chip_007", 3 );
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("chip_008", 3 );
			break;
		case 9 :
			UserDefault::getInstance()->setIntegerForKey("chip_009", 3 );
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("chip_010", 3 );
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("chip_011", 3);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("chip_012", 3);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("chip_013", 3);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("chip_014", 3);
			break;
		default:
			UserDefault::getInstance()->setIntegerForKey("slot_05_now", 0);
			break;
		}
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
		UserDefault::getInstance()->flush();

	Director::getInstance()->replaceScene(Mission2::createScene());
}
void Mission2::s06(cocos2d::Ref* pSender)
{
	int chip_now = UserDefault::getInstance()->getIntegerForKey("chip_now");
	int this_now = UserDefault::getInstance()->getIntegerForKey("slot_06_now");
	
	
	switch(this_now)
	{
	case 1:
			UserDefault::getInstance()->setIntegerForKey("chip_001", 1 );
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("chip_002", 1 );
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("chip_003", 1 );
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("chip_004", 1 );
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("chip_005", 1 );
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("chip_006", 1 );
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("chip_007", 1 );
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("chip_008", 1 );
			break;
		case 9 :
			UserDefault::getInstance()->setIntegerForKey("chip_009", 1);
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("chip_010", 1);
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("chip_011", 1);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("chip_012", 1);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("chip_013", 1);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("chip_014", 1);
			break;
		default:
			break;
		}

		UserDefault::getInstance()->setIntegerForKey("slot_06_now", chip_now);
		UserDefault::getInstance()->flush();
		switch(chip_now)
		{
		case 1:
			UserDefault::getInstance()->setIntegerForKey("chip_001", 3 );
			break;
		case 2:
			UserDefault::getInstance()->setIntegerForKey("chip_002", 3 );
			break;
		case 3:
			UserDefault::getInstance()->setIntegerForKey("chip_003", 3 );
			break;
		case 4:
			UserDefault::getInstance()->setIntegerForKey("chip_004", 3 );
			break;
		case 5:
			UserDefault::getInstance()->setIntegerForKey("chip_005", 3 );
			break;
		case 6:
			UserDefault::getInstance()->setIntegerForKey("chip_006", 3 );
			break;
		case 7:
			UserDefault::getInstance()->setIntegerForKey("chip_007", 3 );
			break;
		case 8:
			UserDefault::getInstance()->setIntegerForKey("chip_008", 3 );
			break;
		case 9 :
			UserDefault::getInstance()->setIntegerForKey("chip_009", 3 );
			break;
		case 10:
			UserDefault::getInstance()->setIntegerForKey("chip_010", 3 );
			break;
		case 11:
			UserDefault::getInstance()->setIntegerForKey("chip_011", 3);
			break;
		case 12:
			UserDefault::getInstance()->setIntegerForKey("chip_012", 3);
			break;
		case 13:
			UserDefault::getInstance()->setIntegerForKey("chip_013", 3);
			break;
		case 14:
			UserDefault::getInstance()->setIntegerForKey("chip_014", 3);
			break;
		default:
			UserDefault::getInstance()->setIntegerForKey("slot_06_now", 0);
			break;
		}
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
		UserDefault::getInstance()->flush();

	Director::getInstance()->replaceScene(Mission2::createScene());
}

void Mission2::b01(cocos2d::Ref* pSender)
{
	//오르내리다 헛손질 굶주리다 절댓값
	//설거지 허허실실 칼날 물렁뼈
	//설익다 비둘기 메아리 국그릇
	//대장장이 호랑이

	//합성어 (슬롯 1~3)
	//001오르내리다 003굶주리다 004절댓값 007칼날 008물렁뼈 012국그릇
	//파생어 (슬롯 4~6)
	//002헛손질 009설익다 013대장장이 014호랑이

	//단일어(해당사항 없음)
	//005설거지 006허허실실 010비둘기 011메아리

	int now1[3], now2[3];
	int i,j;

	now1[0] = UserDefault::getInstance()->getIntegerForKey("slot_01_now");
	now1[1] = UserDefault::getInstance()->getIntegerForKey("slot_02_now");
	now1[2] = UserDefault::getInstance()->getIntegerForKey("slot_03_now");

	for ( i = 0 ; i < 3 ; i ++)
	{
		if(now1[i] != 1 && now1[i] != 3 && now1[i] != 4 && now1[i] != 7 && now1[i] != 8 && now1[i] != 12)
		{
			break;
		}
	}

	
	now2[0] = UserDefault::getInstance()->getIntegerForKey("slot_04_now");
	now2[1] = UserDefault::getInstance()->getIntegerForKey("slot_05_now");
	now2[2] = UserDefault::getInstance()->getIntegerForKey("slot_06_now");
	for ( j = 0 ; j < 3 ; j ++)
	{
		if(now2[j] != 2 && now2[j] != 9 && now2[j] != 13 && now2[j] != 14)
		{
			break;
		}
	}
	
	if( i == 3 && j == 3)
	{
		UserDefault::getInstance()->setIntegerForKey("mission_result", 5);
			UserDefault::getInstance()->flush();
			UserDefault::getInstance()->setIntegerForKey("Mission2_complete", 1);
			UserDefault::getInstance()->flush();
			Director::getInstance()->replaceScene(RoomScene04Final::createScene());
			Director::getInstance()->pushScene(MissionDialog::createScene());
	}
	else
	{
		UserDefault::getInstance()->setIntegerForKey("mission_result", 4);
			UserDefault::getInstance()->flush();
			Director::getInstance()->replaceScene(RoomScene04Final::createScene());
			Director::getInstance()->pushScene(MissionDialog::createScene());
	}

}

void Mission2::offOtherSlot()
{
}

void Mission2::offOtherChip()
{
	if(UserDefault::getInstance()->getIntegerForKey("chip_001") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_001") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_001", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_002") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_002") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_002", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_003") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_003") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_003", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_004") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_004") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_004", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_005") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_005") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_005", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_006") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_006") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_006", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_007") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_007") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_007", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_008") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_008") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_008", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_009") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_009") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_009", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_010") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_010") != 3 )
			UserDefault::getInstance()->setIntegerForKey("chip_010", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_011") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_011") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_011", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_012") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_012") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_012", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_013") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_013") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_013", 1);
		if(UserDefault::getInstance()->getIntegerForKey("chip_014") != 0 && UserDefault::getInstance()->getIntegerForKey("chip_014") != 3)
			UserDefault::getInstance()->setIntegerForKey("chip_014", 1);
		UserDefault::getInstance()->flush();
}

		