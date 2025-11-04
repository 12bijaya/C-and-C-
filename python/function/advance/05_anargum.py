#!/usr/bin/python
#Write a function is_anagram(str1, str2) that checks if two words have the same characters in any order.
def is_anagram(str1, str2):
    return sorted(str1) == sorted(str2)

a = input("Enter first word: ")
b = input("Enter second word: ")

if is_anagram(a, b):
    print("anagrams ")
else:
    print("not anagrams")

