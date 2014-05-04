/**
 * @file Player.cpp
 * @brief Player�N���X�����t�@�C��
 *
 */

// include
#include "DxLib.h"
#include "common.h"
#include "Player.h"
#include "Bullet.h"

/* ______________________________________________________________________________________public method */

/**
 * @brief �R���X�g���N�^
 *
 */
Player::Player() : x(0), y(0), dx(0), dy(0),
	hImage(-1), imageSizeX(32), imageSizeY(32), scale(1.0), bulletIndex(0)
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
Player::Player(double x, double y, char* fileName, Bullet* bullets) : x(x), y(y), dx(0), dy(0), scale(1.0), myBullets(bullets), bulletIndex(0)
{
	hImage = LoadGraph(fileName);
	GetGraphSize(hImage, &imageSizeX, &imageSizeY);
}

/**
 * @brief �f�X�g���N�^
 *
 */
Player::~Player()
{
}

/*
void Player::Init(double x, double y, char* fileName, Bullet* bullets, int id)
{

}
*/

/**
 * @brief ����
 * @param [in] buf ���͏��o�b�t�@
 *
 */
void Player::Input(const int buf)
{
	CheckKey(buf);
}

/**
 * @brief �X�V
 *
 */
void Player::Update()
{
	Move();
}

/**
 * @brief �`��
 *
 */
void Player::Draw()
{
	drawX = static_cast<int>( x - (imageSizeX / 2) );
	drawY = static_cast<int>( y - (imageSizeY / 2) );
	DrawGraph(drawX, drawY, hImage, true);
}

/* ______________________________________________________________________________________private method */

/* ______________________________________________________________________Input method */
/**
 * @brief �L�[���͂̊m�F
 * @param [in] buf ���͏��o�b�t�@
 *
 */
void Player::CheckKey(const int buf)
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
		if(bulletIndex < P_BULLET_MAX){
			myBullets[bulletIndex].Fire( X(), Y() );
			++bulletIndex;
		}else{
			bulletIndex = 0;
		}
	}

	// �e�ۃ����[�h
	if( buf & PAD_INPUT_2 ){										// PAD_INPUT_2 == x�L�[
		for(int i = 0; i < P_BULLET_MAX; ++i){
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
void Player::Move()
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
void Player::Collide()
{
}

/* ______________________________________________________________________Other method */

/**
 * @brief ��ԃ��Z�b�g
 *
 */
void Player::Reset()
{
}
