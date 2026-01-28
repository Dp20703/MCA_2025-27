source_path=r"C:\Users\Darshan\Pictures\Screenshots\Screenshot 2025-10-04 105906.png"
destination_path=r"C:\Users\Darshan\Downloads\copy_image.png"

with open(source_path,"rb") as src:
    with open(destination_path,"wb") as dest:
        dest.write(src.read())

print("Image copied successfully")
