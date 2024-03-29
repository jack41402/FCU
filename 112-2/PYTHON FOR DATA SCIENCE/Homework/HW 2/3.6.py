# 3.6 (Turing Test)Create a script that plays the part of the independent computer, giving its user a simple medical
# diagnosis. The script should prompt the user with 'What is your problem?' When the user answers and presses Enter,
# the script should simply ignore the user’s input, then prompt the user again with 'Have you had this problem before
# (yes or no)?' If the user enters 'yes', print 'Well, you have it again.' If the user answers 'no', print 'Well,
# you have it now.' Would this conversation convince the user that the entity at the other end exhibited intelligent
# behavior? Why or why not?

# ANSWER
# The scripted conversation mimics interaction but lacks true intelligence. It follows predefined rules
# without understanding or adapting to user input. Without contextual understanding or meaningful dialogue,
# it fails to convincingly exhibit genuine intelligence, remaining predictable and limited in its responses.

input("What is your problem? ")
answer = input("Have you had this problem before(yes or no)? ")
answer = answer.lower()
if answer == "y":
    answer = "yes"
elif answer == "n":
    answer = "no"
if answer == "yes":
    print("Well, you have it again.")
elif answer == "no":
    print("Well, you have it now.")
else:
    print("Sorry, you have to answer yes or no.")
