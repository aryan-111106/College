# WAP to develop a smart shop billing system
print("Welcome to Smart Shop")
print("Available items:")
print("1. Rice - ₹50/kg")
print("2. Sugar - ₹40/kg")
print("3. Milk - ₹30/litre")
print("4. Oil  - ₹120/litre")

item = int(input("\nEnter the item number you want to buy: "))
quantity = float(input("Enter the quantity (kg/litre): "))

bill = 0

if item == 1:
    bill = 50 * quantity
    print(f"You bought {quantity} kg Rice")
elif item == 2:
    bill = 40 * quantity
    print(f"You bought {quantity} kg Sugar")
elif item == 3:
    bill = 30 * quantity
    print(f"You bought {quantity} litre Milk")
elif item == 4:
    bill = 120 * quantity
    print(f"You bought {quantity} litre Oil")
else:
    print("Invalid item selected!")

if bill > 0:
    # Apply discount condition
    if bill >= 1000:
        discount = bill * 0.1  # 10% discount
        bill -= discount
        print(f" You got a discount of ₹{discount:.2f}")

    print(f"Your total bill is: ₹{bill:.2f}")
    payment = int(input("Enter payment amount: "))

    if payment == bill:
        print("Payment successful! Thank you for shopping with us.")
    elif payment > bill:
        print(f"Payment successful! Collect your change ₹{payment - bill:.2f}")
    else:
        print(f"Insufficient payment! You still owe ₹{bill - payment:.2f}")

# Write a python program to create a calculator.
print("Choose an operation:")
print("1. Addition")
print("2. Subtraction")
print("3. Multiplication")
print("4. Division")
print("5. Addition of two Square number")
print("6. Addition of two Cube number")

choice = int(input("Enter choice (1-6): "))
a = float(input("Enter first number: "))
b = float(input("Enter second number: "))

match choice:
    case 1:
        result = a + b
    case 2:
        result = a - b
    case 3:
        result = a * b
    case 4:
        result = a / b if b != 0 else "Division by zero not allowed"
    case 5:
        result = a**2 + b**2
    case 6:
        result = a**3 + b**3
    case _:
        result = "Invalid choice"

print("Result:", result)


# Write a python program to show day of a date.

import datetime

# Take date input from user
day = int(input("Enter day (1-31): "))
month = int(input("Enter month (1-12): "))
year = int(input("Enter year (e.g., 2025): "))

# Create date object
date = datetime.date(year, month, day)

# Get weekday number (0=Monday, 6=Sunday)
weekday_num = date.weekday()


# Match to day name
match weekday_num:
    case 0:
        day_name = "Monday"
    case 1:
        day_name = "Tuesday"
    case 2:
        day_name = "Wednesday"
    case 3:
        day_name = "Thursday"
    case 4:
        day_name = "Friday"
    case 5:
        day_name = "Saturday"
    case 6:
        day_name = "Sunday"
    case _:
        day_name = "Invalid day"

print(f"\nThe date {date} is a {day_name}.")

# Weekend / Next weekend check
match weekday_num:
    case 5 | 6:  # Saturday or Sunday
        print("🎉 It's a Weekend!")
    case _:
        days_until_weekend = 5 - weekday_num  # Saturday is 5
        next_weekend = date + datetime.timedelta(days=days_until_weekend)
        print(
            f"⌛ It's a weekday. Next weekend starts on {next_weekend}({next_weekend.strftime('%A')})."
        )
