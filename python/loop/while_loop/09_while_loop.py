n=int(input("Enter the number: "))
b=len(str(n))
b=int(n)
arm=0
while (n>0):
	arm+=n//10**b
	n//=10
if (arm==b):
	print("armstrong")
else:
	print("not a armstrong")
