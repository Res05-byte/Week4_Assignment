#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;

// joins two strings
std::string join_str(std::string a, std::string b) {
    return a + b;
}

PYBIND11_MODULE(concatmod, m) {
    m.def("join", &join_str, "join 2 strings");
}