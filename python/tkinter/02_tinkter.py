# this will show you how to add the image 
from tkinter import *
root = Tk()

_image = PhotoImage(file="pictures/iconic.png")
image_label = Label(image=_image)
image_label.pack()
root.mainloop()
