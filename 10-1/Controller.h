#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>

/**
* ���ӿ� ��µ� ���� ������ϰ� �����Դϴ�.
* BGM�� ���� ��� "C:\\Users\\Desktop\\tetris\���Ǹ�" ��θ� ���ڿ��� �����մϴ�.
* ��δ� \�� �ƴ϶� \\�� �ؾ���.
* #define������ BGM �����ϰ� main�Լ����� ��� ����.
* main()���� BGM �κ� ��θ� ���� �ص� ��.
*/
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
//������ ���۱� ������ ���� �������� �ʽ��ϴ�.
//#define BGM "C:\\Users\\Desktop\\tetros\\���Ǹ�.wav" / WAV Full Path

enum boardProperty {
	BoardWidth = 14, //���� ���� ����
	BoardHeight = 22, //���� ���� ����
	BoardX = 4, //�ܼ�â���� ��µ� ���� X��ǥ
	BoardY = 3 //�ܼ�â���� ��µ� ���� Y��ǥ
};

enum Keys {
	LEFT = 75, //Ű���� ���� Ű
	RIGHT = 77,		//Ű���� ������ Ű
	UP = 72,		//Ű���� �� Ű
	DOWN = 80,		//Ű���� �Ʒ� Ű
	ARROW = 224,	//Ű���� ����Ű
	SPACEBAR = 32  //Ű���� �����̽� Ű
};

enum gameSpeed {
	easy = 230,  //���� ���̵� ����
	normal = 170, //���� ���̵� ����
	hard = 150  //���� ���̵� �����
};

enum gameSpeed SPEED;

enum blockProperity {
	BlockSIZE = 4, //������ ũ��
	BlockRotate = 4, //������ ȸ��
	BlockType = 7, //������ ����
	BlockStartX = 14, //������ Ŀ��â���� ���۵� x��ǥ
	BlockStartY = 4 //������ Ŀ��â���� ���۵� y��ǥ 
};

	//����ڰ� �Է��� Ư�� ����Ű �ƽ�Ű �ڵ尪
	int nkey;
	
	//���� ���� ���
	short curShape;
	void CurrentShape();
	//���� ���� ���
	short nexShape;
	void NextShape();
	//������ ���� ��ǥ!!!
	short BlockCOL;
	short BlockROW;
	//������ ���� ��ǥ
	short prevBlockCOL;
	short prevBlockROW;
	//��Ʈ���� ���� �� ���� ��ġ�ϴ� Ŀ��
	COORD Cursor;
	//���� ���� �����
	void deletePrevBlock();
	//���ھ�
	int static score;
	void printScore();
	//���� ���̵�
	short gameLevel;
	//���ο� ���� ���� ����
	void newBlock();

	/**
	* ���ο� �����ΰ�? (flag����.)
	* ���ο� ���� == true�̶�� ���ο� ������ false ó�� �� �Ŀ�
	* ShowNextBlock() �� ȣ���Ű�� ������ ���� ������ �� ���� ȭ��
	* ��Ʈ���� ���� ���� �����ش�!
	*/
	boolean IsNextBlock;

	/**
	* ȸ�� ����� ����Ű�� �Է� ���� ��
	* turm(���� ������ ȸ�� ���� 0,1,2,3�� ���� ��� turn == 0 ��° ȸ�� ����(�ʱ�����̶��)
	*'->' ����Ű�� ���� turn ==1�� �ǰ�, ����
	*block���� ������
	*block[Ư���� ���� ���][0][][]����
	*block[Ư���� ���� ���][1][][]�� ȸ���� ������ ��µ� �� �ֵ��� turn�� ���¸�
	*RotateBlock() �޼��带 ���� ��ȯ�Ѵ�.
	*/
	short turn;
	void RotateBlock(); //����Ű ���� �� rotate�� ���� ����Ű ����
	

	/**
	* IsCollision(int shape, int rotate, int curX, int curY)
	* ���� �ܼ�â�� Ŀ���� Cursor���� ��ĭ �������� ��
	* �� ��ǥ���� �׷����� ������ ��Ʈ���� ������ �ٴڰ� ��ų�,
	* bottom���� ������ ��� ������ ���ϰ� ������, true ��ȯ
	* �׷� ��� ���� ��ǥ���� ������ �ٴڰ� ��ų�, �ٴ�ȭ?��(����ȭ��?) �����̶�� �ǴܵǱ⿡
	* ���� ��ǥ�� ��µ� ������ ������ �ٴڰ� �νĽ�ŵ�ϴ�. blockFixed(int shape,int rotate)
	*/
	boolean IsCollision(int shape, int rotate, int curX, int curY);
	//������ bottom�� ����� ���
	void blockFixed(int shape, int rotate);
	

	/**
	* ������ Ư�� �������� �������� ����Ǿ��°�? IsMaxLine()
	* yes? -> deleteLine()
	*/
	boolean IsMaxLine();
	void deleteLine();
	//ó�� ������ ������ õ��� ��Ҵ°� ?
	boolean IsOverHeight();

	//�̸����� ���� ����� ���� �� �ش� ��ǥ �����ؾ��մϴ�.
	COORD previewPoint;
	//�̸����� ����, ���� ���� ���Ŀ� ���� ���� ȭ�鿡 ǥ��.
	void previewBlock(int shape, int rotate);
	//��Ʈ���� ���ư��µ� �־� ���� �߿��� �Լ�.(�����Լ����Դϴ�)
	void GameProcess();