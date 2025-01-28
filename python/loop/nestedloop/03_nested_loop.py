'''Let name=[“nispal”, “tilak”, “bharat”, “rijesh”, “soniya”]. Display the numbers of vowels in each 
name of the given list. Display message like :“nispal contains 2 vowels”'''

name=["nispal", "tilak", "bharat", "rijesh", "soniya"]
#count=0
vow="aeiou"
for i in name:
	count=0
	for j in i:
		if j in vow:
			count+=1
	print(f"{i} contains {count} vowels")
