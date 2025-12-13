#pragma once
#include<iostream>
#include<string>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
    WorkerManager();
    void show_Menu();


    void ExitSystem();
    int m_EmpNum;
    Worker **m_EmpArray;
    void Add_Emp();
    void save();
    bool m_FileIsEmpty;
    int get_EmpNum();
    void init_Emp();
    void show_Emp();
    void delete_Emp();
    void modify_Emp();
    int IsExist(int id);
    void find_Emp();

    ~WorkerManager();
};