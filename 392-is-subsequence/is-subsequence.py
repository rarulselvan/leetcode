class Solution:
    def isSubsequenceHelper(self, s, t, m, n) -> bool:

        if n==0 :
            return True
        if m==0 :
            return False
        
        if s[m-1] == t[n-1]:
            return self.isSubsequenceHelper(s, t, m-1, n-1)
        else:
            return self.isSubsequenceHelper(s, t, m-1, n)

    def isSubsequence(self, s, t):
        return self.isSubsequenceHelper(t, s, len(t), len(s))