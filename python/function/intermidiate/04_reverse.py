#!/usr/bin/python
#➤ Write a function reverse_string(s) that reverses a string manually.


def reverse_string(s):
    a=''
    _len = len(s)
    for i in range(_len-1,-1,-1):
        a+=s[i]
    return a
s = input("Enter the word: ")
print(f"The reverse of {s} is {reverse_string(s)}")
