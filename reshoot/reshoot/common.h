#ifndef __COMMON_H__
#define __COMMON_H__

/**
 * @file common.h
 * @brief ���ʒ�`�t�@�C��
 *
 * �}�N����`��O���[�o���ϐ����܂Ƃ߂ĊǗ�����
 *
 */

// �萔
const int PLAYER_BULLET_MAX = 64;	///< �v���C���[�̒e��MAX
const int ENEMY_MAX = 16;					///< �G�l�~�[�̏o����MAX
const int ENEMY_BULLET_MAX = 32;	///< �G�l�~�[�̒e��MAX

/**
 * @brief �`��^�C�v�񋓌^
 *
 * [��ʉ�] 0 >>>> �ő�l [��ʎ�O]
 * �ǂ��܂Ŏg�����͖���
 *
 */
enum DrawType{
	farView = 0,		///< ���i
	farFX,					///< ���i�G�t�F�N�g
	middleView,			///< ���i
	middleFX,				///< ���i�G�t�F�N�g
	farChara,				///< ���L����
	farCharaObj,		///< ���L�����t���I�u�W�F�N�g
	farCharaFX,			///< ���L�����t���G�t�F�N�g
	middleChara,		///< ���L����
	middleCharaObj,	///< ���L�����t���I�u�W�F�N�g
	middleCharaFX,	///< ���L�����t���G�t�F�N�g
	nearChara,			///< �߃L����
	nearCharaObj,		///< �߃L�����t���I�u�W�F�N�g
	nearCharaFX,		///< �߃L�����t���G�t�F�N�g
	grossFX,				///< �S�̃G�t�F�N�g
	systemView,			///< �V�X�e�����
	popup,					///< �|�b�v�A�b�v
};

#endif