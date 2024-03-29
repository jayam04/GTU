import time, random

def merge_sort(arr):
    if len(arr) == 1:
        return arr
    half = len(arr) // 2
    
    left, right = merge_sort(arr[:half]), merge_sort(arr[half:])
    i, j, k = 0, 0, 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1
    for i in range(i, len(left)):
        arr[k] = left[i]
        k += 1
    for j in range(j, len(right)):
        arr[k] = right[j]
        k += 1
    
    print(arr)
    return arr


arr = [5, 6, 7,1, 2, 8]
print(f'Initial array: {arr}\n')
merge_sort(arr)

arr = [random.randint(-100, 100) for _ in range(1000)]
t1 = time.time()
merge_sort(arr)
print(f"Time taken: {time.time() - t1} seconds")
