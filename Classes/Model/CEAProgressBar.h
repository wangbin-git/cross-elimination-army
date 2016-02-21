//
//  CEAProgressBar.h
//  cross-elimination-army
//
//  Created by wangbin on 16/2/21.
//
//

#ifndef CEAProgressBar_h
#define CEAProgressBar_h

USING_NS_CC;

class CEAProgressBar : public Sprite {
public:
    static CEAProgressBar *create();
    
    //重载绘制函数
    void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags);
    
    void setRect(Rect rect);
    
    void setPercentage(float pt);
    
    float getPercentage();

    
public:
    
    bool m_bReversed; // 是否是反向的, 默认是正向(以左边为基准为正向, 以右边为基准为方向)
    
    Rect m_customRect; //progress bar所在rect
    
    Color4B m_fillColor;
    
    Color4B m_outlineColor;
    
private:
    float m_percentage;
};



#endif /* CEAProgressBar_h */
