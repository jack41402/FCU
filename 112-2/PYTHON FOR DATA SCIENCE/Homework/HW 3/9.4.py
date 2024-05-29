# 9.4 (Class Average: Reading Student Records from a CSV File) Use the csv module to read the grades.csv file
# from the previous exercise. Display the data in tabular format.

import csv
from prettytable import PrettyTable


# Function to read CSV file and display data in tabular format
def display_csv_in_table(filename):
    # Create a PrettyTable object
    table = PrettyTable()

    with open(filename, newline='') as csvfile:
        reader = csv.reader(csvfile)

        # Extract and set the header row
        headers = next(reader)
        table.field_names = headers

        # Add rows to the table
        for row in reader:
            table.add_row(row)

    # Print the table
    print(table)


# Example usage
filename = 'grade.csv'
display_csv_in_table(filename)

