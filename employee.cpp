#include "employee.h"
  Employee::Employee(int id ,string name,int did)
    {
        this->m_Id=id;
        this->m_Name=name;
        this->m_DeptId=did;
    }
    void Employee::showInfo()
    {
      cout<<"ְid"<<this->m_Id;
      cout<<"\tְname"<<this->m_Name;
      cout<<"\tDeptName"<<this->getDeptName()<<endl;
      cout<<"\t"<<endl;
    }
    string Employee::getDeptName()
    {
      return string("Employee");
    }