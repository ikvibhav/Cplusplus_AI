#include<iostream>
#include<vector>
#include<chrono>

int main(){
    std::vector<int> x = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> y = {1,2,3,4,5,6,7,8,9,10};
    int dataset_length = x.size();

    //std::vector<double> error_vector;
    double index_error;
    int input_pred_value;

    //Hyperparamters
    double b0 = 2;
    double b1 = 2;
    double learning_rate = 0.0001;
    int epochs = 50000;

    //Training Phase
    auto start = std::chrono::high_resolution_clock::now();
    for(uint16_t i=0; i<epochs; i++){

        for(uint8_t index=0; index<dataset_length; index++){
            double p = b0 + b1*x[index];
            index_error = p - y[index];
            b0 = b0 - learning_rate*index_error;
            b1 = b1 - learning_rate*index_error*x[index];
            //error_vector.push_back(index_error);
        }
        //std::cout << "Epoch " << +i << " - b0 = "<< b0 << " b1 = "<< b1 << " index_error = " << index_error << std::endl;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    std::cout << "Training Phase Completed in " << duration.count() << " milliseconds. b0 = " << b0 << " b1 = " << b1 << std::endl;

    //Prediction Phase
//     std::cout << "Prediction Phase Begin. Enter Input Integer Value" << std::endl;
//     std::cin >> input_pred_value;
//     std::cout << "Predicted Output for " << input_pred_value << " is " << b0+b1*input_pred_value << std::endl;    
// 
}