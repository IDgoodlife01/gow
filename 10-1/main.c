#include  "Blocks.h"
#include "Controller.h"
#include "Screen.h"
#include "ConsoleCursor.h"

void main() {
	CursorView(false);
	system(" mode con cols = 76 lines = 28 | title â�� �ǹ� ������Ʈ _ ��Ʈ���� �ǽ�");

	/*
	�Ʒ� �� PlaySound �޼��� ��.Hay ���� ���� �� ��� ���� �ִ� �Լ� �Դϴ�.
	* Controller.h ��� ���� �� include mmsystem.h ��� ���� �� ����.wav ���� �� ��� ��Ű�µ�,
	*���� �� ��� �� ��� �ش� ��� �� Controller.h �� BGM �� ��� �� ���ڿ� �� ���� �ϸ� �˴ϴ� .
	* ���� �Ʒ� PlaySound �ּ� ����
	* ���� �� ���ڱ� �� ���� �� ���� �ð� �� ���� ���� ���� �ʽ��ϴ� .
	*/

	// PlaySound ( TEXT ( BGM ) , NULL , SND_FILENAME | SND_ASYNC | SND_LOOP ) ; 
	while (true) {
		GameTitle();
		GameProcess();
	}
}

