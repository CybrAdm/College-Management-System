#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <algorithm>
using namespace std;
const int SIZE = 100;
long long int stuIDCounter = 100012;
long long int stfIDCounter = 200006;
long long int admIDCounter = 300002;


struct information {
	long long int id;
	string name;
	string mobileNumber;
	string password;
	string address;
};

struct student {
	information inf;
	string department;
	int academicYear;
	string studentCourses[10];
	float couTotalMarks;
	float totalMarks;
	float percentage;
	float GPA;
	string letter;
} stu[SIZE];

struct staff {
	information inf;
	string department;
	string position;
	string teachingCourses[10];
	int stfNumOfCou;
} stf[SIZE];

struct administration {
	information inf;
	string position;
} adm[SIZE];

struct gradeScheme
{
	float total;
	float finalMax;
	float practicalMax;
	float yearWorkMax;
	float quizMax;
};

struct grade
{
	float total;
	float final;
	float practical;
	float yearWork;
	float quiz;
	float percentage;
	string letter;
	bool gradeAssigned = false;
};

struct enrollment
{
	int studentIndex[SIZE];
	grade g[SIZE];
};

struct courseSchedule
{
	int weekDay;
	int hour;
	int minute;
	bool isSet;
};

struct course
{
	string name;
	int creditHours;
	int academicYear;
	gradeScheme gr;
	string academicMemberName[5];
	int studentCount;
	enrollment enr;
	courseSchedule schedule;

}cou[SIZE];

struct schedule
{
	int day;
	int month;
	int year;

	int hour;
	int minute;
};

struct exam
{
	schedule sch;
	course co;
}exm[SIZE];

struct appointment
{
	long long int studentID;
	string studentName;
	int stfIndex;
	string stfName;
	string status = "Pending";
	schedule sch;
} app[SIZE];




void mainMenu(int&, int&, int&, int&, int&, int&, exam[], appointment[], course[], student[], staff[], administration[]);
void signUp(int&, int&, int&, student[], staff[], administration[]);
void signIn(int, int, int, int&, int&, int&, exam[], appointment[], course[], student[], staff[], administration[]);
string getPassword();
void forgetPassword(int, int, int, int, student[], staff[], administration[]);
void addCourse(int&, course[]);
void viewCourses(int, course[]);
void removeCourse(int&, course[]);
void stfCouMenu(int, int, course[], staff[]);
void stfSelectCourse(int, int, staff[], course[]);
void stfViewCourses(int, staff[]);
void stfRemoveCourse(int, int, course[], staff[]);
void stuMenu(int, int&, int, int, int, int&, int, exam[], appointment[], course[], student[], staff[], administration[]);
void stfMenu(int, int, int, int, int, int, appointment[], course[], student[], staff[], administration[]);
void admMenu(int, int, int, int, int&, int&, exam[], course[], student[], staff[], administration[]);
void couMenu(int&, course[]);
void setGrades(int, int, course[], student[], staff[]);
void requestGrades(int, int, course[], student[]);
void requestAppointment(int, int, int&, appointment[], student[], staff[]);
void calculateGrade(int, grade&, course[]);
void couRegMenu(int&, int, student[], course[]);
void registerCourses(int, int, student[], course[]);
void dropCourses(int, int, student[], course[]);
void viewRegCou(int, student[]);
void availableCourses(int, int, student[], course[]);
void exmMenu(int, int&, course[], exam[]);
void setExamSchedule(int, int&, course[], exam[]);
void viewExamSchedule(int, int, course[], exam[]);
void removeExamSchedule(int, int&, course[], exam[]);
void stuViewExamSchedule(int, int, int, course[], exam[], student[], staff[], administration[]);
void stuProfile(int, int, int, int, student[], staff[], administration[]);
void stfProfile(int, int, int, int, student[], staff[], administration[]);
void admProfile(int, int, int, int, student[], staff[], administration[]);
void stfViewAppointments(int, int, appointment[]);
void stuViewAppointments(int, int, appointment[], student[], staff[]);
void couSchMenu(int, course[]);
void setCourseSchedule(int, course[]);
void viewCourseSchedules(int, course[]);
void removeCourseSchedule(int&, course[]);
void stuViewCourseSchedules(int, int, course[], student[]);
string getDayName(int weekDay);
void calculateGPA(int, int, course[], student[], bool);
float getGradePoint(string);
void getGPAletter(int, student[]);
void getTotalMarks(int, int, course[], student[]);
void gradesMenu(int, int, course[], student[]);
void stfviewTopStudents(int, int, staff[], course[], student[]);
void showTopHonorList(int, int, student[]);
void loadCourses(int, int, course[], student[]);
bool isMobileTaken(string, int, int, int, student[], staff[], administration[]);


int main()
{
	int numOfStu = 0;
	int numOfStf = 0;
	int numOfAdm = 0;
	int numOfCou = 0;
	int numOfApp = 0;
	int numOfExm = 0;


	stu[0] = { {100000, "Adam Ahmed Abdelbaset Ahmed",     "01116622100", "123", "Tawheed Street, Helwan"},  "SWE",    1, {"Calculus I", "Calculus II"} };
	stu[1] = { {100001, "Yousef Allam Abdullah Tayel",  "01103193182", "123", "Gamal Abdelnasser Axis, 5th Settlement"},  "SWE", 1, {"Calculus I", "Calculus II"} };
	stu[2] = { {100002, "Yousef Ehab Makram Armeia",   "01206747635", "123", "Ahmed Esmat, Ain Shams"},  "SWE",    1 };
	stu[3] = { {100003, "Salah Eldin Ibrahim Salah Eldin",     "01003083350", "123", "5th Settlement"},  "AI",    2, {"Linear Algebra", "Introduction to CS"} };
	stu[4] = { {100004, "Malek Mohammed Abdullah Elshazly",  "01227247771", "123", "Tanta"},  "AI", 2, {"Linear Algebra", "Introduction to CS"} };
	stu[5] = { {100005, "Philopater Farag Nabih Farag",   "01097113849", "123", "Zayton"},  "AI",    2 };
	stu[6] = { {100006, "Marwan Mohammed Abed",   "01012112768", "123", "AlNakheel, 1st Settlement"},  "CSEC",    3, {"Data Structures", "Discrete Math"} };
	stu[7] = { {100007, "Karim Mohammed Saleh",   "01234567890", "123", "Rehab"},  "CSEC",    3, {"Data Structures", "Discrete Math"} };
	stu[8] = { {100008, "Ahmed Karim Reda",   "01227727654", "123", "Obour"},  "CSEC",    3 };
	stu[9] = { {100009, "Micheal George Maged",   "01221723032", "123", "Korba"},  "Robotics",    4, {"AI", "SWE"} };
	stu[10] = { {100010, "Mohammed Salah Abdullah",   "01027823966", "123", "Shebin ElKom"},  "Robotics",    4, {"AI", "SWE"} };
	stu[11] = { {100011, "Raneem Ahmed Mostafa",   "01275553141", "123", "Benha"},  "Robotics",    4 };
	numOfStu = 12;


	stf[0] = { {200000, "Hassan Ramadan",   "01098765432", "256" }, "Information Systems", "Professor" };
	stf[1] = { {200001, "Ghada Hamed", "01087654321", "256"}, "Computer Science",    "Lecturer" };
	stf[2] = { {200002, "Naglaa Fathy",   "01098765433", "256" }, "Information Systems", "Lecturer" };
	stf[3] = { {200003, "Doaa Ezzat",   "01098765431", "256" }, "Information Systems", "Lecturer" };
	stf[4] = { {200004, "Eslam Sharshar", "01087654328", "256"}, "Computer Science",    "Teaching Assistant" };
	stf[5] = { {200005, "Habiba Hegazy", "01087654329", "256"}, "Computer Science",    "Teaching Assistant" };
	numOfStf = 6;

	adm[0] = { {300000, "Mohammed Ayad", "01122334455", "256" }, "Supervisor" };
	adm[1] = { {300001, "Hala Moushir", "01133445566", "256"}, "Supervisor" };
	numOfAdm = 2;

	cou[0] = { "Calculus I",          3, 1, {100, 60, 0,  30, 10} };
	cou[1] = { "Calculus II",         3, 1, {100, 60, 0,  30, 10} };
	cou[2] = { "Physics I",           3, 1, {100, 50, 15, 25, 10} };
	cou[3] = { "Introduction to CS",  3, 2, {100, 60, 0,  30, 10} };
	cou[4] = { "Linear Algebra",      3, 2, {100, 60, 0,  30, 10} };
	cou[5] = { "English I",           2, 2, {100, 60, 0,  30, 10} };
	cou[6] = { "Data Structures",     3, 3, {100, 60, 10, 20, 10} };
	cou[7] = { "Discrete Math",       3, 3, {100, 60, 0,  30, 10} };
	cou[8] = { "Database Systems",    3, 3, {100, 55, 15, 20, 10} };
	cou[9] = { "OOP",     3, 4, {100, 60, 10, 20, 10} };
	cou[10] = { "SWE",       3, 4, {100, 60, 0,  30, 10} };
	cou[11] = { "AI",    3, 4, {100, 55, 15, 20, 10} };
	numOfCou = 12;

	// ============ Year 1 ============

	cou[0].enr.studentIndex[0] = 0; cou[0].enr.g[0] = { 87, 52, 0, 25, 10, 87, "B+", true };
	cou[0].enr.studentIndex[1] = 1; cou[0].enr.g[1] = { 73, 43, 0, 22,  8, 73, "C+", true };

	cou[1].enr.studentIndex[0] = 0; cou[1].enr.g[0] = { 91, 55, 0, 27,  9, 91, "A-", true };
	cou[1].enr.studentIndex[1] = 1; cou[1].enr.g[1] = { 65, 38, 0, 19,  8, 65, "D",  true };

	// ============ Year 2 ============

	cou[4].enr.studentIndex[0] = 3; cou[4].enr.g[0] = { 95, 58, 0, 27, 10, 95, "A+", true };
	cou[4].enr.studentIndex[1] = 4; cou[4].enr.g[1] = { 78, 46, 0, 23,  9, 78, "B-", true };

	cou[3].enr.studentIndex[0] = 3; cou[3].enr.g[0] = { 82, 50, 0, 24,  8, 82, "B",  true };
	cou[3].enr.studentIndex[1] = 4; cou[3].enr.g[1] = { 61, 36, 0, 17,  8, 61, "D",  true };

	// ============ Year 3 ============

	cou[6].enr.studentIndex[0] = 6; cou[6].enr.g[0] = { 89, 54,  8, 18,  9, 89, "B+", true };
	cou[6].enr.studentIndex[1] = 7; cou[6].enr.g[1] = { 70, 41,  6, 15,  8, 70, "C",  true };

	cou[7].enr.studentIndex[0] = 6; cou[7].enr.g[0] = { 94, 57, 0, 27, 10, 94, "A",  true };
	cou[7].enr.studentIndex[1] = 7; cou[7].enr.g[1] = { 76, 45, 0, 22,  9, 76, "B-", true };

	// ============ Year 4 ============

	cou[11].enr.studentIndex[0] = 9;  cou[11].enr.g[0] = { 88, 51, 13, 16,  8, 88, "B+", true };
	cou[11].enr.studentIndex[1] = 10; cou[11].enr.g[1] = { 67, 39,  9, 12,  7, 67, "C-", true };

	cou[10].enr.studentIndex[0] = 9;  cou[10].enr.g[0] = { 97, 59, 0, 28, 10, 97, "A+", true };
	cou[10].enr.studentIndex[1] = 10; cou[10].enr.g[1] = { 80, 48, 0, 23,  9, 80, "B",  true };



	loadCourses(numOfStu, numOfCou, cou, stu);
	calculateGPA(0, numOfCou, cou, stu, false);
	calculateGPA(1, numOfCou, cou, stu, false);
	calculateGPA(3, numOfCou, cou, stu, false);
	calculateGPA(4, numOfCou, cou, stu, false);
	calculateGPA(6, numOfCou, cou, stu, false);
	calculateGPA(7, numOfCou, cou, stu, false);
	calculateGPA(9, numOfCou, cou, stu, false);
	calculateGPA(10, numOfCou, cou, stu, false);

	mainMenu(numOfStu, numOfStf, numOfAdm, numOfCou, numOfApp, numOfExm, exm, app, cou, stu, stf, adm);




}

bool isMobileTaken(string phone, int numOfStu, int numOfStf, int numOfAdm, student stu[], staff stf[], administration adm[])
{
	for (int i = 0; i < numOfStu; i++)
		if (stu[i].inf.mobileNumber == phone) return true;

	for (int i = 0; i < numOfStf; i++)
		if (stf[i].inf.mobileNumber == phone) return true;

	for (int i = 0; i < numOfAdm; i++)
		if (adm[i].inf.mobileNumber == phone) return true;

	return false;
}

void loadCourses(int numOfStu, int numOfCou, course cou[], student stu[])
{
	for (int i = 0; i < numOfStu; i++) {
		for (int j = 0; j < 10; j++) {
			if (stu[i].studentCourses[j] != "") {
				for (int k = 0; k < numOfCou; k++) {
					if (cou[k].name == stu[i].studentCourses[j]) {
						cou[k].enr.studentIndex[cou[k].studentCount] = i;
						cou[k].studentCount++;
						break;
					}
				}
			}
		}
	}
}

