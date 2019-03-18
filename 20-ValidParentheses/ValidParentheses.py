class Solution:
    def isValid(self, s: str) -> bool:
        map = {")" : "(", "]" : "[", "}" : "{"}
        stack = []
        for c in s:
            if c in map.values():
                stack.append(c)
            elif not stack or stack.pop() is not map[c]:
                return False
        
        return not stack