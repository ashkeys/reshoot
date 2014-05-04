/**
 * @file Character.cpp
 * @brief Characterクラス実装ファイル
 *
 */

// include
#include "Character.h"

/* ______________________________________________________________________________________public method */

/**
 * @brief コンストラクタ
 *
 */
Character::Character()
{
}

/**
 * @brief デストラクタ
 *
 */
Character::~Character()
{
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
void Character::Init(const int id, const double x, const double y, char* fileName, DrawType type)
{
	Base::Init(id, x, y, fileName, type);
}

/**
 * @brief 描画
 *
 */
void Character::Draw()
{
	
}