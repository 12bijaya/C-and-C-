a=int(input("Enter the first side of traingle "))
b=int(input("Enter the second side of traingle "))
c=int(input("Enter the third side of traingle "))
if(a+b<=c or b+c<=a or c+a<=b):
    print("Traingle is not possible")
    import sys
    sys.exit(0)
if(a==b and b==c):
    print("Equilateral traingle")
elif(a==b or b==c or c==a):
    print("Isosceles traingle")
else:
    print("Scalene traingle")
