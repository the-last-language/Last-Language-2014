#ifndef __Mission1_SCENE_H__
#define __Mission1_SCENE_H__

#include "cocos2d.h"

class Mission1 : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	void m01(cocos2d::Ref* pSender);
	void m02(cocos2d::Ref* pSender);
    void m03(cocos2d::Ref* pSender);
	void m04(cocos2d::Ref* pSender);

	void m05(cocos2d::Ref* pSender);
	void m06(cocos2d::Ref* pSender);
	void m07(cocos2d::Ref* pSender);
	void m08(cocos2d::Ref* pSender);

	void m09(cocos2d::Ref* pSender);
	void m10(cocos2d::Ref* pSender);
	void m11(cocos2d::Ref* pSender);
	void m12(cocos2d::Ref* pSender);
    
	void m13(cocos2d::Ref* pSender);
	void m14(cocos2d::Ref* pSender);
	void m15(cocos2d::Ref* pSender);
	void m16(cocos2d::Ref* pSender);

	void result(cocos2d::Ref* pSender);

	void fail(cocos2d::Ref* pSender);
	void nothing(cocos2d::Ref* pSender);
	void initCancel();

    // implement the "static create()" method manually
    CREATE_FUNC(Mission1);
	
};

#endif // __MenuScene_SCENE_H__
