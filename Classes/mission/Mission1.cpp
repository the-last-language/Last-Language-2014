#include "Mission1.h"
#include "MissionDialog.h"
#include "MenuScene.h"
#include "KoreanUTF8.h"

USING_NS_CC;

Scene* Mission1::createScene()
{
    auto scene = Scene::create();
    
    auto layer = Mission1::create();

    scene->addChild(layer);

    return scene;
}


bool Mission1::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	srand(time(NULL));
	int ran = rand()%2 + 1;
	if(UserDefault::getInstance()->getIntegerForKey("Mission1") ==0)
	{
		
		UserDefault::getInstance()->setIntegerForKey("Mission1", ran);
		UserDefault::getInstance()->flush();
	}
	else
	{
		ran =UserDefault::getInstance()->getIntegerForKey("Mission1");
	}
	if(ran == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("Mission1_1_10", 1);
		UserDefault::getInstance()->flush();

		auto sprite1_1 = Sprite::create("game1/mission/1_1.png");

		sprite1_1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		this->addChild(sprite1_1, 0);
		
		

	}
	else if (ran == 2)
	{
		//전자기기를 함부로/함부러 써서는 안돼/안되. 그들은 우리가 한 것을 금세/금새 알아차릴 것이다.
		auto sprite1_1 = Sprite::create("game1/mission/1_2.png");

		sprite1_1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		this->addChild(sprite1_1, 0);
		
		
	}
	initCancel();
    
    return true;
}

void Mission1::initCancel()
{
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
										   CC_CALLBACK_1(Mission1::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void Mission1::fail(Ref * pSender)
{
	
	UserDefault::getInstance()->setIntegerForKey("Mission1", 2);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(MissionDialog::createScene());
	//Director::getInstance()->popScene();
}



void Mission1::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
	
	UserDefault::getInstance()->setIntegerForKey("Mission1", 2);
	UserDefault::getInstance()->flush();
	Director::getInstance()->popScene();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void Mission1::nothing(Ref* pSender)
{
}