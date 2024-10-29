class ListOP:
    def __init__(self, num: list[int]):
        self.num = num

    # append val
    def append(self, val:int):
        self.num.append(val)

    # tranverse list
    def tranverse(self):
        for val in self.num:
            print(val, sep=" ", end=" ", flush=False)
        print(flush=True)
    
    # insert element
    def insert(self, index:int, val: int):
        if index <0 or index >= len(self.num):
            assert ValueError("Index out of range")
        self.num.insert(index,val)

    # sort list: min->max
    def sort(self, key=None, reverse=False):
        self.num.sort(key=key, reverse=reverse)
        
    # len
    def len(self):
        return len(self.num)
    
    # slice
    def slice(self, start:int, end:int):
        return self.num[start:end]
        


if __name__ == "__main__":
    num: list[int] = [1,2,3,4]
    
    list_num = ListOP(num)
    list_num.tranverse()
    list_num.append(7)
    list_num.tranverse()
    list_num.insert(3,8)
    list_num.insert(2,9)
    list_num.tranverse()
    list_num.sort()
    list_num.tranverse()
    list_num.sort(None, reverse=True)
    list_num.tranverse()
    slice = list_num.slice(3,-1)
    print(slice)
