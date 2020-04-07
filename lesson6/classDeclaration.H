#ifndef CLASSDECLARATION_H_
#define CLASSDECLARATION_H_

#include<iostream>
using namespace std;

class A
{
public:
// 在定义时并不知道最终调用的是哪个函数，因此称为虚函数
    virtual void foo()
    {
        cout<<"A::foo() is called"<<endl;
    }
};

class B: public A
{
public:
// 这里的虚函数必须和A的同名
    virtual void foo()
    {
        cout<<"B::foo() is called"<<endl;
    }
};

// 若一个类至少含有一个纯虚函数，这个类是抽象类
// 抽象类不可实例化对象，它只是一个接口
class abstractClass
{
public:
// 纯虚函数，通过=0来指定
    virtual int getVolume()=0;
    int i_;
    int j_;
};
// 抽象类的作用是规定子类的定义方式
class realized1: public abstractClass
{
public:
    int getVolume()
    {
        return i_*j_;
    }
};

class realized2: public abstractClass
{
public:
    int getVolume()
    {
        return 2*i_*j_;
    }
};

#endif