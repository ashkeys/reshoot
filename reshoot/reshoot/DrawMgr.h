#ifndef __DRAW_MGR_H__
#define __DRAW_MGR_H__

/**
 * @file DrawMgr.h
 * @brief DrawMgrクラスヘッダー
 *
 * 描画管理クラス
 *
 * @sa DrawObj.h
 */

// include
#include <list>

// 前方宣言
class DrawObj;

class DrawMgr
{
public:
	DrawMgr();

	virtual void Draw();

	void Regist(DrawObj* obj);

protected:
	std::list<DrawObj*> drawList;

};

#endif