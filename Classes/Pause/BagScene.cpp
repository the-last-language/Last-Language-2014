#include "BagScene.h"
#include "../MenuScene.h"
#include "../KoreanUTF8.h"
USING_NS_CC;


Scene* BagScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = BagScene::create();

    scene->addChild(layer);

    return scene;
}

bool BagScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");


	auto sprite = Sprite::create("data/pause/PauseMenu.png");

	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite, 0);


	//돌아가기
	auto item_1 = MenuItemImage::create("data/pause/bag/back.png",	"data/pause/bag/back_on.png", CC_CALLBACK_1(BagScene::goBack, this));
	item_1->setPosition(840, 640-70);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 

	wireInit();
	chipInit();
	
    
    
    return true;
}

void BagScene::goBack(Ref* Sender)
{
	Director::getInstance()->popScene();
}

void BagScene::wireInit()
{
	std::string wires = UserDefault::getInstance()->getStringForKey("item_wire1");

	auto label_wire = Label::createWithTTF((UTF8("사용가능한 전선의 수 : ")),"data/fonts/GodoB.ttf",30);
	label_wire->setPosition(Point(180,640-65));
	this->addChild(label_wire);

	auto label_wire_cnt = Label::createWithTTF((UTF8(wires.c_str())),"data/fonts/GodoB.ttf",30);
	label_wire_cnt->setPosition(Point(350,640-65));
	this->addChild(label_wire_cnt);
}

void BagScene::chipInit()
{
	auto label_chip = Label::createWithTTF(UTF8("#현재까지 수집한 칩"),"data/fonts/GodoB.ttf",30);
	label_chip->setPosition(Point(160,640-120));
	this->addChild(label_chip);

	int chip001 = UserDefault::getInstance()->getIntegerForKey("chip_001");
	int chip002 = UserDefault::getInstance()->getIntegerForKey("chip_002");
	int chip003 = UserDefault::getInstance()->getIntegerForKey("chip_003");
	int chip004 = UserDefault::getInstance()->getIntegerForKey("chip_004");
	int chip005 = UserDefault::getInstance()->getIntegerForKey("chip_005");
	int chip006 = UserDefault::getInstance()->getIntegerForKey("chip_006");
	int chip007 = UserDefault::getInstance()->getIntegerForKey("chip_007");
	int chip008 = UserDefault::getInstance()->getIntegerForKey("chip_008");
	int chip009 = UserDefault::getInstance()->getIntegerForKey("chip_009");
	int chip010 = UserDefault::getInstance()->getIntegerForKey("chip_010");
	int chip011 = UserDefault::getInstance()->getIntegerForKey("chip_011");
	int chip012 = UserDefault::getInstance()->getIntegerForKey("chip_012");
	int chip013 = UserDefault::getInstance()->getIntegerForKey("chip_013");
	int chip014 = UserDefault::getInstance()->getIntegerForKey("chip_014");
	

	if(chip001 != 0)
	{
		auto sprite001 = Sprite::create("data/pause/bag/001.png");

		sprite001->setPosition(150, 640-180);

		this->addChild(sprite001, 1);
	}
	if(chip002 != 0)
	{
		auto sprite002 = Sprite::create("data/pause/bag/002.png");

		sprite002->setPosition(310, 640-180);

		this->addChild(sprite002, 1);
	}
	if(chip003 != 0)
	{
		auto sprite003 = Sprite::create("data/pause/bag/003.png");

		sprite003->setPosition(470, 640-180);

		this->addChild(sprite003, 1);
	}
	if(chip004 != 0)
	{
		auto sprite004 = Sprite::create("data/pause/bag/004.png");

		sprite004->setPosition(630, 640-180);

		this->addChild(sprite004, 1);
	}


	if(chip005 != 0)
	{
		auto sprite005 = Sprite::create("data/pause/bag/005.png");

		sprite005->setPosition(150, 640-230);

		this->addChild(sprite005, 1);
	}
	if(chip006 != 0)
	{
		auto sprite006 = Sprite::create("data/pause/bag/006.png");

		sprite006->setPosition(310, 640-230);

		this->addChild(sprite006, 1);
	}
	if(chip007 != 0)
	{
		auto sprite007 = Sprite::create("data/pause/bag/007.png");

		sprite007->setPosition(470, 640-230);

		this->addChild(sprite007, 1);
	}
	if(chip008 != 0)
	{
		auto sprite008 = Sprite::create("data/pause/bag/008.png");

		sprite008->setPosition(630, 640-230);

		this->addChild(sprite008, 1);
	}

	if(chip009 != 0)
	{
		auto sprite009 = Sprite::create("data/pause/bag/009.png");

		sprite009->setPosition(150, 640-280);

		this->addChild(sprite009, 1);
	}
	if(chip010 != 0)
	{
		auto sprite010 = Sprite::create("data/pause/bag/010.png");

		sprite010->setPosition(310, 640-280);

		this->addChild(sprite010, 1);
	}
	if(chip011 != 0)
	{
		auto sprite011 = Sprite::create("data/pause/bag/011.png");

		sprite011->setPosition(470, 640-280);

		this->addChild(sprite011, 1);
	}
	if(chip012 != 0)
	{
		auto sprite012 = Sprite::create("data/pause/bag/012.png");

		sprite012->setPosition(630, 640-280);

		this->addChild(sprite012, 1);
	}

	if(chip013 != 0)
	{
		auto sprite013= Sprite::create("data/pause/bag/013.png");

		sprite013->setPosition(150, 640-330);

		this->addChild(sprite013, 1);
	}
	if(chip014 != 0)
	{
		auto sprite014 = Sprite::create("data/pause/bag/014.png");

		sprite014->setPosition(310, 640-330);

		this->addChild(sprite014, 1);
	}
}