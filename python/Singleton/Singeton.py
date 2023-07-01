from typing import Dict

class SingleTon:
    _shared_state: Dict[str,str] = {}

    def __init__(self):
        self.__dict__ = self._shared_state

class YourBorg(SingleTon):
    def __init__(self, state:str = None)->None:
        super().__init__()
        if state:
            self.state = state
        else:
            if not hasattr(self,"state"):
                self.state = "Init"

    def __str__(self)->str:
        return self.state

rm1 = YourBorg()
rm2 = YourBorg()
rm1.state = 'Idle'
rm2.state = 'Running'
print('rm1: {0}'.format(rm1))
print('rm2: {0}'.format(rm2))