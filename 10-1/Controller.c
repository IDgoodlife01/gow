#include "Controller.h"
#include "Screen.h"
#include "ConsoleCursor.h"
#include "AddBlockColor.h"

//함수 설명은 Controller.h 파일에 설명되어 있다.
void RotateBlock() {
	turn = ++turn;
	if (turn == 4) turn = turn % 4;
}
void CurrentShape() { curShape = nexShape;  }
void NextShape() {
	srand((time(NULL)));
	nexShape = rand() % BlockType;
}
void printScore() {
	GotoXY(36, 20);
	printf("◎점수 : %d", score);
}

//시작할 떄 출력된 블록 4 * 4 가 1이랑 2랑 같이 있으면 게임 오버
boolean IsOverHeight() {
	BlockROW = BlockStartX / 2;
	BlockCOL = 1;
	for (int y = 0; y < BlockSIZE; y++) {
		for (int x = 0; x < BlockSIZE; x++) {
			if (board[BlockCOL + y][BlockROW + x * 2] == 2 &&
				board[BlockCOL + y + 1][BlockROW + x * 2] >= 3)
				return true;
		}
	}
	return false;
}
boolean IsCollision(int shape, int rotate, int curX, int curY) {
	//좌표에서 나누기 2해야 한다.
	BlockROW = curX / 2 - BoardX / 2;
	BlockCOL = curY - BoardY;
	for (int y = 0; y < BlockSIZE; y++) {
		for (int x = 0; x < BlockSIZE; x++) {
			if (Blocks[shape][rotate][y][x] == 2) {
				if (board[BlockCOL + y][BlockROW + x] == 1 ||
					board[BlockCOL + y][BlockROW + x] >= 3) {
					return true;
				}
			}
		}
	}
	return false;
}
//블록 삭제하는 것이 아니라 공백으로 출력한다.
void deletePrevBlock() {
	for (int y = 0; y < BlockSIZE; y++) {
		for (int x = 0; x < BlockSIZE; x++) {
			if (board[prevBlockCOL + y][prevBlockROW + x] == 2) {
				GotoXY(previewPoint.X + x * 2, previewPoint.Y + y);
				printf("  ");
			}
		}
	}
	GotoXY(Cursor.X, Cursor.Y);
}
//블럭이 쌓일 위치 가이드
void previewBlock(int shape, int rotate) {
	COORD Pos = Cursor = getCursor();
	while (!IsCollision(curShape, turn, Pos.X, Pos.Y + 1)) {
		++Pos.Y;
		if (IsCollision(curShape, turn, Pos.X, Pos.Y + 1) == true) {
			previewPoint.X = Pos.X;
			previewPoint.Y = Pos.Y;
			prevBlockROW = BlockROW = Pos.X / 2 - BoardX / 2;
			prevBlockCOL = BlockCOL = Pos.Y - BoardY;
			for (int y = 0; y < BlockSIZE; y++) {
				for (int x = 0; x < BlockSIZE; x++) {
					if (Blocks[shape][rotate][y][x] == 2) {
						board[BlockCOL + y][BlockROW + x] = 2;
						GotoXY(Pos.X + x * 2, Pos.Y + y);
						prevAddBlockColor();
					}
				}
			}
			GotoXY(Cursor.X, Cursor.Y);
			return;
		}
	}
}
/**
*현재 보드 안에서 출력되는 특정한 블록에 대해서는 블록의 색을 block type에 따라서 저장
* 초기 버전에 블록이 바닥에 닿아서 쌓일때 보드안에 추가된 블록을 2 로 정함
* 그리고 나니깐 쌓인 블록은 전부 같은 색이 되어버려서,
* 특정 blockType을 매개변수 받은 인자값 shape 에 3씩 더해서 보드 저장
* 이렇게 하면
* 보드 벽 = 1, 보드 안빈 공간 = 0, 보드 안 내려오는 블록 = 2
* bottom에 닿은 블록은 내려오고 있는 블록의 종류에 따라서 0~6 까지라면 + 3을해서
* 최소 3씩 3 = block[0][rotate][][]
*          4 = block[1][rotate][][]
*		   5 = block[2[rotate][][] 가 된다.
*/
void blockFixed(int shape, int rotate) {
	COORD Pos = getCursor();
	BlockROW = Pos.X / 2 - BoardX / 2;
	BlockCOL = Pos.Y - BoardY;
	for (int y = 0; y < BlockSIZE; y++) {
		for (int x = 0; x < BlockSIZE; x++) {
			if ((Blocks[shape][rotate][y][x] == 2))
				if (board[BlockCOL + y][BlockROW + x] == 2) {
					board[BlockCOL + y][BlockROW + x] = shape + 3;
					GotoXY(Pos.X + x * 2, Pos.Y + y);
					addCurrentBlockColor(shape);
				}
		}
	}


//한 라인이 전부 완성 되었는지 체크
	while (true) {
		if (IsMaxLine()) deleteLine();
		else break;
	}
	turn = 0;
	CurrentShape();
	NextShape();
	Cursor.X = BlockStartX;
	Cursor.Y = BlockStartY;
	GotoXY(Cursor.X, Cursor.Y);
	addBlock(curShape, turn);
	deleteBlock();
	IsNextBlock = true;
}
boolean IsMaxLine() {
	for (int y = BoardHeight - 2; y > 1; y--) {
		int count = 0;
		for (int x = 1; x < BoardWidth - 1; x++) {
			if (board[y][x] >= 3)
				++count;
			if (count >= 12)
				return true;
		}
	}
	return false;
}
void deleteLine() {
	COORD Pos = Cursor = getCursor();
	for (int y = BoardHeight - 2; y > 0; y--) {
		int count = 0;
		for (int x = 1; x < BoardWidth - 1; x++) {
			if (board[y][x] >= 3)
				++count;
			if (count >= 12) {
				int height = y;
				score += 1000;
				//여기는 for 문이 반복되는데, 블록이 사라지는 이펙트를 좀 꾸며봤습니다.
				//Sleep 메서드를 사용해 간단하게
				for (int x = 1; x < BoardWidth - 1; x++) {
					board[height][x] = 0;
					if (board[height][x] == 0) {
						GotoXY(x * 2 + BoardX, height + BoardY);
						printf("   "); Sleep(30);
					}
				}
				for (int i = 0; i < 6; i++) {
					for (int x = 1; x < BoardWidth - 1; x++) {
						if (board[height][x] == 0) {
							GotoXY(x * 2 + BoardX, height + BoardY);
							if (i % 2 == 0) printf("□");
							else printf("  ");
						}
					}Sleep(100);
				}

				//한줄 제거한 height 기준으로
				for (height; height > 0; height--) {
					for (int x = 1; x < BoardWidth - 1; x++) {
						board[height][x] = board[height - 1][x];
						if (board[height - 1][x] == 0 || board[height - 1][x] >= 3) { //3 아리 주석 참고.
							GotoXY(x * 2 + BoardX, height + BoardY); printf(" ");
						}
					}
				}
				for (height = y; height > 0; height--) {
					for (int x = 1; x < BoardWidth - 1; x++) {
						if (board[height][x] >= 3 && board[height][x] <= 9) {
							GotoXY(x * 2 + BoardX, height + BoardY);
							/**
							*요기에 -3을 한 이유는 원래 블록의 모양이 4차원 배열인데 인덱스에 따라서 블록의 유행이 달라집니다.
							* 0부터 6까지 총 7개인데, blockFixed()메서드의 코드 리뷰에서 설명했듯이
							* 바닥에 쌓이게된 블록을 색칠하기 쉽게 표현할려고 +3씩 다했는데, (3 ~9 : 0~6에서 +3해서)
							*colorRetention()이 함수는 0 부터 6까지 색깔을 미리 정한 상태에서 -3 했습니다.
							*colorRetention() 함수의 switch문을 3부터 시작해도 되긴합니다.
							*/
							colorRetention(board[height][x] - 3);
						}
						else {
							GotoXY(x * 2 + BoardX, height + BoardY); printf("  ");
						}
						if (height == 1) board[height][x] = 0;
					}
				}
				GotoXY(Cursor.X, Cursor.Y);
				printScore();
				return;
			}
		}
	}
	GotoXY(Cursor.X, Cursor.Y);
	printScore();
}
//블록이 새로 보드 안에 출력될떄 초기값
void newBlock() {
	turn = 0;
	NextShape();
	CurrentShape();
	NextShape();
	Cursor.X = BlockStartX;
	Cursor.Y = BlockStartY;
}
void GameProcess() {
	system("mode con cols=76 lines=28 | title 창의실무프로젝트_테트리스 실습");
	createBoards();
	srand(time(NULL));
	newBlock();
	InGameFrame();
	ShowNextBlock();
	//방향키 계속해서 알수있도록 while()()문과 _kbhit(), _getch()메서드를 사용했습니다.
	//방향키에 대해 잘 이해가 안되시면
	//"Chapter009 Console을 이용한 C 프로그래밍 활용 1"을 참고 해주시기 바랍니다.
	while (true) {
		if (IsNextBlock == true) {
			IsNextBlock = false;
			DeleteNextBlock();
			ShowNextBlock();
		}
		printBoards();
		GotoXY(Cursor.X, Cursor.Y);
		addBlock(curShape, turn);
		previewBlock(curShape, turn);
		if (_kbhit()) {
			nkey = _getch();
			if (nkey == SPACEBAR) {
				while (!IsCollision(curShape, turn, Cursor.X, Cursor.Y + 1)) {
					deletePrevBlock();
					deleteBlock();
					GotoXY(Cursor.X, Cursor.Y + 1);
					addBlock(curShape, turn);
					if (IsCollision(curShape, turn, Cursor.X, Cursor.Y + 1)) {
						blockFixed(curShape, turn);
						break;
					}
				}
				continue;
			}
			if (nkey == ARROW) {
				nkey = _getch();
				int nTurn;
				switch (nkey) {
				case UP:
					nTurn = turn;
					if (!IsCollision(curShape, (++nTurn % 4), Cursor.X, Cursor.Y)) {
						deletePrevBlock();
						deleteBlock();
						RotateBlock();
						addBlock(curShape, turn);
						previewBlock(curShape, turn);
						continue;
					}
					break;
				case LEFT:
					if (!IsCollision(curShape, turn, Cursor.X - 2, Cursor.Y)) {
						deletePrevBlock();
						deleteBlock();
						GotoXY(Cursor.X - 2, Cursor.Y);
						addBlock(curShape, turn);
						previewBlock(curShape, turn);
						continue;
					}
					break;
				case RIGHT:
					if (!IsCollision(curShape, turn, Cursor.X + 2, Cursor.Y)) {
						deletePrevBlock();
						deleteBlock();
						GotoXY(Cursor.X + 2, Cursor.Y);
						addBlock(curShape, turn);
						previewBlock(curShape, turn);
						continue;
					}
					break;
				case DOWN:
					if (!IsCollision(curShape, turn, Cursor.X, Cursor.Y + 2)) {
						deletePrevBlock();
						deleteBlock();
						GotoXY(Cursor.X, Cursor.Y + 2);
						addBlock(curShape, turn);
						previewBlock(curShape, turn);
						continue;
					}
					break;
				}
			}
		}
		Sleep(gameLevel);
		deleteBlock(curShape, turn);

		//바닥과 닿았는지, 현재 좌표에서 +1 한, y값은 IsCollision 검사후 바닥과 다았으면 bockFixed() 수행
		if (!IsCollision(curShape, turn, Cursor.X, Cursor.Y + 1)) ++Cursor.Y;
		else blockFixed(curShape, turn);

		//게임 종료 체크
		if (IsOverHeight()) {
			EndGameFrame(); return;
		}
	}
}
