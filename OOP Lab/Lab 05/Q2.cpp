#include <iostream>
#include <string>

using namespace std;

class LoanHelper {
private:
const float interestrate;
float loanAmount;
int Months;

public:
LoanHelper(const float interest, float loan,int months) : interestrate(interest), loanAmount(loan), Months(months) {
    cout << "TESTING: " << interestrate << endl;
    if(interestrate < 0 || interestrate > 0.5) {
        cout<<"Interest rate must be between 0 and 0.5%"<< endl;
    }
}
void calculateLoan() {
loanAmount=(loanAmount/Months)*interestrate/100;
cout<<"You have to pay "<< loanAmount << " every month for "<< Months << " months to repay your loan"<<endl;
}

void setLoan(float loan) {
    loanAmount=loan;
}
void setMonths(int m) {
    Months=m;
}
float getInterestRate() {
    return interestrate;
}
int getMonths() {
    return Months;
}
float getLoanAmount() {
    return loanAmount;
}
};

int main () {
float l;
float interestRate;
int months;
    cout<<"Enter Loan Amount: "<<endl;
    cin>>l;
    cout<<"Enter Interest Rate (between 0% and 0.5%): "<<endl;
    cin>>interestRate;
    cout<<"Enter Months: "<<endl;
    cin>>months;
    LoanHelper l1(interestRate, l, months);
    LoanHelper l2(0.24, 7000, 29);
    LoanHelper l3(0.74, 8000, 32);

    l1.calculateLoan();

    cout<<"User 1 (User defined): "<<endl;
    cout<<"Interest Rate: "<<l1.getInterestRate()<<endl;
    cout<<"Loan Amount: "<< l1.getLoanAmount() <<endl;
    cout<<"Months for repayment: "<< l1.getMonths()<<endl;

    l2.calculateLoan();
    cout<<"User 2 (hardcoded): "<<endl;
    cout<<"Interest Rate: "<<l2.getInterestRate()<<endl;
    cout<<"Loan Amount: "<< l2.getLoanAmount()<<endl;
    cout<<"Months for repayment: "<< l2.getMonths()<<endl;

    l3.calculateLoan();
    cout<<"User 3 (hardcoded): "<<endl;
    cout<<"Interest Rate: "<<l3.getInterestRate()<<endl;
    cout<<"Loan Amount: "<< l3.getLoanAmount()<<endl;
    cout<<"Months for repayment: "<< l3.getMonths()<<endl;


}
