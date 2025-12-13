#include"workerManager.h"
#include"worker.h"

int WorkerManager::get_EmpNum()
{   
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int num=0;
    while(ifs>>id&&ifs>>name&&ifs>>dId)
    {
        num++;
    }
   return num;

    return this->m_EmpNum;
}

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    if(!ifs.is_open())
    {
        cout<<"文件不存在"<<endl;
        this->m_FileIsEmpty=true;
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        ifs.close();
        return;
    }

    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
        this->m_FileIsEmpty=true;
         cout<<"文件为空"<<endl;
        this->m_FileIsEmpty=true;
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        ifs.close();
        return;
    }
    else
    {
        this->m_FileIsEmpty=false;
    }
    int num=this->get_EmpNum();
    cout<<"文件中共有"<<num<<"名职工"<<endl;
    this->m_EmpNum=num;

    this->m_EmpArray=new Worker*[this->m_EmpNum];
    this->init_Emp();
}
void WorkerManager::show_Menu()
{

    cout<<"menu"<<endl;
    cout<<"0.exit"<<endl;
    cout<<"1.add"<<endl;
    cout<<"2.show"<<endl;
    cout<<"3.-"<<endl;
    cout<<"4.re"<<endl;
    cout<<"5.find"<<endl;
    cout<<"6.pai"<<endl;
    cout<<"7.clean"<<endl;
    cout<<"design by 雷鸣"<<endl;
    cout<<endl;

}
void WorkerManager::ExitSystem()
{
    cout<<"wlcome back again"<<endl;
    system("pause");
    exit(0);
}

 void WorkerManager::Add_Emp()
    {
        cout<<"输入添加职工数量"<<endl;
        int addNum=0;
        cin>>addNum;

        if(addNum>0)
        {

            int newSize = this->m_EmpNum + addNum;

            Worker **newSpace=new Worker*[newSize];
            if(this->m_EmpArray!=NULL)
            {
                for(int i=0;i<this->m_EmpNum;i++)
                {
                    newSpace[i]=this->m_EmpArray[i];
                }
            }

            for(int i=0;i<addNum;i++)
            {
                int id;
                string name;
                int dId;

                cout<<"请输入第"<<i+1<<"个新职工编号"<<endl;
                cin>>id;
                cout<<"请输入第"<<i+1<<"个新职工姓名"<<endl;
                cin>>name;
                cout<<"请输入第"<<i+1<<"个新职工部门编号"<<endl;
                cin>>dId;

                Worker *worker=NULL;
                if(dId==1)
                {
                    worker=new Employee(id,name,dId);
                }
                else if(dId==2)
                {
                    worker=new Manager(id,name,dId);
                }
                else if(dId==3)
                {
                    worker=new Boss(id,name,dId);
                }
                else
                {
                    cout<<"输入有误，添加失败"<<endl;
                    break;
                }
                newSpace[this->m_EmpNum+i]=worker;

            }
            delete []this->m_EmpArray;
            this->m_EmpArray=newSpace;
            this->m_EmpNum+=addNum;
            this->m_FileIsEmpty=false;
            cout<<"成功添加"<<addNum<<"名新职工"<<endl;
            this->save();
        }
        else{

        }

    }

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);

    for(int i=0;i<this->m_EmpNum;i++)
    {
        ofs<<this->m_EmpArray[i]->m_Id<<" "
           <<this->m_EmpArray[i]->m_Name<<" "
           <<this->m_EmpArray[i]->m_DeptId<<endl;
    }
    ofs.close();

}

void WorkerManager::init_Emp()
{
    cout<<"初始化职工"<<endl;
    if(!this->m_FileIsEmpty)
    {
        ifstream ifs;
        ifs.open(FILENAME,ios::in);

        int id;
        string name;
        int dId;
        int index=0;
        while(ifs>>id&&ifs>>name&&ifs>>dId)
        {
            Worker *worker=NULL;
            if(dId==1)
            {
                worker=new Employee(id,name,dId);
            }
            else if(dId==2)
            {
                worker=new Manager(id,name,dId);
            }
            else if(dId==3)
            {
                worker=new Boss(id,name,dId);
            }
            this->m_EmpArray[index]=worker;
            index++;
        }
        ifs.close();
    }
}

