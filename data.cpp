

vector<Doctor> createDoctors()
{
    vector<Doctor> doctors;
     // Create instances of Doctor
    Doctor doctor("Alice", "Smith", "Marie", "456 Oak St", 9876543210,
                  35, 25, 7, 1989, 5, 8, 160, false, true,
                  "Cardiology", 10, "CARD 56-7");
    Doctor doctor1("Ali", "Monk", "Mart", "45 Oak St", 9876543210,
               35, 25, 7, 1989, 5, 8, 160, true, true,
               "Cardiology", 10, "CARD 56-7");

    Doctor doctor2("John", "Doe", "Michael", "123 Maple Ave", 9865432109,
               40, 10, 1, 1984, 6, 2, 175, true, true,
               "Neurology", 15, "NEUR 12-3");

    Doctor doctor3("Sarah", "Johnson", "Ann", "789 Pine Ln", 9854321098,
               45, 5, 3, 1979, 5, 6, 165, false, true,
               "Pediatrics", 20, "PED 34-8");

    Doctor doctor4("Michael", "Brown", "Lee", "321 Birch Rd", 9843210987,
               50, 20, 5, 1974, 5, 10, 180, true, true,
               "Orthopedics", 25, "ORTH 45-9");

    Doctor doctor5("Emily", "Davis", "Grace", "654 Cedar St", 9832109876,
               30, 15, 4, 1994, 5, 5, 150, false, true,
               "Dermatology", 8, "DERM 67-1");

    Doctor doctor6("James", "Wilson", "Robert", "987 Elm St", 9821098765,
               38, 8, 2, 1986, 6, 1, 170, true, true,
               "Oncology", 12, "ONCO 23-4");

    Doctor doctor7("Linda", "Martinez", "Louise", "654 Pine Ave", 9810987654,
               42, 11, 11, 1982, 5, 9, 160, false, true,
               "Gastroenterology", 18, "GAST 78-2");

    Doctor doctor8("Robert", "Garcia", "Paul", "321 Maple St", 9809876543,
               37, 27, 6, 1987, 6, 3, 175, true, true,
               "Endocrinology", 14, "ENDO 56-8");

    Doctor doctor9("Laura", "Hernandez", "Jane", "123 Oak Ln", 9798765432,
               36, 13, 9, 1988, 5, 4, 155, false, true,
               "Rheumatology", 13, "RHEU 45-7");

    Doctor doctor10("David", "Lee", "Henry", "987 Birch St", 9787654321,
               33, 19, 8, 1991, 5, 7, 160, true, true,
               "Pulmonology", 11, "PULM 34-9");

    doctors.push_back(doctor);
    doctors.push_back(doctor1);
    doctors.push_back(doctor2);
    doctors.push_back(doctor3);
    doctors.push_back(doctor4);
    doctors.push_back(doctor5);
    doctors.push_back(doctor6);
    doctors.push_back(doctor7);
    doctors.push_back(doctor8);
    doctors.push_back(doctor9);
    doctors.push_back(doctor10);

    return doctors;
}

