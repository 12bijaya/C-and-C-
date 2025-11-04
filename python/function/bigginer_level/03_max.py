#!/usr/bin/python
# Write a function max_of_three(a, b, c) that returns the largest of the three.
def max_if_three(a, b, c):
    if(a>b and a>c):
        return f"{a} is greatest: "
    elif(b>a and b>c):
        return f"{b} is greatest: "
    elif(c>a and c>b):
        return f"{c} is greatest: "
    else:
        return "all are equal: "

a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))
c = int(input("Enter the third number: "))

print(max_if_three(a,b,c))
