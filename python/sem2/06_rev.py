'''
import os
_input = int(input("Enter the word: "))
os.system(f"echo {_input} | rev")
_input = int(input("Enter the word: "))

_len = len(_input)
word = ""
for i in range(_len-1,-1,-1):
    word+=_input[i]

print(word)
'''

a = 123456789
num=0
for i in range(len(str(a)):
    b=a%10
    num=num*10+b
    a//=b
print(num)

    
