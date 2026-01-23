#ifndef NN_H
#define NN_H

class nn
{
    public:
        nn();
        void forward_pass(double x1, double x2);
        void train(int epochs, double learn_rate);
        double loss(double guess, double target);
        double get_guess() { return guess; } //needed bc forwardp is void



    private:
        double W1[2][2]; //hiddens, inputs
        double b1[2]; // 2 neurons, 2 biases
        double W2[2]; // hidden, output
        double b2; //bias for output (one neuron)
        double active_one;
        double active_two;
        double guess;


};

#endif // NN_H
