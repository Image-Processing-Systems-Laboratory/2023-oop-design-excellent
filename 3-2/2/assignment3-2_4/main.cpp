#include "Polynomial.h"
#include <iostream>

using namespace std;

int main() {
	char cmd;
	Polynomial p1, p2;		// default: 0, 0
	do {
		cin >> cmd;
		if (cmd == '1') {		// p1에 추가
			int coeff, exp;
			cin >> coeff >> exp;
			Term* temp = new Term;
			temp->SetCoefficient(coeff);
			temp->SetExponent(exp);
			p1.Insert(temp);
			cout << "p1 = ";
			p1.PrintList();
		}
		else if (cmd == '2') {	// p2에 추가
			int coeff, exp;
			cin >> coeff >> exp;
			Term* temp = new Term;
			temp->SetCoefficient(coeff);
			temp->SetExponent(exp);
			p2.Insert(temp);
			cout << "p2 = ";
			p2.PrintList();
		}
		else if (cmd == 'a') {	// p1.Add
			cout << "p1 += p2: " << endl;
			p1.Add(p2);
			cout << "p1 = ";
			p1.PrintList();
		}
		else if (cmd == 's') {	// p1.Sub
			cout << "p1 -= p2: " << endl;
			p1.Sub(p2);
			cout << "p1 = ";
			p1.PrintList();
		}

	} while (cmd != 'b');		// break
}