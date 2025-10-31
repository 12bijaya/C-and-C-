
a = 123456789
check = a
num = 0
_len=len(str(a))
i=0
while i!=_len:
    b=a%10
    num=num*10+b
    a//=10
    i+=1
print(num)

if(check==a):
    print('Pallydrom')
else:
    print("non Pallydrom")
