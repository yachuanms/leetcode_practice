from typing import List


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = {}

        for i in range(numCourses):
            graph[i] = []

        for course, pre in prerequisites:
            graph[course].append(pre)

        visiting = set()
        visited = set()
        order = []

        def dfs(course):
            # TODO 1:
            # if course in visiting -> cycle -> return False
            if course in visiting:
                return False
            # TODO 2:
            # if course in visited -> already processed -> return True
            if course in visited:
                return True
            # TODO 3:
            # add course to visiting
            visiting.add(course)
            # TODO 4:
            # dfs all prerequisites
            for pre in graph[course]:
                if not dfs(pre):
                    return False
            # TODO 5:
            # remove from visiting
            visiting.remove(course)
            # add to visited
            visited.add(course)
            # append course to order
            order.append(course)
            return True

        for course in range(numCourses):
            if not dfs(course):
                return []

        return order


def is_valid_order(order, numCourses, prerequisites):
    if len(order) != numCourses:
        return False

    pos = {course: i for i, course in enumerate(order)}

    for course, pre in prerequisites:
        if pos[pre] > pos[course]:
            return False

    return True


def test_course_schedule_ii():
    s = Solution()

    numCourses1 = 2
    prerequisites1 = [[1, 0]]
    ans1 = s.findOrder(numCourses1, prerequisites1)
    print(ans1, is_valid_order(ans1, numCourses1, prerequisites1))  # expected: True

    numCourses2 = 4
    prerequisites2 = [[1, 0], [2, 0], [3, 1], [3, 2]]
    ans2 = s.findOrder(numCourses2, prerequisites2)
    print(ans2, is_valid_order(ans2, numCourses2, prerequisites2))  # expected: True

    numCourses3 = 2
    prerequisites3 = [[1, 0], [0, 1]]
    ans3 = s.findOrder(numCourses3, prerequisites3)
    print(ans3)  # expected: []

    numCourses4 = 1
    prerequisites4 = []
    ans4 = s.findOrder(numCourses4, prerequisites4)
    print(ans4, is_valid_order(ans4, numCourses4, prerequisites4))  # expected: [0], True


if __name__ == "__main__":
    test_course_schedule_ii()