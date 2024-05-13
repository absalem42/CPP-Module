#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b("John", 45);

        Form f("Form1", 44, 30);

        std::cout << b << std::endl;
        std::cout << f << std::endl;

        b.signForm(f);

        std::cout << f << std::endl;

        b.increment();
        std::cout << b << std::endl;

        b.signForm(f);

        std::cout << f << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
