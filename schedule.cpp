// Scheduler class to manage doctor-patient appointments
class Scheduler {
public:
//&& doctor.isFree(slot.startTime, slot.endTime)
    static void scheduleAppointment(Doctor& doctor, Patient& patient, TimeSlot slot) {
        // Check if both doctor and patient are available at the specified time slot
        if (!patient.hasAppointment() && doctor.isFree(slot.startTime, slot.endTime)) {
            doctor.addAvailability(slot);    // Block time slot in doctor's schedule
            patient.scheduleAppointment(slot); // Schedule appointment for patient
            patient.assignDoctor(doctor); // Assign the doctor to the patient
            doctor.addPatient(patient); // Add patient to doctor's care
            cout << "Appointment scheduled successfully!" << endl;
        } else {
            cout << "Appointment could not be scheduled. \nDoctor or patient is not available." << endl;
        }
    }
    //For the database
    static void scheduleAppointmentstart(Doctor& doctor, Patient& patient, const TimeSlot slot) {
        if (!patient.hasAppointment() && doctor.isFree(slot.startTime, slot.endTime)) {
            doctor.addAvailability(slot);    
            patient.scheduleAppointment(slot);
            patient.assignDoctor(doctor); 
            doctor.addPatient(patient); 
           
        } else {
           cout<<"no";
        }
    }
    static void cancelAppointment(Doctor& doctor, Patient& patient, TimeSlot slot) {
        // Remove the time slot from the doctor's schedule and undo appointment-related changes
        doctor.removeAvailability(slot); // Remove time slot from doctor's schedule
        patient.cancelAppointment(); // Cancel appointment for patient
        patient.removeD(); // Release the assigned doctor from the patient
        doctor.removePatient(&patient); // Remove patient from doctor's care
        std::cout << "Appointment canceled successfully!" << std::endl;
    }
    //For delete without notice
    static void cancelAppointmentDel(Doctor& doctor, Patient& patient, TimeSlot slot) {
        doctor.removeAvailability(slot); 
        patient.cancelAppointment();
        patient.removeD(); 
        doctor.removePatient(&patient); 
    }
};

