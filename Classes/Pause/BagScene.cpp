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


	auto sprite = Sprite::create("pause/PauseMenu.png");

	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite, 0);


	//돌아가기
	auto item_1 = MenuItemImage::create("pause/bag/back.png",	"pause/bag/back_on.png", CC_CALLBACK_1(BagScene::goBack, this));
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

	auto label_wire = Label::createWithTTF((UTF8("사용가능한 전선의 수 : ")),"fonts/GodoB.ttf",30);
	label_wire->setPosition(Point(180,640-65));
	this->addChild(label_wire);

	auto label_wire_cnt = Label::createWithTTF((UTF8(wires.c_str())),"fonts/GodoB.ttf",30);
	label_wire_cnt->setPosition(Point(350,640-65));
	this->addChild(label_wire_cnt);
}

void BagScene::chipInit()
{
	auto label_chip = Label::createWithTTF(UTF8("#현재까지 수집한 칩"),"fonts/GodoB.ttf",30);
	label_chip->setPosition(Point(160,640-120));
	this->addChild(label_chip);

	int chip001 = UserDefault::getInstance()->getIntegerForKey("chip_001");
	int chip002 = UserDefault::getInstance()->getIntegerForKey("chip_002");
	

	if(chip001 != 0)
	{
		auto sprite001 = Sprite::create("pause/bag/001.png");

		sprite001->setPosition(90, 640-180);

		this->addChild(sprite001, 1);
	}
	if(chip002 != 0)
	{
		auto sprite002 = Sprite::create("pause/bag/002.png");

		sprite002->setPosition(250, 640-180);

		this->addChild(sprite002, 1);
	}

}