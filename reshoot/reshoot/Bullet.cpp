/**
 * @file Bullet.cpp
 * @brief Bulletクラス実装ファイル
 *
 */

// include
#include "DxLib.h"
#include "Bullet.h"

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
 * @brief 弾丸の描画
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

/**
 * @brief 弾丸発射
 *
 */
void Bullet::Fire(double ax, double ay)
{
	x = ax;
	y = ay;
}

/**
 * @brief 弾丸の移動
 *
 */
void Bullet::Move()
{
	if(aliveFlg == true){
		x += 10;
	}
}

/**
 * @brief 弾丸の初期化
 *
 */
void Bullet::Init()
{
	aliveFlg = false;
	x = 0;
}

/**
 * @brief 弾丸の衝突判定
 *
 */
void Bullet::Collide()
{
	if(aliveFlg == true){
	
	}
}