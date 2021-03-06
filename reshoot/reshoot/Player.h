#ifndef __PLAYER_H__
#define __PLAYER_H__

/**
 * @file Player.h
 * @brief Playerクラスヘッダー
 *
 */

// include
#include "DrawObj.h"
#include "Character.h"

// 前方宣言
class Bullet;
enum DrawType;

/**
 * @brief Playerクラス
 *
 * 操作するキャラクターに関するクラス
 *
 */
class Player : public DrawObj{
	typedef DrawObj Base;	///< 基底クラスをtypedef

public:
	Player();
	Player(double x, double y, char* fileName, Bullet* bullets);
	~Player();

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