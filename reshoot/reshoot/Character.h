#ifndef __CHARACTER_H__
#define __CHARACTER_H__

/**
 * @file Character.h
 * @brief Characterクラスヘッダー
 *
 */

// include
#include "DrawObj.h"

class Character : public DrawObj{
public:
	Character();
	~Character();

	void Init(int id);
	void Input(const int buf);
	void Update();
	void Draw();

private:
	double x, y;
	double dx, dy;
	//Vector2D dir;

};

#endif