Operate on numpy arrays in C code, build using distutils
========================================================

This example shows how to process data in numpy arrays through a
custom C language function.  The C source code is compiled into a
shared library (``chelpers.so`` or ``chelpers.<arch>.so``) that can be
imported as a stand-alone Python module.  The script ``test.py`` runs
a quick comparison of the speed and output of our function, compared
to the same thing done by numpy.  (The numpy one will probably be
faster! That's not the point.)

To build the module and run the test in place, run::

  make test

Normally one builds C extensions through a setup.py script, which
works well with pip and can bundle .py and compiled extension files
into installable modules.  That should work here; for example::

  pip install .

or::

  pip install . --local


Notes on the C code
-------------------

The important features demonstrated by the C code in this example are:

- Defining a module and registering C functions, with docstrings, to
  be exposed by the module.
- Showing the implementation of a function that accepts numpy arrays
  as arguments and ultimately makes the ndarray data accessible
  through native pointers (``double*``).
- Checking the input array data types, shape, and C-style contiguity.
  
