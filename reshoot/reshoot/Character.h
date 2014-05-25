#ifndef __CHARACTER_H__
#define __CHARACTER_H__

/**
 * @file Character.h
 * @brief Characterクラスヘッダー
 *
 * @note 凍結中
 */

// include
#include <string>

#include "DrawObj.h"

// 前方宣言
enum DrawType;

/**
 * @brief Characterクラス
 *
 * プレイヤーや敵などの基本となるクラス
 *
 */
class Character : public DrawObj{
	typedef DrawObj Base;	///< 基底クラスをtypedef

public:
	Character();
	~Character();

	void Init(const double x, const double y, const char* fileName, DrawType type);
	void Input(const int buf);
	void Update();
	//void Draw();

protected:
	virtual void Draw();

private:
	//アニメーション用画像クラスへのポインタ

	double x, y;
	double dx, dy;
	//Vector2D dir;

	// キャラクターパラメータ
	std::string name;
	int hp;
	double speed;

	//所持Weapon
	

};

#endif