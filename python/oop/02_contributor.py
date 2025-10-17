class cat:
    def __init__(self, name):
        print('Wow what a cute name')
        cat.name = name

name = input('Enter your cat name: ')
cat_name = cat(name)
print(f'lovely name {cat.name}')
