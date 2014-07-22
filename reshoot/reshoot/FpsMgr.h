#ifndef __FPS_MGR_H__
#define __FPS_MGR_H__

/**
 * @file FpsMgr.h
 * @brief FPSMgrクラスヘッダー
 *
 * @sa http://dixq.net/g/03_14.html
 */

// include
#include <math.h>

#include "DxLib.h"

/**
 * @brief FpsMgrクラス
 *
 * FPS管理を行うクラス
 *
 */
class FpsMgr{
	int startTime;							// 測定開始時刻
	int count;									// カウンタ
	double fps;									// fps
	static const int FPS = 60;	// 設定したFPS

public:
	FpsMgr(){
		startTime = 0;
		count = 0;
		fps = 0;
	}

	bool Update(){
		// 1フレーム目なら時刻を記憶
		if( count == 0 ){
			startTime = GetNowCount();
		}

		// フレームが設定したfpsに到達したら平均を計算する
		else if( count == FPS - 1 ){
			int t = GetNowCount();
			fps = 1000 / ( (t - startTime) / static_cast<double>(FPS) );
			count = 0;
			startTime = t;

			return true;
		}
		
		++count;
		return true;
	}

	void Draw(){
		DrawFormatString(200, 0, GetColor(255,255,255), "FPS : %.2f", fps);
	}

	void Wait(){
		int takenTime = GetNowCount() - startTime;			// かかった時間
		int waitTime = ( (count * 1000) / FPS) - takenTime;	// 待つべき時間
		
		if( waitTime > 0 ){
			Sleep(waitTime);	// 待機
		}
	}
};

#endif