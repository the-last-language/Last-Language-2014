#include "PauseScene.h"
#include "BagScene.h"
#include "../MenuScene.h"
USING_NS_CC;


Scene* PauseScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = PauseScene::create();

    scene->addChild(layer);

    return scene;
}

bool PauseScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	int saved = UserDefault::getInstance()->getIntegerForKey("LASTPLAYED");


	auto sprite = Sprite::create("data/pause/PauseMenu.png");

	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite, 0);


	//계속하기
	auto item_1 = MenuItemImage::create("data/pause/pause_btn1.png",	"data/pause/pause_btn1_on.png", CC_CALLBACK_1(PauseScene::sceneReturn, this));
	item_1->setPosition(140, 640-90);
	auto menu_1 = Menu::create(item_1, NULL);
	menu_1->setPosition(Vec2::ZERO);
	this->addChild(menu_1); 


	//가방열기
	auto item_3 = MenuItemImage::create("data/pause/pause_btn2.png", "data/pause/pause_btn2_on.png", CC_CALLBACK_1(PauseScene::openBag, this));
	item_3->setPosition(140, 640-90-60);
	auto menu_3 = Menu::create(item_3, NULL);
	menu_3->setPosition(Vec2::ZERO);
	this->addChild(menu_3);

	//종료하기
	auto item_4 = MenuItemImage::create("data/pause/pause_btn3.png", "data/pause/pause_btn3_on.png", CC_CALLBACK_1(PauseScene::exitGame, this));
	item_4->setPosition(140, 640-90-120);
	auto menu_4 = Menu::create(item_4, NULL);
	menu_4->setPosition(Vec2::ZERO);
	this->addChild(menu_4);



    
    
    return true;
}

void PauseScene::sceneReturn(Ref* Sender)
{
	Director::getInstance()->popScene();

	//Director::getInstance()->replaceScene(GameScene2::createScene());
}

void PauseScene::openBag(Ref* Sender)
{
	Director::getInstance()->pushScene(BagScene::createScene());
}
void PauseScene::exitGame(Ref* Sender)
{
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(MenuScene::createScene());

}

void PauseScene::menuCloseCallback(Ref* pSender)
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
