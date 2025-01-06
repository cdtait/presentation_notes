import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV file
data = pd.read_csv("comp_freqs.csv")

# Aggregate revision counts per module/file
revision_counts = data.groupby('module')['revisions'].sum()

# Sort the revisions in descending order
sorted_revisions = revision_counts.sort_values(ascending=False).reset_index(drop=True)

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(sorted_revisions.index + 1, sorted_revisions.values, marker='o', linestyle='-', color='b')
#plt.xscale('log')  # Optional: Log scale for X-axis to enhance the power-law appearance
#plt.yscale('log')  # Optional: Log scale for Y-axis

# Customize the plot
plt.title("Revisions per File (Descending Order)")
plt.xlabel("File Number (Sorted by Revisions)")
plt.ylabel("Number of Revisions")
plt.grid(True, which="both", linestyle="--", linewidth=0.5)

# Show the plot
plt.show()

