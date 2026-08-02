#include <iostream>
#include <vector>

int main(){
    std::vector<int> nums;

    for (int i = 1; i <= 6; i++) {
        nums.push_back(i * 10);
    }

    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";

   
   
   
    return 0;
}