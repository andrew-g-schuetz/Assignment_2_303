#include <iostream>

class Employee {
protected:
    std::string name;
    double hourly_rate;
    int years_at_company;
    

public:
    //Sets the values given in constructor to the protected variables
    Employee(const std::string& name, double hourly_rate, int years_at_company) {
        this->name = name;
        this->hourly_rate = hourly_rate;
        this->years_at_company = years_at_company;

    }

    virtual double calculate_weekly_salary(int hours_worked) const = 0;
    virtual double calculate_health_care_contribution() const = 0;
    virtual int calculate_vacation_days() const = 0;
};

class Professional : public Employee {
public:
    Professional(const std::string& name, double hourly_rate, int years_at_company)
        : Employee(name, hourly_rate, years_at_company) {}

    //Weekly salary is calculated by multiply hourly rate by 40 no 
    //matter how many hours they actually worked
    double calculate_weekly_salary(int hours_worked) const override {
        return hourly_rate * 40;
    }

    //Health care contribution is 4% * hourly rate * 52(weeks in a year) * years
    //at company
    double calculate_health_care_contribution() const override {
        return .04 * hourly_rate * 52 * years_at_company;
    }

    //Vacation days vary depending on years at the company as a Professional
    int calculate_vacation_days() const override {
            switch(years_at_company){
                case 0:
                    return 14;
                    break;
                case 1:
                    return 16;
                    break;
                case 2:
                    return 18;
                    break;
                case 3:
                    return 20;
                    break;
                case 4:
                    return 22;
                    break;
                case 5:
                    return 24;
                    break;
                default:
                    return 30;
                    break;
            }
    }
};

class Nonprofessional : public Employee {
public:
    Nonprofessional(const std::string& name, double hourly_rate, int years_at_company)
        : Employee(name, hourly_rate, years_at_company) {}

    //Weekly salary is the hourly rate times hours they worked
    double calculate_weekly_salary(int hours_worked) const override {
        return hourly_rate * hours_worked;
    }

    //Health care contribution is 2% * hourly rate * 52(weeks in a year) * years
    //at company
    double calculate_health_care_contribution() const override {
        return .02 * hourly_rate * 52* years_at_company;
    }

    //Vacation days depend on years worked at the company as a NonProfessional
    int calculate_vacation_days() const override {
        switch(years_at_company){
                case 0:
                    return 14;
                    break;
                case 1:
                    return 16;
                    break;
                case 2:
                    return 18;
                    break;
                case 3:
                    return 20;
                    break;
                case 4:
                    return 22;
                    break;
                case 5:
                    return 24;
                    break;
                default:
                    return 30;
                    break;
            }
    }
};

int main() {
    Professional professional_employee("Andrew", 50, 8);
    Nonprofessional nonprofessional_employee("Matthew", 20, 3);

    

    double professional_salary = professional_employee.calculate_weekly_salary(40);
    double professional_healthcare = professional_employee.calculate_health_care_contribution();
    int professional_vacation_days = professional_employee.calculate_vacation_days();

    double nonprofessional_salary = nonprofessional_employee.calculate_weekly_salary(36);
    double nonprofessional_healthcare = nonprofessional_employee.calculate_health_care_contribution();
    int nonprofessional_vacation_days = nonprofessional_employee.calculate_vacation_days();

    std::cout << "Professional Employee: " << std::endl 
            << "Weekly Salary: $" << professional_salary << std::endl
              << "Health Care Contribution: $" << professional_healthcare << std::endl
              << "Vacation Days: " << professional_vacation_days << std::endl;

    std::cout << "-----------------------------------------------------" << std::endl;

    std::cout << "Nonprofessional Employee" << std::endl
                << "Weekly Salary: $" << nonprofessional_salary << std::endl
              << "Health Care Contribution: $" << nonprofessional_healthcare << std::endl
              << "Vacation Days: " << nonprofessional_vacation_days << std::endl;

    return 0;
}
