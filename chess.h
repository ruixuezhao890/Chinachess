/**
*********************************************************************
*********
* @project_name :Chess
* @file : chess.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/6/17 
*********************************************************************
*********
*/
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H
typedef unsigned long int TYPE;
/*enum Pieces //棋子
{
    NONE = -1,
    車, 馬, 象, 士, 将, 砲, 卒,
    俥, 马, 相, 仕, 帥, 炮, 兵,
    BEGIN, END,
};*/
class chess{
//    friend class Myboard;
private:
    int id; //棋子名称
    TYPE type;//棋子类型 黑？红？

    short x;    //坐标x
    short y;    //坐标y
    bool Isriver;//是否过河

public:
     int getid();
     void setid(int set);
     void setType(int set);
     int gettype();
     void setXandY(short x,short y);
     short getX();
     short getY();
     void setIsriver(bool setbool);
     bool getIsriver();


};
#endif //CHESS_CHESS_H



