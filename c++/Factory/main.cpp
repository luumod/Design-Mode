#include <QCoreApplication>
#include <iostream>

//抽象产品类
class AbstractProduct{
public:
    virtual ~AbstractProduct(){}
    virtual void makeProduct() = 0;
};

//具体产品
class PlaneProduct: public AbstractProduct{
public:
    virtual ~PlaneProduct(){}
    void makeProduct(){
        qInfo()<<"造飞机";
    }
private:
};

//具体产品
class RocketProduct: public AbstractProduct{
public:
    virtual ~RocketProduct(){}
    void makeProduct(){
        qInfo()<<"造火箭";
    }
private:
};

//抽象工厂
class AbstractFactory{
public:
    virtual AbstractProduct* create()=0;
};

//具体工厂
class PlaneFactory:public AbstractFactory{
public:
    AbstractProduct* create(){
        return new PlaneProduct();
    }
};

//具体工厂
class RocketFactory:public AbstractFactory{
public:
    AbstractProduct* create(){
        return new RocketProduct();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::unique_ptr<AbstractFactory> factory(new PlaneFactory());
    std::unique_ptr<AbstractProduct> pro(factory->create());
    pro->makeProduct();

    factory.reset(new RocketFactory());
    pro.reset(factory->create());
    pro->makeProduct();

    return a.exec();
}
