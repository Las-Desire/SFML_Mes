//#include "stdafx.h"
#include "../Includes/MapControl.h"
#include "../Includes/Define.h"
#include <iostream>
using namespace std;

void MapControl::InputMap(Map * NewMap)
{
	if (NewMap != nullptr)
	{
		cout << "NULL ������ �ʱ�ȭ �Ҽ� �����ϴ�." << endl;
		exit(1);
	}
	ptr1 = NewMap;
}

void MapControl::AddBlock(int *BlockLine, int Count, int Direction)
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
					if (Temp == EndNumber) { PTR.EndGame(PlayerWin); }
					BlockLine[i] = 0;
					BlockLine[i + 1] = 0;
					BlockLine[Input_place++] = Temp;
					PTR.AddBlank(1);
				}
				i++;
			}
			else
			{
				if (BlockLine[i] != 0)
				{
					if (i != Input_place) 
					{
						int Temp = BlockLine[i];
						BlockLine[i] = 0;
						BlockLine[Input_place] = Temp;
					}
					Input_place++;
				}
				
			}
		}
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
					if (Temp == EndNumber) { PTR.EndGame(PlayerWin); }
					BlockLine[i] = 0;
					BlockLine[i - 1] = 0;
					BlockLine[Input_place--] = Temp;
					PTR.AddBlank(1);
				}
				i--;
			}
			else
			{
				if (BlockLine[i] != 0)
				{
					if (i != Input_place)
					{
						int Temp = BlockLine[i];
						BlockLine[i] = 0;
						BlockLine[Input_place] = Temp;
					}
					Input_place--;
				}
			}
		}
	}
}

bool MapControl::MoveChecking(int * BeforeMoving, int * AfterMoving, int Count)
{
	for (int i = 0; i < Count; i++)
	{
		if (BeforeMoving[i] != AfterMoving[i])
		{
			return true; //��������
		}
	}
	
	return false; // �� ������.
}

bool MapControl::PushKey(int Key)
{
	if (ptr1 == nullptr)
	{
		cout << "MapControl�� Map�� �ʱ�ȭ �����ּ���." << endl;
		exit(1);
	}

	int BlockLineMax; // �� �� ����
	int KeyType; // �����̴� ������ ��������, �������� �����ϴ� ����
	int Direction; // ������ �����Ѵ�. 1�� �������̰� -1�� �ݴ� �����̴�.

	if (Key / Horizontal == -1 || Key / Horizontal == 1)
	{
		BlockLineMax = HorizontalMax;
		KeyType = Horizontal;
		Direction = Key / Horizontal;
	}
	else if(Key / Vertical == -1 || Key / Vertical == 1)
	{
		BlockLineMax = VerticalMax;
		KeyType = Vertical;
		Direction = Key / Vertical;
	}
	else
	{
		cout << "�߸��� Ű���� PushKey()�Լ��� ���޵Ǿ����ϴ�." << endl;
		exit(1);
	}

	bool MoveCheck = false; //���� �������µ� üũ�ϴ� �Լ��̴�.
	int BlockIndex = 0;
	int* BlockLine = new int[BlockLineMax];  // �� �̵� ���¸� �����Ѵ�.
	int* BeforeBlock = new int[BlockLineMax]; //�����̱��� �� ���¸� �����Ѵ�.
	
	for (int i = 0; i < (KeyType == Vertical ? HorizontalMax : VerticalMax); i++)
	{
		BlockIndex = 0; // �� �迭�� ���� �����͸� ������ Index ���̴�.
		for (int j = 0; j < BlockLineMax; j++)
		{
			
			if (KeyType == Vertical)
			{
				BeforeBlock[j] = PTR[i][j];
				if (PTR[i][j] != 0) {
					BlockLine[BlockIndex++] = PTR[i][j];
				}
			}
			else
			{
				BeforeBlock[j] = PTR[j][i];
				if (PTR[j][i] != 0) {
					BlockLine[BlockIndex++] = PTR[j][i];
				}
			}
		}
		for (int j = BlockIndex; j < BlockLineMax; j++) // ���� ������ ������ 0���� �ʱ�ȭ �Ѵ�.
		{
			BlockLine[j] = 0;
		}

		AddBlock(BlockLine, BlockLineMax, Direction);
		MoveCheck = MoveChecking(BeforeBlock, BlockLine, BlockLineMax);

		for (int j = 0; j < BlockLineMax; j++)
		{
			if (KeyType == Vertical)
			{
				PTR[i][j] = BlockLine[j];
			}
			else 
			{
				PTR[j][i] = BlockLine[j];
			}
		}
	}

	delete[] BlockLine;
	delete[] BeforeBlock;

	return MoveCheck;
}

void MapControl::CreateBlock()
{

	if (ptr1 == nullptr)
	{
		cout << "MapControl�� Map�� �ʱ�ȭ �����ּ���." << endl;
		exit(1);
	}
	if (PTR.IsFull())
	{
		return;
	}

	int Randomi, Randomj;
	do
	{
		Randomi = rand() % VerticalMax;
		Randomj = rand() % HorizontalMax;
	} while (PTR[Randomi][Randomj] != 0);

	int RandResult = rand() % 10;
	if (RandResult == 1) PTR[Randomi][Randomj] = 4;
	else PTR[Randomi][Randomj] = 2;
	PTR.AddBlank(-1);
	
}