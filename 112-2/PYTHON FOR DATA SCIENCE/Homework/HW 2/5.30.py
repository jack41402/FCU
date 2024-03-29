# 5.30 (Intro to Data Science: Removing the Text Above the Bars) Modify the die-rolling simulation in Section 5.17.2
# to omit displaying the frequencies and percentages above each bar. Try to minimize the number of lines of code.

import matplotlib.pyplot as plt
import numpy as np
import random
import seaborn as sns

# Rolling the Die and Calculating Die Frequencies
rolls = [random.randrange(1, 7) for i in range(600)]
values, frequencies = np.unique(rolls, return_counts=True)

# Creating the Initial Bar Plot
title = f'Rolling a Six-Sided Die {len(rolls):,} Times'
sns.set_style('whitegrid')
axes = sns.barplot(x=values, y=frequencies, palette='bright', hue=values, dodge=False, legend=False)

# Setting the Window Title and Labeling the x- and y-Axes
axes.set_title(title)
axes.set(xlabel='Die Value', ylabel='Frequency')

# Finalizing the Bar Plot
axes.set_ylim(top=max(frequencies) * 1.10)
plt.show()
