#ifndef __PLAYER_H__
#define __PLAYER_H__

/**
 * @file Player.h
 * @brief Player�N���X�w�b�_�[
 *
 */

// include
#include "DrawObj.h"
#include "Character.h"

// �O���錾
class Bullet;

/**
 * @brief Player�N���X
 *
 * ���삷��L�����N�^�[�Ɋւ���N���X
 *
 */
class Player : public Character{
	typedef Character Base;	///< ���N���X��typedef

public:
	Player();
	Player(double x, double y, char* fileName, Bullet* bullets);
	~Player();

	void Init(const int id, const double x, const double y, char* fileName, Bullet* bullets);
	void Input(const int buf);
	void Update();
	void Draw();

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

	// Other method
	void Reset();

	double x, y;
	double dx, dy;
	//Vector2D dir;

	int drawX, drawY;						/// �`��p���W
	int hImage;									/// �`��n���h��
	int imageSizeX, imageSizeY;
	double scale;

	Bullet* myBullets;
	int bulletIndex;

	//Collider collider;
	//�Փ˔���̃T�C�Y����p�ϐ����K�v�B���G�Ȍ`�̃L�����̏ꍇ�Acollider�������K�v�B
};

#endif