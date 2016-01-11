//
//  CEAWelcomeScene.cpp
//  cross-elimination-army
//
//  Created by wangbin on 15/11/15.
//
//

#include <stdio.h>
#include "CEAWelcomeScene.h"

USING_NS_CC;

Scene* CEAWelcomeScene::createScene() {
    auto scene = Scene::create();
    
    auto layer = CEAWelcomeScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool CEAWelcomeScene::init() {
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    auto bg = Sprite::create("bg_grid.png");
    bg->setRotation(-90.0f);
    bg->setPosition(Point(visibleSize.width / 2.0, visibleSize.height / 2.0));
    addChild(bg);
    return true;
}


void CEAWelcomeScene::menuCloseCallback(Ref* pSender) {
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}