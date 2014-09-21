
#include "EndSceneBad.h"
#include "../Game/GameScene1.h"
#include "../KoreanUTF8.h"
#include "../MenuScene.h"
USING_NS_CC;

Scene* EndSceneBad::createScene()
{
    auto scene = Scene::create();
    
    auto layer = EndSceneBad::create();

    scene->addChild(layer);

    return scene;
}

bool EndSceneBad::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();




	auto sprite1 = Sprite::create("data/scene/bad_ending.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);


	//다음으로 넘기기
	auto item_1 = MenuItemImage::create("data/scene/next.png", "data/scene/next_on.png", CC_CALLBACK_1(EndSceneBad::goNext, this));
	item_1->setPosition(920, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1);

	
	//auto label = Label::createWithTTF(UTF8("배드엔딩."),"data/fonts/GodoB.ttf",30);
	//label->setPosition(Point(480,100));
	//this->addChild(label);
    
    
    return true;
}




void EndSceneBad::menuCloseCallback(Ref* pSender)
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

void EndSceneBad::goNext(Ref *sender)
{
	Director::getInstance()->replaceScene(MenuScene::createScene());
}
