#!/usr/bin/python
#Create a function fibonacci(n) that returns the first n Fibonacci numbers.


def fibonacci(n):
    fib = [0, 1]
    for i in range(2, n):
        fib.append(fib[-1] + fib[-2])
    return fib[:n]
n = int(input("Enter the number: "))
print(f"The fibonacci series of {n} is {fibonacci(n)}")
