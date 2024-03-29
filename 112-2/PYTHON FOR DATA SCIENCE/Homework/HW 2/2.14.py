# 2.14 (Target Heart-Rate Calculator) While exercising, you can use a heart-rate monitor to see that your heart rate
# stays within a safe range suggested by your doctors and trainers. According to the American Heart Association (AHA)
# (http://bit.ly/AHATargetHeart%02Rates), the formula for calculating your maximum heart rate in beats per minute is
# 220 minus your age in years. Your target heart rate is 50–85% of your maximum heart rate. Write a script that
# prompts for and inputs the user’s age and calculates and displays the user’s maximum heart rate and the range of
# the user’s target heart rate.

years = int(input("Enter years: "))
maximum = 220 - years
target = [maximum*0.5, maximum*0.85]
print("Maximum heart rate is", maximum)
print("Target heart rate is between", " and ".join(str(i) for i in target))
