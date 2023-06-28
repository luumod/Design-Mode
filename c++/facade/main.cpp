#include <QCoreApplication>

// 复杂子程序
class SyntaxCheck{
public:
    SyntaxCheck(){}
    void syntaxCheckSystem(){
        qInfo()<<"语法检查中 ... ";
    }
};
class Complie{
public:
    Complie(){}
    void complieSrcCode(){
        qInfo()<<"编译代码 ...";
    }
};
class GeneratMidCode{
public:
    GeneratMidCode(){}
    void generatorM(){
        qInfo()<<"生成中间代码 ...";
    }
};
class GeneratExecutable{
public:
    GeneratExecutable(){}
    void generatE(){
       qInfo()<<"生成可执行文件 ...";
    }
};

// Facade
class Facade{
public:
    Facade():s(),c(),mcode(),exec(){}
    void build(){
        s.syntaxCheckSystem();
        c.complieSrcCode();
        mcode.generatorM();
        exec.generatE();
    }
private:
    SyntaxCheck s;
    Complie c;
    GeneratMidCode mcode;
    GeneratExecutable exec;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Facade f;
    f.build();

    return a.exec();
}
