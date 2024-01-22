#include<bits/stdc++.h>
using namespace std;


class SGPACalculator {
private:
    int totalSubjects;
    double totalCredits;          //double-precision floating-point variable 
    double  totalGradePoints;     //double-precision floating-point variable 

public:
    SGPACalculator() {
        totalSubjects = 0;
        totalCredits = 0.0;
        totalGradePoints = 0.0;
    }

//Function to take the inputs of midsem internals and endsem
    void addSubject() {
        double midSem, internal, endSem;

        cout << "Enter Mid Semester Marks (out of 25): ";
        cin >> midSem;

        cout << "Enter Internal Marks (out of 15): ";
        cin >> internal;

        cout << "Enter End Semester Marks (out of 60): ";
        cin >> endSem;


        // Calculate total marks for one subject
        double totalMarks = midSem + internal + endSem;


        // Assign grades based on total marks
        char grade;
        if (totalMarks >= 90) {
            grade = 'O';
        } else if (totalMarks >= 80) {
            grade = 'A';
        } else if (totalMarks >= 70) {
            grade = 'B';
        } else if (totalMarks >= 60) {
            grade = 'C';
        } else if (totalMarks >= 50) {
            grade = 'D';
        } else if (totalMarks >= 40) {
            grade = 'P';
        } else {
            grade = 'F';
        }

        // Assign grade points based on grades
        int gradePoints;
        switch (grade) {
            case 'O':
                gradePoints = 10;
                break;
            case 'A':
                gradePoints = 9;
                break;
            case 'B':
                gradePoints = 8;
                break;
            case 'C':
                gradePoints = 7;
                break;
            case 'D':
                gradePoints = 6;
                break;
            case 'P':
                gradePoints = 5;
                break;
            case 'F':
                gradePoints = 4;
                break;
            default:
                gradePoints = 0; 
        }

        // Update the total
        totalSubjects++;
        totalCredits += 4.0;  // I am Assuming 4 credit points for each subject
        totalGradePoints += (gradePoints * 4.0);
    }

    double calculateSGPA() const {
        if (totalSubjects == 0) {
            cout << "No subjects entered." << endl;
            return 0.0;
        }

        return totalGradePoints / totalCredits;
    }
};

int main() {

    cout<<"==============================================================================================================="<<endl;
    cout<<"                                          SGPA CALCULATOR                                           "<<endl;
    cout<<"==============================================================================================================="<<endl;
    SGPACalculator sgpaCalculator;

    const int numSubjects = 5;  // Assuming 5 subjects
    for (int i = 0; i < numSubjects; ++i) {
        cout << "\nEnter details for Subject " << i + 1 << ":" << endl;
        sgpaCalculator.addSubject();
    }

    double sgpa = sgpaCalculator.calculateSGPA();

    
        cout << fixed << setprecision(2);  //fixed:  floating-point values will be displayed in fixed-point notation 
                                           //(i.e., with a fixed number of decimal places), regardless of the default behavior or the type of the value.
                                          // setprecision:sets the precision (number of decimal places) to 2.
        cout << "\nYour SGPA is: " << sgpa<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
    

    return 0;
}
