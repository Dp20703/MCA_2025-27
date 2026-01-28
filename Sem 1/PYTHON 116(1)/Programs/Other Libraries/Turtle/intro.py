# from turtle import *
import turtle

# wn=turtle.Screen()
# wn.bgcolor("light green")
# wn.title("Turtle")
# skk=turtle.Turtle()

# skk.forward(100)
# turtle.done()

# Shape 1: Square
# skk=turtle.Turtle()
# for i in range(4):
#     skk.forward(50)
#     skk.right(90)

# turtle.done()


# Python program to draw 
# Rainbow Benzene
# using Turtle Programming
import turtle
colors = ['red', 'purple', 'blue', 'green', 'orange', 'yellow']
t = turtle.Pen()
turtle.bgcolor('black')
for x in range(360):
    t.pencolor(colors[x%6])
    t.width(x//100 + 1)
    t.forward(x)
    t.left(59)