//
//  CEAMainScene.h
//  cross-elimination-army
//
//  Created by wangbin on 15/10/15.
//
//

#ifndef CEAMainScene_h
#define CEAMainScene_h

const int MAX_GAME_ROW = 15;
const int MAX_GAME_COL = 23;

class CEAMainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(CEAMainScene);
    
    void initGame();
    
private:
    char m_BlocksType[MAX_GAME_ROW * MAX_GAME_COL];
    bool m_bRunGame;
    bool m_bBaoJi;
};

#endif /* CEAMainScene_h */
