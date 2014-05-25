#ifndef __DRAW_MGR_H__
#define __DRAW_MGR_H__

/**
 * @file DrawMgr.h
 * @brief DrawMgr�N���X�w�b�_�[
 *
 * @sa DrawObj.h
 * @sa http://marupeke296.com/OOD_No6_CS2_ShootBullet2.html
 */

// include
#include <list>

// �O���錾
class DrawObj;
enum DrawType;

/**
 * @brief DrawMgr�N���X
 *
 * �`��Ǘ��N���X
 * �V���O���g��
 *
 */
class DrawMgr
{
public:
	virtual void Draw();

	static DrawMgr* Instance();
	static void Create();
	static void Destroy();

	void Register(DrawObj* obj);
	void Unregister(DrawObj* obj);
	void ChangeDrawType(DrawObj* obj, DrawType type);

protected:
	std::list<DrawObj*> drawList;

private:
	DrawMgr();
	DrawMgr(const DrawMgr& cpy);
	~DrawMgr();

	static DrawMgr* instance;

};

#endif