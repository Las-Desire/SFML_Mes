#include "../Includes/MapControl.h"
#include "../Includes/Define.h"
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

int MapControl::AddBlock(int * BlockLine, int Count, int Direction)
{
	if (Direction == 1) {
		int Input_place = 0;
		for (int i = 0; i < Count; i++)
		{
			if (BlockLine[i] == BlockLine[i + 1] && i != Count - 1)
			{
				if (BlockLine[i] != 0)
				{
					int Temp = BlockLine[i] + BlockLine[i + 1];
					BlockLine[i] = 0;
					BlockLine[i + 1] = 0;
					BlockLine[Input_place++] = Temp;
				}
				i++;
			}
			else
			{
				if (BlockLine[i] != 0)
				{
					int Temp = BlockLine[i];
					BlockLine[i] = 0;
					BlockLine[Input_place++] = Temp;
				}
			}
		}
		return Input_place - 1; // ������ �����Ͱ� �ִ� Index ��ġ;
	}
	else if (Direction == -1)
	{
		int Input_place = Count - 1;
		for (int i = Count - 1; i >= 0; i--)
		{
			if (BlockLine[i] == BlockLine[i - 1] && i != 0)
			{
				if (BlockLine[i] != 0)
				{
					int Temp = BlockLine[i] + BlockLine[i - 1];
					BlockLine[i] = 0;
					BlockLine[i - 1] = 0;
					BlockLine[Input_place--] = Temp;
				}
				i--;
			}
			else
			{
				if (BlockLine[i] != 0)
				{
					int Temp = BlockLine[i];
					BlockLine[i] = 0;
					BlockLine[Input_place--] = Temp;
				}
			}
		}
		return Input_place + 1; // ������ �����Ͱ� �ִ� Index ��ġ;
	}
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
		Randomi = rand() % Vertical;
		Randomj = rand() % Horizontal;
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

	int BlockCount = 0;
	int BlockLine[Horizontal];
	for (int i = 0; i < Vertical; i++)
	{

		BlockCount = 0;
		for (int j = 0; j < Horizontal; j++)
		{
			if (PTR[i][j] != 0)
				BlockLine[BlockCount++] = PTR[i][j];
		}
		for (int j = BlockCount; j < Horizontal; j++)
			BlockLine[j] = 0;

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

	int BlockCount = 0;
	int BlockLine[Horizontal];
	for (int i = 0; i < Vertical; i++)
	{
		BlockCount = 0;
		for (int j = 0; j < Horizontal; j++)
		{

			if (PTR[i][j] != 0)
				BlockLine[BlockCount++] = PTR[i][j];
		}
		for (int j = BlockCount; j < Horizontal; j++)
			BlockLine[j] = 0;

		int End_Index = AddBlock(BlockLine, Horizontal, -1);
		BlockCount = 0;
		for (int j = 0; j < Horizontal; j++)
		{
			PTR[i][j] = BlockLine[j];
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

	int BlockCount = 0;
	int BlockLine[Vertical];
	for (int i = 0; i < Horizontal; i++)
	{
		BlockCount = 0;
		for (int j = 0; j < Vertical; j++)
		{
			if (PTR[j][i] != 0)
				BlockLine[BlockCount++] = PTR[j][i];
		}
		for (int j = BlockCount; j < Vertical; j++)
			BlockLine[j] = 0;
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

	int BlockCount = 0;
	int BlockLine[Vertical];
	for (int i = 0; i < Horizontal; i++)
	{
		BlockCount = 0;
		for (int j = 0; j < Vertical; j++)
		{
			if (PTR[j][i] != 0)
				BlockLine[BlockCount++] = PTR[j][i];
		}
		for (int j = BlockCount; j < Vertical; j++)
			BlockLine[j] = 0;
		int End_Index = AddBlock(BlockLine, Vertical, -1);
		for (int j = 0; j < Vertical; j++)
		{
			PTR[j][i] = BlockLine[j];
		}
	}
}