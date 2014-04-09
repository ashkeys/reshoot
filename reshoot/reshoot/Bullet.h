/**
 * @file Bullet.h
 * @brief Bulletクラスヘッダー
 *
 * Playerが発射する弾丸に関するクラス
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

	bool aliveFlg;		/// 発射～着弾の間にtrue
	
	int drawX, drawY;		/// 描画用座標
	int hImage;					/// 描画ハンドル
	int imageSizeX, imageSizeY;

	//Collider collider;
	//衝突判定のサイズ決定用変数が必要。複雑な形のキャラの場合、colliderも複数必要。
};
