 
1. Create a data frame of the below table.

import pandas as pd 

data = {
    "Name": ["Mahesh", "Kiran", "Suresh", "Sumit", "Ramesh", "Sawpnil", "Swati"],
    "Age": [23, 25, 28, 26, 27, 30, 29],
    "Salary": [10000, 12000, 15000, 14000, 25000, 20000, 26000]
}

df = pd.DataFrame(data)

df

 
 2. Get the maximum values of salary from the data frame.

df['Salary'].max()

 
 3. Get the minimum values of the salary from the data frame.

df['Salary'].min()

 
 4. Write the statement which will sort the marks in the Data Frame, in descending order.

df.sort_values(by='Salary',ascending=False)

 
 5. Check the shape of data frame.

df.shape

 
 6. Add one row in the above data frame. (Name: Parita, Age: 32, Salary:25000)

df = pd.concat([df,pd.DataFrame([{"Name":"Parita","Age":32,"Salary":250000}])],ignore_index=True)

df 

 
# # 7. Check missing values

df.isnull() 

 
# # 8. Slice data from Suresh to Parita

df

df.iloc[2:7]

 
 9. Write a program to plot the ogive of random data from 1 to 20.

import numpy as np 
import matplotlib.pyplot as plt 

# Random data from 1 to 20
data = np.random.randint(1,21,20)
data

# Sort data 
data_sorted = np.sort(data)
data_sorted

# Cumulative frequency 
cf = np.arange(1,len(data_sorted)+1) 
cf

# Plot ogive 
plt.plot(data_sorted, cf,marker='o')
plt.xlabel("Data Values")
plt.ylabel("Cumulative Frequency")
plt.title("Ogive Curve")
plt.grid()
plt.show()

 
 10. Write a program to plot the area chart of the data from 1 to 30.

import numpy as np 
import matplotlib.pyplot as plt 

x = np.arange(1,31) 
y = np.random.randint(1,50,30)

plt.fill_between(x,y,color='skyblue',alpha=0.5)
plt.plot(x,y,color='blue',label='Data Line')
plt.xlabel("X Values")
plt.ylabel("Y Values")
plt.title("Area Chart")
plt.legend()
plt.show()

 
 11. Create the Data Frame of the below table.

import pandas as pd

data = {
    "Name": ["Ramesh", "Vedika", "Harun", "Prasad"],
    "Maths": [78, 76, 84, 67],
    "English": [67, 75, 59, 72],
    "Science": [56, 47, 60, 54]
}

df2 = pd.DataFrame(data)

df2

 
 12. Access the element in the 1st row in the 3rd column.

print(df2.iloc[0,2])

 
 13. Access all the element in 3rd column.

df2.iloc[:,2] 
# df2['English']

 
 14. Access elements of 2nd and 3rd row from 1st and 2nd column.

df2.iloc[1:3,0:2]

 
 15. Write a program to plot a pie chart of values=[3,4,7,9] and categories=[‘A’, ‘B’, ‘C’, ‘D’].

import matplotlib.pyplot as plt

# Data
values = [3, 4, 7, 9]
categories = ['A', 'B', 'C', 'D']

# Plot pie chart
plt.pie(values, labels=categories, autopct='%1.1f%%', explode=[0,0,0.1,0])

# Title
plt.title("Pie Chart Example")

# Show chart
plt.show()

 
 16. Create a Series from Dictionary. {‘India’:’New Delhi’, ‘UK’: ‘London’, ‘Japan’:’Tokyo’}

import pandas as pd

# Dictionary
data = {
    "India": "New Delhi",
    "UK": "London",
    "Japan": "Tokyo"
}

# Create Series
series = pd.Series(data)

series

 
 17. Create a Series from 10 to 20 values using numpy and index should be of alphabet.

import numpy as np
import pandas as pd

# Values from 10 to 20
values = np.arange(10, 21)

# Alphabet index (11 values → a to k)
index = list('abcdefghijk')

# Create Series
series = pd.Series(values, index=index)

print(series)

 
 18. Write the code for outlier removal from scratch.
# [ 4, 7, 10, 14, 36, 16, 18, 20, 67, 22, 2]

import numpy as np 
import pandas as pd

data = [4, 7, 10, 14, 36, 16, 18, 20, 67, 22, 2] 

data.sort()

Q1 = np.percentile(data, 25)
Q3 = np.percentile(data, 75)

IQR = Q3 - Q1 

lower_bound = Q1 - 1.5 * IQR 
upper_bound = Q3 + 1.5 * IQR

clean_data = []

for x in data:
    if lower_bound <= x <= upper_bound:
        clean_data.append(x)

print("Clean Data:", clean_data)

# whole code
import numpy as np

# Given data
data = [4, 7, 10, 14, 36, 16, 18, 20, 67, 22, 2]

# Step 1: Sort the data
data.sort()

