//
//  CEAGameScene.h
//  cross-elimination-army
//
//  Created by wangbin on 16/1/11.
//
//

#ifndef CEAGameScene_h
#define CEAGameScene_h

const int MAX_GAME_ROW = 10;
const int MAX_GAME_COL = 10;

class CEAGameScene : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(CEAGameScene);
    
    bool initGame();
    
    bool initGrids();
    
    bool initHpMpBar();
    
    bool initTouchEvents();
    
    void updateHPBar(float delta);
    
    void updateHPPercentage(float pt);
    
private:
    
};

#endif /* CEAGameScene_h */
