#pragma once
#include "Blocks.h"
#include "Controller.h"

//색상
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

//두번째 게임 Scene
void InGameFrame();
//게임에서 출력될 다음 블록 밀리보기!
void ShowNextBlock();
//게임에서 출력될 다음 블록미리보기 삭제
void DeleteNextBlock();
//미리 보여질 블록을 배열로 정의했습니다.
int NextBlock[6][6]; //Next Stage
int static Rotation = 0;

void EndGameFrame();
void GameTitle();

/*
*Controller.c 소스 파일의 tetris_process()메서드에서
* 테트리스 보드 안 현재 블록이 출력 "addBlock(shape, rotate)">"되고,
*한칸 내려가면 현재 출력된 블록 삭제후
* y값 증가된 상태로 현재 블록 다시 출력
* 블록을 출력, 삭제하는 함수입니다.
*/
void addBlock(int shape, int rotate);
void deleteBlock();

//보드 생성 0 과 1 생성 1 = 벽, 0 = 빈 공간
void createBoards();
int board[BoardHeight][BoardWidth];
void printBoards();

void textcolor(int color_number);
