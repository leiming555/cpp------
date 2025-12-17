#include"manager.h"
Manager::Manager(int id,string name,int dId)
{
    this->m_Id=id;
    this->m_Name=name;
    this->m_DeptId=dId;
}
void Manager::showInfo()
{
    cout<<"ְid  "<<this->m_Id;
    cout<<"\tְname  "<<this->m_Name;
    cout<<"\tDeptName "<<this->getDeptName()<<endl;
    cout<<"\t"<<endl;
}
string Manager::getDeptName()
{
    return string("manager");
}