# private attributes and methods to make anythong private in the class just use __ infront of the private attributes in the class. 
#Let's see the example ok 

class cat:
    __name = 'Iconic_The_Ripper'
    name = 'Iconic_The_Ripper'

    def __private_method(self):
        print(self.__name)

    @staticmethod
    def public_method():
        print(cat.name)

ca = cat()
ca.public_method()
