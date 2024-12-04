/*The Hospital Management System can help any hospital or healthcare facility
by boosting productivity, lowering paperwork, and enhancing patient care. The
Hospital Management System in C++ simplifies the process for hospitals and
other healthcare organizations to manage medical records and appointments.
The Hospital has many branches. Each branch has basic information (ID, Name,
and Location). The Hospital has many doctors. Each Doctor has basic
information (ID, Name, Specialization, and hospital branch). The Hospital
Also deals with many patients and each patient has basic information (ID,
Name, Address, and Appointment). Create a C++ program using three singly
Linked Lists to perform the following functions:
System Required Functions:-
1- For Hospital:-
a. Add new branch.
b. Display Branches.
c. Search for Branch by ID.
2- For Doctor: -
a. Add new doctor.
b. Remove a doctor.
c. Display all appointments.
3- For Patients: -
a. Add new patient.
b. Remove a patient.
c. Book Appointment.
d. Search for patient by Name.
Bonus:-
➢ Update patient Information.
➢ Remove Branch.*/

#include <iostream>
#include <string>
using namespace std;

struct Branch {
	int IDB;
	string NameB, locationB;
	Branch* next;

	Branch() {
		IDB = 0;
		NameB = "";
		locationB = "";
		next = NULL;
	}
};

class LinkedListBranch {
public:
	Branch* branchHead;

	LinkedListBranch() {
		branchHead = NULL;
	}

	// Insert a new branch
	void InsertBranch(int IDB, string NameB, string locationB) {
		Branch* newBranch = new Branch;
		newBranch->IDB = IDB;
		newBranch->NameB = NameB;
		newBranch->locationB = locationB;

		newBranch->next = branchHead;
		branchHead = newBranch;
	}

	// Traverse and display branches
	void TraverseBranch() {
		if (branchHead == NULL) {
			cout << "No branches available.\n";
			return;
		}

		Branch* temp = branchHead;
		cout << "Branches:\n";
		while (temp != NULL) {
			cout << "ID: " << temp->IDB << "\n"
				<< "Name: " << temp->NameB << "\n"
				<< "Location: " << temp->locationB << "\n\n";
			temp = temp->next;
		}
	}

	// Search for a branch by ID
	string SearchBranch(int IDB) {
		if (branchHead == NULL) {
			return "No branches available.";
		}

		Branch* temp = branchHead;
		while (temp != NULL) {
			if (temp->IDB == IDB) {
				return "Branch Found: " + temp->NameB + " at " + temp->locationB;
			}
			temp = temp->next;
		}
		return "Branch not found.";
	}
};

struct Doctor {
	string IDD, NameD, specializationD, BranchHosD;
	int appointmentD;
	Doctor* next;

	Doctor() {
		IDD = "";
		NameD = "";
		specializationD = "";
		BranchHosD = "";
		appointmentD = 0;
		next = NULL;
	}
};

class LinkedListDoctor {
public:
	Doctor* doctorHead;

	LinkedListDoctor() {
		doctorHead = NULL;
	}

	// Insert a new doctor
	void InsertDoctor(string IDD, string NameD, string specializationD, string BranchHosD) {
		Doctor* newDoctor = new Doctor;
		newDoctor->IDD = IDD;
		newDoctor->NameD = NameD;
		newDoctor->specializationD = specializationD;
		newDoctor->BranchHosD = BranchHosD;

		newDoctor->next = doctorHead;
		doctorHead = newDoctor;
	}

	// Traverse and display doctors with their appointments
	void TraverseDoctors() {
		if (doctorHead == NULL) {
			cout << "No doctors available.\n";
			return;
		}

		Doctor* temp = doctorHead;
		cout << "Doctors:\n";
		while (temp != NULL) {
			cout << "ID: " << temp->IDD << "\n"
				<< "Name: " << temp->NameD << "\n"
				<< "Specialization: " << temp->specializationD << "\n"
				<< "Branch: " << temp->BranchHosD << "\n"
				<< "Appointments: " << temp->appointmentD << "\n\n";
			temp = temp->next;
		}
	}

	// Remove a doctor by ID
	string RemoveDoctor(string IDD) {
		if (doctorHead == NULL) {
			return "No doctors available.";
		}

		Doctor* temp = doctorHead;
		Doctor* prev = NULL;

		while (temp != NULL) {
			if (temp->IDD == IDD) {
				string removedName = temp->NameD;
				if (prev == NULL) {
					doctorHead = temp->next;
				}
				else {
					prev->next = temp->next;
				}
				delete temp;
				return "Doctor removed: " + removedName;
			}
			prev = temp;
			temp = temp->next;
		}
		return "Doctor not found.";
	}
};

