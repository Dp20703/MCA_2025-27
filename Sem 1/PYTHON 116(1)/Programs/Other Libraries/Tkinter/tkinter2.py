import tkinter as tk
from tkinter import messagebox

# -------------------------------
# Function Definitions
# -------------------------------

def show_message():
    user_text = entry.get()
    if user_text.strip() == "":
        messagebox.showwarning("Warning", "Please enter some text!")
    else:
        messagebox.showinfo("Message", f"You entered: {user_text}")

def change_label_color():
    label.config(fg="blue")  # change label text color

def clear_entry():
    entry.delete(0, tk.END)

# -------------------------------
# Main Window
# -------------------------------

root = tk.Tk()
root.title("Basic Tkinter Operations")
root.geometry("350x250")
root.configure(bg="lightyellow")

# -------------------------------
# Widgets
# -------------------------------

label = tk.Label(root, text="Enter Something:", font=("Arial", 12), bg="lightyellow")
label.pack(pady=10)

entry = tk.Entry(root, width=30, font=("Arial", 12))
entry.pack(pady=5)

# Button frame using grid layout
button_frame = tk.Frame(root, bg="lightyellow")
button_frame.pack(pady=15)

btn_show = tk.Button(button_frame, text="Show Message", command=show_message, width=12)
btn_show.grid(row=0, column=0, padx=5)

btn_color = tk.Button(button_frame, text="Color Label", command=change_label_color, width=12)
btn_color.grid(row=0, column=1, padx=5)

btn_clear = tk.Button(button_frame, text="Clear", command=clear_entry, width=12)
btn_clear.grid(row=1, column=0, columnspan=2, pady=10)

# Exit button
btn_exit = tk.Button(root, text="Exit", command=root.quit, width=12, bg="lightcoral")
btn_exit.pack(pady=5)

# -------------------------------
# Run the window
# -------------------------------
root.mainloop()