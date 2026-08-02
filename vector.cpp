#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums;

    for (int i = 1; i <= 5; i++) {
        nums.push_back(i);
    }
    
    std::cout << "Size: " << nums.size() << "\n";
    
    return 0;
}