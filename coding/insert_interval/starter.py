class Solution:
    # @params:
    # - intervals: List[List[int]]
    # - newInterview: List[int]
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        new_start, new_end = newInterval
        result = []
        for i, (start, end) in enumerate(intervals):
            if end < new_start:
                result.append([start, end])
            elif end <= new_end:
                new_start = min(start, new_start)
            elif start <= new_end:
                new_start = min(start, new_start)
                new_end = end
            elif start > new_end:
                result.append([new_start, new_end])
                result += intervals[i:]
                break
        else:
            result.append([new_start, new_end])
            
        return result
