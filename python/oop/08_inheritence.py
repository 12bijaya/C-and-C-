#This will cover the concept of inheritence.

# Single inheritence
class cat:
    name = "Kitty"

class iconic(cat):
    def __init__(self):
        print(f"This is single inheritence because one parent class cat has it's only one child class which is iconic()")

single = iconic
print(f"Iconic's name is: {single.name}")


# Multiple level inheritence since I am lazy programmer I am gonna use the above one class hehe 

class ram(cat):
    king = 'ram'
    def __init__(self):
        print("This is multi level inheritence since one parent class cat will gonna have it many sub class on different level like grand child")

class sita(ram):
    queen = 'sita'
    def __init__(self):
        print("Multi level Inheritence:")

friend = sita()
ram()
print(f'Iconic cat name is: {friend.name}')

# Multiple inheritence this is gonna that because it will gonna have multiple parents

class multiple(sita, ram):
    def __init__(self):
        print("This is gonna mulltiple inheritence because same child will gonna have many parents and vice versa")
        
last = multiple()
print(f"King is: {ram.king}\nQueen is: {sita.queen}")
