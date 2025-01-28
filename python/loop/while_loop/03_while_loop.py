#3. WAP to display multiplication of a number in reverse order (i.e. 5*10=50 first and 5*1 =5 in last)
n = int(input("Enter the number you want to find the multiplication in reverse order: "))
i=10
while (i>=1):
	print(f"{n} * {i} = {n*i}")
	print()
	i-=1

