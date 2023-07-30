
# Binary tree node class for reference
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def diameterOfBinaryTree(root):
  width = 0
  def height(root):
    nonlocal width;
    if not root:
      return 0
    left = 1 + height(root.left)
    right = 1 + height(root.right)
    width = max(width, left+right-2)
    return max(left,right)
  height(root)
  return width
