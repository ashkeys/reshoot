#ifndef __CHARACTER_H__
#define __CHARACTER_H__

/**
 * @file Character.h
 * @brief Character�N���X�w�b�_�[
 *
 */

// include
#include <string>

#include "DrawObj.h"

// �O���錾
enum DrawType;

/**
 * @brief Character�N���X
 *
 * �v���C���[��G�Ȃǂ̊�{�ƂȂ�N���X
 *
 */
class Character : public DrawObj{
	typedef DrawObj Base;	///< ���N���X��typedef

public:
	Character();
	~Character();

	void Init(const int id, const double x, const double y, char* fileName, DrawType type);
	void Input(const int buf);
	void Update();
	//void Draw();

protected:
	virtual void Draw();

private:
	//�A�j���[�V�����p�摜�N���X�ւ̃|�C���^

	double x, y;
	double dx, dy;
	//Vector2D dir;

	// �L�����N�^�[�p�����[�^
	std::string name;
	int hp;
	double speed;

	//����Weapon
	

};

#endif