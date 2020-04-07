#include <iostream>
using namespace std;
/* 
指针常常和引用混淆，指针拥有被指向对象的地址，而引用则可看成是对引用对象的别称。
指针能被重新分配，而引用则在初始化后不能更改引用对象。
OpenFOAM中指针可以用来在运行时做出不同的选择，例如选择不同的湍流模型 
 */

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
    //myClassObject:(20,4.5) ,myClassObject2:(30,4.5)

    // myClassObjectPntrt通过引用指向了myClassObject
    myClass *myClassObjectPntr = &myClassObject;
    // myClassObjectPntr:(20,4.5)
    cout << "myClassObjectPntr->i_: " << myClassObjectPntr->i_ << endl; // 20
    // 这里使用了构造函数，说明创建了一个新对象，通过new方法
    myClass *myClassPntr = new myClass;
    cout << "myClassPntr->i_: " << myClassPntr->i_ << endl;
    myClassObjectPntr->i_ = 3; //这将改变myClassObject的值
    myClassPntr->i_ = 4;
    cout << "myClassObjectPntr->i_: " << myClassObjectPntr->i_ << endl; //3
    cout << "myClassPntr->i_: " << myClassPntr->i_ << endl;             //4
    // 构建一个myClass类的指针 构建函数未被调用
    myClass *generalPntr;
    // 指向myClassObject
    generalPntr = &myClassObject;
    cout << "generalPntr->i_: " << generalPntr->i_ << endl;
    // 再指向myClassObject2
    generalPntr = &myClassObject2;
    cout << "generalPntr->i_: " << generalPntr->i_ << endl;
    return 0;
}
