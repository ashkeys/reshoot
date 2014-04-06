/**
 * @brief Player�N���X�w�b�_�[
 *
 * �v���C���[�����삷��L�����Ɋւ���N���X
 *
 */

class Player{
public:
	Player();
	Player(double x, double y, char* fileName);
	~Player();

	void Draw();
	void Move();
	void Input();

private:
	double x, y;
	double dx, dy;
	// Vector2D dir;
	char keyBuf[256];						/// �L�[���͗p�̃o�b�t�@�B�z��T�C�Y256�Œ�B

	int drawX, drawY;
	int hImage;									/// �`��n���h��
	int imageSizeX, imageSizeY;
	double scale;
};