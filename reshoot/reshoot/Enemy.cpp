/**
 * @file Enemy.cpp
 * @brief Enemyクラス実装ファイル
 *
 */

// include
#include "DxLib.h"
#include "common.h"
#include "Enemy.h"
#include "Bullet.h"

DrawType Enemy::s_drawType = middleChara;

/* ______________________________________________________________________________________public method */

/**
 * @brief コンストラクタ
 *
 */
Enemy::Enemy()
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
Enemy::Enemy(double x, double y, char* fileName, Bullet* bullets)
{
}

/**
 * @brief デストラクタ
 *
 */
Enemy::~Enemy()
{
}

/**
 * @brief 初期化
 *
 * @param [in] id 識別番号
 * @param [in] x 初期x座標
 * @param [in] y 初期y座標
 * @param [in] fileName 画像ファイル名
 * @param [in] bullets 所持する弾丸
 *
 */
void Enemy::Init(const double x, const double y, const char* fileName, Bullet* bullets)
{
	Base::Init(x, y, fileName, s_drawType);

	this->x = x;
	this->y = y;
	myBullets = bullets;
	bulletIndex = 0;
}

/**
 * @brief 入力
 *
 * @param [in] buf 入力情報バッファ
 *
 */
void Enemy::Input(const int buf)
{
	CheckKey(buf);
}

/**
 * @brief 更新
 *
 */
void Enemy::Update()
{
	Move();

	SendDataToParent();
}

/* ______________________________________________________________________________________private method */

/* ______________________________________________________________________Input method */
/**
 * @brief キー入力の確認
 *
 * @param [in] buf 入力情報バッファ
 *
 */
void Enemy::CheckKey(const int buf)
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
		if(bulletIndex < PLAYER_BULLET_MAX){
			myBullets[bulletIndex].Fire( X(), Y() );
			++bulletIndex;
		}else{
			bulletIndex = 0;
		}
	}

	// 弾丸リロード
	if( buf & PAD_INPUT_2 ){										// PAD_INPUT_2 == xキー
		for(int i = 0; i < PLAYER_BULLET_MAX; ++i){
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
void Enemy::Move()
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
void Enemy::Collide()
{
}

/**
 * @brief 親クラスに更新後のデータを送る
 *
 */
void Enemy::SendDataToParent()
{
	Base::X(x);
	Base::Y(y);
}

/* ______________________________________________________________________Other method */

/**
 * @brief 状態リセット
 *
 */
void Enemy::Reset()
{
}
