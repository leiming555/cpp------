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
        cout<<"FileIsEmpty"<<endl;
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
         cout<<"FileIsEmpty"<<endl;
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
    cout<<"  "<<num<<" "<<endl;
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
    cout<<"design by leiming"<<endl;
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
        cout<<"cin the number you want add"<<endl;
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

                cout<<" put "<<i+1<<"id"<<endl;
                cin>>id;
                cout<<" put "<<i+1<<"name"<<endl;
                cin>>name;
                cout<<" put "<<i+1<<"did"<<endl;
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
                    cout<<"error"<<endl;
                    break;
                }
                newSpace[this->m_EmpNum+i]=worker;

            }
            delete []this->m_EmpArray;
            this->m_EmpArray=newSpace;
            this->m_EmpNum+=addNum;
            this->m_FileIsEmpty=false;
            cout<<"has add"<<addNum<<" "<<endl;
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
        cout<<"FileIsEmpty"<<endl;
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
        cout<<"FileIsEmpty"<<endl;
    }
    else
    {
        cout<<"cin id "<<endl;
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
            cout<<"ok"<<endl;
        }
        else
        {
            cout<<"error"<<endl;
        }
    }
}

void WorkerManager::modify_Emp()
{
    
  
    
    
}



void WorkerManager::find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "FileIsEmpty" << endl;
    }
    else
    {

        cout << "1." << endl;
        cout << "2." << endl;
        cout << "please select your way" << endl;   
        
        int select = 0;
        cin >> select;
        switch (select)
        {
        case 1:
            {
                cout << "  " << endl;
                int id;
                cin >> id;
                int index = this->IsExist(id);
                if (index != -1)
                {
                    // cout << "���" << this->m_EmpArray[i]->m_Id 
                    //      << " ����" << this->m_EmpArray[i]->m_Name 
                    //      << " ���ű��" << this->m_EmpArray[i]->m_DeptId << endl;
                }
                else
                {
                    cout <<   " " << endl;
                }
                break;
            }
        case 2:
            {
                cout << "  " << endl;
                string name;
                cin >> name;
                bool flag = false;
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    if (this->m_EmpArray[i]->m_Name == name)
                    {
                        cout << "  " << this->m_EmpArray[i]->m_Id 
                             << "  " << this->m_EmpArray[i]->m_Name 
                             << "  " << this->m_EmpArray[i]->m_DeptId << endl;
                        flag = true;
                    }
                }
                if (!flag)
                {
                    cout << "  " << endl;
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