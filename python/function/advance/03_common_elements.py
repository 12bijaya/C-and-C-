#!/usr/bin/python
#➤ Write a function common_elements(list1, list2) that returns a list of common values.
list1 = [1,3,'cat',5,'sirjal']
list2 = [2,3,'sirjal']

def common_elements(list1, list2):
    return list(set(list1) & set(list2))

print(f"The common_elements in {list1} and {list2} is {common_elements(list1, list2)}")
