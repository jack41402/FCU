# 8.6 (Tokenizing and Comparing Strings) Write a script that reads a line of text, tokenizes it using space characters
# as delimiters and outputs only those words ending with the letters 'ed'.

import re

text = "The tired, excited children played in the fenced yard."

# Use regular expression to remove punctuation from each word
text = re.sub(r'[^\w\s]', ' ', text)
words = text.split()  # Tokenize the text using space as delimiter
print(words)
result = [word for word in words if word.lower().endswith('ed')]  # Filter words ending with 'ed'

print("Words ending with 'ed':", result)
