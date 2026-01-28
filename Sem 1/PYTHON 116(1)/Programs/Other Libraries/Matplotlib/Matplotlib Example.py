import matplotlib.pyplot as plt
import numpy as np

# Sample data
x = np.linspace(0, 10, 50)
y = np.sin(x)
y2 = np.cos(x)

# 1. Line Graph
plt.figure()
plt.plot(x, y)
plt.title("Line Graph - Sine Wave")
plt.xlabel("X-axis")
plt.ylabel("sin(x)")
plt.grid(True)
plt.show()

# 2. Bar Graph
languages = ['Python', 'Java', 'C++', 'JavaScript']
popularity = [85, 75, 65, 90]

plt.figure()
plt.bar(languages, popularity)
plt.title("Bar Graph - Language Popularity")
plt.xlabel("Languages")
plt.ylabel("Popularity")
plt.show()

# 3. Scatter Plot
x_scatter = np.random.rand(50)
y_scatter = np.random.rand(50)

plt.figure()
plt.scatter(x_scatter, y_scatter)
plt.title("Scatter Plot")
plt.xlabel("X values")
plt.ylabel("Y values")
plt.show()

# 4. Histogram
data = np.random.randn(500)

plt.figure()
plt.hist(data, bins=20)
plt.title("Histogram")
plt.xlabel("Value")
plt.ylabel("Frequency")
plt.show()

# 5. Pie Chart
sizes = [25, 35, 20, 20]
labels = ['A', 'B', 'C', 'D']

plt.figure()
plt.pie(sizes, labels=labels, autopct='%1.1f%%')
plt.title("Pie Chart")
plt.show()

# 6. Multiple Lines in One Plot
plt.figure()
plt.plot(x, y, label='sin(x)')
plt.plot(x, y2, label='cos(x)')
plt.title("Multiple Line Graph")
plt.xlabel("X-axis")
plt.ylabel("Values")
plt.legend()
plt.grid(True)
plt.show()
