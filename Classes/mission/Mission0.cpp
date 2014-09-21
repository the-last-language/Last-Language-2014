#include "Mission0.h"
#include "MissionDialog.h"
#include "MenuScene.h"
#include "KoreanUTF8.h"
#include "Game/RoomScene0401.h"

USING_NS_CC;

Scene* Mission0::createScene()
{
    auto scene = Scene::create();
    
    auto layer = Mission0::create();

    scene->addChild(layer);

    return scene;
}


bool Mission0::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	srand(time(NULL));
	int ran = rand()%2 + 1;
	if(UserDefault::getInstance()->getIntegerForKey("mission0") ==0)
	{
		
		UserDefault::getInstance()->setIntegerForKey("mission0", ran);
		UserDefault::getInstance()->flush();
	}
	else
	{
		ran =UserDefault::getInstance()->getIntegerForKey("mission0");
	}
	if(ran == 1)
	{
		UserDefault::getInstance()->setIntegerForKey("mission0_1_10", 1);
		UserDefault::getInstance()->flush();
		//그들을 몇일동안/며칠동안 지켜봐왔다. 어떻게/어떡해 그들은 로봇의 삼원칙을 신경쓰지 안는것일까/않는것인가.
		auto sprite1_1 = Sprite::create("data/game1/mission/0_1.png");

		sprite1_1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		this->addChild(sprite1_1, 0);
		
		
		//그들을
		auto item_1 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::mission0_1_1, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_1") == 1)
		{
			item_1 = MenuItemImage::create("data/game1/mission/letter3_on.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_1->setPosition(460, 640-85);
		auto menu_1 = Menu::create(item_1, NULL);
		menu_1->setPosition(Vec2::ZERO);
		this->addChild(menu_1); 
		
		//몇일동안(오답)
		auto item_2 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter4_on.png", CC_CALLBACK_1(Mission0::fail, this));
		item_2->setPosition(870, 640-85);
		auto menu_2 = Menu::create(item_2, NULL);
		menu_2->setPosition(Vec2::ZERO);
		this->addChild(menu_2); 

		//며칠동안
		auto item_3 = MenuItemImage::create("data/game1/mission/letter4.png",	"data/game1/mission/letter4_on.png", CC_CALLBACK_1(Mission0::mission0_1_2, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_2") == 1)
		{
			item_3 = MenuItemImage::create("data/game1/mission/letter4_on.png",	"data/game1/mission/letter4_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_3->setPosition(250, 640-125);
		auto menu_3 = Menu::create(item_3, NULL);
		menu_3->setPosition(Vec2::ZERO);
		this->addChild(menu_3); 

		//지켜봐왔다
		auto item_4 = MenuItemImage::create("data/game1/mission/letter5.png",	"data/game1/mission/letter5_on.png", CC_CALLBACK_1(Mission0::mission0_1_3, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_3") == 1)
		{
			item_4 = MenuItemImage::create("data/game1/mission/letter5_on.png",	"data/game1/mission/letter5_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_4->setPosition(770, 640-125);
		auto menu_4 = Menu::create(item_4, NULL);
		menu_4->setPosition(Vec2::ZERO);
		this->addChild(menu_4); 

		//어떻게
		auto item_5 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::mission0_1_4, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_4") == 1)
		{
			item_5 = MenuItemImage::create("data/game1/mission/letter3_on.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_5->setPosition(180, 640-160);
		auto menu_5 = Menu::create(item_5, NULL);
		menu_5->setPosition(Vec2::ZERO);
		this->addChild(menu_5); 

		//어떡해(오답)
		auto item_6 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::fail, this));
		item_6->setPosition(775, 640-200);
		auto menu_6 = Menu::create(item_6, NULL);
		menu_6->setPosition(Vec2::ZERO);
		this->addChild(menu_6); 

		//그들은
		auto item_7 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::mission0_1_5, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_5") == 1)
		{
			item_7 = MenuItemImage::create("data/game1/mission/letter3_on.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_7->setPosition(405, 640-275);
		auto menu_7 = Menu::create(item_7, NULL);
		menu_7->setPosition(Vec2::ZERO);
		this->addChild(menu_7); 

		//로봇의
		auto item_8 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::mission0_1_6, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_6") == 1)
		{
			item_8 = MenuItemImage::create("data/game1/mission/letter3_on.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_8->setPosition(715, 640-275);
		auto menu_8 = Menu::create(item_8, NULL);
		menu_8->setPosition(Vec2::ZERO);
		this->addChild(menu_8); 

		//삼원칙을
		auto item_9 = MenuItemImage::create("data/game1/mission/letter4.png",	"data/game1/mission/letter4_on.png", CC_CALLBACK_1(Mission0::mission0_1_7, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_7") == 1)
		{
			item_9 = MenuItemImage::create("data/game1/mission/letter4_on.png",	"data/game1/mission/letter4_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_9->setPosition(190, 640-315);
		auto menu_9 = Menu::create(item_9, NULL);
		menu_9->setPosition(Vec2::ZERO);
		this->addChild(menu_9); 

		//신경쓰지
		auto item_10 = MenuItemImage::create("data/game1/mission/letter4.png",	"data/game1/mission/letter4_on.png", CC_CALLBACK_1(Mission0::mission0_1_8, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_8") == 1)
		{
			item_10 = MenuItemImage::create("data/game1/mission/letter4_on.png",	"data/game1/mission/letter4_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_10->setPosition(450, 640-315);
		auto menu_10 = Menu::create(item_10, NULL);
		menu_10->setPosition(Vec2::ZERO);
		this->addChild(menu_10); 

		//안는것일까(오답)
		auto item_11 = MenuItemImage::create("data/game1/mission/letter5.png",	"data/game1/mission/letter5_on.png", CC_CALLBACK_1(Mission0::fail, this));
		item_11->setPosition(660, 640-310);
		auto menu_11 = Menu::create(item_11, NULL);
		menu_11->setPosition(Vec2::ZERO);
		this->addChild(menu_11); 

		//않는것일까
		auto item_12 = MenuItemImage::create("data/game1/mission/letter5.png",	"data/game1/mission/letter5_on.png", CC_CALLBACK_1(Mission0::mission0_1_9, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_9") == 1)
		{
			item_12 = MenuItemImage::create("data/game1/mission/letter5_on.png",	"data/game1/mission/letter5_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_12->setPosition(95, 640-350);
		auto menu_12 = Menu::create(item_12, NULL);
		menu_12->setPosition(Vec2::ZERO);
		this->addChild(menu_12); 

	}
	else if (ran == 2)
	{
		//전자기기를 함부로/함부러 써서는 안돼/안되. 그들은 우리가 한 것을 금세/금새 알아차릴 것이다.
		auto sprite1_1 = Sprite::create("data/game1/mission/0_2.png");

		sprite1_1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		this->addChild(sprite1_1, 0);
		
		
		//전자기기를
		auto item_1 = MenuItemImage::create("data/game1/mission/letter5.png",	"data/game1/mission/letter5_on.png", CC_CALLBACK_1(Mission0::mission0_1_1, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_1") == 1)
		{
			item_1 = MenuItemImage::create("data/game1/mission/letter5_on.png",	"data/game1/mission/letter5_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_1->setPosition(265, 640-50);
		auto menu_1 = Menu::create(item_1, NULL);
		menu_1->setPosition(Vec2::ZERO);
		this->addChild(menu_1); 
		
		//함부러(오답)
		auto item_2 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::fail, this));
		item_2->setPosition(660, 640-50);
		auto menu_2 = Menu::create(item_2, NULL);
		menu_2->setPosition(Vec2::ZERO);
		this->addChild(menu_2); 

		//함부로
		auto item_3 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::mission0_1_2, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_2") == 1)
		{
			item_3 = MenuItemImage::create("data/game1/mission/letter3_on.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_3->setPosition(685, 640-90);
		auto menu_3 = Menu::create(item_3, NULL);
		menu_3->setPosition(Vec2::ZERO);
		this->addChild(menu_3); 

		//써서는
		auto item_4 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::mission0_1_3, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_3") == 1)
		{
			item_4 = MenuItemImage::create("data/game1/mission/letter3_on.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_4->setPosition(410, 640-85);
		auto menu_4 = Menu::create(item_4, NULL);
		menu_4->setPosition(Vec2::ZERO);
		this->addChild(menu_4); 

		//안돼
		auto item_5 = MenuItemImage::create("data/game1/mission/letter2.png",	"data/game1/mission/letter2_on.png", CC_CALLBACK_1(Mission0::mission0_1_4, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_4") == 1)
		{
			item_5 = MenuItemImage::create("data/game1/mission/letter2_on.png",	"data/game1/mission/letter2_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_5->setPosition(755, 640-85);
		auto menu_5 = Menu::create(item_5, NULL);
		menu_5->setPosition(Vec2::ZERO);
		this->addChild(menu_5); 

		//안되(오답)
		auto item_6 = MenuItemImage::create("data/game1/mission/letter2.png",	"data/game1/mission/letter2_on.png", CC_CALLBACK_1(Mission0::fail, this));
		item_6->setPosition(225, 640-125);
		auto menu_6 = Menu::create(item_6, NULL);
		menu_6->setPosition(Vec2::ZERO);
		this->addChild(menu_6); 

		//그들은
		auto item_7 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::mission0_1_5, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_5") == 1)
		{
			item_7 = MenuItemImage::create("data/game1/mission/letter3_on.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_7->setPosition(715, 640-125);
		auto menu_7 = Menu::create(item_7, NULL);
		menu_7->setPosition(Vec2::ZERO);
		this->addChild(menu_7); 

		//우리가
		auto item_8 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::mission0_1_6, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_6") == 1)
		{
			item_8 = MenuItemImage::create("data/game1/mission/letter3_on.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_8->setPosition(180, 640-165);
		auto menu_8 = Menu::create(item_8, NULL);
		menu_8->setPosition(Vec2::ZERO);
		this->addChild(menu_8); 

		//한것을
		auto item_9 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::mission0_1_7, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_7") == 1)
		{
			item_9 = MenuItemImage::create("data/game1/mission/letter3_on.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_9->setPosition(490, 640-165);
		auto menu_9 = Menu::create(item_9, NULL);
		menu_9->setPosition(Vec2::ZERO);
		this->addChild(menu_9); 

		//금세
		auto item_10 = MenuItemImage::create("data/game1/mission/letter2.png",	"data/game1/mission/letter2_on.png", CC_CALLBACK_1(Mission0::mission0_1_8, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_8") == 1)
		{
			item_10 = MenuItemImage::create("data/game1/mission/letter2_on.png",	"data/game1/mission/letter2_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_10->setPosition(55, 640-200);
		auto menu_10 = Menu::create(item_10, NULL);
		menu_10->setPosition(Vec2::ZERO);
		this->addChild(menu_10); 

		//금새(오답)
		auto item_11 = MenuItemImage::create("data/game1/mission/letter2.png",	"data/game1/mission/letter2_on.png", CC_CALLBACK_1(Mission0::fail, this));
		item_11->setPosition(675, 640-200);
		auto menu_11 = Menu::create(item_11, NULL);
		menu_11->setPosition(Vec2::ZERO);
		this->addChild(menu_11); 

		//알아차릴
		auto item_12 = MenuItemImage::create("data/game1/mission/letter4.png",	"data/game1/mission/letter4_on.png", CC_CALLBACK_1(Mission0::mission0_1_9, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_9") == 1)
		{
			item_12 = MenuItemImage::create("data/game1/mission/letter4_on.png",	"data/game1/mission/letter4_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_12->setPosition(280, 640-240);
		auto menu_12 = Menu::create(item_12, NULL);
		menu_12->setPosition(Vec2::ZERO);
		this->addChild(menu_12); 

		//것이다
		auto item_13 = MenuItemImage::create("data/game1/mission/letter3.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::mission0_1_10, this));
		if(UserDefault::getInstance()->getIntegerForKey("mission0_1_10") == 1)
		{
			item_13 = MenuItemImage::create("data/game1/mission/letter3_on.png",	"data/game1/mission/letter3_on.png", CC_CALLBACK_1(Mission0::nothing, this));
		}
		item_13->setPosition(660, 640-275);
		auto menu_13 = Menu::create(item_13, NULL);
		menu_13->setPosition(Vec2::ZERO);
		this->addChild(menu_13); 
	}


	initCancel();
    
    return true;
}

void Mission0::initCancel()
{
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(Mission0::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}

void Mission0::fail(Ref * pSender)
{
	UserDefault::getInstance()->setIntegerForKey("mission0_1_1", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_2", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_3", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_4", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_5", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_6", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_7", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_8", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_9", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_10", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission_result", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0", 0);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(RoomScene0401::createScene());
	Director::getInstance()->pushScene(MissionDialog::createScene());
	//Director::getInstance()->popScene();
}

int judge()
{
	int i;
	int a[10];
	a[0] = UserDefault::getInstance()->getIntegerForKey("mission0_1_1");
	a[1] = UserDefault::getInstance()->getIntegerForKey("mission0_1_2");
	a[2] = UserDefault::getInstance()->getIntegerForKey("mission0_1_3");
	a[3] = UserDefault::getInstance()->getIntegerForKey("mission0_1_4");
	a[4] = UserDefault::getInstance()->getIntegerForKey("mission0_1_5");
	a[5] = UserDefault::getInstance()->getIntegerForKey("mission0_1_6");
	a[6] = UserDefault::getInstance()->getIntegerForKey("mission0_1_7");
	a[7] = UserDefault::getInstance()->getIntegerForKey("mission0_1_8");
	a[8] = UserDefault::getInstance()->getIntegerForKey("mission0_1_9");
	a[9] = UserDefault::getInstance()->getIntegerForKey("mission0_1_10");

	for ( i = 0 ; i < 10 ; i ++)
	{
		if(a[i] == 0 )
		{
			break;
		}
	}
	return i;
}

void Mission0::mission0_1_1(Ref* pSender)
{
	UserDefault::getInstance()->setIntegerForKey("mission0_1_1", 1);
	UserDefault::getInstance()->flush();
	
	

	if( judge() == 10)
	{
		UserDefault::getInstance()->setIntegerForKey("mission_result", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("Mission0_complete", 1);
		UserDefault::getInstance()->flush();
		Director::getInstance()->replaceScene(RoomScene0401::createScene());
		Director::getInstance()->pushScene(MissionDialog::createScene());
	}
	else
	{
		Director::getInstance()->replaceScene(Mission0::createScene());
	}
}

void Mission0::mission0_1_2(Ref* pSender)
{
	UserDefault::getInstance()->setIntegerForKey("mission0_1_2", 1);
	UserDefault::getInstance()->flush();
	if( judge() == 10)
	{
		UserDefault::getInstance()->setIntegerForKey("mission_result", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("Mission0_complete", 1);
		UserDefault::getInstance()->flush();
		Director::getInstance()->replaceScene(RoomScene0401::createScene());
		Director::getInstance()->pushScene(MissionDialog::createScene());
	}
	else
	{
		Director::getInstance()->replaceScene(Mission0::createScene());
	}
}

void Mission0::mission0_1_3(Ref* pSender)
{
	UserDefault::getInstance()->setIntegerForKey("mission0_1_3", 1);
	UserDefault::getInstance()->flush();
	if( judge() == 10)
	{
		UserDefault::getInstance()->setIntegerForKey("mission_result", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("Mission0_complete", 1);
		UserDefault::getInstance()->flush();
		Director::getInstance()->replaceScene(RoomScene0401::createScene());
		Director::getInstance()->pushScene(MissionDialog::createScene());
	}
	else
	{
		Director::getInstance()->replaceScene(Mission0::createScene());
	}
}

void Mission0::mission0_1_4(Ref* pSender)
{
	UserDefault::getInstance()->setIntegerForKey("mission0_1_4", 1);
	UserDefault::getInstance()->flush();
	if( judge() == 10)
	{
		UserDefault::getInstance()->setIntegerForKey("mission_result", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("Mission0_complete", 1);
		UserDefault::getInstance()->flush();
		Director::getInstance()->replaceScene(RoomScene0401::createScene());
		Director::getInstance()->pushScene(MissionDialog::createScene());
	}
	else
	{
		Director::getInstance()->replaceScene(Mission0::createScene());
	}
}

void Mission0::mission0_1_5(Ref* pSender)
{
	UserDefault::getInstance()->setIntegerForKey("mission0_1_5", 1);
	UserDefault::getInstance()->flush();
	if( judge() == 10)
	{
		UserDefault::getInstance()->setIntegerForKey("mission_result", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("Mission0_complete", 1);
		UserDefault::getInstance()->flush();
		Director::getInstance()->replaceScene(RoomScene0401::createScene());
		Director::getInstance()->pushScene(MissionDialog::createScene());
	}
	else
	{
		Director::getInstance()->replaceScene(Mission0::createScene());
	}
}

void Mission0::mission0_1_6(Ref* pSender)
{
	UserDefault::getInstance()->setIntegerForKey("mission0_1_6", 1);
	UserDefault::getInstance()->flush();
	if( judge() == 10)
	{
		UserDefault::getInstance()->setIntegerForKey("mission_result", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("Mission0_complete", 1);
		UserDefault::getInstance()->flush();
		Director::getInstance()->replaceScene(RoomScene0401::createScene());
		Director::getInstance()->pushScene(MissionDialog::createScene());
	}
	else
	{
		Director::getInstance()->replaceScene(Mission0::createScene());
	}
}

void Mission0::mission0_1_7(Ref* pSender)
{
	UserDefault::getInstance()->setIntegerForKey("mission0_1_7", 1);
	UserDefault::getInstance()->flush();
	if( judge() == 10)
	{
		UserDefault::getInstance()->setIntegerForKey("mission_result", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("Mission0_complete", 1);
		UserDefault::getInstance()->flush();
		Director::getInstance()->replaceScene(RoomScene0401::createScene());
		Director::getInstance()->pushScene(MissionDialog::createScene());
	}
	else
	{
		Director::getInstance()->replaceScene(Mission0::createScene());
	}
}

void Mission0::mission0_1_8(Ref* pSender)
{
	UserDefault::getInstance()->setIntegerForKey("mission0_1_8", 1);
	UserDefault::getInstance()->flush();
	if( judge() == 10)
	{
		UserDefault::getInstance()->setIntegerForKey("mission_result", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("Mission0_complete", 1);
		UserDefault::getInstance()->flush();
		Director::getInstance()->replaceScene(RoomScene0401::createScene());
		Director::getInstance()->pushScene(MissionDialog::createScene());
	}
	else
	{
		Director::getInstance()->replaceScene(Mission0::createScene());
	}
}

void Mission0::mission0_1_9(Ref* pSender)
{
	UserDefault::getInstance()->setIntegerForKey("mission0_1_9", 1);
	UserDefault::getInstance()->flush();
	if( judge() == 10)
	{
		UserDefault::getInstance()->setIntegerForKey("mission_result", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("Mission0_complete", 1);
		UserDefault::getInstance()->flush();
		Director::getInstance()->replaceScene(RoomScene0401::createScene());
		Director::getInstance()->pushScene(MissionDialog::createScene());
	}
	else
	{
		Director::getInstance()->replaceScene(Mission0::createScene());
	}
}

void Mission0::mission0_1_10(Ref* pSender)
{
	UserDefault::getInstance()->setIntegerForKey("mission0_1_10", 1);
	UserDefault::getInstance()->flush();
	if( judge() == 10)
	{
		UserDefault::getInstance()->setIntegerForKey("mission_result", 1);
		UserDefault::getInstance()->flush();
		UserDefault::getInstance()->setIntegerForKey("Mission0_complete", 1);
		UserDefault::getInstance()->flush();
		Director::getInstance()->replaceScene(RoomScene0401::createScene());
		Director::getInstance()->pushScene(MissionDialog::createScene());
	}
	else
	{
		Director::getInstance()->replaceScene(Mission0::createScene());
	}
}

void Mission0::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
	UserDefault::getInstance()->setIntegerForKey("mission0_1_1", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_2", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_3", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_4", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_5", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_6", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_7", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_8", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_9", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0_1_10", 0);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->setIntegerForKey("mission0", 0);
	UserDefault::getInstance()->flush();
	Director::getInstance()->replaceScene(RoomScene0401::createScene());
	//Director::getInstance()->popScene();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void Mission0::nothing(Ref* pSender)
{
}