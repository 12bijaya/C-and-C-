a=input("Enter the sentence: ")
a=a.split()
b=0
for i in a:
	if(len(i)>b):
		b=len(i)
print(f"the greates word is {i}")
