#include"Person.h"

int main(void)
{
	char pname[] = "Sim Dong-Gyu";
	char pnum[] = "123456789";
	char pmajor[] = "EE";

	Professor sim;
	sim.setage(20);
	sim.setname(pname);
	sim.setpnum(pnum);
	sim.setmajor(pmajor);

	char sname[] = "Choi Min-Seok";
	char snum[] = "2020202090";
	char smajor[] = "CIE";

	Student choi;
	choi.setage(19);
	choi.setname(sname);
	choi.setsnum(snum);
	choi.setmajor(smajor);
	choi.setyear(2);

	sim.Say();
	cout << endl;
	choi.Say();

	return 0;
}