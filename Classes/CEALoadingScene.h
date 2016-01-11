//
//  CEALoadingScene.h
//  cross-elimination-army
//
//  Created by wangbin on 15/11/15.
//
//

#ifndef CEALoadingScene_h
#define CEALoadingScene_h


class CEALoadingScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(CEALoadingScene);
    
    void logic(float dt);

    void loadResources();
private:
    int numOfLoadedResources;
    
};


#endif /* CEALoadingScene_h */
