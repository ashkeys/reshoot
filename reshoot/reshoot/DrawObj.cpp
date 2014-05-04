/**
 * @file DrawObj.cpp
 * @brief DrawObj�N���X�����t�@�C��
 *
 */

// include
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
DrawObj::DrawObj()
{
	if(s_drawMgr){
		s_drawMgr->Register(this);
	}
}

