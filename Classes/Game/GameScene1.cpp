#include "GameScene1.h"
#include "GameScene2.h"
#include "GameScene1Obj1.h"
#include "MenuScene.h"
#include "../Pause/PauseScene.h"
#include "Dialog.h"
#include "mission/Mission0.h"

USING_NS_CC;

Scene* GameScene1::createScene()
{
    auto scene = Scene::create();
    
    auto layer = GameScene1::create();

    scene->addChild(layer);

    return scene;
}


bool GameScene1::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
	int item1 = UserDefault::getInstance()->getIntegerForKey("item_bg0_001");
	int item2 = UserDefault::getInstance()->getIntegerForKey("item_bg0_002");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	UserDefault::getInstance()->setIntegerForKey("LASTPLAYED", 1);
	UserDefault::getInstance()->flush();


	initBG();
	initObj1();//복도로 나가는문
	if(item1 == 0)
		initObj2();//칩 줍기
	if(item2 == 0)
		initObj3();//전선 줍기
	initExit();

    
    
    return true;
}

void GameScene1::initObj1()//나가는 문.
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg0_0.png", "data/game1/object/bg0_0_on.png", CC_CALLBACK_1(GameScene1::callObj1Content, this));
	item_1->setPosition(630, 390);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene1::initObj2()//칩 줍기.
{
	auto item_2 = MenuItemImage::create("data/game1/object/bg0_1.png", "data/game1/object/bg0_1_on.png", CC_CALLBACK_1(GameScene1::callObj2Content, this));
	item_2->setPosition(287, 487);
	auto menu_2 = Menu::create(item_2, NULL);
	menu_2->setPosition(Vec2::ZERO);
	this->addChild(menu_2); 
}

void GameScene1::initObj3()//전선 줍기.
{
	auto item_1 = MenuItemImage::create("data/game1/object/bg0_2.png",	"data/game1/object/bg0_2_on.png", CC_CALLBACK_1(GameScene1::callObj3Content, this));
	item_1->setPosition(207, 167);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 
}

void GameScene1::initExit()
{
 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(GameScene1::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void GameScene1::initBG()
{
//	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("data/game1/bg0.png");

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

}

//복도로 나가기
void GameScene1::callObj1Content(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene2::createScene());	
}

//칩을 주워라
void GameScene1::callObj2Content(Ref * pSender)
{
	UserDefault::getInstance()->setIntegerForKey("Dialog", 3);
	UserDefault::getInstance()->flush();
	
	Director::getInstance()->pushScene(GameScene1Obj1::createScene());
	UserDefault::getInstance()->setIntegerForKey("item_bg0_001", 1);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("chip_001", 1);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("chip_002", 1);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(GameScene1::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
	//Director::getInstance()->pushScene(Mission0::createScene());
	

}

//전선을 주워라
void GameScene1::callObj3Content(Ref * pSender)
{
	UserDefault::getInstance()->setIntegerForKey("Dialog", 4);
	UserDefault::getInstance()->flush();
	

	int wires = UserDefault::getInstance()->getIntegerForKey("item_wire1");

	UserDefault::getInstance()->setIntegerForKey("item_bg0_002", 1);
	UserDefault::getInstance()->flush();
	wires += 2;
	UserDefault::getInstance()->setIntegerForKey("item_wire1", wires);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(GameScene1::createScene());
	Director::getInstance()->pushScene(Dialog::createScene());
	

}

//일시정지 메뉴 가기
void GameScene1::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

	Director::getInstance()->pushScene(PauseScene::createScene());

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
