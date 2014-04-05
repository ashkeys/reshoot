/**
 * @file main.cpp
 * @brief WinMain
 *
 * 2D横スクロールシューティングゲーム「reshoot」（仮）
 * 
 * @author とねりこ
 */

#include "DxLib.h"

/**
 * @brief Win32アプリケーションエントリポイント
 *
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	int handle = LoadGraph("../data/image/player.jpg");

	// メインループ
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
