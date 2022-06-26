//Inheritance
#include<iostream>
#include<string>
using namespace std;

#define HUMAN_PARAMETERS	const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_ARGUMENTS		last_name, first_name, age
class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	Human(HUMAN_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	virtual void info()const
	{
		cout << last_name << " " << first_name << " " << age << " years\n";
	}
};

#define STUDENT_PARAMETERS	const std::string& speciality, const std::string& group, unsigned int year, float rating, float attendance
#define STUDENT_ARGUMENTS	speciality, group, year, rating, attendance
class Student :public Human
{
	std::string specialty;
	std::string group;
	unsigned int year;
	float rating;
	float attendance;
public:
	const std::string& get_specialty()const
	{
		return specialty;
	}
	const std::string& get_group()const
	{
		return group;
	}
	unsigned int get_year()const
	{
		return year;
	}
	float get_rating()const
	{
		return rating;
	}
	float get_attendance()const
	{
		return attendance;
	}

	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_year(unsigned int year)
	{
		this->year = year;
	}
	void set_rating(float rating)
	{
		this->rating = rating;
	}
	void set_attendance(float attendance)
	{
		this->attendance = attendance;
	}
	Student(HUMAN_PARAMETERS, STUDENT_PARAMETERS) :Human(HUMAN_ARGUMENTS)
	{
		set_specialty(specialty);
		set_group(group);
		set_year(year);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SCostructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	void info()const
	{
		Human::info();
		cout << specialty << " " << group << " " << year << " " << rating << " " << attendance << endl;
	}
};

#define TEACHER_PARAMETERS	const std::string& specialty, unsigned int experience
#define TEACHER_ARGUMENTS	specialty, experience
class Teacher :public Human
{
	std::string specialty;
	unsigned int experience;
public:
	const std::string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	Teacher(HUMAN_PARAMETERS, TEACHER_PARAMETERS) :Human(HUMAN_ARGUMENTS)
	{
		set_specialty(specialty);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void info()const
	{
		Human::info();
		cout << specialty << " " << experience << endl;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	Graduate(HUMAN_PARAMETERS, STUDENT_PARAMETERS, const std::string& subject) 
		:Student(HUMAN_ARGUMENTS, STUDENT_ARGUMENTS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void info()const
	{
		Student::info();
		cout << " " << subject << endl;
	}
};

//#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
	Human h("Montana", "Antonio", 25);
	h.info();
	cout << "\n---------------------------------------------------\n";

	Student jessie("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 1, 70, 90);
	jessie.info();
	cout << "\n---------------------------------------------------\n";

	Teacher walter("White", "Walter", 50, "Chemistry", 25);
	walter.info();
	cout << "\n---------------------------------------------------\n";

	Graduate hank("Schrader", "Hank", 40, "Criminalistic", "WW_220", 5, 89, 80, "How to catch Heisenberg");
	hank.info();
#endif // INHERITANCE_CHECK

	//Polymorphism (многоформенность: poly - много, morphis - форма).
	//1. ”казатели на базовый класс - Generalisation;	
	//2. ¬иртуальные метода - Specialisation;

	//Generalisation:
	Human* group[] =
	{
		//Upcast - преобразование к базовому типу:
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 1, 70, 90),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "WW_220", 5, 89, 80, "How to catch Heisenberg"),
		new Student("Vercetti", "Tomas", 30, "Criminal", "Vice", 2, 95, 98)
	};
	cout << "\n---------------------------------------------------\n";
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->info();
		cout << "\n---------------------------------------------------\n";
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}

}