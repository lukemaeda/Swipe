//
//  TopScene.cpp
//  Screen
//
//  Created by MAEDAHAJIME on 2015/02/02.
//
//

#include "TopScene.h"
#include "SecondScene.h"
// Swipe UP DOWN RIGHT LEFT
#include "EventListenerGesture.h"
//音をならすためにinclude
#include "SimpleAudioEngine.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

// _/_/_/ コンストラクタ プロパティー _/_/_/
TopScene::TopScene()
{
    
}

#pragma mark - デストラクタで解放 メモリーリークを防ぐ

// SecondScene デストラクタで解放 メモリーリークを防ぐ
TopScene::~TopScene()
{
    
}

Scene* TopScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = TopScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}


// 「INIT」初期化
bool TopScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // 画面の座標関係の詳しい説明はここ http://www.cocos2d-x.org/wiki/Coordinate_System
    // 画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    //マルチレゾリューション対応がどうとか
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::WHITE,
                                         winSize.width,
                                         winSize.height);
    // バックグランドカラー 第2引数は表示順
    this->addChild(background, 0);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // タイトルを設置
    auto lbl_title = Label::createWithSystemFont("Top", "HiraKakuProN-W6", 100);
    lbl_title->setPosition(Point(origin.x + winSize.width/2,
                                 origin.y + winSize.height
                                 -lbl_title->getContentSize().height));
    lbl_title->setColor(Color3B::BLUE);
    // ラベルタイトルを追加
    this->addChild(lbl_title,1);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // 矢印画像Spriteクラスを初期化しています。
    auto sprite = Sprite::create("Arrow.png");
    // 位置を設定
    sprite->setPosition(Point(winSize.width /2 ,winSize.height/2 - 50));
    // 画面に追加をしています。
    this->addChild(sprite);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // ラベルを作成し、初期化する。
    // Label::createWithSystemFont("文字列", "フォントの種類", 文字サイズ);
    auto label1 = Label::createWithSystemFont("上下左右スワイプで次画面", "HiraKakuProN-W6", 50);
    // ラベルの色:ホワイト
    label1->setColor(Color3B::ORANGE);
    //画面の中央に表示
    label1->setPosition(Point(winSize.width/2, winSize.height/2 - 250));
    // Layerにラベルを追加
    this->addChild(label1);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // Swipe UP DOWN RIGHT LEFT
    auto listener = EventListenerGesture::create();
    
    //if dont set this value is 0.5f.
    listener->setLongTapThreshouldSeconds(1.0f);
    //if dont set this value is 100.0f.
    listener->setSwipeThreshouldDistance(150.0f);
    listener->onTap = [](Vec2 vec2){log("onTap called.");};
    listener->onLongTapBegan = [](Vec2 vec2){log("onLongTapBegan called.");};
    listener->onLongTapEnded = [](Vec2 vec2){log("onLongTapEnded called.");};
    listener->onSwipe = [](EventListenerGesture::SwipeDirection direction)
    {
        
        if (direction == EventListenerGesture::SwipeDirection::UP) {
            log("Swipe UP.");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
            Scene *pScene = SecondScene::createScene();
            Director::getInstance()->replaceScene(pScene);
        }
        
        if (direction == EventListenerGesture::SwipeDirection::DOWN) {
            log("Swipe DOWN.");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
            Scene *pScene = SecondScene::createScene();
            Director::getInstance()->replaceScene(pScene);
        }
        
        if (direction == EventListenerGesture::SwipeDirection::RIGHT) {
            log("Swipe 右 RIGHT.");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
            Scene *pScene = SecondScene::createScene();
            Director::getInstance()->replaceScene(pScene);
        }
        
        if (direction == EventListenerGesture::SwipeDirection::LEFT) {
            log("Swipe 左 LEFT.");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
            Scene *pScene = SecondScene::createScene();
            Director::getInstance()->replaceScene(pScene);
        }
        
    };
    
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    
    return true;
}