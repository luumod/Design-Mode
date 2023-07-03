'''

简单工厂

'''
from abc import ABCMeta, abstractmethod
from enum import Enum


class Type(Enum):
    Plane = 1,
    Rocket = 2


class AbstractProduct(object):
    def __init__(self):
        pass

    @abstractmethod
    def makeProduct(self):
        pass


class PlaneProduct(AbstractProduct):
    def __init__(self):
        super().__init__()

    def makeProduct(self):
        return print("造飞机")


class RocketProduct(AbstractProduct):
    def __init__(self):
        super().__init__()

    def makeProduct(self):
        return print("造火箭")


class AbstractFactory(object):
    @staticmethod
    def create(t: Type) -> AbstractProduct:
        if t == Type.Plane:
            return PlaneProduct()
        elif t == Type.Rocket:
            return RocketProduct()


def main():
    pro = AbstractFactory.create(Type.Plane)
    pro.makeProduct()
    pro = AbstractFactory.create(Type.Rocket)
    pro.makeProduct()


main()
