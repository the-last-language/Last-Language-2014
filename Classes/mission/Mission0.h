#ifndef __Mission0_SCENE_H__
#define __Mission0_SCENE_H__

#include "cocos2d.h"

class Mission0 : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	void mission0_1_1(cocos2d::Ref* pSender);
	void mission0_1_2(cocos2d::Ref* pSender);
	void mission0_1_3(cocos2d::Ref* pSender);
	void mission0_1_4(cocos2d::Ref* pSender);
	void mission0_1_5(cocos2d::Ref* pSender);
	void mission0_1_6(cocos2d::Ref* pSender);
	void mission0_1_7(cocos2d::Ref* pSender);
	void mission0_1_8(cocos2d::Ref* pSender);
	void mission0_1_9(cocos2d::Ref* pSender);
	void mission0_1_10(cocos2d::Ref* pSender);
    
	void fail(cocos2d::Ref* pSender);
	void nothing(cocos2d::Ref* pSender);
	void initCancel();

    // implement the "static create()" method manually
    CREATE_FUNC(Mission0);
	
};

#endif // __MenuScene_SCENE_H__
