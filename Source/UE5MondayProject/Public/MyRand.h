// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UE5MONDAYPROJECT_API MyRand
{
public:
	MyRand();
	~MyRand();
public:
	//----------------------------------------------------------------------
	// 定数

	static const int MYRAND_MIN = 0;		// 乱数最小値
	static const int MYRAND_MAX = 3000;		// 乱数最大値

	//----------------------------------------------------------------------
	// メソッド						// コンストラクタ
	void initSeed(const unsigned int seed);	// シード値の初期化
	unsigned int rand();					// 独自乱数		// ベンチマーク

private:
	//----------------------------------------------------------------------
	// フィールド

	unsigned int _mySeed = 0;		// 独自乱数のランダムシード値

};
