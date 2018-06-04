/*************************************************************************
> File Name: Map.cpp
> Project Name: 2048 in GSM
> Author: ������
> Purpose: Definition of Map in Game
> Created Time: 2018/06/04
> Copyright (c) 2018, ������
*************************************************************************/
#pragma once
#include "2048Define.h"

class Map
{
private:
	int MapArray[Vertical][Horizontal];

public:
	int* operator[](int idx);
	void ShowMap();
};