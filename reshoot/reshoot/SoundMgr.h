#ifndef __SOUND_MGR_H__
#define __SOUND_MGR_H__

/**
 * @file SoundMgr.h
 * @brief SoundMgrクラスヘッダー
 *
 * サウンド管理クラス
 *
 */

// include
#include <list>

class SoundMgr
{
public:
	SoundMgr();

	virtual void PlaySound();

	void Regist();

protected:
	std::list<>

};

#endif