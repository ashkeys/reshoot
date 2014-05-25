/**
 * @file Bullet.cpp
 * @brief Bullet�N���X�����t�@�C��
 *
 */

// include
#include "DxLib.h"
#include "common.h"
#include "Bullet.h"

DrawType Bullet::s_drawType = middleCharaObj;

/* ______________________________________________________________________________________public method */

/**
 * @brief �R���X�g���N�^
 *
 */
Bullet::Bullet()
{

}

/**
 * @brief �f�X�g���N�^
 *
 */
Bullet::~Bullet()
{
	activeFlg = false;
}

/**
 * @brief ������
 *
 * @param [in] id ���ʔԍ�
 * @param [in] x ����x���W
 * @param [in] y ����y���W
 * @param [in] fileName �摜�t�@�C����
 *
 */
void Bullet::Init(const double x, const double y, const char* fileName)
{
	Base::Init(x, y, fileName, s_drawType);

	this->x = x;
	this->y = y;
	activeFlg = false;
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
	SendDataToParent();
}

/* ______________________________________________________________________________________private method */

/* ______________________________________________________________________Update method */

/**
 * @brief �ړ�
 *
 */
void Bullet::Move()
{
	if(activeFlg == true){
		x += 10;
	}
}

/**
 * @brief �Փ˔���
 *
 */
void Bullet::Collide()
{
	if(activeFlg == true){
	
	}
}

/**
 * @brief �e�N���X�ɍX�V��̃f�[�^�𑗂�
 *
 */
void Bullet::SendDataToParent()
{
	Base::X(x);
	Base::Y(y);
}

/* ______________________________________________________________________Other method */

/**
 * @brief ����
 * @param [in] x ���ˎ���x���W
 * @param [in] y ���ˎ���y���W
 *
 */
void Bullet::Fire(const double x, const double y)
{
	activeFlg = true;
	this->x = x;
	this->y = y;
}

/**
 * @brief ��ԃ��Z�b�g
 *
 */
void Bullet::Reset()
{
	activeFlg = false;
	x = 0;
}