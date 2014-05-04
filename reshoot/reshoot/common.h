#ifndef __COMMON_H__
#define __COMMON_H__

/**
 * @file common.h
 * @brief 共通定義ファイル
 *
 * マクロ定義やグローバル変数をまとめて管理する
 *
 */

/// プレイヤーの弾数MAX
#define P_BULLET_MAX 32

/**
 * @brief 描画タイプ列挙型
 *
 * [画面奥] 0 >>>> 最大値 [画面手前]
 * どこまで使うかは未定
 *
 */
enum DrawType{
	farView = 0,		///< 遠景
	farFX,					///< 遠景エフェクト
	middleView,			///< 中景
	middleFX,				///< 中景エフェクト
	farChara,				///< 遠キャラ
	farCharaObj,		///< 遠キャラ付随オブジェクト
	farCharaFX,			///< 遠キャラ付随エフェクト
	middleChara,		///< 中キャラ
	middleCharaObj,	///< 中キャラ付随オブジェクト
	middleCharaFX,	///< 中キャラ付随エフェクト
	nearChara,			///< 近キャラ
	nearCharaObj,		///< 近キャラ付随オブジェクト
	nearCharaFX,		///< 近キャラ付随エフェクト
	grossFX,				///< 全体エフェクト
	systemView,			///< システム画面
	popup,					///< ポップアップ
};

#endif