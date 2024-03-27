# from functools import reduce
#
#
# def minimum(arr):
#     if isinstance(arr[0], str):
#         return reduce(lambda x, y: x if len(x) < len(y) else y, arr)
#         # return min(arr, key=len)
#     else:
#         return min(arr)
#
#
# result = minimum([45, 5, 4, 3])
# print(result)
#
# result = minimum(["red", "yellow", "green"])
# print(result)
import numpy

number = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(number)
odd = [i for i in number if i % 2 == 1]
print(odd)
