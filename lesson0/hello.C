#include <iostream>
using namespace std;
// 声明一个类myClass
class myClass
{
private:
protected:
public:
    int i_;
    float j_;
    myClass();  // 构造函数
    ~myClass(); // 析构函数
};
// 定义构造函数，为了表明它属于什么类，使用myClass::声明
myClass::myClass()
    : i_(20), // 按顺序定义变量，这里用,分隔
      j_(4.5)
{
    cout << "构造函数被调用了" << endl;
    cout << "i_=" << i_ << endl;
    cout << "j_=" << j_ << endl;
}
// 定义析构函数（啥也没干）
myClass::~myClass()
{
    cout << "析构函数被调用了" << endl;
}

int main()
{
    // 实例化一个对象
    myClass myClassObject;
    cout << "对象1的i_: " << myClassObject.i_ << endl;
    cout << "对象1的j_: " << myClassObject.j_ << endl;
    myClass myClassObject2;
    cout << "对象2的i_: " << myClassObject2.i_ << endl;
    myClassObject2.i_ = 30; 
    cout << "对象1的i_依然是: " << myClassObject.i_ << endl;
    cout << "对象2的i_变成了: " << myClassObject2.i_ << endl;
    // myClassObject和my...2离开了作用域(main函数),析构函数起作用
    return 0;
}