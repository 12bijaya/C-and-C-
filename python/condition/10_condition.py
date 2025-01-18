a=input("Enter the character ")
if(a>='a' and a<='z' or a>='A' and a<='Z'):
    print(f"{a} is alphabet")
elif(a>='0' and a<='9'):
    print(f"{a} is digit")
else:
    print(f"{a} is special character")