void mainMenu(int& numOfStu, int& numOfStf, int& numOfAdm, int& numOfCou, int& numOfApp, int& numOfExm, exam exm[], appointment app[], course cou[], student stu[], staff stf[], administration adm[])
{
	int choice;
	do
	{
		cout << "====== College Management System ======" << endl;
		cout << "[1] - Sign Up" << endl;
		cout << "[2] - Sign In" << endl;
		cout << "[0] - Exit" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			signUp(numOfStu, numOfStf, numOfAdm, stu, stf, adm);
			break;
		case 2:
			signIn(numOfStu, numOfStf, numOfAdm, numOfCou, numOfApp, numOfExm, exm, app, cou, stu, stf, adm);
			break;
		case 0:
			cout << "Exiting..." << endl;
			return;
		default:
			cout << "Invalid choice! Please try again" << "\n\n";
			break;
		}
	} while (true);
}

void signUp(int& numOfStu, int& numOfStf, int& numOfAdm, student stu[], staff stf[], administration adm[])
{
	int choice;
	do {
		cout << "====== Sign Up Menu ======" << endl;
		cout << "[1] - Student" << endl;
		cout << "[2] - Academic Staff Member" << endl;
		cout << "[3] - Administration Member" << endl;
		cout << "[0] - Back" << endl;
		cout << "--------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		if (choice != 1 && choice != 2 && choice != 3 && choice != 0) {
			cout << "Invalid choice! Please try again" << "\n\n";
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

	cin.ignore();
	string pass1, pass2, phone;
	int academicYear;
	bool taken = false;
	switch (choice) {
	case 1:
		stu[numOfStu].inf.id = stuIDCounter;
		cout << "Your generated ID: " << stu[numOfStu].inf.id << endl;
		cout << "Enter your full name: "; getline(cin, stu[numOfStu].inf.name);
		cout << "Enter your mobile number: "; getline(cin, phone);

		if (phone.length() != 11)
		{
			cout << "\nInvalid mobile number! Must be exactly 11 digits\n\n";
			break;
		}
		if (isMobileTaken(phone, numOfStu, numOfStf, numOfAdm, stu, stf, adm))
		{
			cout << "\nMobile number was taken before, Please try again\n\n";
			break;
		}
		stu[numOfStu].inf.mobileNumber = phone;

		cout << "Enter your password: ";
		pass1 = getPassword();
		cout << "Confirm your password: ";
		pass2 = getPassword();

		if (pass1 == pass2) {
			stu[numOfStu].inf.password = pass1;
		}
		else {
			cout << "\nPasswords do not match, Please try again\n";
			cout << endl;
			break;
		}
		cout << "Enter your address: "; getline(cin, stu[numOfStu].inf.address);
		cout << "Enter your department (General, SWE, AI, CSEC, ROB, DMM, BIO): "; getline(cin, stu[numOfStu].department);
		cout << "Enter your academic year (1, 2, 3, 4): "; cin >> academicYear;

		if (academicYear != 1 && academicYear != 2 && academicYear != 3 && academicYear != 4)
		{
			cout << "\nInvalid year! Please enter a value between 1 and 4\n\n";
			break;
		}
		else
			stu[numOfStu].academicYear = academicYear;

		cout << "\nStudent registered successfully!\n" << endl;
		stuIDCounter++;
		numOfStu++;
		break;

	case 2:
		stf[numOfStf].inf.id = stfIDCounter;
		cout << "Your generated ID: " << stf[numOfStf].inf.id << endl;
		cout << "Enter your full name: "; getline(cin, stf[numOfStf].inf.name);
		cout << "Enter your mobile number: "; getline(cin, phone);

		if (phone.length() != 11)
		{
			cout << "\nInvalid mobile number! Must be exactly 11 digits\n\n";
			break;
		}
		if (isMobileTaken(phone, numOfStu, numOfStf, numOfAdm, stu, stf, adm))
		{
			cout << "\nMobile number was taken before, Please try again\n\n";
			break;
		}
		stf[numOfStf].inf.mobileNumber = phone;

		cout << "Enter your password: ";
		pass1 = getPassword();
		cout << "Confirm your password: ";
		pass2 = getPassword();
		if (pass1 == pass2) {
			stf[numOfStf].inf.password = pass1;
		}
		else {
			cout << "\nPasswords do not match, Please try again\n";
			cout << endl;
			break;
		}
		cout << "Enter your address: "; getline(cin, stf[numOfStf].inf.address);
		cout << "Enter your department: "; getline(cin, stf[numOfStf].department);
		cout << "Enter your position: "; getline(cin, stf[numOfStf].position);
		cout << "\nStaff member registered successfully!\n" << endl;
		stfIDCounter++;
		numOfStf++;
		break;


	case 3:
		adm[numOfAdm].inf.id = admIDCounter;
		cout << "Your generated ID is: " << adm[numOfAdm].inf.id << endl;
		cout << "Enter your full name: "; getline(cin, adm[numOfAdm].inf.name);
		cout << "Enter your mobile number: "; getline(cin, phone);

		if (phone.length() != 11)
		{
			cout << "\nInvalid mobile number! Must be exactly 11 digits\n\n";
			break;
		}
		if (isMobileTaken(phone, numOfStu, numOfStf, numOfAdm, stu, stf, adm))
		{
			cout << "\nMobile number was taken before, Please try again\n\n";
			break;
		}
		adm[numOfAdm].inf.mobileNumber = phone;

		cout << "Enter your password: ";
		pass1 = getPassword();
		cout << "Confirm your password: ";
		pass2 = getPassword();
		if (pass1 == pass2) {
			adm[numOfAdm].inf.password = pass1;
		}
		else {
			cout << "\nPasswords do not match, Please try again\n";
			cout << endl;
			break;
		}
		cout << "Enter your address: "; getline(cin, adm[numOfAdm].inf.address);
		cout << "Enter your position: "; getline(cin, adm[numOfAdm].position);
		cout << "\nAdministration member registered successfully!\n" << endl;
		admIDCounter++;
		numOfAdm++;
		break;


	case 0:
		cout << "Returning to the Main Menu... \n" << endl;
		return;
	}
}


void signIn(int numOfStu, int numOfStf, int numOfAdm, int& numOfCou, int& numOfApp, int& numOfExm, exam exm[], appointment app[], course cou[], student stu[], staff stf[], administration adm[])
{
	int choice;
	do {
		cout << "====== Sign In Menu ======\n";
		cout << "[1] - Student\n";
		cout << "[2] - Academic Staff Member\n";
		cout << "[3] - Administration Member\n";
		cout << "[0] - Back\n";
		cout << "--------------------------\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
			cout << "Invalid choice! Please try again\n\n";

	} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

	if (choice == 0) {
		cout << "Returning to the Main Menu...\n\n";
		return;
	}

	long long int tempID;
	cout << "Enter your ID: ";
	cin >> tempID;

	bool idFound = false;
	int userIndex = -1;

	switch (choice) {
	case 1:
		for (int i = 0; i < numOfStu; i++)
			if (stu[i].inf.id == tempID) { idFound = true; userIndex = i; break; }
		break;
	case 2:
		for (int i = 0; i < numOfStf; i++)
			if (stf[i].inf.id == tempID) { idFound = true; userIndex = i; break; }
		break;
	case 3:
		for (int i = 0; i < numOfAdm; i++)
			if (adm[i].inf.id == tempID) { idFound = true; userIndex = i; break; }
		break;
	}

	if (!idFound) {
		cout << "\nID Not Found! Please try again\n\n";
		return;
	}

	int trials = 3;
	bool loggedIn = false;

	while (trials > 0 && !loggedIn) {
		cout << "Enter password: ";
		string tempPass = getPassword();

		switch (choice) {
		case 1:
			if (stu[userIndex].inf.password == tempPass) {
				cout << "\nWelcome, " << stu[userIndex].inf.name << "\n\n";
				loggedIn = true;
				stuMenu(userIndex, numOfCou, numOfStu, numOfStf, numOfAdm, numOfApp, numOfExm, exm, app, cou, stu, stf, adm);
			}
			break;
		case 2:
			if (stf[userIndex].inf.password == tempPass) {
				cout << "\nWelcome, " << stf[userIndex].inf.name << "\n\n";
				loggedIn = true;
				stfMenu(userIndex, numOfCou, numOfApp, numOfStu, numOfStf, numOfAdm, app, cou, stu, stf, adm);
			}
			break;
		case 3:
			if (adm[userIndex].inf.password == tempPass) {
				cout << "\nWelcome, " << adm[userIndex].inf.name << "\n\n";
				loggedIn = true;
				admMenu(userIndex, numOfStu, numOfStf, numOfAdm, numOfCou, numOfExm, exm, cou, stu, stf, adm);
			}
			break;
		}

		if (!loggedIn) {
			trials--;
			if (trials > 0) {
				cout << "\nWrong password! You have " << trials << " trial(s) left.\n\n";
			}
			else {
				cout << "\nWrong password! You have no trials left.\n";
				cout << "If you forgot your password, Press [1] to Reset,  Press any key to Return: ";
				string x; cin >> x;
				if (x == "1") {
					forgetPassword(choice, numOfStu, numOfStf, numOfAdm, stu, stf, adm);
					return;
				}
				else {
					cout << "\n\nReturning to the Main Menu...\n\n";
				}
				return;
			}
		}
	}
}

string getPassword() {
	string password = "";
	char ch;

	while ((ch = _getch()) != 13) {
		if (ch == 8) {
			if (!password.empty()) {
				password.pop_back();
				cout << "\b \b";
			}
		}
		else {
			password += ch;
			cout << '*';
		}
	}
	cout << endl;
	return password;
}


void forgetPassword(int choice, int numOfStu, int numOfStf, int numOfAdm, student stu[], staff stf[], administration adm[])
{
	bool found = false;
	while (!found) {
		string phone;
		long long int id;
		cout << "Enter your mobile number (or type '0' to cancel): ";
		cin >> phone;

		if (phone == "0") {
			cout << "Returning to the Main Menu...\n\n";
			return;
		}

		cout << "Enter your ID (or type '0' to cancel): ";
		cin >> id;

		if (id == 0) {
			cout << "Returning to the Main Menu...\n\n";
			return;
		}

		if (choice == 1) {
			for (int i = 0; i < numOfStu; i++) {
				if (stu[i].inf.mobileNumber == phone && stu[i].inf.id == id) {
					found = true;
					string newPass, confirmPass;
					do {
						cout << "Enter your new password: ";
						newPass = getPassword();
						cout << "Confirm your new password: ";
						confirmPass = getPassword();
						if (newPass != confirmPass)
							cout << "\nPasswords do not match! Please try again\n\n";
					} while (newPass != confirmPass);
					stu[i].inf.password = newPass;
					cout << "\nPassword has been reset successfully!\n\n";
					break;
				}
			}
		}
		else if (choice == 2) {
			for (int i = 0; i < numOfStf; i++) {
				if (stf[i].inf.mobileNumber == phone && stf[i].inf.id == id) {
					found = true;
					string newPass, confirmPass;
					do {
						cout << "Enter your new password: ";
						newPass = getPassword();
						cout << "Confirm your new password: ";
						confirmPass = getPassword();
						if (newPass != confirmPass)
							cout << "\nPasswords do not match! Please try again\n\n";
					} while (newPass != confirmPass);
					stf[i].inf.password = newPass;
					cout << "\nPassword has been reset successfully!\n\n";
					break;
				}
			}
		}
		else if (choice == 3) {
			for (int i = 0; i < numOfAdm; i++) {
				if (adm[i].inf.mobileNumber == phone && adm[i].inf.id == id) {
					found = true;
					string newPass, confirmPass;
					do {
						cout << "Enter your new password: ";
						newPass = getPassword();
						cout << "Confirm your new password: ";
						confirmPass = getPassword();
						if (newPass != confirmPass)
							cout << "\nPasswords do not match! Please try again\n\n";
					} while (newPass != confirmPass);
					adm[i].inf.password = newPass;
					cout << "\nPassword has been reset successfully!\n\n";
					break;
				}
			}
		}

		if (!found) {
			cout << "\nMobile number or ID is incorrect! Please try again\n\n";
			return;
		}
	}
}


void stuMenu(int stuIndex, int& numOfCou, int numOfStu, int numOfStf, int numOfAdm, int& numOfApp, int numOfExm, exam exm[], appointment app[], course cou[], student stu[], staff stf[], administration adm[])
{
	int choice;
	do
	{
		do
		{
			cout << "====== Student Dashboard ======" << endl;
			cout << "[1] - Profile" << endl;
			cout << "[2] - Course Registration" << endl;
			cout << "[3] - Grades" << endl;
			cout << "[4] - Request Appointment with Staff Members" << endl;
			cout << "[5] - View Appointments" << endl;
			cout << "[6] - View Course Schedule" << endl;
			cout << "[7] - View Exam Schedule" << endl;
			cout << "[8] - Top 5 Students" << endl;
			cout << "[0] - Logout" << endl;
			cout << "-------------------------------" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			cout << endl;

			if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 0)
				cout << "Invalid choice! Please try again\n\n";

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 0);

		switch (choice)
		{
		case 1:
			stuProfile(stuIndex, numOfStu, numOfStf, numOfAdm, stu, stf, adm);
			break;

		case 2:
			couRegMenu(numOfCou, stuIndex, stu, cou);
			break;

		case 3:
			gradesMenu(stuIndex, numOfCou, cou, stu);
			break;

		case 4:
			requestAppointment(stuIndex, numOfStf, numOfApp, app, stu, stf);
			break;

		case 5:
			stuViewAppointments(stuIndex, numOfApp, app, stu, stf);
			break;

		case 6:
			stuViewCourseSchedules(stuIndex, numOfCou, cou, stu);
			break;

		case 7:
			stuViewExamSchedule(stuIndex, numOfCou, numOfExm, cou, exm, stu, stf, adm);
			break;

		case 8:
			showTopHonorList(stuIndex, numOfStu, stu);
			break;

		case 0:
			cout << "Logging Out... \n" << endl;
			return;
		}
	} while (true);
}

