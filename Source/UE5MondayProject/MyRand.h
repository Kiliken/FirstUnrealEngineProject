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
	// �萔

	static const int MYRAND_MIN = 0;		// �����ŏ��l
	static const int MYRAND_MAX = 3000;		// �����ő�l

	//----------------------------------------------------------------------
	// ���\�b�h						// �R���X�g���N�^
	void initSeed(const unsigned int seed);	// �V�[�h�l�̏�����
	unsigned int rand();					// �Ǝ�����		// �x���`�}�[�N

private:
	//----------------------------------------------------------------------
	// �t�B�[���h

	unsigned int _mySeed = 0;		// �Ǝ������̃����_���V�[�h�l

};
