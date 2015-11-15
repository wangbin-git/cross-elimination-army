//
//  CEAMainScene.cpp
//  cross-elimination-army
//
//  Created by wangbin on 15/10/15.
//
//

#include <stdio.h>
#include "CEAConsts.h"
#include "CEAMainScene.h"


enum CrossTag{
    kTagStart,
    kTagProgress,
    kTagBatchNode,
    kTagScore,
    kTagBgProgress,
    kTagRestart,
    kTagBatchDot,
    kTagBaoJi,
};

const int EMPTY_BLOCK = 10;
static const char g_gamescore[] = "\xe6\xb8\xb8\xe6\x88\x8f\xe5\xbe\x97\xe5\x88\x86";//游戏得分
static const char g_restart[]	= "\xe5\x86\x8d\xe7\x8e\xa9\xe4\xb8\x80\xe6\xac\xa1";//再玩一次
static const char g_baoji[]		= "\xe6\x9a\xb4\xe5\x87\xbb";//暴击

USING_NS_CC;

Scene* CEAMainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CEAMainScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CEAMainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    

    this->initGame();
    /*
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(CEAMainScene::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    */
    return true;
}


void CEAMainScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void CEAMainScene::initGame()
{
    m_bRunGame = false;
    m_bBaoJi = false;
    
    Sprite *pSpriteBg = Sprite::create(s_bg_frame);
    //  默认描点位于图片中心点
    Size visibleSize = Director::getInstance()->getVisibleSize();
    pSpriteBg->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    //pSpriteBg->setAnchorPoint(Vec2(0, 0));
    this->addChild(pSpriteBg, 1);
    
//    Sprite *pSpriteStart = Sprite::create(s_start);
//    pSpriteStart->setPosition(Vec2(0, 0));
//    //pSpriteStart->setAnchorPoint(Vec2(0, 0));
//    this->addChild(pSpriteStart, 0, kTagStart);
    //
    //	CCControlSlider* pSliderVolume = CCControlSlider::create(s_sliderTrack, s_sliderTrack, s_sliderThumb);
    //	pSliderVolume->setMaximumValue(25.0f);
    //	pSliderVolume->setMinimumValue(0.0f);
    //	pSliderVolume->setValue(10.0f);
    //	pSliderVolume->setPosition(ccp(540, 6));
    //	pSliderVolume->setAnchorPoint(ccp(0, 0));
    //	pSliderVolume->addTargetWithActionForControlEvents(this, cccontrol_selector(MainScene::updateVolume), CCControlEventValueChanged);
    //	this->addChild(pSliderVolume, 1);
    
//    Label *pLabelBaoJi = Label::createWithSystemFont(g_baoji, "Arial", 10);
//    pLabelBaoJi->setPosition(Vec2(20, 13));
//    pLabelBaoJi->setAnchorPoint(Vec2(0, 0));
//    this->addChild(pLabelBaoJi, 1, kTagBaoJi);
}


