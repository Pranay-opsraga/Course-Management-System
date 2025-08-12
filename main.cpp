#include <iostream>
#include <cstring>

int tfees = 0;
int allstu = 0;
int allteacher = 0;
int totalcourses;
float totalrating = 0;
class Youtube
{
public:
    int fees, students, teachers;
    float rating;

    Youtube(int fees, int students, int teachers, float rating)
    {
        this->fees = fees;
        this->students = students;
        this->teachers = teachers;
        this->rating = rating;
    }
    void displayyoutube()
    {
        std::cout << "-----------YOUTUBE DETAILS-------------" << std::endl;
        std::cout << " Fees on youtube : Rs" << fees << std::endl;
        std::cout << " Number of students :" << students << std::endl;
        std::cout << " Number of teachers :" << teachers << std::endl;
        std::cout << " Rating of the course on yt :" << rating << std::endl;
    }
};
class App
{
public:
    int fees, students, teachers;
    float rating;

    App(int fees, int students, int teachers, float rating)
    {
        this->fees = fees;
        this->students = students;
        this->teachers = teachers;
        this->rating = rating;
    }
    void displayapp()
    {
        std::cout << "----------APP DETAILS ----------------" << std::endl;
        std::cout << " Fees on App : Rs" << fees << std::endl;
        std::cout << " Number of students :" << students << std::endl;
        std::cout << " Number of teachers :" << teachers << std::endl;
        std::cout << " Rating of the course on App :" << rating << std::endl;
    }
};
class website
{
public:
    int fees, students, teachers;
    float rating;

    website(int fees, int students, int teachers, float rating)
    {
        this->fees = fees;
        this->students = students;
        this->teachers = teachers;
        this->rating = rating;
    }
    void displaywebsite()
    {
        std::cout << "----------WEBSITE DETAILS-------------" << std::endl;
        std::cout << " Fees on website : Rs" << fees << std::endl;
        std::cout << " Number of students :" << students << std::endl;
        std::cout << " Number of teachers :" << teachers << std::endl;
        std::cout << " Rating of the course on website :" << rating << std::endl;
    }
};
class Course
{
    int duration;
    std::string name;
    Youtube *yt;
    website *web;
    App *app;

public:
    void displayCourse();

    void totalcoursedetails();
    Course(std::string name, int duration, Youtube *yt, website *web, App *app)
    {
        this->name = name;
        this->duration = duration;
        this->yt = yt;
        this->web = web;
        this->app = app;

        tfees += yt->fees + web->fees + app->fees;
        allstu += yt->students + web->students + app->students;
        allteacher += yt->teachers + web->teachers + app->teachers;
        totalrating += yt->rating + web->rating + app->rating;
        totalcourses += 3;
    }
};
void Course ::displayCourse()
{
    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "->" << " " << std::endl
              << name << "( " << duration << "months )" << std::endl;
    yt->displayyoutube();
    web->displaywebsite();
    app->displayapp();
}

class Student
{
    std::string name;
    int age;
    int courseCount;
    Course **enrollcourses;

public:
    Student(std::string name, int age, int courseCount)
    {
        this->name = name;
        this->age = age;
        this->courseCount = courseCount;
        float static Averageratings;
        float ratings;

        enrollcourses = new Course *[courseCount];
        for (int i = 0; i < courseCount; i++)
        {
            std::string coursename;
            int duration, totalstu, totalteacher;
            int fees;
            std::cout << "Enter the course " << i + 1 << " Name: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, coursename);
            std::cout << "Enter the course " << i + 1 << " Duration: " << std::endl;
            std::cin >> duration;

            int f, s, t;
            float r;
            std::cout << "--- YouTube ---\nFees: " << std::endl;
            std::cin >> f;
            std::cout << "Students: " << std::endl;
            std::cin >> s;
            std::cout << "Teachers: " << std::endl;
            std::cin >> t;
            std::cout << "Rating: " << std::endl;
            std::cin >> r;
            Youtube *yt = new Youtube(f, s, r, t);

            std::cout << "--- App ---\nFees: ";
            std::cin >> f;
            std::cout << "Students: " << std::endl;
            std::cin >> s;
            std::cout << "Teachers: " << std::endl;
            std::cin >> t;
            std::cout << "Rating: " << std::endl;
            std::cin >> r;
            App *app = new App(f, s, r, t);

            std::cout << "--- Website ---\nFees: " << std::endl;
            std::cin >> f;
            std::cout << "Students: " << std::endl;
            std::cin >> s;
            std::cout << "Teachers: " << std::endl;
            std::cin >> t;
            std::cout << "Rating: " << std::endl;
            std::cin >> r;
            website *web = new website(f, s, r, t);

            enrollcourses[i] = new Course(coursename, duration, yt, web, app);
        }
    }

    void displaystudentdetails()
    {
        std::cout << "Student name : " << name << std::endl
                  << "Age : " << age << std::endl
                  << "Enrolled in :\n";
        for (int i = 0; i < courseCount; i++)
        {
            enrollcourses[i]->displayCourse();
        }
    }
    ~Student()
    {
        for (int i = 0; i < courseCount; i++)
        {
            delete enrollcourses[i];
            enrollcourses[i] = nullptr;
        }
        delete[] enrollcourses;
        enrollcourses = nullptr;
    }
};
int main()
{
    int n;
    std::cout << "-------------WELCOME TO COURSE MANAGMENT SYSTEM-------------" << std::endl;
    std::cout << "Enter the number of the student : " << std::endl;
    std::cin >> n;

    Student **ptr = new Student *[n];
    for (int i = 0; i < n; i++)
    {
        std::string name;
        int age, coursecount;
        std::cout << "Enter the details of the student no.  " << i + 1 << " :" << std::endl;
        std::cout << "Name :" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Age :" << std::endl;
        std::cin >> age;
        std::cout << "In how many course have you enrolled in " << std::endl;
        std::cin >> coursecount;
        ptr[i] = new Student(name, age, coursecount);
    }
    std::cout << "\n ---------------All students details-----------\n"
              << std::endl;

    for (int i = 0; i < n; i++)
    {
        ptr[i]->displaystudentdetails();
    }

    for (int i = 0; i < n; i++)
    {
        delete ptr[i];
        ptr[i] = nullptr;
    }
    delete[] ptr;
    ptr = nullptr;
    std::cout << "-----------Overall details----------------" << std::endl;
    std::cout << "->" << " " << std::endl;
    std::cout << " Total Fees of the courses : Rs " << tfees << std::endl;
    std::cout << "Total enrollment of the courses :" << allstu << std::endl;
    std::cout << "Total teacher of the courses :" << allteacher << std::endl;
    std::cout << " Average rating of the courses : "
              << (totalcourses == 0 ? 0 : totalrating / totalcourses) << std::endl;
    return 0;
}