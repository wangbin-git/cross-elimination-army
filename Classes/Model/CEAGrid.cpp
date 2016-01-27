//
//  CEAGrid.cpp
//  cross-elimination-army
//
//  Created by wangbin on 16/1/27.
//
//

#include <stdio.h>
#include "CEAGrid.h"

USING_NS_CC;

void CEAGrid::initCells() {
    srand((int)time(0));
    auto visibleSize = Director::getInstance()->getVisibleSize();
    int cellSize = (int)((visibleSize.width - GRID_START_X * 2) / GRID_MAX_COL);
    for (int i = 0; i < GRID_MAX_ROW; i++) {
        for (int j = 0; j < GRID_MAX_COL; j++) {
            int nIndex = i * GRID_MAX_COL + j;
            int nRandType = rand() % (CELLS_TYPE_COUNT + 5);
            if (nRandType >= CELLS_TYPE_COUNT) {
                m_cells[nIndex] = nullptr;
                continue;
            }
            Rect nodeRect = Rect(nRandType * 100, 0, 100, 100); //100是资源图片中每个cell的宽高
            CEACell *pCell = CEACell::create("cells_circle.png", nodeRect);
            pCell->setCell(i, j, nRandType);
            pCell->setScale(cellSize / 100.0 * GRID_CELL_DEFAULT_SCALE, cellSize / 100.0 * GRID_CELL_DEFAULT_SCALE);
            pCell->setPosition(Point(i * cellSize + GRID_START_X + cellSize / 2.0, j * cellSize + GRID_START_Y));
            m_cells[nIndex] = pCell;
            this->addChild(pCell);
        }
    }
}
