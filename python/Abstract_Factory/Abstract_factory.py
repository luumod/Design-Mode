from abc import ABCMeta, abstractmethod

# 抽象产品类
class Product(metaclass=ABCMeta):
    def __init__(self):
        pass

    @abstractmethod
    def showInfo(self):
        pass


# 具体产品族
class Mouse(Product):
    pass


# 具体产品
class RojiMouse(Mouse):
    def __init__(self):
        pass

    def showInfo(self):
        print("罗技鼠标 ...")


class RazerMouse(Mouse):
    def __init__(self):
        pass

    def showInfo(self):
        print("雷蛇鼠标 ...")


# 具体产品族
class keyBoard(Product):
    pass


# 具体产品
class RojiKeyboard(Product):
    def __init__(self):
        pass

    def showInfo(self):
        print("罗技键盘 ...")


class RazerKeyboard(Product):
    def __init__(self):
        pass

    def showInfo(self):
        print("雷蛇键盘 ...")


# 抽象工厂类
class Factory(metaclass=ABCMeta):
    def __init__(self):
        pass

    @abstractmethod
    def produceMouse(self) -> Mouse:
        pass

    @abstractmethod
    def produceKeyboard(self) -> keyBoard:
        pass


class RojiFactory(Factory):
    def __init__(self):
        pass

    def produceMouse(self) -> Mouse:
        return RojiMouse()

    def produceKeyboard(self) -> keyBoard:
        return RojiKeyboard()


class RazerFactory(Factory):
    def __init__(self):
        pass

    def produceMouse(self) -> Mouse:
        return RazerMouse()

    def produceKeyboard(self) -> keyBoard:
        return RazerKeyboard()


if __name__ == "__main__":
    def main() -> None:
        fact = RojiFactory()
        keyboard = fact.produceKeyboard()
        mouse = fact.produceMouse()
        keyboard.showInfo()
        mouse.showInfo()

        fact = RazerFactory()
        keyboard = fact.produceKeyboard()
        mouse = fact.produceMouse()
        keyboard.showInfo()
        mouse.showInfo()


    main()
