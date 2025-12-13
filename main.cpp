#include <iostream>
using namespace std;
#include "workerManager.h"
#include "employee.h"
#include "worker.h"
#include "manager.h"
#include "boss.h"

int main()
{
    Worker *worker=NULL;
    worker =new Employee(1,"张三",1);
    worker->showInfo();
    delete worker;

    worker =new Manager(2,"张三",2);
    worker->showInfo();
    delete worker;

    worker =new Boss(2,"adwd",2);
    worker->showInfo();
    delete worker;

    WorkerManager wm;
    int choice=0;
    while (true)
    {
        wm.show_Menu();
        cout<<"please cin:  "<<endl;
        cin>>choice;

        switch (choice)
        {   
        case 0:
           wm.ExitSystem();
            
            break;
        case 1:
            wm.Add_Emp();
            break;

        case 2:
            wm.show_Emp();
            break;
        case 3:
            wm.delete_Emp();
            break;
            
        case 4:
            wm.modify_Emp();
            break;
        case 5:
            wm.find_Emp();
            break;
        default:
            system("cls");
            break;
        }
    }
    
    

    system("pause");
    return 0;
}