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
#include "SimpleAudioEngine.h"

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

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
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
    }

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
	//sprite2 = Sprite::create("HelloWorld.png");
	//sprite = Sprite::create("tamatama.png");
	//sprite = Sprite::create("tamatama.png");
	sprite = Sprite::create("tama.png");
	sprite2= Sprite::create("magma.png");
	// シーングラフにつなぐ
	this->addChild(sprite);
	this->addChild(sprite2);

	sprite->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));//座標位置
	sprite2->setPosition(Vec2(visibleSize.width / 2.0f+100, visibleSize.height / 2.0f));
	//sprite->setRotation(45);//画像回転
	//sprite->setScale(3, 4);//拡縮指定
	//sprite->setFlippedX(true);//左右反転
	//sprite->setFlippedY(true);//上下反転
	//sprite->setVisible(false);//非表示
	//sprite->setColor(Color3B(0xff, 34, 12));//色合い指定　(255,255,255)で元の色

	sprite->setOpacity(255);//不透明度　255で完全に見えてる状態
	//sprite2->setOpacity(0);

	sprite->setAnchorPoint(Vec2(0.5f,0.5f));//画像の左下(0,0)右下(1,1)の座標系で基準点を指定
	sprite2->setAnchorPoint(Vec2(0.0f, 0.5f));
	sprite2->setOpacity(0);

	sprite->setTextureRect(Rect(24*3, 0, 24, 32));//x,y,w,h
	sprite2->setTextureRect(Rect(0, 0, 1, 1));

	sprite->setScale(10);
	sprite->getTexture()->setAliasTexParameters();

	this->scheduleUpdate();//updateを有効化する

	count = 1;
	count2 = 0;
	time = 0;
	time2 = 0;
	scaly = 0;
	al = false;
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


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
	if (al == false) 
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
	}
}
