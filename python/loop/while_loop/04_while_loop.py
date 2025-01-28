'''WAP to display  and count the numbers of vowels in a string entered by the user(using for loop).
 and count the number of consonant letters using while loop.'''
a=input("Enter the string: ")
i=0
a=a.lower()
b="aeiou"
count=0
while i < len(a):
	if a[i] in b:
		count+=1
	i+=1
print(count)

