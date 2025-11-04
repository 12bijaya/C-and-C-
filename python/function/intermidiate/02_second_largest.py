#!/usr/bin/python
# Create a function sum_list(numbers) that returns the sum of all items in a list.
def sum_list(number):
    sum = 0
    for i in number:
        sum+=i
    return sum

number = [1,2,3,4,5]
print(f"sum of {number} is {sum_list(number)}")

