#ifndef __EndScene1_SCENE_H__
#define __EndScene1_SCENE_H__

#include "cocos2d.h"

class EndScene1 : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(EndScene1);
	
	//void changeScene(Ref *sender);

	void goNext(Ref *sender);

	void initAllDefaults();
};

#endif // __MenuScene_SCENE_H__
