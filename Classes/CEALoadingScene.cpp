//
//  CEALoadingScene.cpp
//  cross-elimination-army
//
//  Created by wangbin on 15/11/15.
//
//

#include <stdio.h>
#include "CEALoadingScene.h"
#include "CEAWelcomeScene.h"
#include "CEAGameScene.h"

USING_NS_CC;

Scene* CEALoadingScene::createScene() {
    auto scene = Scene::create();
    
    auto layer = CEALoadingScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool CEALoadingScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();

    auto bg = Sprite::create("Default@2x.png");
    //back->setRotation(-90.0f);
    bg->setPosition(Point(visibleSize.width / 2.0, visibleSize.height / 2.0));
    addChild(bg);
    schedule(schedule_selector(CEALoadingScene::logic));
    return true;
}


void CEALoadingScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void CEALoadingScene::loadResources() {
    numOfLoadedResources++;
}

void CEALoadingScene::logic(float dt) {
    if (numOfLoadedResources == 0) {
        this->loadResources();
    } else if (numOfLoadedResources == 1) {
        auto scene = CEAGameScene::createScene();
        Director::getInstance()->replaceScene(scene);
    }
}