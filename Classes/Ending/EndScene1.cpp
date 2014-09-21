#include "EndScene1.h"
#include "EndScene2.h"
#include "../KoreanUTF8.h"
#include "../Pause/PauseScene.h"
USING_NS_CC;

Scene* EndScene1::createScene()
{
    auto scene = Scene::create();
    
    auto layer = EndScene1::create();

    scene->addChild(layer);

    return scene;
}

bool EndScene1::init()
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

	initAllDefaults();

	auto sprite1 = Sprite::create("data/scene/endScene1.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

	auto label = Label::createWithTTF(UTF8("엘리베이터를 타고 위층들을 두루 살펴 보았다.\n위층에서도 아랫층에서 한 것과 비슷한 암호들을 풀어 나갔다.\n여기서 알 수 있는 것들이 있다.\n두억시니라는 기계인간이 여기를 공격하려고 했었고\n여기 있던 사람들은 다른 곳으로 갔다는 사실과\n현재도 두억시니들이 인류를 학살하고 있다는 사실이다.\n또한 내가 그들이 찾던 실종된 샤를 미테랑 중위인 것도...\n"),"data/fonts/GodoB.ttf",30);
	label->setPosition(Point(480,320));
	this->addChild(label);

	//다음으로 넘기기
	auto item_1 = MenuItemImage::create("data/scene/next.png", "data/scene/next_on.png", CC_CALLBACK_1(EndScene1::goNext, this));
	item_1->setPosition(920, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1);

	

    
    
    return true;
}


void EndScene1::initAllDefaults()
{
}


void EndScene1::menuCloseCallback(Ref* pSender)
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

void EndScene1::goNext(Ref *sender)
{
	Director::getInstance()->replaceScene(EndScene2::createScene());
}
