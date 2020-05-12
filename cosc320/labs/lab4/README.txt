Florent Dondjeu Tschoufack
COSC 320 - lab4
README.txt
Feb 27,2020

(a) I have a matrix class where all the variables and functions are public. In order to make a matrix, I used a two-dimensional array where each row and column are dynamically allocated. In order to utalize that matrix, I made multiple fill<order_type>() fucntions. I also overloaded the +, -, and * operator in order to do matrix arithmatics. Most of my functions also have error handling, where if the matrices dimensions do not match or the user inputs an invalid matrix size, an error will be thrown which will then end the program.

(b) The addition and substraction time complexity was O(n^2), and my multiplication time complexity was O(n^3).

(c) For both my addition and substraction which consisted of double nested for loops that go from 0 to n, the time complexity is Θ(n^2). My multiplication time complexity on the other hand is Θ(n^3), because of the triple nested for loops which go from o to n.

(d) My code could be improved by implemented a stronger error handling system and having more comments explaining what is happening.