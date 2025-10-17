#create student class that takes name & marks of 3 students as argument in cronstructor and print the average.
class marks:
    def __init__(self,name,subject):
        
        self.name = name
        self.subject = subject

    def average(self):
        sum = 0
        i = 0
        for subjects in subject:
            mark = float(input(f'Enter the marks in {subjects}: '))
            i+=1
            sum += mark
        return sum/len(subject)


class printer:
    def __init__(self,mark):
        name = mark.name
        average = mark.average()
        print(f'Congratulation {name} your average marks is: {average:.2f}')

student_number = int(input('Enter the number of students: '))
for i in range(0,student_number):
    name = input('Enter the student name: ')
    subject = ["math", "physics", "chemistry"]
    mark = marks(name,subject) 
    message = printer(mark)

