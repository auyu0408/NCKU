#include <iostream>
#include <stdexcept>

int main()
{
    bool flag = false;

    try {
       try {
          throw std::runtime_error("");
       } catch (std::exception const& inner_std_exception) {
          if (flag) {
             // goes to outter catch(std::exception const&)
             // QUESTION: why is this not caught by catch (std::runtime_error const&)?
             throw inner_std_exception;
          } else {
             // goes to catch (std::runtime_error const&)
             throw;
          }
       }
    } catch (std::runtime_error const& runtime_error) {
       std::cout << "caught std::runtime_error" << '\n';
    } catch (std::exception const& outter_std_exception) {
       std::cout << "caught std::exception" << '\n';
    }

    return 0;
}
