#ifndef _LEVELONE_H
#define _LEVELONE_H
#include "cocos2d.h"
USING_NS_CC;

class LevelOne : public cocos2d::Layer
{
public:
	static int lostscore;
	static Label* scorelabel;
	static int score;
	LevelOne();
	~LevelOne();
	CREATE_FUNC(LevelOne);
	static Scene* createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	void addstar(float t);
private:


};




#endif  //_LEVELONE_H