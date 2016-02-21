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
        sprite->m_customRect = Rect(20, 970, 300, 20);
        sprite->m_outlineColor = Color4B(255, 0, 0, 255);
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

void CEAProgressBar::setRect(cocos2d::Rect rect) {
    this->m_customRect = rect;
}

void CEAProgressBar::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) {
//    glLineWidth(1.0f);
//    glClearColor(m_outlineColor.r, m_outlineColor.g, m_outlineColor.b, m_outlineColor.a);
//    Vec2 origin = m_customRect.origin;
//    Vec2 destination = Vec2(m_customRect.origin.x + m_customRect.size.width, m_customRect.origin.y + m_customRect.size.height);
//    Color4F color = Color4F(1.0, 0.0, 0.0, 0.5);
//    drawRect(origin, destination, color);
    
    DrawNode *pDN = DrawNode::create();
    this->addChild(pDN);
    pDN->setLineWidth(10);
    pDN->drawRect(Vec2(20, 20), Vec2(60, 60), Color4F(1.0f, 0.0f, 0.0f, 0.5f));

    
    
    //DrawNode::drawRect(m_customRect.origin, Vec2(m_customRect.origin.x + m_customRect.size.width, m_customRect.origin.y + m_customRect.size.height), Color4F(1.0, 0.0, 0.0, 0.0));
    //ccDrawRect(m_customRect.origin, Vec2(m_customRect.origin.x + m_customRect.size.width, m_customRect.origin.y + m_customRect.size.height));
}