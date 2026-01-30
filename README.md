# XOR Neural Network in C++

This project implements a small neural network in C++, from scratch. The network consists of 5 neurons (2 Input, 2 Hidden, 1 Output) and learns the **XOR gate logic** based on its truth table.

## Overview

### What is a Neural Network?
Abstractly, a neural network is a computational model inspired by the human brain. It is composed of three main layers:
1. **Input Layer**
2. **Hidden Layer**
3. **Output Layer**

At each neuron, mathematical operations occur as data is passed through the network. The final result returned by the output layer is a probability, a number representing how confident the model is in its prediction.

In this project, I explore the mathematics behind why neural networks can be so accurate.

## How It Works: The Math

### Weights and Biases
Each input value ($x$) is tied to a weight ($w$). The weight determines the influence a specific neuron has on the outcome.

The process begins with the linear input (often called the **logit**). This is calculated by taking the **dot product** (multiplying and summing) of the inputs and weights, and then adding a **bias** ($b$).
*   **Bias ($b$):** Allows us to shift or "nudge" the neuron's activation function in a specific direction, independent of the input.

We sum these operations and store the result in a variable, often denoted as $z$.

### Activation Function
The value $z$ is then passed through an activation function. In this model, we use the **Sigmoid** function.
*   **Purpose:** Activation functions introduce non-linearity, allowing the model to learn and represent complex patterns that a simple linear equation cannot.

For a deeper explanation of activation functions, check out this article:
[Activation Functions in Neural Networks (GeeksforGeeks)](https://www.geeksforgeeks.org/machine-learning/activation-functions-neural-networks/)

### The Forward Pass
1.  **Hidden Layer:** The inputs are processed by two neurons in the hidden layer using the weights, biases, and sigmoid activation described above.
2.  **Output Layer:** The single output neuron sums the activated outputs from the hidden layer (weighted and biased) and **applies the activation function again** to produce the final probability.

### Training: Loss and Backpropagation
To make the network learn, we need to measure its performance and adjust it accordingly.

1.  **Loss Function:** After a forward pass, we use a loss function to measure the error—how far the model's prediction was from the true label (the target).
2.  **Backpropagation:** We compute the **gradients** of the loss with respect to the weights and biases. This tells us the direction in which we need to adjust our parameters to reduce the error.
3.  **Gradient Descent:** Using the calculated gradients, we update the weights and biases to minimize the cost function.

### Conclusion
By repeating this process over many **epochs** (passes through the training data), the model iteratively improves its accuracy. In this specific implementation, I found that allowing the model more epochs significantly improved its performance on the XOR problem.

Thanks for reading! :)
