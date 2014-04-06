#include "Player.h"
#include "DxLib.h"

Player::Player() : x(0), y(0), dx(0), dy(0), hImage(-1), scale(1.0)
{
}

Player::Player(double x, double y, char* fileName) : x(0), y(0), dx(0), dy(0), scale(1.0)
{
	hImage = LoadGraph(fileName);
}

void Player::Draw()
{
	drawX = static_cast<int>(x);
	drawY = static_cast<int>(y);
	DrawGraph(drawX, drawY, hImage, true);
}

void Player::Move()
{
	x += dx;
	y += dy;
}

void Player::Input()
{
	dx += 0.1;
	dy += 0.1;
}