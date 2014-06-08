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
#include "Enemy.h"

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
static DrawMgr* g_pDrawMgr;
static Player* g_pPlayer;
static Enemy* g_pEnemy;
static Bullet* g_pPlayerBullets;
static Bullet** g_pEnemyBullets;

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
	g_pDrawMgr = DrawMgr::Instance();
	DrawObj::SetDrawMgr(g_pDrawMgr);

	// 各オブジェクトのメモリ確保
	//g_pWeapon = new Weapon[P_WEAPON_NUM];
	g_pPlayer = new Player();
	g_pEnemy = new Enemy[ENEMY_MAX];
	g_pPlayerBullets = new Bullet[PLAYER_BULLET_MAX];
	g_pEnemyBullets = new Bullet*[ENEMY_MAX];
	for(int i = 0; i < ENEMY_MAX; ++i){
		g_pEnemyBullets[i] = new Bullet[ENEMY_BULLET_MAX];
	}

	// 各オブジェクトの初期化
	const char* const playerFileName = "../data/image/Player.png";
	g_pPlayer->Init(320, 240, playerFileName, g_pPlayerBullets);

	const char* const enemyFileName = "../data/image/Enemy.png";
	for(int i = 0; i < ENEMY_MAX; ++i){
		g_pEnemy[i].Init(i * 40, i * 40, enemyFileName, g_pEnemyBullets[i]);	
	}

	const char* const playerBulletFileName = "../data/image/PlayerBullet.png";
	for(int i = 0; i < PLAYER_BULLET_MAX; ++i){
		g_pPlayerBullets[i].Init(0, 0, playerBulletFileName);
	}

	const char* const enemyBulletFileName = "../data/image/EnemyBullet.png";
	for(int i = 0; i < ENEMY_MAX; ++i){
		for(int j = 0; j < ENEMY_BULLET_MAX; ++j){
			g_pEnemyBullets[i][j].Init(0, 0, enemyBulletFileName);
		}
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

	g_pPlayer->Input(padBuf);

	for(int i = 0; i < PLAYER_BULLET_MAX; ++i){
		g_pPlayerBullets[i].Input();
	}
}

/**
 * @brief 更新
 *
 */
void Update()
{
	/* オブジェクトの更新 */
	g_pPlayer->Update();

	for(int i = 0; i < PLAYER_BULLET_MAX; ++i){
		g_pPlayerBullets[i].Update();
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
	g_pDrawMgr->Draw();

	// デバッグ用に残しておく
	//g_pPlayer->Draw();
	//for(int i = 0; i < PLAYER_BULLET_MAX; ++i){
	//	g_pPlayerBullets[i].Draw();
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
	delete g_pPlayer;
	g_pPlayer = NULL;

	delete[] g_pEnemy;
	g_pEnemy = NULL;

	delete[] g_pPlayerBullets;
	g_pPlayerBullets = NULL;

	for(int i = 0; i < ENEMY_MAX; ++i){
		delete[] g_pEnemyBullets[i];
		g_pEnemyBullets[i] = NULL;
	}
	delete[] g_pEnemyBullets;
	g_pEnemyBullets = NULL;

	DrawMgr::Destroy();
}
