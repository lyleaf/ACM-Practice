class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s = list(s.encode('utf-8'))
        t = list(t.encode('utf-8'))
        s.sort()
        t.sort()
        if s == t:
            return True
        else:
            return False            
