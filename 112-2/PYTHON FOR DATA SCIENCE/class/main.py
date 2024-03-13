height = float(input("Height: "))
weight = float(input("Weight: "))
BMI = weight / (height ** 2)

if BMI < 18.5:
    print("low BMI\n")
elif BMI < 25:
    print("normal BMI\n")
else:
    print("high BMI\n")
