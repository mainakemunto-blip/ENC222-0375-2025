class Fraction:
 def __init__(self, numerator, denominator):
    self.numerator = numerator
    self.denominator = denominator

def largest_fraction(f1, f2, f3):
    value1 = f1.numerator / f1.denominator
    value2 = f2.numerator / f2.denominator
    value3 = f3.numerator / f3.denominator

    if value1 >= value2 and value1 >= value3:
        return f1
    elif value2 >= value1 and value2 >= value3:
        return f2
    else:
        return f3

f1 = Fraction(2, 3)
f2 = Fraction(4, 5)
f3 = Fraction(10, 1)
largest = largest_fraction(f1, f2, f3)
print(f"Largest fraction is {largest.numerator}/{largest.denominator}")
