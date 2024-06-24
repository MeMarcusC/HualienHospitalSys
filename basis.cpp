using namespace std;
int ptid = 0,drid =0;
class Doctor;

// Define TimeSlot structure to represent time intervals
struct TimeSlot {
    int startTime; // in 24-hour format, e.g., 900 for 9:00 AM
    int endTime;   // in 24-hour format, e.g., 1700 for 5:00 PM

    TimeSlot(int start, int end) : startTime(start), endTime(end) {}
    
    // Define equality operator (==) for TimeSlot objects
    bool operator==(const TimeSlot& other) const {
        return startTime == other.startTime && endTime == other.endTime;
    }
};

// Struct to manage different types of allergies
struct Allergies {
    map<int, vector<string> > mpAlToMn;
    vector<string> thr;   // Allergy type: threat
    vector<string> plln;  // Allergy type: pollen
    vector<string> fd;    // Allergy type: food
    vector<string> mdtn;  // Allergy type: medication
    vector<string> nml;   // Allergy type: animals
    vector<string> mld;   // Allergy type: mold
    vector<string> chmcl; // Allergy type: chemicals

    Allergies() {
        // Initialize each allergy category with an empty vector
        mpAlToMn[0] = thr;
        mpAlToMn[1] = plln;
        mpAlToMn[2] = fd;
        mpAlToMn[3] = mdtn;
        mpAlToMn[4] = nml;
        mpAlToMn[5] = mld;
        mpAlToMn[6] = chmcl;
    }

    void removeAllergies() {
        for (auto& pair : mpAlToMn) {
            pair.second.clear(); // Clear each vector<string> in the map
        }
    }
};
