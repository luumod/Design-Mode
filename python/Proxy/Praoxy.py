"""

代理模式

"""

from abc import ABCMeta, abstractmethod


class AbstractSubject(metaclass=ABCMeta):
    @abstractmethod
    def beginClass(self):
        pass


# 普通学生
class NormalStudent(AbstractSubject):
    def __init__(self):
        pass

    def beginClass(self):
        print("老师好~~~~")


# 代理：学生班长
class HeadStudent(AbstractSubject):
    def __init__(self, student: AbstractSubject):
        self.student = student

    def beginClass(self):
        print("上课，起立")
        self.student.beginClass()
        print("坐下")


if __name__ == "__main__":
    def main():
        nstu = NormalStudent()
        hstu = HeadStudent(nstu)
        hstu.beginClass()


    main()
