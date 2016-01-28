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
    
public:
    CEACell *m_cells[GRID_MAX_ROW * GRID_MAX_COL];
};


#endif /* CEAGrid_h */
