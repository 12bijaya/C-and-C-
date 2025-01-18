a=int(input("Enter the 1st number "))
b=int(input("Enter the 2nd number "))
c=int(input("Enter the 3rd number "))
if(a<b):
    if(a<c):
        print(f"{a} is smallest")
    else:
        print(f"{c} is smallest")
elif(b<c):
    if(b<a):
        print(f"{b} is smallest")
    else:
        print(f"{a} is smallest")
else:
    print(f"{c} is smallest")