/**
 * @file Character.cpp
 * @brief Character�N���X�����t�@�C��
 *
 */

// include
#include "Character.h"

/* ______________________________________________________________________________________public method */

/**
 * @brief �R���X�g���N�^
 *
 */
Character::Character()
{
}

/**
 * @brief �f�X�g���N�^
 *
 */
Character::~Character()
{
}

/**
 * @brief ������
 *
 * @param [in] id ���ʔԍ�
 * @param [in] x ����x���W
 * @param [in] y ����y���W
 * @param [in] fileName �摜�t�@�C����
 * @param [in] type �`��^�C�v
 *
 */
void Character::Init(const int id, const double x, const double y, char* fileName, DrawType type)
{
	Base::Init(id, x, y, fileName, type);
}

/**
 * @brief �`��
 *
 */
void Character::Draw()
{
	
}