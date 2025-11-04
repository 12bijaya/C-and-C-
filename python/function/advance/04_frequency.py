#!/usr/bin/python
# Write a function char_frequency(s) that counts how many times each character appears.
def char_frequency(s,m):
    frequency = 0
    for i in s:
        if m == i:
            frequency += 1
    return frequency
s = input("Enter the word: ")
for m in s:
    print(f"{m} is repeated {char_frequency(s,m)}")

