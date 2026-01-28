import turtle

# Create screen
screen = turtle.Screen()
screen.bgcolor("lightyellow")   # background color

# Create turtle object
t = turtle.Turtle()
t.speed(3)   # drawing speed

# -------------------------
# Draw a filled square
# -------------------------
t.color("blue", "cyan")    # (border color, fill color)
t.begin_fill()

for _ in range(4):
    t.forward(100)
    t.right(90)

t.end_fill()

# Move turtle
t.penup()
t.goto(-150, 0)
t.pendown()

# -------------------------
# Draw a filled triangle
# -------------------------
t.color("red", "pink")
t.begin_fill()

for _ in range(3):
    t.forward(120)
    t.left(120)

t.end_fill()

# Move turtle
t.penup()
t.goto(150, 0)
t.pendown()

# -------------------------
# Draw a filled circle
# -------------------------
t.color("green", "lightgreen")
t.begin_fill()
t.circle(60)
t.end_fill()

t.hideturtle()

# Keep window open
turtle.done()