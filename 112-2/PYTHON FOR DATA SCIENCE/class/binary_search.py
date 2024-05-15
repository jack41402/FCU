# Binary Search
import random

arr = []


def binary_search(num):
    left = 0
    right = len(arr) - 1
    arr.sort()
    while left <= right:
        middle = ((left + right) / 2).__floor__()
        if arr[middle] > num:
            right = middle - 1
        elif arr[middle] < num:
            left = middle + 1
        else:
            return middle


def main():
    for i in range(10):
        arr.append(random.randint(0, 100))
    arr.sort()
    print(arr)
    while (n := int(input("Enter a number: "))) >= 0:
        print(f"Number {n} found at {binary_search(n)}")


if __name__ == "__main__":
    main()
