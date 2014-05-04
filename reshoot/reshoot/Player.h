#ifndef __PLAYER_H__
#define __PLAYER_H__

/**
 * @file Player.h
 * @brief Playerクラスヘッダー
 *
 */

// include
#include "DrawObj.h"

// 前方宣言
class Bullet;

class Player : public DrawObj{
public:
	Player();
	Player(double x, double y, char* fileName, Bullet* bullets);
	~Player();

	//void Init(int id);
	void Input(const int buf);
	void Update();
	void Draw();

	void X(const double ax) {x = ax;}		/// setter
	double X() const				{return x;}	/// getter
	void Y(const double ay)	{y = ay;}		/// setter
	double Y() const				{return y;}	/// getter

private:
	// Input method
	void CheckKey(const int buf);

	// Update method
	void Move();
	void Collide();

	// Other method
	void Reset();

	double x, y;
	double dx, dy;
	//Vector2D dir;

	int drawX, drawY;						/// 描画用座標
	int hImage;									/// 描画ハンドル
	int imageSizeX, imageSizeY;
	double scale;

	Bullet* myBullets;
	int bulletIndex;

	//Collider collider;
	//衝突判定のサイズ決定用変数が必要。複雑な形のキャラの場合、colliderも複数必要。
};

#endif