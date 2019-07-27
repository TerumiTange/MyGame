/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"//古い
using namespace CocosDenshion;//音を出すのに必要(古い)

#include "AudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    /*auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }*/

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
    //if (sprite == nullptr)
    //{
    //    problemLoading("'HelloWorld.png'");
    //}
    //else
    //{
    //    // position the sprite on the center of the screen
    //    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	//
    //    // add the sprite as a child to this layer
    //    this->addChild(sprite, 0);
    //}



	// テクスチャファイル名を指定して、スプライトを作成
	/*sprite2 = Sprite::create("HelloWorld.png");
	sprite = Sprite::create("tamatama.png");
	sprite2 = Sprite::create("tamatama.png");
	sprite = Sprite::create("tama.png");
	sprite2= Sprite::create("magma.png");
	
	 シーングラフにつなぐ
	this->addChild(sprite);
	this->addChild(sprite2);

	sprite->setPosition(Vec2(visibleSize.width / 2.0f - 100, visibleSize.height / 2.0f));//座標位置
	sprite2->setPosition(Vec2(visibleSize.width / 2.0f+100, visibleSize.height / 2.0f));
	sprite->setRotation(45);//画像回転
	sprite->setScale(3, 4);//拡縮指定
	sprite->setFlippedX(true);//左右反転
	sprite->setFlippedY(true);//上下反転
	sprite->setVisible(false);//非表示
	sprite->setColor(Color3B(0xff, 34, 12));//色合い指定　(255,255,255)で元の色

	sprite->setOpacity(255);//不透明度　255で完全に見えてる状態
	sprite2->setOpacity(0);

	sprite->setAnchorPoint(Vec2(0.5f,0.5f));//画像の左下(0,0)右下(1,1)の座標系で基準点を指定
	sprite2->setAnchorPoint(Vec2(0.0f, 0.5f));
	sprite2->setOpacity(0);

	sprite->setTextureRect(Rect(24*3, 0, 24, 32));//x,y,w,h
	sprite2->setTextureRect(Rect(0, 0, 1, 1));
	
	sprite->setScale(10);
	sprite->getTexture()->setAliasTexParameters();*/

	this->scheduleUpdate();//updateを有効化する

	/*count = 1;
	count2 = 0;
	time = 0;
	time2 = 0;
	scaly = 0;
	al = false;
	
	ccBezierConfig conf;
	conf.controlPoint_1 = Vec2();
	conf.controlPoint_2 = Vec2(1, 1);
	conf.endPosition = Vec2(3, 3);
	BezierTo* action1 = BezierTo::create(3.0f, conf);
	
	                               時間　　　　X　　Y
	MoveBy* action1 = MoveBy::create(0.5f, Vec2(200, 100));
	EaseIn* action2 = EaseIn::create(action1, 2.0f);
	sprite->runAction(action1);
	sprite2->runAction(action1->clone());
	
	srand(time(nullptr));//ランダム
	
	for (int i = 0; i < 10; i++) 
	{
		spriteList[i] = Sprite::create("tamatama.png");
		this->addChild(spriteList[i]);
	
		float mx, my;
		mx = (float)rand() / RAND_MAX * 200 - 100;
		my = (float)rand() / RAND_MAX * 200 - 100;
	
		spriteList[i]->setPosition(Vec2(visibleSize.width / 2.0f - (350 + mx) + (i * 100), visibleSize.height / 2.0f + my));
		
		mx = (float)rand() / RAND_MAX * 200 - 100;
		my = (float)rand() / RAND_MAX * 200 - 100;
		
		MoveBy* action1 = MoveBy::create(0.5f, Vec2(mx, my));
		spriteList[i]->runAction(action1->clone());
	}*/

	/*{
		//BGMを流す(古いほう)
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("ending.mp3");//どの曲を保管するか
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.01f);//音量(1.0が最大)
		SimpleAudioEngine::getInstance()->playBackgroundMusic("ending.mp3", true);//ループするかどうか(trueがループ)
		SimpleAudioEngine::getInstance()->playBackgroundMusic("ending.mp3");//曲を再生


		//SimpleAudioEngine::getInstance()->stopBackgroundMusic();//停止
		//SimpleAudioEngine::getInstance()->pauseBackgroundMusic();//一時停止
		//SimpleAudioEngine::getInstance()->resumeBackgroundMusic();//一時停止からの復帰
		//SimpleAudioEngine::getInstance()->rewindBackgroundMusic();//音楽を先頭に戻す
		//if(SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying){}//音楽が流れているかどうか
	}*/

	/*{
		//SE音をならす(古いほう)
		SimpleAudioEngine::sharedEngine()->preloadEffect("曲名.mp3");
		SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.1f);
		int soundID;
		soundID = SimpleAudioEngine::sharedEngine()->playEffect("曲名.mp3");
		SimpleAudioEngine::sharedEngine()->stopEffect(soundID);//効果音を止める
		SimpleAudioEngine::sharedEngine()->pauseEffect(soundID);//一時停止
		SimpleAudioEngine::sharedEngine()->resumeEffect(soundID);//再開
		SimpleAudioEngine::unloadEffect//se開放
	}*/

	/*{
		//無限ループ
		spriteList[0] = Sprite::create("tamatama.png");
		this->addChild(spriteList[0]);
		spriteList[0]->setPosition(Vec2(visibleSize.width / 2.0f - 100, visibleSize.height / 2.0f));
		MoveTo* action1 = MoveTo::create(1, Vec2(100, 500));	//この地点に移動
		MoveTo* action2 = MoveTo::create(0.3f, Vec2(100, 100));	//この地点に移動
		MoveTo* action3 = MoveTo::create(1, Vec2(1200, 100));	//この地点に移動
		MoveTo* action4 = MoveTo::create(0.3f, Vec2(1200, 500));//この地点に移動
		Sequence* action5 = Sequence::create(action1, action2, action3, action4, nullptr);//この順番で行う
		RepeatForever* action6 = RepeatForever::create(action5);//この作業を繰り返す
		spriteList[0]->runAction(action6);
		//DelayTime* action = DelayTime::create(1);//この時間止まる

	}*/

	{//新しいほう(今回はこっちを使う)
		//BGM(new)
		//experimental::AudioEngine::play2d("ending.mp3", true);//ループ再生 
        // オーディオIDを入れる変数（メンバ変数にするとよい）
		//int audioID;
		// 再生すると、オーディオIDが割り振られる
		//audioID = experimental::AudioEngine::play2d("ending.mp3", true);
		// 割り振られたオーディオIDを指定して止める
		//experimental::AudioEngine::stop(audioID);
		// 割り振られたオーディオIDを指定して一時停止
		//experimental::AudioEngine::pause(audioID);
		// 割り振られたオーディオIDを指定して再開
		//experimental::AudioEngine::resume(audioID);
	}
	{//制作
		{//BGMを流す
			experimental::AudioEngine::play2d("syousitu.mp3");
		}
		//出力
		spriteList[50] = Sprite::create("b.jpg");
		this->addChild(spriteList[50]);
		spriteList[50]->setOpacity(0);
		spriteList[50]->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
		DelayTime* ta1 = DelayTime::create(5);

		FadeIn* fadein = FadeIn::create(2);
		DelayTime* ta2 = DelayTime::create(5);
		FadeOut* fadeout = FadeOut::create(2);

		MoveBy* moveright1 = MoveBy::create(2, Vec2(400, 0));
		MoveBy* moveleft1 = MoveBy::create(4, Vec2(-800, 0));
		MoveBy* moveright2 = MoveBy::create(2, Vec2(400, 0));
		JumpBy* jump = JumpBy::create(2, Vec2(0, 0), 150, 2);


		Sequence* ac = Sequence::create(ta1, fadein, moveright1 ,jump,moveleft1,jump,moveright2,fadeout, nullptr);

		spriteList[50]->runAction(ac);//実行

		m3(visibleSize.width / 2.0f, visibleSize.height / 2.0f);
		//       画面中央　　　　　　　　　　　　　　　        番号　メイン時間t      画像      n秒後に登場か   サブから消えるまでs
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f, 0,      1.0f,       "aa.png",       26.1f,       0.8f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f, 1,      0.8f,       "ab.png",       27.1f,       0.8f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f, 2,      0.8f,       "ac.png",       27.9f,       0.6f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f, 3,      0.6f,       "ad.png",       28.7f,       0.7f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f, 4,      0.7f,       "ae.png",       29.3f,       0.7f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f, 5,      0.7f,       "af.png",       30.0f,       0.9f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f, 6,      0.9f,       "ag.png",       30.7f,       0.9f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f, 7,      0.9f,       "ah.png",       31.6f,       0.4f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f, 8,      0.4f,       "ai.png",       32.5f,       0.4f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f, 9,      0.4f,       "aj.png",       32.9f,       0.6f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f,10,      0.6f,       "ak.png",       33.3f,       0.7f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f,11,      0.7f,       "al.png",       33.9f,       1.4f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f,10,      1.4f,       "am.png",       34.6f,       1.1f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f,10,      1.1f,       "an.png",       36.0f,       1.1f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f,10,      1.1f,       "ao.png",       37.1f,       0.8f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f,10,      0.8f,       "ap.png",       38.2f,       1.0f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f,10,      1.0f,       "aq.png",       39.0f,       1.0f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f,10,      1.0f,       "ar.png",       40.0f,       0.5f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f,19,      0.5f,       "as.png",       41.0f,       0.5f);
		m1(visibleSize.width / 2.0f, visibleSize.height / 2.0f,20,      0.5f,       "at.png",       41.5f,       0.5f);

		m2(visibleSize.width / 2.0f, visibleSize.height / 2.0f);
	}
    return true;
	//AppDelegate.cppの94行目をコメントアウトすること
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);

}

