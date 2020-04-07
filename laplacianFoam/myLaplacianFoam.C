/*---------------------------------------------------------------------------*\
Description
    求解热传导方程
    $$
		\frac{\partial T}{\partial t}=\nabla\cdot{(D_T\nabla T)}
	$$
\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "simpleControl.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    argList::addNote("求解标量场的拉普拉斯方程.");

    #include "setRootCaseLists.H"
    #include "createTime.H"
    #include "createMesh.H"

    simpleControl simple(mesh);

    #include "createFields.H"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info << "\n计算温度分布\n" << endl;
    // SIMPLE算法循环
    while (simple.loop())
    {
        Info << "时间 = " << runTime.timeName() << nl << endl;
        // 要求解的方程
        fvScalarMatrix TEqn
        (
            fvm::ddt(T) - fvm::laplacian(DT, T) //==0 
        );
        TEqn.solve();

        runTime.write(); // 写结果

        runTime.printExecutionTime(Info);
    }

    Info << "计算结束\n" << endl;

    return 0;
}

// ************************************************************************* //