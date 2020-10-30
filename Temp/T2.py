money = 50000
rate = [0.0325, 0.03, 0.02, 0.04, 0.0375]
for i in range(5):
    money = round(money * (1 + i), 2)
print("The money 5 years later:", money, " yuan")
input("Please tap any key to continue")
