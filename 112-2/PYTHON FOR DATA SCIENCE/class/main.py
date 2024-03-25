from functools import reduce


def minimum(arr):
    if isinstance(arr[0], str):
        return reduce(lambda x, y: x if len(x) < len(y) else y, arr)
        # return min(arr, key=len)
    else:
        return min(arr)


result = minimum([45, 5, 4, 3])
print(result)

result = minimum(["red", "yellow", "green"])
print(result)
