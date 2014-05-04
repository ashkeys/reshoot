/**
 * @file DrawObj.cpp
 * @brief DrawObjクラス実装ファイル
 *
 */

// include
#include "DrawObj.h"
#include "DrawMgr.h"

static DrawMgr* s_drawMgr;

/* ______________________________________________________________________________________public method */

/**
 * @brief 使用するDrawMgrをstatic変数にセット
 *
 */
void DrawObj::SetDrawMgr(DrawMgr* mgr)
{
	s_drawMgr = mgr;
}

/* ______________________________________________________________________________________protected method */

/**
 * @brief コンストラクタ
 *
 */
DrawObj::DrawObj()
{
	if(s_drawMgr){
		s_drawMgr->Register(this);
	}
}

