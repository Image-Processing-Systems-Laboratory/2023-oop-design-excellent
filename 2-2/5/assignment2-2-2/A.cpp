#include "A.h"



 A:: A(double input)  {

	 member = input;//멤버 변수에 매개변수 값 대입
	cout << "Class A is created  with " << member<<endl;//출력
	
}





A:: ~A() {

	cout << "Class A is destroyed  with " << member<<endl;//출력


}
