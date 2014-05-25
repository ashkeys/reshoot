#ifndef __DRAW_MGR_H__
#define __DRAW_MGR_H__

/**
 * @file DrawMgr.h
 * @brief DrawMgrクラスヘッダー
 *
 * @sa DrawObj.h
 * @sa http://marupeke296.com/OOD_No6_CS2_ShootBullet2.html
 */

// include
#include <list>

// 前方宣言
class DrawObj;
enum DrawType;

/**
 * @brief DrawMgrクラス
 *
 * 描画管理クラス
 * シングルトン
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