# Step 2: Calculate Q1 and Q3
Q1 = np.percentile(data, 25)
Q3 = np.percentile(data, 75)

# Step 3: Calculate IQR
IQR = Q3 - Q1

# Step 4: Calculate lower and upper bounds
lower_bound = Q1 - 1.5 * IQR
upper_bound = Q3 + 1.5 * IQR

# Step 5: Remove outliers
clean_data = []

for x in data:
    if lower_bound <= x <= upper_bound:
        clean_data.append(x)

# Output results
print("Original Data:", data)
print("Q1:", Q1)
print("Q3:", Q3)
print("IQR:", IQR)
print("Lower Bound:", lower_bound)
print("Upper Bound:", upper_bound)
print("Data after removing outliers:", clean_data)

 
 19. Write the code of Finding Covariance from given data.
# X= [2, 4, 6, 8, 10] , Y= [1, 3, 5, 7, 9]

import numpy as np

# Given data
X = [2, 4, 6, 8, 10]
Y = [1, 3, 5, 7, 9]

# Step 1: Convert to numpy arrays
X = np.array(X)
Y = np.array(Y)

# Step 2: Calculate means
mean_X = np.mean(X)
mean_Y = np.mean(Y)

# Step 3: Calculate covariance (manual formula)
cov = np.sum((X - mean_X) * (Y - mean_Y)) / len(X)

# Output
print("Mean of X:", mean_X)
print("Mean of Y:", mean_Y)
print("Covariance:", cov)

# Direct method 
cov_matrix = np.cov(X, Y)
print(cov_matrix)

cov_matrix[0][1]

 
 20. Create a Data frame from Lists of Dictionary.

import pandas as pd
import numpy as np

data = [
    {"a": 10, "b": 20, "c": np.nan},
    {"a": 5, "b": 10, "c": 20}
]

df = pd.DataFrame(data)

df

 
 21. Create a Data frame from Dictionary of Lists.

import pandas as pd

data = {
    "State": ["Guj.", "Raj."],
    "Area": [50123, 69536],
    "Temp": [30, 35]
}

df = pd.DataFrame(data)

df

 
 22. Create a Data frame from Series.

import pandas as pd

series = pd.Series([1, 2, 3, 4, 5], index=["a", "b", "c", "d", "e"])

df = pd.DataFrame(series)

df

 
 23. Create a Data frame from Dictionary of Series.

import pandas as pd

data = {
    "Arnab": pd.Series([90, 91, 97], index=["Maths", "Science", "Hindi"]),
    "Ramit": pd.Series([92, 81, 96], index=["Maths", "Science", "Hindi"]),
    "Samridhi": pd.Series([89, 91, 88], index=["Maths", "Science", "Hindi"]),
    "Riya": pd.Series([81, 71, 67], index=["Maths", "Science", "Hindi"]),
    "Mallika": pd.Series([94, 95, 99], index=["Maths", "Science", "Hindi"])
}

df = pd.DataFrame(data)

df

 
 24. Do the following pre- processing techniques on the different 10 data sets.

 
# ### (a) Data Cleaning (Handling missing value for rows/columns, Handling Duplicates,Outliers detection and removal)

import pandas as pd 
import numpy as np 
from sklearn.preprocessing import StandardScaler,LabelEncoder ,normalize

df = pd.read_csv("sample_dataset.csv")
df.head()

df.isnull().sum()

 
# ###  (a) Data Cleaning 

# 1. Handling Missing Values

df["Age"].fillna(df["Age"].mean(), inplace=True)
df["Salary"].fillna(df["Salary"].median(), inplace=True)

# 2. Handling Duplicates
df.drop_duplicates(inplace=True)

# 3. Outlier Detection & Removal (IQR Method) 
Q1 = df['Salary'].quantile(0.25)
Q3 = df['Salary'].quantile(0.75)
IQR = Q3 - Q1 

lower = Q1 - 1.5 * IQR
upper = Q3 + 1.5 * IQR 

df = df[(df['Salary'] >= lower) & df['Salary'] <= upper ]

print("\nAfter Cleaning:\n", df.head())

 
# ### (b) Handling Categorical data

le = LabelEncoder()
df["City"] = le.fit_transform(df["City"])

print("\nAfter Encoding:\n")
df.head()

 
# ### (c) SCALING (Standardization)

scaler = StandardScaler()
df[["Age", "Salary"]] = scaler.fit_transform(df[["Age", "Salary"]])

print("\nAfter Scaling:\n")
df.head()

 
# ### (d) NORMALIZATION

df[['Age','Salary'] ]= normalize((df[['Age','Salary']]))

print("\nAfter Normalization:\n") 
df.head()

 
# ### (e) Identity insights which could be drawn from data and demonstrations of the same

print("\nStatistical Summary:\n", df.describe())

