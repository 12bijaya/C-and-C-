a=int(input("Enter 1 to change celcius to fahrenheit or 2 to change fahrenheit to celcius "))
if a==1:
    c=int(input("Enter the temperature in celcius "))
    f=(c*9/5)+32
    print(f"The temperature in fahrenheit is {f}")
elif a==2:
    f=int(input("Enter the temperature in fahrenheit "))
    c=(f-32)*5/9
    print(f"The temperature in celcius is {c}")
else:
    print("Enter 1 or 2")