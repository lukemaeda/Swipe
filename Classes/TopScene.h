//
//  TopScene.h
//  Screen
//
//  Created by MAEDAHAJIME on 2015/02/02.
//
//

#ifndef __Sprite__TopScene__
#define __Sprite__TopScene__

#include "cocos2d.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

class TopScene : public cocos2d::Layer
{
public:
    
    // コンストラクタ
    TopScene();
    // デストラクタ
    virtual ~TopScene();

    // 初期化のメソッド
    virtual bool init();
    
    static cocos2d::Scene* createScene();
    
    // create()を使えるようにしている。
    CREATE_FUNC(TopScene);

};

#endif /* defined(__Label__Top__) */
