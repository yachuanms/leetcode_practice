from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        # adjacency list
        graph = {}

        for i in range(numCourses):
            graph[i] = []

        for course, pre in prerequisites:
            graph[course].append(pre)

        visiting = set()
        visited = set()

        def dfs(course):
            if course in visiting:
                return False
            if course in visited:
                return True
            
            visiting.add(course)
            for pre in graph[course]:
                if not dfs(pre):
                    return False
                
            visiting.remove(course)
            visited.add(course)
            return True
        
        for course in range(numCourses):
            if not dfs(course):
                return False
        
        return True
        


def test_course_schedule():
    s = Solution()

    print(s.canFinish(2, [[1,0]]))          # expected: True
    print(s.canFinish(2, [[1,0],[0,1]]))    # expected: False
    print(s.canFinish(4, [[1,0],[2,1],[3,2]]))  # expected: True
    print(s.canFinish(3, [[0,1],[1,2],[2,0]]))  # expected: False


if __name__ == "__main__":
    test_course_schedule()