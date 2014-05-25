#ifndef __BULLET_H__
#define __BULLET_H__

/**
 * @file Bullet.h
 * @brief Bulletクラスヘッダー
 *
 */

// include
#include "DrawObj.h"

/**
 * @brief Bulletクラス
 *
 */
class Bullet : public DrawObj{
	typedef DrawObj Base;	///< 基底クラスをtypedef

public:
	Bullet();
	~Bullet();

	void Init(const double x, const double y, const char* fileName);
	void Input();
	void Update();

	// 一旦publicで進める
	void Fire(const double x, const double y);
	void Reset();	

private:
	// Update method
	void Move();
	void Collide();
	void SendDataToParent();

	static DrawType s_drawType;
	double x, y;
	//Vector2D dir;
	bool activeFlg;		/// 発射～着弾の間にtrue

	//Collider collider;
	//衝突判定のサイズ決定用変数が必要。複雑な形のキャラの場合、colliderも複数必要。
};

#endif