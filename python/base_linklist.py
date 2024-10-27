class LinkNode:
    def __init__(self, val:int):
        self.val: int = val
        self.next: LinkNode | None = None

class LinkList:
    def __init__(self, nums:list[int]):
        self.head = None
        self.tail = None
        
        for val in nums:
            node = LinkNode(val)
            if self.head is None:
                self.head = node
                self.tail = node
            else:
                self.tail.next = node
                self.tail = node
    
    def tranverse(self):
        temp_node = self.head
        while temp_node:
            print(temp_node.val, end=" ", flush=False)
            temp_node = temp_node.next
        print("")
    
    def find(self, val) -> LinkNode:
        temp_node = self.head
        idx = 1
        find = False
        while temp_node:
            if temp_node.val == val:
                find = True
                print(f"find it, at {idx} node")
                break
            temp_node = temp_node.next
            idx+=1
        if not find:
            print(f"{val} not in link list")
        return temp_node

    def insert(self, node: LinkNode, val:int):
        new_node = LinkNode(val)
        new_node.next = node.next
        node.next = new_node
        
    
    def delete(self, val:int):
        pre_node = self.head
        cur_node = self.head        
        while cur_node:
            if cur_node.val == val:
                if cur_node == self.head:
                    self.head = self.head.next
                else:
                    pre_node.next = cur_node.next
                    
                if cur_node == self.tail:
                    self.tail = pre_node
                del cur_node
                break
            pre_node = cur_node
            cur_node = cur_node.next
        return


if __name__ == "__main__":
    nums: list[5] = [1,5,9,2,3]
    
    link = LinkList(nums=nums)
    
    link.tranverse()
    
    insert_pos = link.find(9)
    
    link.insert(insert_pos, 13)
    
    link.tranverse()
    
    link.delete(1)
    
    link.tranverse()
    
    link.delete(12)
    
    link.tranverse()
    
    link.delete(3)
    
    link.tranverse()
