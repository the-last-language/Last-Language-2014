#include "IntroScene1.h"
#include "IntroScene2.h"
#include "../KoreanUTF8.h"
#include "../Pause/PauseScene.h"
USING_NS_CC;

Scene* IntroScene1::createScene()
{
    auto scene = Scene::create();
    
    auto layer = IntroScene1::create();

    scene->addChild(layer);

    return scene;
}

bool IntroScene1::init()
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

	initAllDefaults();

	auto sprite1 = Sprite::create("data/scene/Scene1.jpg");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

	auto label = Label::createWithTTF(UTF8("깨어나 보니 처음 보는 방이다.\n내가 어떻게 해서 여기까지 왔는지\n전혀 기억나지 않는다."),"data/fonts/GodoB.ttf",30);
	label->setPosition(Point(480,100));
	this->addChild(label);

	//다음으로 넘기기
	auto item_1 = MenuItemImage::create("data/scene/next.png", "data/scene/next_on.png", CC_CALLBACK_1(IntroScene1::goNext, this));
	item_1->setPosition(920, 40);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1);

	

    
    
    return true;
}


void IntroScene1::initAllDefaults()
{
	//Userdefault의 모든 것을 초기화 한다.
	//새 게임이 시작하기 때문.

	//아이템 초기화
	UserDefault::getInstance()->setIntegerForKey("failcnt", 0);
	UserDefault::getInstance()->flush();

	UserDefault::getInstance()->setIntegerForKey("item_wire1", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_bg0_001", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_bg0_002", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_room0202_0", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_room0202_1", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_room0203_0", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_room0203_1", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_room0401_1", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_room0501_1", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_room0502_0", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_room0502_1", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("item_bg5_0", 0);
	UserDefault::getInstance()->flush();
	

	UserDefault::getInstance()->setIntegerForKey("mission0", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("Mission0_complete", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("Mission1_complete", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("Mission2_complete", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("Mission1", 0);
	UserDefault::getInstance()->flush();

	UserDefault::getInstance()->setIntegerForKey("m01", 0);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("m02", 0);
		UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("m03", 0);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("m04", 0);
		UserDefault::getInstance()->flush();

			UserDefault::getInstance()->setIntegerForKey("m05", 0);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("m06", 0);
		UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("m07", 0);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("m08", 0);
		UserDefault::getInstance()->flush();

			UserDefault::getInstance()->setIntegerForKey("m09", 0);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("m10", 0);
		UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("m11", 0);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("m12", 0);
		UserDefault::getInstance()->flush();

			UserDefault::getInstance()->setIntegerForKey("m13", 0);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("m14", 0);
		UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("m15", 0);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("m16", 0);
		UserDefault::getInstance()->flush();

		UserDefault::getInstance()->setIntegerForKey("chip_001", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_002", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_003", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_004", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_005", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_006", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_007", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_008", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_009", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_010", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_011", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_012", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_013", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_014", 0);
		UserDefault::getInstance()->setIntegerForKey("chip_now", 0);
		UserDefault::getInstance()->flush();

		UserDefault::getInstance()->setIntegerForKey("slot_01_now", 0);
		UserDefault::getInstance()->setIntegerForKey("slot_02_now", 0);
		UserDefault::getInstance()->setIntegerForKey("slot_03_now", 0);
		UserDefault::getInstance()->setIntegerForKey("slot_04_now", 0);
		UserDefault::getInstance()->setIntegerForKey("slot_05_now", 0);
		UserDefault::getInstance()->setIntegerForKey("slot_06_now", 0);
		UserDefault::getInstance()->flush();

}


void IntroScene1::menuCloseCallback(Ref* pSender)
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

void IntroScene1::goNext(Ref *sender)
{
	Director::getInstance()->replaceScene(IntroScene2::createScene());
}
