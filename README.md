

# C++ in OpenFOAM Style

![badge](https://img.shields.io/badge/License-MIT-brightgreen)

#### 介绍
C++学习笔记，不涉及太深，大多是关于面向对象编程以及OpenFOAM中的实现方法

#### 平台
- WSL Ubuntu 18.04LTS
- OpenFOAM-v1912
- 使用Vscode编写，包含有Vscode配置文件`c_cpp_properties.json`
- Vscode插件C/C++

#### Contents
0. 类的声明和定义(declaration and definition)
1. 引用(reference)
2. 指针(pointer)
3. 静态变量(static)
4. 常量和变量(const)
5. 继承、算符重载、友函数、模板、Typedef(Inheritace,reload,Friends,Templates,Typedef)
6. 虚函数、抽象类、容器(Virtual member functions, Abstract class and container class)
7. OpenFOAM实例-`laplacianFoam`

#### myLaplacianFoam

修改了`laplacianFoam`求解器，只输出温度场，而不输出温度梯度场，去掉了源项框架`fvOptions`，去掉了非正交修正部分`correctNonOrthogonal`，成为一个较为简明的热传导方程求解器。
- 运行算例1:法兰的导热计算
```
cd flange
./Allrun
```
相当于
```
ansysToFoam flange.ans -scale 0.001
myLaplacianFoam
```
- 运行算例2:平板导热计算
```
fluentMeshToFoam fluent.msh
myLaplacianFoam
```

<img src="https://images.gitee.com/uploads/images/2020/0327/141942_ca7c2a05_6577728.png" alt="flange" title="flange.png"  />

![plane](https://images.gitee.com/uploads/images/2020/0330/104143_90c5c961_6577728.png "plane.png")

#### Notes
默认`Allrun`运行法兰导热算例，要运行平板非稳态算例：

*Step 1*

`/flange/constant/transportProperties`修改为：
```
DT              DT [ 0 2 -1 0 0 0 0 ] 0.1;; // 热扩散率
```

*Step2*

运行`fluentMeshToFoam fluent.msh`后，修改`constant/polyMesh/boudary`中的`EMPTY`项的类型为`empty`（用ICEM画网格时未考虑到，设置成了`wall`）

*Step3*

修改`0/T`中的`boundaryField`，注释patch1-4，启用`SOURCE EMPTY COLD`这三个边界条件

*Step4*

运行
```
fluentMeshToFoam fluent.msh
myLaplacianFoam
```
