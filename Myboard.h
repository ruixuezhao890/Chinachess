/**
*********************************************************************
*********
* @project_name :Chess
* @file : Myboard.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/6/16 
*********************************************************************
*********
*/
//

#ifndef CHESS_MYBOARD_H
#define CHESS_MYBOARD_H
#include "easyx.h"
#include "iostream"
#include "chess.h"
#define ROW 10
#define COL 9
#define INTERVAL 50  //前面的间隔
#define CHESS_GRID_SIZE 70  //格子宽度
#define DrawRadiu 30
#define TEST 1
enum flag{
    END=0,
    Begin
};
class MyBoard{
public:
    MyBoard();
    void BoardInit();
    void ChessInit();
    void drawChess();
    void TestPrint();
    void mouseEvent();
    void ChessMove();
private:
    IMAGE image;

//绘制时转化成字符串
    int Blackchessid[7]={0,1,2,3,4,5,6,};
    int REDchessid[7]={7,8,9,10,11,12,13,};
    const char* ChessName[14] = { "車","馬","象","士","将","砲","卒","俥", "马", "相", "仕", "帥", "炮", "兵" };
    chess map[ROW][COL];
    struct state{
        int begr;
        int begc;
        int endr;
        int endc;
        int State;
    }state={-1,-1,-1,-1,Begin};
};
#endif //CHESS_MYBOARD_H



