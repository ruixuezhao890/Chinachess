/**
*********************************************************************
*********
* @project_name :Chess
* @file : Myboard.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/6/16 
*********************************************************************
*********
*/
//


#include <graphics.h>
#include "Myboard.h"

MyBoard::MyBoard() {

    initgraph(740,820,1);
    this->BoardInit();
    this->ChessInit();
}
//��������
void MyBoard::drawBoard()
{
    setbkcolor(RGB(252, 215, 162));
    cleardevice();
    setlinecolor(BLACK);
    setlinestyle(PS_SOLID, 2);
    for (int i = 0; i < 10; i++)
    {
        //������
        line(INTERVAL, i*CHESS_GRID_SIZE + INTERVAL, 8 * CHESS_GRID_SIZE + INTERVAL, i*CHESS_GRID_SIZE + INTERVAL);
        //������
        if (i < 9)
        {
            line(i*CHESS_GRID_SIZE + INTERVAL, INTERVAL, i*CHESS_GRID_SIZE + INTERVAL, 9 * CHESS_GRID_SIZE + INTERVAL);
        }
    }
    rectangle(INTERVAL - 5, INTERVAL - 5, 8 * CHESS_GRID_SIZE + INTERVAL+5, 5+9 * CHESS_GRID_SIZE + INTERVAL);
    //���Ӻ�����ʾ
    setfillcolor(RGB(252, 215, 162));
    fillrectangle(INTERVAL, 4 * CHESS_GRID_SIZE + INTERVAL, 8 * CHESS_GRID_SIZE + INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL);
    //��ʾ����
    char river[30] = "����        ����";
    settextstyle(50, 0, "����");
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    outtextxy(INTERVAL+100, 4 * CHESS_GRID_SIZE + INTERVAL+10, river);
    //���Ź���
    //������
    line(3 * CHESS_GRID_SIZE + INTERVAL, INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL, 2 * CHESS_GRID_SIZE + INTERVAL);
    line(3 * CHESS_GRID_SIZE + INTERVAL, 2 * CHESS_GRID_SIZE + INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL, INTERVAL);
    //������
    line(3 * CHESS_GRID_SIZE + INTERVAL, 7 * CHESS_GRID_SIZE + INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL, 9 * CHESS_GRID_SIZE + INTERVAL);
    line(3 * CHESS_GRID_SIZE + INTERVAL, 9 * CHESS_GRID_SIZE+INTERVAL,5*CHESS_GRID_SIZE+INTERVAL,7*CHESS_GRID_SIZE+INTERVAL);
}
//���������Լ������������ʼ��
void MyBoard::BoardInit() {

    this->drawBoard();

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            map[i][j].setid(-1);
        }
    }

}
//���ӳ�ʼ�� ��ʼ����������ӱ�������
void MyBoard::ChessInit() {
    for (int i = 0; i < ROW; ++i) {
        size_t temp=0;
        for (int j = 0; j < COL; ++j) {
            map[i][j].setType(-2);
            if (i<=4){//��ʱΪ����

                if (i==0){//���õ�һ�е�����
                    //0 1 2 3 4 3 2 1 0
                    if (j<=4){
                        temp=j;
                    }
                    else{
                        temp=4-(j-4);
                    }
                    map[i][j].setid(this->Blackchessid[temp]);
                }
                if (i==2&&(j==1||j==7))//��
                {
                    map[i][j].setid(this->Blackchessid[5]);
                }
                if (i == 3 && j% 2 == 0)//��
                {
                    map[i][j].setid(this->Blackchessid[6]);
                }
                if (  map[i][j].getid()!=-1)
                {
                    map[i][j].setType(BLACK);
                }
            }
            else{
//                map[i][j].setType(RED);
                if (i==9){//���õ�һ�е�����
                    //0 1 2 3 4 3 2 1 0
                    if (j<=4){
                        temp=j;
                    }
                    else{
                        temp=4-(j-4);
                    }
                    map[i][j].setid(this->REDchessid[temp]);
                }
                if (i==7&&(j==1||j==7))//��
                {
                    map[i][j].setid(this->REDchessid[5]);
                }
                if (i == 6 && j% 2 == 0)//��
                {
                    map[i][j].setid(this->REDchessid[6]);
                }
                if (  map[i][j].getid()!=-1)
                {
                    map[i][j].setType(RED);
                }
            }
           map[i][j].setIsriver(false);
            map[i][j].setXandY((j*CHESS_GRID_SIZE+INTERVAL),(i*CHESS_GRID_SIZE+INTERVAL));

        }
    }

}
//��ӡ����
void MyBoard::TestPrint() {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            std::cout<<this->map[i][j].getid();
            std::cout<<"  ";
        }
        std::cout<<std::endl;
    }

}
//������
void MyBoard::drawChess() {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (map[i][j].getid()!=-1)
            {
                setlinecolor(map[i][j].gettype());
                fillcircle(map[i][j].getX(),map[i][j].getY(),DrawRadiu);
                fillcircle(map[i][j].getX(),map[i][j].getY(),DrawRadiu-5);
                settextcolor(map[i][j].gettype());
                settextstyle(30, 0, "����");
                outtextxy((map[i][j].getX()-15),(map[i][j].getY()-15),this->ChessName[map[i][j].getid()]);
            }

        }
    }
}
//�ж�����Ƿ���
void MyBoard::mouseEvent() {
    ExMessage message;
    if(peekmessage(&message,EM_MOUSE))
    {
        if (message.message==WM_LBUTTONDOWN)//����������
        {
            int col=(message.x-INTERVAL)/CHESS_GRID_SIZE;
            int row=(message.y-INTERVAL)/CHESS_GRID_SIZE;
            //У׼
            if (message.x>map[row][col].getX()+30&&message.y<map[row][col].getY()+30)
            {
                col++;
            }
            if (message.x<map[row][col].getX()+30&&message.y>map[row][col].getY()+30)
            {
                row++;
            }
            if (message.x>map[row][col].getX()+30&&message.y>map[row][col].getY()+30)
            {
                col++;
                row++;
            }
#if TEST
            std::cout<<row<<"   "<<col<<std::endl;
#endif
            if (state.State==Begin){
                state.begr=row;
                state.begc=col;
                state.State=END;

            }
            else if (state.State==END){
                state.endr=row;
                state.endc=col;
                state.State=Begin;
            }
            this->ChessMove();
        }
    }




}
int MyBoard::HorseNearhasChess(struct state* state1)
{
    int cnt=0;
    if (state1->begr-state1->endr==2){
        if (map[state1->begr-1][state1->begc].getid()!=-1)
        {
          cnt=1;
        }
    }
    else if (state1->endr-state1->begr==2){
        if (map[state1->begr+1][state1->begc].getid()!=-1)
        {
            cnt=1;
        }
    }
    else if (state1->begc-state1->endc==2){
        if (map[state1->begr][state1->begc-1].getid()!=-1)
        {
            cnt=1;
        }
    }
    else if (state1->endc-state1->begc==2){
        if (map[state1->begr][state1->begc+1].getid()!=-1)
        {
            cnt=1;
        }
    }
     if (this->map[state1->begr][state1->begc].gettype()==this->map[state1->endr][state1->endc].gettype())
    {

//#if TEST
//        std::cout<<this->map[state1->begr][state1->begc].gettype()<<"   "<<this->map[state1->endr][state1->endc].gettype()<<std::endl;
//#endif
        cnt=1;
    }
//#if TEST
//    std::cout<<this->map[state1->begr][state1->begc].gettype()<<"   "<<this->map[state1->endr][state1->endc].gettype()<<std::endl;
//#endif
    std::cout<<"cnt:"<<cnt<<std::endl;
    return cnt;


}
int MyBoard::IshasChess(struct state* state1)
{
#if TEST
   this->TestPrint();
#endif
    int cnt=0;
    if (state1->begc!=state1->endc&&state1->begr!=state1->endr)//�ж��ƶ�ǰ���������ƶ����Ƿ��غ� ���غ���ֱ�ӽ���
        return 0;
        if (state1->begc==state1->endc) {//�ж����Ƿ����
//            temp=state1->begr>state1->endr?state1->begr-state1->endr:state1->endr-state1->begr;
            if (state1->begr > state1->endr) {  //�����ʼ������ڽ������� ��Ӵ�������С������������Ƿ�������
                                                //���� ��ʼ����9 0 ��������7 0 ���в��� �ӵڰ��п�ʼ�����������в鿴�Ƿ�������
                for (int i = state1->begr; i > state1->endr; i--) {
                    if (this->map[i - 1][state1->endc].getid() != -1) {
                        cnt++;
                    }
                }
            }else//�����ʼ����С�ڽ������� ���С��������������������Ƿ�������
            {
                for (int i = state1->begr; i < state1->endr; i++) {
                    if (this->map[i + 1][state1->endc].getid() != -1) {
                        cnt++;
                    }
                }
            }
        }

        else{//�ж������
            if (state1->begc>state1->endc) {
                for (int i = state1->begc; i > state1->endc; i--) {
                    if (this->map[state1->endr][i-1].getid() != -1) {
                        cnt++;
                    }
                }
            }else
            {
                for (int i = state1->begc; i < state1->endc; i++) {
                    if (this->map[state1->endr][i+1].getid() != -1) {
                        cnt++;
                    }
                }
            }
    }
    if (this->map[state1->begr][state1->begc].gettype()==this->map[state1->endr][state1->endc].gettype())
    {
        cnt=4;
    }
        std::cout<<"cnt:"<<cnt<<std::endl;
    return cnt;

}
int MyBoard::ElephantNearhasChess(struct state* state1){
    int rnt=0;
    if(map[(state.begr+state.endr)/2]
          [(state.begc+state.endc)/2].getid()!=-1)
    {
        rnt=1;
    }
    this->IsRiver(state1);
    if (map[state1->begr][state1->begc].getIsriver()== true){
        rnt=1;
    }
    if (this->map[state1->begr][state1->begc].gettype()==this->map[state1->endr][state1->endc].gettype())
    {
        rnt=1;
    }
    return rnt;
}
void   MyBoard::IsRiver(struct state* state1)
{
    if (map[state1->begr][state1->begc].gettype()==RED){
        if (state1->endr<=4){
            map[state1->begr][state1->begc].setIsriver(true);
        }
        else{
            map[state1->begr][state1->begc].setIsriver(false);
        }
    }
    else{
        if (state1->endr>=5){
            map[state1->begr][state1->begc].setIsriver(true);
        }
        else{
            map[state1->begr][state1->begc].setIsriver(false);
        }
    }
}

