#include "MissionDialog.h"
#include "MenuScene.h"
#include "KoreanUTF8.h"

USING_NS_CC;

Scene* MissionDialog::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MissionDialog::create();

    scene->addChild(layer);

    return scene;
}


bool MissionDialog::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	 auto sprite1 = Sprite::create("data/MissionDialog/bg.png");
	
	 int MissionDialog_num = UserDefault::getInstance()->getIntegerForKey("mission_result");
	 int fail;
	switch(MissionDialog_num)
	{
	case 0://game1, 문장찾기 게임 실패
		fail = UserDefault::getInstance()->getIntegerForKey("failcnt");
		UserDefault::getInstance()->setIntegerForKey("failcnt", fail+1);
	UserDefault::getInstance()->flush();
		sprite1 = Sprite::create("data/game1/mission/0_fail.png");
		break;
	case 1://game1, 문장찾기 게임 성공
		sprite1 = Sprite::create("data/game1/mission/0_success.png");
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
		break;//여기까지 GameScene1에 할당된 대화창
	case 2://단어 나누기 실패
		sprite1 = Sprite::create("data/game1/mission/1_fail.png");
		fail = UserDefault::getInstance()->getIntegerForKey("failcnt");
		UserDefault::getInstance()->setIntegerForKey("failcnt", fail+1);
	UserDefault::getInstance()->flush();
		break;
	case 3://단어 나누기 성공
		sprite1 = Sprite::create("data/game1/mission/1_success.png");
		break;
	case 4://단어 분류 실패
		sprite1 = Sprite::create("data/game1/mission/2_fail.png");
		fail = UserDefault::getInstance()->getIntegerForKey("failcnt");
		UserDefault::getInstance()->setIntegerForKey("failcnt", fail+1);
	UserDefault::getInstance()->flush();
		break;
	case 5://단어 분류 성공.
		sprite1 = Sprite::create("data/game1/mission/2_success.png");
		break;
	default:
		sprite1 = Sprite::create("data/MissionDialog/bg.png");
	}

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

	
   
	initCancel();
    
    return true;
}

void MissionDialog::initCancel()
{
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(MissionDialog::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}


void MissionDialog::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    //Director::getInstance()->end();
	Director::getInstance()->popScene();
	//Director::getInstance()->replaceScene(MenuScene::createScene());
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
