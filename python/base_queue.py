from queue import Queue, PriorityQueue


# 先进先出队列
q = Queue() 

q.put(1)
q.put(2)
q.put(3)

print(f"queue size: {q.qsize()}")
print(q.get())
print(q.get())
print(f"queue size: {q.qsize()}")

# 优先级队列: 小根堆
q = PriorityQueue()
q.put(10)
q.put(8)
q.put(12)

print(f"get the first min val: {q.get()}")
print(f"get the second min val: {q.get()}")

