#ifndef __GameScene4_SCENE_H__
#define __GameScene4_SCENE_H__

#include "cocos2d.h"

class GameScene4 : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void callObj1Content(cocos2d::Ref* pSender);
    void callObj2Content(cocos2d::Ref* pSender);
	void callObj3Content(cocos2d::Ref* pSender);
	void callObj4Content(cocos2d::Ref* pSender);

	void initBG();
	void initExit();
	void initObj1();
	void initObj2();
	void initObj3();
	void initObj4();

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene4);
	
};

#endif // __MenuScene_SCENE_H__
