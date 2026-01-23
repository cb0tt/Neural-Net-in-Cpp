#include "nn.h"
#include "math_utils.h"
#include <iostream>
#include <random>
 nn::nn()
 {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    for (int i = 0; i < 2; i++) {
        b1[i] = dis(gen);
        W2[i] = dis(gen);
        for (int j = 0; j < 2; j++) {
            W1[i][j] = dis(gen);
        }
    }
    b2 = dis(gen);
 }


 void nn::forward_pass(double x1, double x2){
    double z1 = W1[0][0] * x1 + W1[0][1] * x2 + b1[0];
    active_one = sigmoid(z1);

    double z2 = W1[1][0] * x1 + W1[1][1] * x2 + b1[1]; // weight from input (x1) * hn 1 is (W1[0][0])
    active_two = sigmoid(z2);

    double out = W2[0] * active_one + W2[1] * active_two + b2;
    guess = sigmoid(out);
 }

 double nn::loss(double guess, double target)
 {
    double err = guess - target;
    return 0.5 * err * err;
 }


 void nn::train(int epochs, double learn_rate) {
    double train_data[4][3] = {{0,0,0}, {0,1,1}, {1,0,1}, {1,1,0}};

    for (int i = 0; i < epochs; i++) {
        double total_loss = 0;
        for (int j = 0; j < 4; j++) {
            double x1 = train_data[j][0];
            double x2 = train_data[j][1];
            double target = train_data[j][2];
            forward_pass(x1, x2);
            total_loss += loss(guess, target);
            double out_delta = (guess - target) * guess * (1 - guess);
            double hidden_one = (out_delta * W2[0]) * active_one * (1 - active_one);
            double hidden_two = (out_delta * W2[1]) * active_two * (1 - active_two);
            W1[0][0] = W1[0][0] - (learn_rate * hidden_one * x1);
            W1[0][1] = W1[0][1] - (learn_rate * hidden_one * x2);
            W1[1][0] = W1[1][0] - (learn_rate * hidden_two * x1);
            W1[1][1] = W1[1][1] - (learn_rate * hidden_two * x2);
            W2[0] = W2[0] - (learn_rate * out_delta * active_one);
            W2[1] = W2[1] - (learn_rate * out_delta * active_two);
            b1[0] = b1[0] - (learn_rate * hidden_one);
            b1[1] = b1[1] - (learn_rate * hidden_two);
            b2 = b2 - (learn_rate * out_delta);
        }
        if (i % 10000 == 0) {
            std::cout << "Epoch " << i << " Loss: " << total_loss << std::endl;
        }
    }
 }
