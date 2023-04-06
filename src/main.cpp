#include <numeric>
#include <pybind11/pybind11.h>

#define FORCE_IMPORT_ARRAY
#include <xtensor-python/pyarray.hpp>

#include <mypackage/sum_of_sines.hpp>

double wrap_sum_of_sines(const xt::pyarray<double> &m) {
  return sum_of_sines(m);
}

PYBIND11_MODULE(mymodule, m) {
  xt::import_numpy();
  m.doc() = "Test module for xtensor python bindings";
  m.def("wrap_sum_of_sines", wrap_sum_of_sines,
        "Sum the sines of the input values");
}
