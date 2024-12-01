# LBYARCH-Project
- Buencamino, Prince Bendrik C.
- Ruiz, Chester Bryan C.

Short Demo Video (DLSU Email): https://drive.google.com/file/d/1sQzAPKQiTc5H4MvHj4e6Jmok3wRGxdfW/view?usp=sharing

The program converts a grayscale image representation from int-based to float-based using C and x86 Assembly language. When running the program, the user is prompted with the option of either inputting their own image sizes and values, or randomizing the inputs for either a 10x10, 100x100, or 1000x1000 image.

![image](https://github.com/user-attachments/assets/c745ee77-a0fc-4474-a658-92cd541ebe28)

The outputs of C and Assembly are checked for correctness by the following code:

![image](https://github.com/user-attachments/assets/07240fb4-97fe-4347-bf1f-fe79262b0367)


## I. Execution Time and Short Analysis of the Performance
- At every run, the functions for converting int to float for C and Assembly are looped 30 times, the run times for these are tallied up and the averages are calculated. The following are the average run times for C and Assembly when given: A. a 10x10 input image size, B. a 100x100 input image size, and C. a 1000x1000 input image size.

### A. 10x10 input image

Time Taken:

![image](https://github.com/user-attachments/assets/20630bd6-40a9-45b1-b15e-cb01f1ec2ece)

### B. 100x100 input image

Time Taken:

![image](https://github.com/user-attachments/assets/9564caeb-0eb0-473c-88f4-8baa921ab1eb)

### C. 1000x1000 input image

Time Taken:

![image](https://github.com/user-attachments/assets/1705597a-fb4f-48b0-87cd-2db2edbe929f)

Analysis of the Performance:
For the 10 x 10 matrix and 100 x 100 matrix, the execution time is so small that most of the function executions don’t reach 1 msec except for one instance for the C function. However, the difference can be clearly observed when the functions are called with larger inputs as seen with the test for the 1000 x 1000 matrix. Each time the C function is ran, it takes 3 to 4 msecs to execute while the assembly function takes 2 to 3 msecs. After 30 executions for each function, it can be observed that, on average, the C function takes 0.56667 msecs longer to finish execution than assembly. This is largely due to assembly eliminating high-level language abstractions such as with type checking or function calling which results in additional cycles per operation. Additionally, the usage of registers such as RAX, RBX, and XMM1 ensures that redundant memory loads and access is minimized, resulting in the faster execution times.

## II.) Screenshots of the Program Output with Correctness Check (C)

- (Note: Only the first few lines of the output pixel values for 100x100 inputs will be shown since the entire results are too large and convoluted. Additionally, the output pixel values for 1000x1000 inputs won't be shown since there's too many values that the command prompt can't display all of it, there is, however, the error check.)

### 10x10 input image:

![image](https://github.com/user-attachments/assets/8972404f-5eb8-4b66-875b-fa1aa90b8c94)

### 100x100 input image:

![image](https://github.com/user-attachments/assets/38375ebd-fa53-4f46-94a2-9d7062651a62)
...

![image](https://github.com/user-attachments/assets/4dac812e-6c65-4c51-89db-5fb3af8d7301)
...

![image](https://github.com/user-attachments/assets/1084de0a-17b5-43de-9eca-3929bde38dd1)

### 1000x1000 input image:

![image](https://github.com/user-attachments/assets/d2d38ed6-581e-4da8-bc8a-bf100cf4d515)

### Project specification sample:

![image](https://github.com/user-attachments/assets/ca6583f4-59d5-41dc-96a8-1d3406e6e369)
![image](https://github.com/user-attachments/assets/b98b5631-1fa7-476b-8f03-ee9b7e849675)

## III.) Short Video (5-10 mins) Showing Source Code, Compilation, and Execution of the C and x86-64 program

Note: use DLSU email
https://drive.google.com/file/d/1sQzAPKQiTc5H4MvHj4e6Jmok3wRGxdfW/view?usp=sharing
