from anytree import Node, RenderTree
from anytree import PreOrderIter, PostOrderIter, LevelOrderIter
from queue import Queue

class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BTree():
    def __init__(self, root: TreeNode):
        self.root = root

    def get_root(self)->TreeNode:
        return self.root

    def pre_order_traversal(self, node: TreeNode):
        if node:
            print(node.value, end=" ")
            self.pre_order_traversal(node.left)
            self.pre_order_traversal(node.right)

    def in_order_traversal(self, node: TreeNode):
        if node:
            self.pre_order_traversal(node.left)
            print(node.value, end=" ")
            self.pre_order_traversal(node.right)
    
    def post_order_traversal(self, node: TreeNode):
        if node:
            self.pre_order_traversal(node.left)
            self.pre_order_traversal(node.right)
            print(node.value, end=" ")

    def level_order_traversal(self, node: TreeNode):
        if not root:
            return
        q = Queue()
        q.put(node)
        while not q.empty():
            node = q.get()
            print(node.value, end=" ")
            if node.left:
                q.put(node.left)
            if node.right:
                q.put(node.right)
        
    def size(self, node:TreeNode) -> int:
        if not node:
            return 0
        return 1 + self.size(node.left) + self.size(node.right)
    
    def height(self, node:TreeNode):
        if not node:
            return 0
        left_height = self.height(node.left)
        right_height = self.height(node.right)
        return max(left_height,right_height) + 1


if __name__ == '__main__':
    # 示例
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)

    btree = BTree(root)
    print("\n前序遍历:", end=" ")
    btree.pre_order_traversal(root)
    print("\n中序遍历:", end=" ")
    btree.in_order_traversal(root)
    print("\n后序遍历:", end=" ")
    btree.post_order_traversal(root)
    print("\n层序遍历:", end=" ")
    btree.level_order_traversal(root)
    print("\n")
    print(f"tree has {btree.size(root)} elements")
    print(f"tree height is {btree.height(root)}")

    # 创建树
    root = Node("1")
    child1 = Node("2", parent=root)
    child2 = Node("3", parent=root)
    subchild1 = Node("4", parent=child1)
    subchild2 = Node("5", parent=child1)

    # 显示树结构
    for pre, fill, node in RenderTree(root):
        print(f"{pre}{node.name}")

    # 前序遍历树
    for node in PreOrderIter(root):
        print(node.name, end=" ")

    print("\n")

    # 后序遍历
    for node in PostOrderIter(root):
        print(node.name, end=" ")
    print("\n")

    # 层序遍历
    for node in LevelOrderIter(root):
        print(node.name, end=" ")
    print("\n")

    # 打印树的高度
    print(f"tree height: {root.height}")

        
        