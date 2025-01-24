 #WAP to check whether a number enter by the user is Prime or Not
a=int(input("Enter the number: "))
c=int(1+a/2)
b=False
count=0
for i in range(2,c):
	if(a%i==0):
		count+=1
		if(count==2):
			b=True
if(b):
	print("composite")
else:
	print("prime")
