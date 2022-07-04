x = [1,2,3,4,5,6,7,8,9,10]
y = [1,2,3,4,5,6,7,8,9,10]
dataset_length = len(x)

b0 = 2
b1 = 2
learning_rate = 0.0001
epochs = 50000

for i in range(epochs):
    for index in range(dataset_length):
        p = b0 + b1*x[index]
        index_error = p - y[index]
        b0 = b0 - learning_rate*index_error
        b1 = b1 - learning_rate*index_error*x[index]

print(f'Training Phase Complete. b0 = {b0} b1 = {b1}')
input_pred_value = input('Prediction Phase Begin. Enter Input Integer Value ')
print(f'Predicted Output for {input_pred_value} is {b0 + b1*int(input_pred_value)}')