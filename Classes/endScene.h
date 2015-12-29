#ifndef _ENDSCENE_H
#define _ENDSCENE_H
#include "cocos2d.h"
#include "ui\UIButton.h"
USING_NS_CC;
using namespace ui;

class EndScene : public cocos2d::Layer
{
public:
	EndScene();
	~EndScene();
	CREATE_FUNC(EndScene);
	static Scene* createScene();
	virtual bool init();
	void end(cocos2d::Ref* pSender);
	void touchevent(Ref* psender, TouchEventType type);
private:


};






#endif  //_MAINPAGE_H