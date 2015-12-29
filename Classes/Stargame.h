#ifndef _STARGAME_
#define _STARGAME_
#include "cocos2d.h"
USING_NS_CC;

class Stargame : public cocos2d::Sprite
{
	Stargame();
	~Stargame();
private:


public:

	int score;
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Stargame);
	Stargame *create(const std::string fileName);
	virtual bool onTouchBegan(Touch *touch, Event *event);
	virtual void onEnter();
	void launcherfromButtom();
	void launcherfromUp();
	void launcherfromLeft();
	void launcherfromRight();
	void menuCloseCallback(cocos2d::Ref* pSender);
	void addstar(float t);
	void spriteMoveFinished(Object* pSender);
	void spritefadeout(Object* pSender);
};






#endif  //_STARGAME_