//�����ƶ�
void MyBoard::ChessMove() {
    this->TestPrint();
    this->PrintChess();
    int judeR=0;
    int judeC=0;
    bool canMove= false;
    if (!((state.begr==state.endr)&&(state.begc==state.endc))
    &&state.endr!=-1&&state.endc!=-1
    &&map[state.begr][state.begc].getid()!=-1){

        switch (map[state.begr][state.begc].getid()) {
            case 0://��
            case 7:
                if (state.begr==state.endr||state.begc==state.endc){
                    if (this->IshasChess(&this->state)==0||
                    this->IshasChess(&this->state)==1&&map[state.endr][state.endc].gettype()!=map[state.begr][state.begc].gettype())
                    canMove= true;
                    IsRiver(&state);
                }
                break;
            case 1://��
            case 8:
                if (state.begr!=state.endr&&state.begc!=state.endc) {
                    if (abs(state.begr-state.endr)==2&&abs(state.begc-state.endc)==1
                    ||abs(state.begr-state.endr)==1&&abs(state.begc-state.endc)==2) {
                        if (this->HorseNearhasChess(&this->state) == 0) {
                            canMove = true;
                            IsRiver(&state);
                        }
                    }
                }
                break;
            case 2://��
            case 9:
                if (state.begr!=state.endr&&state.begc!=state.endc) {
                    if (abs(state.begr-state.endr)==2&&abs(state.begc-state.endc)==2){
                        if (this->ElephantNearhasChess(&state)==0){
                            canMove = true;
                        }

                    }

                }
                break;
            case 3://��
            case 10:
                if (state.begr!=state.endr&&state.begc!=state.endc) {

                }
                break;
            case 4://˧
            case 11:
                break;
            case 5://��
            case 12:
                if (state.begr==state.endr||state.begc==state.endc){
                    if (this->IshasChess(&this->state)==0||this->IshasChess(&this->state)==2||
                            (this->IshasChess(&this->state)==2&&map[state.endr][state.endc].gettype()!=map[state.begr][state.begc].gettype()))
                        canMove= true;
                }
                break;
            case 6://��
            case 13:
                break;

        }

        if (canMove){
            map[state.endr][state.endc].setid(map[state.begr][state.begc].getid()) ;
            map[state.begr][state.begc].setid(-1);
            map[state.endr][state.endc].setIsriver(map[state.begr][state.begc].getIsriver()) ;
            //map[state.begr][state.begc].setIsriver(map[state.begr][state.begc].getIsriver());
//            if (map[state.begr][state.begc].getIsriver()== false)
            int temp=map[state.endr][state.endc].gettype();
            map[state.endr][state.endc].setType(map[state.begr][state.begc].gettype()) ;
            map[state.begr][state.begc].setType(temp);
            this->drawBoard();


        }
    }
}

void MyBoard::PrintChess() {
    std::cout<<"getid:"<<this->map[state.begr][state.begc].getid()<<std::endl;
    std::cout<<"gettype:"<<this->map[state.begr][state.begc].gettype()<<std::endl;
    std::cout<<"getIsriver:"<<this->map[state.begr][state.begc].getIsriver()<<std::endl;
    //std::cout<<"getid:"<<this->map[state.begr][state.begc].getid()<<std::endl;
}



