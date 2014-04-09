/**
 * @file Player.cpp
 * @brief Playerクラス実装ファイル
 *
 */

// include
#include "DxLib.h"
#include "Player.h"

/**
 * @brief コンストラクタ
 *
 */
Player::Player() : x(0), y(0), dx(0), dy(0), hImage(-1), imageSizeX(32), imageSizeY(32), scale(1.0), bulletIndex(0)
{
}

/**
 * @brief コンストラクタ
 *
 * @param [in] x				初期x座標
 * @param [in] y				初期y座標
 * @param [in] fileName 画像ファイル名
 *
 */
Player::Player(double x, double y, char* fileName) : x(x), y(y), dx(0), dy(0), scale(1.0), bulletIndex(0)
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

/**
 * @brief プレイヤーの描画
 *
 */
void Player::Draw()
{
	drawX = static_cast<int>( x - (imageSizeX / 2) );
	drawY = static_cast<int>( y - (imageSizeY / 2) );
	DrawGraph(drawX, drawY, hImage, true);

	//仮にプレイヤー下で一緒に描画
	for(int i = 0; i < P_BULLET_MAX; ++i){
		bullets[i].Draw();
	}
}

/**
 * @brief プレイヤーの移動
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

	//仮にプレイヤー下で一緒に移動
	for(int i = 0; i < P_BULLET_MAX; ++i){
		bullets[i].Move();
	}
}

/**
 * @brief プレイヤーの入力
 *
 */
void Player::Input()
{
	GetHitKeyStateAll(keyBuf);

	// キー入力による移動
	if( (keyBuf[KEY_INPUT_A] == 1) || (keyBuf[KEY_INPUT_LEFT] == 1) ){
		dx -= 0.1;
	}
	if( (keyBuf[KEY_INPUT_D] == 1) || (keyBuf[KEY_INPUT_RIGHT] == 1) ){
		dx += 0.1;
	}
	if( (keyBuf[KEY_INPUT_W] == 1) || (keyBuf[KEY_INPUT_UP] == 1) ){
		dy -= 0.1;
	}
	if( (keyBuf[KEY_INPUT_S] == 1) || (keyBuf[KEY_INPUT_DOWN] == 1) ){
		dy += 0.1;
	}

	// 弾丸発射
	if( keyBuf[KEY_INPUT_Z] == 1 ){
		bullets[bulletIndex].Fire( X(), Y() );
		bullets[bulletIndex].AliveFlg(true);
		
		// 弾が切れたら最初の弾丸に戻る
		if(bulletIndex < P_BULLET_MAX){
			++bulletIndex;
		}else{
			bulletIndex = 0;
		}
	}

	// 弾丸リロード
	if( keyBuf[KEY_INPUT_R] == 1 ){
		for(int i = 0; i < P_BULLET_MAX; ++i){
			bullets[i].Init();
		}

		bulletIndex = 0;
	}

}

/**
 * @brief プレイヤーの衝突判定（使い道未定）
 *
 */
void Player::Collide()
{
}
