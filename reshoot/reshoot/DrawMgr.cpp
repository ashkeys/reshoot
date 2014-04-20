/**
 * @file DrawMgr.cpp
 * @brief DrawMgr�N���X�����t�@�C��
 *
 */

// include
#include "DrawMgr.h"
#include "DrawObj.h"

/* ______________________________________________________________________________________public method */

/**
 * @brief �R���X�g���N�^
 *
 */
DrawMgr::DrawMgr()
{
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
void DrawMgr::Regist(DrawObj* obj)
{
	drawList.push_back(obj);
}
