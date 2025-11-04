#!/usr/bin/python
# Write a function is_palindrome(word) that checks if a string reads the same forward and backward.
def is_palindrome(word):
    rev_word = word[::-1]
    if rev_word == word:
        return f"{word} is palindrome"
    else:
        return f"{word} is not palindrome"
word = input("Enter the word to check the palindrome: ")
print(f"{is_palindrome(word)}")

