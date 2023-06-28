"""

外观模式

"""


class CPU:
    """
    CPU
    """
    def freeze(self) -> None:
        print("freeze processor")

    def jump(self, position: str) -> None:
        print(f"jumping to {position}")

    def execute(self) -> None:
        print("Execute ...")


class Memory:
    """
    内存
    """
    def load(self, position: str, data: str) -> None:
        print(f"Loading from {position} data: {data}")


class SolidStateDrive:
    """
    固态硬盘
    """
    def read(self, lba: str, size: str) -> str:
        return f"Some data from sector {lba} with size {size}"


class ComputerFacade:
    def __init__(self):
        self.cpu = CPU()
        self.memory = Memory()
        self.ssd = SolidStateDrive()

    def start(self):
        self.cpu.freeze()
        self.memory.load("0x00", self.ssd.read("100", "1024"))
        self.cpu.jump("0x00")
        self.cpu.execute()


def main():
    """
    >>> Computer_Facade = ComputerFacade()
    >>> Computer_Facade.start()
    freeze processor
    Loading from 0x00 data: Some data from sector 100 with size 1024
    jumping to 0x00
    Execute ...
    """
    if __name__ == "__main__":
        import doctest

        doctest.testmod(optionflags=doctest.ELLIPSIS)

main()