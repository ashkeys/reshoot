#ifndef __FPS_MGR_H__
#define __FPS_MGR_H__

/**
 * @file FpsMgr.h
 * @brief FPSMgr�N���X�w�b�_�[
 *
 * @sa http://dixq.net/g/03_14.html
 */

// include
#include <math.h>

#include "DxLib.h"

/**
 * @brief FpsMgr�N���X
 *
 * FPS�Ǘ����s���N���X
 *
 */
class FpsMgr{
	int startTime;							// ����J�n����
	int count;									// �J�E���^
	double fps;									// fps
	static const int FPS = 60;	// �ݒ肵��FPS

public:
	FpsMgr(){
		startTime = 0;
		count = 0;
		fps = 0;
	}

	bool Update(){
		// 1�t���[���ڂȂ玞�����L��
		if( count == 0 ){
			startTime = GetNowCount();
		}

		// �t���[�����ݒ肵��fps�ɓ��B�����畽�ς��v�Z����
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
		int takenTime = GetNowCount() - startTime;			// ������������
		int waitTime = ( (count * 1000) / FPS) - takenTime;	// �҂ׂ�����
		
		if( waitTime > 0 ){
			Sleep(waitTime);	// �ҋ@
		}
	}
};

#endif