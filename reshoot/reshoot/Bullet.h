#ifndef __BULLET_H__
#define __BULLET_H__

/**
 * @file Bullet.h
 * @brief Bulletクラスヘッダー
 *
 * Playerが発射する弾丸に関するクラス
 *
 */

// include
#include "DrawObj.h"

class Bullet : public DrawObj{
public:
	Bullet();
	~Bullet();

	void Input();
	void Update();
	void Draw();

	// 一旦publicで進める
	void Fire(const double ax, const double ay);
	void Reset();	

	/*
	void AliveFlg(const bool flg)	{aliveFlg = flg;}		/// setter
	bool AliveFlg() const					{return aliveFlg;}	/// getter
	*/
private:
	// Update method
	//void Fire(double ax, double ay);
	void Move();
	void Collide();

	// Other method
	//void Reset();

	double x, y;
	//Vector2D dir;

	bool aliveFlg;		/// 発射～着弾の間にtrue
	
	int drawX, drawY;		/// 描画用座標
	int hImage;					/// 描画ハンドル
	int imageSizeX, imageSizeY;

	//Collider collider;
	//衝突判定のサイズ決定用変数が必要。複雑な形のキャラの場合、colliderも複数必要。
};

#endif