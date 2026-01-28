# Parent class 1
class Father:
    def father_info(self):
        print("This is Father class.")

# Parent class 2
class Mother:
    def mother_info(self):
        print("This is Mother class.")

# Child class inheriting from both Father and Mother
class Child(Father, Mother):
    def child_info(self):
        print("This is Child class.")


# Creating object of Child class
c = Child()

# Calling methods from both parent classes
c.father_info()
c.mother_info()
c.child_info()
