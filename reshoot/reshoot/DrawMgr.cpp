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
	std::list<DrawObj*>::iterator it = drawList.begin();

	while( it != drawList.end() ){
		if(*it){
			if( obj->GetDrawType() < (*it)->GetDrawType() ){
				break;
			}
		}

		++it;
	}

	drawList.insert(it, obj);

	//drawList.push_back(obj);
}

/**
 * @brief �`�惊�X�g����o�^����
 * @param [in] obj �o�^��������I�u�W�F�N�g
 *
 */
void DrawMgr::Unregister(DrawObj* obj)
{
	//std::list<DrawObj*>::iterator it = drawList.begin();

	//while( it != drawList.end() ){
	//	if(*it){
	//		if( obj->Id() == (*it)->Id() ){
	//			drawList.erase(it);
	//			break;
	//		}
	//	}

	//	++it;
	//}

	drawList.remove(obj);
}

/**
 * @brief �`��^�C�v�̕ύX
 * @param [in] id �ύX����I�u�W�F�N�g��id
 * @param [in: type �ύX��̕`��^�C�v
 *
 */
void DrawMgr::ChangeDrawType(DrawObj* obj, DrawType type)
{
	if(obj->GetDrawType() != type){
		Unregister(obj);

		obj->SetDrawType(type);
		Register(obj);
	}
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
