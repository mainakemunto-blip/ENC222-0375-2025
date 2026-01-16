class Employee:
    def __init__(self, name, age, service_year, salary):
        # private data members
        self.__name = name
        self.__age = age
        self.__service_year = service_year
        self.__salary = salary

    def __del__(self):
        # destructor (optional in Python)
        pass

    # accessor (getter) methods
    def get_name(self):
        return self.__name

    def get_age(self):
        return self.__age

    def get_service_year(self):
        return self.__service_year

    def get_salary(self):
        return self.__salary
