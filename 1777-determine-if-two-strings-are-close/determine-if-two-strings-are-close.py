class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        # Count the frequency of each character in both words
        cnt1, cnt2 = Counter(word1), Counter(word2)
      
        # If the sets of unique characters (keys of the counters) are the same and
        # the sorted lists of character counts (values of the counters) are the same,
        # then the strings are "close"
        return sorted(cnt1.values()) == sorted(cnt2.values()) and set(cnt1.keys()) == set(cnt2.keys())