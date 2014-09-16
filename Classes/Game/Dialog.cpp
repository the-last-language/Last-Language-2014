#include "Dialog.h"
#include "MenuScene.h"
#include "KoreanUTF8.h"

USING_NS_CC;

Scene* Dialog::createScene()
{
    auto scene = Scene::create();
    
    auto layer = Dialog::create();

    scene->addChild(layer);

    return scene;
}


bool Dialog::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	 auto sprite1 = Sprite::create("dialog/bg.png");
	
	 int dialog_num = UserDefault::getInstance()->getIntegerForKey("Dialog");
 	auto label = Label::createWithTTF(UTF8("Object TEST.\n그냥 일반적인 컴퓨터.\n지금은 고장남.\n아마 접속콘솔로 쓰일듯."),"fonts/GodoB.ttf",30);

	switch(dialog_num)
	{
	case 3://game1, bg0, 칩을 주워라.
		sprite1 = Sprite::create("dialog/game1_bg0.png");
		label = Label::createWithTTF(UTF8("몇개의 칩으로 보이는 물체를 주웠다.\n네모 다섯개가 연결되어 있다.\n각 네모에는 글자가 적혀 있다.\n[단어칩 2개를 획득하였습니다.]"),"fonts/GodoB.ttf",30);
		break;
	case 4://game1, bg0, 전선을 주워라
		sprite1 = Sprite::create("dialog/game1_bg0.png");
		label = Label::createWithTTF(UTF8("낡은 전선을 주웠다.\n분명 어딘가에 쓸모는 있을 것이다.\n[전선 2개를 주웠습니다.]"),"fonts/GodoB.ttf",30);
		break;//여기까지 GameScene1에 할당된 대화창


	default:
		sprite1 = Sprite::create("dialog/bg.png");
	}

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

	label->setPosition(Point(480,320));
	this->addChild(label);
   
	initCancel();
    
    return true;
}

void Dialog::initCancel()
{
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
										   CC_CALLBACK_1(Dialog::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}


void Dialog::menuCloseCallback(Ref* pSender)
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
