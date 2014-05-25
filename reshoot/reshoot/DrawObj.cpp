/**
 * @file DrawObj.cpp
 * @brief DrawObjクラス実装ファイル
 *
 */

// include
#include "DxLib.h"
#include "common.h"
#include "DrawObj.h"
#include "DrawMgr.h"

int DrawObj::currentId = 0;
DrawMgr* DrawObj::s_drawMgr = NULL;

/* ______________________________________________________________________________________public method */

/**
 * @brief 使用するDrawMgrをstatic変数にセット
 *
 */
void DrawObj::SetDrawMgr(DrawMgr* mgr)
{
	s_drawMgr = mgr;
}

/**
 * @brief 描画タイプを変更する
 *
 * @param [in] type 描画タイプ
 *
 */
void DrawObj::SetDrawType(const DrawType type)
{
	s_drawMgr->ChangeDrawType(this, type);
}

/* ______________________________________________________________________________________protected method */

/**
 * @brief コンストラクタ
 *
 */
DrawObj::DrawObj() : id(currentId), scale(1.0), angle(0.0)
{
	++currentId;
}

/**
 * @brief 描画
 *
 */
void DrawObj::Draw()
{
	if(activeFlg == true){
		drawX = static_cast<int>( x - (imageSizeX / 2) );
		drawY = static_cast<int>( y - (imageSizeY / 2) );
		DrawRotaGraph(drawX, drawY, scale, angle, hImage, true);
	}
}

/**
 * @brief 初期化
 *
 * @param [in] id 識別番号
 * @param [in] x 初期x座標
 * @param [in] y 初期y座標
 * @param [in] fileName 画像ファイル名
 * @param [in] type 描画タイプ
 *
 */
void DrawObj::Init(const double x, const double y, const char* fileName, DrawType type)
{
	drawType = type;

	if(s_drawMgr){
		s_drawMgr->Register(this);
	}

	hImage = LoadGraph(fileName);
	GetGraphSize(hImage, &imageSizeX, &imageSizeY);

	this->x = x;
	this->y = y;
	activeFlg = true;
}
