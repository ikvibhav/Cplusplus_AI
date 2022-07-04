#include<iostream>
#include<vector>

int main(){
    std::vector<int> x = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> y = {1,2,3,4,5,6,7,8,9,10};
    int dataset_length = x.size();

    std::vector<double> error_vector;
    double index_error;

    //Hyperparamters
    double b0 = 10;
    double b1 = 10;
    double learning_rate = 0.0001;
    int epochs = 500;

    //Training Phase
    for(uint32_t i=0; i<epochs; i++){

        for(uint32_t index=0; index<dataset_length; index++){
            double p = b0 + b1*x[index];
            index_error = p - y[index];
            b0 = b0 - learning_rate*index_error;
            b1 = b1 - learning_rate*index_error*x[index];
            error_vector.push_back(index_error);
        }

        std::cout << "Epoch " << +i << " - b0 = "<< b0 << " b1 = "<< b1 << " index_error = " << index_error << std::endl;
    
    }

    //Prediction Phase

}