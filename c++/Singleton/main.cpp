#include <QCoreApplication>


//懒汉式
class Singleton{
public:
    static Singleton* obj;
    static Singleton* getInstance(){
        if (!obj){
            obj = new Singleton();
        }
        return obj;
    }
    void testOperation(){
        qInfo()<<"进行操作";
    }
private:
    Singleton(){
        //构造函数私有化
        obj = nullptr;
    }
};

Singleton* Singleton::obj = nullptr;

//饿汉式： 直接在外部创建变量

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    qInfo()<<p1<<p2;
    p1->testOperation();
    p2->testOperation();
    delete Singleton::getInstance();
    return a.exec();
}
