#pragma once
#include "Blocks.h"
#include "Controller.h"

//����
typedef enum Color {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VIOLET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
}COLOR;
int static level;

//�ι�° ���� Scene
void InGameFrame();
//���ӿ��� ��µ� ���� ��� �и�����!
void ShowNextBlock();
//���ӿ��� ��µ� ���� ��Ϲ̸����� ����
void DeleteNextBlock();
//�̸� ������ ����� �迭�� �����߽��ϴ�.
int NextBlock[6][6]; //Next Stage
int static Rotation = 0;

void EndGameFrame();
void GameTitle();

/*
*Controller.c �ҽ� ������ tetris_process()�޼��忡��
* ��Ʈ���� ���� �� ���� ����� ��� "addBlock(shape, rotate)">"�ǰ�,
*��ĭ �������� ���� ��µ� ��� ������
* y�� ������ ���·� ���� ��� �ٽ� ���
* ����� ���, �����ϴ� �Լ��Դϴ�.
*/
void addBlock(int shape, int rotate);
void deleteBlock();

//���� ���� 0 �� 1 ���� 1 = ��, 0 = �� ����
void createBoards();
int board[BoardHeight][BoardWidth];
void printBoards();

void textcolor(int color_number);
