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
 * @brief 出力
 *
 */
void Bullet::Output()
{
	Draw();
}

/* ______________________________________________________________________________________private method */

/* ______________________________________________________________________Input method */

/* ______________________________________________________________________Update method */

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
 * @brief 弾丸の衝突判定
 *
 */
void Bullet::Collide()
{
	if(aliveFlg == true){
	
	}
}

/* ______________________________________________________________________Output method */

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

/* ______________________________________________________________________Other method */

/**
 * @brief 弾丸発射
 * @param [in] ax 発射時のx座標
 * @param [in] ay 発射時のy座標
 *
 */
void Bullet::Fire(const double ax, const double ay)
{
	aliveFlg = true;
	x = ax;
	y = ay;
}

/**
 * @brief 弾丸の初期化
 *
 */
void Bullet::Reset()
{
	aliveFlg = false;
	x = 0;
}