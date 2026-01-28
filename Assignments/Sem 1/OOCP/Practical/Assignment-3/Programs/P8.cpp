// 8) Define a class Faculty. It contains the following attributes:
// (a) Name of the faculty
// (b) Qualification of the faculty
// (c) Subjects the faculty can teach
// Inherit the Faculty class into a regular faculty, who
// (a) is available full time (no consulting time is specified)
// (b) teaches at least three subjects
// (c) is part of the institute alone
// Inherit the Faculty class into visiting faculty, who
// (a) is available only on two to three days (consulting time is also to be
// specified)
// (b) teaches a single subject
// (c) is part of some other institute
// Provide virtual functions for reading and writing class objects of the classes
// given above.

#include <iostream>
#include <string>
using namespace std;

// Base class
class Faculty
{
protected:
    string name;
    string qualification;
    string subjects[10]; // Fixed-size array for subjects
    int subjectCount;

public:
    Faculty()
    {
        subjectCount = 0;
    }

    // Virtual functions
    virtual void read()
    {
        cout << "Enter Faculty Name: ";
        getline(cin, name);
        cout << "Enter Qualification: ";
        getline(cin, qualification);

        cout << "Enter number of subjects faculty can teach: ";
        cin >> subjectCount;
        cin.ignore();

        for (int i = 0; i < subjectCount; i++)
        {
            cout << "Enter subject " << i + 1 << ": ";
            getline(cin, subjects[i]);
        }
    }

    virtual void display()
    {
        cout << "\nFaculty Name: " << name << endl;
        cout << "Qualification: " << qualification << endl;
        cout << "Subjects: ";
        for (int i = 0; i < subjectCount; i++)
        {
            cout << subjects[i];
            if (i != subjectCount - 1)
                cout << ", ";
        }
        cout << endl;
    }

    virtual ~Faculty() {}
};

// Derived class for Regular Faculty
class RegularFaculty : public Faculty
{
public:
    void read() override
    {
        cout << "\n--- Enter Regular Faculty Details ---\n";
        Faculty::read();

        if (subjectCount < 3)
        {
            cout << "Regular faculty must teach at least 3 subjects.\n";
            while (subjectCount < 3)
            {
                cout << "Enter additional subject " << subjectCount + 1 << ": ";
                getline(cin, subjects[subjectCount]);
                subjectCount++;
            }
        }
    }

    void display() override
    {
        cout << "\n--- Regular Faculty Details ---";
        Faculty::display();
        cout << "Availability: Full Time\n";
        cout << "Institute Type: Internal (Part of the institute alone)\n";
    }
};

// Derived class for Visiting Faculty
class VisitingFaculty : public Faculty
{
    int consultingDays;
    string consultingTime;
    string otherInstitute;

public:
    void read() override
    {
        cout << "\n--- Enter Visiting Faculty Details ---\n";
        cout << "Enter Faculty Name: ";
        getline(cin, name);
        cout << "Enter Qualification: ";
        getline(cin, qualification);

        subjectCount = 1;
        cout << "Enter the subject taught: ";
        getline(cin, subjects[0]);

        cout << "Enter number of consulting days (2 or 3): ";
        cin >> consultingDays;
        cin.ignore();

        cout << "Enter consulting time: ";
        getline(cin, consultingTime);

        cout << "Enter other institute name: ";
        getline(cin, otherInstitute);
    }

    void display() override
    {
        cout << "\n--- Visiting Faculty Details ---";
        Faculty::display();
        cout << "Consulting Days: " << consultingDays << endl;
        cout << "Consulting Time: " << consultingTime << endl;
        cout << "Other Institute: " << otherInstitute << endl;
    }
};

// Main function
int main()
{
    Faculty *f1, *f2;

    f1 = new RegularFaculty();
    f2 = new VisitingFaculty();

    cout << "Enter details for Regular Faculty:\n";
    f1->read();

    cout << "\nEnter details for Visiting Faculty:\n";
    f2->read();

    cout << "\n=============================\n";
    cout << "Displaying Faculty Details:\n";
    cout << "=============================\n";

    f1->display();
    f2->display();

    delete f1;
    delete f2;

    return 0;
}

// OUTPUT

// Enter details for Regular Faculty:

// --- Enter Regular Faculty Details ---
// Enter Faculty Name: DP SIR
// Enter Qualification: B.C.A.
// Enter number of subjects faculty can teach: 2
// Enter subject 1: DBMS
// Enter subject 2: OOCP
// Regular faculty must teach at least 3 subjects.
// Enter additional subject 3: DBMS PART 2

// Enter details for Visiting Faculty:

// --- Enter Visiting Faculty Details ---
// Enter Faculty Name: HARDIK PANDYA
// Enter Qualification: 12TH PASS
// Enter the subject taught: P.T.
// Enter number of consulting days (2 or 3): 3
// Enter consulting time: 3 HOURS
// Enter other institute name: M.S. DHONI ACEDAMI

// =============================
// Displaying Faculty Details:
// =============================

// --- Regular Faculty Details ---
// Faculty Name: DP SIR
// Qualification: B.C.A.
// Subjects: DBMS, OOCP, DBMS PART 2
// Availability: Full Time
// Institute Type: Internal (Part of the institute alone)

// --- Visiting Faculty Details ---
// Faculty Name: HARDIK PANDYA
// Qualification: 12TH PASS
// Subjects: P.T.
// Consulting Days: 3
// Consulting Time: 3 HOURS
// Other Institute: M.S. DHONI ACEDAMI