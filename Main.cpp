#include "requirements.hpp"

using namespace std;

template<typename datatype, int size>
void printArray(array<datatype, size> vec) {
  for (datatype i : vec) {
    cout << i << endl;
  }
}



int main(){ 
  
  array<int, 5>* dataList = new array<int, 5>();
  printArray<int, 5>(*dataList);

}
