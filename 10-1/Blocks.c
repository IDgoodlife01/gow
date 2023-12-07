#include "Blocks.h"
/**
* blocks.h과 소스파일은 테트리스의 7가지 블록에 대해서 회전할 수 있는 4가지 경우를 4차원 배열로 표현
* Blocks 배열
* -첫번째 index [BlockType]에 따라서 블록의 형태를 지정할 수 있습니다.
* -두번째 index [BlockRotate]에 따라서 블록이 회전할 수 있는 4가지 형태를 지정할 수 있습니다.
* -세번째, 4번째 인덱스(4*4) 형태를 출력하면 원하는 블록의 형태를 얻을 수 있습니다.
*
* 숫자 0은 공백
* 숫자 2는 도형을 나타냅니다.
* ->	이때 블록의 표현을 숫자 2로 한 이윤느 테트리스 보드가 표현되는 부분이 숫자 1로 정해서,
*		이 둘을 쉽게 구분하기 위해서 숫자 2로 정의했습니다.
*/
int Blocks[BlockType][BlockRotate][BlockSIZE][BlockSIZE] =
{
	 0, 0, 0, 0      
	,0, 2, 2, 0       //■■
	,0, 2, 2, 0		 //■■
	,0, 0, 0, 0
	,0, 0, 0, 0
	,0, 2, 2, 0
	,0, 2, 2, 0
	,0, 0, 0, 0
	,0, 0, 0, 0
	,0, 2, 2, 0
	,0, 2, 2, 0
	,0, 0, 0, 0
	,0, 0, 0, 0
	,0, 2, 2, 0
	,0, 2, 2, 0
	,0, 0, 0, 0
	
	,0, 0, 0, 0     
	,2, 2, 2, 2		  //■■■■
	,0, 0, 0, 0
	,0, 0, 0, 0
	,0, 0, 2, 0
	,0, 0, 2, 0
	,0, 0, 2, 0
	,0, 0, 2, 0
	,0, 0, 0, 0
	,2, 2, 2, 2
	,0, 0, 0, 0
	,0, 0, 0, 0
	,0, 0, 2, 0
	,0, 0, 2, 0
	,0, 0, 2, 0
	,0, 0, 2, 0
	    
	,0, 0, 0, 0    
	,0, 0, 2, 2       //■■
	,0, 2, 2, 0		//■■
	,0, 0, 0, 0
	,0, 0, 2, 0
	,0, 0, 2, 2
	,0, 0, 0, 2
	,0, 0, 0, 0
	,0, 0, 0, 0
	,0, 0, 2, 2
	,0, 2, 2, 0
	,0, 0, 0, 0
	,0, 0, 2, 0
	,0, 0, 2, 2
	,0, 0, 0, 2
	,0, 0, 0, 0

	,0, 0, 0, 0    
	,0, 2, 2, 0   // ■■
	,0, 0, 2, 2	 //   ■■
	,0, 0, 0, 0
	,0, 0, 0, 2
	,0, 0, 2, 2
	,0, 0, 2, 0
	,0, 0, 0, 0
	,0, 0, 0, 0
	,0, 2, 2, 0
	,0, 0, 2, 2
	,0, 0, 0, 0
	,0, 0, 0, 2
	,0, 0, 2, 2
	,0, 0, 2, 0

	,0, 0, 0, 0
	,0, 0, 0, 0       //■■■
	,0, 2, 2, 2       //■
	,0, 2, 0, 0
	,0, 0, 0, 0
	,0, 0, 2, 0
	,0, 0, 2, 0
	,0, 0, 2, 2
	,0, 0, 0, 0
	,0, 0, 0, 2
	,0, 2, 2, 2
	,0, 0, 0, 0
	,0, 0, 0, 0
	,0, 2, 2, 0
	,0, 0, 2, 0
	,0, 0, 2, 0
	,0, 0, 0, 0

	,0, 0, 0, 0       
	,2, 2, 2, 0        //■■■ 
	,0, 0, 2, 0        //    ■
	,0, 0, 0, 0
	,0, 0, 2, 2
	,0, 0, 2, 0
	,0, 0, 2, 0
	,0, 0, 0, 0
	,0, 2, 0, 0
	,0, 2, 2, 2
	,0, 0, 0, 0
	,0, 0, 0, 0
	,0, 0, 2, 0
	,0, 0, 2, 0
	,0, 2, 2, 0
	,0, 0, 0, 0
	
	,0, 0, 0, 0       
	,0, 2, 2, 2        //■■■ 
	,0, 0, 2, 0	       //  ■ 
	,0, 0, 0, 0
	,0, 0, 2, 0
	,0, 0, 2, 2
	,0, 0, 2, 0
	,0, 0, 0, 0
	,0, 0, 2, 0
	,0, 2, 2, 2
	,0, 0, 0, 0
	,0, 0, 0, 0
	,0, 0, 2, 0
	,0, 2, 2, 0
	,0, 0, 2, 0
	,0, 0, 0, 0
	
};