a=int(input("Enter your lottery number: "))
import random
a1=random.randint(1, 99)
if(a==a1):
	print("Congratulations you won the lottery ticket")
else:
	print("Oops you are so close...")
