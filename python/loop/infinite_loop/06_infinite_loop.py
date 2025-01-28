''' WAP that asks the user to enter a number one at a time until the user hits exactly zero (0). 
Display the sum of all the numbers that were entered by the user before hitting zero.'''
sum=0
a=1
while a!=0:
	a=int(input("Enter a number: "))
	sum+=a
print(f"The sum is {sum}")
