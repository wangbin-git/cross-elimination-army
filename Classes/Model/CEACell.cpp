//
//  CEACell.cpp
//  cross-elimination-army
//
//  Created by wangbin on 16/1/27.
//
//

#include <stdio.h>
#include "CEACell.h"


CEACell* CEACell::create(const std::string &filename, const cocos2d::Rect &rect) {
    CEACell *pCell = new CEACell();
    if (pCell && pCell->initWithFile(filename, rect))
    {
        pCell->autorelease();
        return pCell;
    }
    CC_SAFE_DELETE(pCell);
    return nullptr;
}

void CEACell::setCell(int row, int col, int type) {
    m_iRow = row;
    m_iCol = col;
    m_iType = type;
}