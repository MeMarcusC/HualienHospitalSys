
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


struct Allergies
{
    map<int, vector<string> > mpAlToMn;
     vector<string> thr;
        vector<string> plln;
        vector<string> fd;
        vector<string> mdtn;
        vector<string> nml;
        vector<string> mld;
        vector<string> chmcl;
    Allergies()
    {
        // thr = 0,plln = 1,fd = 2,mdtn = 3,nml = 4,mld = 5,chmcl = 6;
       
        // Initialize each allergy category with a default "none"
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

