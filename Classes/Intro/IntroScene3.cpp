
#include "IntroScene3.h"
#include "../Game/GameScene1.h"
#include "../KoreanUTF8.h"
USING_NS_CC;

Scene* IntroScene3::createScene()
{
    auto scene = Scene::create();
    
    auto layer = IntroScene3::create();

    scene->addChild(layer);

    return scene;
}

bool IntroScene3::init()
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
                                           CC_CALLBACK_1(IntroScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);*/


	auto sprite1 = Sprite::create("data/scene/Scene1.jpg");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);


	//다음으로 넘기기
	auto item_1 = MenuItemImage::create("data/scene/next.png", "data/scene/next_on.png", CC_CALLBACK_1(IntroScene3::goNext, this));
	item_1->setPosition(920, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1);

	
	auto label = Label::createWithTTF(UTF8("왠지 빠져 나가야 할 것만 같은 느낌이 든다.\n저기 보이는 네모난 물체부터 살펴보자."),"data/fonts/GodoB.ttf",30);
	label->setPosition(Point(480,100));
	this->addChild(label);
    
    
    return true;
}




void IntroScene3::menuCloseCallback(Ref* pSender)
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

void IntroScene3::goNext(Ref *sender)
{
	Director::getInstance()->replaceScene(GameScene1::createScene());
}
