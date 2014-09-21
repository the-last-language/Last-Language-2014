﻿#ifndef __EndSceneBad_SCENE_H__
#define __EndSceneBad_SCENE_H__

#include "cocos2d.h"

class EndSceneBad : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(EndSceneBad);
	
	//void changeScene(Ref *sender);

	void goNext(Ref *sender);
};

#endif // __MenuScene_SCENE_H__
