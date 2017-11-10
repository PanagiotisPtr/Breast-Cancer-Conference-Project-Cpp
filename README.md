# Augmented Adaline Model

### What is this project all about
This is a simple project that my team made to present at the Student Computer Conference at NOESIS, thessaloniki, Greece. This project is an implementation of the Adaline model in C++ but with a twist! Instead of using a linear activation function we are using the Hyperbolic tangent to show that in doing so the model converges faster. Not only that but also the derivative of the hyperbolic tangent is replaced by the equation 1 - x^2 to enhance not only computation speed but also performance since it seems like the model converges in much less epochs.

### The Code
The code is all written in C++. The folder named source contains our model while the folder named original contains the classic Adaline model. There one more fodler named Paper which contains the paper pdf of the project(It is also written in greek).

To compile the project you will need to open the terminal/command Line and go into the source folder. Then you can either run the demo.exe or compile the files with:

```cpp
  g++ Adaline.h datasets.h MachineLearning.cpp -o (The name of the excecutable)
```

### Results
Our results were slightly above average at with an average accuracy of 95%.

Odyssey Sapoznikov & Panagiotis Petridis, High School Students,
Greece
