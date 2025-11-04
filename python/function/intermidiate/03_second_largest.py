#!/usr/bin/python
#Write a function second_largest(nums) that returns the second largest value from a list.
def second_largest(num):
    _len = len(num)
    num.sort()
    return num[-2]
num = [2,5,65,7,7,343]
print(second_largest(num))
