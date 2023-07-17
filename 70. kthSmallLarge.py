import heapq 

def kthSmallLarge(arr, n, k):
    heapq.heapify(arr)
    while len(arr) >= min(k, n-k+1):
        top = heapq.heappop(arr)
        if len(arr)+1 == n - k + 1:
            kthSmallest = top
        if len(arr)+1 == k:
            kthLargest = top
    return kthSmallest, kthLargest
