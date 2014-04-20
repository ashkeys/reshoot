/**
 * @file DrawMgr.cpp
 * @brief DrawMgrクラス実装ファイル
 *
 */

// include
#include "DrawMgr.h"
#include "DrawObj.h"

/* ______________________________________________________________________________________public method */

/**
 * @brief コンストラクタ
 *
 */
DrawMgr::DrawMgr()
{
}

/**
 * @brief drawList内を順番に描画
 *
 */
void DrawMgr::Draw()
{
	std::list<DrawObj*>::iterator it = drawList.begin();

	while( it != drawList.end() ){
		if(*it){
			(*it)->Draw();
		}

		++it;
	}
}

/**
 * @brief 描画リストに登録
 * @param [in] obj 登録するオブジェクト
 *
 */
void DrawMgr::Regist(DrawObj* obj)
{
	drawList.push_back(obj);
}
