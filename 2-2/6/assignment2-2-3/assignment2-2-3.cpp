#include "CSVLoader.h"
#include <iostream>

int main()
{
    // 선언 및 파싱
    CSVLoader loader("CSVLoader_Data.csv");
    
    // 행과 열 출력
    int rows = loader.getRows(), cols = loader.getCols();
    std::cout << "[" << rows << "][" << cols << "]" << std::endl;

    // 데이터 출력
    float** data = loader.getData();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // 파일이나 데이터가 없을 경우
    if (!data)  std::cout << "File or data does not exist.\n";
    
    // 텍스트 파일 출력
    loader.print();
    
    // 종료
    return 0;
}