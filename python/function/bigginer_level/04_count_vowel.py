#!/usr/bin/python
#Make a function count_vowels(s) that counts the number of vowels in a given string.

def count(word):
    count = 0
    for i in word:
        if(i=='a' or i=='e' or i=='i'or i=='o' or i=='u'):
            count+=1
    return count

word = input("Enter the word: ")

print(f"the number of vowel present in the {word} is {count(word)}")

