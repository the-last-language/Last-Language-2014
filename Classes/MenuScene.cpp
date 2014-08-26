#include "MenuScene.h"
#include "Intro/IntroScene1.h"
#include "AboutScene.h"

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
	auto sprite = Sprite::create("main_temp.png");

	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite, 0);

	//게임시작
	auto item_1 = MenuItemImage::create("btn1.png",	"btn1_on.png", CC_CALLBACK_1(MenuScene::startScene, this));
	item_1->setPosition(800, 300);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 

	//이어하기
	auto item_2 = MenuItemImage::create("btn2.png", "btn2_on.png", CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
	item_2->setPosition(800, 240);
	auto menu_2 = Menu::create(item_2, NULL);
	menu_2->setPosition(Vec2::ZERO);
	this->addChild(menu_2);

	//소개
	auto item_3 = MenuItemImage::create("btn3.png", "btn3_on.png", CC_CALLBACK_1(MenuScene::aboutScene, this));
	item_3->setPosition(800, 180);
	auto menu_3 = Menu::create(item_3, NULL);
	menu_3->setPosition(Vec2::ZERO);
	this->addChild(menu_3);

	//끝
	auto item_4 = MenuItemImage::create("btn4.png", "btn4_on.png", CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
	item_4->setPosition(800, 120);
	auto menu_4 = Menu::create(item_4, NULL);
	menu_4->setPosition(Vec2::ZERO);
	this->addChild(menu_4);



    
    
    return true;
}

void MenuScene::startScene(Ref* Sender)
{
	Director::getInstance()->replaceScene(IntroScene1::createScene());
}

void MenuScene::aboutScene(Ref* Sender)
{
	Director::getInstance()->replaceScene(AboutScene::createScene());
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
