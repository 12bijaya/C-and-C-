'''
Suppose you have a string str1=“ram123@baha23dur#”. WAP to copy the alphabet characters 
to another string str2, and numeric characters to another string str3. Finally display the contents 
of str2 and str3.
'''
str1="ram123@baha23dur#"
num=''
str=''
spc=''
for i in str1:
	if i.isalpha():
		str+=i
	elif i.isalnum():
		num+=i
	else:
		spc+=i	
print(f"The alphabet is {str} num is {num} and special character is {spc}")
