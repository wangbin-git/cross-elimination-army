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
    
    bool ret = initGame();
    //ret = initTouchEvents();
    return ret;
}

bool CEAGameScene::initTouchEvents() {
    //Create a "one by one" touch event listener (processes one touch at a time)
    auto listener1 = EventListenerTouchOneByOne::create();
    // When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
    listener1->setSwallowTouches(true);
    
    // Example of using a lambda expression to implement onTouchBegan event callback function
    listener1->onTouchBegan = [](Touch* touch, Event* event){
        log("sprite onTouchBegan.. ");

        // event->getCurrentTarget() returns the *listener's* sceneGraphPriority node.
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        //Get the position of the current point relative to the button
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        //Check the click area
        if (rect.containsPoint(locationInNode))
        {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setOpacity(180);
            target->setScale(1.2, 1.2);
            return true;
        }
        return false;
    };
    
    //Trigger when moving touch
    listener1->onTouchMoved = [](Touch* touch, Event* event){
        log("sprite onTouchMoved.. ");

//        auto target = static_cast<Sprite*>(event->getCurrentTarget());
//        //Move the position of current button sprite
//        target->setPosition(target->getPosition() + touch->getDelta());
    };
    
    //Process the touch end event
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        log("sprite onTouchesEnded.. ");
        target->setOpacity(255);
        //Reset zOrder and the display sequence will change
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
    return true;
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
    return true;
}


void CEAGameScene::menuCloseCallback(Ref* pSender) {
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}