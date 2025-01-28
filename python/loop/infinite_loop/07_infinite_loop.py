''' WAP that asks  the user to enter an integer number one at a time until the user hits fifth even 
number, note that the user can hit even or odd numbers randomly.  Display the total sum of those 
f
 ive even numbers at last. '''
count=0
sum=0
while 1:
	a=int(input("enter the number: "))
	if a%2==0:
		count+=1
		sum+=a
	if count==5:
		print(f"sum is {sum}")
		break
