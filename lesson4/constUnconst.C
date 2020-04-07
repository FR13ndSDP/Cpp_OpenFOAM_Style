#include <iostream>
using namespace std;
/* 
在OpenFOAM中， 你可能看到const int& myClass::k() const
这表明函数返回值是一个const int&, 函数名后的const表明函数是
一个静态成员函数
 */
class myClass
{
private:
    int l_=9;
public:
    const int k_ = 8;
    myClass();
    ~myClass();
    // 静态成员函数 int表示返回整形，const告诉编译器它不改变静态成员的值
    int k() const;
    // 非静态成员函数
    int& l()
    {
        return l_;
    };
};

myClass::myClass()
{
    cout << "构建函数调用" << endl;
}

myClass::~myClass()
{
}

int myClass::k() const
{
    return k_;
}

int main()
{
    myClass myClassObject;
    cout << "k_=" << myClassObject.k() << endl;
    // k是k_的静态引用
    // k也必须是一个静态变量才能引用，这保证了代码的安全性
    // 注意const_k=10;这样的赋值是不允许的
    const int &const_k = myClassObject.k(); // 这是一个引用，和赋值区分开
    cout << "const_k=" << const_k << endl;
    // 这里k不是静态变量，却依然能够进行赋值
    // 而且再进行k=10;也是允许的
    int k = myClassObject.k();
    cout << "k=" << k << endl;
    // 私有成员不可以使用myClassObject.l_来调用
    // 通过成员函数来调用是可以的
    cout<<"l_="<<myClassObject.l()<<endl;
    int& l=myClassObject.l();
    l=12;// 非静态成员可以在引用后被改变
    cout<<"l="<<l<<endl;
    return 0;
}
