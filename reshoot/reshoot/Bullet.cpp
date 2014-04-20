/**
 * @file Bullet.cpp
 * @brief Bullet�N���X�����t�@�C��
 *
 */

// include
#include "DxLib.h"
#include "Bullet.h"

/* ______________________________________________________________________________________public method */

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
 * @brief ����
 *
 */
void Bullet::Input()
{
}

/**
 * @brief �X�V
 *
 */
void Bullet::Update()
{
	Move();
	Collide();
}

/**
 * @brief �`��
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

/* ______________________________________________________________________________________private method */

/* ______________________________________________________________________Update method */

/**
 * @brief �ړ�
 *
 */
void Bullet::Move()
{
	if(aliveFlg == true){
		x += 10;
	}
}

/**
 * @brief �Փ˔���
 *
 */
void Bullet::Collide()
{
	if(aliveFlg == true){
	
	}
}

/* ______________________________________________________________________Other method */

/**
 * @brief ����
 * @param [in] ax ���ˎ���x���W
 * @param [in] ay ���ˎ���y���W
 *
 */
void Bullet::Fire(const double ax, const double ay)
{
	aliveFlg = true;
	x = ax;
	y = ay;
}

/**
 * @brief ��ԃ��Z�b�g
 *
 */
void Bullet::Reset()
{
	aliveFlg = false;
	x = 0;
}