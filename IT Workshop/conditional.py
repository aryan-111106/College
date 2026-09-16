#WAP to show students passed with and without distinction.

marks=int(input("Enter marks: "))
if marks >= 75:
	print("Distinction")

#WAP to check if a year is leap year or not using all the possible conditions.

year=int(input("Enter year: "))
if (year % 400 == 0) or (year % 4 == 0 and year % 100 != 0):
	print("Leap year")
else:
	print("Not leap")

#WAP in python for grading 90-100=O, 80-89=E, 70-79=A, 60-69=B,50-59=C,40-49=D,<40=Fail

marks = float(input("Enter your marks (0-100): "))

if marks >= 90:
    print("Grade: O (Distinction)")
elif marks >= 80:
    print("Grade: E (Distinction)")
elif marks >= 70:
    print("Grade: A")
elif marks >= 60:
    print("Grade: B")
elif marks >= 50:
    print("Grade: C")
elif marks >= 40:
    print("Grade: D")
elif marks < 40:
    print("Grade: Fail")
else:
    print("Invalid marks")

#WAP in python to create a tier based electricity bill using simpleladder if-else.

units = int(input("Enter electricity units consumed: "))

if units <= 102:
    bill = units * 5.66
elif units <= 180:
    bill = (102 * 5.66) + ((units - 102) * 6.41)
elif units <= 300:
    bill = (102 * 5.66) + (78 * 6.41) + ((units - 180) * 6.89)
else:
    bill = (102 * 5.66) + (78 * 6.41) + (120 * 6.89) + ((units - 300) * 7.45)

print("Electricity Bill = ₹", round(bill, 2))

#WAP in python to check ATM transaction and balance checker.

balance = 0
while True:
    print("\n===== ATM MENU =====")
    print("1. Check Balance")
    print("2. Deposit")
    print("3. Withdraw")
    print("4. Exit")

    choice = int(input("Enter your choice (1-4): "))

    if choice == 1:
        print("Current Balance = ₹", balance)

    elif choice == 2:
        amount = float(input("Enter deposit amount: ₹"))
        balance = balance + amount
        print("₹", amount, "deposited successfully.")
        print("Updated Balance = ₹", balance)

    elif choice == 3:
        amount = float(input("Enter withdrawal amount: ₹"))

        if amount <= balance:
            balance = balance - amount
            print("Please collect your cash.")
            print("Remaining Balance = ₹", balance)
        else:
            print("Insufficient Balance!")

    elif choice == 4:
        print("Thank you for using our ATM!")
        break

    else:
        print("Invalid choice! Please enter a number between 1 and 4.")

#WAP in python to check score and time laps of performer using nested if.

score = int(input("Enter the score: "))
distance = int(input("Enter race distance (100/200/400): "))
time = float(input("Enter time taken (in seconds): "))

if score >= 50:
    print("Score Qualified")

    if distance == 100:
        if time <= 12:
            print("Gold Medal")
        elif time <= 15:
            print("Silver Medal")
        else:
            print("Bronze Medal")

    elif distance == 200:
        if time <= 25:
            print("Gold Medal")
        elif time <= 30:
            print("Silver Medal")
        else:
            print("Bronze Medal")

    elif distance == 400:
        if time <= 55:
            print("Gold Medal")
        elif time <= 65:
            print("Silver Medal")
        else:
            print("Bronze Medal")

    else:
        print("Invalid Distance")

else:
    print("Disqualified due to low score")

#WAP in python to check type of triangle using nested if.

a = float(input("Enter first side: "))
b = float(input("Enter second side: "))
c = float(input("Enter third side: "))
if (a + b > c) and (a + c > b) and (b + c > a):
    if a == b:
        if b == c:
            print("Equilateral Triangle")
        else:
            print("Isosceles Triangle")
    else:
        if b == c or a == c:
            print("Isosceles Triangle")
        else:
            print("Scalene Triangle")
else:
    print("Not a Valid Triangle")

#Ternary operator
score=85
if score >= 75: print("Qualified for Advanced Python Quiz!")

ques_att = int(input("Enter no. of questions attempted: "))
result= "Qualified for the next round" if ques_att >=50 else "Not qualified"
print(result)