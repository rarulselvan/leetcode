class Solution(object):
    def kClosest(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """

        points.sort(key=lambda p: hypot(p[0], p[1]))
        return points[:k]