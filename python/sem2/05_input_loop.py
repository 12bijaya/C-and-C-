#!/usr/bin/python
n = int(input("Enter how many times you want to print: "))
word = input("Enter what to print: ")
for i in range(n):
    print(f"{word} {i+1}")
