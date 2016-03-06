//
//  CEAGameInfoWin_h
//  cross-elimination-army
//
//  Created by wangbin on 16/2/26.
//
//

#ifndef CEAGameInfoWin_h
#define CEAGameInfoWin_h


class CEAGameInfoWin : public cocos2d::Sprite {
    
public:
    
    static CEAGameInfoWin* create();
    
public:
    
    cocos2d::__String m_sInfo;
    
};

#endif /* CEAGameInfoWin_h */
