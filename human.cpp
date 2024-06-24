class Human
{
private:
    string fName, lName, mName, address;
    int age, day, month, year, ftH, inH, wght;
    long phone;
    bool sex, life;

public:
    // Constructor to initialize variables
    Human(string firstName, string lastName, string middleName,
          string addr, long phoneNumber, int personAge,
          int birthDay, int birthMonth, int birthYear,
          int feetHeight, int inchesHeight, int weight,
          bool gender, bool alive)
        : fName(firstName), lName(lastName), mName(middleName),
          address(addr), phone(phoneNumber), age(personAge),
          day(birthDay), month(birthMonth), year(birthYear),
          ftH(feetHeight), inH(inchesHeight), wght(weight),
          sex(gender), life(alive)
    {
        // Constructor body
    }
    void setLife(bool lf)
    {
        life = lf;
    }
    void setFirstNam(const string& newFirstName) {
        fName = newFirstName;
    }

    void setLastNam(const string& newLastName) {
        lName = newLastName;
    }

    void setMiddleNam(const string& newMiddleName) {
        mName = newMiddleName;
    }

    void setAddres(const string& newAddress) {
        address = newAddress;
    }

    void setAg(int newAge) {
        age = newAge;
    }

    void setDa(int newDay){
        day = newDay;

    }
    void setMont(int newMonth) {
        month = newMonth;    }
    void setYea( int newYear) {
  
        year = newYear;
    }

    void setHeightFee(int newFtHeight) {
        ftH = newFtHeight;
    }
    void setHeightInche(int newInHeight) {
        inH = newInHeight;
    }

    void setWeigh(int newWeight) {
        wght = newWeight;
    }

    void setPhon(long newPhone) {
        phone = newPhone;
    }

    void setSe(bool newSex) {
        sex = newSex;
    }

    // Getter functions for accessing private member variables
    string getFirstName() const { return fName; }
    string getLastName() const { return lName; }
    string getMiddleName() const { return mName; }
    string getAddress() const { return address; }
    long getPhoneNumber() const { return phone; }
    int getAge() const { return age; }
    int getDayOfBirth() const { return day; }
    int getMonthOfBirth() const { return month; }
    int getYearOfBirth() const { return year; }
    string getBirthday() const
    {
        const string months[13] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
        string mnth = months[getMonthOfBirth()-1];
        string retrn = mnth +" "+ to_string(getDayOfBirth())+", "+to_string(getYearOfBirth());
        return retrn;
    }
    int getHeightFeet() const { return ftH; }
    int getHeightInches() const { return inH; }
    int getWeight() const { return wght; }
    bool getSex() const { return sex; }
    bool isAlive() const { return life; }
};