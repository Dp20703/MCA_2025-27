import tkinter as tk

# Create the main window
root = tk.Tk()
root.title("My First Tkinter App")
root.geometry("300x200") # Set window size

# Create a label widget
label = tk.Label(root, text="Hello, Tkinter!")
label.pack(pady=20) # Add padding

# Create a button widget
def on_button_click():
    label.config(text="Button Clicked!")

button = tk.Button(root, text="Click Me", command=on_button_click)
button.pack()

# Start the main event loop
root.mainloop()