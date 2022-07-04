#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

int main(){
    std::vector<int> x = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> y = {1,2,3,4,5,6,7,8,9,10};

    int dataset_length = x.size();
    std::cout << dataset_length << std::endl;

    std::vector<double> error_vector;
    double index_error;

    double b0 = 10;
    double b1 = 10;
    double learning_rate = 0.0001;

    //Training Phase
    for(uint16_t i=0; i<20000; i++){
        uint16_t index = i % dataset_length;
        double p = b0 + b1*x[index];
        index_error = p - y[index];
        b0 = b0 - learning_rate*index_error;
        b1 = b1 - learning_rate*index_error*x[index];
        std::cout<<"i = " << i << " b0 = "<< b0 << " b1 = "<< b1 << " index_error = " << index_error << std::endl;
        error_vector.push_back(index_error);
    }
    // Goes to infitiy when squared is given. Why???

    //Select Optimal b0 and b1 values
    //sort(error_vector.begin(), error_vector.end(), custom_sort);
    std::cout<<"b0 = "<< b0 << " b1 = "<< b1 << " index_error = " << index_error << std::endl;

}

// When uint8_t used until 255, then it does not work. 
// After 256, the program decreases the index error, however the program crashes!