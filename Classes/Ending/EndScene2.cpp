#include "EndScene2.h"
#include "EndScene3.h"
#include "../KoreanUTF8.h"
USING_NS_CC;

Scene* EndScene2::createScene()
{
    auto scene = Scene::create();
    
    auto layer = EndScene2::create();

    scene->addChild(layer);

    return scene;
}

bool EndScene2::init()
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
                                           CC_CALLBACK_1(EndScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);*/


	auto sprite2 = Sprite::create("data/scene/endScene2.png");

	sprite2->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite2, 0);




	//다음으로 넘기기
	auto item_1 = MenuItemImage::create("data/scene/next.png", "data/scene/next_on.png", CC_CALLBACK_1(EndScene2::goNext, this));
	item_1->setPosition(920, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1);
	
	auto label = Label::createWithTTF(UTF8("밖으로 나왔다.\n밖에는 아무 것도 없이 황량한 땅이다.\n조금만 더 지나고 나서 보니 내가 깨어났던 곳과 다를바 없는 폐허였다.\n어서 빨리 방공호 속에 있었던 나의 전우들을 찾자.\n그리고 두억시니의 만행을 막자."),"data/fonts/GodoB.ttf",30);
	label->setPosition(Point(480,320));
	this->addChild(label);
	
    
    
    return true;
}



void EndScene2::menuCloseCallback(Ref* pSender)
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

void EndScene2::goNext(Ref *sender)
{
	Director::getInstance()->replaceScene(EndScene3::createScene());
}
