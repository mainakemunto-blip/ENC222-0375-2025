#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract base class
class Employee {
protected:
    string firstName;
    char initial;
    string lastName;

public:
    Employee(string fn, char init, string ln) 
        : firstName(fn), initial(init), lastName(ln) {}

    virtual ~Employee() {}

    virtual double calculatePay() const = 0; // pure virtual function

    virtual void displayInfo() const {
        cout << firstName << " " << initial << ". " << lastName;
    }
};

// SalaryEmployee class
class SalaryEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalaryEmployee(string fn, char init, string ln, double salary)
        : Employee(fn, init, ln), monthlySalary(salary) {}

    double calculatePay() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << " | Ksh " << calculatePay() << " (Salary)" << endl;
    }
};

// HourlyEmployee class
class HourlyEmployee : public Employee {
private:
    double hoursWorked;
    double hourlyRate;

public:
    HourlyEmployee(string fn, char init, string ln, double hours, double rate)
        : Employee(fn, init, ln), hoursWorked(hours), hourlyRate(rate) {}

    double calculatePay() const override {
        return hoursWorked * hourlyRate;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << " | Ksh " << calculatePay() << " (Hourly)" << endl;
    }
};

// Main function
int main() {
    vector<Employee*> payroll;

    payroll.push_back(new SalaryEmployee("Ismael", 'K', "Kipkoech", 60000));
    payroll.push_back(new HourlyEmployee("Lucy", 'M', "Mundia", 160, 120));
    payroll.push_back(new HourlyEmployee("Angela", 'N', "Newton", 192, 120));
    payroll.push_back(new SalaryEmployee("Angel", 'G', "Gabriel", 45000));

    cout << "NAME | PAY" << endl;
    cout << "-------------------------" << endl;

    for (Employee* emp : payroll) {
        emp->displayInfo(); 
    }

    // Clean up memory
    for (Employee* emp : payroll) {
        delete emp;
    }

    return 0;
}
