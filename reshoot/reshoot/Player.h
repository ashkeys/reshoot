#ifndef __PLAYER_H__
#define __PLAYER_H__

/**
 * @file Player.h
 * @brief Player�N���X�w�b�_�[
 *
 * �v���C���[�����삷��L�����Ɋւ���N���X
 *
 */

// include
#include "Bullet.h"

class Player{
public:
	Player();
	Player(double x, double y, char* fileName, Bullet* bullets);
	~Player();

	void Input(const int buf);
	void Update();
	void Output();

	void X(const double ax) {x = ax;}		/// setter
	double X() const				{return x;}	/// getter
	void Y(const double ay)	{y = ay;}		/// setter
	double Y() const				{return y;}	/// getter

private:
	// Input method
	void CheckKey(const int buf);

	// Update method
	void Move();
	void Collide();

	// Output method
	void Draw();

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