import pandas as pd
import matplotlib.pyplot as plt

# Read the data from the CSV file
data = pd.read_csv('data/EWMA.csv')

# Calculate the upper and lower bounds


# Plot the stock values and weighted averages without markers
plt.figure(figsize=(10, 5))
plt.plot(data['Index'], data['Portfolio Value'], label='Portfolio Value', linewidth=2, color='orange')

# Add labels and legend
plt.xlabel('Index', fontsize=12)
plt.ylabel('Value', fontsize=12)
plt.title('Portfolio value', fontsize=14)
plt.legend(fontsize=12)

# Add a grid for better readability
plt.grid(True)

# Show the plot
plt.show()
