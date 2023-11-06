#include <iostream>

int main() {
    // Declare variables
    int a, b, c;

    // Get user input
    std::cout << "Enter three integer values: ";
    std::cin >> a >> b >> c;

    // Create integer pointers and allocate dynamic memory
    int *ptrA = new int(a);
    int *ptrB = new int(b);
    int *ptrC = new int(c);

    // Display contents of variables and pointers
    std::cout << "\nContents of variables:\n";
    std::cout << "a: " << a << "\nb: " << b << "\nc: " << c << "\n\n";

    std::cout << "Contents of pointers:\n";
    std::cout << "ptrA: " << *ptrA << "\nptrB: " << *ptrB << "\nptrC: " << *ptrC << "\n\n";

    // Deallocate dynamic memory using delete operator
    delete ptrA;
    delete ptrB;
    delete ptrC;

    return 0;
}
