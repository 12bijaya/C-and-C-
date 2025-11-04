#!/usr/bin/python
# Create a function is_even(n) that checks whether a number is even or odd.
def is_even(n):
    if (n&1==1):
         print("Odd")
    else:
        print("Even")
is_even(int(input("Enter the number to check odd or even: ")))
