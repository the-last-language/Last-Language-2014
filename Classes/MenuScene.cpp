#include "MenuScene.h"
#include "Intro/IntroScene1.h"
#include "AllScene.h"
#include "Game/GameScene4.h"
#include "mission/Mission1.h"
#include "mission/Mission2.h"
USING_NS_CC;


Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MenuScene::create();

    scene->addChild(layer);

    return scene;
}

bool MenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");

	//닫기 메뉴 예시
	/*
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);*/
	auto sprite = Sprite::create("data/mainMenu.png");

	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite, 0);


	//게임시작
	auto item_1 = MenuItemImage::create("data/btn1.png",	"data/btn1_on.png", CC_CALLBACK_1(MenuScene::startScene, this));
	item_1->setPosition(800, 300);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 

	//이어하기

	loadButton(saved);

	//소개
	auto item_3 = MenuItemImage::create("data/btn3.png", "data/btn3_on.png", CC_CALLBACK_1(MenuScene::aboutScene, this));
	item_3->setPosition(800, 180);
	auto menu_3 = Menu::create(item_3, NULL);
	menu_3->setPosition(Vec2::ZERO);
	this->addChild(menu_3);

	//끝
	auto item_4 = MenuItemImage::create("data/btn4.png", "data/btn4_on.png", CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
	item_4->setPosition(800, 120);
	auto menu_4 = Menu::create(item_4, NULL);
	menu_4->setPosition(Vec2::ZERO);
	this->addChild(menu_4);



    
    
    return true;
}

void MenuScene::startScene(Ref* Sender)
{
	Director::getInstance()->replaceScene(IntroScene1::createScene());

	//Director::getInstance()->replaceScene(GameScene2::createScene());
}


void MenuScene::aboutScene(Ref* Sender)
{
	Director::getInstance()->replaceScene(AboutScene::createScene());
	//Director::getInstance()->replaceScene(Mission2::createScene());
}


void MenuScene::loadScene1(Ref* Sender)
{

	Director::getInstance()->replaceScene(GameScene1::createScene());
}

void MenuScene::load1(Ref* Sender)
{

	Director::getInstance()->replaceScene(GameScene1::createScene());
}
void MenuScene::load2(Ref* Sender)
{

	Director::getInstance()->replaceScene(GameScene2::createScene());
}
void MenuScene::load3(Ref* Sender)
{

	Director::getInstance()->replaceScene(GameScene3::createScene());
}
void MenuScene::load4(Ref* Sender)
{

	Director::getInstance()->replaceScene(GameScene4::createScene());
}
void MenuScene::load5(Ref* Sender)
{

	Director::getInstance()->replaceScene(GameScene5::createScene());
}
void MenuScene::load201(Ref* Sender)
{

	Director::getInstance()->replaceScene(RoomScene0201::createScene());
}
void MenuScene::load202(Ref* Sender)
{

	Director::getInstance()->replaceScene(RoomScene0202::createScene());
}
void MenuScene::load203(Ref* Sender)
{

	Director::getInstance()->replaceScene(RoomScene0203::createScene());
}

void MenuScene::load401(Ref* Sender)
{

	Director::getInstance()->replaceScene(RoomScene0401::createScene());
}
void MenuScene::load402(Ref* Sender)
{

	Director::getInstance()->replaceScene(RoomScene0402::createScene());
}
void MenuScene::load403(Ref* Sender)
{

	Director::getInstance()->replaceScene(RoomScene04Final::createScene());
}
void MenuScene::load501(Ref* Sender)
{

	Director::getInstance()->replaceScene(RoomScene0501::createScene());
}
void MenuScene::load502(Ref* Sender)
{

	Director::getInstance()->replaceScene(RoomScene0502::createScene());
}

void MenuScene::loadButton(int num)
{
	auto item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::aboutScene, this));
	auto menu_2 = Menu::create(item_2, NULL);
	switch(num)
		{
		case 1:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load1, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		case 2:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load2, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		case 3:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load3, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		case 4:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load4, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		case 5:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load5, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		case 201:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load201, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		case 202:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load202, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		case 203:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load203, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		case 401:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load401, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		case 402:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load402, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		case 403:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load403, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		case 501:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load501, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		case 502:
			item_2 =MenuItemImage::create("data/btn2.png", "data/btn2_on.png", CC_CALLBACK_1(MenuScene::load502, this));
			item_2->setPosition(800, 240);
			menu_2 = Menu::create(item_2, NULL);
			menu_2->setPosition(Vec2::ZERO);
			this->addChild(menu_2);
			break;
		default:
			auto sprite = Sprite::create("data/btn2_off.png");
			sprite->setPosition(800, 240);
			this->addChild(sprite, 0);
		}
}



void MenuScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
