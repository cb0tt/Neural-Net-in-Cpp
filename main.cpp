#include <iostream>
#include "nn.h"
#include "math_utils.h"



int main()
{
    std::cout << "Training..." << std::endl;
    nn neural_net;
    neural_net.train(100000, 0.1);

    neural_net.forward_pass(0, 0);
    std::cout << "0,0 -> " << neural_net.get_guess() << std::endl;

    neural_net.forward_pass(0, 1);
    std::cout << "0,1 -> " << neural_net.get_guess() << std::endl;

    neural_net.forward_pass(1, 0);
    std::cout << "1,0 -> " << neural_net.get_guess() << std::endl;

    neural_net.forward_pass(1, 1);
    std::cout << "1,1 -> " << neural_net.get_guess() << std::endl;

    return 0;
}
