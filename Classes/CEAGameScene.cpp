//
//  CEAGameScene.cpp
//  cross-elimination-army
//
//  Created by wangbin on 16/1/11.
//
//

#include <stdio.h>
#include "CEAGameScene.h"
#include "CEAGrid.h"
#include "CEAProgressBar.h"
USING_NS_CC;

Scene* CEAGameScene::createScene() {
    auto scene = Scene::create();
    
    auto layer = CEAGameScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool CEAGameScene::init() {
    //////////////////////////////
    // 1. super init first
    //if ( !Layer::init() )
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
    {
        return false;
    }
    //auto visibleSize = Director::getInstance()->getVisibleSize();
    //auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
    
    //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    bool ret = initGame();
    
    return ret;
}

bool CEAGameScene::initGame() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
    
    Sprite *startButton = Sprite::create("restart.png");
    
    startButton->setPosition(Point(visibleSize.width / 2.0, visibleSize.height / 2.0));
    //this->addChild(startButton, 2);
    initGrids();
    initHpMpBar();
    //this->schedule(schedule_selector(CEAGameScene::updateHPBar), 1);
    this->scheduleUpdate();
    return true;
}

bool CEAGameScene::initGrids() {
//    srand((int)time(0));
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//    int gridBorder = 20; //网格左右距离屏幕边缘的距离
//    int gridStartY = 150; //网格开始的Y坐标值
//    int nodeSize = (int)((visibleSize.width - 40) / MAX_GAME_COL);
//    for (int i = 0; i < MAX_GAME_ROW; i++) {
//        for (int j = 0; j < MAX_GAME_COL; j++) {
//            int nRandType = rand() % 15;
//            if (nRandType >= 10) {
//                nRandType = 9;
//                continue;
//            }
//            int nIndex = i * MAX_GAME_COL + j;
//            Rect nodeRect = Rect(nRandType * 100, 0, 100, 100);
//            Sprite *pNode = Sprite::create("cells_circle.png", nodeRect);
//            pNode->setScale(nodeSize / 100.0 * 0.95, nodeSize / 100.0 * 0.95);
//            pNode->setPosition(Point(i * nodeSize + gridBorder + nodeSize / 2.0, j * nodeSize + gridStartY));
//            this->addChild(pNode, 100, nIndex);
//        }
//    }
    CEAGrid *pGrid = new CEAGrid();
    pGrid->initCells();
    this->addChild(pGrid);
    
//    CEAHpMpBar *phpmp = new CEAHpMpBar();
//    phpmp->initBar();
//    this->addChild(phpmp);
    
    return true;
}

bool CEAGameScene::initHpMpBar() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    CEAProgressBar *pMP = CEAProgressBar::create();
    pMP->setFillColor(Color4F(0.0, 0.0, 1.0, 0.9));
    pMP->setOutlineColor(Color4F(0.5, 0.5, 0.8, 1.0));
    pMP->setRect(Rect(20, visibleSize.height - 120, visibleSize.width - 40, 15));
    pMP->setPercentage(0.0);
    this->addChild(pMP, 100, TAG_MP_BAR);
    
    CEAProgressBar *pHP = CEAProgressBar::create();
    pHP->setFillColor(Color4F(1.0, 0.0, 0.0, 0.9));
    pHP->setOutlineColor(Color4F(1.0, 0.2, 0.2, 1.0));
    pHP->setRect(Rect(20, visibleSize.height - 100, visibleSize.width - 40, 15));
    pHP->setPercentage(1.0);
    this->addChild(pHP, 101, TAG_HP_BAR);
    
    return true;
}

void CEAGameScene::updateHPBar(float delta) {
    this->updateHPPercentage(-0.05);
}

void CEAGameScene::update(float dt) {
    log("CEAGameScene::update");
    this->updateHPPercentage(-0.01);
}


void CEAGameScene::updateHPPercentage(float pt) {
    

//        CCProgressTimer* pProgressTimer = (CCProgressTimer*)this->getChildByTag(kTagProgress);
//        pProgressTimer->setPercentage(fPercentage + pProgressTimer->getPercentage());
//        if (100 <= pProgressTimer->getPercentage())
//        {
//            pProgressTimer->setPercentage(0);
//            unschedule(schedule_selector(MainScene::updateProgress));
//            overGame();
//        }
    
    CEAProgressBar* pProgressBar = (CEAProgressBar*)this->getChildByTag(TAG_HP_BAR);
    pProgressBar->setPercentage(pProgressBar->getPercentage() + pt);
    if (pProgressBar->getPercentage() <= 0.0) {
        //unschedule(schedule_selector(CEAGameScene::updateHPBar));
        this->unscheduleUpdate();
        log("game is over");
    }
}


void CEAGameScene::menuCloseCallback(Ref* pSender) {
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}