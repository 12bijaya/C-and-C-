a=int(input("Enter the number in decimal "))
b=input("Enter into which number system you want to convert ")
b=b[:3:1].lower()
print(f"converting into {b}")
if(b=='hex'):
	print(hex(a))
elif(b=='bin'):
	print(bin(a))
elif(b=='oct'):
	print(oct(a))
else:
	print("invalid number system")
