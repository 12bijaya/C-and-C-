a=input("Enter the month   ")
a=a[0:3:1].lower()
if a == "jun" or a == "jul" or a == "aug":
    print("Summer")
elif a == "jan" or a == "feb" or a == "dec":
    print("Winter")
elif a == "mar" or a == "apr" or a == "may":
    print("Spring")
else:
    print("Autumn")