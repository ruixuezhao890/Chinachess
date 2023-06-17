/**
*********************************************************************
*********
* @project_name :Chess
* @file : chess.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/6/17 
*********************************************************************
*********
*/
//

#include "chess.h"

int chess::getid() {
    return this->id;
}

void chess::setid(int set) {
    if(set<14)
    {
        this->id=set;
    }
}

void chess::setType(int set) {
    this->type=set;
}

int chess::gettype() {
    return this->type;
}

void chess::setXandY(short x, short y) {
    this->x=x;
    this->y=y;
}

short chess::getX() {
    return this->x;
}

short chess::getY() {
    return this->y;
}

void chess::setIsriver(bool setbool) {
    this->Isriver=setbool;
}

bool chess::getIsriver() {
    return this->Isriver;
}



