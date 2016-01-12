//
//  CEAGameScene.cpp
//  cross-elimination-army
//
//  Created by wangbin on 16/1/11.
//
//

#include <stdio.h>
#include "CEAGameScene.h"

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
    if ( !Layer::init() )
    {
        return false;
    }
    //auto visibleSize = Director::getInstance()->getVisibleSize();
    //auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
    
    this->setTouchEnabled(bool value)
    
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
    return true;
}

bool CEAGameScene::initGrids() {
    srand((int)time(0));
    auto visibleSize = Director::getInstance()->getVisibleSize();
    int gridBorder = 20; //网格左右距离屏幕边缘的距离
    int gridStartY = 150; //网格开始的Y坐标值
    int nodeSize = (int)((visibleSize.width - 40) / MAX_GAME_COL);
    for (int i = 0; i < MAX_GAME_ROW; i++) {
        for (int j = 0; j < MAX_GAME_COL; j++) {
            int nRandType = rand() % 15;
            if (nRandType >= 10) {
                nRandType = 9;
                continue;
            }
            int nIndex = i * MAX_GAME_COL + j;
            Rect nodeRect = Rect(nRandType * 100, 0, 100, 100);
            Sprite *pNode = Sprite::create("cells_brick.png", nodeRect);
            pNode->setScale(nodeSize / 100.0 * 0.95, nodeSize / 100.0 * 0.95);
            pNode->setPosition(Point(i * nodeSize + gridBorder + nodeSize / 2.0, j * nodeSize + gridStartY));
            this->addChild(pNode, 100, nIndex);
        }
    }
    return true;
}


void CEAGameScene::menuCloseCallback(Ref* pSender) {
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}