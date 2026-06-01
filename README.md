# 🎓 College Management System

A console-based college management system built in C++ that handles students, academic staff, and administration — all from a single unified interface.

---

## 📋 Overview

This system simulates the core operations of a college environment. Users can sign up and sign in as one of three roles, each with its own dashboard and set of features.

| Role | Description |
|------|-------------|
| 🧑‍🎓 Student | Register for courses, view grades & GPA, schedule appointments, view exam/course schedules |
| 👨‍🏫 Academic Staff | Assign grades, manage teaching courses, handle appointment requests |
| 🏛️ Administration | Manage courses, course schedules, and exam schedules |

---

## ✨ Features

### 🧑‍🎓 Student
- View & edit personal profile
- Register / drop courses by academic year
- Request & view appointments with staff members
- View course schedules and exam timetables
- Check grades per course and calculate GPA
- View top 5 honor students in their year

### 👨‍🏫 Academic Staff
- View & edit personal profile
- Select / remove teaching courses
- Assign grades (final, practical, year work, quiz)
- Approve or reject student appointment requests
- View top 5 students per course

### 🏛️ Administration
- View & edit personal profile
- Add / remove / view courses
- Set, view, and remove course schedules (with conflict detection)
- Set, view, and remove exam schedules

### 🔐 Authentication
- Role-based sign up & sign in
- Password masking with `_getch()`
- 3 login attempts before lockout
- Password reset via mobile number + ID verification
- Unique mobile number validation across all users

---

## 🛠️ Tech Stack

|---|---|
| **Language** | C++ |
| **Data Structures** | Structs & fixed-size arrays |
| **Algorithms** | Bubble sort (for top student rankings) |

---

## 📐 Data Model

```
information        → shared by all users (ID, name, mobile, password, address)
student            → extends information + department, year, courses, GPA
staff              → extends information + department, position, teaching courses
administration     → extends information + position
course             → name, credit hours, grade scheme, enrolled students
enrollment         → per-student grades (final, practical, year work, quiz)
appointment        → student ↔ staff scheduling with status (Pending/Approved/Rejected)
exam               → course + date/time schedule
courseSchedule     → weekday + time per course
```

---

## 🚀 Getting Started

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-username/college-management-system.git
   ```

2. **Open in Visual Studio** (or any Windows C++ compiler)

3. **Build & Run**
   ```bash
   g++ -o cms main.cpp
   ./cms
   ```

---

## 👥 Sample Credentials

| Role | ID | Password |
|------|----|----------|
| Student | 100011 | 123 |
| Staff | 200000 | 256 |
| Admin | 300000 | 256 |

---

## 📁 Project Structure

```
main.cpp          → entire project (single-file architecture)
```

---

## 🤝 Contributors

| Name |
|------|
| Adam Ahmed Abdelbaset |
| Yousef Allam Abdullah |
| Marwan Mohammed Abed |
| Yousef Ehab Makram |
| Salah Eldin Ibrahim Salah Eldin |
| Malek Mohammed ElShazly |
| Philopater Farag Nabih |
