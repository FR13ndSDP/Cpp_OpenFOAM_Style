#include "classDeclaration.H"

/* virtual abstract container */
// 虚函数主要用于实现多态 

int main()
{
    // 使用指针建立连接
    A* a=new B();
    // 调用了B::foo()
    a->foo();
    realized1 real1;
    realized2 real2;
    real1.i_=2;
    real1.j_=4;
    real2.i_=1;
    real2.j_=4;
    int volume1 = real1.getVolume();
    int volume2 = real2.getVolume();
    cout<<volume1<<volume2<<endl;
    return 0;
}

/*
 关于容器：在C++ 中容器被定义为：在数据存储上，有一种对象类型，
它可以持有其它对象或指向其它对像的指针，这种对象类型就叫做容器
这种“对象”还包含了一系列处理“其它对象”的方法
OpenFOAM中的容器定义可以在 $FOAM_SRC/OpenFOAM/containers中找到
例如在Lists/UList中，
forAll 在UList.H 中定义，可以用来遍历任何的类：
#define forAll(list, i) \
    for (Foam::label i=0; i<(list).size(); i++)
使用forAll的方法：
    forAll(anyList, i) { statements; }
*/

/*
关于前置声明 FORWARD DECLARATION:
https://www.cnblogs.com/King-Gentleman/p/5081159.html
*/