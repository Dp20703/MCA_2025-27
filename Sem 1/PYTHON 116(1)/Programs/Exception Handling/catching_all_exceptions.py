try:
   x=int(input("Enter a number:"))
   y=10/x
except Exception as e:
    print("Error occurred:", e)