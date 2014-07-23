#ifndef __FPS_MGR_H__
#define __FPS_MGR_H__
 
/**
 * @file FpsMgr.h
 * @brief FPSMgr�N���X�w�b�_�[�A�����t�@�C��
 *
 */
 
// include
#include <math.h>
#include <time.h>

#include "DxLib.h"

/**
 * @brief FpsMgr�N���X
 *
 * FPS�Ǘ����s���N���X
 *
 */
class FpsMgr{
	clock_t startTime;
	clock_t endTime;
	int count;										// �J�E���^
	double fps;										// fps
	static const int sample = 60;	// �T���v���t���[����
	static const int fixFps = 60;	// �Œ肵����FPS
 
public:
  /**
   * @brief �R���X�g���N�^
   *
   */
	FpsMgr() : count(0), fps(0)
	{
		startTime = clock();
		endTime = clock();
	}

	/**
	* @brief �X�V
	*
	*/
	bool Update(){
		if( count == 0 ){	// 1�t���[���ڂȂ玞�����L��
			startTime = clock();
		}
 
		if( count == sample - 1 ){	// �ݒ肵���t���[���ɓ��B�����畽�ς��v�Z����
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
	* @brief �`��
	*
	*/
	void Draw(){
		DrawFormatString(200, 0, GetColor(255,255,255), "FPS : %.2f", fps);
	}
 
	/**
	* @brief FPS�����̂��߂̑ҋ@
	*
	*/
	void Wait(){
		int takenTime = static_cast<int>( clock() - startTime );	// ������������
		int waitTime = ( (count * 1000) / fixFps ) - takenTime;					// �҂ׂ�����
		if( waitTime > 0 ){
			Sleep(waitTime);	// �ҋ@
		}
	}
};
 
#endif