#1. WAP to find the sum of first 'n' natural numbers. take 'n' as input
n = int(input("Enter the number: "))
sum=0
i=1
while (i<=n):
	sum+=i
	i+=1
print(f"The sum of first {n} number is {sum}")
