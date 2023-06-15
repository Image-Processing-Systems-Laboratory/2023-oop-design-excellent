#include <iostream>
using namespace std;
namespace oopstd {
    //memset ptr 포인터가 가리키는 메모리를 num 바이트만큼 value로 초기화
    void* memset(void* ptr, int value, size_t num) {
        //static cast로 void형 포인터를 unsigned char형 포인터로 형변환 (캐스팅)
        unsigned char* casting_ptr = static_cast<unsigned char*>(ptr);
        for (int i = 0; i < num; ++i) {
            //int형인 value를 char로 형변환해서 메모리에 저장
            casting_ptr[i] = value+'0';
        }
        //포인터 반환
        return ptr;
    }
    //memcpy source가 가리키는 메모리를 num바이트 만큼 destination으로 복사
    void* memcpy(void* destination, const void* source, size_t num) {
        //void형 포인터 destination을 unsigned char 포인터로 캐스팅
        unsigned char* casting_destination = static_cast<unsigned char*>(destination);
        //source 포인터를 unsigned char로 캐스팅
        const unsigned char* casting_src = static_cast<const unsigned char*>(source);
        //source에서 destination으로 num바이트 만큼 메모리 복사
        for (int i = 0; i < num; ++i) {
            casting_destination[i] = casting_src[i];
        }
        //복사된 메모리를 가르키는 포인터 destination반환
        return destination;
    }
    //strcmp 문자열 str1과 str2를 비교해서 같으면 0반환 str1의 길이가 str2보다 짧으면 음수 반환, 길면 양수 반환
    int strcmp(const char* str1, const char* str2) {
        //str1,str2가 가리키는 문자가 null문자가 아니면서 str1과 str2가 가르키는 문자가 같을 때 - 참
        while (*str1 != '\0' && *str2 != '\0' && (*str1 == *str2)) {
            ++str1;
            ++str2;
        }
        //str1과 str2의 문자가 다를 때 양수나 음수 반환
        //널문자까지 while문을 수행했다면 str1문자열과 str2문자열은 같으므로 0반환
        return *str1 - *str2;
    }

    //strncmp 문자열 str1과 str2의 num만큼 비교해서 같으면 0반환 다르면 첫 번째 문자의 아스키코드 값 차이 반환
    int strncmp(const char* str1, const char* str2, size_t num) {
        //str1,str2의 첫 번째 문자 부터 n-1번째 문자부터 비교
        for (int i = 0; i < num; ++i) {
            //문자가 다르면 첫 번째 문자의 아스키 코드값 차이 반환
            if (str1[i] != str2[i]) {
                return str1[i] - str2[i];
            }
            //str1이나 str2에서 널문자가 나올 때, str1 문자열 비교 끝
            if (str1[i] == '\0'||str2[i]=='\0') {
                return 0;
            }
        }
        //for문 루프가 끝났다면 str1과 str2가 일치하기 때문에 0반환
        return 0;
    }
    //strcpy source문자열을 destination문자열에 복사
    char* strcpy(char* destination, const char* source) {
        char* buffer_ptr = destination;
        //source에서 널문자가 나오기 전까지 while문 반복
        //source에서 한글자씩 읽어와서 buffer_ptr에 저장
        while (*source) {
            *buffer_ptr++ = *source++;
        }
        //문자열 끝에 널문자 추가
        *buffer_ptr = '\0';
        //복사된 문자열 가르키는 포인터 반환
        return destination;
    }
    //strncpy source문자열을 num 바이트 만큼 destionation에 복사
    char* strncpy(char* destination, const char* source, size_t num) {
        char* buff_ptr = destination;
        int i = 0;
        //source 문자열 복사
        while (i < num && *source) {
            *buff_ptr++ = *source++;
            ++i;
        }
        //복사하려는 문자열의 길이가 num보다 작을 때
        if (i < num) {
            *buff_ptr = '\0';
        }
        //복사된 문자열 가르키는 포인터 반환
        return destination;
    }
    //strlen str문자열의 길이를 반환
    size_t strlen(const char* str) {
        //size_t 부호없는 32비트 정수
        size_t len = 0;
        while (*str++) {
            ++len;
        }
        return len;
    }
    //atoi str문자열을 정수로 변환
    int atoi(const char* str) {
        int num = 0;
        int sign = 1; //부호 결정
        if (*str == '-') {
            sign = -1;
            ++str;
        }
        //문자열에서 숫자를 각자릿수 만큼 10을 곱해서 num에 더함
        while (*str >= '0' && *str <= '9') {
            num = num * 10 + (*str - '0');
            ++str;
        }
        return sign * num;
    }
    //atof 문자열 str을 double형으로 변환
    double atof(const char* str) {
        double num = 0.0;
        int sign = 1; //부호 결정
        if (*str == '-') {
            sign = -1;
            ++str;
        }
        //소수점 앞 정수 부분을 변환
        while (*str >= '0' && *str <= '9') {
            num = num * 10.0 + (*str - '0');
            ++str;
        }
        //소수부가 있을 때 소수부 변환
        if (*str == '.') {
            //실수부는 자릿수 증가할 때마다 10^-1을 곱한다
            double frac = 0.1;
            ++str;
            while (*str >= '0' && *str <= '9') {
                num += frac * (*str - '0');
                frac *= 0.1;
                ++str;
            }
        }
        //문자열에서 e 나 E가 나오면
        //aeb = a*10^(b)
        if (*str == 'e' || *str == 'E') {
            ++str;
            int exp = 0; 
            int exp_sign = 1;
            //부호 계산
            if (*str == '-') {
                exp_sign = -1;
                ++str;
            }
            else if (*str == '+') {
                ++str;
            }
            //지수 부분 계산
            while (*str >= '0' && *str <= '9') {
                exp = exp * 10 + (*str - '0');
                ++str;
            }

            num *= pow(10.0, exp_sign * exp);
        }

        return sign * num;
    }
}

int main()
{
    char arr1[] = "Hello World";
    char arr2[12] = { 0 };
    cout << arr1 << endl << arr2 << endl;
    oopstd::memset(arr1, 1, 3);
    cout << arr1 << endl;
    oopstd::memcpy(arr2,arr1,5);
    cout << arr2 << endl;
    cout<< oopstd::strcmp(arr1, arr2)<<endl;
    cout<<oopstd::strncmp(arr1, arr2, 5)<<endl;
    oopstd::strcpy(arr1, arr2);
    cout << arr1 << endl << arr2 << endl;
    oopstd::strncpy(arr1, "HELLO", 5);
    cout << arr1 << endl;
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    cout << len1 << endl << len2 << endl;
    char arr3[] = "2023";
    int arr3_atoi = oopstd::atoi(arr3);
    cout << arr3_atoi << " " << arr3_atoi + 1 << endl;
    char arr4[] = "20.23";
    double arr4_atof = oopstd::atof(arr4);
    cout << arr4_atof << " "<<arr4_atof + 0.11 << endl;
    char arr5[] = "164e-3";
    cout << arr5<< " "<< atof(arr5) << endl;
    return 0;
}