struct Patients {
	string IDP, NameP, AddressP;
	int AppointmentP;
	Patients* next;

	Patients() {
		IDP = "";
		NameP = "";
		AddressP = "";
		AppointmentP = 0;
		next = NULL;
	}
};

class LinkedListPatient {
public:
	Patients* patientsHead;

	LinkedListPatient() {
		patientsHead = NULL;
	}

	// Insert a new patient
	void InsertPatient(string IDP, string NameP, string AddressP, int AppointmentP) {
		Patients* newPatient = new Patients;
		newPatient->IDP = IDP;
		newPatient->NameP = NameP;
		newPatient->AddressP = AddressP;
		newPatient->AppointmentP = AppointmentP;

		newPatient->next = patientsHead;
		patientsHead = newPatient;
	}

	// Traverse and display patients with appointments
	void TraversePatients() {
		if (patientsHead == NULL) {
			cout << "No patients available.\n";
			return;
		}

		Patients* temp = patientsHead;
		cout << "Patients:\n";
		while (temp != NULL) {
			cout << "ID: " << temp->IDP << "\n"
				<< "Name: " << temp->NameP << "\n"
				<< "Address: " << temp->AddressP << "\n"
				<< "Appointments: " << temp->AppointmentP << "\n\n";
			temp = temp->next;
		}
	}

	// Remove a patient by Name
	string RemovePatient(string NameP) {
		if (patientsHead == NULL) {
			return "No patients available.";
		}

		Patients* temp = patientsHead;
		Patients* prev = NULL;

		while (temp != NULL) {
			if (temp->NameP == NameP) {
				string removedName = temp->NameP;
				if (prev == NULL) {
					patientsHead = temp->next;
				}
				else {
					prev->next = temp->next;
				}
				delete temp;
				return "Patient removed: " + removedName;
			}
			prev = temp;
			temp = temp->next;
		}
		return "Patient not found.";
	}
};

void DisplayMenu() {
	cout << "1. Add Branch\n"
		<< "2. Add Doctor\n"
		<< "3. Add Patient\n"
		<< "4. Display Branches\n"
		<< "5. Display Doctors\n"
		<< "6. Display Patients\n"
		<< "7. Search Branch\n"
		<< "8. Remove Doctor\n"
		<< "9. Remove Patient\n"
		<< "0. Exit\n"
		<< "Choose an option: ";
}

// Main Function
int main() {
	LinkedListBranch branchList;
	LinkedListDoctor doctorList;
	LinkedListPatient patientList;

	int choice;
	do {
		DisplayMenu();
		cin >> choice;
		
		switch (choice) {
		case 1: {
			int id;
			string name, location;
			cout << "Enter Branch ID, Name, and Location:\n";
			cin >> id >> name >> location;
			branchList.InsertBranch(id, name, location);
			break;
		}
		case 2: {
			string id, name, specialization, branch;
			cout << "Enter Doctor ID, Name, Specialization, and Branch:\n";
			cin >> id >> name >> specialization >> branch;
			doctorList.InsertDoctor(id, name, specialization, branch);
			break;
		}
		case 3: {
			string id, name, address;
			int appointments;
			cout << "Enter Patient ID, Name, Address, and Appointments:\n";
			cin >> id >> name >> address >> appointments;
			patientList.InsertPatient(id, name, address, appointments);
			break;
		}
		case 4:
			branchList.TraverseBranch();
			break;
		case 5:
			doctorList.TraverseDoctors();
			break;
		case 6:
			patientList.TraversePatients();
			break;
		case 7: {
			int id;
			cout << "Enter Branch ID to search: ";
			cin >> id;
			cout << branchList.SearchBranch(id) << endl;
			break;
		}
		case 8: {
			string id;
			cout << "Enter Doctor ID to remove: ";
			cin >> id;
			cout << doctorList.RemoveDoctor(id) << endl;
			break;
		}
		case 9: {
			string name;
			cout << "Enter Patient Name to remove: ";
			cin >> name;
			cout << patientList.RemovePatient(name) << endl;
			break;
		}
		case 0:
			cout << "Exiting program.\n";
			break;
		default:
			cout << "Invalid choice.\n";
		}
	} while (choice != 0);

	return 0;
}
