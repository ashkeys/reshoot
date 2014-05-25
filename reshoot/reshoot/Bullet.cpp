/**
 * @file Bullet.cpp
 * @brief Bulletクラス実装ファイル
 *
 */

// include
#include "DxLib.h"
#include "common.h"
#include "Bullet.h"

DrawType Bullet::s_drawType = middleCharaObj;

/* ______________________________________________________________________________________public method */

/**
 * @brief コンストラクタ
 *
 */
Bullet::Bullet()
{

}

/**
 * @brief デストラクタ
 *
 */
Bullet::~Bullet()
{
	activeFlg = false;
}

/**
 * @brief 初期化
 *
 * @param [in] id 識別番号
 * @param [in] x 初期x座標
 * @param [in] y 初期y座標
 * @param [in] fileName 画像ファイル名
 *
 */
void Bullet::Init(const double x, const double y, const char* fileName)
{
	Base::Init(x, y, fileName, s_drawType);

	this->x = x;
	this->y = y;
	activeFlg = false;
}

/**
 * @brief 入力
 *
 */
void Bullet::Input()
{
}

/**
 * @brief 更新
 *
 */
void Bullet::Update()
{
	Move();
	Collide();
	SendDataToParent();
}

/* ______________________________________________________________________________________private method */

/* ______________________________________________________________________Update method */

/**
 * @brief 移動
 *
 */
void Bullet::Move()
{
	if(activeFlg == true){
		x += 10;
	}
}

/**
 * @brief 衝突判定
 *
 */
void Bullet::Collide()
{
	if(activeFlg == true){
	
	}
}

/**
 * @brief 親クラスに更新後のデータを送る
 *
 */
void Bullet::SendDataToParent()
{
	Base::X(x);
	Base::Y(y);
}

/* ______________________________________________________________________Other method */

/**
 * @brief 発射
 * @param [in] x 発射時のx座標
 * @param [in] y 発射時のy座標
 *
 */
void Bullet::Fire(const double x, const double y)
{
	activeFlg = true;
	this->x = x;
	this->y = y;
}

/**
 * @brief 状態リセット
 *
 */
void Bullet::Reset()
{
	activeFlg = false;
	x = 0;
}