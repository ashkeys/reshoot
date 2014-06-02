#ifndef __BULLET_H__
#define __BULLET_H__

/**
 * @file Bullet.h
 * @brief Bullet�N���X�w�b�_�[
 *
 */

// include
#include "DrawObj.h"

/**
 * @brief Bullet�N���X
 *
 */
class Bullet : public DrawObj{
	typedef DrawObj Base;	///< ���N���X��typedef

public:
	Bullet();
	~Bullet();

	void Init(const double x, const double y, const char* fileName);
	void Input();
	void Update();

	// ��Upublic�Ői�߂�
	void Fire(const double x, const double y);
	void Reset();	

private:
	// Update method
	void Move();
	void Collide();
	void SendDataToParent();

	static DrawType s_drawType;
	double x, y;
	//Vector2D dir;
	bool activeFlg;		/// ���ˁ`���e�̊Ԃ�true

	//Collider collider;
};

#endif