#2. WAP to take a number 'n' as input, find and display the factorial of 'n'.
n = int(input("Enter the number: "))
i = 1
fact = 1
while (i<=n):
	fact*=i
	i+=1
print(f"The factorial of {n} is {fact}")
