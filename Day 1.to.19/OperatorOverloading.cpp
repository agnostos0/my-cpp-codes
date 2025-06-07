#include<iostream>
using namespace std;
class COMPLEX{
    int real,imag;
    public:
   COMPLEX (int real,int imag){
    this->real = real;
   this->imag = imag;


}

    void img()
    {
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
    void operator+ (COMPLEX &c){
        cout<<this->real + c.real<<"+"<<this->imag + c.imag<<"i"<<endl;
     COMPLEX c3(this->real + c.real,this->imag + c.imag);
     
    }
};
int main()
{   
    COMPLEX c1(3,4);
   COMPLEX c2(4,5);
   c1.img();
   c2.img();
   c1.operator+(c2);
   
   return 0;
}
