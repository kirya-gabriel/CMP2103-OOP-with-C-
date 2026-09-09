// The income tax rate for individuals in business depends on the income bracket in which the individual falls.
// Resident individuals enjoy a tax free annual income threshold of UGX. 2,820,000 per annum. The
// balance is taxed at 10%, 20% or 30% depending on the income bracket. Individuals who earn
// above UGX 120,000,000 pa pay an additional 10% on the income above 120m.
// +----------------------+------------------------------------------+------------------------------------------+
// | CHARGEABLE INCOME, CY| RESIDENTS                                | NON-RESIDENTS                             |
// | (UGX Annual)         | RATE OF TAX                              | RATE OF TAX                               |
// +----------------------+------------------------------------------+------------------------------------------+
// | 0 to 2,820,000       | Nil                                      | CY x 10%                                  |
// | 2,820,000 to         | (CY - 2,820,000) x 10%                   | CY x 10%                                  |
// | 4,020,000            |                                          |                                           |
// | 4,020,000 to         | (CY - 4,020,000) x 20% + 120,000         | (CY - 4,020,000) x 20% + 402,000          |
// | 4,920,000            |                                          |                                           |
// | 4,920,000 to         | (CY - 4,920,000) x 30% + 300,000         | (CY - 4,920,000) x 30% + 582,000          |
// | 120,000,000          |                                          |                                           |
// | Above 120,000,000    | [(CY - 4,920,000) x 30% + 300,000]       | [(CY - 4,920,000) x 30% + 582,000]        |
// |                      | + [(CY - 120,000,000) x 10%]             | + [(CY - 120,000,000) x 10%]              |
// +----------------------+------------------------------------------+------------------------------------------+

// You are to write a program to compute personal income tax. Your program should prompt
// the user to enter the residence status and taxable income and then compute the tax. Enter 0 for
// resident and 1 for non-resident.

// Output
// (0-Resident, 1-Non-resident)
// Enter the residence status: 0
// Enter the taxable income: 4,000,000
// Tax is 118000.

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

static double parse_amount(const string &s)
{
    string t;
    for(char c:s)
    if(isdigit((unsigned char)c) || c == '.' || c == '-' )
    t.push_back(c);
    if(t.empty())
    return 0.0;
    return stod(t);

}
long long compute_tax(bool resident, double income)
{
    const double b_1 = 2820000.0;
    const double b_2 = 4020000.0;
    const double b_3 = 4920000.0;
    const double top = 120000000.0;

    double tax = 0.0;

    if(resident)
    {
        if(income <= b_1)
        {
            tax = 0.0;
        }
        else if (income <= b_2)
        {
            tax = (income - b_1) * 0.10;
        }
        else if(income <= b_3)
        {
            tax = (income - b_2) * 0.20 + 120000.0;
        }
        else if(income <= top)
        {
            tax = (income - b_3) * 0.30 + 300000.0;
        }
        else 
        {
            tax = (income - b_3) * 0.30 + 300000.0 + (income - top) * 0.10;  
        }
    }
        else
        {
            if(income <= b_2){
                tax = income * 0.10;
            }
            else if(income <= b_3)
            {
                tax = (income - b_2) * 0.20 + 402000.0;
            }
            else if(income <= top)
            {
                tax = (income - b_3) * 0.30 + 582000.0;
            }
            else
            {
                tax = (income - b_3) * 0.30 + 582000.0 + (income - top) * 0.10;
            }
        }
    return (long long)llround(tax);
    }


int main()
{
    cout << "(0-Resident, 1-Non-resident)" << endl;
    cout << "Enter the residence status: ";
    int status;
    if(!(cin >> status))
    return 0;

    cout << "Enter the taxable income:";
    string income_str;
    if(!(cin >> income_str))
    return 0;

    double income = parse_amount(income_str);
    long long tax = compute_tax(status == 0, income);

    cout << "Tax is" << tax << "." << endl;
    return 0;
}