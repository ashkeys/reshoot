/**
 * @brief Playerクラスヘッダー
 *
 * プレイヤーが操作するキャラに関するクラス
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
	char keyBuf[256];						/// キー入力用のバッファ。配列サイズ256固定。

	int drawX, drawY;
	int hImage;									/// 描画ハンドル
	int imageSizeX, imageSizeY;
	double scale;
};