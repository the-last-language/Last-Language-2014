#ifndef __RoomScene0202_SCENE_H__
#define __RoomScene0202_SCENE_H__

#include "cocos2d.h"

class RoomScene0202 : public cocos2d::Layer
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
	void nothing(cocos2d::Ref* pSender);

	void initBG();
	void initExit();
	void initObj1();
	void initObj2();
	void initObj3();
	
    // implement the "static create()" method manually
    CREATE_FUNC(RoomScene0202);
	
};

#endif // __MenuScene_SCENE_H__
