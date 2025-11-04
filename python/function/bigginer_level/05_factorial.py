#!/usr/bin/python
#Write a function factorial(n) that returns the factorial of a number using a loop or recursion.

def factorial(number):
    value=1
    for i in range(0,number):
        value*=number
        number-=1
    return value
a = int(input("Enter the number to find factorial: "))
print(f"The factorial of {a} is {factorial(a)}")

