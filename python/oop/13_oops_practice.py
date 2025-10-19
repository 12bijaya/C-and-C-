class Circle:
    def __init__(self, radius):
        self.radius = radius
    def area(self):
        return 3.14*pow(self.radius,2)
    def perimeter(self):
        return 2*3.14*self.radius

r = int(input("Enter your radius: "))
circle = Circle(r)
print(f'Area of circle is {circle.area()} and perimeter is {circle.perimeter()}')

