//
//  CEAMainScene.h
//  cross-elimination-army
//
//  Created by wangbin on 15/10/15.
//
//

#ifndef CEAMainScene_h
#define CEAMainScene_h

class CEAMainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(CEAMainScene);
};

#endif /* CEAMainScene_h */
