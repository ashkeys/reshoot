/**
 * @file Player.h
 * @brief Player�N���X�w�b�_�[
 *
 * �v���C���[�����삷��L�����Ɋւ���N���X
 *
 */

// include
#include "common.h"
#include "Bullet.h"

class Player{
public:
	Player();
	Player(double x, double y, char* fileName);
	~Player();

	void X(double ax) {x = ax;}		/// setter
	double X()				{return x;}	/// getter
	void Y(double ay)	{y = ay;}		/// setter
	double Y()				{return y;}	/// getter

	void Draw();
	void Move();
	void Input();
	void Collide();

private:
	double x, y;
	double dx, dy;
	//Vector2D dir;
	char keyBuf[256];						/// �L�[���͗p�̃o�b�t�@�B�z��T�C�Y256�Œ�B

	int drawX, drawY;						/// �`��p���W
	int hImage;									/// �`��n���h��
	int imageSizeX, imageSizeY;
	double scale;

	//�e�ۂ�Player���番������\��
	Bullet bullets[P_BULLET_MAX];
	int bulletIndex;

	//Collider collider;
	//�Փ˔���̃T�C�Y����p�ϐ����K�v�B���G�Ȍ`�̃L�����̏ꍇ�Acollider�������K�v�B
};