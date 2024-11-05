class Stack:
    def __init__(self):
        self.list: list[int] = []
    
    def push(self, val:int):
        self.list.append(val)
    
    def pop(self) -> int:
        if self.is_empty():
            return IndexError("stack is empty")
        return self.list.pop()
    
    def top(self) -> int:
        if self.is_empty():
            return IndexError("stack is empty")
        return self.list[-1]
    
    def is_empty(self):
        return len(self.list) == 0
    
    def size(self) -> int:
        return len(self.list)
    
    def to_list(self) -> list[int]:
        return self.list

if __name__ == "__main__":
    s = Stack()
    s.push(1)
    s.push(3)
    print(f"statck has {s.size()} elements")
    print(f"statck top  element is {s.top()}")
    s.pop()
    print(f"statck has {s.size()} elements")
    print(f"statck top  element is {s.top()}")
    
    