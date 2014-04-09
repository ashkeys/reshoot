/**
 * @file Player.h
 * @brief Playerクラスヘッダー
 *
 * プレイヤーが操作するキャラに関するクラス
 *
 */

// include
#include "common.h"
#include "Bullet.h"

class Player{
public:
	Player();
	Player(double x, double y, char* fileName);
	~Player();

	void X(double ax) {x = ax;}		/// setter
	double X()				{return x;}	/// getter
	void Y(double ay)	{y = ay;}		/// setter
	double Y()				{return y;}	/// getter

	void Draw();
	void Move();
	void Input();
	void Collide();

private:
	double x, y;
	double dx, dy;
	//Vector2D dir;
	char keyBuf[256];						/// キー入力用のバッファ。配列サイズ256固定。

	int drawX, drawY;						/// 描画用座標
	int hImage;									/// 描画ハンドル
	int imageSizeX, imageSizeY;
	double scale;

	//弾丸はPlayerから分離する予定
	Bullet bullets[P_BULLET_MAX];
	int bulletIndex;

	//Collider collider;
	//衝突判定のサイズ決定用変数が必要。複雑な形のキャラの場合、colliderも複数必要。
};