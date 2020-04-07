#include <iostream>
using namespace std;
/* 
静态变量只存在类的一个实例里，当有类多个对象时，所有
对象的值都一样 ，static关键字可以作用在变量或者函数上
静态变量不属于特定的对象，它属于特定的类
 */
class myClass
{
private:
protected:
public:
    int i_;
    float j_;
    static int m_;
    myClass();
    ~myClass();
    void write();
    void read();
};

myClass::myClass()
    : i_(10),
      j_(1.1)
{
    cout << "***构造函数调用" << endl;
}

myClass::~myClass()
{
}

// 定义成员函数
void myClass::write()
{
    cout << "my member data i_=" << i_ << endl;
    cout << "my member data j_=" << j_ << endl;
    cout << "my member data m_=" << m_ << endl;// 成员函数对类的所有变量有访问权
}

inline void myClass::read()
{
    cout<<"input i_:";
    cin>>i_;
}

// 定义静态变量
// 静态变量只能在类之外定义
int myClass::m_ = 11;

int main()
{
    myClass myClassObject;
    myClass myClassObject2;
    myClass *generalPntr;
    generalPntr = &myClassObject;
    cout << "myClassObject.m_:" << myClassObject.m_ << endl;
    cout << "myClassObject2.m_:" << myClassObject2.m_ << endl;
    //使用myClassObject.m_=30有同样的效果，但是为了可读性，不要这样做
    myClass::m_ = 30;
    cout << "m_ has changed" << endl;
    cout << "myClassObject.m_:" << myClassObject.m_ << endl;
    cout << "myClassObject2.m_:" << myClassObject2.m_ << endl;
    cout<<"***成员函数test"<<endl;
    myClassObject.j_ = 6.6;
    myClassObject2.i_ = 2;
    myClassObject.write();
    myClassObject2.write();
    generalPntr->write();//指针使用"->"
    cout<<"***inline函数test"<<endl;
    myClassObject.read();
    myClassObject.write();
    return 0;
}
