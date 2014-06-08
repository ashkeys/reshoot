/**
 * @file main.cpp
 * @brief WinMain
 *
 * 2D���X�N���[���V���[�e�B���O�Q�[���ureshoot�v
 * DxLib, ����ny-up
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

// �֐��v���g�^�C�v�錾
void Init();

void Input();
void Update();
void Output();

void Draw();
void PlaySound();

void Final();

// �O���[�o���ϐ�

/* @note DxLib_Init()���s�O�ɕ`��I�u�W�F�N�g�Ȃǂ����Ȃ����Ɓi�|�C���^��OK�j */
static DrawMgr* g_pDrawMgr;
static Player* g_pPlayer;
static Enemy* g_pEnemy;
static Bullet* g_pPlayerBullets;
static Bullet** g_pEnemyBullets;

/**
 * @brief Win32�A�v���P�[�V�����G���g���|�C���g
 *
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	Init();

	// ���C�����[�v
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
 * @brief �S�̂̏�����
 *
 */
void Init()
{
	// �`��Ǘ��N���X�̎g�p����
	DrawMgr::Create();
	g_pDrawMgr = DrawMgr::Instance();
	DrawObj::SetDrawMgr(g_pDrawMgr);

	// �e�I�u�W�F�N�g�̃������m��
	//g_pWeapon = new Weapon[P_WEAPON_NUM];
	g_pPlayer = new Player();
	g_pEnemy = new Enemy[ENEMY_MAX];
	g_pPlayerBullets = new Bullet[PLAYER_BULLET_MAX];
	g_pEnemyBullets = new Bullet*[ENEMY_MAX];
	for(int i = 0; i < ENEMY_MAX; ++i){
		g_pEnemyBullets[i] = new Bullet[ENEMY_BULLET_MAX];
	}

	// �e�I�u�W�F�N�g�̏�����
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
 * @brief ���͊֘A
 *
 */
void Input()
{
	// �L�[�{�[�h��Pad�̓��͂��ApadBuf�Ɋi�[�����
	int padBuf = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	g_pPlayer->Input(padBuf);

	for(int i = 0; i < PLAYER_BULLET_MAX; ++i){
		g_pPlayerBullets[i].Input();
	}
}

/**
 * @brief �X�V
 *
 */
void Update()
{
	/* �I�u�W�F�N�g�̍X�V */
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
 * @brief �`��
 *
 */
void Draw()
{
	/* �I�u�W�F�N�g�̕`�� */
	g_pDrawMgr->Draw();

	// �f�o�b�O�p�Ɏc���Ă���
	//g_pPlayer->Draw();
	//for(int i = 0; i < PLAYER_BULLET_MAX; ++i){
	//	g_pPlayerBullets[i].Draw();
	//}
}

/**
 * @brief �T�E���h�Đ�
 *
 */
void PlaySound()
{
}

/**
 * @brief �S�̂̏I������
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
