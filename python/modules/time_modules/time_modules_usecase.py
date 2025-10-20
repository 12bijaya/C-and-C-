from time import *

time = time()
print('Time function calculate the time in second till now from the epoch')
print(time)

print("code is hanging for 2 second....")
sleep(2)
print('sleep function will wait for the certain seconds..')


time = ctime()
print("ctime function is that which show time in human readable form..")
print(time)


time = gmtime()
print("gmtime will show change the time into a fine structure..: \nNote: It will represent time in UTC")
print(time)

time = localtime()
print("This will print the local time of the system..")
print(time)


print(localtime("%Y/%m/%d %H-%M-%S"))
