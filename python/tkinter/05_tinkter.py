# Adding the entry widgit
from tkinter import *

root = Tk()

listbox = Listbox(
    root,
    height = 6,
    width= 25,
    bg = "lightgray",
    fg = "blue",
    font=("Helvetica", 12)
)
listbox.pack(pady = 25)
for item in ["Assembly", "Python", "C", "C++", "Nix" "Java", "Go", "Rust"]:
    listbox.insert(END, item)
entry = Entry(
    root,
    width = 25
)
entry.pack(pady = 5)
root.mainloop()
