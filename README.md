Steps to reproduce:  
1. Create venv, activate venv, and update pip:
```
python3 -m venv venv && source venv/bin/activate && python3 -m pip install --upgrade pip
```

2. Installation:
- Git clone repo and install from source: 
```
python3 -m pip install .
```
- Install from github:
```
python3 -m pip install 
```

3. Verify installation:
```python
>>> import numpy as np
>>> import mymodule
>>> v = np.arange(15).reshape(3, 5)
>>> mymodule.wrap_sum_of_sines(v)
1.2853996391883833
```
