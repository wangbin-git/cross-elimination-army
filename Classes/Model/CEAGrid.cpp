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
    float cellSize = (visibleSize.width - GRID_START_X * 2) / GRID_MAX_COL;
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
            pCell->setAnchorPoint(Vec2(0, 0));
            pCell->setScale(cellSize / 100.0 * GRID_CELL_DEFAULT_SCALE, cellSize / 100.0 * GRID_CELL_DEFAULT_SCALE);
            pCell->setPosition(Point(i * cellSize + GRID_START_X, j * cellSize + GRID_START_Y));
            m_cells[nIndex] = pCell;
            this->addChild(pCell);
        }
    }
    this->initTouchEvents();
}

void CEAGrid::initTouchEvents() {
    //Create a "one by one" touch event listener (processes one touch at a time)
    auto listener = EventListenerTouchOneByOne::create();
    // When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
    listener->setSwallowTouches(true);
    
    // Example of using a lambda expression to implement onTouchBegan event callback function
    listener->onTouchBegan = [](Touch* touch, Event* event){
        log("sprite onTouchBegan.. ");
        
        // event->getCurrentTarget() returns the *listener's* sceneGraphPriority node.
        auto target = static_cast<CEAGrid*>(event->getCurrentTarget());
        if (target == nullptr) {
            return false;
        }
        
        //Get the position of the current point relative to the button
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
        Vec2 idx = target->getIndexByLocation(locationInNode.x, locationInNode.y);
        target->doCrossElimination(idx.x, idx.y);
//        CEACell *selectedCell = target->getCellByLocation(locationInNode.x, locationInNode.y);
//        if (selectedCell) {
//            selectedCell->setOpacity(50);
//            selectedCell->setScale(1.2, 1.2);
//        }
//        //Check the click area
//        if (rect.containsPoint(locationInNode))
//        {
//            log("contains point");
//            target->setOpacity(180);
//            target->setScale(1.2, 1.2);
//            return true;
//        }
        return false;
    };
    
    //Trigger when moving touch
    listener->onTouchMoved = [](Touch* touch, Event* event){
        log("sprite onTouchMoved.. ");
        //        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        //        //Move the position of current button sprite
        //        target->setPosition(target->getPosition() + touch->getDelta());
    };
    
    //Process the touch end event
    listener->onTouchEnded = [=](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        log("sprite onTouchesEnded.. ");
        target->setOpacity(255);
        target->setScale(1.0, 1.0);
        //Reset zOrder and the display sequence will change
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

CEACell* CEAGrid::getCellByIndex(int i, int j) {
    if (i >= 0 && i < GRID_MAX_ROW && j >= 0 && j < GRID_MAX_COL) {
        return m_cells[i * GRID_MAX_ROW + j];
    }
    return nullptr;
}

CEACell* CEAGrid::getCellByLocation(float x, float y) {
    float deltaX = x - GRID_START_X;
    float deltaY = y - GRID_START_Y;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float cellSize = (visibleSize.width - GRID_START_X * 2) / GRID_MAX_COL;
    int i = deltaX / cellSize;
    int j = deltaY / cellSize;
    log("index: [%d,%d]", i, j);
    return this->getCellByIndex(i, j);
}

Vec2 CEAGrid::getIndexByLocation(float x, float y) {
    float deltaX = x - GRID_START_X;
    float deltaY = y - GRID_START_Y;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float cellSize = (visibleSize.width - GRID_START_X * 2) / GRID_MAX_COL;
    int i = deltaX / cellSize;
    int j = deltaY / cellSize;
    return Vec2(i, j);
}

void CEAGrid::doCrossElimination(int row, int col) {
    CEACell *pCell = this->getCellByIndex(row, col);
    if (pCell) {
        return;
    }
    CEACell* crossEnd[4] = {nullptr, nullptr, nullptr, nullptr};
    for (int i = row + 1; i < GRID_MAX_ROW; i++) {
        CEACell *pTempCell = this->getCellByIndex(i, col);
        if (pTempCell) {
            crossEnd[0] = pTempCell;
            break;
        }
    }
    for (int i = row - 1; i >= 0; i--) {
        CEACell *pTempCell = this->getCellByIndex(i, col);
        if (pTempCell) {
            crossEnd[1] = pTempCell;
            break;
        }
    }
    for (int i = col + 1; i < GRID_MAX_COL; i++) {
        CEACell *pTempCell = this->getCellByIndex(row, i);
        if (pTempCell) {
            crossEnd[2] = pTempCell;
            break;
        }
    }
    for (int i = col - 1; i >= 0; i--) {
        CEACell *pTempCell = this->getCellByIndex(row, i);
        if (pTempCell) {
            crossEnd[3] = pTempCell;
            break;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        if (crossEnd[i] == nullptr) {
            continue;
        }
        for (int j = i + 1; j < 4; j++) {
            if (crossEnd[j] == nullptr) {
                continue;
            }
            if (crossEnd[i]->m_iType == crossEnd[j]->m_iType) {
                crossEnd[i]->m_bMatchFlag = true;
                crossEnd[j]->m_bMatchFlag = true;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (crossEnd[i] == nullptr) {
            continue;
        }
        if (crossEnd[i]->m_bMatchFlag) {
            //crossEnd[i]->setScale(0.1, 0.1);
            crossEnd[i]->setVisible(false);
            int row = crossEnd[i]->m_iRow;
            int col = crossEnd[i]->m_iCol;
            //delete m_cells[row * GRID_MAX_ROW + col];
            m_cells[row * GRID_MAX_ROW + col] = nullptr;
        }
    }
}

