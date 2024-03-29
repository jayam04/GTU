import time

def quick_sort(arr):
    print(arr)
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[-1]
        less_than_pivot = [x for x in arr[:-1] if x <= pivot]
        greater_than_pivot = [x for x in arr[:-1] if x > pivot]
        sorted_arr = quick_sort(less_than_pivot) + [pivot] + quick_sort(greater_than_pivot)

        print(sorted_arr)
        return sorted_arr

my_list = [4, 2, 7, 3, 8]
print(f"Initial Array: {my_list}")
t1 = time.time()
sorted_list = quick_sort(my_list)
print(f"Sorted Array: {sorted_list}")
print(f"Time taken: {time.time() - t1}")
