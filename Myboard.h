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
#include "math.h"
#define ROW 10
#define COL 9
#define INTERVAL 50  //ǰ��ļ��
#define CHESS_GRID_SIZE 70  //���ӿ��
#define DrawRadiu 30
#define TEST 1
enum flag{
    END=0,
    Begin
};
class MyBoard{
public:
    MyBoard();
    void drawBoard();
    void BoardInit();
    void ChessInit();
    void drawChess();
    void TestPrint();
    void PrintChess();
    void mouseEvent();
    void ChessMove();
private:
    IMAGE image;

//����ʱת�����ַ���
    int Blackchessid[7]={0,1,2,3,4,5,6,};
    int REDchessid[7]={7,8,9,10,11,12,13,};
    const char* ChessName[14] = { "܇","�R","��","ʿ","��","�h","��","�e", "��", "��", "��", "��", "��", "��" };
    chess map[ROW][COL];
    struct state{
        int begr;
        int begc;
        int endr;
        int endc;
        int State;
    }state={-1,-1,-1,-1,Begin};
public:
    int IshasChess(struct state* state1);
    int HorseNearhasChess(struct state* state1);
    int ElephantNearhasChess(struct state* state1);
    void  IsRiver(struct state* state1);
};
#endif //CHESS_MYBOARD_H



