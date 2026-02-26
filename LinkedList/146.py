class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None


class LRUCache:

    def __init__(self, capacity):
        self.buf = {}
        self.cap = capacity
        self.head = Node(0,0)
        self.tail = Node(0,0)
        self.head.next = self.tail
        self.tail.prev = self.head

    # 🔹 你要實作這三個
    def remove(self, node):
        front = node.prev
        back = node.next
        front.next = back
        back.prev = front
        

    def insert_front(self, node):
        back = self.head.next
        self.head.next = node
        node.next = back
        back.prev = node
        node.prev = self.head
        
    def get(self, key):
        if key not in self.buf:
            return -1
        
        node = self.buf[key]
        self.remove(node)
        self.insert_front(node)
        return node.val        

    def put(self, key, value):
        if key in self.buf:
            node = self.buf[key]
            node.val = value
            self.remove(node)
            self.insert_front(node)
            return
        node = Node(key, value)
        self.buf[key] = node
        self.insert_front(node)

        if len(self.buf) > self.cap:
            lru = self.tail.prev
            self.remove(lru)
            del self.buf[lru.key]
        



# -----------------------
# Testing main
# -----------------------

def run_test_1():
    print("Test 1")
    cache = LRUCache(2)

    cache.put(1, 1)
    cache.put(2, 2)
    print(cache.get(1))  # 1

    cache.put(3, 3)      # evicts key 2
    print(cache.get(2))  # -1

    cache.put(4, 4)      # evicts key 1
    print(cache.get(1))  # -1
    print(cache.get(3))  # 3
    print(cache.get(4))  # 4
    print()


def run_test_2():
    print("Test 2")
    cache = LRUCache(1)

    cache.put(1, 1)
    cache.put(2, 2)
    print(cache.get(1))  # -1
    print(cache.get(2))  # 2
    print()


if __name__ == "__main__":
    run_test_1()
    run_test_2()