void HelloWorld::m1(int x, int y, int i, float times, const std::string& filename,float t,float s)
{
	spriteList[i] = Sprite::create(filename);
	this->addChild(spriteList[i]);
	spriteList[i]->setPosition(Vec2(-200, 0));//適当な位置に表示
	DelayTime* ts = DelayTime::create(t);//登場する時間
	DelayTime* time = DelayTime::create(times);//メインからサブに移る時間
	MoveTo* action0 = MoveTo::create(0, Vec2(x, y));//メインに描画
	MoveBy* action1 = MoveBy::create(0.1f, Vec2(200, 200));//サブに移動
	SkewTo* action2 = SkewTo::create(0.1f, 45, 0);//サブに移動
	//auto action3 = CallFunc::create([i]() {  });
	Spawn* action4 = Spawn::create(action1, action2,nullptr);//同時
	//Sequence* action5 = Sequence::create(action6, time, action4, nullptr);//連続

	DelayTime* ti = DelayTime::create(s);
	MoveBy* action7 = MoveBy::create(0.1f, Vec2(300, 300));
	Sequence* action9 = Sequence::create(ts,action0, time, action4, ti,action7, nullptr);
	
	spriteList[i]->runAction(action9->clone());//実行
}

void HelloWorld::m2(int x, int y) 
{
	spriteList[21] = Sprite::create("shousitu.jpg");
	this->addChild(spriteList[21]);
	spriteList[21]->setOpacity(0);
	spriteList[21]->setScale(3, 3);
	spriteList[21]->setPosition(x, y);
	DelayTime* time1 = DelayTime::create(43);
	FadeIn* actions0 = FadeIn::create(5);
	DelayTime* time2 = DelayTime::create(5);
	FadeOut* actions1 = FadeOut::create(5);
	Sequence* actions2 = Sequence::create(time1, actions0, time2, actions1, nullptr);
	spriteList[21]->runAction(actions2);
	//59
	spriteList[22] = Sprite::create("d.jpg");
	this->addChild(spriteList[22]);
	spriteList[22]->setOpacity(0);
	spriteList[22]->setPosition(x, y);
	DelayTime* time3 = DelayTime::create(58);
	FadeIn* actions3 = FadeIn::create(0.1f);
	DelayTime* time4 = DelayTime::create(15);
	FadeOut* actions4 = FadeOut::create(0.1f);
	Sequence* actions5 = Sequence::create(time3, actions3, time4, actions4, nullptr);
	spriteList[22]->runAction(actions5);

	spriteList[23] = Sprite::create("haikei2.jpg");
	this->addChild(spriteList[23]);
	spriteList[23]->setOpacity(0);
	spriteList[23]->setScale(4,4);
	spriteList[23]->setPosition(x, y);
	DelayTime* time5 = DelayTime::create(74);
	FadeIn* actions6 = FadeIn::create(0.1f);
	DelayTime* time6 = DelayTime::create(15);
	FadeOut* actions7 = FadeOut::create(0.1f);
	Sequence* actions8 = Sequence::create(time5, actions6, time6, actions7, nullptr);
	spriteList[23]->runAction(actions8->clone());

	spriteList[25] = Sprite::create("onp.png");
	this->addChild(spriteList[25]);
	spriteList[25]->setOpacity(0);
	DelayTime* time9 = DelayTime::create(75);
	spriteList[25]->setPosition(x, y - 200);
	MoveBy* actions9 = MoveBy::create(1, Vec2(400,400));
	JumpBy* action13 = JumpBy::create(1, Vec2(10, 10), 150, 2);
	Sequence* actions10 = Sequence::create(time9, actions6, actions9,action13,actions7, nullptr);
	spriteList[25]->runAction(actions10->clone());

	spriteList[26] = Sprite::create("onp.png");
	this->addChild(spriteList[26]);
	spriteList[26]->setOpacity(0);
	spriteList[26]->setPosition(x, y - 200);
	MoveBy* actions11 = MoveBy::create(1, Vec2(250, 300));
	Sequence* actions12 = Sequence::create(time9, actions6, actions11, action13, actions7, nullptr);
	spriteList[26]->runAction(actions12->clone());

	spriteList[24] = Sprite::create("a.jpg");
	this->addChild(spriteList[24]);
	spriteList[24]->setOpacity(0);
	spriteList[24]->setScale(2,2);
	spriteList[24]->setPosition(x, y-200);
	spriteList[24]->runAction(actions8->clone());

}

