//
//  SecondScene.h
//  Screen
//
//  Created by MAEDAHAJIME on 2015/02/02.
//
//

#ifndef __Screen__SecondScene__
#define __Screen__SecondScene__

#include "cocos2d.h"

class SecondScene : public cocos2d::Layer
{
public:
    
    // コンストラクタ
    SecondScene();
    // デストラクタ
    virtual ~SecondScene();
    
    //初期化のメソッド
    virtual bool init();
    
    static cocos2d::Scene* createScene();
    
    // create()を使えるようにしている。 
    CREATE_FUNC(SecondScene);
    
};

#endif /* defined(__Screen__SecondScene__) */
