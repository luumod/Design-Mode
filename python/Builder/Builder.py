'''

建造者模式

'''
from abc import ABCMeta,abstractmethod

class Computer:
    def __init__(self, name:str, cpu:str, ram: str):
        self.name = name
        self.cpu = cpu
        self.ram = ram
    def setMouse(self, mouse:str):
        self.mouse = mouse
    def setDisplay(self, display:str):
        self.display = display
    def showInfo(self)->None:
        print(f"电脑信息: {self.name},{self.cpu},{self.ram},{self.mouse},{self.display}")

class ComputerBuilder(metaclass=ABCMeta):

    @abstractmethod
    def setMouse(self):
        pass
    def setDisplay(self):
        pass
    def getProduct(self)->Computer:
        pass

class MacComputer(ComputerBuilder):
    def __init__(self, name:str, cpu:str, ram:str):
        self.computer = Computer(name,cpu,ram)
    def setMouse(self):
        self.computer.setMouse("mac鼠标")
    def setDisplay(self):
        self.computer.setDisplay("mac键盘")
    def getProduct(self) ->Computer:
        return self.computer

class LenovoComputer(ComputerBuilder):
    def __init__(self,name:str, cpu:str, ram:str):
        self.computer = Computer(name,cpu,ram)
    def setMouse(self):
        self.computer.setMouse("Lenovo鼠标")
    def setDisplay(self):
        self.computer.setDisplay("Lenovo显示器")
    def getProduct(self)->Computer:
        return self.computer

class Director:
    def __init__(self):
        pass
    def makeProduct(self, builder:ComputerBuilder):
        builder.setMouse()
        builder.setDisplay()


if __name__=='__main__':
    def main():
        d = Director()
        builder = MacComputer("苹果电脑","I7处理器","海力士222")
        d.makeProduct(builder)
        mac = builder.getProduct()
        mac.showInfo()

        builder = LenovoComputer("联想电脑","I5处理器","三星125")
        d.makeProduct(builder)
        lenovo = builder.getProduct()
        lenovo.showInfo()

    main()