void stfMenu(int stfIndex, int numOfCou, int numOfApp, int numOfStu, int numOfStf, int numOfAdm, appointment app[], course cou[], student stu[], staff stf[], administration adm[])
{
	int choice;
	do
	{
		do
		{
			cout << "====== Staff Dashboard ======" << endl;
			cout << "[1] - Profile" << endl;
			cout << "[2] - Set Grades" << endl;
			cout << "[3] - Edit Courses you Teach" << endl;
			cout << "[4] - View Appointments" << endl;
			cout << "[5] - View Top 5 Students in Courses you Teach" << endl;
			cout << "[0] - Logout" << endl;
			cout << "-----------------------------" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			cout << endl;

			if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 0)
				cout << "Invalid choice! Please try again" << "\n\n";

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 0);

		switch (choice)
		{
		case 1:
			stfProfile(stfIndex, numOfStu, numOfStf, numOfAdm, stu, stf, adm);
			break;

		case 2:
			setGrades(stfIndex, numOfCou, cou, stu, stf);
			break;

		case 3:
			stfCouMenu(stfIndex, numOfCou, cou, stf);
			break;

		case 4:
			stfViewAppointments(stfIndex, numOfApp, app);
			break;

		case 5:
			stfviewTopStudents(stfIndex, numOfCou, stf, cou, stu);
			break;

		case 0:
			cout << "Returning to the Main Menu... \n" << endl;
			return;
		}
	} while (true);
}

void admMenu(int admIndex, int numOfStu, int numOfStf, int numOfAdm, int& numOfCou, int& numOfExm, exam exm[], course cou[], student stu[], staff stf[], administration adm[])
{
	int choice;
	do
	{
		do
		{
			cout << "====== Administration Dashboard ======" << endl;
			cout << "[1] - Profile" << endl;
			cout << "[2] - Edit Courses" << endl;
			cout << "[3] - Edit Course Schedule" << endl;
			cout << "[4] - Edit Exam Schedule" << endl;
			cout << "[0] - Logout" << endl;
			cout << "--------------------------------------" << endl;
			cout << "Enter your choice: ";
			cin >> choice;

			if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0)
				cout << "Invalid choice! Please try again" << "\n\n";

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0);

		switch (choice)
		{
		case 1:
			admProfile(admIndex, numOfStu, numOfStf, numOfAdm, stu, stf, adm);
			break;

		case 2:
			couMenu(numOfCou, cou);
			break;

		case 3:
			couSchMenu(numOfCou, cou);
			break;

		case 4:
			exmMenu(numOfCou, numOfExm, cou, exm);
			break;

		case 0:
			cout << "Returning to the Main Menu... \n" << endl;
			return;
		}
	} while (true);
}

