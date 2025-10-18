# Use of del Keyword 
class cat: 
    def __init__(self,name):
        self.name = name
        print(self.name)

s1 = cat('iconic')
print(s1.name)
del s1.name
print('now the attribute is deleted')
