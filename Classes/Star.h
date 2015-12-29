#ifndef _STAR_H
#define _STAR_H
#include "cocos2d.h"
USING_NS_CC;

class Star : public cocos2d::Sprite
{
	Star();
	~Star();
private:


public:
	
	//CREATE_FUNC(Star);
	static Star *create(const std::string &fileName);
	virtual bool onTouchBegan(Touch *touch, Event *event);
	virtual void onEnter();
	void launcherfromButtom();
	void launcherfromUp();
	void launcherfromLeft();
	void launcherfromRight();
	void menuCloseCallback(cocos2d::Ref* pSender);
	void spriteMoveFinished(Object* pSender);
	void spritefadeout(Object* pSender);
};






#endif  //_STAR_H