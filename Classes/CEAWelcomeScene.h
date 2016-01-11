//
//  CEAWelcomeScene.h
//  cross-elimination-army
//
//  Created by wangbin on 15/11/15.
//
//

#ifndef CEAWelcomeScene_h
#define CEAWelcomeScene_h

class CEAWelcomeScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(CEAWelcomeScene);
    
private:
    
};

#endif /* CEAWelcomeScene_h */