print("\nAverage Salary:", df["Salary"].mean())
print("Max Salary:", df["Salary"].max())
print("Min Salary:", df["Salary"].min())

print("\nCity-wise Salary Mean:\n")
df.groupby("City")["Salary"].mean()

 
# # Unit 2 Data Visualization
# (Qualitative and Quantitative data)

 
 1.Bar chart

 
# ### Example 1: Bar Chart (Student Marks)

import matplotlib.pyplot as plt 

# Data
students = ["A","B","C","D"]
marks = [70,85,60,90]

# Plot 
plt.bar(students,marks) 

# Labels
plt.xlabel("Students")
plt.ylabel("Marks")
plt.title("Student Marks Bar Chart")

plt.show()

 
# ### Example 2: Bar Chart (Cities - Population)

import matplotlib.pyplot as plt

cities = ["Ahmedabad", "Surat", "Rajkot", "Vadodara"]
population = [80, 60, 30, 40]

plt.bar(cities, population, color='green')

plt.xlabel("Cities")
plt.ylabel("Population (Lakhs)")
plt.title("City Population")

plt.show()

 
# ### Multiple Bar Chart

import numpy as np

students = ["A", "B", "C"]
maths = [70, 80, 90]
science = [60, 75, 85]

x = np.arange(len(students))

plt.bar(x - 0.2, maths, width=0.4, label="Maths")
plt.bar(x + 0.2, science, width=0.4, label="Science")

plt.xticks(x, students)
plt.legend()

plt.show()

 
 Pie chart 

import matplotlib.pyplot as plt 

values = [3, 4, 7, 9]
labels = ['A', 'B', 'C', 'D']

plt.pie(values,labels=labels,autopct="%1.1f%%",explode=[0,0,0,.1])
plt.title("Pie Chart with Percentage")
plt.show()

 
 Scatter plots

import matplotlib.pyplot as plt

# Data
x = [1, 2, 3, 4, 5]
y = [2, 4, 5, 4, 5]

plt.scatter(x,y,color="red")

plt.xlabel("X Values")
plt.ylabel("Y Values")
plt.title("Basic Scatter Plot")

plt.show()

 
 Line Chart 

import matplotlib.pyplot as plt

# Data
x = [1, 2, 3, 4, 5]
y = [10, 20, 15, 25, 30]

# Plot
plt.plot(x, y,linestyle="--",marker='o')

plt.xlabel("X Values")
plt.ylabel("Y Values",color='blue')
plt.title("Basic Line Chart")

plt.show()

 
 Area chart

import matplotlib.pyplot as plt

# Data
x = [1, 2, 3, 4, 5]
y = [10, 20, 15, 25, 30]

# Plot
plt.fill_between(x, y,color='skyblue',alpha=0.5)
plt.plot(x,y,color='blue')

# Labels 
plt.xlabel("X Values")
plt.ylabel("Y Values")
plt.title("Basic Area Chart")

plt.show()

 
 ogive

import numpy as np
import matplotlib.pyplot as plt

# Data
data = [5, 7, 9, 10, 12, 15, 18, 20]

# Sort data
data = np.sort(data)

# Cumulative frequency
cf = np.arange(1, len(data)+1)

# Plot ogive
plt.plot(data, cf, marker='o')

plt.xlabel("Data Values")
plt.ylabel("Cumulative Frequency")
plt.title("Ogive Curve")

plt.grid()
plt.show()

 
# # stem and leaf

data = [12, 15, 17, 21, 23, 25, 29]

# Sort data
data.sort()

stem_leaf = {}

for num in data:
    stem = num // 10
    leaf = num % 10
    
    if stem not in stem_leaf:
        stem_leaf[stem] = []
    
    stem_leaf[stem].append(leaf)

# Display
for stem, leaf in stem_leaf.items():
    print(stem, "|", *leaf)

 
 Dot Plot

import matplotlib.pyplot as plt
from collections import Counter

data = [1, 2, 2, 3, 3, 3, 4]

freq = Counter(data)

x = []
y = []

for value, count in freq.items():
    for i in range(count):
        x.append(value)
        y.append(i)

plt.scatter(x, y)

plt.xlabel("Values")
plt.ylabel("Frequency")
plt.title("Dot Plot")

plt.show()

 
 Histrogram

import matplotlib.pyplot as plt

data = [10, 20, 20, 30, 40, 40, 40, 50]

plt.hist(data,edgecolor='black')

plt.xlabel("Values")
plt.ylabel("Frequency")
plt.title("Basic Histogram")

plt.show()

 
# # Box Plot 

import matplotlib.pyplot as plt

data = [10, 20, 30, 40, 50, 100]

plt.boxplot(data)

plt.title("Box Plot Example")

plt.show()

 
# # Unit-3 Descriptive statistics

 
 Measures of location

