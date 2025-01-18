a=int(input("Enter the year"))
if a%4==0:
    if a%100==0:
        if a%400==0:
            print(f"{a} is leap year")
        else:
            print(f"{a} is not leap year")
    else:
        print(f"{a} is leap year")
else:
    print(f"{a} is not leap year")
    