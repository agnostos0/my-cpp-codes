#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
class Student{
       public:
    int marks;
    string name;
 
    Student(int m,string n){
      marks = m;
      name = n;}
    bool operator < (const Student &s) const{
        return this->marks < s.marks;
    }
    void getdetails(){
        cout<<marks;
        cout<<name<<",";
    }
};
int main(){
    priority_queue<Student> ss;
    ss.push(Student(90,"Rahul"));
    ss.push(Student(85,"Rohan"));
    ss.push(Student(95,"Rahul"));
    while(!ss.empty()){
  
        cout<<ss.top().marks<<" ";
        cout<<ss.top().name;
        cout<<",";
        ss.pop();

    }
}