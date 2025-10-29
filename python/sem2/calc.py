i = input("Enter (+),(-),(*),(/)")
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
if(i == '+'):
    print(f"{a}+{b}={a+b}")
elif(i == '-'):
     print(f"{a}-{b}={a-b}")
elif(i == '*' ):
    print(f"{a}*{b}={a*b}")
elif(i == "/"):
     print(f"{a}/{b}={a/b}")
else:
    print('Error 404 sign not found')
