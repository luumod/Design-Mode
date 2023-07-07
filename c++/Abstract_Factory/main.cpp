#include <QCoreApplication>
#include <iostream>
#include <QDebug>

//抽象产品
class AbstractProduct{
public:
    virtual void showInfo() = 0;
};

//抽象产品族1
class Mouse : public AbstractProduct{};

//具体产品
class RojiMouse: public Mouse{
public:
    void showInfo()override{
        qInfo()<<"罗技鼠标产品 ...";
    }
};
class RazerMouse:public Mouse{
public:
    void showInfo()override{
        qInfo()<<"雷蛇鼠标产品 ...";
    }
};

//抽象产品族2
class Keyboard:public AbstractProduct{};

//具体产品
class RojiKeyboard:public Keyboard{
public:
    void showInfo()override{
        qInfo()<<"罗技键盘产品 ...";
    }
};
class RazerKeyboard:public Keyboard{
public:
    void showInfo()override{
        qInfo()<<"雷蛇键盘产品 ...";
    }
};

// 抽象工厂
class AbstractFactory{
public:
    virtual Mouse* produceMouse() = 0;
    virtual Keyboard* produceKeyboard() = 0;
};
//具体工厂
class RojiFactory:public AbstractFactory{
public:
    Mouse* produceMouse()override{
        return new RojiMouse;
    }
    Keyboard* produceKeyboard()override{
        return new RojiKeyboard;
    }
};

class RazerFactory:public AbstractFactory{
public:
    Mouse* produceMouse()override{
        return new RazerMouse;
    }
    Keyboard* produceKeyboard()override{
        return new RazerKeyboard;
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo()<<"---------- 雷蛇工厂 --------------";
    std::unique_ptr<AbstractFactory> fact(new RazerFactory());
    std::unique_ptr<Mouse> mouse(fact->produceMouse());
    std::unique_ptr<Keyboard> keyboard(fact->produceKeyboard());
    mouse->showInfo();
    keyboard->showInfo();

    qInfo()<<"---------- 罗技工厂 --------------";
    fact.reset(new RojiFactory());
    mouse.reset(fact->produceMouse());
    keyboard.reset(fact->produceKeyboard());
    mouse->showInfo();
    keyboard->showInfo();

    return a.exec();
}
