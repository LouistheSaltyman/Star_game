#include "Star.h"
#include "StarScene.h"


Star::Star()
{

}
Star::~Star()
{

}


Star* Star::create(const std::string &fileName)
{
	Star* star = new Star();
	if (star && star->initWithFile(fileName))
	{
		
		if (fileName == "star5.png")
		{
			star->setTag(5);
			CCLOG("Set the Tag 5 Success");
		}
		else
		{
			star->setTag(6); 
			CCLOG("Set the Tag 6 Success");
		}
		auto visblesizeWith = Director::sharedDirector()->getVisibleSize().width;
		star->setScale((visblesizeWith/15)/star->getContentSize().width);
		star->autorelease();
		ActionInterval * rotateto = RotateBy::create(1.2f, 360);
		auto act = RepeatForever::create(rotateto);
		star->runAction(act);
		int n = rand()%4 ;
	
		switch (n)
		{	
		case 0:
			star->launcherfromButtom();
			break;
		case 1:
			star->launcherfromLeft();
			break;
		case 2:
			star->launcherfromUp();
			break;
		case 3:
			star->launcherfromRight();
			break;
		}

		return star;
	}
	CC_SAFE_DELETE(star);
	return NULL;
}


bool Star::onTouchBegan(Touch *touch, Event *event)
{	
	auto sprite = event->getCurrentTarget();
	Size size = sprite->getContentSize();
	Point pos = sprite->getPosition();
	Rect rect = CCRectMake(pos.x - size.width / 2, pos.y - size.height / 2, size.width, size.height);
	Point touchPoint = touch->getLocationInView();
	touchPoint = Director::sharedDirector()->convertToGL(touchPoint);
	if (rect.containsPoint(touchPoint))
	{
		if (sprite->getTag() == 5)
		{	
			//产生爆炸效果
			auto exp = ParticleExplosion::createWithTotalParticles(10);
			exp->setLife(2);
			exp->setStartColor(Color4F(0, 191, 255, 255));
			exp->setStartColorVar(Color4F(70, 130, 180, 255));
			exp->setPosition(sprite->getPosition().x, sprite->getPosition().y);
			sprite->getParent()->addChild(exp);
			CCLOG("The Tag Is 5");
		}
		else
		{
			//产生爆炸效果
			auto exp = ParticleExplosion::createWithTotalParticles(10);
			exp->setLife(2);
			exp->setStartColor(Color4F(0, 0, 205, 255));
			//exp->setStartColorVar(Color4F(0, 0, 139, 255));
			exp->setPosition(sprite->getPosition().x, sprite->getPosition().y);
			sprite->getParent()->addChild(exp);
			CCLOG("The Tag Is Not 5");
		}
		//淡出效果
		auto fadeout = FadeOut::create(0.3);
		//sprite->runAction(fadeout);
		auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(Star::spritefadeout, this));
		this->runAction(Sequence::create(fadeout, actionMoveDone, NULL));

		//分数条发生变化
	
		//CCLOG("score: %0d", StarScene::score);
		StarScene::score++;
		char strscore[20];
		sprintf(strscore, "Score: %0d", StarScene::score);
		StarScene::scorelabel->setString(strscore);
	
	}
	return false;
}
//淡出后删除star，释放内存
void Star::spritefadeout(Object* pSender)
{
	Star *sprite = (Star *)pSender;
	sprite->removeFromParent();
	
}

void Star::onEnter()
{	

	Sprite::onEnter();
	auto lis = EventListenerTouchOneByOne::create();
	lis->setSwallowTouches(true);	
	lis->onTouchBegan = CC_CALLBACK_2(Star::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(lis, this);

}
void Star::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void Star::launcherfromButtom()
{
	
	int x = rand() % 381 + 50;
	int y = -25;
	this->setPosition(Point(x,y));
	auto destination = Vec2(x, 320 + this->getContentSize().height);
	auto Moveto = MoveTo::create(5, destination);

	auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(Star::spriteMoveFinished, this));
	this->runAction(Sequence::create(Moveto, actionMoveDone, NULL));

}

void Star::spriteMoveFinished(Object* pSender)
{
	Star *sprite = (Star *)pSender;
	sprite->removeFromParent();
	StarScene::lostscore++;
}

void Star::launcherfromUp()
{
	
	
	int x = rand() % 381 + 50;
	int y = 345;
	this->setPosition(Point(x, y));
	auto destination = Vec2(x, -this->getContentSize().height);
	auto Moveto = MoveTo::create(5, destination);
	auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(Star::spriteMoveFinished, this));
	this->runAction(Sequence::create(Moveto, actionMoveDone, NULL));
	
	




}


void Star::launcherfromLeft()
{

	int x = -25;
	int y = rand() % 270 + 50;
	
	this->setPosition(Point(x, y));
	auto destination = Vec2(480 + this->getContentSize().width, y);
	auto Moveto = MoveTo::create(5, destination);
	auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(Star::spriteMoveFinished, this));
	this->runAction(Sequence::create(Moveto, actionMoveDone, NULL));
	





}

void Star::launcherfromRight()
{
	
	int x = 505;

	int y = rand() % 270 + 30;
	this->setPosition(Point(x, y));
	auto destination = Vec2(-this->getContentSize().width, y);
	auto Moveto = MoveTo::create(5, destination);
	auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(Star::spriteMoveFinished, this));
	this->runAction(Sequence::create(Moveto, actionMoveDone, NULL));
	




}
