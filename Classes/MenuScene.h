#ifndef __MenuScene_SCENE_H__
#define __MenuScene_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
	
	void startScene(Ref *sender);
	void aboutScene(Ref *sender);
	void loadScene1(Ref *sender);

	void load1(Ref *sender);
	void load2(Ref *sender);
	void load3(Ref *sender);
	void load4(Ref *sender);
	void load5(Ref *sender);
	void load201(Ref *sender);
	void load202(Ref *sender);
	void load203(Ref *sender);
	void load401(Ref *sender);
	void load402(Ref *sender);
	void load403(Ref *sender);//Final Room
	void load501(Ref *sender);
	void load502(Ref *sender);
	void loadButton(int num);
};

#endif // __MenuScene_SCENE_H__
