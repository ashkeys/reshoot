/**
 * @file Bullet.cpp
 * @brief BulletNXÀt@C
 *
 */

// include
#include "DxLib.h"
#include "Bullet.h"

/* ______________________________________________________________________________________public method */

/**
 * @brief RXgN^
 *
 */
Bullet::Bullet() : x(0), y(100), aliveFlg(false)
{
	hImage = LoadGraph("../data/image/bullet.png");
	GetGraphSize(hImage, &imageSizeX, &imageSizeY);
}

/**
 * @brief fXgN^
 *
 */
Bullet::~Bullet()
{
	aliveFlg = false;
}

/**
 * @brief üÍ
 *
 */
void Bullet::Input()
{
}

/**
 * @brief XV
 *
 */
void Bullet::Update()
{
	Move();
	Collide();
}

/**
 * @brief oÍ
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
 * @brief eÛÌÚ®
 *
 */
void Bullet::Move()
{
	if(aliveFlg == true){
		x += 10;
	}
}

/**
 * @brief eÛÌÕË»è
 *
 */
void Bullet::Collide()
{
	if(aliveFlg == true){
	
	}
}

/* ______________________________________________________________________Output method */

/**
 * @brief eÛÌ`æ
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
 * @brief eÛ­Ë
 * @param [in] ax ­ËÌxÀW
 * @param [in] ay ­ËÌyÀW
 *
 */
void Bullet::Fire(const double ax, const double ay)
{
	aliveFlg = true;
	x = ax;
	y = ay;
}

/**
 * @brief eÛÌú»
 *
 */
void Bullet::Reset()
{
	aliveFlg = false;
	x = 0;
}