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

	int drawX, drawY;
	int hImage;
	double scale;
};