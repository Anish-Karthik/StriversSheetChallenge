# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
1. class Solution:
2.     def maxPathSum(self, root: TreeNode) -> int:
3. 		max_path = float("-inf")
4. 		def get_max_gain(node):
5. 			nonlocal max_path
6. 			if node is None:
7. 				return 0
9. 			gain_on_left = max(get_max_gain(node.left), 0) 
10. 		gain_on_right = max(get_max_gain(node.right), 0)  
12. 		current_max_path = node.val + gain_on_left + gain_on_right 
13. 		max_path = max(max_path, current_max_path) 
14. 			
15. 		return node.val + max(gain_on_left, gain_on_right) 
17. 			
18. 	get_max_gain(root) # Starts the recursion chain
19. 	return max_path		
