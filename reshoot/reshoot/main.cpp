/**
 * @file main.cpp
 * @brief WinMain
 *
 * 2D���X�N���[���V���[�e�B���O�Q�[���ureshoot�v�i���j
 * 
 * @author �Ƃ˂肱
 */

// include
#include "DxLib.h"
#include <iostream>
#include <list>

#include "Player.h"

// �֐��v���g�^�C�v�錾
void Init();
void InputKey();
void Update();
void Draw();

Player* player;
//std::list<int> g_imageList;
int i = 0;

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
	while( !ProcessMessage() ){
		ClearDrawScreen();

		InputKey();
		Update();
		Draw();

		

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}

void Init()
{
	player = new Player(32, 32, "../data/image/player.png");

	//int hImage = LoadGraph("../data/image/player.png");

	//g_imageList.push_back(hImage);
}

void InputKey()
{
	player->Input();
}

void Update()
{
	player->Move();
}

void Draw()
{
	//std::list<int>::iterator it = g_imageList.begin();
	/*
	while( it != g_imageList.end() ){
		DrawGraph(48 + i, 56, *it, true);
		// �`��̎d���̓I�u�W�F�N�g���Ƃɕς��̂ŁA*it->draw() �Ƃ��ɂ���
		
		++it;
	}
	*/
	player->Draw();
}
