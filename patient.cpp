class Patient : public Human
{
private:
            int patientID;
            string room, eName;
            long ePhone;
            bool hospitalized, disabled, medication, allergies, doc;
            Allergies patientAllergies;
            Doctor* assignedDoctor; // Pointer to the assigned doctor
            TimeSlot appointment; // Patient's scheduled appointments


public:
            // Constructor to initialize Patient specific variables and Human variables
            Patient(string firstName, string lastName, string middleName,
                    string addr, long phoneNumber, int personAge,
                    int birthDay, int birthMonth, int birthYear,
                    int feetHeight, int inchesHeight, int wght,
                    bool gender, bool alive,
                    string roomNumber, bool inHospital, bool isDisabled,
                    bool onMedication, bool hasAllergies, string enm, long ephn)
                : Human(firstName, lastName, middleName, addr, phoneNumber,
                        personAge, birthDay, birthMonth, birthYear,
                        feetHeight, inchesHeight, wght, gender, alive),
                  room(roomNumber), hospitalized(inHospital), disabled(isDisabled),
                  medication(onMedication), allergies(hasAllergies) ,eName(enm),ePhone(ephn),appointment(0000,2400)
            {
                        doc = false;
                        patientID = ptid++;// Constructor body
            }
            void setRoom(const string& newRoom) {
                        room = newRoom;
            }

            void setEmergencyContactName(const string& newName) {
                        eName = newName;
            }
            void setEmergencyContactPhone(long newPhone) {
                        ePhone = newPhone;
            }
            void setbool( bool alive,bool inHospital, bool isDisabled,bool onMedication, bool hasAllergies) {
                        hospitalized = inHospital;
                        disabled = isDisabled;
                        medication = onMedication;
                        allergies=hasAllergies;
                        if(!hasAllergies)
                        {
                                    patientAllergies.removeAllergies();
                        }
                        setLife(alive);
            }
            
            void setFirstName(const string& newFirstName) {
                        setFirstNam(newFirstName);
            }

            void setLastName(const string& newLastName) {
                        setLastNam(newLastName);
            }

            void setMiddleName(const string& newMiddleName) {
                        setMiddleNam(newMiddleName);
            }

            void setAddress(const string& newAddress) {
                        setAddres(newAddress);
            }

            void setAge(int newAge) {
                        setAg(newAge);
            }

            void setDay(int newDay){
                        setDa(newDay);

            }
            void setMonth(int newMonth) {
                        setMont(newMonth);    }
            void setYear( int newYear) {
            
                        setYea(newYear);
            }

            void setHeightFeet(int newFtHeight) {
                        setHeightFee(newFtHeight);
            }
            void setHeightInches(int newInHeight) {
                        setHeightInche(newInHeight);
            }

            void setWeight(int newWeight) {
                        setWeigh(newWeight);
            }

            void setPhone(long newPhone) {
                        setPhon(newPhone);
            }

            void setSex(bool newSex) {
                        setSe(newSex);
            }

            // Getter functions specific to Patient class
            string getRoom() const { return room; }
            int getPid() const
            {
                        return patientID;
            }
            string getEName() const { return eName; }
            
            bool isHospitalized() const { return hospitalized; }
            bool isDisabled() const { return disabled; }
            bool isOnMedication() const { return medication; }
            bool hasAllergies() const { return allergies; }
            long getEPhone() const {return ePhone;}
            // Getter function to access patient's allergies
            const Allergies& getAllergies() const { return patientAllergies; }
            // Method to assign a doctor to the patient
            void assignDoctor(Doctor& doctor)
            {
                        doc = true;
                        assignedDoctor = &doctor;
            }

            // Method to get assigned doctor
            Doctor* getAssignedDoctor() const
            {
                        return assignedDoctor;
            }
            void scheduleAppointment(TimeSlot slot) {
                        appointment = slot;
            }
            void cancelAppointment() {
                        appointment= TimeSlot(0000,2400);
            }
            TimeSlot giveslot() const
            {
                        return appointment;
            }

            bool hasAppointment() const {// Check if the patient has an appointment overlapping with the specified time range
                        if (appointment.startTime == 0000 && appointment.endTime == 2400) {
                                    return false;
                        }
                        return true;
            }
            // Method to add an allergy to the patient

            void addAllergy(int category, const string& allergen) {
                        // Check if the category exists in the map
                        if (patientAllergies.mpAlToMn.find(category) != patientAllergies.mpAlToMn.end()) {
                                    // Add allergen to the existing category
                                    patientAllergies.mpAlToMn[category].push_back(allergen);
                        } else {
                                    // Create a new category and add the allergen
                                    vector<string> allg;
                                    allg.push_back(allergen);
                                    patientAllergies.mpAlToMn[category] = allg;
                        }
            }
            // Method to display allergies
            void displayAllergies() const
            {
                        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                        cout << "Allergies for Patient " << this->getFirstName() << " " << this->getLastName() << ":" << endl;
                        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";


                        for (const auto& category : patientAllergies.mpAlToMn)
                        {
                                    
                                    if (!category.second.empty()) // Check if the vector is not empty
                                    {
                                                int ch = category.first;
                                                string arr[8] = {"Other","Pollen","Food","Medication","Animals","Mold","Chemicals"};
                                                cout << "Category: " << arr[ch] << endl;
                                                cout << "Allergens: ";
                                                int cnt =0;
                                                for (const auto& allergen : category.second)
                                                {
                                                            if( cnt == 0)
                                                            {
                                                                        cnt =1;
                                                                        cout << allergen ;
                                                            }
                                                            else
                                                            {
                                                                        cout << ", "<<allergen;
                                                            }
                                                }
                                                cout <<endl;
                                    }
                                    else
                                    {
                                                //cout << "No allergens recorded for this category." << endl;
                                    }
                        }
            }

            // Method to get all allergies of the patient
            map<int, vector<string> > getAllergiesMp() const {
                        return patientAllergies.mpAlToMn;
            }
            string getDoctorN() const;
            void display () const;
            int getDoctorid() const;
            void removeD();
            
            void displayAppointment() const {
            
                        // If there are no busy slots, print "None" and return
                        if (appointment.startTime == 0000 && appointment.endTime == 2400) {
                                    //  cout << "None" << endl;
                                    return;
                        }
                        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                        cout << "Appointment Of The Day" << endl<<endl;

                        // If there are busy slots, print each busy slot
                        auto formatTime = [](int time) -> string {
                                    int hours = time / 100;
                                    int minutes = time % 100;
                                    char buffer[6];
                                    snprintf(buffer, sizeof(buffer), "%02d:%02d", hours, minutes);
                                    return string(buffer);
                        };

                        
                                    string start = formatTime(appointment.startTime);
                                    string end = formatTime(appointment.endTime);

                                    cout << "Attended to from " << start << " to " << end << endl;
                        
                        
            }
};
