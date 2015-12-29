#include"endScene.h"
#include "StarScene.h"
EndScene::EndScene()
{

}
EndScene::~EndScene()
{

}
Scene* EndScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();


	// 'layer' is an autorelease object
	auto layer = EndScene::create();


	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
bool EndScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	


	// 添加背景
	auto sprite = Sprite::create("bg2.png");
	float winw = visibleSize.width;
	float winh = visibleSize.height;
	float spx = sprite->getTextureRect().getMaxX();
	float spy = sprite->getTextureRect().getMaxY();
	sprite->setScaleX(winw / spx);
	sprite->setScaleY(winh / spy);//设置背景全屏
	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite);

	//添加显示条gmaeover
	auto label = Label::create("Game Over, You Missed More Than 5 Stars ", "Marker Felt.ttf", 25);
	label->setDimensions(300, 70);
	label->setTextColor(Color4B(0, 0, 205, 225));
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(label);




	//添加重新开始按钮
	auto restartItem = Button::create("007.png");
	restartItem->setTitleText("Restart");
	//restartItem->setAnchorPoint(Vec2(0, 0));
	restartItem->setScale(visibleSize.width / 4 / restartItem->getContentSize().width);
	restartItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + restartItem->getContentSize().height));
	restartItem->setTitleFontName("fonts/MFYueYuan.otf");
	restartItem->addTouchEventListener(this, toucheventselector(EndScene::touchevent));
	this->addChild(restartItem);


	//添加退出按钮
	auto startButton = Button::create("007.png");
	startButton->setTitleText("Exit");
	//startButton->setAnchorPoint(Vec2(0, 0));
	startButton->setScale(visibleSize.width / 4 / startButton->getContentSize().width);
	startButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - startButton->getContentSize().height));
	startButton->setTitleFontName("fonts/MFYueYuan.otf");
	startButton->addTouchEventListener(this, toucheventselector(EndScene::end));
	this->addChild(startButton);
	auto closeItem = MenuItem::create();
	//closeItem->set

	return true;
}
void EndScene::end(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void EndScene::touchevent(Ref* psender, TouchEventType type)
{
	
	Director::sharedDirector()->replaceScene(StarScene::createScene());



}