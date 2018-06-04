/*************************************************************************
> File Name: DisplayChange.cpp
> Project Name: 2048 in GSM
> Author: ������
> Purpose: Display Update with Map
> Created Time: 2018/06/04
> Copyright (c) 2018, ������
*************************************************************************/
#include "../Includes/MapController.h"
#include "../Includes/2048Define.h"
#include <iostream>
using namespace std;

void MapControl::InputMap(Map * NewMap)
{
	if (NewMap != nullptr)
	{
		cout << "NULL ������ �ʱ�ȭ �Ҽ� �����ϴ�." << endl;
		return;
	}
	ptr1 = NewMap;
}

int MapControl::AddBlock(int * BlockLine, int Count)
{
	int Input_place = 0;
	for (int i = 0; i < Count - 1; i++)
	{
		if (BlockLine[i] == BlockLine[i + 1] && BlockLine[i] != 0)
		{
			BlockLine[Input_place++] = BlockLine[i] + BlockLine[i + 1];
			i++;
		}
	}
	return Input_place - 1; // ������ �����Ͱ� �ִ� Index ��ġ;
}

void MapControl::CreateBlock()
{

	if (ptr1 == nullptr)
	{
		cout << "MapControl�� Map�� �ʱ�ȭ �����ּ���." << endl;
		return;
	}

	int Randomi, Randomj;

	do
	{
		Randomi = rand() % 5;
		Randomj = rand() % 5;
	} while (PTR[Randomi][Randomj] != 0);

	int RandResult = rand() % 10;
	if (RandResult == 1) PTR[Randomi][Randomj] = 4;
	else PTR[Randomi][Randomj] = 2;

}

void MapControl::LeftKey()
{

	if (ptr1 == nullptr)
	{
		cout << "MapControl�� Map�� �ʱ�ȭ �����ּ���." << endl;
		return;
	}

	int BlockLine[Horizontal];
	for (int i = 0; i < Vertical; i++)
	{
		for (int j = 0; j < Horizontal; j++)
		{
			BlockLine[j] = PTR[i][j];
		}

		int End_Index = AddBlock(BlockLine, Horizontal);
		for (int j = 0; j < Horizontal; j++)
		{
			PTR[i][j] = BlockLine[j];
		}
	}
}

void MapControl::RightKey()
{

	if (ptr1 == nullptr)
	{
		cout << "MapControl�� Map�� �ʱ�ȭ �����ּ���." << endl;
		return;
	}

	int BlockLine[Horizontal];
	for (int i = 0; i < Vertical; i++)
	{
		for (int j = 0; j < Horizontal; j++)
		{
			BlockLine[j] = PTR[i][j];
		}

		int End_Index = AddBlock(BlockLine, Horizontal);
		for (int j = Horizontal - 1, l = 0; j >= 0; j--, l++)
		{
			PTR[i][j] = BlockLine[l];
		}
	}
}

void MapControl::UpKey()
{

	if (ptr1 == nullptr)
	{
		cout << "MapControl�� Map�� �ʱ�ȭ �����ּ���." << endl;
		return;
	}

	int BlockLine[Vertical];
	for (int i = 0; i < Horizontal; i++)
	{
		for (int j = 0; j < Vertical; j++)
		{
			BlockLine[j] = PTR[j][i];
		}
		int End_Index = AddBlock(BlockLine, Vertical);
		for (int j = 0; j < Vertical; j++)
		{
			PTR[j][i] = BlockLine[j];
		}
	}
}

void MapControl::DownKey()
{

	if (ptr1 == nullptr)
	{
		cout << "MapControl�� Map�� �ʱ�ȭ �����ּ���." << endl;
		return;
	}

	int BlockLine[Vertical];
	for (int i = 0; i < Horizontal; i++)
	{
		for (int j = 0; j < Vertical; j++)
		{
			BlockLine[j] = PTR[j][i];
		}

		int End_Index = AddBlock(BlockLine, Vertical);
		for (int j = Vertical - 1, l = 0; j >= 0; j--, l++)
		{
			PTR[j][i] = BlockLine[l];
		}
	}
}