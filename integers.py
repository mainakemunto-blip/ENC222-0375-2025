numbers = []
even = []
odd = []

for i in range(20):
    numbers.append(i + 1)
for num in numbers:
 if num % 2 == 0:
   even.append(num)
 else:
   odd.append(num)
print("Even numbers:", even)
print("Odd numbers:", odd)
