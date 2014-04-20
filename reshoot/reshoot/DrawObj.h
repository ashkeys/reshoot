#ifndef __DRAW_OBJ_H__
#define __DRAW_OBJ_H__

/**
 * @file DrawObj.h
 * @brief DrawObjクラスヘッダー
 *
 * 描画オブジェクト基底クラス
 *
 * @sa DrawMgr.h
 */

// 前方宣言
class DrawMgr;

class DrawObj
{
public:
	virtual void Draw() = 0;

	static void SetDrawMgr(DrawMgr* mgr);

protected:
	DrawObj();

private:
	//static DrawMgr* s_drawMgr;

};

#endif