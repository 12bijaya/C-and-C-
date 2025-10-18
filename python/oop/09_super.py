# concept of super basically it is uesd to access the methods of parent class.

class cat:
    name = 'Kitty'
    def __init__(self):
        print('Hello Word!')
    def flag(self):
        print('flag{1c0n1c_th3_r3pp3r}')

class hi(cat):
    def __init__(self):
        super().flag()

ram = hi()


# Note: I learned that it is used inside the __init__()
