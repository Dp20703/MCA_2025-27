import pandas as pd

# -----------------------------------------
# Create a DataFrame
# -----------------------------------------
data = {
    'Name': ['Amit', 'Darshan', 'Meera', 'Ravi', 'Neha'],
    'Age': [21, 25, 23, 22, 24],
    'Marks': [88, 92, 75, 85, 90],
    'City': ['Delhi', 'Ahmedabad', 'Surat', 'Mumbai', 'Pune']
}

df = pd.DataFrame(data)

print("Original DataFrame:")
print(df)

# -----------------------------------------
# View first and last few rows
# -----------------------------------------
print("\nHead (first 3 rows):")
print(df.head(3))

print("\nTail (last 2 rows):")
print(df.tail(2))

# -----------------------------------------
# Basic info about DataFrame
# -----------------------------------------
print("\nInfo:")
print(df.info())

print("\nDescribe (numerical summary):")
print(df.describe())

# -----------------------------------------
# Selecting a column
# -----------------------------------------
print("\nSelect Age column:")
print(df['Age'])

# Selecting multiple columns
print("\nSelect Name and Marks:")
print(df[['Name', 'Marks']])

# -----------------------------------------
# Row selection using loc and iloc
# -----------------------------------------
print("\nRow with index 2:")
print(df.loc[2])

print("\nRow selection using iloc (row 1 to 3):")
print(df.iloc[1:4])

# -----------------------------------------
# Filtering data
# -----------------------------------------
print("\nStudents with Marks > 85:")
print(df[df['Marks'] > 85])

# -----------------------------------------
# Adding new column
# -----------------------------------------
df['Grade'] = ['A', 'A+', 'B', 'A', 'A+']
print("\nAfter adding Grade column:")
print(df)

# -----------------------------------------
# Dropping a column
# -----------------------------------------
df2 = df.drop('City', axis=1)
print("\nAfter dropping City column:")
print(df2)

# -----------------------------------------
# Sorting
# -----------------------------------------
print("\nSorted by Age:")
print(df.sort_values(by='Age'))

# -----------------------------------------
# Groupby example
# -----------------------------------------
print("\nGroup by Grade (Average Marks):")
print(df.groupby('Grade')['Marks'].mean())

# -----------------------------------------
# Export to CSV
# -----------------------------------------
df.to_csv("students.csv", index=False)
print("\nData exported to 'students.csv'")
