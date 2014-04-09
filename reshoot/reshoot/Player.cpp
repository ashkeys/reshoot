/**
 * @file Player.cpp
 * @brief Player�N���X�����t�@�C��
 *
 */

// include
#include "DxLib.h"
#include "Player.h"

/**
 * @brief �R���X�g���N�^
 *
 */
Player::Player() : x(0), y(0), dx(0), dy(0), hImage(-1), imageSizeX(32), imageSizeY(32), scale(1.0), bulletIndex(0)
{
}

/**
 * @brief �R���X�g���N�^
 *
 * @param [in] x				����x���W
 * @param [in] y				����y���W
 * @param [in] fileName �摜�t�@�C����
 *
 */
Player::Player(double x, double y, char* fileName) : x(x), y(y), dx(0), dy(0), scale(1.0), bulletIndex(0)
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

/**
 * @brief �v���C���[�̕`��
 *
 */
void Player::Draw()
{
	drawX = static_cast<int>( x - (imageSizeX / 2) );
	drawY = static_cast<int>( y - (imageSizeY / 2) );
	DrawGraph(drawX, drawY, hImage, true);

	//���Ƀv���C���[���ňꏏ�ɕ`��
	for(int i = 0; i < P_BULLET_MAX; ++i){
		bullets[i].Draw();
	}
}

/**
 * @brief �v���C���[�̈ړ�
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

	//���Ƀv���C���[���ňꏏ�Ɉړ�
	for(int i = 0; i < P_BULLET_MAX; ++i){
		bullets[i].Move();
	}
}

/**
 * @brief �v���C���[�̓���
 *
 */
void Player::Input()
{
	GetHitKeyStateAll(keyBuf);

	// �L�[���͂ɂ��ړ�
	if( (keyBuf[KEY_INPUT_A] == 1) || (keyBuf[KEY_INPUT_LEFT] == 1) ){
		dx -= 0.1;
	}
	if( (keyBuf[KEY_INPUT_D] == 1) || (keyBuf[KEY_INPUT_RIGHT] == 1) ){
		dx += 0.1;
	}
	if( (keyBuf[KEY_INPUT_W] == 1) || (keyBuf[KEY_INPUT_UP] == 1) ){
		dy -= 0.1;
	}
	if( (keyBuf[KEY_INPUT_S] == 1) || (keyBuf[KEY_INPUT_DOWN] == 1) ){
		dy += 0.1;
	}

	// �e�۔���
	if( keyBuf[KEY_INPUT_Z] == 1 ){
		bullets[bulletIndex].Fire( X(), Y() );
		bullets[bulletIndex].AliveFlg(true);
		
		// �e���؂ꂽ��ŏ��̒e�ۂɖ߂�
		if(bulletIndex < P_BULLET_MAX){
			++bulletIndex;
		}else{
			bulletIndex = 0;
		}
	}

	// �e�ۃ����[�h
	if( keyBuf[KEY_INPUT_R] == 1 ){
		for(int i = 0; i < P_BULLET_MAX; ++i){
			bullets[i].Init();
		}

		bulletIndex = 0;
	}

}

/**
 * @brief �v���C���[�̏Փ˔���i�g��������j
 *
 */
void Player::Collide()
{
}
