#include <iostream>
#include "easyx.h"
#include "Myboard.h"
int main() {
    MyBoard myBoard;
#if TEST
    myBoard.TestPrint();
#endif
    myBoard.drawChess();
    BeginBatchDraw();//Ë«»º³å·ÀÖ¹ÉÁÆÁ
    while (1){
        myBoard.drawChess();
        FlushBatchDraw();
        myBoard.mouseEvent();
    }
    EndBatchDraw();


   getchar();
    closegraph();
    return 0;
}




