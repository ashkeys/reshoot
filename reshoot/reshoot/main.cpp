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
static DrawMgr* g_drawMgr;
static Player* g_player;
static Bullet* g_pBullets;

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
 * @brief ���͊֘A
 *
 */
void Input()
{
	// �L�[�{�[�h��Pad�̓��͂��ApadBuf�Ɋi�[�����
	int padBuf = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	g_player->Input(padBuf);

	for(int i = 0; i < P_BULLET_MAX; ++i){
		g_pBullets[i].Input();
	}

}

/**
 * @brief �X�V
 *
 */
void Update()
{
	/* �I�u�W�F�N�g�̍X�V */
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
 * @brief �`��
 *
 */
void Draw()
{
	/* �I�u�W�F�N�g�̕`�� */
	g_drawMgr->Draw();

	// �f�o�b�O�p�Ɏc���Ă���
	//g_player->Draw();
	//for(int i = 0; i < P_BULLET_MAX; ++i){
	//	g_pBullets[i].Draw();
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
	delete g_player;
	g_player = NULL;

	delete [] g_pBullets;
	g_pBullets = NULL;

	DrawMgr::Destroy();
}
