money = 50000
rate = 0.0325
for i in range(5):
    money = money * (1 + rate)
    
print("5年后的存款：", money, "yuan")
input("请按任意键继续......")
