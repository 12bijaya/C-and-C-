a=int(input("Enter the number to check: "))
sum = 0
a=str(a)
for i in a:
	sum += int(i) ** len(a)
if int(a)==sum:
	print("amstrong")
else:
	print("not a armstrong")
