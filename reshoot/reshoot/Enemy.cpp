/**
 * @file Enemy.cpp
 * @brief Enemy�N���X�����t�@�C��
 *
 */

// include
#include "DxLib.h"
#include "common.h"
#include "Enemy.h"
#include "Bullet.h"

DrawType Enemy::s_drawType = middleChara;

/* ______________________________________________________________________________________public method */

/**
 * @brief �R���X�g���N�^
 *
 */
Enemy::Enemy()
{
}

/**
 * @brief �R���X�g���N�^
 *
 * @param [in] x				����x���W
 * @param [in] y				����y���W
 * @param [in] fileName �摜�t�@�C����
 * @param [in] bullets	�v���C���[�̏�������e��
 *
 */
Enemy::Enemy(double x, double y, char* fileName, Bullet* bullets)
{
}

/**
 * @brief �f�X�g���N�^
 *
 */
Enemy::~Enemy()
{
}

/**
 * @brief ������
 *
 * @param [in] id ���ʔԍ�
 * @param [in] x ����x���W
 * @param [in] y ����y���W
 * @param [in] fileName �摜�t�@�C����
 * @param [in] bullets ��������e��
 *
 */
void Enemy::Init(const double x, const double y, const char* fileName, Bullet* bullets)
{
	Base::Init(x, y, fileName, s_drawType);

	this->x = x;
	this->y = y;
	myBullets = bullets;
	bulletIndex = 0;
}

/**
 * @brief ����
 *
 * @param [in] buf ���͏��o�b�t�@
 *
 */
void Enemy::Input(const int buf)
{
	CheckKey(buf);
}

/**
 * @brief �X�V
 *
 */
void Enemy::Update()
{
	Move();

	SendDataToParent();
}

/* ______________________________________________________________________________________private method */

/* ______________________________________________________________________Input method */
/**
 * @brief �L�[���͂̊m�F
 *
 * @param [in] buf ���͏��o�b�t�@
 *
 */
void Enemy::CheckKey(const int buf)
{
	if(buf & PAD_INPUT_DOWN){
		dy += 0.1;		
	}
	if(buf & PAD_INPUT_LEFT){
		dx -= 0.1;		
	}
	if(buf & PAD_INPUT_RIGHT){
		dx += 0.1;		
	}
	if(buf & PAD_INPUT_UP){
		dy -= 0.1;		
	}

	// �e�۔���
	if( buf & PAD_INPUT_1 ){										// PAD_INPUT_1 == z�L�[
		
		// �e���؂ꂽ��ŏ��̒e�ۂɖ߂�
		if(bulletIndex < PLAYER_BULLET_MAX){
			myBullets[bulletIndex].Fire( X(), Y() );
			++bulletIndex;
		}else{
			bulletIndex = 0;
		}
	}

	// �e�ۃ����[�h
	if( buf & PAD_INPUT_2 ){										// PAD_INPUT_2 == x�L�[
		for(int i = 0; i < PLAYER_BULLET_MAX; ++i){
			myBullets[i].Reset();
		}

		bulletIndex = 0;
	}
}

/* ______________________________________________________________________Update method */

/**
 * @brief �ړ�
 *
 */
void Enemy::Move()
{
	if( ( (x + dx) < 0 ) || ( (x + dx) > 640 ) ){
		dx = 0;
	}
	if( ( (y + dy) < 0 ) || ( (y + dy) > 480 ) ){
		dy = 0;
	}

	x += dx;
	y += dy;
}

/**
 * @brief �Փ˔���i�g��������j
 *
 */
void Enemy::Collide()
{
}

/**
 * @brief �e�N���X�ɍX�V��̃f�[�^�𑗂�
 *
 */
void Enemy::SendDataToParent()
{
	Base::X(x);
	Base::Y(y);
}

/* ______________________________________________________________________Other method */

/**
 * @brief ��ԃ��Z�b�g
 *
 */
void Enemy::Reset()
{
}