void WorkerManager::show_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或为空"<<endl;
    }
    else
    {
        for(int i=0;i<this->m_EmpNum;i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");

}

int WorkerManager::IsExist(int id)
{
    int index=-1;
    for(int i=0;i<this->m_EmpNum;i++)
    {
        if(this->m_EmpArray[i]->m_Id==id)
        {
            index=i;
            break;
        }
    }
    return index;
}

void WorkerManager::delete_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或为空"<<endl;
    }
    else
    {
        cout<<"请输入要删除的职工编号"<<endl;
        int id;
        cin>>id;
        int index=this->IsExist(id);
        if(index!=-1)
        {
            for(int i=index;i<this->m_EmpNum-1;i++)
            {
                this->m_EmpArray[i]=this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;
            this->save();
            cout<<"删除成功"<<endl;
        }
        else
        {
            cout<<"删除失败，未找到该职工"<<endl;
        }
    }
}

void WorkerManager::modify_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或为空"<<endl;
    }
    else
    {
        cout<<"请输入要修改的职工编号"<<endl;
        int id;
        cin>>id;
        int index=this->IsExist(id);
        if(index!=-1)
        {
            delete this->m_EmpArray[index];

            int newId=0;
            string newName="";
            int newdId=0;
            cout<<"编号"<<this->m_EmpArray[index]->m_Id<<"姓名"<<this->m_EmpArray[index]->m_Name<<"部门编号"<<this->m_EmpArray[index]->m_DeptId<<endl;
            cout<<"请输入新的职工编号"<<endl;
            cin>>newId;
            cout<<"请输入新的职工姓名"<<endl;
            cin>>newName;
            
            cout<<"1.员工"<<endl;
            cout<<"2.经理"<<endl;
            cout<<"3.老板"<<endl;
            cout<<"请输入新的职工部门编号"<<endl;
            int dSelect=0;
            cin>>dSelect;
            Worker *Worker=NULL;
            switch(dSelect)
            {
            case 1:
                Worker = new Employee(newId,newName,newdId);
                break;
            case 2:
                Worker = new Manager(newId,newName,newdId);
                break;
            case 3:
                Worker = new Boss(newId,newName,newdId);
                break;
            default:
                cout<<"输入错误"<<endl;
                break;
            }
            this->m_EmpArray[index]=Worker;
            cout<<"修改成功"<<endl;
            this->save();




        }
        else
        {
            cout<<"修改失败，未找到该职工"<<endl;
        }

    }
    system("pause");
    system("cls");
    
    
}



void WorkerManager::find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        cout << "查找方式" << endl;
        cout << "1.按编号查找" << endl;
        cout << "2.按姓名查找" << endl;
        int select = 0;
        cin >> select;
        switch (select)
        {
        case 1:
            {
                cout << "请输入要查找的编号" << endl;
                int id;
                cin >> id;
                int index = this->IsExist(id);
                if (index != -1)
                {
                    cout << "编号" << this->m_EmpArray[i]->m_Id 
                         << " 姓名" << this->m_EmpArray[i]->m_Name 
                         << " 部门编号" << this->m_EmpArray[i]->m_DeptId << endl;
                }
                else
                {
                    cout << "未找到该职工" << endl;
                }
                break;
            }
        case 2:
            {
                cout << "请输入要查找的姓名" << endl;
                string name;
                cin >> name;
                bool flag = false;
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    if (this->m_EmpArray[i]->m_Name == name)
                    {
                        cout << "编号" << this->m_EmpArray[i]->m_Id 
                             << " 姓名" << this->m_EmpArray[i]->m_Name 
                             << " 部门编号" << this->m_EmpArray[i]->m_DeptId << endl;
                        flag = true;
                    }
                }
                if (!flag)
                {
                    cout << "未找到该职工" << endl;
                }
                break;
            }
        } // end of switch
    } // end of else
}  // end of function
       
WorkerManager::~WorkerManager()
{
    if(this->m_EmpArray!=NULL)
    {
        delete []this->m_EmpArray;
        this->m_EmpArray=NULL;
    }

}