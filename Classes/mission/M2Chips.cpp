#include "M2Chips.h"


USING_NS_CC;

M2Chips::M2Chips()
	:_listener(nullptr), _fixedPriority(0), _useNodePriority(false)
{
	bool b0k = initWithTexture(nullptr, Rect::ZERO);
	if(b0k)
	{
		this->autorelease();
	}
}

void M2Chips::setPriority(int fixedPriority)
{
	_fixedPriority = fixedPriority;
	_useNodePriority = false;
};

void M2Chips::setPriorityWithThis(bool useNodePriority)
{
	_useNodePriority = useNodePriority;
	_fixedPriority = true;
};

void M2Chips::onEnter()
{
	Sprite::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener -> setSwallowTouches(true);

	listener -> onTouchBegan = [=](Touch* touch, Event * event)
	{
		log("touch Began...");
		Point locationInNode = this->convertToNodeSpace(touch->getLocation());
		Size s = this->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		if(rect.containsPoint(locationInNode))
		{
			this->setColor(Color3B::RED);
			return true;
		}
		return false;
	};

	listener->onTouchMoved=[=](Touch* touch, Event* event)
	{
	};

	listener->onTouchEnded=[=](Touch* touch, Event* event)
	{
		this->setColor(Color3B::WHITE);
	};

	if(_useNodePriority)
	{
		_eventDispatcher -> addEventListenerWithSceneGraphPriority(listener,this);
	}
	else
	{
		_eventDispatcher->addEventListenerWithFixedPriority(listener, _fixedPriority);
	}
	_listener = listener;

}

void M2Chips::onExit()
{
	_eventDispatcher->removeEventListener(_listener);
	Sprite::onExit();
}