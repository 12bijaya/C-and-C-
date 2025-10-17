# Create Accout class with 2 attributes - balance and account no.
# Create method for debit , credit and printing the balance.

class account:
    def __init__(self, balance, account_no):
        self.balance = balance
        self.account_no = account_no
        print(f'Current balance in {account_no}: {balance}')

    def debit(self, amount):
        a = self.balance - amount
        self.balance = a
        if(self.balance>0):
            print(f'You have debited {amount}')
            print(f'Current balance in account is: {self.balance}')
        else:
            print('Failed! Insuffient amount')

    def credit(self, amount):
        self.balance+=amount
        print(f'Congratulation your account was credited {amount}')
        print(f'Current balance is {self.balance}')


balance = 1400000
acount_no = 12355587988
acnt = account(balance,acount_no)
print('Do you wanna credit or debit on your account? press "D" for debit and "C" for credit. ')
a = input()
a = a.upper()

if(a=='D'):
    amount = int(input('Enter the amount: '))
    acnt.debit(amount)
elif(a=='C'):
    amount = int(input('Enter the amount: '))
    acnt.credit(amount)
else:
    print('Thanks for visiting.....')        

