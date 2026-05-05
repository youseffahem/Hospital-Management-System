#  Hospital Management System

A C++ console application that manages hospital branches, doctors, and patients using three singly linked lists.

---

##  Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Data Structures](#data-structures)
- [Project Structure](#project-structure)
- [How to Compile & Run](#how-to-compile--run)
- [Menu Options](#menu-options)
- [Usage Examples](#usage-examples)
- [Bonus Features](#bonus-features)
- [Limitations & Notes](#limitations--notes)

---

## Overview

The Hospital Management System simplifies how hospitals and healthcare organizations manage:
- **Branches** — Multiple hospital locations
- **Doctors** — Medical staff across branches
- **Patients** — Patient records and appointments

All data is stored in-memory using **singly linked lists** — one list per entity.

---

## Features

### 🏢 Branch Management
| Function | Description |
|----------|-------------|
| Add Branch | Insert a new hospital branch (ID, Name, Location) |
| Display Branches | List all existing branches |
| Search by ID | Find a branch using its unique ID |

###  Doctor Management
| Function | Description |
|----------|-------------|
| Add Doctor | Insert a new doctor (ID, Name, Specialization, Branch) |
| Remove Doctor | Delete a doctor record by ID |
| Display Appointments | Show all doctors and their appointment counts |

###  Patient Management
| Function | Description |
|----------|-------------|
| Add Patient | Insert a new patient (ID, Name, Address, Appointments) |
| Remove Patient | Delete a patient record by Name |
| Display Patients | Show all patients and their appointment info |
| Search by Name | *(Extendable — see Limitations)* |

---

## Data Structures

### `Branch` (struct)
```
IDB        → int     : Unique branch ID
NameB      → string  : Branch name
locationB  → string  : Branch location
next       → Branch* : Pointer to next node
```

### `Doctor` (struct)
```
IDD            → string  : Unique doctor ID
NameD          → string  : Doctor's name
specializationD→ string  : Medical specialization
BranchHosD     → string  : Assigned hospital branch
appointmentD   → int     : Number of appointments
next           → Doctor* : Pointer to next node
```

### `Patients` (struct)
```
IDP          → string    : Unique patient ID
NameP        → string    : Patient's name
AddressP     → string    : Patient's address
AppointmentP → int       : Appointment number/count
next         → Patients* : Pointer to next node
```

---

## Project Structure

```
HospitalManagementSystem/
│
├── main.cpp               # Full source code (single file)
└── README.md              # This file
```

---

## How to Compile & Run

### Requirements
- C++ compiler (g++, MSVC, Clang, etc.)
- C++11 or later

### Using g++ (Linux / macOS / MinGW on Windows)

```bash
# Compile
g++ -std=c++11 -o hospital main.cpp

# Run
./hospital
```

### Using MSVC (Windows)

```cmd
cl /EHsc main.cpp /Fe:hospital.exe
hospital.exe
```

---

## Menu Options

When you run the program, you'll see this menu:

```
1. Add Branch
2. Add Doctor
3. Add Patient
4. Display Branches
5. Display Doctors
6. Display Patients
7. Search Branch
8. Remove Doctor
9. Remove Patient
0. Exit
```

---

## Usage Examples

### Adding a Branch
```
Choose an option: 1
Enter Branch ID, Name, and Location:
101 CentralHospital Cairo
```

### Adding a Doctor
```
Choose an option: 2
Enter Doctor ID, Name, Specialization, and Branch:
D001 Dr.Ahmed Cardiology CentralHospital
```

### Adding a Patient
```
Choose an option: 3
Enter Patient ID, Name, Address, and Appointments:
P001 Sara Alexandria 3
```

### Searching for a Branch
```
Choose an option: 7
Enter Branch ID to search: 101
Branch Found: CentralHospital at Cairo
```

### Removing a Doctor
```
Choose an option: 8
Enter Doctor ID to remove: D001
Doctor removed: Dr.Ahmed
```

>  **Note:** Input fields do **not** support spaces (e.g., use `Dr.Ahmed` instead of `Dr. Ahmed`). This is a known limitation of using `cin >>` for string input.

---

## Bonus Features

The following features are mentioned as bonus tasks and can be added as extensions:

- **Update Patient Information** — Traverse to the patient node by ID/Name and modify fields.
- **Remove Branch** — Traverse `LinkedListBranch` and unlink the matching node by ID.

---

## Limitations & Notes

| Issue | Details |
|-------|---------|
| No space support in input | `cin >>` stops at whitespace; multi-word names/addresses will break input |
| No persistent storage | All data is lost when the program exits (no file/database saving) |
| No duplicate checking | Inserting the same ID twice is allowed |
| Patient search by name | Defined in requirements but not wired to the menu — add case 10 to extend |
| Appointment booking | Currently stored as an integer count; no date/time logic implemented |

---

## Author Notes

This project demonstrates core **Data Structures** concepts in C++:
- Singly linked list insertion (prepend / head insertion)
- Linked list traversal
- Node deletion with pointer relinking
- Modular class-based design separating Branch, Doctor, and Patient logic
