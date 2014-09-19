#ifndef __Mission2_SCENE_H__
#define __Mission2_SCENE_H__

#include "cocos2d.h"

class Mission2 : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	
	CREATE_FUNC(Mission2);
	void nothing(cocos2d::Ref* pSender);
	 void menuCloseCallback(cocos2d::Ref* pSender);
	void initItems();
	void initCancel();
	void initSlot();
	void initButton();
	void offOtherChip();
	void offOtherSlot();
	void c01(cocos2d::Ref* pSender);
	void c02(cocos2d::Ref* pSender);
	void c03(cocos2d::Ref* pSender);
	void c04(cocos2d::Ref* pSender);
	void c05(cocos2d::Ref* pSender);
	void c06(cocos2d::Ref* pSender);
	void c07(cocos2d::Ref* pSender);
	void c08(cocos2d::Ref* pSender);
	void c09(cocos2d::Ref* pSender);
	void c10(cocos2d::Ref* pSender);
	void c11(cocos2d::Ref* pSender);
	void c12(cocos2d::Ref* pSender);
	void c13(cocos2d::Ref* pSender);
	void c14(cocos2d::Ref* pSender);

	void s01(cocos2d::Ref* pSender);
	void s02(cocos2d::Ref* pSender);
	void s03(cocos2d::Ref* pSender);
	void s04(cocos2d::Ref* pSender);
	void s05(cocos2d::Ref* pSender);
	void s06(cocos2d::Ref* pSender);

	void b01(cocos2d::Ref* pSender);
};


#endif // __MenuScene_SCENE_H__
