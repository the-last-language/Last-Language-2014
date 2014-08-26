#include "GameScene1.h"


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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	initBG();

    
    
    return true;
}

void GameScene1::initBG()
{
	auto node = ParallaxNode::create();
	this->addChild(node);

	auto action_0 = MoveBy::create(10.0, Point(-2000,0));
	auto action_1 = Place::create(Point::ZERO);
	auto action_2 = Sequence::create(action_0, action_1, NULL);
	auto action_3 = RepeatForever::create(action_2);
	node->runAction(action_3);

	auto spr_0 = Sprite::create("game1/bg1.png");
	spr_0->setAnchorPoint(Point::ZERO);
	node->addChild(spr_0,0,Point::ZERO,Point::ZERO);

	auto spr_1 = Sprite::create("game1/bg1.png",Rect(0,0,960,640));
	spr_1->setAnchorPoint(Point::ZERO);
	node->addChild(spr_1,0,Point::ZERO,Point(2000,0));

	auto spr_2 = Sprite::create("game1/bg2.png");
	spr_2->setAnchorPoint(Point::ZERO);
	node->addChild(spr_2,1,Point::ZERO,Point::ZERO);

	auto spr_3 = Sprite::create("game1/bg2.png");
	spr_3->setAnchorPoint(Point::ZERO);
	node->addChild(spr_3,1,Point::ZERO,Point(2000,0));

	auto spr_4 = Sprite::create("game1/bg2.png",Rect(0,0,960,114));
	spr_4->setAnchorPoint(Point::ZERO);
	node->addChild(spr_4,1,Point::ZERO,Point(4000,0));
}

void GameScene1::menuCloseCallback(Ref* pSender)
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
