import bisect

if __name__ == "__main__":
    x = (1, 3, 4, 5, 6, 8)
    index = bisect.bisect_left(x, 5)
    print(index)
