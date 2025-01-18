a=int(input("Enter the number "))
if(a%5==0):
    if(a%7==0):
        print(f"{a} is divisible by 5 and 7")
    else:
        print(f"{a} is divisible by 5 but not by 7")
else:
    if(a%7==0):
        print(f"{a} is divisible by 7 but not by 5")
    else:
        print(f"{a} is not divisible by 5 and 7")