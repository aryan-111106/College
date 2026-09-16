#WAP to create a multiplication table
n=int(input("Enter a no.: "))
print(f"Table of {n}: ")
for i in range(1, 11):      
    print(f"{n} x {i} = {n*i:2}")

#WAP to calculate factorial
num = int(input("Enter a number to find its factorial: "))
fact = 1
if num < 0:
    print("Factorial does not exist for negative numbers.")
else:
    for i in range(1, num + 1):
        fact *= i
    print("Factorial of", num, "is", fact)

#WAP to show fibonacci series
n = int(input("Enter the number of terms for Fibonacci series: "))
a, b = 0, 1
print("Fibonacci Series:")
for i in range(n):
    print(a, end=" ")
    a, b = b, a + b
print()

#WAP to claculate sum of digits
num = int(input("Enter a number: "))
total = 0
while num > 0:
    digit = num % 10
    total += digit
    num //= 10
print("Sum of digits =", total)

#WAP to check Prime numbers
num = int(input("Enter a number: "))
is_prime = True
if num < 2:
    is_prime = False
else:
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            is_prime = False
            break
print(num, "is Prime" if is_prime else "is Not Prime")

#Pyramid
rows = 5
for i in range(1, rows + 1):
    print(" " * (rows - i) + "* " * i)

#Inverted pyramid
rows = 5
for i in range(rows, 0, -1):
    print(" " * (rows - i) + "* " * i)
 
#Diamond
rows = 5
# Upper pyramid
for i in range(1, rows + 1):
    print(" " * (rows - i) + "* " * i)
# Lower pyramid
for i in range(rows - 1, 0, -1):
    print(" " * (rows - i) + "* " * i)

#Hollow
rows = 5
for i in range(1, rows + 1):
    for j in range(1, 2*rows):
        if j == rows - i + 1 or j == rows + i - 1 or i == rows:
            print("*", end="")
        else:
            print(" ", end="")
    print()

#Sand glass
rows = 5
# Upper inverted triangle
for i in range(rows, 0, -1):
    print(" " * (rows - i) + "* " * i)
# Lower triangle
for i in range(2, rows + 1):
    print(" " * (rows - i) + "* " * i)