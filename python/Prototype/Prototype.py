from __future__ import annotations
from typing import Any
class Prototype:
    def __init__(self, value: str = "default", **attrs: Any) -> None:
        self.value = value
        self.__dict__.update(attrs)

    def clone(self, **attrs: Any) -> Prototype:
        obj = self.__class__(**self.__dict__)
        obj.__dict__.update(attrs)
        return obj


class PrototypeDispatcher:
    def __init__(self):
        self._objects = {}

    def get_objects(self) -> dict[str, Prototype]:
        """Get all objects"""
        return self._objects

    def register_object(self, name: str, obj: Prototype) -> None:
        self._objects[name] = obj

    def unregister_object(self, name: str) -> None:
        del self._objects[name]


if __name__ == "__main__":
    def main():
        dispatcher = PrototypeDispatcher()
        prototype = Prototype()

        d = prototype.clone()
        a = prototype.clone(value='a-value', category='a')
        b = a.clone(value='b-value', is_checked=True)
        dispatcher.register_object('objecta', a)
        dispatcher.register_object('objectb', b)
        dispatcher.register_object('default', d)

        print([{n: p.value} for n, p in dispatcher.get_objects().items()])
        print(b.category, b.is_checked)
    main()