void addCourse(int& numOfCou, course cou[])
{
	char cont;
	do {
		if (numOfCou >= SIZE)
		{
			cout << "\nMaximum number of courses reached!\n" << endl;
			return;
		}

		cin.ignore();
		cout << "\nEnter Course Name: ";
		getline(cin, cou[numOfCou].name);
		for (int i = 0; i < numOfCou; i++)
		{
			if (cou[numOfCou].name == cou[i].name)
			{
				cout << "\nName was taken before, Please Try Again\n" << endl;
				return;
			}
		}

		cout << "Enter Course Credit Hour (1-5): ";
		cin >> cou[numOfCou].creditHours;
		if (cou[numOfCou].creditHours > 5 || cou[numOfCou].creditHours <= 0)
		{
			cout << "\nInvalid Credit Hours! Please Try Again\n" << endl;
			return;
		}

		cout << "Enter Course Academic Year (1-4): ";
		cin >> cou[numOfCou].academicYear;
		if (cou[numOfCou].academicYear > 4 || cou[numOfCou].academicYear <= 0)
		{
			cout << "\nInvalid Academic Year! Please Try Again\n" << endl;
			return;
		}

		cout << "Enter Course Total Marks: ";
		cin >> cou[numOfCou].gr.total;

		cout << "Enter Course Final Max Marks: ";
		cin >> cou[numOfCou].gr.finalMax;

		cout << "Enter Course Practical Max Marks: ";
		cin >> cou[numOfCou].gr.practicalMax;

		cout << "Enter Course Year Work Max Marks: ";
		cin >> cou[numOfCou].gr.yearWorkMax;

		cout << "Enter Course Quiz Max Marks: ";
		cin >> cou[numOfCou].gr.quizMax;

		if (cou[numOfCou].gr.total != cou[numOfCou].gr.finalMax + cou[numOfCou].gr.practicalMax + cou[numOfCou].gr.yearWorkMax + cou[numOfCou].gr.quizMax)
		{
			cout << "\nInvalid Total Marks! Please Try Again\n" << endl;
			return;
		}

		cout << "\nCourse added successfully!" << endl;
		numOfCou++;

		do {
			cout << "\nDo you want to add another course? (Y/N): ";
			cin >> cont;
			cout << endl;

			if (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N')
				cout << "Invalid choice! Please enter (Y/N)\n";

		} while (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N');

		if (cont == 'n' || cont == 'N')
			cout << "Returning to Courses Menu... \n" << endl;

	} while (cont == 'y' || cont == 'Y');
}

void viewCourses(int numOfCou, course cou[])
{
	if (numOfCou == 0)
	{
		cout << "\nNo Courses available\n" << endl;
		return;
	}
	cout << "\n====== Courses (" << numOfCou << ") ======\n\n";
	for (int j = 0; j < numOfCou; j++)
	{
		cout << "Course " << "[" << j + 1 << "]" << endl;

		cout << "Name: " << cou[j].name << endl;
		cout << "Credit Hours: " << cou[j].creditHours << endl;
		cout << "Academic Year: " << cou[j].academicYear << endl;
		cout << "Total Marks: " << cou[j].gr.total << endl;
		cout << "Final Max Marks: " << cou[j].gr.finalMax << endl;
		cout << "Practical Max Marks: " << cou[j].gr.practicalMax << endl;
		cout << "Year Work Max Marks: " << cou[j].gr.yearWorkMax << endl;
		cout << "Quiz Max Marks: " << cou[j].gr.quizMax << endl;

		cout << endl;
	}
}

void removeCourse(int& numOfCou, course cou[])
{
	if (numOfCou == 0)
	{
		cout << "No Courses available\n" << endl;
		return;
	}



	char again;
	do
	{
		int cntr = 1;

		cout << "====== Courses (" << numOfCou << ") ======\n";
		for (int i = 0; i < numOfCou; i++)
			cout << "[" << cntr++ << "] - " << cou[i].name << endl;

		string remCourse;
		cout << "\nEnter Name of Course you want to remove (enter '0' to exit): ";
		cin.ignore();
		getline(cin, remCourse);

		bool found = false;
		for (int i = 0; i < numOfCou; i++)
		{
			if (remCourse == "0")
			{
				cout << "\nReturning to Courses Menu...\n\n";
				return;
			}
			else if (remCourse == cou[i].name)
			{
				found = true;
				char confirm;
				do
				{
					cout << "Are you sure you want to remove \"" << cou[i].name << "\"? (Y/N): ";
					cin >> confirm;
					if (confirm != 'y' && confirm != 'n' && confirm != 'Y' && confirm != 'N')
						cout << "\nInvalid choice! Please enter (Y/N)\n";
				} while (confirm != 'y' && confirm != 'n' && confirm != 'Y' && confirm != 'N');

				if (confirm == 'y' || confirm == 'Y')
				{
					for (int j = i; j < numOfCou - 1; j++)
						cou[j] = cou[j + 1];
					numOfCou--;
					cout << "\nCourse removed successfully!\n\n";
				}
				else
					cout << "\nOperation Cancelled! Course remains unchanged\n" << endl;

				break;
			}
		}

		if (!found)
			cout << "\nCourse doesn't Exist, Please try again\n\n";

		do
		{
			cout << "Do you want to remove another course? (Y/N): ";
			cin >> again;

			if (again != 'y' && again != 'n' && again != 'Y' && again != 'N')
				cout << "\nInvalid Choice! Please enter (Y/N)\n";

			if (again == 'n' || again == 'N')
				cout << "\nReturning to Courses Menu... \n" << endl;

		} while (again != 'y' && again != 'n' && again != 'Y' && again != 'N');

	} while (again == 'y' || again == 'Y');
}

void stfCouMenu(int stfIndex, int numOfCou, course cou[], staff stf[])
{
	int choice;
	do
	{
		do
		{
			cout << "====== Staff Courses Menu ======" << endl;
			cout << "[1] - Select Courses to Teach" << endl;
			cout << "[2] - View Courses you Teach" << endl;
			cout << "[3] - Remove Courses you Teach" << endl;
			cout << "[0] - Back" << endl;
			cout << "-----------------------------" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			cout << endl;

			if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
				cout << "Invalid choice! Please try again" << "\n\n";

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

		switch (choice)
		{
		case 1:
			stfSelectCourse(stfIndex, numOfCou, stf, cou);
			break;

		case 2:
			stfViewCourses(stfIndex, stf);
			break;

		case 3:
			stfRemoveCourse(stfIndex, numOfCou, cou, stf);
			break;

		case 0:
			cout << "Returning to the Staff Dashboard... \n" << endl;
			return;
		}
	} while (true);
}

void stfSelectCourse(int stfIndex, int numOfCou, staff stf[], course cou[])
{

	int courseCount = stf[stfIndex].stfNumOfCou;
	string temp_courses[10];
	for (int i = 0; i < courseCount; i++)
		temp_courses[i] = stf[stfIndex].teachingCourses[i];

	if (courseCount >= 10)
	{
		cout << "You have reached the maximum number of teaching courses (10)!\n" << endl;
		return;
	}


	int cntr = 1;

	cout << "====== Courses (" << numOfCou << ") ======\n";
	for (int i = 0; i < numOfCou; i++)
		cout << "[" << cntr++ << "] - " << cou[i].name << endl;

	cout << "\nEnter name of your teaching courses (Enter '0' to finish): ";
	cin.ignore();

	while (courseCount < 10)
	{
		string temp;
		getline(cin, temp);

		if (temp == "0")
		{
			cout << "\nReturning to Staff Courses Menu... \n" << endl;
			break;
		}

		bool found = false;
		for (int i = 0; i < numOfCou; i++) {
			if (cou[i].name == temp) {
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "\nCourse is not available! Please try again\n\n";
			cout << "Enter another course (or '0' to finish): ";
			continue;
		}

		bool alreadyAdded = false;
		for (int j = 0; j < courseCount; j++) {
			if (temp_courses[j] == temp) {
				cout << "\nAlready added! Please try again\n\n";
				cout << "Enter another course (or '0' to finish): ";
				alreadyAdded = true;
				break;
			}
		}

		if (!alreadyAdded) {
			temp_courses[courseCount] = temp;
			courseCount++;
			cout << "\nCourse added successfully!\n\n";

			for (int i = 0; i < numOfCou; i++) {
				if (cou[i].name == temp) {
					for (int j = 0; j < 5; j++) {
						if (cou[i].academicMemberName[j] == "") {
							cou[i].academicMemberName[j] = stf[stfIndex].inf.name;
							break;
						}
					}
					break;
				}
			}

			if (courseCount == 10) {
				cout << "You have reached the maximum number of courses (10)!\n" << endl;
				break;
			}

			cout << "Enter another course (or '0' to finish): ";
		}
	}

	for (int i = 0; i < courseCount; i++)
		stf[stfIndex].teachingCourses[i] = temp_courses[i];

	stf[stfIndex].stfNumOfCou = courseCount;
}

void stfViewCourses(int stfIndex, staff stf[])
{
	int cntr = 1;

	if (stf[stfIndex].stfNumOfCou == 0)
	{
		cout << "No Courses available\n\n";
		return;
	}

	cout << "====== Courses You Teach (" << stf[stfIndex].stfNumOfCou << ") ======" << endl;
	for (int i = 0; i < stf[stfIndex].stfNumOfCou; i++)
	{
		cout << "[" << cntr++ << "] - " << stf[stfIndex].teachingCourses[i] << endl;
	}
	cout << endl;
}

void stfRemoveCourse(int stfIndex, int numOfCou, course cou[], staff stf[])
{
	if (stf[stfIndex].stfNumOfCou == 0)
	{
		cout << "No Courses available\n" << endl;
		return;
	}

	int cntr = 1;

	cout << "====== Courses You Teach (" << stf[stfIndex].stfNumOfCou << ") ======\n";
	for (int i = 0; i < stf[stfIndex].stfNumOfCou; i++)
		cout << "[" << cntr++ << "] - " << stf[stfIndex].teachingCourses[i] << endl;

	char again;
	do
	{
		string remCourse;
		cout << "\nEnter Name of Course you want to remove: ";
		cin.ignore();
		getline(cin, remCourse);

		bool found = false;
		for (int i = 0; i < stf[stfIndex].stfNumOfCou; i++)
		{
			if (remCourse == stf[stfIndex].teachingCourses[i])
			{
				found = true;
				char confirm;
				do
				{
					cout << "Are you sure you want to remove \"" << stf[stfIndex].teachingCourses[i] << "\"? (Y/N): ";
					cin >> confirm;
					if (confirm != 'y' && confirm != 'n' && confirm != 'Y' && confirm != 'N')
						cout << "\nInvalid choice! Please enter (Y/N)\n";
				} while (confirm != 'y' && confirm != 'n' && confirm != 'Y' && confirm != 'N');

				if (confirm == 'y' || confirm == 'Y')
				{
					for (int j = i; j < stf[stfIndex].stfNumOfCou - 1; j++)
						stf[stfIndex].teachingCourses[j] = stf[stfIndex].teachingCourses[j + 1];
					stf[stfIndex].teachingCourses[stf[stfIndex].stfNumOfCou - 1] = "";

					stf[stfIndex].stfNumOfCou--;

					for (int k = 0; k < numOfCou; k++)
					{
						if (cou[k].name == remCourse)
						{
							for (int m = 0; m < 5; m++)
							{
								if (cou[k].academicMemberName[m] == stf[stfIndex].inf.name)
								{
									for (int n = m; n < 4; n++)
										cou[k].academicMemberName[n] = cou[k].academicMemberName[n + 1];
									cou[k].academicMemberName[4] = "";
									break;
								}
							}
							break;
						}
					}
					cout << "\nCourse removed successfully!\n\n";
				}
				else
					cout << "\nOperation Cancelled! Course remains unchanged\n" << endl;

				break;
			}
		}

		if (!found)
			cout << "\nCourse doesn't Exist, Please try again\n\n";

		do
		{
			cout << "Do you want to remove another course? (Y/N): ";
			cin >> again;

			if (again != 'y' && again != 'n' && again != 'Y' && again != 'N')
				cout << "\nInvalid Choice! Please enter (Y/N)\n";

			if (again == 'n' || again == 'N')
				cout << "\nReturning to Staff Courses Menu... \n" << endl;

		} while (again != 'y' && again != 'n' && again != 'Y' && again != 'N');

	} while (again == 'y' || again == 'Y');
}

void couMenu(int& numOfCou, course cou[])
{
	int choice;
	do
	{
		do
		{
			cout << "====== Courses Menu ======" << endl;
			cout << "[1] - Add Course" << endl;
			cout << "[2] - Remove Course" << endl;
			cout << "[3] - View Courses" << endl;
			cout << "[0] - Back" << endl;
			cout << "--------------------------\n";
			cout << "Enter your choice: ";
			cin >> choice;
			cout << endl;

			if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
				cout << "Invalid choice! Please try again\n\n";

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

		switch (choice)
		{
		case 1:
			addCourse(numOfCou, cou);
			break;

		case 2:
			removeCourse(numOfCou, cou);
			break;

		case 3:
			viewCourses(numOfCou, cou);
			break;

		case 0:
			cout << "Returning to Administration Dashboard... \n" << endl;
			return;
		}
	} while (true);
}

void requestAppointment(int stuIndex, int numOfStf, int& numOfApp, appointment app[], student stu[], staff stf[])
{

	int choice;

	if (numOfApp >= SIZE)
	{
		cout << "\nMaximum number of appointments reached!\n" << endl;
		return;
	}

	if (numOfStf == 0)
	{
		cout << "\nNo staff members available\n" << endl;
		return;
	}

	cout << "\n====== Request Appointment ======" << endl;


	app[numOfApp].studentID = stu[stuIndex].inf.id;
	app[numOfApp].studentName = stu[stuIndex].inf.name;
	cout << "Your ID: " << app[numOfApp].studentID << endl;


	cout << "\nAvailable Staff Members:\n";
	for (int i = 0; i < numOfStf; i++)
	{
		cout << "[" << i + 1 << "] - " << stf[i].inf.name << " (" << stf[i].department << ")" << endl;
	}

	cout << "\nChoose Staff Member number: ";
	cin >> choice;

	if (choice < 1 || choice > numOfStf)
	{
		cout << "\nInvalid choice! Please try again\n" << endl;
		return;
	}

	app[numOfApp].stfName = stf[choice - 1].inf.name;
	app[numOfApp].stfIndex = choice - 1;

	do {
		cout << "Enter Day (1-31): ";
		cin >> app[numOfApp].sch.day;

		if (app[numOfApp].sch.day < 1 || app[numOfApp].sch.day > 31)
		{
			cout << "\nInvalid day! Please enter a value between 1 and 31\n\n";
		}

	} while (app[numOfApp].sch.day < 1 || app[numOfApp].sch.day > 31);


	do {
		cout << "Enter Month (1-12): ";
		cin >> app[numOfApp].sch.month;

		if (app[numOfApp].sch.month < 1 || app[numOfApp].sch.month > 12)
		{
			cout << "\nInvalid month! Please enter a value between 1 and 12\n\n";
		}

	} while (app[numOfApp].sch.month < 1 || app[numOfApp].sch.month > 12);

	do {
		cout << "Enter Hour (8-18): ";
		cin >> app[numOfApp].sch.hour;

		if (app[numOfApp].sch.hour < 8 || app[numOfApp].sch.hour > 18)
		{
			cout << "\nInvalid hour! Working hours are from 8 to 18\n\n";
		}

	} while (app[numOfApp].sch.hour < 8 || app[numOfApp].sch.hour > 18);

	do {
		cout << "Enter Minute (0, 15, 30, 45): ";
		cin >> app[numOfApp].sch.minute;

		if (app[numOfApp].sch.minute != 0 &&
			app[numOfApp].sch.minute != 15 &&
			app[numOfApp].sch.minute != 30 &&
			app[numOfApp].sch.minute != 45)
		{
			cout << "\nInvalid minute! Choose (0, 15, 30, or 45)\n\n";
		}
	} while (app[numOfApp].sch.minute != 0 && app[numOfApp].sch.minute != 15 && app[numOfApp].sch.minute != 30 && app[numOfApp].sch.minute != 45);

	for (int i = 0; i < numOfApp; i++)
	{
		if (app[i].stfName == app[numOfApp].stfName &&
			app[i].sch.day == app[numOfApp].sch.day &&
			app[i].sch.month == app[numOfApp].sch.month &&
			app[i].sch.hour == app[numOfApp].sch.hour &&
			app[i].sch.minute == app[numOfApp].sch.minute)
		{
			cout << "\nThis time slot is already requested for this Staff Member!\n" << endl;
			return;
		}
	}


	cout << "\nAppointment requested successfully with " << stf[choice - 1].position << " " << app[numOfApp].stfName << "!\n" << endl;

	numOfApp++;
}

void calculateGrade(int couIdx, grade& g, course cou[])
{
	g.total = g.final + g.quiz + g.practical + g.yearWork;

	float percentage = (g.total / cou[couIdx].gr.total) * 100.0;
	g.percentage = percentage;

	if (percentage >= 97)
		g.letter = "A+";
	else if (percentage >= 93)
		g.letter = "A";
	else if (percentage >= 89)
		g.letter = "A-";
	else if (percentage >= 84)
		g.letter = "B+";
	else if (percentage >= 80)
		g.letter = "B";
	else if (percentage >= 76)
		g.letter = "B-";
	else if (percentage >= 73)
		g.letter = "C+";
	else if (percentage >= 70)
		g.letter = "C";
	else if (percentage >= 67)
		g.letter = "C-";
	else if (percentage >= 64)
		g.letter = "D+";
	else if (percentage >= 60)
		g.letter = "D";
	else
		g.letter = "F";
}



void registerCourses(int numOfCou, int stuIndex, student stu[], course cou[])
{
	if (numOfCou == 0) {
		cout << "No Courses available\n" << endl;
		return;
	}

	int count = 0;
	for (int i = 0; i < numOfCou; i++) {
		if (stu[stuIndex].academicYear == cou[i].academicYear)
			count++;
	}

	int cntr = 1;

	cout << "====== Available Courses (" << count << ") ======\n";
	for (int i = 0; i < numOfCou; i++)
	{
		if (stu[stuIndex].academicYear == cou[i].academicYear)
		{
			cout << "[" << cntr++ << "] - " << cou[i].name << endl;
		}
	}

	cout << endl;

	char cont;
	do {
		cin.ignore();
		string regCou;
		cout << "Enter name of Course that you want to register: ";
		getline(cin, regCou);

		bool found = false;
		for (int i = 0; i < numOfCou; i++) {
			if (regCou == cou[i].name && cou[i].academicYear == stu[stuIndex].academicYear)
			{
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "\nCourse is not available! Please try again\n\n";
		}
		else {
			bool alreadyReg = false;
			for (int j = 0; j < 10; j++) {
				if (stu[stuIndex].studentCourses[j] == regCou) {
					cout << "\nAlready registered!\n\n";
					alreadyReg = true;
					break;
				}
			}
			if (!alreadyReg) {
				bool registered = false;
				for (int i = 0; i < 10; i++) {
					if (stu[stuIndex].studentCourses[i] == "") {
						stu[stuIndex].studentCourses[i] = regCou;
						cout << "\nCourse registered successfully!\n\n";
						registered = true;

						for (int j = 0; j < numOfCou; j++) {
							if (cou[j].name == regCou) {
								cou[j].enr.studentIndex[cou[j].studentCount] = stuIndex;
								cou[j].studentCount++;
								break;
							}
						}

						break;
					}
				}
				if (!registered)
					cout << "Maximum courses reached! Cannot register more\n\n";
			}
		}

		do {
			cout << "Do you want to register another course? (Y/N): ";
			cin >> cont;
			cout << endl;

			if (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N')
				cout << "Invalid choice! Please enter (Y/N)\n";

		} while (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N');

		if (cont == 'n' || cont == 'N')
			cout << "Returning to Course Registration Menu... \n" << endl;

	} while (cont == 'y' || cont == 'Y');
}

void dropCourses(int stuIndex, int numOfCou, student stu[], course cou[]) {

	int count = 0;
	char cont;

	for (int i = 0; i < 10; i++) {
		if (stu[stuIndex].studentCourses[i] != "")
			count++;
	}
	if (count == 0) {
		cout << "No Courses Registered\n\n";
		return;
	}
	cout << "====== Registered Courses (" << count << ") ======\n";
	for (int i = 0; i < 10; i++)
	{
		if (stu[stuIndex].studentCourses[i] != "")
			cout << "[" << i + 1 << "] " << "- " << stu[stuIndex].studentCourses[i] << endl;
	}

	cout << endl;

	do
	{
		cin.ignore();
		string dropCou;
		cout << "Enter name of Course that you want to drop: ";
		getline(cin, dropCou);

		bool found = false;
		for (int i = 0; i < 10; i++) {
			if (stu[stuIndex].studentCourses[i] == dropCou) {

				for (int j = 0; j < numOfCou; j++) {
					if (cou[j].name == dropCou) {
						for (int k = 0; k < cou[j].studentCount; k++) {
							if (cou[j].enr.studentIndex[k] == stuIndex) {
								cou[j].enr.studentIndex[k] = cou[j].enr.studentIndex[cou[j].studentCount - 1];
								cou[j].enr.g[k] = cou[j].enr.g[cou[j].studentCount - 1];
								cou[j].enr.g[cou[j].studentCount - 1] = {};
								cou[j].studentCount--;
								break;
							}
						}
						break;
					}
				}

				for (int j = i; j < 9; j++) {
					stu[stuIndex].studentCourses[j] = stu[stuIndex].studentCourses[j + 1];
					stu[stuIndex].studentCourses[9] = "";
				}
				found = true;
				cout << "\nCourse dropped successfully!\n\n";
				count--;
				break;
			}
		}

		if (!found)
			cout << "\nCourse is not available! Please try again\n\n";

		do {
			cout << "Do you want to drop another course? (Y/N): ";
			cin >> cont;
			cout << endl;

			if (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N')
				cout << "Invalid choice! Please enter (Y/N)\n";

		} while (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N');

		if (cont == 'n' || cont == 'N')
			cout << "Returning to Course Registration Menu... \n" << endl;

	} while (cont == 'y' || cont == 'Y');
}

void viewRegCou(int stuIndex, student stu[]) {

	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (stu[stuIndex].studentCourses[i] != "")
			count++;
	}
	if (count == 0) {
		cout << "No Courses Registered\n\n";
		return;
	}

	cout << "====== Registered Courses (" << count << ") ======\n";
	for (int i = 0; i < 10; i++) {
		if (stu[stuIndex].studentCourses[i] != "")
			cout << "[" << i + 1 << "] " << "- " << stu[stuIndex].studentCourses[i] << endl;
	}
	cout << endl;
}


void couRegMenu(int& numOfCou, int stuIndex, student stu[], course cou[]) {
	int choice;
	do {
		cout << "====== Course Registration Menu ======\n";
		cout << "[1] - Register Courses\n";
		cout << "[2] - View Available Courses\n";
		cout << "[3] - Drop Courses\n";
		cout << "[4] - View Registered Courses\n";
		cout << "[0] - Back\n";
		cout << "---------------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1: registerCourses(numOfCou, stuIndex, stu, cou);
			break;
		case 2: availableCourses(numOfCou, stuIndex, stu, cou);
			break;
		case 3: dropCourses(stuIndex, numOfCou, stu, cou);
			break;
		case 4: viewRegCou(stuIndex, stu);
			break;
		case 0: cout << "Returning to Student Dashboard... \n\n";
			return;
		default: cout << "Invalid choice! Please try again\n\n";
		}
	} while (true);
}

void availableCourses(int numOfCou, int stuIndex, student stu[], course cou[])
{
	int cntr = 1;
	int count = 0;
	for (int i = 0; i < numOfCou; i++) {
		if (stu[stuIndex].academicYear == cou[i].academicYear)
			count++;
	}

	cout << "====== Available Courses (" << count << ") ======" << endl;
	for (int i = 0; i < numOfCou; i++)
	{
		if (stu[stuIndex].academicYear == cou[i].academicYear)
		{
			cout << "[" << cntr++ << "] - " << cou[i].name << endl;
		}
	}
	cout << endl;
}

void exmMenu(int numOfCou, int& numOfExm, course cou[], exam exm[])
{
	int choice;
	do
	{
		do
		{
			cout << "====== Exam Schedule Menu ======" << endl;
			cout << "[1] - Set Exam Schedule" << endl;
			cout << "[2] - View Exam Schedule" << endl;
			cout << "[3] - Remove Exam Schedule" << endl;
			cout << "[0] - Back" << endl;
			cout << "--------------------------------" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			cout << endl;

			if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
				cout << "Invalid choice! Please try again" << "\n\n";

		} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

		switch (choice)
		{
		case 1:
			setExamSchedule(numOfCou, numOfExm, cou, exm);
			break;

		case 2:
			viewExamSchedule(numOfCou, numOfExm, cou, exm);
			break;

		case 3:
			removeExamSchedule(numOfCou, numOfExm, cou, exm);
			break;

		case 0:
			cout << "Returning to Administration Dashboard... \n" << endl;
			return;
		}
	} while (true);
}

void setExamSchedule(int numOfCou, int& numOfExm, course cou[], exam exm[])
{
	if (numOfCou == 0)
	{
		cout << "\nNo courses available to set Exam Schedule!\n" << endl;
		return;
	}

	char again;
	do
	{
		cout << "====== Available Courses (" << numOfCou << ") ======" << endl;
		for (int i = 0; i < numOfCou; i++)
			cout << "[" << i + 1 << "] - " << cou[i].name << endl;
		cout << endl;

		int courseChoice;
		do
		{
			cout << "Select a Course (1-" << numOfCou << ", [0] to exit): ";
			cin >> courseChoice;

			if (courseChoice == 0)
			{
				cout << "\nReturning to Exam Schedule Menu...\n\n";
				return;
			}
			else if (courseChoice < 1 || courseChoice > numOfCou)
				cout << "\nInvalid choice! Please enter a value between 1 and " << numOfCou << "\n\n";

		} while (courseChoice < 1 || courseChoice > numOfCou);

		int idx = courseChoice - 1;

		cout << "\nSetting Exam Schedule for: " << cou[idx].name << endl;
		cout << "-------------------------------" << endl;

		int d, mo, y, h, mi;

		do
		{
			cout << "Enter Exam Day (1-31): ";
			cin >> d;
			if (d < 1 || d > 31) cout << "\nInvalid Day! Please enter a value between 1 and 31\n\n";
		} while (d < 1 || d > 31);

		do
		{
			cout << "Enter Exam Month (1-12): ";
			cin >> mo;
			if (mo < 1 || mo > 12) cout << "\nInvalid Month! Please enter a value between 1 and 12\n\n";
		} while (mo < 1 || mo > 12);

		do
		{
			cout << "Enter Exam Year (2026-2030): ";
			cin >> y;
			if (y < 2026 || y > 2030) cout << "\nInvalid Year! Please enter a value between 2026 and 2030\n\n";
		} while (y < 2026 || y > 2030);

		do
		{
			cout << "Enter Exam Hour (8-18): ";
			cin >> h;
			if (h < 8 || h > 18) cout << "\nInvalid Hour! Please enter a value between 8 and 18\n\n";
		} while (h < 8 || h > 18);

		do
		{
			cout << "Enter Exam Minute (0-59): ";
			cin >> mi;
			if (mi < 0 || mi > 59) cout << "\nInvalid Minute! Please enter a value between 0 and 59\n\n";
		} while (mi < 0 || mi > 59);

		int examIdx = -1;
		for (int i = 0; i < numOfExm; i++) {
			if (exm[i].co.name == cou[idx].name) {
				examIdx = i;
				break;
			}
		}
		if (examIdx == -1) {
			examIdx = numOfExm;
			numOfExm++;
		}

		exm[examIdx].co.name = cou[idx].name;
		exm[examIdx].co.academicYear = cou[idx].academicYear;
		exm[examIdx].sch.day = d;
		exm[examIdx].sch.month = mo;
		exm[examIdx].sch.year = y;
		exm[examIdx].sch.hour = h;
		exm[examIdx].sch.minute = mi;

		cout << "\nExam Schedule has been set successfully for " << cou[idx].name << "!\n" << endl;

		do {
			cout << "Do you want to set another Exam Schedule (Y/N): ";
			cin >> again;
			cout << endl;

			if (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
				cout << "Invalid choice! Please enter (Y/N)\n";

		} while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

		if (again == 'n' || again == 'N')
			cout << "Returning to Exam Schedule Menu... \n" << endl;

	} while (again == 'y' || again == 'Y');
}

void viewExamSchedule(int numOfCou, int numOfExm, course cou[], exam exm[])
{
	if (numOfCou == 0)
	{
		cout << "No courses available!\n" << endl;
		return;
	}

	if (numOfExm == 0)
	{
		cout << "No Exam Schedules have been set yet!\n" << endl;
		return;
	}


	cout << "====== Exam Schedule (" << numOfExm << ") ======" << endl;
	for (int i = 0; i < numOfExm; i++)
	{
		cout << "Course : " << exm[i].co.name << endl;
		cout << "Year   : " << exm[i].co.academicYear << endl;
		cout << "Date   : " << exm[i].sch.day << "/"
			<< exm[i].sch.month << "/"
			<< exm[i].sch.year << endl;

		cout << "Time   : ";
		if (exm[i].sch.hour < 10)   cout << "0";
		cout << exm[i].sch.hour << ":";
		if (exm[i].sch.minute < 10) cout << "0";
		cout << exm[i].sch.minute << endl;

		cout << endl;

	}

}


void removeExamSchedule(int numOfCou, int& numOfExm, course cou[], exam exm[])
{
	if (numOfCou == 0)
	{
		cout << "No courses available!\n" << endl;
		return;
	}

	if (numOfExm == 0)
	{
		cout << "No Exam Schedules have been set yet!\n" << endl;
		return;
	}

	char again;
	do
	{
		int cntr = 1;

		cout << "====== Exam Schedule (" << numOfExm << ") ======" << endl;
		for (int i = 0; i < numOfExm; i++)
			if (exm[i].sch.year != 0)
				cout << "[" << cntr++ << "] - " << exm[i].co.name << endl;
		cout << endl;

		int courseChoice;
		do
		{
			cout << "Select a course to remove its Exam Schedule (1-" << cntr - 1 << ", [0] to exit): ";
			cin >> courseChoice;

			if (courseChoice == 0)
			{
				cout << "\nReturning to Exam Schedule Menu...\n\n";
				return;
			}
			else if (courseChoice < 1 || courseChoice >(cntr - 1))
				cout << "\nInvalid choice! Please try again\n\n";
			else if (exm[courseChoice - 1].sch.year == 0)
				cout << "\nThis Course has no Exam Schedule! Please enter a value between 1 and 12\n\n";

		} while (courseChoice < 1 || courseChoice >(cntr - 1) || exm[courseChoice - 1].sch.year == 0);

		int idx = courseChoice - 1;

		char confirm;
		cout << "Are you sure you want to remove the exam schedule for " << exm[idx].co.name << " (Y/N): ";
		cin >> confirm;

		while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N')
		{
			cout << "\nInvalid choice! Please enter (Y/N)\n";
			cout << "Are you sure you want to remove the exam schedule for " << exm[idx].co.name << " (Y/N): ";
			cin >> confirm;
		}


		if (confirm == 'y' || confirm == 'Y') {

			string removedName = exm[idx].co.name;
			for (int i = idx; i < numOfExm - 1; i++)
				exm[i] = exm[i + 1];

			exm[numOfExm - 1].co.name = "";
			exm[numOfExm - 1].sch.day = 0;
			exm[numOfExm - 1].sch.month = 0;
			exm[numOfExm - 1].sch.year = 0;
			exm[numOfExm - 1].sch.hour = 0;
			exm[numOfExm - 1].sch.minute = 0;
			numOfExm--;

			cout << "\nExam schedule for " << removedName << " removed successfully!\n" << endl;
		}
		else if (confirm == 'n' || confirm == 'N') {
			cout << "\nOperation Cancelled! Exam Schedule remains unchanged\n" << endl;
		}
		else
		{
			cout << "\nInvalid choice! Please enter (Y/N)\n";
		}

		bool stillHasExams = false;
		for (int i = 0; i < numOfExm; i++)
			if (exm[i].sch.year != 0)
			{
				stillHasExams = true;
				break;
			}

		if (!stillHasExams)
		{
			cout << "No more exam schedules to remove.\n" << endl;
			return;
		}

		do
		{
			cout << "Do you want to remove another exam schedule? (Y/N): ";
			cin >> again;
			if (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
				cout << "\nInvalid choice! Please enter (Y/N)\n";
			if (again == 'n' || again == 'N')
				cout << "\nReturning to Exam Schedule Menu... " << endl;
		} while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

		cout << endl;

	} while (again == 'y' || again == 'Y');
}

void stuViewExamSchedule(int stuIndex, int numOfCou, int numOfExm, course cou[], exam exm[], student stu[], staff stf[], administration adm[])
{
	int StuNumOfCou = 0;

	for (int i = 0; i < 10; i++)
		if (stu[stuIndex].studentCourses[i] != "") StuNumOfCou++;

	if (numOfCou == 0 || StuNumOfCou == 0)
	{
		cout << "No courses available!\n" << endl;
		return;
	}

	if (numOfExm == 0)
	{
		cout << "No Exam Schedules have been set yet!\n" << endl;
		return;
	}

	int cntr = 0;
	for (int i = 0; i < numOfExm; i++)
	{
		if (exm[i].co.academicYear == stu[stuIndex].academicYear)
			cntr++;
	}

	cout << "====== Exam Schedule (" << cntr << ") ======" << endl;
	for (int i = 0; i < numOfExm; i++)
	{
		if (exm[i].co.academicYear == stu[stuIndex].academicYear)
		{
			cout << "Course : " << exm[i].co.name << endl;
			cout << "Year   : " << exm[i].co.academicYear << endl;
			cout << "Date   : " << exm[i].sch.day << "/"
				<< exm[i].sch.month << "/"
				<< exm[i].sch.year << endl;

			cout << "Time   : ";
			if (exm[i].sch.hour < 10)   cout << "0";
			cout << exm[i].sch.hour << ":";
			if (exm[i].sch.minute < 10) cout << "0";
			cout << exm[i].sch.minute << endl;

			cout << endl;
		}

	}

}


void stuProfile(int stuIndex, int numOfStu, int numOfStf, int numOfAdm, student stu[], staff stf[], administration adm[])
{
	int choice;
	do
	{
		cout << "====== Student Profile ======" << endl;
		cout << "[1] - Name         : " << stu[stuIndex].inf.name << endl;
		cout << "[2] - Mobile       : " << stu[stuIndex].inf.mobileNumber << endl;
		cout << "[3] - Address      : " << stu[stuIndex].inf.address << endl;
		cout << "[4] - Department   : " << stu[stuIndex].department << endl;
		cout << "[5] - Academic Year: " << stu[stuIndex].academicYear << endl;
		cout << "[1-5] - Edit Field" << endl;
		cout << "-----------------------------" << endl;
		cout << "[0] - Back" << endl;
		cout << "---------------------------" << endl;


		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;
		cin.ignore();

		switch (choice)
		{
		case 1:
		{
			string name;
			cout << "Enter new name (Enter '0' to exit): ";
			getline(cin, name);
			if (name == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			else
			{
				cout << "\nName changed successfully!\n\n";
				stu[stuIndex].inf.name = name;
			}
			break;
		}

		case 2:
		{
			string phone;
			bool taken = false;
			cout << "Enter new mobile number (Enter '0' to exit): ";
			getline(cin, phone);

			if (phone == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			if (phone.length() != 11)
			{
				cout << "\nInvalid mobile number! Must be exactly 11 digits\n\n";
				break;
			}
			if (isMobileTaken(phone, numOfStu, numOfStf, numOfAdm, stu, stf, adm))
			{
				cout << "\nMobile number was taken before, Please try again\n\n";
				break;
			}
			stu[stuIndex].inf.mobileNumber = phone;
			cout << "\nMobile Number changed successfully!\n\n";
			break;
		}

		case 3:
		{
			string address;
			cout << "Enter new address (Enter '0' to exit): ";
			getline(cin, address);
			if (address == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			else
			{
				cout << "\nAddress changed successfully!\n\n";
				stu[stuIndex].inf.address = address;
			}
			break;
		}
		case 4:
		{
			string dep;
			cout << "Enter new department (Enter '0' to exit): ";
			getline(cin, dep);
			if (dep == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			else
			{
				cout << "\nDepartment changed successfully!\n\n";
				stu[stuIndex].department = dep;
			}
			break;
		}
		case 5:
		{
			int academicYear;
			cout << "Enter new academic year (Enter '0' to exit): ";
			cin >> academicYear;

			if (academicYear == 0)
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			if (academicYear > 4 || academicYear < 1)
			{
				cout << "\nInvalid choice! Please enter a value between 1 and 4\n";
				break;
			}
			else
			{
				cout << "\nAcademic Year changed successfully!\n\n";
				stu[stuIndex].academicYear = academicYear;
			}
			break;
		}

		case 0:
			cout << "Returning to Student Dashboard...\n\n";
			break;

		default:
			cout << "Invalid choice! Please try again\n\n";
		}

	} while (choice != 0);
}



void stfProfile(int stfIndex, int numOfStu, int numOfStf, int numOfAdm, student stu[], staff stf[], administration adm[])
{
	int choice;
	do
	{
		cout << "====== Staff Profile ======" << endl;
		cout << "[1] - Name         : " << stf[stfIndex].inf.name << endl;
		cout << "[2] - Mobile       : " << stf[stfIndex].inf.mobileNumber << endl;
		cout << "[3] - Address      : " << stf[stfIndex].inf.address << endl;
		cout << "[4] - Department   : " << stf[stfIndex].department << endl;
		cout << "[5] - Position     : " << stf[stfIndex].position << endl;
		cout << "[1-5] - Edit Field" << endl;
		cout << "---------------------------" << endl;
		cout << "[0] - Back" << endl;
		cout << "---------------------------" << endl;


		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;
		cin.ignore();

		switch (choice)
		{
		case 1:
		{
			string name;
			cout << "Enter new name (Enter '0' to exit): ";
			getline(cin, name);
			if (name == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			else
			{
				cout << "\nName changed successfully!\n\n";
				stf[stfIndex].inf.name = name;
			}
			break;
		}

		case 2:
		{
			string phone;
			bool taken = false;
			cout << "Enter new mobile number (Enter '0' to exit): ";
			getline(cin, phone);

			if (phone == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			if (phone.length() != 11)
			{
				cout << "\nInvalid mobile number! Must be exactly 11 digits\n\n";
				break;
			}
			if (isMobileTaken(phone, numOfStu, numOfStf, numOfAdm, stu, stf, adm))
			{
				cout << "\nMobile number was taken before, Please try again\n\n";
				break;
			}
			stf[stfIndex].inf.mobileNumber = phone;
			cout << "\nMobile Number changed successfully!\n\n";
			break;
		}

		case 3:
		{
			string address;
			cout << "Enter new address (Enter '0' to exit): ";
			getline(cin, address);
			if (address == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			else
			{
				cout << "\nAddress changed successfully!\n\n";
				stf[stfIndex].inf.address = address;
			}
			break;
		}
		case 4:
		{
			string dep;
			cout << "Enter new department (Enter '0' to exit): ";
			getline(cin, dep);
			if (dep == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			else
			{
				cout << "\nDepartment changed successfully!\n\n";
				stf[stfIndex].department = dep;
			}
			break;
		}

		case 5:
		{
			string pos;
			cout << "Enter new department (Enter '0' to exit): ";
			getline(cin, pos);
			if (pos == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			else
			{
				cout << "\nPosition changed successfully!\n\n";
				stf[stfIndex].position = pos;
			}
			break;
		}

		case 0:
			cout << "Returning to Staff Dashboard...\n\n";
			break;

		default:
			cout << "Invalid choice! Please try again\n\n";
		}

	} while (choice != 0);
}


void admProfile(int admIndex, int numOfStu, int numOfStf, int numOfAdm, student stu[], staff stf[], administration adm[])
{
	int choice;
	do
	{
		cout << "====== Admin Profile ======" << endl;
		cout << "[1] - Name         : " << adm[admIndex].inf.name << endl;
		cout << "[2] - Mobile       : " << adm[admIndex].inf.mobileNumber << endl;
		cout << "[3] - Address      : " << adm[admIndex].inf.address << endl;
		cout << "[4] - Position     : " << adm[admIndex].position << endl;
		cout << "[1-4] - Edit Field" << endl;
		cout << "-----------------------------" << endl;
		cout << "[0] - Back" << endl;
		cout << "-----------------------------" << endl;


		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;
		cin.ignore();

		switch (choice)
		{
		case 1:
		{
			string name;
			cout << "Enter new name (Enter '0' to exit): ";
			getline(cin, name);
			if (name == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			else
			{
				cout << "\nName changed successfully!\n\n";
				adm[admIndex].inf.name = name;
			}
			break;
		}

		case 2:
		{
			string phone;
			bool taken = false;
			cout << "Enter new mobile number (Enter '0' to exit): ";
			getline(cin, phone);

			if (phone == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			if (phone.length() != 11)
			{
				cout << "\nInvalid mobile number! Must be exactly 11 digits\n\n";
				break;
			}
			if (isMobileTaken(phone, numOfStu, numOfStf, numOfAdm, stu, stf, adm))
			{
				cout << "\nMobile number was taken before, Please try again\n\n";
				break;
			}
			adm[admIndex].inf.mobileNumber = phone;
			cout << "\nMobile Number changed successfully!\n\n";
			break;
		}

		case 3:
		{
			string address;
			cout << "Enter new address (Enter '0' to exit): ";
			getline(cin, address);
			if (address == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			else
			{
				cout << "\nAddress changed successfully!\n\n";
				adm[admIndex].inf.address = address;
			}
			break;
		}

		case 4:
		{
			string pos;
			cout << "Enter new department (Enter '0' to exit): ";
			getline(cin, pos);
			if (pos == "0")
			{
				cout << "\nReturning to your Profile...\n\n";
				break;
			}
			else
			{
				cout << "\nPosition changed successfully!\n\n";
				adm[admIndex].position = pos;
			}
			break;
		}

		case 0:
			cout << "Returning to Administration Dashboard...\n\n";
			break;

		default:
			cout << "Invalid choice! Please try again\n\n";
		}

	} while (choice != 0);
}

void setGrades(int stfIndex, int numOfCou, course cou[], student stu[], staff stf[])
{
	int coursemap[10];
	int stfCouCount = 0;

	if (stf[stfIndex].stfNumOfCou == 0)
	{
		cout << "You have no courses assigned yet!\n\n";
		return;
	}

	char again;
	do
	{
		stfCouCount = 0;
		cout << "====== Courses You Teach ======\n";

		for (int i = 0; i < numOfCou; i++)
			for (int j = 0; j < 10; j++)
				if (stf[stfIndex].teachingCourses[j] == cou[i].name)
				{
					cout << "[" << stfCouCount + 1 << "] - " << cou[i].name << endl;
					coursemap[stfCouCount] = i;
					stfCouCount++;
				}

		stf[stfIndex].stfNumOfCou = stfCouCount;

		int choice;
		cout << "\nChoose a course (1-" << stfCouCount << "): ";
		cin >> choice;

		if (choice < 1 || choice > stfCouCount)
		{
			cout << "\nInvalid choice! Please try again\n\n";
			return;
		}

		int couIdx = coursemap[choice - 1];

		if (cou[couIdx].studentCount == 0)
		{
			cout << "\nNo students enrolled in this course yet!\n\n";
		}
		else
		{
			cout << "\n====== Students In " << cou[couIdx].name << " (" << cou[couIdx].studentCount << ") ======\n";

			for (int i = 0; i < cou[couIdx].studentCount; i++)
			{
				int stuIdx = cou[couIdx].enr.studentIndex[i];
				cout << "[" << i + 1 << "] "
					<< "ID: " << stu[stuIdx].inf.id << " | "
					<< "Name: " << stu[stuIdx].inf.name << " | "
					<< "Year: " << stu[stuIdx].academicYear << " | "
					<< "Department: " << stu[stuIdx].department << endl;
			}

			int stuChoice;
			cout << "\nChoose a student (1-" << cou[couIdx].studentCount << "): ";
			cin >> stuChoice;

			if (stuChoice < 1 || stuChoice > cou[couIdx].studentCount)
			{
				cout << "\nInvalid choice! Please try again\n\n";
				return;
			}

			int stuIdx = cou[couIdx].enr.studentIndex[stuChoice - 1];
			grade& g = cou[couIdx].enr.g[stuChoice - 1];

			cout << "\nEntering Grades for: " << stu[stuIdx].inf.name << endl;
			cout << "*NOTE* - The total marks for this course are: " << cou[couIdx].gr.total << "\n\n";

			do
			{
				cout << "Enter Final Grade (0 - " << cou[couIdx].gr.finalMax << "): ";
				cin >> g.final;
				if (g.final < 0 || g.final > cou[couIdx].gr.finalMax)
					cout << "\nInvalid! Must be between 0 and " << cou[couIdx].gr.finalMax << "\n\n";
			} while (g.final < 0 || g.final > cou[couIdx].gr.finalMax);

			do
			{
				cout << "Enter Practical Grade (0 - " << cou[couIdx].gr.practicalMax << "): ";
				cin >> g.practical;
				if (g.practical < 0 || g.practical > cou[couIdx].gr.practicalMax)
					cout << "\nInvalid! Must be between 0 and " << cou[couIdx].gr.practicalMax << "\n\n";
			} while (g.practical < 0 || g.practical > cou[couIdx].gr.practicalMax);

			do
			{
				cout << "Enter Year Work Grade (0 - " << cou[couIdx].gr.yearWorkMax << "): ";
				cin >> g.yearWork;
				if (g.yearWork < 0 || g.yearWork > cou[couIdx].gr.yearWorkMax)
					cout << "\nInvalid! Must be between 0 and " << cou[couIdx].gr.yearWorkMax << "\n\n";
			} while (g.yearWork < 0 || g.yearWork > cou[couIdx].gr.yearWorkMax);

			do
			{
				cout << "Enter Quiz Grade (0 - " << cou[couIdx].gr.quizMax << "): ";
				cin >> g.quiz;
				if (g.quiz < 0 || g.quiz > cou[couIdx].gr.quizMax)
					cout << "\nInvalid! Must be between 0 and " << cou[couIdx].gr.quizMax << "\n\n";
			} while (g.quiz < 0 || g.quiz > cou[couIdx].gr.quizMax);

			calculateGrade(couIdx, g, cou);
			calculateGPA(stuIdx, numOfCou, cou, stu, false);
			g.gradeAssigned = true;

			cout << "\n====== Grade Results for: " << stu[stuIdx].inf.name << " ======\n";
			cout << "Final:      " << g.final << " / " << cou[couIdx].gr.finalMax << endl;
			cout << "Practical:  " << g.practical << " / " << cou[couIdx].gr.practicalMax << endl;
			cout << "Year Work:  " << g.yearWork << " / " << cou[couIdx].gr.yearWorkMax << endl;
			cout << "Quiz:       " << g.quiz << " / " << cou[couIdx].gr.quizMax << endl;
			cout << "------------------------------\n";
			cout << "Total:      " << g.total << " / " << cou[couIdx].gr.total << endl;
			cout << "Percentage: " << g.percentage << "%\n";
			cout << "Grade:      " << g.letter << "\n\n";
		}

		do
		{
			cout << "Do you want to enter grades for another course? (Y/N): ";
			cin >> again;
			if (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
				cout << "\nInvalid choice! Please enter (Y/N)\n";
		} while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

		if (again == 'n' || again == 'N')
			cout << "\nReturning to Staff Dashboard... \n" << endl;

	} while (again == 'y' || again == 'Y');
}

void requestGrades(int stuIndex, int numOfCou, course cou[], student stu[])
{
	int stuCouCount = 0;
	for (int i = 0; i < 10; i++)
		if (stu[stuIndex].studentCourses[i] != "")
			stuCouCount++;

	if (stuCouCount == 0) {
		cout << "\nYou have no courses registered yet!\n\n";
		return;
	}

	char again;
	do {
		int cntr = 1;
		cout << "\n====== Your Courses (" << stuCouCount << ") ======\n";
		for (int i = 0; i < 10; i++)
			if (stu[stuIndex].studentCourses[i] != "")
				cout << "[" << cntr++ << "] - " << stu[stuIndex].studentCourses[i] << endl;

		int choice;
		do {
			cout << "\nChoose a course (1-" << stuCouCount << "): ";
			cin >> choice;
			if (choice < 1 || choice > stuCouCount)
				cout << "\nInvalid choice! Please try again\n";
		} while (choice < 1 || choice > stuCouCount);

		string tempCourse = "";
		int cntr2 = 0;
		for (int i = 0; i < 10; i++) {
			if (stu[stuIndex].studentCourses[i] != "") {
				cntr2++;
				if (cntr2 == choice) {
					tempCourse = stu[stuIndex].studentCourses[i];
					break;
				}
			}
		}

		int couIdx = -1;
		for (int i = 0; i < numOfCou; i++) {
			if (cou[i].name == tempCourse) {
				couIdx = i;
				break;
			}
		}

		if (couIdx == -1) {
			cout << "\nCourse not found!\n\n";
			return;
		}

		int gradeIdx = -1;
		for (int i = 0; i < cou[couIdx].studentCount; i++) {
			if (cou[couIdx].enr.studentIndex[i] == stuIndex) {
				gradeIdx = i;
				break;
			}
		}

		if (gradeIdx == -1 || !cou[couIdx].enr.g[gradeIdx].gradeAssigned) {
			cout << "\nNo grade assigned yet for this course!\n\n";
		}
		else {
			grade& g = cou[couIdx].enr.g[gradeIdx];
			cout << "\n====== Grade Results: " << tempCourse << " ======\n";
			cout << "Final:      " << g.final << " / " << cou[couIdx].gr.finalMax << endl;
			cout << "Practical:  " << g.practical << " / " << cou[couIdx].gr.practicalMax << endl;
			cout << "Year Work:  " << g.yearWork << " / " << cou[couIdx].gr.yearWorkMax << endl;
			cout << "Quiz:       " << g.quiz << " / " << cou[couIdx].gr.quizMax << endl;
			cout << "-----------------------------\n";
			cout << "Total:      " << g.total << " / " << cou[couIdx].gr.total << endl;
			cout << "Percentage: " << g.percentage << "%\n";
			cout << "Grade:      " << g.letter << "\n\n";
		}

		do {
			cout << "Do you want to request another course grade? (Y/N): ";
			cin >> again;
			if (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
				cout << "\nInvalid choice! Please enter (Y/N)\n";
		} while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

		if (again == 'n' || again == 'N')
		{
			cout << "\nReturning to Grades Menu...\n\n";
			return;
		}

	} while (again == 'y' || again == 'Y');
}



void stfViewAppointments(int stfIndex, int numOfApp, appointment app[])
{
	char again;
	do
	{
		if (numOfApp == 0)
		{
			cout << "No appointments available!\n\n";
			return;
		}

		int count = 0;
		for (int i = 0; i < numOfApp; i++) {
			if (app[i].stfIndex == stfIndex)
				count++;
		}

		if (count == 0)
		{
			cout << "\nNo appointments found!\n";
			return;
		}

		int cntr = 1;

		cout << "====== Your Appointments (" << count << ") ======\n";

		for (int i = 0; i < numOfApp; i++)
		{
			if (app[i].stfIndex == stfIndex)
			{
				cout << "\n[" << cntr++ << "] ";
				cout << "Student ID: " << app[i].studentID;

				cout << " | Student Name: " << app[i].studentName;

				cout << " | Date: "
					<< app[i].sch.day << "/"
					<< app[i].sch.month;

				cout << " | Time: ";
				if (app[i].sch.hour < 10)   cout << "0";
				cout << app[i].sch.hour << ":";
				if (app[i].sch.minute < 10) cout << "0";
				cout << app[i].sch.minute;

				cout << " | Status: ";
				if (app[i].status == "Pending") cout << "Pending";
				else if (app[i].status == "Approved") cout << "Approved";
				else cout << "Rejected";

				cout << endl;
			}
		}

		int choice;
		cout << "\nEnter appointment to manage (Type '0' to exit): ";
		cin >> choice;

		if (choice == 0)
		{
			cout << "\nReturning to Staff Dashboard..." << "\n\n";
			return;
		}
		if (choice < 1 || choice > count)
		{
			cout << "\nInvalid choice! Please try again\n\n";
			return;
		}

		int realIndex = -1;
		int cntr2 = 0;
		for (int i = 0; i < numOfApp; i++)
		{
			if (app[i].stfIndex == stfIndex)
			{
				cntr2++;
				if (cntr2 == choice)
				{
					realIndex = i;
					break;
				}
			}
		}

		int action;
		cout << "\n[1] - Approve\n[2] - Reject\nEnter your choice: ";
		cin >> action;

		if (action == 1)
		{
			app[realIndex].status = "Approved";
			cout << "\nAppointment Approved!\n\n";
		}
		else if (action == 2)
		{
			app[realIndex].status = "Rejected";
			cout << "\nAppointment Rejected!\n\n";
		}
		else
		{
			cout << "\nInvalid option! Please enter (1/2)\n";
		}

		do {
			cout << "Do you want to manage another appointment? (Y/N): ";
			cin >> again;
			cout << endl;
			if (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
				cout << "Invalid choice! Please enter (Y/N)\n";
		} while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

		if (again == 'n' || again == 'N')
			cout << "Returning to Staff Dashboard...\n\n";

	} while (again == 'y' || again == 'Y');
}

void stuViewAppointments(int stuIndex, int numOfApp, appointment app[], student stu[], staff stf[])
{
	if (numOfApp == 0)
	{
		cout << "No appointments available!\n\n";
		return;
	}

	int count = 0;
	for (int i = 0; i < numOfApp; i++) {
		if (app[i].studentID == stu[stuIndex].inf.id)
			count++;
	}

	if (count == 0)
	{
		cout << "\nYou have no appointments!\n\n";
		return;
	}

	int cntr = 1;

	cout << "====== Your Appointments (" << count << ") ======\n";

	for (int i = 0; i < numOfApp; i++)
	{
		if (app[i].studentID == stu[stuIndex].inf.id)
		{
			cout << "\n[" << cntr++ << "] ";
			cout << "Staff Member: " << stf[app[i].stfIndex].inf.name;

			cout << " | Date: "
				<< app[i].sch.day << "/"
				<< app[i].sch.month;

			cout << " | Time: ";
			if (app[i].sch.hour < 10)   cout << "0";
			cout << app[i].sch.hour << ":";
			if (app[i].sch.minute < 10) cout << "0";
			cout << app[i].sch.minute;

			cout << " | Status: ";
			if (app[i].status == "Pending") cout << "Pending";
			else if (app[i].status == "Approved") cout << "Approved";
			else cout << "Rejected";

			cout << endl;
			cout << endl;
		}
	}
}

void couSchMenu(int numOfCou, course cou[])
{
	int choice;
	do {
		do {
			cout << "====== Course Schedule Menu ======" << endl;
			cout << "[1] - Set Course Schedule" << endl;
			cout << "[2] - View Course Schedules" << endl;
			cout << "[3] - Remove Course Schedule" << endl;
			cout << "[0] - Back" << endl;
			cout << "----------------------------------" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			cout << endl;
			if (choice != 1 && choice != 2 && choice != 3 && choice != 0)
				cout << "Invalid choice! Please try again\n\n";
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 0);

		switch (choice) {
		case 1: setCourseSchedule(numOfCou, cou); break;
		case 2: viewCourseSchedules(numOfCou, cou); break;
		case 3: removeCourseSchedule(numOfCou, cou); break;
		case 0: cout << "Returning to Administration Dashboard...\n\n"; return;
		}
	} while (true);
}

string getDayName(int weekDay)
{
	switch (weekDay) {
	case 1: return "Saturday";
	case 2: return "Sunday";
	case 3: return "Monday";
	case 4: return "Tuesday";
	case 5: return "Wednesday";
	case 6: return "Thursday";
	default: return "Unknown";
	}
}

void setCourseSchedule(int numOfCou, course cou[])
{
	if (numOfCou == 0)
	{
		cout << "No courses available!\n\n";
		return;
	}

	char again;
	do
	{
		int year;
		do
		{
			cout << "Enter Academic Year (1-4): ";
			cin >> year;
			if (year < 1 || year > 4)
				cout << "\nInvalid Choice! Please enter a value between 1 and 4\n\n";
		} while (year < 1 || year > 4);


		int count = 0;
		int indexMap[SIZE];

		for (int i = 0; i < numOfCou; i++)
			if (cou[i].academicYear == year)
				count++;

		if (count == 0) {
			cout << "\nNo Courses found for Year " << year << "! Please try again\n\n";
			return;
		}

		int cntr = 0;
		cout << "\n====== Year " << year << " Courses ======\n";
		for (int i = 0; i < numOfCou; i++)
		{
			if (cou[i].academicYear == year)
			{
				cout << "[" << cntr + 1 << "] - " << cou[i].name;
				if (cou[i].schedule.isSet)
					cout << "  [Scheduled: " << getDayName(cou[i].schedule.weekDay)
					<< " " << cou[i].schedule.hour << ":"
					<< (cou[i].schedule.minute == 0 ? "0" : "") << cou[i].schedule.minute << "]";
				cout << endl;
				indexMap[cntr] = i;
				cntr++;
			}
		}

		int courseChoice;
		do {
			cout << "\nSelect a Course (1-" << count << "): ";
			cin >> courseChoice;
			if (courseChoice < 1 || courseChoice > count)
				cout << "\nInvalid Choice! Please enter a value between 1 and " << count << "\n";
		} while (courseChoice < 1 || courseChoice > count);

		int idx = indexMap[courseChoice - 1];

		cout << "\nSetting Schedule for: " << cou[idx].name << endl;
		cout << "-----------------------------------" << endl;

		int day;
		cout << "Select Day:\n";
		cout << "[1] - Saturday\n[2] - Sunday\n[3] - Monday\n";
		cout << "[4] - Tuesday\n[5] - Wednesday\n[6] - Thursday\n\n";
		do {
			cout << "Enter day number (1-6): ";
			cin >> day;
			if (day < 1 || day > 6)
				cout << "\nInvalid Choice! Please enter a value between 1 and 6\n\n";
		} while (day < 1 || day > 6);

		int hour;
		do {
			cout << "Enter Hour (8-18): ";
			cin >> hour;
			if (hour < 8 || hour > 18) {
				cout << "\nInvalid Choice! Lectures starting times are from 8 to 18\n\n";
			}
		} while (hour < 8 || hour > 18);

		int minute;
		do {
			cout << "Enter Minute (0, 15, 30, 45): ";
			cin >> minute;
			if (minute != 0 && minute != 15 && minute != 30 && minute != 45)
				cout << "\nInvalid Choice! Choose (0, 15, 30, or 45)\n\n";
		} while (minute != 0 && minute != 15 && minute != 30 && minute != 45);

		bool conflict = false;
		for (int i = 0; i < numOfCou; i++) {
			if (cou[i].academicYear == year &&
				cou[i].schedule.isSet &&
				cou[i].schedule.weekDay == day &&
				cou[i].schedule.hour == hour &&
				cou[i].schedule.minute == minute)
			{
				conflict = true;
				cout << "\n[!] Conflict! \"" << cou[i].name
					<< "\" (Year " << year << ") already has a lecture on "
					<< getDayName(day) << " at "
					<< hour << ":" << (minute == 0 ? "0" : "") << minute << "\n\n";
				break;
			}
		}

		if (!conflict) {
			cou[idx].schedule.weekDay = day;
			cou[idx].schedule.hour = hour;
			cou[idx].schedule.minute = minute;
			cou[idx].schedule.isSet = true;

			cout << "\nSchedule set successfully for \"" << cou[idx].name << "\"!\n";
			cout << "Day : " << getDayName(day) << endl;
			cout << "Time: " << hour << ":" << (minute == 0 ? "0" : "") << minute << "\n\n";
		}



		do {
			cout << "Do you want to set another schedule? (Y/N): ";
			cin >> again;
			cout << endl;
			if (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
				cout << "Invalid Choice! Please enter (Y/N)\n";
		} while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

		if (again == 'n' || again == 'N')
			cout << "Returning to Course Schedule Menu...\n\n";

	} while (again == 'y' || again == 'Y');
}


void viewCourseSchedules(int numOfCou, course cou[])
{
	if (numOfCou == 0) {
		cout << "No courses available!\n\n";
		return;
	}

	int year;
	do {
		cout << "Enter Academic Year (1-4): ";
		cin >> year;
		if (year < 1 || year > 4)
			cout << "\nInvalid Choice! Please enter a value between 1 and 4\n\n";
	} while (year < 1 || year > 4);

	int count = 0;

	for (int i = 0; i < numOfCou; i++)
		if (cou[i].academicYear == year)
			count++;

	if (count == 0) {
		cout << "\nNo Courses found for Year " << year << "! Please try again\n\n";
		return;
	}

	int count2 = 0;
	for (int i = 0; i < numOfCou; i++)
		if (cou[i].schedule.isSet && cou[i].academicYear == year)
			count2++;

	if (count2 == 0) {
		cout << "\nNo Schedules found for Year " << year << "! Please try again\n\n";
		return;
	}

	cout << "\n====== Year " << year << " - Course Schedules ======\n\n";
	for (int i = 0; i < numOfCou; i++) {
		if (cou[i].schedule.isSet && cou[i].academicYear == year) {
			cout << "Course : " << cou[i].name << endl;
			cout << "Year   : " << cou[i].academicYear << endl;
			cout << "Day    : " << getDayName(cou[i].schedule.weekDay) << endl;
			cout << "Time   : " << cou[i].schedule.hour << ":"
				<< (cou[i].schedule.minute == 0 ? "0" : "") << cou[i].schedule.minute << endl;
			cout << endl;
		}
	}
}

void removeCourseSchedule(int& numOfCou, course cou[])
{
	if (numOfCou == 0) {
		cout << "No courses available!\n\n";
		return;
	}

	int year;
	do {
		cout << "Enter Academic Year (1-4): ";
		cin >> year;
		if (year < 1 || year > 4)
			cout << "\nInvalid! Please enter a value between 1 and 4\n\n";
	} while (year < 1 || year > 4);


	int count = 0;

	for (int i = 0; i < numOfCou; i++)
		if (cou[i].academicYear == year)
			count++;

	if (count == 0) {
		cout << "\nNo Courses found for Year " << year << "! Please try again\n\n";
		return;
	}

	int count2 = 0;
	for (int i = 0; i < numOfCou; i++)
		if (cou[i].schedule.isSet && cou[i].academicYear == year)
			count2++;

	if (count2 == 0) {
		cout << "\nNo Schedules found for Year " << year << "! Please try again\n\n";
		return;
	}


	char again;
	do {

		int indexMap[SIZE];
		int cntr = 0;
		cout << "\n====== Year " << year << " - Scheduled Courses ======\n";
		for (int i = 0; i < numOfCou; i++) {
			if (cou[i].schedule.isSet && cou[i].academicYear == year) {
				cout << "[" << cntr + 1 << "] - " << cou[i].name
					<< " | " << getDayName(cou[i].schedule.weekDay)
					<< " " << cou[i].schedule.hour << ":"
					<< (cou[i].schedule.minute == 0 ? "0" : "") << cou[i].schedule.minute << endl;
				indexMap[cntr] = i;
				cntr++;
			}
		}

		int courseChoice;
		do {
			cout << "\nSelect a course to remove its schedule (1-" << cntr << "): ";
			cin >> courseChoice;
			if (courseChoice < 1 || courseChoice > cntr)
				cout << "\nInvalid choice! Please try again\n";
		} while (courseChoice < 1 || courseChoice > cntr);

		int idx = indexMap[courseChoice - 1];

		char confirm;
		do {
			cout << "Are you sure you want to remove the schedule for \""
				<< cou[idx].name << "\"? (Y/N): ";
			cin >> confirm;
			if (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N')
				cout << "\nInvalid Choice! Please enter (Y/N)\n";
		} while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N');

		if (confirm == 'y' || confirm == 'Y') {
			cou[idx].schedule.isSet = false;
			cou[idx].schedule.weekDay = 0;
			cou[idx].schedule.hour = 0;
			cou[idx].schedule.minute = 0;
			cout << "\nSchedule removed successfully for \"" << cou[idx].name << "\"!\n\n";


			count = 0;
			for (int i = 0; i < numOfCou; i++) {
				if (cou[i].academicYear == year && cou[i].schedule.isSet) {
					indexMap[count] = i;
					count++;
				}
			}
		}
		else {
			cout << "\nOperation Cancelled!\n\n";
		}

		if (count == 0) {
			cout << "No more scheduled courses for this year to remove\n\n";
			return;
		}

		do {
			cout << "Do you want to remove another schedule? (Y/N): ";
			cin >> again;
			if (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
				cout << "\nInvalid Choice! Please enter (Y/N)\n";
		} while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

		if (again == 'n' || again == 'N')
			cout << "\nReturning to Course Schedule Menu...\n\n";

	} while (again == 'y' || again == 'Y');
}

void stuViewCourseSchedules(int stuIndex, int numOfCou, course cou[], student stu[])
{
	if (numOfCou == 0) {
		cout << "No courses available!\n\n";
		return;
	}

	int count = 0;

	for (int i = 0; i < numOfCou; i++)
		if (cou[i].academicYear == stu[stuIndex].academicYear)
			count++;

	if (count == 0) {
		cout << "\nNo Courses found for Year " << stu[stuIndex].academicYear << "! Please try again\n\n";
		return;
	}

	int count2 = 0;
	for (int i = 0; i < numOfCou; i++)
		if (cou[i].schedule.isSet && cou[i].academicYear == stu[stuIndex].academicYear)
			count2++;

	if (count2 == 0) {
		cout << "\nNo Schedules found for Year " << stu[stuIndex].academicYear << "! Please try again\n\n";
		return;
	}

	cout << "\n====== Year " << stu[stuIndex].academicYear << " - Course Schedules ======\n\n";
	for (int i = 0; i < numOfCou; i++) {
		if (cou[i].schedule.isSet && cou[i].academicYear == stu[stuIndex].academicYear) {
			cout << "Course : " << cou[i].name << endl;
			cout << "Year   : " << cou[i].academicYear << endl;
			cout << "Day    : " << getDayName(cou[i].schedule.weekDay) << endl;
			cout << "Time   : " << cou[i].schedule.hour << ":"
				<< (cou[i].schedule.minute == 0 ? "0" : "") << cou[i].schedule.minute << endl;
			cout << endl;
		}
	}
}

void stfviewTopStudents(int stfIndex, int numOfCou, staff stf[], course cou[], student stu[])
{
	char again;
	do
	{
		int cntr = 1;
		int Reqcourse;

		if (stf[stfIndex].stfNumOfCou == 0)
		{
			cout << "No Courses available\n\n";
			return;
		}

		cout << "====== Courses You Teach (" << stf[stfIndex].stfNumOfCou << ") ======" << endl;
		for (int i = 0; i < stf[stfIndex].stfNumOfCou; i++)
		{
			cout << "[" << cntr++ << "] - " << stf[stfIndex].teachingCourses[i] << endl;
		}
		cout << endl;

		cout << "Choose the number of the course (1-" << stf[stfIndex].stfNumOfCou << "): ";
		cin >> Reqcourse;

		if (Reqcourse < 1 || Reqcourse > stf[stfIndex].stfNumOfCou)
		{
			cout << "\nInvalid choice! Please try again\n\n";
			return;
		}

		string selectedCourse = stf[stfIndex].teachingCourses[Reqcourse - 1];
		int couIdx = -1;

		for (int i = 0; i < numOfCou; i++)
		{
			if (cou[i].name == selectedCourse)
			{
				couIdx = i;
				break;
			}
		}

		if (couIdx == -1)
		{
			cout << "Course not found!\n\n";
			return;
		}

		if (cou[couIdx].studentCount == 0)
		{
			cout << "\nNo students in this course!\n\n";
		}
		else
		{
			int n = cou[couIdx].studentCount;
			int validCount = 0;

			for (int i = 0; i < n; i++)
			{
				if (cou[couIdx].enr.g[i].percentage >= 60)
					validCount++;
			}

			if (validCount == 0)
			{
				cout << "\nNo students with grades in this course yet!\n\n";
				return;
			}


			int indices[SIZE];
			int index = 0;
			for (int i = 0; i < n; i++)
			{
				if (cou[couIdx].enr.g[i].percentage >= 60)
					indices[index++] = i;
			}

			for (int i = 0; i < validCount - 1; i++)
			{
				for (int j = 0; j < validCount - i - 1; j++)
				{
					if (cou[couIdx].enr.g[indices[j]].percentage < cou[couIdx].enr.g[indices[j + 1]].percentage)
					{
						int temp = indices[j];
						indices[j] = indices[j + 1];
						indices[j + 1] = temp;
					}
				}
			}

			int topCount = min(5, validCount);

			cout << "\n====== Top (" << topCount << ") Students In " << cou[couIdx].name << " ======\n";


			for (int i = 0; i < topCount; i++)
			{
				int idx = indices[i];
				int stuIdx = cou[couIdx].enr.studentIndex[idx];
				grade g = cou[couIdx].enr.g[idx];

				cout << "\n[" << i + 1 << "] ";
				cout << "ID: " << stu[stuIdx].inf.id << " | ";
				cout << "Name: " << stu[stuIdx].inf.name << endl;

				cout << "Total:      " << g.total << " / " << cou[couIdx].gr.total << endl;
				cout << "Percentage: " << g.percentage << "%\n";
				cout << "Grade:      " << g.letter << "\n";
			}
			cout << endl;
		}

		do {
			cout << "Do you want to view top students in another course? (Y/N): ";
			cin >> again;
			cout << endl;
			if (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
				cout << "Invalid choice! Please enter (Y/N)\n";
		} while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

		if (again == 'n' || again == 'N')
			cout << "Returning to Staff Dashboard...\n\n";

	} while (again == 'y' || again == 'Y');
}

void showTopHonorList(int stuIndex, int numOfStu, student stu[])
{
	if (numOfStu == 0)
	{
		cout << "\nNo students available!\n\n";
		return;
	}

	int validCount = 0;
	for (int i = 0; i < numOfStu; i++)
		if (stu[i].GPA > 0 && stu[i].academicYear == stu[stuIndex].academicYear)
			validCount++;

	if (validCount == 0)
	{
		cout << "No students with grades in year " << stu[stuIndex].academicYear << " yet!\n\n";
		return;
	}

	int indices[SIZE];
	int index = 0;
	for (int i = 0; i < numOfStu; i++)
		if (stu[i].GPA > 0 && stu[i].academicYear == stu[stuIndex].academicYear)
			indices[index++] = i;

	for (int i = 0; i < validCount - 1; i++)
	{
		for (int j = 0; j < validCount - i - 1; j++)
		{
			if (stu[indices[j]].GPA < stu[indices[j + 1]].GPA)
			{
				int temp = indices[j];
				indices[j] = indices[j + 1];
				indices[j + 1] = temp;
			}
		}
	}



	int topCount = (validCount < 5) ? validCount : 5;


	cout << "====== TOP (" << topCount << ") HONOR LIST AT YEAR (" << stu[stuIndex].academicYear << ") ======\n" << endl;
	for (int i = 0; i < topCount; i++)
	{
		int idx = indices[i];

		cout << ">> Rank " << (i + 1) << endl;
		cout << "   Name       : " << stu[idx].inf.name << endl;
		cout << "   ID         : " << stu[idx].inf.id << endl;
		cout << "   Department : " << stu[idx].department << endl;
		cout << "   GPA        : " << setprecision(3) << stu[idx].GPA << "\n" << endl;
	}
}

void getTotalMarks(int stuIndex, int numOfCou, course cou[], student stu[])
{
	float totalMarks = 0;
	float couTotalMarks = 0;

	for (int i = 0; i < 10; i++)
	{
		if (stu[stuIndex].studentCourses[i] == "") continue;

		int couIdx = -1;
		for (int j = 0; j < numOfCou; j++)
		{
			if (stu[stuIndex].studentCourses[i] == cou[j].name)
			{

				couIdx = j;
				break;
			}
		}

		if (couIdx == -1) continue;

		for (int k = 0; k < cou[couIdx].studentCount; k++)
		{
			if (cou[couIdx].enr.studentIndex[k] == stuIndex)
			{
				if (cou[couIdx].enr.g[k].letter == "") break;
				totalMarks += cou[couIdx].enr.g[k].total;
				couTotalMarks += cou[couIdx].gr.total;
				break;
			}
		}
	}

	stu[stuIndex].totalMarks = totalMarks;
	stu[stuIndex].couTotalMarks = couTotalMarks;
	if (couTotalMarks > 0)
		stu[stuIndex].percentage = (totalMarks / couTotalMarks) * 100;
	else
		stu[stuIndex].percentage = 0;
}

void getGPAletter(int stuIndex, student stu[])
{
	float gpa = stu[stuIndex].GPA;
	float pct = stu[stuIndex].percentage;

	if (gpa >= 4.0 && pct >= 97) stu[stuIndex].letter = "A+";
	else if (gpa >= 4.0) stu[stuIndex].letter = "A";
	else if (gpa >= 3.7) stu[stuIndex].letter = "A-";
	else if (gpa >= 3.3) stu[stuIndex].letter = "B+";
	else if (gpa >= 3.0) stu[stuIndex].letter = "B";
	else if (gpa >= 2.7) stu[stuIndex].letter = "B-";
	else if (gpa >= 2.3) stu[stuIndex].letter = "C+";
	else if (gpa >= 2.0) stu[stuIndex].letter = "C";
	else if (gpa >= 1.7) stu[stuIndex].letter = "C-";
	else if (gpa >= 1.3) stu[stuIndex].letter = "D+";
	else if (gpa >= 1.0) stu[stuIndex].letter = "D";
	else stu[stuIndex].letter = "F";
}

float getGradePoint(string letter)
{
	if (letter == "A+" || letter == "A") return 4.0;
	else if (letter == "A-") return 3.7;
	else if (letter == "B+") return 3.3;
	else if (letter == "B") return 3.0;
	else if (letter == "B-") return 2.7;
	else if (letter == "C+") return 2.3;
	else if (letter == "C") return 2.0;
	else if (letter == "C-") return 1.7;
	else if (letter == "D+") return 1.3;
	else if (letter == "D") return 1.0;
	else if (letter == "F") return 0.0;
	else return 0.0;

}

void calculateGPA(int stuIndex, int numOfCou, course cou[], student stu[], bool showOutput = true)
{

	float totalPoints = 0;
	float totalCredits = 0;
	int StuNumOfCou = 0;

	for (int i = 0; i < 10; i++)
		if (stu[stuIndex].studentCourses[i] != "") StuNumOfCou++;

	if (StuNumOfCou == 0)
	{
		cout << "\nNo Courses registered for GPA calculation\n\n";
		return;
	}

	for (int i = 0; i < numOfCou; i++)
	{
		for (int j = 0; j < cou[i].studentCount; j++)
		{
			if (cou[i].enr.studentIndex[j] == stuIndex)
			{
				string letter = cou[i].enr.g[j].letter;
				if (letter == "") break;
				float gradePoint = getGradePoint(letter);
				int credits = cou[i].creditHours;

				totalPoints += gradePoint * credits;
				totalCredits += credits;
			}
		}
	}

	if (totalCredits == 0)
	{
		cout << "\nNo grades assigned for GPA calculation\n\n";
		return;
	}

	float gpa = totalPoints / totalCredits;
	stu[stuIndex].GPA = gpa;
	getTotalMarks(stuIndex, numOfCou, cou, stu);
	getGPAletter(stuIndex, stu);

	if (showOutput)
	{
		cout << "\n====== GPA Result ======\n";
		cout << "Student    : " << stu[stuIndex].inf.name << endl;
		cout << "Total Marks: " << stu[stuIndex].totalMarks << " / " << stu[stuIndex].couTotalMarks << endl;
		cout << "Percentage : " << setprecision(3) << stu[stuIndex].percentage << " %" << endl;
		cout << "GPA        : " << setprecision(3) << gpa << endl;
		cout << "Grade      : " << stu[stuIndex].letter << endl;
		cout << endl;
	}
}

void gradesMenu(int stuIndex, int numOfCou, course cou[], student stu[])
{
	int choice;

	do
	{
		do
		{
			cout << "====== Grades Menu ======" << endl;
			cout << "[1] - Request Grades" << endl;
			cout << "[2] - My GPA" << endl;
			cout << "[0] - Back" << endl;
			cout << "---------------------" << endl;
			cout << "Enter your choice: ";
			cin >> choice;

			if (choice != 1 && choice != 2 && choice != 0)
				cout << "\nInvalid choice! Please try again\n\n";

		} while (choice != 1 && choice != 2 && choice != 0);

		switch (choice)
		{
		case 1:
			requestGrades(stuIndex, numOfCou, cou, stu);
			break;
		case 2:
			calculateGPA(stuIndex, numOfCou, cou, stu, true);
			break;
		case 0:
			cout << "\nReturning to Student Dashboard... \n" << endl;
			return;
		}

	} while (true);
}
