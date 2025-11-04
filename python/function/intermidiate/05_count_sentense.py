#!/usr/bin/python
#➤ Write a function word_count(sentence) that returns the total number of words in a sentence.
sentence = "Sirjal is sirjal who am i"
def word_count(sentence):
    count = len(sentence.split())
    return count
print(f"The number of word in sentence is: {word_count(sentence)}")
