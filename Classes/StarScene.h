#ifndef _STARSCENE_H
#define _STARSCENE_H
#include "cocos2d.h"
USING_NS_CC;

class StarScene : public cocos2d::Layer
{
public:
	static int lostscore;
	static Label* scorelabel;
	static int score;
	StarScene();
	~StarScene();
	CREATE_FUNC(StarScene);
	static Scene* createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	void addstar(float t);
private:


};




#endif  //_STARSCENE_H