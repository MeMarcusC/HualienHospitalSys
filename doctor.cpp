// Define the Doctor class inheriting from Human
class Doctor : public Human
{
private:
    string office, specialization;
    int experienceYears, doctorID;
    vector<Patient*> patientsUnderCare; // Vector of pointers to patients under care
    vector<TimeSlot> availability; // Doctor's availability schedule

public:
    // Constructor to initialize Doctor specific variables and Human variables
    Doctor(string firstName, string lastName, string middleName,
           string addr, long phoneNumber, int personAge,
           int birthDay, int birthMonth, int birthYear,
           int feetHeight, int inchesHeight, int wght,
           bool gender, bool alive,
           string speciality, int expYears, string off)
        : Human(firstName, lastName, middleName, addr, phoneNumber,
                personAge, birthDay, birthMonth, birthYear,
                feetHeight, inchesHeight, wght, gender, alive),
          specialization(speciality), experienceYears(expYears), office(off)
    {
        doctorID = drid++;
        // Initialize the doctor's availability to be free all day (00:00 - 23:59)
        //availability.push_back(TimeSlot(0, 0));
    }

    // Getter functions specific to Doctor class
    string getSpecialization() const { return specialization; }
    int getExperienceYears() const { return experienceYears; }
    int getID() const {
        return doctorID;
    }
    vector<Patient*> getPatientsUnderCare() const {
        return patientsUnderCare; // Return a copy of the vector
    }

    // Method to add a patient under care
    void addPatient(Patient& patient)
    {
        patientsUnderCare.push_back(&patient);
    }

    // Method to list patients under care
    void listPatientsUnderCare() const {
        if (patientsUnderCare.empty()) {
            // No patients under care
        } else {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            cout << "Patients under the care of Dr." << getLastName() << ":" << endl << endl;
            for (const auto& patient : patientsUnderCare) {
                cout << patient->getFirstName() << " " << patient->getLastName() << endl;
            }
        }
    }

    // Method to add availability time slot
    void addAvailability(const TimeSlot slot) {
        availability.push_back(slot);
    }

    // Method to remove availability time slot
    void removeAvailability(const TimeSlot& slot) {
        auto it = std::find_if(availability.begin(), availability.end(),
                               [&slot](const TimeSlot& timeSlot) {
                                   return timeSlot == slot;
                               });
        if (it != availability.end()) {
            availability.erase(it);
        }
    }

    // Method to check if the doctor is free in a specified time range
    bool isFree(int startTime, int endTime) const {
        // Check if the doctor is free within the specified time range
        for (const auto& slot : availability) {
            if (!(endTime <= slot.startTime || startTime >= slot.endTime)) {
                // There is an overlap with an existing slot
                return false;
            }
        }
        // No overlap with any existing slots, so the time range is free
        return true;
    }

    // Getter for office
    string getOffice() {
        return office;
    }

    // Method to display busy schedule of the doctor
    void displayBusySchedule() const {
        // Check if there are any busy slots
        bool hasBusySlots = false;
        for (const auto& slot : availability) {
            if (slot.startTime != 0 || slot.endTime != 2359) {
                hasBusySlots = true;
                break; // Exit the loop early since we found at least one busy slot
            }
        }

        // If there are no busy slots, print "None" and return
        if (!hasBusySlots) {
            //  cout << "None" << endl;
            return;
        }
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Dr." << getLastName() << "'s Busy Schedule:" << endl << endl;

        // If there are busy slots, print each busy slot
        auto formatTime = [](int time) -> string {
            int hours = time / 100;
            int minutes = time % 100;
            char buffer[6];
            snprintf(buffer, sizeof(buffer), "%02d:%02d", hours, minutes);
            return string(buffer);
        };

        for (const auto& slot : availability) {
            if (slot.startTime != 0 || slot.endTime != 2359) {
                string start = formatTime(slot.startTime);
                string end = formatTime(slot.endTime);

                cout << "Busy from " << start << " to " << end << endl;
            }
        }
    }

    // Method to display doctor's information
    void display()
    {
        cout << "Loading Doctor Information...\n";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

        if (!isAlive())
        {
            cout << "Notice: Unfortunately Doctor is Deceased.\n";
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        }
        char sx = getSex() ? 'M' : 'F';
        cout << "Doctor ID : " << getID() << endl;
        cout << "Name: Dr." << getFirstName() << " " << getMiddleName() << " " << getLastName() << endl;
        cout << "Age : " << getAge() << endl;
        cout << "Sex : " << sx << endl;
        cout << "Height  : " << getHeightFeet() << " FT " << getHeightInches() << " IN" << endl;
        cout << "Weight  : " << getWeight() << " LB" << endl;
        cout << "Birthday: " << getBirthday() << endl;
        cout << "~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  ~~  \n";
        cout << "Office : " << getOffice() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "Phone Number  : +" << getPhoneNumber() << endl;
        cout << "Specialization: " << getSpecialization() << endl;
        cout << "Experience    : " << getExperienceYears() << " Years" << endl;
        listPatientsUnderCare();
        displayBusySchedule();
    }

    // Method to remove a patient from under care
    void removePatient(Patient* patient);

    // Setter for office
    void setOffice(const string& newRoom) {
        office = newRoom;
    }

    // Setter for specialization
    void setSp(const string& spec)
    {
        specialization = spec;
    }

    // Setter for first name
    void setFirstName(const string& newFirstName) {
        setFirstNam(newFirstName);
    }

    // Setter for last name
    void setLastName(const string& newLastName) {
        setLastNam(newLastName);
    }

    // Setter for middle name
    void setMiddleName(const string& newMiddleName) {
        setMiddleNam(newMiddleName);
    }

    // Setter for address
    void setAddress(const string& newAddress) {
        setAddres(newAddress);
    }

    // Setter for age
    void setAge(int newAge) {
        setAg(newAge);
    }

    // Setter for day of birth
    void setDay(int newDay) {
        setDa(newDay);
    }

    // Setter for month of birth
    void setMonth(int newMonth) {
        setMont(newMonth);
    }

    // Setter for year of birth
    void setYear(int newYear) {
        setYea(newYear);
    }

    // Setter for height in feet
    void setHeightFeet(int newFtHeight) {
        setHeightFee(newFtHeight);
    }

    // Setter for height in inches
    void setHeightInches(int newInHeight) {
        setHeightInche(newInHeight);
    }

    // Setter for weight
    void setWeight(int newWeight) {
        setWeigh(newWeight);
    }

    // Setter for experience years
    void exp(int yr) {
        experienceYears = yr;
    }

    // Setter for phone number
    void setPhone(long newPhone) {
        setPhon(newPhone);
    }

    // Setter for sex
    void setSex(bool newSex) {
        setSe(newSex);
    }
};

