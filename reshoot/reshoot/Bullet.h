/**
 * @file Bullet.h
 * @brief Bullet�N���X�w�b�_�[
 *
 * Player�����˂���e�ۂɊւ���N���X
 *
 */

class Bullet{
public:
	Bullet();
	~Bullet();

	void AliveFlg(bool flg)	{aliveFlg = flg;}		/// setter
	bool AliveFlg()					{return aliveFlg;}	/// getter

	void Draw();
	void Fire(double ax, double ay);
	void Move();
	void Init();
	void Collide();

private:
	double x, y;
	//Vector2D dir;

	bool aliveFlg;		/// ���ˁ`���e�̊Ԃ�true
	
	int drawX, drawY;		/// �`��p���W
	int hImage;					/// �`��n���h��
	int imageSizeX, imageSizeY;

	//Collider collider;
	//�Փ˔���̃T�C�Y����p�ϐ����K�v�B���G�Ȍ`�̃L�����̏ꍇ�Acollider�������K�v�B
};
