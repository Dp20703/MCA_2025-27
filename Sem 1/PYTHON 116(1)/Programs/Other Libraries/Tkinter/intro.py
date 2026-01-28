from tkinter import *
# create a label
# root=Tk()
# w=Label(root,text="Codewithdp")
# w.pack()
# root.mainloop()


# create a button
# r=Tk()
# r.title("Counting seconds ")
# button=Button(r,text='Stop',width=25,command=r.destroy)
# button.pack()
# r.mainloop()


# creates a form with two labeled input fields
master=Tk()
Label(master,text="First name ").grid(row=0)
Label(master,text="Last name ").grid(row=1)
e1=Entry(master)
e2=Entry(master)
e1.grid(row=0,column=1)
e2.grid(row=1,column=1)
mainloop()