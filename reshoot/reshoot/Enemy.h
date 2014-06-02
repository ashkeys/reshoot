#ifndef __ENEMY_H__
#define __ENEMY_H__

/**
 * @file Enemy.h
 * @brief Enemyクラスヘッダー
 *
 */

// include
#include "DrawObj.h"

// 前方宣言
class Bullet;
enum DrawType;

/**
 * @brief Enemyクラス
 *
 * 敵キャラクターに関するクラス
 *
 */
class Enemy : public DrawObj{
	typedef DrawObj Base;	///< 基底クラスをtypedef

public:
	Enemy();
	Enemy(double x, double y, char* fileName, Bullet* bullets);
	~Enemy();

	void Init(const double x, const double y, const char* fileName, Bullet* bullets);
	void Input(const int buf);
	void Update();

	void X(const double x)	{this->x = x;}		///< setter
	double X() const				{return this->x;}	///< getter
	void Y(const double y)	{this->y = y;}		///< setter
	double Y() const				{return this->y;}	///< getter

private:
	// Input method
	void CheckKey(const int buf);

	// Update method
	void Move();
	void Collide();
	void SendDataToParent();

	// Other method
	void Reset();

	double x, y;
	double dx, dy;
	//Vector2D dir;

	static DrawType s_drawType;
	Bullet* myBullets;
	int bulletIndex;

	//Collider collider;
};

#endif