/**
 * @file main.cpp
 * @brief WinMain
 *
 * 2D���X�N���[���V���[�e�B���O�Q�[���ureshoot�v�i���j
 * 
 * @author �Ƃ˂肱
 */

// include
#include <iostream>
#include <list>

#include "DxLib.h"
#include "Player.h"

// �֐��v���g�^�C�v�錾
void Init();
void Input();
void Update();
void Draw();

// �O���[�o���ϐ�
Player* g_player;
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
		Draw();

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}

/**
 * @brief �S�̂̏�����
 *
 */
void Init()
{
	g_player = new Player(320, 240, "../data/image/player.png");

	//int hImage = LoadGraph("../data/image/player.png");

	//g_imageList.push_back(hImage);
}

/**
 * @brief ���͊֘A
 *
 */
void Input()
{
	g_player->Input();
}

/**
 * @brief �X�V
 *
 */
void Update()
{
	g_player->Move();
}

/**
 * @brief �`��
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
	
	//�e�ۂ��v���C���[�ƕ������Ă����ɋL�q����
	/*
	for(int i = 0; i < P_BULLET_MAX; ++i){
		bullets[i].Draw();
	}
	*/
}
