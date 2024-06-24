
string Patient::getDoctorN() const{
        string drn;
        drn = "Dr."+ assignedDoctor->getLastName();
        return drn;
    }
int Patient::getDoctorid() const{
        int id;
        id =assignedDoctor->getID();
        return id;
    }
void Patient::removeD() {
        doc = false;
         // Optionally, set to nullptr for safety
    }
void Doctor::removePatient(Patient* patient){
        auto it = std::find(patientsUnderCare.begin(), patientsUnderCare.end(), patient);
        if (it != patientsUnderCare.end()) {
            patientsUnderCare.erase(it);
        }
    }
void Patient::display () const
    {
        cout << "Loading Patient Information...\n";
        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

        char sx = getSex()? 'M' : 'F';
        cout<<  "Patient ID : "<<getPid()<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
         if(!isAlive())
        {
        cout<<"Notice: Unfortunately Patient is Deceased.\n";
        cout<<  "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        }
        cout << "Name: " << getFirstName() << " " << getMiddleName() << " " << getLastName()<< endl;
        cout << "Age : "<< getAge() << endl;
        cout << "Sex : " << sx<< endl;
        cout << "Height  : "<< getHeightFeet() <<" FT "<< getHeightInches()<<" IN"<<endl;
        cout << "Weight  : "<< getWeight()<<" LB"<<endl;
        cout << "Birthday: " << getBirthday()<<endl;
        cout<<  "~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  \n";
        cout << "Room   : " << getRoom() << endl;
        cout << "Address: "<< getAddress()<<endl;
        cout << "Phone Number: +" << getPhoneNumber()<<endl;
        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        if(doc)
        {
        cout<<  "Assigned Doctor  : "<< getDoctorN()<<endl;
        cout<<  "Doctor's ID No.  : "<< getDoctorid()<<endl;
        }
        cout << "Emergency Contact: " << getEName() << endl;
        cout << "Emergency Phone  : +"<< getEPhone()<<endl;
        
        if (allergies)
        displayAllergies();
        displayAppointment();
    }


int findLP( vector<Patient>* pts,int id ) 
{
    bool found;
    int pct= -1;
    vector<Patient>& tempP = *pts;
    for (const auto& patient : tempP) {
        pct++;
                if (patient.getPid() == id) {
                    found = true;
                    break;
                }
            }
    if(!found)
        return -1;
    return pct;
}

int findLD(vector<Doctor>* drs,  int id) 
{
    bool found;
    int dct= -1;
    vector<Doctor>& tempD = *drs;
     for (const auto& doctor : tempD) {
        dct++;
                if (doctor.getID() == id) {
                    found = true;
                    break;
                }
            }
    if (!found)
        return -1;
    return dct;
}


void makeappointment(vector<Doctor>* drs, vector<Patient>* pts,int dd, int pd, int start, int end)
{

    int pct,dct;
    vector<Doctor>& tempD = *drs;
    vector<Patient>& tempP = *pts;
    dct = findLD(drs,dd);
    pct = findLP(pts,pd);
    if( pct != -1&& dct != -1)
    {

    TimeSlot appointmentTime(start, end); // 9:30 AM to 10:30 AM

    // Schedule an appointment
    Scheduler::scheduleAppointment(tempD[dct], tempP[pct], appointmentTime);
    }
    else
    {
        cout<<"Patient Or Doctor ID Not Found!\n";
    }
}
void cancelappointment(vector<Doctor>* drs, vector<Patient>* pts,int dd, int pd, TimeSlot tm)
{

    int pct,dct;
    vector<Doctor>& tempD = *drs;
    vector<Patient>& tempP = *pts;
    dct = findLD(drs,dd);
    pct = findLP(pts,pd);
    if( pct != -1&& dct != -1)
    {


    // Schedule an appointment
    Scheduler::cancelAppointment(tempD[dct], tempP[pct], tm);
    }
    else
    {
        cout<<"Patient Or Doctor ID Not Found!\n";
    }
}
void cancelappointmentD(vector<Doctor>* drs, vector<Patient>* pts,int dd, int pd, TimeSlot tm)
{

    int pct,dct;
    vector<Doctor>& tempD = *drs;
    vector<Patient>& tempP = *pts;
    dct = findLD(drs,dd);
    pct = findLP(pts,pd);
    if( pct != -1&& dct != -1)
    {


    // Schedule an appointment
    Scheduler::cancelAppointmentDel(tempD[dct], tempP[pct], tm);
    }
    else
    {
        cout<<"Patient Or Doctor ID Not Found!\n";
    }
}



// Function to display patient data based on search criteria
void displayPatients(const vector<Patient>& patients, int searchCriterion, const string& searchTerm) {
    bool found = false;
    switch (searchCriterion) {
        case 1: // First Name
            for (const auto& patient : patients) {
                if (patient.getFirstName() == searchTerm) {
                    patient.display(); // Assuming Patient has a display() method
                    found = true;
                }
            }
            break;
        case 2: // Last Name
            for (const auto& patient : patients) {
                if (patient.getLastName() == searchTerm) {
                    patient.display(); // Assuming Patient has a display() method
                    found = true;
                }
            }
            break;
        case 3: // Room
            for (const auto& patient : patients) {
                if (patient.getRoom() == searchTerm) {
                    patient.display(); // Assuming Patient has a display() method
                    found = true;
                }
            }
            break;
        case 4: // Hospitalized
            for (const auto& patient : patients) {
                if (patient.isHospitalized() && searchTerm == "Y") {
                    patient.display(); // Assuming Patient has a display() method
                    found = true;
                } else if (!patient.isHospitalized() && searchTerm == "N") {
                    patient.display(); // Assuming Patient has a display() method
                    found = true;
                }
            }
            break;
        case 5: // Disabled
            for (const auto& patient : patients) {
                if (patient.isDisabled() && searchTerm == "Y") {
                    patient.display(); // Assuming Patient has a display() method
                    found = true;
                } else if (!patient.isDisabled() && searchTerm == "N") {
                    patient.display(); // Assuming Patient has a display() method
                    found = true;
                }
            }
            break;
        case 6: // Medicated
            for (const auto& patient : patients) {
                if (patient.isOnMedication() && searchTerm == "Y") {
                    patient.display(); // Assuming Patient has a display() method
                    found = true;
                } else if (!patient.isOnMedication() && searchTerm == "N") {
                    patient.display(); // Assuming Patient has a display() method
                    found = true;
                }
            }
            break;
        case 7: // Allergies
            for (const auto& patient : patients) {
                if (patient.hasAllergies() && searchTerm == "Y") {
                    patient.display(); // Assuming Patient has a display() method
                    found = true;
                } else if (!patient.hasAllergies() && searchTerm == "N") {
                    patient.display(); // Assuming Patient has a display() method
                    found = true;
                }
            }
            break;
        default:
            cout << "Invalid search criterion.\n";
            return;
    }

    if (!found) {
        cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "No patients found matching the criteria.\n";
    }
}
