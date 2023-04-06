Steps to reproduce:  
1. Create venv, activate venv, and update pip:
```
python3 -m venv venv && source venv/bin/activate && python3 -m pip install --upgrade pip
```

2. Installation: There are two ways to install.
- Git clone repo and install from source: 
```
git clone --recursive https://github.com/lionlai1989/xtensor_pybind11_cmake.git
python3 -m pip install .
```
- Install from github:
```
python3 -m pip install "mymodule @ git+ssh://git@github.com/lionlai1989/xtensor_pybind11_cmake.git"
```

3. Verify installation:
```python
>>> import numpy as np
>>> import mymodule
>>> v = np.arange(15).reshape(3, 5)
>>> mymodule.wrap_sum_of_sines(v)
1.2853996391883833
```

4. Link the library `xtensor::use_xsimd` to my target `sum_of_sines_static` in `src/mypackage/CMakeLists.txt`:
- Comment out Line:5 in `src/mypackage/CMakeLists.txt` and uncomment Line:6:
```
target_link_libraries(sum_of_sines_static PUBLIC xtensor xtensor::optimize xtensor::use_xsimd)
```
- The error when `python3 -m pip install .`:
```
      -- Configuring done (1.3s)
      CMake Error at src/mypackage/CMakeLists.txt:5 (target_link_libraries):
        Target "sum_of_sines_static" links to:
      
          xtensor::optimize
      
        but the target was not found.  Possible reasons include:
      
          * There is a typo in the target name.
          * A find_package call is missing for an IMPORTED target.
          * An ALIAS target is missing.
      
      
      
      -- Generating done (0.0s)
      CMake Warning:
        Manually-specified variables were not used by the project:
      
          EXAMPLE_VERSION_INFO
      
      
      CMake Generate step failed.  Build files cannot be regenerated correctly.
```

