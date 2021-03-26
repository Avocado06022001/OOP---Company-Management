#include<iostream>
using namespace std;
#include<vector>
class Date{
private:
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year){
        this->day=day;
        this->month=month;
        this->year=year;
    }
};

class Employee{
private:
    string Id;
    string name;
    Date birthday;
    Date startday;
    string address;
    double rate;
    double salary;
public:
    Employee(string Id, string name, int daybirth, int monthbirth, int yearbirth, int daystart, int monthstart, int yearstart, string address, double rate, double salary)
    : birthday(daybirth, monthbirth, yearbirth), startday(daystart, monthstart, yearstart){
        this->Id=Id;
        this->name=name;
        this->birthday=birthday;
        this->startday=startday;
        this->address=address;
        this->rate=rate;
        this->salary=salary;
    }
    void setSalary(double salary){this->salary=salary;}
    double getSalary(){return salary;}
    void setRate(double rate){this->salary=salary;}
    double getRate(){return rate;}
    virtual double computeSalary()=0;
};

class Manager:public Employee{
public:
    Manager(string Id, string name, int daybirth, int monthbirth, int yearbirth, int daystart, int monthstart, int yearstart, string address, double rate, double salary)
    : Employee(Id,name,daybirth,monthbirth,yearbirth,daystart,monthstart,yearstart,address,rate,salary){}
    double computeSalary(){
        return Employee::getSalary()*Employee::getRate();
    }
};

class Programmer:public Employee{
private:
    double overtime;
public:
    Programmer(string Id, string name, int daybirth, int monthbirth, int yearbirth, int daystart, int monthstart, int yearstart, string address, double rate, double salary, double overtime)
    : Employee(Id,name,daybirth,monthbirth,yearbirth,daystart,monthstart,yearstart,address,rate,salary){
        this->overtime=overtime;
    }
    double computeSalary(){
        return Employee::getSalary()*Employee::getRate()+overtime;
    }
};

class Designer:public Employee{
private:
    double bonus;
public:
    Designer(string Id, string name, int daybirth, int monthbirth, int yearbirth, int daystart, int monthstart, int yearstart, string address, double rate, double salary, double bonus)
    : Employee(Id,name,daybirth,monthbirth,yearbirth,daystart,monthstart,yearstart,address,rate,salary){
        this->bonus=bonus;
    }
    double computeSalary(){
        return Employee::getSalary()*Employee::getRate()+bonus;
    }
};

class Tester:public Employee{
private:
    int Error;
public:
    Tester(string Id, string name, int daybirth, int monthbirth, int yearbirth, int daystart, int monthstart, int yearstart, string address, double rate, double salary, int Error)
    : Employee(Id,name,daybirth,monthbirth,yearbirth,daystart,monthstart,yearstart,address,rate,salary){
        this->Error=Error;
    }
    double computeSalary(){
        return Employee::getSalary()*Employee::getRate()+200000*Error;
    }
};

class Company{
private:
    vector<Employee*>list;
public:
    void addEmployee(Employee* e){
        list.push_back(e);
    }
    double computeSum(){
        double sum=0;
        for (int i=0; i<list.size(); i++){
            sum+=list[i]->computeSalary();
        }
        return sum;
    }
};

class subOrdinate{
private:
    vector<Employee*>list;
public:
    void addSub(Employee* e){
        list.push_back(e);
    }
    int numberofSub(){
        return list.size();
    }
};

int main(){
    Company c;
    Employee* manager=new Manager ("16128", "Tai Nguyen", 6, 2, 2001, 8, 3, 2002, "Au Co", 0.8, 200000);
    Employee* programmer=new Programmer("15656", "Huy Nguyen", 9, 3, 2001, 12, 6, 2011, "Le Hong Phong", 0.8, 300000, 10000);
    Employee* designer=new Designer("14167", "Long Le", 15, 6, 2001, 24, 1, 2018, "Nguyen Thi Minh Khai", 0.9, 200000, 30000);
    Employee* tester=new Tester("13245", "Trung Hua", 20, 5, 2002, 12, 3, 2019, "Hong Bang", 0.8, 250000, 12);
    c.addEmployee(manager);
    c.addEmployee(programmer);
    c.addEmployee(designer);
    c.addEmployee(tester);
    cout<<c.computeSum()<<endl;
    subOrdinate s;
    s.addSub(manager);
    s.addSub(tester);
    s.addSub(designer);
    cout<<s.numberofSub();

}
