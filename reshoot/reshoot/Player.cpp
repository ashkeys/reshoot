/**
 * @file Player.cpp
 * @brief Playerクラス実装ファイル
 *
 */

// include
#include "DxLib.h"
#include "common.h"
#include "Player.h"
#include "Bullet.h"

/* ______________________________________________________________________________________public method */

/**
 * @brief コンストラクタ
 *
 */
Player::Player() : x(0), y(0), dx(0), dy(0),
	hImage(-1), imageSizeX(32), imageSizeY(32), scale(1.0), bulletIndex(0)
{
}

/**
 * @brief コンストラクタ
 *
 * @param [in] x				初期x座標
 * @param [in] y				初期y座標
 * @param [in] fileName 画像ファイル名
 * @param [in] bullets	プレイヤーの所持する弾丸
 *
 */
Player::Player(double x, double y, char* fileName, Bullet* bullets) : x(x), y(y), dx(0), dy(0), scale(1.0), myBullets(bullets), bulletIndex(0)
{
	hImage = LoadGraph(fileName);
	GetGraphSize(hImage, &imageSizeX, &imageSizeY);
}

/**
 * @brief デストラクタ
 *
 */
Player::~Player()
{
}

/*
void Player::Init(double x, double y, char* fileName, Bullet* bullets, int id)
{

}
*/

/**
 * @brief 入力
 * @param [in] buf 入力情報バッファ
 *
 */
void Player::Input(const int buf)
{
	CheckKey(buf);
}

/**
 * @brief 更新
 *
 */
void Player::Update()
{
	Move();
}

/**
 * @brief 描画
 *
 */
void Player::Draw()
{
	drawX = static_cast<int>( x - (imageSizeX / 2) );
	drawY = static_cast<int>( y - (imageSizeY / 2) );
	DrawGraph(drawX, drawY, hImage, true);
}

/* ______________________________________________________________________________________private method */

/* ______________________________________________________________________Input method */
/**
 * @brief キー入力の確認
 * @param [in] buf 入力情報バッファ
 *
 */
void Player::CheckKey(const int buf)
{
	if(buf & PAD_INPUT_DOWN){
		dy += 0.1;		
	}
	if(buf & PAD_INPUT_LEFT){
		dx -= 0.1;		
	}
	if(buf & PAD_INPUT_RIGHT){
		dx += 0.1;		
	}
	if(buf & PAD_INPUT_UP){
		dy -= 0.1;		
	}

	// 弾丸発射
	if( buf & PAD_INPUT_1 ){										// PAD_INPUT_1 == zキー
		
		// 弾が切れたら最初の弾丸に戻る
		if(bulletIndex < P_BULLET_MAX){
			myBullets[bulletIndex].Fire( X(), Y() );
			++bulletIndex;
		}else{
			bulletIndex = 0;
		}
	}

	// 弾丸リロード
	if( buf & PAD_INPUT_2 ){										// PAD_INPUT_2 == xキー
		for(int i = 0; i < P_BULLET_MAX; ++i){
			myBullets[i].Reset();
		}

		bulletIndex = 0;
	}
}

/* ______________________________________________________________________Update method */

/**
 * @brief 移動
 *
 */
void Player::Move()
{
	if( ( (x + dx) < 0 ) || ( (x + dx) > 640 ) ){
		dx = 0;
	}
	if( ( (y + dy) < 0 ) || ( (y + dy) > 480 ) ){
		dy = 0;
	}

	x += dx;
	y += dy;
}

/**
 * @brief 衝突判定（使い道未定）
 *
 */
void Player::Collide()
{
}

/* ______________________________________________________________________Other method */

/**
 * @brief 状態リセット
 *
 */
void Player::Reset()
{
}
