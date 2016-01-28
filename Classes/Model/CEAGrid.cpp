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
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        //Get the position of the current point relative to the button
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
        //Check the click area
        if (rect.containsPoint(locationInNode))
        {
            log("contains point");
            target->setOpacity(180);
            target->setScale(1.2, 1.2);
            return true;
        }
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

