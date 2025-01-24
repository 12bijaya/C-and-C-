a="aeiou"
b=input("ENter your string: ")
b=b.lower()
count=0
for i in b:
	if i in a:
		count+=1
print(f"the number of vowels is: {count}")
