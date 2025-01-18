a=int(input("Enter the 1st number "))
b=int(input("Enter the 2nd number "))
c=int(input("Enter the 3rd number "))
if(a>b and a>c):
    print(f"{a} is greatest")
elif(b>a and b>c):
    print(f"{b} is greatest")
elif(c>a and c>b):
    print(f"{c} is greatest")
else:
    print("Enter the 3 different numbers")