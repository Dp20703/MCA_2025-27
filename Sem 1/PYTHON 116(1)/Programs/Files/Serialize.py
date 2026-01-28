import pickle

class Student:
    def __init__(self,name,age):
        self.name=name
        self.age=age
        
    def display(self):
        print("name:",self.name)
        print("age:",self.age)

# save students
def save_students(students,filename):
    with open (filename,'wb') as file:
        pickle.dump(students,file)
        print("Saved students successfully")

# read students
def read_students(filename):
    with open(filename,'rb') as file:
     students= pickle.load(file)
     return students
    
# main
if __name__=='__main__':
    s1=Student('dp',24)
    s2=Student('yash',25)
    students=[s1,s2]
    save_students(students,'Student.dat')
    students=read_students('Student.dat')
    for stud in students:
        stud.display()
