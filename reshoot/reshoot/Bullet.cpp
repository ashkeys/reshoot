/**
 * @file Bullet.cpp
 * @brief Bulletクラス実装ファイル
 *
 */

// include
#include "DxLib.h"
#include "Bullet.h"

/* ______________________________________________________________________________________public method */

/**
 * @brief コンストラクタ
 *
 */
Bullet::Bullet() : x(0), y(100), aliveFlg(false)
{
	hImage = LoadGraph("../data/image/bullet.png");
	GetGraphSize(hImage, &imageSizeX, &imageSizeY);
}

/**
 * @brief デストラクタ
 *
 */
Bullet::~Bullet()
{
	aliveFlg = false;
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
}

/**
 * @brief 描画
 *
 */
void Bullet::Draw()
{
	if(aliveFlg == true){
		drawX = static_cast<int>( x - (imageSizeX / 2) );
		drawY = static_cast<int>( y - (imageSizeY / 2) );
		DrawGraph(drawX, drawY, hImage, true);
	}
}

/* ______________________________________________________________________________________private method */

/* ______________________________________________________________________Update method */

/**
 * @brief 移動
 *
 */
void Bullet::Move()
{
	if(aliveFlg == true){
		x += 10;
	}
}

/**
 * @brief 衝突判定
 *
 */
void Bullet::Collide()
{
	if(aliveFlg == true){
	
	}
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
	aliveFlg = true;
	this->x = x;
	this->y = y;
}

/**
 * @brief 状態リセット
 *
 */
void Bullet::Reset()
{
	aliveFlg = false;
	x = 0;
}