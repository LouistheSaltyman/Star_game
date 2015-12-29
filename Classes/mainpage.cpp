#include "mainpage.h"
#include "ui\UIListView.h"
#include "StarScene.h"

MainPage::MainPage()
{

}
MainPage::~MainPage()
{

}

Scene* MainPage::createScene()
{


	// 'scene' is an autorelease object
	auto scene = Scene::create();


	// 'layer' is an autorelease object
	auto layer = MainPage::create();


	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
bool MainPage::init()
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
		CC_CALLBACK_1(MainPage::menuCloseCallback, this));

	closeItem->setScale(visibleSize.width / 16 / closeItem->getContentSize().width);
	closeItem->setAnchorPoint(Vec2(1, 0));
	closeItem->setPosition(visibleSize.width, 10);
	

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("bg2.png");
	float winw = visibleSize.width;
	float winh = visibleSize.height;
	float spx = sprite->getTextureRect().getMaxX();
	float spy = sprite->getTextureRect().getMaxY();
	sprite->setScaleX(winw / spx);
	sprite->setScaleY(winh / spy);
	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite);

	

	//添加开始按钮
	auto startButton = Button::create("button1.png");
	startButton->setTitleText("Start");
	//startButton->setAnchorPoint(Vec2(0, 0));
	startButton->setScale(visibleSize.width / 4 / startButton->getContentSize().width);
	startButton->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
	startButton->setTitleFontName("fonts/MFYueYuan.otf");
	startButton->addTouchEventListener(this, toucheventselector(MainPage::touchevent));
	this->addChild(startButton);
//	//添加帮助按钮
//	auto helpButton = Button::create("button1.png");
//	helpButton->setTitleText("Help");
////	helpButton->setAnchorPoint(Vec2(1, 0));
//	helpButton->setScale(visibleSize.width / 4 / helpButton->getContentSize().width);
//	helpButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - helpButton->getContentSize().height));
//	helpButton->setTitleFontName("fonts/MFYueYuan.otf");
//	this->addChild(helpButton);
//
	return true;
}

void MainPage::touchevent(Ref* psender, TouchEventType type)
{
	switch (type)
	{
	case TOUCH_EVENT_BEGAN:
		Director::sharedDirector()->replaceScene(TransitionFadeTR::create(1, StarScene::createScene()));
		break;
	}

}



void MainPage::menuCloseCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

}