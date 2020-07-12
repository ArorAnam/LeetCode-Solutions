class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        nums.sort()

        N = int(pow(2, len(nums)))
        s = set()

        for i in range(N):
            subset = []
            #check every bit of i
            for j in range(len(nums)):
                # if the j'th bit of i is set, append nums[j] to subset
                if i & (1 << j):
                    subset.append(nums[j])

            s.add(str(subset))

        return s
