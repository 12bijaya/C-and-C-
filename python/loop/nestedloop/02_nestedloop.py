'''. WAP to take a number ’n’ from user. And display the multiplication table of all numbers from 1 
to n  side by side.'''
n=int(input("Enter the number: "))
for i in range(n,0,-1):
	for j in range(1,11):
		print(f"{i} * {j} = {i*j}")
	print("\n")
