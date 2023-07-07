#include <QCoreApplication>
#include <iostream>
#include <vld.h>

//抽象产品类
template <typename T>
class AbstractProduct{
public:
    AbstractProduct(T v1,T v2):v1(v1),v2(v2){}
    virtual ~AbstractProduct(){}
    virtual T getResult() = 0;
protected:
    T v1,v2;
};

//具体产品
template <typename T>
class AddOperation : public AbstractProduct<T>{
public:
    AddOperation(T v1,T v2):AbstractProduct<T>(v1,v2){}
    virtual ~AddOperation(){}
    T getResult()override{
        return this->v1 + this->v2;
    }
private:
};

//具体产品
template <typename T>
class SubOperation : public AbstractProduct<T>{
public:
    SubOperation(T v1,T v2):AbstractProduct<T>(v1,v2){}
    virtual ~SubOperation(){}
    T getResult()override{
        return this->v1 - this->v2;
    }
private:
};

//具体产品
template <typename T>
class MulOperation : public AbstractProduct<T>{
public:
    MulOperation(T v1,T v2):AbstractProduct<T>(v1,v2){}
    virtual ~MulOperation(){}
    T getResult()override{
        return this->v1 * this->v2;
    }
private:
};

//具体产品
template <typename T>
class DivOperation : public AbstractProduct<T>{
public:
    DivOperation(T v1,T v2):AbstractProduct<T>(v1,v2){}
    virtual ~DivOperation(){}
    T getResult()override{
        return this->v1 / this->v2;
    }
private:
};

//抽象工厂
template <typename T>
class AbstractFactory{
public:
    static AbstractProduct<T>* create(T v1, char op, T v2){
        assert(op=='+' || op=='-' || op=='*' || op=='/');
        if (op=='+'){
            return new AddOperation<T>(v1,v2);
        }
        else if (op=='-'){
            return new SubOperation<T>(v1,v2);
        }
        else if (op=='*'){
            return new MulOperation<T>(v1,v2);
        }
        else if (op=='/'){
            return new DivOperation<T>(v1,v2);
        }
        return nullptr;
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::unique_ptr<AbstractProduct<int>> pro(AbstractFactory<int>::create(5,'+',2));
    qInfo()<<pro->getResult();
    pro.reset( AbstractFactory<int>::create(5,'-',2));
    qInfo()<<pro->getResult();
    pro.reset( AbstractFactory<int>::create(5,'*',2));
    qInfo()<<pro->getResult();
    pro.reset( AbstractFactory<int>::create(5,'/',2));
    qInfo()<<pro->getResult();

    return a.exec();
}
