#ifndef __BULLET_H__
#define __BULLET_H__

/**
 * @file Bullet.h
 * @brief Bullet�N���X�w�b�_�[
 *
 * Player�����˂���e�ۂɊւ���N���X
 *
 */

// include
#include "DrawObj.h"

class Bullet : public DrawObj{
public:
	Bullet();
	~Bullet();

	void Input();
	void Update();
	void Draw();

	// ��Upublic�Ői�߂�
	void Fire(const double ax, const double ay);
	void Reset();	

	/*
	void AliveFlg(const bool flg)	{aliveFlg = flg;}		/// setter
	bool AliveFlg() const					{return aliveFlg;}	/// getter
	*/
private:
	// Update method
	//void Fire(double ax, double ay);
	void Move();
	void Collide();

	// Other method
	//void Reset();

	double x, y;
	//Vector2D dir;

	bool aliveFlg;		/// ���ˁ`���e�̊Ԃ�true
	
	int drawX, drawY;		/// �`��p���W
	int hImage;					/// �`��n���h��
	int imageSizeX, imageSizeY;

	//Collider collider;
	//�Փ˔���̃T�C�Y����p�ϐ����K�v�B���G�Ȍ`�̃L�����̏ꍇ�Acollider�������K�v�B
};

#endif