#ifndef __DRAW_MGR_H__
#define __DRAW_MGR_H__

/**
 * @file DrawMgr.h
 * @brief DrawMgr�N���X�w�b�_�[
 *
 * �`��Ǘ��N���X
 *
 * @sa DrawObj.h
 */

// include
#include <list>

// �O���錾
class DrawObj;

class DrawMgr
{
public:
	DrawMgr();

	virtual void Draw();

	void Regist(DrawObj* obj);

protected:
	std::list<DrawObj*> drawList;

};

#endif