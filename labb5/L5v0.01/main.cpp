// Laboration5, DT079G
// Amarildo Rajta
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Car.h"

struct MyBinOp {
    double operator()(double accum, const Car &b) {
        return accum + b.getSpeed();
    }
};

struct MyUnOp {
    double operator()(const Car &a) {
        return a.getSpeed();
    }
};

/*Returns difference of in*/
struct MyFunc {
    double substrVal;
    MyFunc(double subVal): substrVal(subVal){}
    double operator()(const double &a) const {
        return a-substrVal;
    }
};


int main() {
    Car arr1[]={
            Car("Koenigsegg Agera RS", 447.2),
            Car("Porsche 959", 319),
            Car("Porsche 959", 339),
            Car("Aston Martin DB4 GT", 245)};
    std::vector<Car>v1 = {
            Car("Lamborghini Miura P400S", 288.6),
            Car("Bugatti Veyron EB 16.4", 408.5)
    };
    std::copy(std::begin(arr1), std::end(arr1), std::back_inserter(v1));


        //Test 1
    std::cout << "\n Test 1, printing the vector elements with algorithm for_each\n";
    std::for_each(v1.begin(), v1.end(), MyPrint());

        //Test 2
    std::cout << "\n Test 2, algorithm find_if\n";
    auto it = std::find_if(v1.begin(), v1.end(), HigherSpeedThan(440));
    MyPrint print;
    print(*it);

        //Test 3
    std::cout << "\n Test 3, algorithm adjacent_find\n";
    auto match = std::adjacent_find(v1.begin(), v1.end());
    print(*match);


        //Test 4
    //Checking the equality of the contents of the original array and the vector
    std::cout << "\n Test 4, algorithm equal\n";
    if(std::equal(v1.begin(), v1.end(), arr1)) {
        std::cout << "Equal content\n";
    }
    else {
        std::cout << "Unequal content\n";
    }

        //Test 5
    //Establishing location of the arbitrary subsequence in the vector range
    std::cout << "\n Test 5, algorithm search\n";
    std::vector<Car> subsequence;
    std::copy(arr1+1, arr1+4, std::back_inserter(subsequence));

    auto matchPosFirst = std::search(v1.begin(), v1.end(),subsequence.begin(), subsequence.end());
    auto matchPosLast = std::search(v1.begin(), v1.end(),subsequence.rend(), subsequence.rbegin())-1;
    if (matchPosFirst==v1.end()){
        std::cout << "No match\n";
    }
    else {
        std::cout << "Subsequence found from position " << std::distance(v1.begin(), matchPosFirst)
                  << " to position " << std::distance(v1.begin(), matchPosLast) << "\n";
        std::for_each(subsequence.begin(), subsequence.end(), MyPrint());
    }

        //Test 6
    //Calculating the average (mean) speed
    std::cout << "\n Test 6, algorithm accumulate\n";
    auto mean= std::accumulate(v1.begin(), v1.end(), 0.0, MyBinOp()) / v1.size();
    std::cout << "Mean speed: " << mean << "km/h\n";


        //Test 7
    //Creating a new vector v2 of double values with the same size as the original one,
    // and filling in it with the parameter values from the first vector
    std::cout << "\n Test 7, algorithm transform part 1\n";
    std::vector<double>v2(v1.size());
    std::transform(v1.begin(), v1.end(), v2.begin(), MyUnOp());
    for (auto e: v2){
        std::cout << e << ", ";
    }
    std::cout << std::endl;

        //Test 8
    //Replacing all old values xi of the vector v2 with the new ones yi = xi - mean (mean from Task 6)
    std::cout << "\n Test 8, algorithm transform part 2\n";
    std::transform(v2.begin(), v2.end(), v2.begin(), MyFunc(mean));
    for (auto e: v2){
        std::cout << e << ", ";
    }
    std::cout << std::endl;

        //Test 9
    //Sorting the contents of v2 in ascending order
    std::cout << "\n Test 9, algorithm sort\n";
    std::sort(v2.begin(),v2.end());
    for (auto e: v2){
        std::cout << e << ", ";
    }
    std::cout << std::endl;

    return 0;
}
