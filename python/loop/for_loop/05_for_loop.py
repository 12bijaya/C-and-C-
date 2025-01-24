#Suppose you have a list of marks obtained by ten students as [60,67,45,87,90,78,84,38,13,56]
a=[60,67,45,87,90,78,84,38,13,56]
sum=0
# Find the number of students who scored 60 or more than 60, what will be the total sum of marks obtained by only these students?

for i in a:
	if(i>=60):
		sum+=i	
	elif(i==13):
		print("13 exists")
print(f"The required ans is: {sum}")

