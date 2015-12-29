#ifndef _MAINPAGE_H
#define _MAINPAGE_H
#include "cocos2d.h"
#include "ui\UIButton.h"
USING_NS_CC;
using namespace ui;

class MainPage : public cocos2d::Layer
{
public:
	MainPage();
	~MainPage();
	CREATE_FUNC(MainPage);
	static Scene* createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	void touchevent(Ref* psender, TouchEventType type);
private:

	
};






#endif  //_MAINPAGE_H