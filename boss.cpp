#include "boss.h"
    Boss::Boss(int id ,string name,int did)
    {
        this->m_Id=id;
        this->m_Name=name;
        this->m_DeptId=did;
    }
    void Boss::showInfo()
    {
      cout<<"ְid"<<this->m_Id;
      cout<<"\tְname"<<this->m_Name;
      cout<<"\tDeptName"<<this->getDeptName()<<endl;
      cout<<"\t"<<endl;
    }
    string Boss::getDeptName()
    {
      return string("Boss");
    }