#WAP to display multiplication of a number in reverse order (i.e. 5*10=50 first and 5*1 =5 in last)
a=int(input("Enter the number you want to find the multiplication table"))
for i in range(10,0,-1):
	print(f"{a} * {i} = {i*a}")
