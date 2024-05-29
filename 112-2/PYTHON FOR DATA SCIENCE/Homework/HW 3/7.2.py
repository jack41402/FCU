# 7.2 (Broadcasting) Use arange to create a 2-by-2 array containing the numbers 0–3.
# Use broadcasting to perform each of the following operations on the original array:
# a) Cube every element of the array.
# b) Add 7 to every element of the array.
# c) Multiply every element of the array by 2.

import numpy as np

# Create a 2-by-2 array containing the numbers 0-3
array = np.arange(4).reshape(2, 2)
print("Original array:")
print(array)

# a) Cube every element of the array.
cubed_array = array ** 3
print("\nCubed array:")
print(cubed_array)

# b) Add 7 to every element of the array.
added_array = array + 7
print("\nArray with 7 added to each element:")
print(added_array)

# c) Multiply every element of the array by 2.
multiplied_array = array * 2
print("\nArray with each element multiplied by 2:")
print(multiplied_array)
