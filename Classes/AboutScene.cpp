#include "AboutScene.h"
#include "MenuScene.h"
#include "KoreanUTF8.h"
USING_NS_CC;

Scene* AboutScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = AboutScene::create();

    scene->addChild(layer);

    return scene;
}

bool AboutScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("data/aboutUS.png");

	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite, 0);

	//auto label = Label::createWithTTF(UTF8("아직 테스트 중.\n딱히 할 말은 없음.\n굴림 극혐이라 고도폰트 사용."),"fonts/GodoB.ttf",30);
	//label->setPosition(Point(480,320));
	//this->addChild(label);

	//닫기 메뉴 예시
	
    auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(AboutScene::changeScene, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	




    
    
    return true;
}

void AboutScene::changeScene(Ref* Sender)
{
	Director::getInstance()->replaceScene(MenuScene::createScene());
}

void AboutScene::menuCloseCallback(Ref* pSender)
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
