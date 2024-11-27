# MP2
This is a project created by both Neil Harry So and Aaron Ace Toledo

# Specifications
Implement a program that computes for the accelerations of multiple cars in a Y by 3 matrix. Where Y is the number of cars. All inputs are in single floating point.

The output acceleration for each will be converted into integers

Input: Matrix Rows, single float matrix values

Ouput: Integer Acceleration Values (m/s^2)

# Analysis
The performance of the accelerationasm function, which computes the acceleration of vehicles based on their initial and final velocities and time, was analyzed by varying the number of input rows (cars). The results indicate the function's high efficiency and scalability. Below is the detailed analysis:
Average execution times based on number of rows:

10 rows = 0.00000000s

100 rows = 0.00000000s

1000 rows = 0.00000000s

10000 rows = 0.00003333s

For small to medium-sized datasets (up to 1000 rows), the execution time is essentially negligible, making the program highly efficient.
For large datasets (up to 10,000 rows), the performance is still excellent, with only a slight increase in execution time
The linear relationship between the number of rows and execution time demonstrates excellent scalability for larger datasets.

## Screenshot
![Alt text](./Result.png?raw=true "10 row output")
