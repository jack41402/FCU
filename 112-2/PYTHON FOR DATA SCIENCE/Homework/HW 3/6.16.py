# 6.16 (Intro to Data Science: Dynamic Visualization of the Dice Game of Craps) Reimplement your solution to
# Exercise 5.33, using the techniques you learned in Section 6.4.2 to create a dynamic bar chart showing the
# wins and losses on the first roll, second roll, third roll, etc.

# 5.33 (Intro to Data Science Challenge: Analyzing the Dice Game Craps) In this exercise,
# you’ll modify Chapter 4’s script that simulates the dice game craps by using the techniques
# you learned in Section 5.17.2. The script should receive a command-line argument indicating
# the number of games of craps to execute and use two lists to track the total numbers
# of games won and lost on the first roll, second roll, third roll, etc. Summarize the results
# as follows:
# a) Display a horizontal bar plot indicating how many games are won and how
# many are lost on the first roll, second roll, third roll, etc. Since the game could
# continue indefinitely, you might track wins and losses through the first dozen
# rolls (of a pair of dice), then maintain two counters that keep track of wins and
# losses after 12 rolls—no matter how long the game gets. Create separate bars
# for wins and losses.
# b) What are the chances of winning at craps? [Note: You should discover that craps
# is one of the fairest casino games. What do you suppose this means?]
# c) What is the mean for the length of a game of craps? The median? The mode?
# d) Do the chances of winning improve with the length of the game?

import matplotlib

matplotlib.use('TkAgg')  # Use 'TkAgg' or another suitable backend
import matplotlib.pyplot as plt
import seaborn as sns
import random
from matplotlib import animation


def roll_dice():
    """Roll two dice and return their face values as a tuple."""
    die1 = random.randrange(1, 7)
    die2 = random.randrange(1, 7)
    return die1, die2  # pack die face values into a tuple


def simulate_craps_game():
    """Simulate a single game of craps and return the result."""
    die_values = roll_dice()  # first roll
    sum_of_dice = sum(die_values)

    if sum_of_dice in (7, 11):  # win
        return 1, 0, 1  # win on first roll
    elif sum_of_dice in (2, 3, 12):  # lose
        return 0, 1, 1  # lose on first roll
    else:  # remember point
        my_point = sum_of_dice
        roll_count = 1
        while True:
            die_values = roll_dice()
            sum_of_dice = sum(die_values)
            roll_count += 1

            if sum_of_dice == my_point:  # win by making point
                return 1, 0, roll_count
            elif sum_of_dice == 7:  # lose by rolling 7
                return 0, 1, roll_count


def update(frame_number, rolls, faces, win_counts, loss_counts, games_reached_roll):
    """Update bar plot for each animation frame."""
    for _ in range(rolls):
        win, lose, roll_count = simulate_craps_game()
        index = roll_count - 1 if roll_count <= 12 else 12
        win_counts[index] += win
        loss_counts[index] += lose
        games_reached_roll[index] += 1

    plt.cla()  # clear old contents of current Figure
    sns.barplot(x=faces, y=win_counts, color='blue', label='Wins')
    sns.barplot(x=faces, y=loss_counts, bottom=win_counts, color='red', label='Losses')
    plt.title('Craps Game Outcomes per Roll')
    plt.xlabel('Roll Number')
    plt.ylabel('Count')
    plt.legend()


# Simulation parameters
number_of_games = 10000
number_of_frames = 13  # First 12 rolls plus cumulative
rolls_per_frame = number_of_games // number_of_frames

# Initialize counts
faces = list(range(1, 13)) + ['12+']
win_counts = [0] * 13
loss_counts = [0] * 13
games_reached_roll = [0] * 13

# Set up plot
sns.set_style('whitegrid')
figure = plt.figure('Craps Game Simulation')
plt.ion()  # Enable interactive mode

# Create animation
craps_animation = animation.FuncAnimation(figure, update, repeat=False, frames=number_of_frames, interval=500,
                                          fargs=(rolls_per_frame, faces, win_counts, loss_counts, games_reached_roll))

plt.show(block=True)  # Keep the window open
