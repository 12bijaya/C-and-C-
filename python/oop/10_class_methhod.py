# class method is used to change the attribute of the class itself and it's usage is shown below 

class cat:
    name = 'Kitty'

    def cat_name(self,name):
        self.__class__.name = name
        print(f"hi {cat.name}")

name = input('Enter your cat name: ')
cat = cat()
cat.cat_name(name)
