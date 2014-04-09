/**
 * @file Bullet.cpp
 * @brief Bullet�N���X�����t�@�C��
 *
 */

// include
#include "DxLib.h"
#include "Bullet.h"

/**
 * @brief �R���X�g���N�^
 *
 */
Bullet::Bullet() : x(0), y(100), aliveFlg(false)
{
	hImage = LoadGraph("../data/image/bullet.png");
	GetGraphSize(hImage, &imageSizeX, &imageSizeY);
}

/**
 * @brief �f�X�g���N�^
 *
 */
Bullet::~Bullet()
{
	aliveFlg = false;
}

/**
 * @brief �e�ۂ̕`��
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

/**
 * @brief �e�۔���
 *
 */
void Bullet::Fire(double ax, double ay)
{
	x = ax;
	y = ay;
}

/**
 * @brief �e�ۂ̈ړ�
 *
 */
void Bullet::Move()
{
	if(aliveFlg == true){
		x += 10;
	}
}

/**
 * @brief �e�ۂ̏�����
 *
 */
void Bullet::Init()
{
	aliveFlg = false;
	x = 0;
}

/**
 * @brief �e�ۂ̏Փ˔���
 *
 */
void Bullet::Collide()
{
	if(aliveFlg == true){
	
	}
}