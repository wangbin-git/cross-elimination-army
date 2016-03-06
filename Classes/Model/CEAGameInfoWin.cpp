//
//  CEAGameInfoWin.cpp
//  cross-elimination-army
//
//  Created by wangbin on 16/2/26.
//
//

#include <stdio.h>
#include "CEAGameInfoWin.h"

USING_NS_CC;

CEAGameInfoWin* CEAGameInfoWin::create() {
    CEAGameInfoWin *sprite = new CEAGameInfoWin();
    if (sprite && sprite->init())
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}