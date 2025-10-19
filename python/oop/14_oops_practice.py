class Employee:
    def __init__(self,role,departmenet,salary):
        self.role = role
        self.department = departmenet
        self.salary = salary
    def showDetails(self):
        print(f"Role is {self.role}")
        print(f"Department is {self.department}")
        print(f"Salary is {self.salary}")

emply_01 = Employee("DevSecOps","Cyber Security", "5 lkh/month")
emply_01.showDetails()
class Engineer(Employee):
    def __init__(self,name,age):
        self.name = name
        self.age = age
        super().__init__("Engineer", "Civil", "2 lakh/mth")

er_01 = Engineer("ram",20)
er_01.showDetails()
