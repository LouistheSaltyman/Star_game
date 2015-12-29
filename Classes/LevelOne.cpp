#include "LevelOne.h"
#include "mainpage.h"
#include "Star.h"
#include"endScene.h"




LevelOne::LevelOne()
{


}
LevelOne::~LevelOne()
{


}
Scene* LevelOne::createScene()
{


	// 'scene' is an autorelease object
	auto scene = Scene::create();


	// 'layer' is an autorelease object
	auto layer = LevelOne::create();


	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

int LevelOne::score;
Label* LevelOne::scorelabel;
int LevelOne::lostscore;



bool LevelOne::init()
{


	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
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
		CC_CALLBACK_1(LevelOne::menuCloseCallback, this));
	closeItem->setScale(visibleSize.width / 16 / closeItem->getContentSize().width);
	closeItem->setAnchorPoint(Vec2(1, 0));
	closeItem->setPosition(visibleSize.width, 0 + 10);

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("bg5.png");
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
	scorelabel = Label::create("Score: 0", "fonts/Marker Felt.ttf", 15);
	scorelabel->setTextColor(Color4B(127, 255, 212, 255));
	scorelabel->setAnchorPoint(Vec2(1, 1));
	scorelabel->setPosition(visibleSize.width - 10, visibleSize.height - 10);
	scorelabel->setScale(1.5);
	this->addChild(scorelabel);
	//
	score = 0;
	lostscore = 0;
	//加入星星，且点击发生动画

	this->schedule(schedule_selector(LevelOne::addstar), 0.5f);



	return true;
}

void LevelOne::menuCloseCallback(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(MainPage::createScene());
}

void LevelOne::addstar(float t)
{
	if (lostscore < 6)
	{
		int n = rand() % 4;
		if (n == 0)
		{
			auto star = Star::create("star6.png");
			addChild(star);
		}
		else
		{
			auto star = Star::create("star5.png");
			addChild(star);
		}
	}
	else
	{
		Director::sharedDirector()->replaceScene(EndScene::createScene());
	}

}

//int LevelOne::getscore()
//{
//	int newscore = score;
//	return newscore;
//
//}
//Label* LevelOne::getlabel()
//{
//	auto label = scorelabel;
//	return label;
//
//}
//void LevelOne::setScore()
//{
//	//分数条改变
//	score++;
//	char strscore[20];
//	sprintf(strscore, "Score : %0d", score);
//	scorelabel->setString(strscore);
//
//
//}