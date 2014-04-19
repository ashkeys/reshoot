/**
 * @file main.cpp
 * @brief WinMain
 *
 * 2D���X�N���[���V���[�e�B���O�Q�[���ureshoot�v�i���j
 * 
 * @author ashkeys
 */

// include
#include <iostream>
#include <list>

#include "DxLib.h"
#include "common.h"
#include "Player.h"

// �֐��v���g�^�C�v�錾
void Init();

void Input();
void Update();
void Output();

void Draw();
void PlaySound();

// �O���[�o���ϐ�

/* @note DxLib_Init()���s�O�ɕ`��I�u�W�F�N�g�Ȃǂ����Ȃ����� */
static Player* g_player;
static Bullet* g_pBullets;
//std::list<int> g_imageList;

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

	delete g_player;
	g_player = NULL;
	delete [] g_pBullets;
	g_pBullets = NULL;

	DxLib_End();
	return 0;
}

/**
 * @brief �S�̂̏�����
 *
 */
void Init()
{
	// �z��new�͏������ł��Ȃ��̂ŁA�R���X�g���N�^�łȂ�Init()�Ȃǂ�����������悳����
	g_pBullets = new Bullet[P_BULLET_MAX];
	
	g_player = new Player(320, 240, "../data/image/player.png", g_pBullets);

	//g_imageList.push_back(hImage);
}

/**
 * @brief ���͊֘A
 *
 */
void Input()
{
	// �L�[�{�[�h��Pad�̓��͂��A28bit��padBuf�Ɋi�[�����
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
	// @sa http://marupeke296.com/OOD_No6_CS2_ShootBullet2.html
	//     �`��̎d�g�݂���LURL���Q�l�ɍ�肩����

	/*
	std::list<int>::iterator it = g_imageList.begin();
	
	while( it != g_imageList.end() ){
		DrawGraph(48 + i, 56, *it, true);
		++it;
	}
	*/

	/* �I�u�W�F�N�g�̕`�� */
	g_player->Output();					// Draw()�̒���Output()���Ă΂�Ă���̂͂��������̂ŁA�v�C��

	for(int i = 0; i < P_BULLET_MAX; ++i){
		g_pBullets[i].Output();		// Draw()�̒���Output()���Ă΂�Ă���̂͂��������̂ŁA�v�C��
	}
}

/**
 * @brief �T�E���h�Đ�
 *
 */
void PlaySound()
{
}
