#ifndef __SpriteExtendEx__M2Chips__
#define __SpriteExtendEx__M2Chips__

#include "cocos2d.h"

class M2Chips : public cocos2d::Sprite
{
public:
   M2Chips();

   void setPriority(int fixedPriority);
   void setPriorityWithThis(bool useNodePriority);

   virtual void onEnter();
   virtual void onExit();

private:
	cocos2d::EventListener* _listener;
	int _fixedPriority;
	bool _useNodePriority;
};

#endif // __MenuScene_SCENE_H__
