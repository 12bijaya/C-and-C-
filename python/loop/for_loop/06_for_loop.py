#WAP to find the sum of all the digits of a number enter by the user (23189 ==> 2+3+1+8+9 ==> 23)
a=input("Enter the number: ")
sum=0
for i in a:
	sum+=int(i);
print(sum)
