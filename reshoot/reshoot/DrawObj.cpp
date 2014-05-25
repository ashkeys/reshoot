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

int DrawObj::currentId = 0;
DrawMgr* DrawObj::s_drawMgr = NULL;

/* ______________________________________________________________________________________public method */

/**
 * @brief �g�p����DrawMgr��static�ϐ��ɃZ�b�g
 *
 */
void DrawObj::SetDrawMgr(DrawMgr* mgr)
{
	s_drawMgr = mgr;
}

/**
 * @brief �`��^�C�v��ύX����
 *
 * @param [in] type �`��^�C�v
 *
 */
void DrawObj::SetDrawType(const DrawType type)
{
	s_drawMgr->ChangeDrawType(this, type);
}

/* ______________________________________________________________________________________protected method */

/**
 * @brief �R���X�g���N�^
 *
 */
DrawObj::DrawObj() : id(currentId), scale(1.0), angle(0.0)
{
	++currentId;
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
void DrawObj::Init(const double x, const double y, const char* fileName, DrawType type)
{
	drawType = type;

	if(s_drawMgr){
		s_drawMgr->Register(this);
	}

	hImage = LoadGraph(fileName);
	GetGraphSize(hImage, &imageSizeX, &imageSizeY);

	this->x = x;
	this->y = y;
	activeFlg = true;
}
