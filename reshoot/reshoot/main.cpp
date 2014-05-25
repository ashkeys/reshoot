/**
 * @file main.cpp
 * @brief WinMain
 *
 * 2D横スクロールシューティングゲーム「reshoot」
 * DxLib, 左手系y-up
 * 
 * @author ashkeys
 */

// include
#include <iostream>
#include <list>

#include "DxLib.h"
#include "common.h"
#include "DrawMgr.h"
#include "Player.h"
#include "Bullet.h"

// 関数プロトタイプ宣言
void Init();

void Input();
void Update();
void Output();

void Draw();
void PlaySound();

void Final();

// グローバル変数

/* @note DxLib_Init()実行前に描画オブジェクトなどを作らないこと（ポインタはOK） */
static DrawMgr* g_drawMgr;
static Player* g_player;
static Bullet* g_pBullets;

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

	Final();

	DxLib_End();
	return 0;
}

/**
 * @brief 全体の初期化
 *
 */
void Init()
{
	// 描画管理クラスの使用準備
	DrawMgr::Create();
	g_drawMgr = DrawMgr::Instance();
	DrawObj::SetDrawMgr(g_drawMgr);

	//g_pWeapon = new Weapon[P_WEAPON_NUM];
	g_player = new Player();
	g_pBullets = new Bullet[P_BULLET_MAX];

	const char* playerFileName = "../data/image/player.png";
	g_player->Init(320, 240, playerFileName, g_pBullets);

	const char* bulletFileName = "../data/image/bullet.png";
	for(int i = 0; i < P_BULLET_MAX; ++i){
		g_pBullets[i].Init(0, 0, bulletFileName);
	}
}

/**
 * @brief 入力関連
 *
 */
void Input()
{
	// キーボードとPadの入力が、padBufに格納される
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
	/* オブジェクトの描画 */
	g_drawMgr->Draw();

	// デバッグ用に残しておく
	//g_player->Draw();
	//for(int i = 0; i < P_BULLET_MAX; ++i){
	//	g_pBullets[i].Draw();
	//}
}

/**
 * @brief サウンド再生
 *
 */
void PlaySound()
{
}

/**
 * @brief 全体の終了処理
 *
 */
void Final()
{
	delete g_player;
	g_player = NULL;

	delete [] g_pBullets;
	g_pBullets = NULL;

	DrawMgr::Destroy();
}
