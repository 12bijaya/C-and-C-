a=input("Enter your string")
vow='aeiou'
j=0
for i in a:
	if a.isalpha()<10:
		num[j]=a[j]
	else:
		alpha[j]=a[j]
	if a.lower() in vow:
		break
	j+=1
print(num,alpha)