void HelloWorld::m3(int x, int y)
{
	
	//テキスト文
	std::string gText[23] = {
		">",
		">U",
		">Un",
		">Uni",
		">Unin",
		">Unins",
		">Uninst",
		">Uninsta",
		">Uninstal",
		">Uninstall",
		">Uninstall ",
		">Uninstall M",
		">Uninstall Mi",
		">Uninstall Mik",
		">Uninstall Miku",
		">Uninstall Miku_",
		">Uninstall Miku_H",
		">Uninstall Miku_Ha",
		">Uninstall Miku_Hat",
		">Uninstall Miku_Hats",
		">Uninstall Miku_Hatsu",
		">Uninstall Miku_Hatsun",
		">Uninstall Miku_Hatsune"
	};
	//auto label22 = Label::createWithSystemFont(">Uninstall Miku_Hatsune", "fonts/Marker Felt.ttf", 48);
	//  ラベルの設定
	
	labelText = Label::createWithTTF(gText[22], "fonts/Marker Felt.ttf", 48);
	//labelText->setString(gText[22]);
	
	this->addChild(labelText);
	labelText->setPosition(Vec2(x, y));
	labelText->setColor(Color3B::WHITE);//文字色を白に設定
	labelText->setOpacity(0);//透明化

	//	テキストを１文字ずつ表示
	int textLength = labelText->getStringLength();//表示文字の長さ取得
	for (int i = 0; i < textLength; i++) {
	
		Sprite *sp = labelText->getLetter(i);//i番目の文字をスプライトに変換
	
		if (sp) {
			//アニメーション開始
			sp->runAction(Sequence::create(
				DelayTime::create(0.1f * i), //1文字0.1秒
				CallFunc::create([sp, i, textLength]() {
				sp->setOpacity(255);
			}),
				NULL
				));
		}
	}
	
	for (int i = 0; i < textLength; i++) {
	
		Sprite *sp = labelText->getLetter(i);//i番目の文字をスプライトに変換
	
		if (sp) {
			//アニメーション開始
			sp->runAction(Sequence::create(
				DelayTime::create(5.0f),
				CallFunc::create([sp, i, textLength]() {
				sp->setOpacity(0);
			}),
				NULL
				));
		}
	}
}

