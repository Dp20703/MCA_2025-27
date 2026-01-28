import numpy as np
from scipy import stats # used for mode function

# Sample data
data = np.array([10, 20, 20, 30, 40, 40, 40, 50])

# Calculate mean
mean_value = np.mean(data)

# Calculate median
median_value = np.median(data)

# Calculate mode
mode_value=stats.mode(data)

# Display results
print("Data:", data)
print("Mean:", mean_value)
print("Median:", median_value)
print("Mode:", mode_value.mode)
print("Mode Count :", mode_value.count)

