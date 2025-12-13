#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee:public Worker
{
public:
    Employee(int id, string name, int did);
    virtual void showInfo();
    virtual string getDeptName();
};

#endif // EMPLOYEE_H