void HelloWorld::update(float delta) 
{
	
	/*Vec2 pos = sprite->getPosition();
	time+=1;
	float i = 255 - time / 300 * 255;
	pos += Vec2(-1, 0);
	sprite->setPosition(pos);//左に移動+
	if (i < 0)i = 0;
	sprite->setOpacity(i);//徐々に透明*/

	//←↓→↑に移動
	//Vec2 pos = sprite->getPosition();
	//switch (count)
	//{
	//case 1:pos.x -= 5; 
	//	if (pos.x < 100){
	//	count = 2;
	//    } 
	//	break;
	//case 2:
	//	pos.y -= 5;
	//	if (pos.y < 100) {
	//		count = 3;
	//	}
	//	break;
	//case 3:
	//	pos.x += 5; 
	//	if (pos.x > 1280 - 100) {
	//		count = 4;
	//	}
	//	break;
	//case 4:
	//	pos.y += 5;
	//	if (pos.y > 600) {
	//		count = 1;
	//	}
	//	break;
	//}
	//
	//sprite->setPosition(pos);

	//クロスフェード
	//float i = sprite->getOpacity();
	//float m = sprite2->getOpacity();
	//i --;
	//m ++;
	//if (i <= 0)i = 0;
	//if (m >= 255)m = 255;
	//
	//sprite->setOpacity(i);
	//sprite2->setOpacity(m);

	//アニメーション
	/*if (al == false) 
	{
		if (!(count2 >= 5)) {
			time += 1;
		}
		else
		{
			time = 1;
		}

		if ((int)time % 30 == 0) {
			if (count == 1)count = 0;
			else
			{
				count = 1;
			}
			count2++;
		}

		switch (count)
		{
		case 0:sprite->setTextureRect(Rect(0, 32 * 2, 24, 32)); break;
		case 1:sprite->setTextureRect(Rect(24, 32 * 2, 24, 32)); break;
		}

		if (count2 >= 5) {
			sprite2->setOpacity(255);
			time2++;
		}

		if (time2 > 10) {

			sprite2->setScaleY(scaly * 5);
			if (time2 > 50)
			{
				sprite2->setScaleX(50 * 100);
			}
		}
		else
		{
			scaly += 0.1f;
			sprite2->setScaleY(scaly * 5);
			sprite2->setScaleX(time2 * 100);
		}

		if (time2 > 300)
		{
			scaly--;
			if (scaly <= 0) {
				scaly = 0;
			}
			sprite2->setScaleY(scaly * 5);
			if (sprite2->getScaleY() <= 0) {
				al = true;
			}
		}
	}
	else
	{
		count = 1;
		count2 = 0;
		time = 0;
		time2 = 0;
		scaly = 0;
		al = false;
	}*/
}
