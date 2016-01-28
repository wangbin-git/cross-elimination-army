//
//  CEAGrid.h
//  cross-elimination-army
//
//  Created by wangbin on 16/1/27.
//
//

#ifndef CEAGrid_h
#define CEAGrid_h

#include "CEACell.h"
#include "CEAConsts.h"

class CEAGrid : public cocos2d::Sprite {
public:
    void initCells();
    
    void initTouchEvents();
    
    CEACell *getCellByIndex(int i, int j);
    
    Vec2 getIndexByLocation(float x, float y);
    
    CEACell *getCellByLocation(float x, float y);
    
    void doCrossElimination(int i, int j);
    
    
public:
    CEACell *m_cells[GRID_MAX_ROW * GRID_MAX_COL];
};


#endif /* CEAGrid_h */
