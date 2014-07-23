#ifndef __FPS_MGR_H__
#define __FPS_MGR_H__
 
/**
 * @file FpsMgr.h
 * @brief FPSMgrクラスヘッダー、実装ファイル
 *
 */
 
// include
#include <math.h>
#include <time.h>

#include "DxLib.h"

/**
 * @brief FpsMgrクラス
 *
 * FPS管理を行うクラス
 *
 */
class FpsMgr{
	clock_t startTime;
	clock_t endTime;
	int count;										// カウンタ
	double fps;										// fps
	static const int sample = 60;	// サンプルフレーム数
	static const int fixFps = 60;	// 固定したいFPS
 
public:
  /**
   * @brief コンストラクタ
   *
   */
	FpsMgr() : count(0), fps(0)
	{
		startTime = clock();
		endTime = clock();
	}

	/**
	* @brief 更新
	*
	*/
	bool Update(){
		if( count == 0 ){	// 1フレーム目なら時刻を記憶
			startTime = clock();
		}
 
		if( count == sample - 1 ){	// 設定したフレームに到達したら平均を計算する
			endTime = clock();
			double t = ( static_cast<double>( (endTime - startTime) ) / sample ) / CLOCKS_PER_SEC;
 
			if(t != 0){
				fps = 1 / t;
			}
			count = 0;
 
			return true;
		}
 
		++count;
 
		return true;
	}
 
	/**
	* @brief 描画
	*
	*/
	void Draw(){
		DrawFormatString(200, 0, GetColor(255,255,255), "FPS : %.2f", fps);
	}
 
	/**
	* @brief FPS調整のための待機
	*
	*/
	void Wait(){
		int takenTime = static_cast<int>( clock() - startTime );	// かかった時間
		int waitTime = ( (count * 1000) / fixFps ) - takenTime;					// 待つべき時間
		if( waitTime > 0 ){
			Sleep(waitTime);	// 待機
		}
	}
};
 
#endif