vector<Patient> createPatients() {
    vector<Patient> patients;
    // Create instances of Patient
    Patient patient("Bob", "Johnson", "Michael", "123 Maple Ave", 9882317890,
                    45, 15, 3, 1979, 6, 1, 180, true, true,
                    "Room 101", true, false, true, true,
                    "Emma Johnson", 2345678901);
    patient.addAllergy(1, "Bee Pollen");    // Category 1 (example: pollen)
    patient.addAllergy(3, "Penicillin"); // Category 2 (example: medication)
    patient.addAllergy(3, "Benadryl"); // Category 2 (example: medication)
    Patient patient1("Alice", "Smith", "Marie", "456 Oak St", 9876543210,
                 30, 22, 4, 1994, 5, 6, 150, false, true,
                 "Room 102", true, false, true, true,
                 "John Smith", 3456789012);
patient1.addAllergy(1, "Grass Pollen");    // Category 1 (example: pollen)
patient1.addAllergy(2, "Peanuts");         // Category 2 (example: food)
patient1.addAllergy(3, "Ibuprofen");       // Category 3 (example: medication)

Patient patient2("John", "Doe", "Henry", "789 Pine Rd", 8765432109,
                 55, 13, 7, 1969, 6, 2, 200, true, true,
                 "Room 103", false, true, false, true,
                 "Jane Doe", 4567890123);
patient2.addAllergy(0, "Latex");           // Category 0 (example: other)
patient2.addAllergy(3, "Amoxicillin");     // Category 3 (example: medication)

Patient patient3("Emily", "Davis", "Ann", "321 Birch Ln", 7654321098,
                 40, 29, 10, 1983, 5, 8, 170, false, true,
                 "Room 104", true, true, true, true,
                 "Michael Davis", 5678901234);
patient3.addAllergy(1, "Dust Mites");      // Category 1 (example: pollen)
patient3.addAllergy(2, "Shellfish");       // Category 2 (example: food)
patient3.addAllergy(6, "Bleach");          // Category 6 (example: chemical)

Patient patient4("Michael", "Brown", "Lee", "654 Cedar Ct", 6543210987,
                 60, 5, 12, 1964, 6, 0, 190, true, true,
                 "Room 105", true, false, false, true,
                 "Linda Brown", 6789012345);
patient4.addAllergy(4, "None");            // Category 4 (example: none)

Patient patient5("Olivia", "Wilson", "Rose", "987 Elm Ave", 5432109876,
                 28, 17, 2, 1996, 5, 5, 140, false, true,
                 "Room 106", false, true, true, true,
                 "Ethan Wilson", 7890123456);
patient5.addAllergy(1, "Ragweed");         // Category 1 (example: pollen)
patient5.addAllergy(3, "Aspirin");         // Category 3 (example: medication)
patient5.addAllergy(3, "Sulfa Drugs");     // Category 3 (example: medication)

Patient patient6("David", "Clark", "James", "111 Maple St", 5432198765,
                 38, 11, 8, 1985, 5, 11, 160, true, true,
                 "Room 107", false, true, true, true,
                 "Sara Clark", 8901234567);
patient6.addAllergy(1, "Tree Pollen");    // Category 1 (example: pollen)
patient6.addAllergy(2, "Dairy");          // Category 2 (example: food)
patient6.addAllergy(3, "Codeine");        // Category 3 (example: medication)

Patient patient7("Sophia", "Walker", "Lynn", "222 Oak Ave", 4321987654,
                 50, 9, 5, 1974, 5, 7, 175, false, true,
                 "Room 108", true, true, false, true,
                 "Peter Walker", 9012345678);
patient7.addAllergy(0, "Pet Dander");     // Category 0 (example: other)
patient7.addAllergy(2, "Gluten");         // Category 2 (example: food)

Patient patient8("Liam", "Johnson", "Mark", "333 Pine St", 3219876543,
                 42, 14, 9, 1981, 6, 2, 185, true, true,
                 "Room 109", true, false, true, true,
                 "Ella Johnson", 1234567890);
patient8.addAllergy(1, "Mold Spores");    // Category 1 (example: pollen)
patient8.addAllergy(3, "Heparin");        // Category 3 (example: medication)
patient8.addAllergy(6, "Chlorine");       // Category 6 (example: chemical)

Patient patient9("Isabella", "Martinez", "Eva", "444 Birch Blvd", 2198765432,
                 29, 3, 12, 1994, 5, 4, 155, false, true,
                 "Room 110", false, true, false, true,
                 "Carlos Martinez", 2345678901);
patient9.addAllergy(2, "Soy");            // Category 2 (example: food)
patient9.addAllergy(4, "None");           // Category 4 (example: none)

Patient patient10("Ethan", "Lewis", "John", "555 Cedar Dr", 1987654321,
                  35, 6, 1, 1989, 6, 0, 170, true, true,
                  "Room 111", true, false, true, true,
                  "Mia Lewis", 3456789012);
patient10.addAllergy(1, "Weed Pollen");   // Category 1 (example: pollen)
patient10.addAllergy(2, "Tree Nuts");     // Category 2 (example: food)
patient10.addAllergy(3, "Morphine");      // Category 3 (example: medication)

Patient patient11("Mia", "Anderson", "Grace", "666 Elm St", 9876543210,
                  27, 25, 7, 1996, 5, 3, 145, false, true,
                  "Room 112", false, true, true, true,
                  "Lucas Anderson", 4567890123);
patient11.addAllergy(0, "Insect Stings"); // Category 0 (example: other)
patient11.addAllergy(3, "Warfarin");      // Category 3 (example: medication)

Patient patient12("Alexander", "Harris", "Luke", "777 Pine Ln", 8765432109,
                  44, 18, 11, 1979, 5, 10, 175, true, true,
                  "Room 113", true, false, true, true,
                  "Anna Harris", 5678901234);
patient12.addAllergy(2, "Eggs");          // Category 2 (example: food)
patient12.addAllergy(6, "Pesticides");    // Category 6 (example: chemical)

Patient patient13("Ava", "Robinson", "Marie", "888 Birch Rd", 7654321098,
                  33, 12, 6, 1990, 5, 7, 160, false, true,
                  "Room 114", true, true, false, true,
                  "Jack Robinson", 6789012345);
patient13.addAllergy(1, "Animal Dander"); // Category 1 (example: pollen)
patient13.addAllergy(3, "Antibiotics");   // Category 3 (example: medication)

Patient patient14("Benjamin", "White", "Noah", "999 Oak Ct", 6543210987,
                  48, 20, 10, 1975, 6, 1, 180, true, true,
                  "Room 115", true, false, true, true,
                  "Emma White", 7890123456);
patient14.addAllergy(0, "Perfumes");      // Category 0 (example: other)
patient14.addAllergy(3, "Beta Blockers"); // Category 3 (example: medication)

Patient patient15("Charlotte", "Green", "Rose", "101 Maple Ave", 5432109876,
                  31, 15, 4, 1993, 5, 6, 150, false, true,
                  "Room 116", false, false, true, false,
                  "Henry Green", 8901234567);


    // Push patients into vector
    patients.push_back(patient);
    patients.push_back(patient1);
    patients.push_back(patient2);
    patients.push_back(patient3);
    patients.push_back(patient4);
    patients.push_back(patient5);
    patients.push_back(patient6);
    patients.push_back(patient7);
    patients.push_back(patient8);
    patients.push_back(patient9);
    patients.push_back(patient10);
    patients.push_back(patient11);
    patients.push_back(patient12);
    patients.push_back(patient13);
    patients.push_back(patient14);
    patients.push_back(patient15);
  
    return patients;
}
void appointments(vector<Doctor>* drs, vector<Patient>* pts)
{
    vector<Doctor>& tempD = *drs;
    vector<Patient>& tempP = *pts;


    // Define Time Slots
    TimeSlot slot1(900, 1000);    // 9:00 AM - 10:00 AM
    TimeSlot slot2(1000, 1100);   // 10:00 AM - 11:00 AM
    TimeSlot slot3(1100, 1200);   // 11:00 AM - 12:00 PM
    TimeSlot slot4(1300, 1400);   // 1:00 PM - 2:00 PM
    TimeSlot slot5(1400, 1500);   // 2:00 PM - 3:00 PM
    TimeSlot slot6(1500, 1600);   // 3:00 PM - 4:00 PM
    TimeSlot slot7(1600, 1700);   // 4:00 PM - 5:00 PM

    // Schedule Appointments
     // Schedule an appointment
    Scheduler::scheduleAppointmentstart(tempD[0], tempP[0], slot1);   // Doctor 0, Patient 0
    Scheduler::scheduleAppointmentstart(tempD[1], tempP[1], slot2);   // Doctor 1, Patient 1
    Scheduler::scheduleAppointmentstart(tempD[2], tempP[2], slot3);   // Doctor 2, Patient 2
    Scheduler::scheduleAppointmentstart(tempD[3], tempP[3], slot4);   // Doctor 3, Patient 3
    Scheduler::scheduleAppointmentstart(tempD[4], tempP[4], slot5);   // Doctor 4, Patient 4
    Scheduler::scheduleAppointmentstart(tempD[5], tempP[5], slot6);   // Doctor 5, Patient 5
    Scheduler::scheduleAppointmentstart(tempD[6], tempP[6], slot7);   // Doctor 6, Patient 6

    // Additional Appointments
    TimeSlot slot8(930, 1030);    // 9:30 AM - 10:30 AM
    TimeSlot slot9(1030, 1130);   // 10:30 AM - 11:30 AM
    TimeSlot slot10(1130, 1230);  // 11:30 AM - 12:30 PM
    TimeSlot slot11(1330, 1430);  // 1:30 PM - 2:30 PM
    TimeSlot slot12(1430, 1530);  // 2:30 PM - 3:30 PM
    TimeSlot slot13(1530, 1630);  // 3:30 PM - 4:30 PM
    TimeSlot slot14(1630, 1730);  // 4:30 PM - 5:30 PM

    Scheduler::scheduleAppointmentstart(tempD[7], tempP[7], slot8);   // Doctor 7, Patient 7
    Scheduler::scheduleAppointmentstart(tempD[8], tempP[8], slot9);   // Doctor 8, Patient 8
    Scheduler::scheduleAppointmentstart(tempD[9], tempP[9], slot10);  // Doctor 9, Patient 9
    Scheduler::scheduleAppointmentstart(tempD[6], tempP[10], slot11); // Doctor 0, Patient 10
    Scheduler::scheduleAppointmentstart(tempD[1], tempP[11], slot12); // Doctor 1, Patient 11
    Scheduler::scheduleAppointmentstart(tempD[2], tempP[12], slot13); // Doctor 2, Patient 12
    Scheduler::scheduleAppointmentstart(tempD[3], tempP[13], slot14); // Doctor 3, Patient 13

    // Continue scheduling without overlaps
    TimeSlot slot15(1700, 1800);    // 5:00 PM - 6:00 PM
    Scheduler::scheduleAppointmentstart(tempD[4], tempP[14], slot15); // Doctor 4, Patient 14
    TimeSlot slot16(1800, 1900);    // 6:00 PM - 7:00 PM
    Scheduler::scheduleAppointmentstart(tempD[5], tempP[15], slot16); // Doctor 5, Patient 15

    
}