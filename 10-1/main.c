#include  "Blocks.h"
#include "Controller.h"
#include "Screen.h"
#include "ConsoleCursor.h"

void main() {
	CursorView(false);
	system(" mode con cols = 76 lines = 28 | title 창의 실무 프로젝트 _ 테트리스 실습");

	/*
	아래 의 PlaySound 메서드 는.Hay 음악 파일 을 재생 시켜 주는 함수 입니다.
	* Controller.h 헤더 파일 에 include mmsystem.h 헤더 파일 을 통해.wav 음악 을 출력 시키는데,
	*음악 을 출력 할 경우 해당 경로 를 Controller.h 에 BGM 의 경로 를 문자열 로 지정 하면 됩니다 .
	* 그후 아래 PlaySound 주석 해제
	* 음원 은 저자권 의 문제 로 수업 시간 에 따로 제공 되지 않습니다 .
	*/

	// PlaySound ( TEXT ( BGM ) , NULL , SND_FILENAME | SND_ASYNC | SND_LOOP ) ; 
	while (true) {
		GameTitle();
		GameProcess();
	}
}

