// -这个函数T返回vaolScalarField
volScalarField T
(
    IOobject
    (
        "T", // 对象名
        runTime.timeName(),// 路径 "/0/T"
        mesh,// objectRegistry 注册为mesh对象
        IOobject::MUST_READ, // r
        IOobject::AUTO_WRITE // w
    ),
    mesh
);

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

dimensionedScalar DT
(
    transportProperties.lookup("DT")
);
