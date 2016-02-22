//
//  CEAProgressBar.cpp
//  cross-elimination-army
//
//  Created by wangbin on 16/2/21.
//
//

#include <stdio.h>

#include "CEAProgressBar.h"

CEAProgressBar* CEAProgressBar::create()
{
    CEAProgressBar *sprite = new CEAProgressBar();
    if (sprite && sprite->init())
    {
        sprite->m_bReversed = false;
        sprite->m_percentage = 0.0;
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

void CEAProgressBar::setRect(cocos2d::Rect rect) {
    this->m_customRect = rect;
}

Rect CEAProgressBar::getRect() {
    return m_customRect;
}

void CEAProgressBar::setOutlineColor(Color4F c) {
    m_outlineColor = c;
}

void CEAProgressBar::setFillColor(Color4F c) {
    m_fillColor = c;
}

void CEAProgressBar::setPercentage(float pt) {
    if (pt >= 0.0 && pt <= 1.0) {
        m_percentage = pt;
    } else if (pt > 1.0) {
        m_percentage = 1.0;
    } else {
        m_percentage = 0.0;
    }
}

float CEAProgressBar::getPercentage() {
    return m_percentage;
}

void CEAProgressBar::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) {
    this->removeAllChildren();
    DrawNode *pDN = DrawNode::create();
    this->addChild(pDN);
    pDN->setLineWidth(3);
    Vec2 start = m_customRect.origin;
    Vec2 end = Vec2(start.x + m_customRect.size.width, start.y + m_customRect.size.height);
    Vec2 percentEnd = Vec2(start.x + m_customRect.size.width * m_percentage, start.y + m_customRect.size.height);
    pDN->drawRect(start, end, m_outlineColor);
    pDN->drawSolidRect(start, percentEnd, m_fillColor);
}