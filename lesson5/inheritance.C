#include <iostream>
using namespace std;
/* 
类的继承: 一个类可以继承自任何已经存在的类，并且可以加入新的属性 
在OpenFOAM中，子类在不同的路径中，因此不同的文件下，为了实现继
承，在#include中加入声明了母类的头文件 *.H
*/

class myClass
{
private:
    int l_ = 10;

public:
    int m_;
    int n_;
    myClass();
    myClass(int, int);
    ~myClass();
    // 类的友函数(Friends) 可以获取这个类的私有成员
    // 类可以邀请函数或者另一个类成为他的朋友，但是他不能要求成为其他类的朋友
    friend class myClassFriend;
};

myClass::myClass()
{
}

myClass::myClass(int m, int n)
    : m_(m),
      n_(n)
{
    cout << "m_=" << m_ << endl;
    cout << "n_=" << n_ << endl;
}

myClass::~myClass()
{
}
// 继承
class mySubClass : public myClass
{
public:
    mySubClass();
    mySubClass(int, int);
};
// 构造函数的重定义是必须的，而且必须从母函数中构造
mySubClass::mySubClass()
    : myClass()
{
}
mySubClass::mySubClass(int i, int j)
    : myClass(i, j)
{
}

class myClassFriend
{
public:
    int private_l;
    myClassFriend();
};

myClassFriend::myClassFriend()
{
    myClass testmyClassFriend;
    private_l = testmyClassFriend.l_;
    cout << "testmyClassFriend.l_=" << testmyClassFriend.l_ << endl;
}
// 算符重载 定义类之间的加法
inline myClass operator+(const myClass &mC1, const myClass &mC2)
{
    return myClass(
        mC1.m_ + mC2.m_,
        mC1.n_ + mC2.n_);
}

// 模板: 使类成员的类型可以随意指定
template <typename T> // 这里说明了T是一个模板
class MyTemplateClass
{
public:
    T x_;
    MyTemplateClass(T);
};
template <typename T>
MyTemplateClass<T>::MyTemplateClass(T x)
    : x_(x)
{
    cout << "x_=" << x_ << endl;
}
// 为了使代码更易读，使用别名
typedef MyTemplateClass<int> myTemplInt;

int main()
{
    myClass myClassObject(1, 2);
    myClass myClassObject2(3, 4);
    myClass mySum;
    mySum = myClassObject + myClassObject2;
    cout << mySum.m_ << endl;
    mySubClass mySubClassObject(1, 1);
    cout << mySubClassObject.m_ << endl;
    // 友类获取到了private成员
    myClassFriend myClassFriendObject;
    cout << myClassFriendObject.private_l << endl;
    // 模板
    myTemplInt myTemplateClassIntObject(4.6);
    cout << "myTemplatedClassIntObject.x_: " << myTemplateClassIntObject.x_ << endl;
    MyTemplateClass<float> myTemplateClassFloatObject(4.6);
    cout << "myTemplatedClassFloatObject.x_: " << myTemplateClassFloatObject.x_ << endl;
    return 0;
}