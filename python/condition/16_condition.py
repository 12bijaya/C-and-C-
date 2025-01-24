print("Enter 'S' for scissor , 'R' for rock and 'P' for paper")
a1=input("Enter the input of user 1: ")
a2=input("Enter the input of user 2: ")
a1=a1.upper()
a2=a2.upper()
if(a1=='S' and a2=='R' or a1=='R' and a2=='P' or a1=='P' and a2=='S'):
	print('user2 is winner')
else:
	print("user1 is winner")
