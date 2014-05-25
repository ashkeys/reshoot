#ifndef __DRAW_OBJ_H__
#define __DRAW_OBJ_H__

/**
 * @file DrawObj.h
 * @brief DrawObjクラスヘッダー
 *
 * @sa DrawMgr.h
 */

// 前方宣言
class DrawMgr;
enum DrawType;

/**
 * @brief DrawObjクラス
 *
 * 描画オブジェクト基底クラス
 *
 */
class DrawObj
{
public:
	static void SetDrawMgr(DrawMgr* mgr);
	
	void Draw();

	int Id() const {return this->id;}	///< getter
	void SetDrawType(const DrawType type);									///< setter + α
	DrawType GetDrawType() const	{return this->drawType;}	///< getter

protected:
	DrawObj();
	void Init(const double x, const double y, const char* fileName, DrawType type);

	void X(const double x)	{this->x = x;}		///< setter
	double X() const				{return this->x;}	///< getter
	void Y(const double y)	{this->y = y;}		///< setter
	double Y() const				{return this->y;}	///< getter

private:
	int id;
	DrawType drawType;
	bool activeFlg;
	double x, y;
	int drawX, drawY;						///< 描画用座標
	int hImage;									///< 描画ハンドル
	int imageSizeX, imageSizeY;
	double scale;
	double angle;

	static int currentId;
	static DrawMgr* s_drawMgr;

};

#endif