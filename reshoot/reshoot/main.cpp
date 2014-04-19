/**
 * @file main.cpp
 * @brief WinMain
 *
 * 2D横スクロールシューティングゲーム「reshoot」（仮）
 * 
 * @author ashkeys
 */

// include
#include <iostream>
#include <list>

#include "DxLib.h"
#include "common.h"
#include "Player.h"

// 関数プロトタイプ宣言
void Init();

void Input();
void Update();
void Output();

void Draw();
void PlaySound();

// グローバル変数

/* @note DxLib_Init()実行前に描画オブジェクトなどを作らないこと */
static Player* g_player;
static Bullet* g_pBullets;
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
		Output();

		ScreenFlip();
	}

	delete g_player;
	g_player = NULL;
	delete [] g_pBullets;
	g_pBullets = NULL;

	DxLib_End();
	return 0;
}

/**
 * @brief 全体の初期化
 *
 */
void Init()
{
	// 配列newは初期化できないので、コンストラクタでなくInit()などを作った方がよさそう
	g_pBullets = new Bullet[P_BULLET_MAX];
	
	g_player = new Player(320, 240, "../data/image/player.png", g_pBullets);

	//g_imageList.push_back(hImage);
}

/**
 * @brief 入力関連
 *
 */
void Input()
{
	// キーボードとPadの入力が、28bit分padBufに格納される
	int padBuf = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	g_player->Input(padBuf);

	for(int i = 0; i < P_BULLET_MAX; ++i){
		g_pBullets[i].Input();
	}

}

/**
 * @brief 更新
 *
 */
void Update()
{
	/* オブジェクトの更新 */
	g_player->Update();

	for(int i = 0; i < P_BULLET_MAX; ++i){
		g_pBullets[i].Update();
	}
}

void Output()
{
	Draw();
	PlaySound();
}

/**
 * @brief 描画
 *
 */
void Draw()
{
	// @sa http://marupeke296.com/OOD_No6_CS2_ShootBullet2.html
	//     描画の仕組みを上記URLを参考に作りかえる

	/*
	std::list<int>::iterator it = g_imageList.begin();
	
	while( it != g_imageList.end() ){
		DrawGraph(48 + i, 56, *it, true);
		++it;
	}
	*/

	/* オブジェクトの描画 */
	g_player->Output();					// Draw()の中でOutput()が呼ばれているのはおかしいので、要修正

	for(int i = 0; i < P_BULLET_MAX; ++i){
		g_pBullets[i].Output();		// Draw()の中でOutput()が呼ばれているのはおかしいので、要修正
	}
}

/**
 * @brief サウンド再生
 *
 */
void PlaySound()
{
}