# Mean → Average  
# Median → Middle  
# Mode → Most frequent  

 
# ### Mean 

import numpy as np 

data = [20,20,30,40,50]
mean = np.mean(data)
mean2 = sum(data)/len(data)

print(mean) 
print(mean2)

 
# ### Median 

import numpy as np 

data = [20,20,30,40,50]
median = np.median(data)

print(median)

 
# ### Mode 

from scipy import stats 

data = [20,20,20,30,40,50] 

mode = stats.mode(data) 

mode

 
 (From Scratch Code)

 
 1.Mean 

data = [10, 20, 30, 40, 50]

# Step 1: Sum
total = 0
for x in data:
    total += x

# Step 2: Count
n = len(data)

# Step 3: Mean
mean = total / n

print("Mean:", mean)

 
 2.Median 

data = [10, 20, 30, 40, 50]

# Step 1: Sort
data.sort()

n = len(data)

# Step 2: Find median
if n % 2 == 0:
    median = (data[n//2 - 1] + data[n//2]) / 2
else:
    median = data[n//2]

print("Median:", median)

 
 3.Mode 

data = [2, 3, 3, 4, 5]

# Count frequency
freq = {}

for x in data:
    if x in freq:
        freq[x] += 1
    else:
        freq[x] = 1

# Find max frequency
max_freq = max(freq.values())

# Find mode
mode = []

for key, value in freq.items():
    if value == max_freq:
        mode.append(key)

print("Mode:", mode)

 
 Measures of variability

# It shows how spread out the data is.

# Low variability → data close together
# High variability → data widely spread

 
 1. Range  
# ### Range = Max - Min 

data = [10, 20, 30, 40, 50] 

range_val = max(data) - min(data)
range_val

 
 2. Variance 

data = [10, 20, 30, 40, 50]

# Mean
mean = sum(data) / len(data)

# Variance
total = 0
for x in data:
    total += (x - mean) ** 2

variance = total / len(data)

print("Variance:", variance)

 
 3. Standard Deviation

import math

sd = math.sqrt(variance)

print("Standard Deviation:", sd)

 
 4.Interquartile Range (IQR)

data = [10, 20, 30, 40, 50]

data.sort()

n = len(data)

Q1 = data[n//4]
Q3 = data[(3*n)//4]

iqr = Q3 - Q1

print("IQR:", iqr)

 
# # Measures of association between two variables

 
 1.Covariance

X = [2, 4, 6, 8, 10]
Y = [1, 3, 5, 7, 9]

# Means
mean_X = sum(X) / len(X)
mean_Y = sum(Y) / len(Y)

# Covariance
cov = 0
for i in range(len(X)):
    cov += (X[i] - mean_X) * (Y[i] - mean_Y)

cov = cov / len(X)

print("Covariance:", cov)

 
 2.Correlation

import math

X = [2, 4, 6, 8, 10]
Y = [1, 3, 5, 7, 9]

mean_X = sum(X) / len(X)
mean_Y = sum(Y) / len(Y)

# Covariance
cov = 0
for i in range(len(X)):
    cov += (X[i] - mean_X) * (Y[i] - mean_Y)
cov = cov / len(X)

# Standard deviations
var_X = sum((x - mean_X)**2 for x in X) / len(X)
var_Y = sum((y - mean_Y)**2 for y in Y) / len(Y)

sd_X = math.sqrt(var_X)
sd_Y = math.sqrt(var_Y)

# Correlation
r = cov / (sd_X * sd_Y)

print("Correlation:", r)

 
# # Measures of distribution

 
 1.Skewness

# Skewness ~~ ( Mean - Median ) / Standard Deviation

data = [10, 20, 30, 40, 100] 

# Mean 
mean = sum(data) / len(data) 

# Median 
data.sort()

n = len(data)

if n % 2 == 0:
    median = (data[n//2 - 1] + data[n//2]) / 2
else:
    median = data[n//2]

# Standard Deviation 
import math
variance = sum((x - mean)**2 for x in data) / len(data)
sd = math.sqrt(variance)

skewness = ( mean - median ) / sd 
print("Skewness:", skewness)

 
 2. Kurtosis

 
# ### Using Library

from scipy.stats import kurtosis

data = [10, 20, 30, 40, 50]

print("Kurtosis:", kurtosis(data))

 
# ### From Scratch

import math

# Data
data = [10, 20, 30, 40, 50]

n = len(data)

# Step 1: Mean
mean = sum(data) / n

# Step 2: Variance
variance = sum((x - mean)**2 for x in data) / n

# Step 3: Standard Deviation
sd = math.sqrt(variance)

# Step 4: Kurtosis
kurt = sum((x - mean)**4 for x in data) / (n * (sd**4))

print("Kurtosis:", kurt)

excess_kurt = kurt - 3
print("Excess Kurtosis:", excess_kurt)




