from tkinter import *

root = Tk()
root.title("Listbox Parameters Demo")

listbox = Listbox(
    root,
    height=6,
    width=25,
    selectmode=EXTENDED,
    bg="lightgray",
    fg="blue",
    font=("Helvetica", 12),
    selectbackground="darkblue",
    selectforeground="white"
)
listbox.pack(pady=20)

for item in ["Assembly", "Python", "C", "C++", "Nix" "Java", "Go", "Rust"]:
    listbox.insert(END, item)

root.mainloop()

