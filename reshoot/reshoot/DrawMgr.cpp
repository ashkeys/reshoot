/**
 * @file DrawMgr.cpp
 * @brief DrawMgrクラス実装ファイル
 *
 */

// include
#include "DrawMgr.h"
#include "DrawObj.h"

DrawMgr* DrawMgr::instance = NULL;

/* ______________________________________________________________________________________public method */

/**
 * @brief インスタンスを返す
 *
 */
DrawMgr* DrawMgr::Instance()
{
	return instance;
}

/**
 * @brief インスタンスの生成
 *
 */
void DrawMgr::Create()
{
	if(!instance){
		instance = new DrawMgr();
	}
}

/**
 * @brief インスタンスの破棄
 *
 */
void DrawMgr::Destroy()
{
	delete instance;
	instance = NULL;
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
void DrawMgr::Register(DrawObj* obj)
{
	drawList.push_back(obj);
}

/* ______________________________________________________________________________________private method */

/**
 * @brief コンストラクタ
 *
 */
DrawMgr::DrawMgr()
{
}

/**
 * @brief コピーコンストラクタ
 *
 * @param [in] cpy コピーの参照
 *
 */
DrawMgr::DrawMgr(const DrawMgr& cpy)
{
}

/**
 * @brief デストラクタ
 *
 */
DrawMgr::~DrawMgr()
{
}
