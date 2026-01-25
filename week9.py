# Abstract base class
class Employee:
    def __init__(self, first_name, initial, last_name):
        self.first_name = first_name
        self.initial = initial
        self.last_name = last_name

    def calculate_pay(self):
        raise NotImplementedError("Subclass must implement abstract method")

    def display_info(self):
        print(self.first_name + " " + self.initial + ". " + self.last_name, end='')

# SalaryEmployee class
class SalaryEmployee(Employee):
    def __init__(self, first_name, initial, last_name, monthly_salary):
        super().__init__(first_name, initial, last_name)
        self.monthly_salary = monthly_salary

    def calculate_pay(self):
        return self.monthly_salary

    def display_info(self):
        super().display_info()
        print(" | Ksh " + str(self.calculate_pay()) + " (Salary)")


# HourlyEmployee class
class HourlyEmployee(Employee):
    def __init__(self, first_name, initial, last_name, hours_worked, hourly_rate):
        super().__init__(first_name, initial, last_name)
        self.hours_worked = hours_worked
        self.hourly_rate = hourly_rate

    def calculate_pay(self):
        return self.hours_worked * self.hourly_rate

    def display_info(self):
        super().display_info()
        print(" | Ksh " + str(self.calculate_pay()) + " (Hourly)")

# Main program
def main():
    payroll = []

    payroll.append(SalaryEmployee("Ismael", "K", "Kipkoech", 60000))
    payroll.append(HourlyEmployee("Lucy", "M", "Mundia", 160, 120))
    payroll.append(HourlyEmployee("Angela", "N", "Newton", 192, 120))
    payroll.append(SalaryEmployee("Angel", "G", "Gabriel", 45000))

    print("NAME | PAY")
    print("-------------------------")

    total_payroll = 0  # Initialize total payroll

    for emp in payroll:
        emp.display_info()
        total_payroll += emp.calculate_pay()  # Add each employee's pay to total

    print("-------------------------")

if __name__ == "__main__":
    main()
