// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned int stdRand()
{
	return (rand() % MyRand::MYRAND_MAX) + MyRand::MYRAND_MIN;
}

MyRand::MyRand() : _mySeed(0)
{

}

void MyRand::initSeed(const unsigned int seed)
{
	_mySeed = seed;
}

unsigned int MyRand::rand()
{
	// �������ɓƎ������̌v�Z������

	// ���݃I���W�i���̗����v�Z
	unsigned int r = _mySeed * 11111 + 55555;
	_mySeed = r;
	r += r / 128;
	return (r % MYRAND_MAX) + MYRAND_MIN;
}

MyRand::~MyRand()
{
}
