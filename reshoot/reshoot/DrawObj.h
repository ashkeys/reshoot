#ifndef __DRAW_OBJ_H__
#define __DRAW_OBJ_H__

/**
 * @file DrawObj.h
 * @brief DrawObj�N���X�w�b�_�[
 *
 * �`��I�u�W�F�N�g���N���X
 *
 * @sa DrawMgr.h
 */

// �O���錾
class DrawMgr;

class DrawObj
{
public:
	virtual void Draw() = 0;

	static void SetDrawMgr(DrawMgr* mgr);

protected:
	DrawObj();

private:
	int drawX, drawY;						/// �`��p���W
	int hImage;									/// �`��n���h��
	int imageSizeX, imageSizeY;
	double scale;

};

#endif