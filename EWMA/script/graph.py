import pandas as pd
import matplotlib.pyplot as plt

# Read the data from the CSV file
data = pd.read_csv('data/output.csv')

# Calculate the upper and lower bounds
data['Upper Bound'] = data['Weighted Average'] + data['Sigma']
data['Lower Bound'] = data['Weighted Average'] - data['Sigma']

# Plot the stock values and weighted averages without markers
plt.figure(figsize=(10, 5))
plt.plot(data['Index'], data['Stock Value'], label='Stock Value', linewidth=2, color='blue')
plt.plot(data['Index'], data['Weighted Average'], label='Weighted Average', linewidth=2, color='red')
plt.plot(data['Index'], data['Upper Bound'], label='Weighted Average + Sigma', linewidth=1, linestyle='--', color='green')
plt.plot(data['Index'], data['Lower Bound'], label='Weighted Average - Sigma', linewidth=1, linestyle='--', color='purple')

# Add labels and legend
plt.xlabel('Index', fontsize=12)
plt.ylabel('Value', fontsize=12)
plt.title('Stock Value and Weighted Average with Sigma Bounds', fontsize=14)
plt.legend(fontsize=12)

# Add a grid for better readability
plt.grid(True)

# Show the plot
plt.show()
