# in this we will define the dunder function 

user_choice = (input("Do you want to add or subtract two imaginary numbers? Y/N?: "))
user_choice = user_choice.upper()



class complex:
    def __init__(self,real,img):
        self.real = real
        self.img = img
    def printComplex(self):
        return f'{self.real}i + {self.img}j'
    def __add__(self,num1):
        new_real = self.real + num1.real
        new_img = self.img + num1.img
        return complex(new_real,new_img)
    def __sub__(self,num1):
        new_real = self.real + num1.real
        new_img = self.img + num1.img
        return complex(new_real,new_img)

if(user_choice=='Y'):
    pass
elif(user_choice=='N'):
    exit()
else:
    print('Invalid symbol')
    exit()

i = int(input("Enter the real part of your first imaginary number: "))
j = int(input("Enter the imaginary part of your first imaginary number: "))
num1 = complex(i,j)

i = int(input("Enter the real part of your second imaginary number: "))
j = int(input("Enter the imaginary part of your second imaginary number: "))
num2 = complex(i,j)

decision = input("Do you want to add or subtract the imaginary numbers. type (+) for add and (-) for subtract: ")

if (decision == '+'):
    num3 = num1+num2
elif(decision == '-'):
    num3 = num1-num2
else:
    print("Use the valid symbol")

print(f"The sum of {num1.printComplex()} and {num2.printComplex()} is {num3.printComplex()}")
