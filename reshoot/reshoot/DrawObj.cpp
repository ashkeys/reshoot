/**
 * @file DrawObj.cpp
 * @brief DrawObj�N���X�����t�@�C��
 *
 */

// include
#include "DxLib.h"
#include "common.h"
#include "DrawObj.h"
#include "DrawMgr.h"

static DrawMgr* s_drawMgr;

/* ______________________________________________________________________________________public method */

/**
 * @brief �g�p����DrawMgr��static�ϐ��ɃZ�b�g
 *
 */
void DrawObj::SetDrawMgr(DrawMgr* mgr)
{
	s_drawMgr = mgr;
}

/* ______________________________________________________________________________________protected method */

/**
 * @brief �R���X�g���N�^
 *
 */
DrawObj::DrawObj() : id(-1), scale(1.0), angle(0.0)
{
}

/**
 * @brief �`��
 *
 */
void DrawObj::Draw()
{
	if(activeFlg == true){
		drawX = static_cast<int>( x - (imageSizeX / 2) );
		drawY = static_cast<int>( y - (imageSizeY / 2) );
		DrawRotaGraph(drawX, drawY, scale, angle, hImage, true);
	}
}

/**
 * @brief ������
 *
 * @param [in] id ���ʔԍ�
 * @param [in] x ����x���W
 * @param [in] y ����y���W
 * @param [in] fileName �摜�t�@�C����
 * @param [in] type �`��^�C�v
 *
 */
void DrawObj::Init(const int id, const double x, const double y, char* fileName, DrawType type)
{
	drawType = type;

	if(s_drawMgr){
		s_drawMgr->Register(this);
	}

	hImage = LoadGraph(fileName);
	GetGraphSize(hImage, &imageSizeX, &imageSizeY);

	this->id = id;
	this->x = x;
	this->y = y;
	activeFlg = true;
}

/**
 * @brief DrawType��ύX����
 *
 */
void DrawObj::setDrawType(DrawType type)
{
	drawType = type;
	s_drawMgr->Replace(id, type);
}
