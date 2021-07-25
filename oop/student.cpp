#include <iostream>
#include <string>

class Student
{
public:
    Student(std::string name, int grade, float gpa);

    void SetName(std::string name);
    void SetGrade(int grade);
    void SetGPA(float gpa);

    std::string GetName() const;
    int GetGrade() const;
    float GetGPA() const;

private:
    std::string name_;
    int grade_;
    float gpa_;
};

std::string Student::GetName() const { return name_; }
int Student::GetGrade() const { return grade_; }
float Student::GetGPA() const { return gpa_; }

void Student::SetName(std::string name) { name_ = name; }

void Student::SetGrade(int grade)
{
    if (grade < 0 || grade > 12)
        throw std::string{"grade"};
    grade_ = grade;
}

void Student::SetGPA(float gpa)
{
    if (gpa < 0.0 || gpa > 4.0)
        throw std::string{"gpa"};
    gpa_ = gpa;
}

Student::Student(std::string name, int grade, float gpa)
{
    SetName(name);
    SetGrade(grade);
    SetGPA(gpa);
}

int main()
{
    // Test instantiation and getters / setters
    try
    {
        Student david("David", 11, 7.1);
        std::cout << david.GetName() << "\n";
        std::cout << david.GetGrade() << "\n";
        std::cout << david.GetGPA() << "\n";
    }
    catch (std::string e)
    {
        std::cout << "Invalid " << e;
        return -1;
    }
}
