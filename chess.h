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
/*enum Pieces //����
{
    NONE = -1,
    ܇, �R, ��, ʿ, ��, �h, ��,
    �e, ��, ��, ��, ��, ��, ��,
    BEGIN, END,
};*/
class chess{
//    friend class Myboard;
private:
    int id; //��������
    TYPE type;//�������� �ڣ��죿

    short x;    //����x
    short y;    //����y
    bool Isriver;//�Ƿ����

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



