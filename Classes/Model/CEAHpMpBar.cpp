//
//  CEAHpMpBar.cpp
//  cross-elimination-army
//
//  Created by wangbin on 16/2/4.
//
//

#include <stdio.h>
#include "CEAHpMpBar.h"
#include "CEAConsts.h"
#include "CEAProgressBar.h"

USING_NS_CC;

void CEAHpMpBar::initBar() {
//    Sprite *pHpMpBarBg = Sprite::create("hpmp_bar_bg.png");
//    pHpMpBarBg->setPosition(Vec2(GRID_START_X, 0));
//    pHpMpBarBg->setAnchorPoint(Vec2(0,0));
//    pHpMpBarBg->setScale(0.25, 0.25);
//    this->addChild(pHpMpBarBg);
    
    CEAProgressBar *pPb = CEAProgressBar::create();
    this->addChild(pPb);
    //
//    DrawNode *pdn = DrawNode::create();
//    this->addChild(pdn);
//    pdn->drawRect(Vec2(20, 20), Vec2(40, 40), Color4F(1.0f, 0.0f, 0.0f, 0.5f));
    
}

void CEAHpMpBar::initHpBar() {
//    Sprite* pSpriteProgressBg = CCSprite::create(s_bg_time);
//    pSpriteProgressBg->setPosition(ccp(37, 443));
//    pSpriteProgressBg->setAnchorPoint(ccp(0, 0));
//    this->addChild(pSpriteProgressBg, 2, kTagBgProgress);
//    
//    CCProgressTimer* pProgressTimer = CCProgressTimer::create(CCSprite::create(s_fg_time));
//    pProgressTimer->setType(kCCProgressTimerTypeBar);
//    pProgressTimer->setMidpoint(ccp(1, 0));
//    pProgressTimer->setBarChangeRate(ccp(1, 0));
//    pProgressTimer->setPercentage(0);
//    pProgressTimer->setPosition(ccp(38, 444));
//    pProgressTimer->setAnchorPoint(ccp(0, 0));
//    this->addChild(pProgressTimer, 3, kTagProgress);
    
}

void CEAHpMpBar::initMpBar() {
    
}