/**
 * @file main.cpp
 * @brief WinMain
 *
 * 2D���X�N���[���V���[�e�B���O�Q�[���ureshoot�v�i���j
 * 
 * @author �Ƃ˂肱
 */

#include "DxLib.h"

/**
 * @brief Win32�A�v���P�[�V�����G���g���|�C���g
 *
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	int handle = LoadGraph("../data/image/player.jpg");

	// ���C�����[�v
	while( !ProcessMessage() ){
		ClearDrawScreen();

		static int i = 0;
		DrawGraph(48 + i, 56, handle, true);
		++i;

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}
