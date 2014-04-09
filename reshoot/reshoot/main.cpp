/**
 * @file main.cpp
 * @brief WinMain
 *
 * 2D横スクロールシューティングゲーム「reshoot」（仮）
 * 
 * @author とねりこ
 */

// include
#include <iostream>
#include <list>

#include "DxLib.h"
#include "Player.h"

// 関数プロトタイプ宣言
void Init();
void Input();
void Update();
void Draw();

// グローバル変数
Player* g_player;
//std::list<int> g_imageList;

/**
 * @brief Win32アプリケーションエントリポイント
 *
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	Init();

	// メインループ
	while( !ProcessMessage() && !( CheckHitKey(KEY_INPUT_ESCAPE) ) ){
		ClearDrawScreen();

		Input();
		Update();
		Draw();

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}

/**
 * @brief 全体の初期化
 *
 */
void Init()
{
	g_player = new Player(320, 240, "../data/image/player.png");

	//int hImage = LoadGraph("../data/image/player.png");

	//g_imageList.push_back(hImage);
}

/**
 * @brief 入力関連
 *
 */
void Input()
{
	g_player->Input();
}

/**
 * @brief 更新
 *
 */
void Update()
{
	g_player->Move();
}

/**
 * @brief 描画
 *
 */
void Draw()
{
	/*
	std::list<int>::iterator it = g_imageList.begin();
	
	while( it != g_imageList.end() ){
		DrawGraph(48 + i, 56, *it, true);
		++it;
	}
	*/
	g_player->Draw();
	
	//弾丸をプレイヤーと分離してここに記述する
	/*
	for(int i = 0; i < P_BULLET_MAX; ++i){
		bullets[i].Draw();
	}
	*/
}
