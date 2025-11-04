#!/usr/bin/python
#Write a function is_prime(n) that determines whether a number is prime or not.
def is_prime(n):
    count=0
    for i in range(1,n):
        if n%i==0:
            count+=1
        if count==2:
            return 0
    return 1

a = int(input("Enter the number: "))
if is_prime(a):
    print(f"{a} is prime")
else:
    print(f"{a} is composite")
