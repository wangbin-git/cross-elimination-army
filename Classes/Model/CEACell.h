//
//  CEACell.h
//  cross-elimination-army
//
//  cell class in game scene
//  inherit from Cocos2d::Sprite
//  Created by wangbin on 16/1/27.
//



#ifndef CEACell_h
#define CEACell_h

USING_NS_CC;

class CEACell : public cocos2d::Sprite {
    
public:
    
    static CEACell* create(const std::string& filename, const Rect& rect);
    
    void setCell(int row, int col, int type);

public:
    int m_iRow;        // row index of cell
    int m_iCol;        // column index of cell
    int m_iType;       // type index of cell
};



#endif /* CEACell_h */
