#include "header.h"

int main() {
    string searchTerm;
    vector<Patient> patientVector = createPatients();
    vector<Doctor> doctorVector = createDoctors();
    appointments(&doctorVector, &patientVector);

    bool running = true;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "         Welcome to the Hospital Management System\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "                               +                               \n";
    cout << "                               |                               \n";
    cout << "                               |                               \n";
    cout << "                +--------------+-------------+                 \n";
    cout << "                |       Hualien Marcus       |                 \n" ;
    cout << "                |       Hospital System      |                 \n" ;
    cout << "                +--------------+-------------+                 \n";
    cout << "                               |                               \n";
    cout << "                               |                               \n";
    cout << "                               +                               \n";
    while (running) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << endl;
        cout << "                  Welcome to the Main Menu...\n\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Press Keys (1-10) to access options!\n\n";
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "1.  Create New Data\n";
        cout << "2.  Add New Appointment\n";
        cout << "3.  Cancel Appointment\n";
        cout << "4.  Edit Patient Data\n";
        cout << "5.  Update Doctor Data\n";
        cout << "6.  Big Data Search\n";
        cout << "7.  View Data By ID\n";
        cout << "8.  Show List\n";
        cout << "9.  Delete Data\n";
        cout << "10. Quit\n";
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Option: ";
        
        int usrop;
        cin >> usrop;
        
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        while (cin.fail()) {
                cin.clear(); // Clear the error state of cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input buffer
                cout << "Invalid input. Please enter an integer: ";
                cin >> usrop;
                }
        cin.ignore(); // Clear newline character from buffer after reading usrop

        switch (usrop) {
            case 1: {
                // Create new data
                string fName, lName, mName, address;
                int age, day, month, year, ftH, inH, wght;
                long phone;
                bool sex, life = true;
                char sx;

                cout << "Creating New Data...\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "Select Option (1,2):\n\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"1. Doctor\n2. Patient\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"Option: ";
                int newOption;
                cin >> newOption;
                while (cin.fail()) {
                cin.clear(); // Clear the error state of cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input buffer
                cout << "Invalid input. Please enter an integer: ";
                cin >> newOption;
                }
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cin.ignore(); // Clear newline character from buffer after reading newOption

                if (newOption == 1) {
                     string office, specialization;
                    int experienceYears,doctorID;
                    cout << "\nEnter New Doctor Data...\n\n";
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    cout << "First Name  : ";
                    getline(cin, fName);
                    cout << "Middle Name : ";
                    getline(cin, mName);
                    cout << "Family Name : ";
                    getline(cin, lName);
                    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    cout << "Age (Years): ";
                    cin >> age;
                    cout << "Sex (M | F): ";
                    cin >> sx;
                    sex = (sx == 'M' || sx == 'm');
                    cout << "Height (FT): ";
                    cin >> ftH;
                    cout << "Height (IN): ";
                    cin >> inH;
                    cout << "Weight (LB): ";
                    cin >> wght;
                     cout<< "Birth Day (dd)   : ";
                    cin >> day;
                    cout << "Birth Month (mm) : ";
                    cin >> month;
                    cout << "Birth Year (yyyy): ";
                    cin >> year;
                    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    cout << "Address     : ";
                    cin.ignore();
                    getline(cin, address);
                    cout << "Office Name : ";
                    getline(cin, office);
                    cout << "Phone Number: +";
                    cin >> phone;
                    cout << "Specialization     : ";
                    cin.ignore();
                    getline(cin, specialization);
                    cout << "Years Of Experience: ";
                    cin>>experienceYears;
                    cout<<endl;
                    Doctor doctor(fName, lName, mName, address, phone, age, day, month, year,
                                    ftH, inH, wght, sex, life,specialization,experienceYears,office);
                    doctorVector.push_back(doctor);
                    // Logic to create new doctor
                } else if (newOption == 2) {
                    string room, eName;
                    long ePhone;
                    char ch;
                    bool hospitalized, disabled, medication, allergies;

                    cout << "\nEnter New Patient Data...\n\n";
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    cout << "First Name  : ";
                    getline(cin, fName);
                    cout << "Middle Name : ";
                    getline(cin, mName);
                    cout << "Family Name : ";
                    getline(cin, lName);
                    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    cout << "Age (Years): ";
                    cin >> age;
                    cout << "Sex (M | F): ";
                    cin >> sx;
                    sex = (sx == 'M' || sx == 'm');
                    cout << "Height (FT): ";
                    cin >> ftH;
                    cout << "Height (IN): ";
                    cin >> inH;
                    cout << "Weight (LB): ";
                    cin >> wght;
                     cout<< "Birth Day (dd)   : ";
                    cin >> day;
                    cout << "Birth Month (mm) : ";
                    cin >> month;
                    cout << "Birth Year (yyyy): ";
                    cin >> year;
                    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    cout << "Room   : ";
                    cin.ignore();
                    getline(cin, room);
                    cout << "Address: ";
                    getline(cin, address);
                    cout << "Phone Number: +";
                    cin >> phone;
                    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";              
                    cout << "Emergency Contact    : ";
                    cin.ignore(); // Clear newline character from buffer after reading sex
                    getline(cin, eName);
                    cout << "Emergency Phonenumber: +";
                    cin >> ePhone;
                    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";              
                    cout << "Hospitalized? (Y/N) : ";
                    cin >> ch;
                    hospitalized = (ch == 'Y' || ch == 'y');
                    cout << "A Disability? (Y/N) : ";
                    cin >> ch;
                    disabled = (ch == 'Y' || ch == 'y');
                    cout << "Is Medicated? (Y/N) : ";
                    cin >> ch;
                    medication = (ch == 'Y' || ch == 'y');
                    cout << "Has Allergies? (Y/N): ";
                    cin >> ch;
                    allergies = (ch == 'Y' || ch == 'y');

                    Patient patient(fName, lName, mName, address, phone, age, day, month, year,
                                    ftH, inH, wght, sex, life, room, hospitalized, disabled,
                                    medication, allergies, eName, ePhone);

                    string allergen;
                    int category;
                    if (allergies) {
                        // Assuming there are 7 categories (0-6)
                        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";              
                        cout << "Enter allergies by category (1-7):" << endl;
                        cout << "Category 1: Other" <<endl
                             << "Category 2: Pollen"<<endl
                             << "Category 3: Food"  <<endl
                             << "Category 4: Medication" <<endl
                             << "Category 5: None" <<endl
                             << "Category 6: Mold"<<endl 
                             << "Category 7: Chemical" << endl;
                        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              


                        while (true) {
                            cout << "Enter category (0 to stop): ";
                            cin >> category;
                            category -=1;
                              while (cin.fail()) {
                                cin.clear(); // Clear the error state of cin
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input buffer
                                cout << "Invalid input. Please enter an integer: ";
                                cin >> category;
                            }
                            if(category == -1)
                            {
                                break;
                            }
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";              

                            if (category < 0 || category > 6) {
                                cout << "Invalid category. Please enter a number between 0 and 6." << endl;
                                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              

                                continue;
                            }

                            cout << "Enter allergen for category " << category << ": ";
                            cin.ignore(); // Clear newline character from buffer after reading category
                            getline(cin, allergen);
                            cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              

                            // Add allergy to the patient record
                            patient.addAllergy(category, allergen); // Category 1 (example: pollen)
                        }
                    }

                    patientVector.push_back(patient);
                } else {
                    cout << "Invalid Option\n";
                }
                break;
            }
             case 2:
            {
                // Add new appointment
                int pid, did, st, ed;
                cout << "Adding New Appointment...\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"\nEnter The Patient Due For Appointment\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"ID: ";
                cin>>pid;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout<<"Enter The Doctor To Be Scheduled\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"ID: ";
                cin>>did;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout<<"Enter Start Time of Todays Appointment\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"Time (0000): ";
                cin>>st;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout<<"Enter End Time of Todays Appointment\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"Time (0000): ";
                cin>>ed;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

                makeappointment(&doctorVector, &patientVector,did, pid, st,ed);
                cout<<endl;

                break;
                }
            case 3:
            {
                int calOp;
                cout << "Canceling Appointment...\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"\nSelect Option (1,2):\n\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"1. Doctor\n2. Patient\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"Option: ";
                cin >>calOp;
                if(calOp == 1)
                {
                    int c;
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    cout<<"CLearing All Scheduled Appointments Of...";
                    cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                    cout<<"Enter ID: ";
                    cin>>c;
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                    for (const auto& patient : patientVector) {
                        if (patient.getDoctorid() == c) {
                            TimeSlot sl = patient.giveslot();
                            int pid = patient.getPid();
                            cancelappointment(&doctorVector, &patientVector,c, pid,sl );
                    }
                    }
                
                }
                else if(calOp ==2){
                    int delID;
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                    cout<<"Canceling Appointment For...";
                    cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                    cout<<"Enter ID: ";
                    cin>>delID;
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                   for (const auto& doctor : doctorVector) {
                    vector<Patient*> patientPtrVector = doctor.getPatientsUnderCare();
                    int did = doctor.getID();
    
                    for (const auto& patPtr : patientPtrVector) {
                        Patient* pat = patPtr; // Dereference the pointer to get the Patient object
        
                        if (pat->getPid() == delID) {
                            TimeSlot sl = pat->giveslot();
                            int pid = pat->getPid();
                            cancelappointment(&doctorVector, &patientVector, did, pid, sl);
                        }
                        }
                    }
                }
                break;
                }

            case 4:
            {
                // Prompt user to select patient to edit
                int patientIndex;
                    char ch;
                    bool hospitalized, disabled, medication, allergies;
                // Edit existing data
                cout << "Editing Data...\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"\nEnter The Patient Information to Update\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"ID: ";
                cin>>patientIndex;
                cin.ignore(); // Clear newline character from buffer

                // Validate user input
                if (patientIndex <0 || patientIndex > static_cast<int>(patientVector.size())) {
                    cout << "Invalid selection!" << endl;
                    break;
                }

                // Get reference to the selected patient
                Patient& patient = patientVector[patientIndex];

                // Prompt for edits, only update non-empty fields
                string input;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "Editing Patient Data of "<<patient.getFirstName()<<" "<<patient.getLastName() <<"\n\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout<<"NOTE: LEAVE EMPTY TO KEEP CURRENT (ENTER KEY):\n\n";
                cout << "First Name  : ";
                getline(cin, input);
                if (!input.empty()) {
                patient.setFirstName(input);
                }
                cout << "Middle Name : ";
                getline(cin, input);
                if (!input.empty()) {
                patient.setMiddleName(input);
                }
                cout << "Family Name : ";
                getline(cin, input);
                if (!input.empty()) {
                    patient.setLastName(input);
                }
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "Age (Years): ";
                getline(cin, input);
                if (!input.empty()) {
                    int age;
                    stringstream(input) >> age;
                    patient.setAge(age);
                }
                cout << "Sex (M | F): ";
                getline(cin, input);
                if (!input.empty()) {
                    char sex = toupper(input[0]);
                    patient.setSex(sex == 'M');
                }
                cout << "Height (FT): ";
                getline(cin, input);
                if (!input.empty()) {
                    int heightFeet;
                    stringstream(input) >> heightFeet;
                    patient.setHeightFeet(heightFeet);
                }
                cout << "Height (IN): ";
                getline(cin, input);
                if (!input.empty()) {
                    int heightInches;
                    stringstream(input) >> heightInches;
                    patient.setHeightInches(heightInches);
                }
                cout << "Weight (LB): ";
                getline(cin, input);
                if (!input.empty()) {
                    int weight;
                    stringstream(input) >> weight;
                    patient.setWeight(weight);
                }
                cout << "Birth Day (dd)   : ";
                getline(cin, input);
                if (!input.empty()) {
                    int day;
                    stringstream(input) >> day;
                    patient.setDay(day);
                }
                cout << "Birth Month (mm) : ";
                getline(cin, input);
                if (!input.empty()) {
                    int month;
                    stringstream(input) >> month;
                    patient.setMonth(month);
                }
                cout << "Birth Year (yyyy): ";
                getline(cin, input);
                if (!input.empty()) {
                    int year;
                    stringstream(input) >> year;
                    patient.setYear(year);
                }
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "Room   : ";   
                getline(cin, input);
                if (!input.empty()) {
                    patient.setRoom(input);
                }      
                cout << "Address: ";            
                getline(cin, input);
                if (!input.empty()) {
                    patient.setAddress(input);
                }
                cout << "Phone Number: +";         
                getline(cin, input);
                if (!input.empty()) {
                    long phoneNumber;
                    stringstream(input) >> phoneNumber;
                    patient.setPhone(phoneNumber);
                }
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";              
                cout << "Emergency Contact    : ";                   
                getline(cin, input);
                if (!input.empty()) {
                patient.setEmergencyContactName(input);
                }

                cout << "Emergency Phonenumber: +";
                getline(cin, input);
                if (!input.empty()) {
                    long emergencyContactPhone;
                    stringstream(input) >> emergencyContactPhone;
                    patient.setEmergencyContactPhone(emergencyContactPhone);
                }
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                bool alive;  
                cout<<"Please Restate Your Answers (No Empty):\n\n";            
                    cout << "Hospitalized? (Y/N) : ";
                    cin >> ch;
                    hospitalized = (ch == 'Y' || ch == 'y');
                    cout << "A Disability? (Y/N) : ";
                    cin >> ch;
                    disabled = (ch == 'Y' || ch == 'y');
                    cout << "Is Medicated? (Y/N) : ";
                    cin >> ch;
                    medication = (ch == 'Y' || ch == 'y');
                    cout << "Has Allergies? (Y/N): ";
                    cin >> ch;
                    allergies = (ch == 'Y' || ch == 'y');
                    cout << "Is Alive? (Y/N): ";
                    cin >> ch;
                    alive = (ch == 'Y' || ch == 'y');
                    if(!alive)
                    {
                        for (const auto& doctor : doctorVector) {
                    vector<Patient*> patientPtrVector = doctor.getPatientsUnderCare();
                        int did = doctor.getID();
                    for (const auto& patPtr : patientPtrVector) {
                        Patient* pat = patPtr; // Dereference the pointer to get the Patient object
        
                        if (pat->getPid() == patientIndex) {
                            TimeSlot sl = pat->giveslot();
                            int pid = pat->getPid();
                            cancelappointmentD(&doctorVector, &patientVector, did, pid, sl);
                        }
                        }
                    } 
                    }
                    patient.setbool(alive,hospitalized, disabled,medication, allergies);

                    string allergen;
                    int category;
                    if (allergies) {
                        // Assuming there are 7 categories (0-6)
                        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";              
                        cout << "Enter allergies by category (1-7):" << endl;
                        cout << "Category 1: Other" <<endl
                             << "Category 2: Pollen"<<endl
                             << "Category 3: Food"  <<endl
                             << "Category 4: Medication" <<endl
                             << "Category 5: None" <<endl
                             << "Category 6: Mold"<<endl 
                             << "Category 7: Chemical" << endl;
                        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              


                        while (true) {
                            cout << "Enter category (0 to stop): ";
                            cin >> category;
                            category -=1;
                              while (cin.fail()) {
                                cin.clear(); // Clear the error state of cin
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input buffer
                                cout << "Invalid input. Please enter an integer: ";
                                cin >> category;
                            }
                            if(category == -1)
                            {
                                break;
                            }
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";              

                            if (category < 0 || category > 6) {
                                cout << "Invalid category. Please enter a number between 0 and 6." << endl;
                                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              

                                continue;
                            }

                            cout << "Enter allergen for category " << category << ": ";
                            cin.ignore(); // Clear newline character from buffer after reading category
                            getline(cin, allergen);
                            cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              

                            // Add allergy to the patient record
                            patient.addAllergy(category, allergen); // Category 1 (example: pollen)
                        }
                    }

                // Confirmation message
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              
                cout << "Patient details updated successfully!" << endl;
                break;
            }

            case 5:
            {
                int doctorIndex;
                    char ch;
                    bool hospitalized, disabled, medication, allergies;
                // Edit existing data
                cout << "Editing Data...\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"\nEnter The Doctors' Information to Update\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"ID: ";
                cin>>doctorIndex;
                cin.ignore(); // Clear newline character from buffer

                // Validate user input
                if (doctorIndex <0 || doctorIndex > static_cast<int>(doctorVector.size())) {
                    cout << "Invalid selection!" << endl;
                    break;
                }

                // Get reference to the selected doctor
                Doctor& doctor = doctorVector[doctorIndex];

                // Prompt for edits, only update non-empty fields
                string input;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "Editing Doctor Data of Dr."<<doctor.getFirstName()<<" "<<doctor.getLastName() <<"\n\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout<<"NOTE: LEAVE EMPTY TO KEEP CURRENT (ENTER KEY):\n\n";
                cout << "First Name  : ";
                getline(cin, input);
                if (!input.empty()) {
                doctor.setFirstName(input);
                }
                cout << "Middle Name : ";
                getline(cin, input);
                if (!input.empty()) {
                doctor.setMiddleName(input);
                }
                cout << "Family Name : ";
                getline(cin, input);
                if (!input.empty()) {
                    doctor.setLastName(input);
                }
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "Age (Years): ";
                getline(cin, input);
                if (!input.empty()) {
                    int age;
                    stringstream(input) >> age;
                    doctor.setAge(age);
                }
                cout << "Sex (M | F): ";
                getline(cin, input);
                if (!input.empty()) {
                    char sex = toupper(input[0]);
                    doctor.setSex(sex == 'M');
                }
                cout << "Height (FT): ";
                getline(cin, input);
                if (!input.empty()) {
                    int heightFeet;
                    stringstream(input) >> heightFeet;
                    doctor.setHeightFeet(heightFeet);
                }
                cout << "Height (IN): ";
                getline(cin, input);
                if (!input.empty()) {
                    int heightInches;
                    stringstream(input) >> heightInches;
                    doctor.setHeightInches(heightInches);
                }
                cout << "Weight (LB): ";
                getline(cin, input);
                if (!input.empty()) {
                    int weight;
                    stringstream(input) >> weight;
                    doctor.setWeight(weight);
                }
                cout << "Birth Day (dd)   : ";
                getline(cin, input);
                if (!input.empty()) {
                    int day;
                    stringstream(input) >> day;
                    doctor.setDay(day);
                }
                cout << "Birth Month (mm) : ";
                getline(cin, input);
                if (!input.empty()) {
                    int month;
                    stringstream(input) >> month;
                    doctor.setMonth(month);
                }
                cout << "Birth Year (yyyy): ";
                getline(cin, input);
                if (!input.empty()) {
                    int year;
                    stringstream(input) >> year;
                    doctor.setYear(year);
                }
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout << "Office : ";   
                getline(cin, input);
                if (!input.empty()) {
                    doctor.setOffice(input);
                }      
                cout << "Address: ";            
                getline(cin, input);
                if (!input.empty()) {
                    doctor.setAddress(input);
                }
                cout << "Phone Number: +";         
                getline(cin, input);
                if (!input.empty()) {
                    long phoneNumber;
                    stringstream(input) >> phoneNumber;
                    doctor.setPhone(phoneNumber);
                }
                cout << "Speciality  : ";         
                getline(cin, input);
                if (!input.empty()) {
                    doctor.setSp(input);
                }  
                cout << "Experience  : ";         
                getline(cin, input);
                if (!input.empty()) {
                    int yr;
                    stringstream(input) >> yr;
                    doctor.exp(yr);
                }
                // Confirmation message
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              
                cout << "Doctor details updated successfully!" << endl;
                break;
            }
            case 6:
            {
                cout<<"Big Data Search...\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

               // Search data
                cout << "Search Criteria:\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

                cout << "1. First Name\n";
                cout << "2. Last Name\n";
                cout << "3. Room\n";
                cout << "4. Hospitalized (Y/N)\n";
                cout << "5. Disabled (Y/N)\n";
                cout << "6. Medicated (Y/N)\n";
                cout << "7. Allergies (Y/N)\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "Enter option: ";
                int searchCriterion;
                cin >> searchCriterion;
                 while (cin.fail()) {
                cin.clear(); // Clear the error state of cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input buffer
                cout << "Invalid input. Please enter an integer: ";
                cin >> searchCriterion;
                }
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

                cin.ignore();
               
                cout << "Enter search term: ";
                getline(cin,searchTerm);

                displayPatients(patientVector, searchCriterion, searchTerm);
                cout<<endl;
                
                break;
            }

            case 7:
            {
                // View data
                cout << "View Data...\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              
                cout<<"Select Option (1,2):\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              
                cout<<"\n1. Doctor\n2. Patient\n\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              
                cout<<"Option: ";
                int viewOption;
                cin >> viewOption;
                cin.ignore(); // Clear newline character from buffer after reading viewOption
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";              
                if (viewOption == 1) {
                    cout << "View Doctor Data...\n\n";
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              
                    cout<<"Enter Doctor ID: ";
                    int docID;
                    cin >> docID;
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";              
                    int lid = findLD(&doctorVector,docID);
                    if (lid >= 0 && lid < doctorVector.size() && lid != -1) {
                        doctorVector[lid].display();
                    } else {
                        cout << "Invalid Doctor ID\n";
                    }
                } else if (viewOption == 2) {
                    cout << "View Patient Data...\n\n";
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";              
                    cout<<"Enter Patient ID: ";
                    int patID;
                    cin >> patID;
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";     
                    int pid = findLP(&patientVector,patID);        
                    if (pid >= 0 && pid < patientVector.size()&& pid != -1) {
                        patientVector[pid].display();
                    } else {
                        cout << "Invalid Patient ID\n";
                    }
                } else {
                    cout << "Invalid Option\n";
                }
                cout<<endl;
                break;}
            case 8:
            {
                int op;
                cout << "Showing List...\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"\nSelect Option (1,2):\n\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"1. Doctor\n2. Patient\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"Option: ";
                cin >>op;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                if(op == 1)
                {
                     // Display existing data for editing
                    cout << "Existing Doctors:" << endl<<endl;
                    // Iterate through doctorVector and display doctors
                    for (size_t i = 0; i < doctorVector.size(); ++i) {
                        cout <<"ID  : "<< doctorVector[i].getID()  << endl<<"Name: Dr." << doctorVector[i].getFirstName() <<" "<<doctorVector[i].getLastName()<< endl<<endl;
                    }
                }
                else if(op == 2)
                {
                    // Display existing data for editing
                    cout << "Existing Patients:" << endl<<endl;
                    // Iterate through patientVector and display patients
                    for (size_t i = 0; i < patientVector.size(); ++i) {
                        cout <<"ID  : "<< patientVector[i].getPid()  << endl<<"Name: " <<patientVector[i].getFirstName() <<" "<<patientVector[i].getLastName()<< endl<<endl;
                    }

                }
                else{
                    cout<<"Invalid Option!";
                }
                cout<<endl;
                break;

            }
            case 9:
            {
                // Delete data
                cout << "Deleting Data...\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"\nSelect Option (1,2):\n\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"1. Doctor\n2. Patient\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"Option: ";
                int delOp, delID;
                cin >>delOp;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                cout<<"Finding Data to Delete...";
                cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"Enter ID: ";
                cin>>delID;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                if(delOp == 1)
                {
                    for (const auto& patient : patientVector) {

                        if (patient.getDoctorid() == delID) {
                            TimeSlot sl = patient.giveslot();
                            int pid = patient.getPid();
                            cancelappointmentD(&doctorVector, &patientVector,delID, pid,sl );
                    }
                          

                    }
                 // Find the doctor with the specified ID
                    auto it = find_if(doctorVector.begin(), doctorVector.end(),
                                    [delID](const Doctor& doc) { return doc.getID() == delID; });

                if (it != doctorVector.end()) {
                    // Erase the doctor from the vector
                        doctorVector.erase(it);

                    cout << "Doctor with ID " << delID << " deleted successfully.\n\n";
                } else {
                     cout << "Doctor with ID " << delID << " not found.\n\n";
                    }
                }
                else if(delOp ==2){
                   for (const auto& doctor : doctorVector) {
                    vector<Patient*> patientPtrVector = doctor.getPatientsUnderCare();
                    int did = doctor.getID();
    
                    for (const auto& patPtr : patientPtrVector) {
                        Patient* pat = patPtr; // Dereference the pointer to get the Patient object
        
                        if (pat->getPid() == delID) {
                            TimeSlot sl = pat->giveslot();
                            int pid = pat->getPid();
                            cancelappointmentD(&doctorVector, &patientVector, did, pid, sl);
                        }
                        }
                    }

                    // Find the  patientwith the specified ID
                    auto it = find_if(patientVector.begin(), patientVector.end(),
                                    [delID](const Patient& pat) { return pat.getPid() == delID; });

                if (it != patientVector.end()) {
                    // Erase the doctor from the vector
                        patientVector.erase(it);

                    cout << "Patient with ID " << delID << " deleted successfully.\n\n";
                } else {
                     cout << "Patient with ID " << delID << " not found.\n\n";
                    }
                }
   
                break;
            }
            case 10:{
                cout << "Exiting the program. Goodbye!\n";
                cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                running = false; // Exit the loop
                break;}

            default:
            {
                cout << "Invalid option. Please try again.\n";
                break;}
        }
    }

    return 0;
}

