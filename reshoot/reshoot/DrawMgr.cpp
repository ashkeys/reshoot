/**
 * @file DrawMgr.cpp
 * @brief DrawMgr�N���X�����t�@�C��
 *
 */

// include
#include "DrawMgr.h"
#include "DrawObj.h"

DrawMgr* DrawMgr::instance = NULL;

/* ______________________________________________________________________________________public method */

/**
 * @brief �C���X�^���X��Ԃ�
 *
 */
DrawMgr* DrawMgr::Instance()
{
	return instance;
}

/**
 * @brief �C���X�^���X�̐���
 *
 */
void DrawMgr::Create()
{
	if(!instance){
		instance = new DrawMgr();
	}
}

/**
 * @brief �C���X�^���X�̔j��
 *
 */
void DrawMgr::Destroy()
{
	delete instance;
	instance = NULL;
}

/**
 * @brief drawList�������Ԃɕ`��
 *
 */
void DrawMgr::Draw()
{
	std::list<DrawObj*>::iterator it = drawList.begin();

	while( it != drawList.end() ){
		if(*it){
			(*it)->Draw();
		}

		++it;
	}
}

/**
 * @brief �`�惊�X�g�ɓo�^
 * @param [in] obj �o�^����I�u�W�F�N�g
 *
 */
void DrawMgr::Register(DrawObj* obj)
{
	drawList.push_back(obj);
}

/* ______________________________________________________________________________________private method */

/**
 * @brief �R���X�g���N�^
 *
 */
DrawMgr::DrawMgr()
{
}

/**
 * @brief �R�s�[�R���X�g���N�^
 *
 * @param [in] cpy �R�s�[�̎Q��
 *
 */
DrawMgr::DrawMgr(const DrawMgr& cpy)
{
}

/**
 * @brief �f�X�g���N�^
 *
 */
DrawMgr::~DrawMgr()
{
}
