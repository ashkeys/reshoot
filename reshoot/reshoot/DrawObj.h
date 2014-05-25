#ifndef __DRAW_OBJ_H__
#define __DRAW_OBJ_H__

/**
 * @file DrawObj.h
 * @brief DrawObj�N���X�w�b�_�[
 *
 * @sa DrawMgr.h
 */

// �O���錾
class DrawMgr;
enum DrawType;

/**
 * @brief DrawObj�N���X
 *
 * �`��I�u�W�F�N�g���N���X
 *
 */
class DrawObj
{
public:
	void Draw();

	static void SetDrawMgr(DrawMgr* mgr);

protected:
	DrawObj();
	void Init(const double x, const double y, const char* fileName, DrawType type);
	void setDrawType(DrawType type);

	void X(const double x)	{this->x = x;}		///< setter
	double X() const				{return this->x;}	///< getter
	void Y(const double y)	{this->y = y;}		///< setter
	double Y() const				{return this->y;}	///< getter

private:
	int id;
	DrawType drawType;
	bool activeFlg;
	double x, y;
	int drawX, drawY;						///< �`��p���W
	int hImage;									///< �`��n���h��
	int imageSizeX, imageSizeY;
	double scale;
	double angle;

	static int currentId;
	static DrawMgr* s_drawMgr;

};

#endif