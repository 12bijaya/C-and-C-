print("Declare the geometric figure")
a=input("write 'c' for circle 's' for square and 'r' for rectangle: ")
print("!--------------------------------------------------!")
a=a.lower()
if a=="c":
    r=float(input("Enter the radius of the circle: "))
    print(f"The area of the circle is {3.14*r*r}")
elif a=="s":
    s=float(input("Enter the side of the square: "))
    print(f"The area of the square is {s*s}")
elif a=="r":
    l=float(input("Enter the length of the rectangle: "))
    b=float(input("Enter the breadth of the rectangle: "))
    print(f"The area of the rectangle is {l*b}")
else:
    print("Invalid input")