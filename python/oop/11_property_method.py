class student:
    def __init__(self, marks):
        self.phy = marks[0]
        self.chem = marks[1]
        self.math = marks[2]
    @property
    def average(self):
        return str((self.phy+self.chem+self.math)/3)
marks=[]
marks.append(int(input('Enter your marks in phytics: ')))
marks.append(int(input('Enter your marks in chemistry: ')))
marks.append(int(input('Enter your marks in math: ')))

student = student(marks)
print(f'Your average marks is: {student.average}')
