#include "Stargame.h"



Stargame::Stargame()
{

}
Stargame::~Stargame()
{

}

Scene* Stargame::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	

	// 'layer' is an autorelease object
	auto layer = Stargame::create();


	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool Stargame::init()
{
	
	//////////////////////////////
	// 1. super init first
	if (!Sprite::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(Stargame::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("bg1.png");
	//设置背景图片全屏
	float winw = visibleSize.width;
	float winh = visibleSize.height;
	float spx = sprite->getTextureRect().getMaxX();
	float spy = sprite->getTextureRect().getMaxY();
	sprite->setScaleX(winw / spx);
	sprite->setScaleY(winh / spy);
	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	//分数条
	score = 0;
	auto scorelabel = Label::create("Score: 0", "fonts/MFYueYuan.otf", 15);
	scorelabel->setTextColor(Color4B(72, 61, 139, 255));
	scorelabel->setAnchorPoint(Vec2(1, 1));
	scorelabel->setPosition(visibleSize.width - 10, visibleSize.height - 10);
	this->addChild(scorelabel);
	
//	getscore();


	//加入星星，且点击发生动画


	this->schedule(schedule_selector(Stargame::addstar), 1.0f);




	return true;

}

void Stargame::addstar(float t)
{
	
	auto star = Stargame::create("star2.png");
	

}
Stargame* Stargame::create(const std::string fileName)
{
	

	Stargame* star = new Stargame();
	if (star && star->initWithFile(fileName))
	{
		star->autorelease();
		ActionInterval * rotateto = RotateBy::create(1.2f, 360);
		auto act = RepeatForever::create(rotateto);
		star->runAction(act);
		int n = rand() % 4;
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

		this->addChild(star);
		return star;
	}
	CC_SAFE_DELETE(star);
	return NULL;
}
bool Stargame::onTouchBegan(Touch *touch, Event *event)
{





	auto sprite = event->getCurrentTarget();
	Size size = sprite->getContentSize();
	Point pos = sprite->getPosition();
	Rect rect = CCRectMake(pos.x - size.width / 2, pos.y - size.height / 2, size.width, size.height);
	Point touchPoint = touch->getLocationInView();
	touchPoint = Director::sharedDirector()->convertToGL(touchPoint);
	if (rect.containsPoint(touchPoint))
	{
		//产生爆炸效果
		auto exp = ParticleExplosion::createWithTotalParticles(10);
		//exp->setColor(Color3B(0, 191, 255));
		exp->setLife(2);
		exp->setStartColor(Color4F(0, 191, 255, 255));
		exp->setStartColorVar(Color4F(70, 130, 180, 255));
		exp->setPosition(sprite->getPosition().x, sprite->getPosition().y);
		sprite->getParent()->addChild(exp);
		//淡出效果
		auto fadeout = FadeOut::create(0.3);
		//sprite->runAction(fadeout);
		auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(Stargame::spritefadeout, this));
		this->runAction(Sequence::create(fadeout, actionMoveDone, NULL));
		//分数条发生变化
		this->score++;
		CCLOG("Score: %0d", score);
	
		
		//CCLOG("score: %0d", StarScene::score);
		/*	auto score = StarScene::
		score++;
		auto label = StarScene::getlabel();
		char strscore[20];
		sprintf(strscore, "Score: %0d", score);
		label->setString(strscore);*/



		/*	AppDelegate *delegate = dynamic_cast<AppDelegate*>(Application::getInstance());

		StarScene* scene1 = dynamic_cast<StarScene*>(delegate->scene->getChildByTag(2));
		scene1->setScore();
		*/








	}
	return false;
}

void Stargame::spritefadeout(Object* pSender)
{

	Stargame *sprite = (Stargame *)pSender;
	sprite->removeFromParent();
}

void Stargame::onEnter()
{

	Sprite::onEnter();
	auto lis = EventListenerTouchOneByOne::create();
	lis->setSwallowTouches(true);
	lis->onTouchBegan = CC_CALLBACK_2(Stargame::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(lis, this);
}
void Stargame::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void Stargame::launcherfromButtom()
{

	int x = rand() % 381 + 50;
	int y = -25;
	this->setPosition(Point(x, y));
	auto destination = Vec2(x, 320 + this->getContentSize().height);
	auto Moveto = MoveTo::create(5, destination);
	auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(Stargame::spriteMoveFinished, this));
	this->runAction(Sequence::create(Moveto, actionMoveDone, NULL));

}

void Stargame::spriteMoveFinished(Object* pSender)
{
	Stargame *sprite = (Stargame *)pSender;
	sprite->removeFromParent();
}

void Stargame::launcherfromUp()
{

	int x = rand() % 381 + 50;
	int y = 345;
	this->setPosition(Point(x, y));
	auto destination = Vec2(x, -this->getContentSize().height);
	auto Moveto = MoveTo::create(5, destination);
	auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(Stargame::spriteMoveFinished, this));
	this->runAction(Sequence::create(Moveto, actionMoveDone, NULL));






}


void Stargame::launcherfromLeft()
{

	int x = -25;
	int y = rand() % 270 + 50;

	this->setPosition(Point(x, y));
	auto destination = Vec2(480 + this->getContentSize().width, y);
	auto Moveto = MoveTo::create(5, destination);
	auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(Stargame::spriteMoveFinished, this));
	this->runAction(Sequence::create(Moveto, actionMoveDone, NULL));






}

void Stargame::launcherfromRight()
{

	int x = 505;

	int y = rand() % 270 + 30;
	this->setPosition(Point(x, y));
	auto destination = Vec2(-this->getContentSize().width, y);
	auto Moveto = MoveTo::create(5, destination);
	auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(Stargame::spriteMoveFinished, this));
	this->runAction(Sequence::create(Moveto, actionMoveDone, NULL));





}
