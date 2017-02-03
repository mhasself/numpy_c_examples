/* -*- mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *      vim: sw=4 ts=4 et tw=80
 */

#include <Python.h>
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/arrayobject.h>

#include <assert.h>

/* Custom includes... */

PyDoc_STRVAR(contract__doc,
             "contract(v, M, w)\n"
             "\n"
             "Compute dot(v, dot(m, w))\n"
             "\n"
             "v and w are 1-d C-ordered numpy arrays.\n"
             "M is a 2-d C-ordered numpy array, with dimensions matching v and w.\n"
             "\n"
             "All arrays must have dtype='float64'\n"
    );




static PyObject *contract(PyObject *self, PyObject *args) {
    PyArrayObject *v_array;
    PyArrayObject *M_array;
    PyArrayObject *w_array;
    if (!PyArg_ParseTuple(args, "O!O!O!",
                          &PyArray_Type, &v_array,
                          &PyArray_Type, &M_array,
                          &PyArray_Type, &w_array)) {
        printf("contract: bad input arguments.\n");
        Py_RETURN_NONE;
    }

    // Check ordering
    assert(PyArray_FLAGS(v_array) & NPY_ARRAY_CARRAY);
    assert(PyArray_FLAGS(M_array) & NPY_ARRAY_CARRAY);
    assert(PyArray_FLAGS(w_array) & NPY_ARRAY_CARRAY);
    
    // Check dimensionality
    assert(PyArray_NDIM(v_array)==1);
    assert(PyArray_NDIM(M_array)==2);
    assert(PyArray_NDIM(w_array)==1);

    // Check size
    int nv = PyArray_DIMS(v_array)[0];
    int nw = PyArray_DIMS(w_array)[0];
    assert(PyArray_DIMS(M_array)[0] == nv);
    assert(PyArray_DIMS(M_array)[1] == nw);

    // And types.
    assert(PyArray_TYPE(v_array) == NPY_FLOAT64);
    assert(PyArray_TYPE(M_array) == NPY_FLOAT64);
    assert(PyArray_TYPE(w_array) == NPY_FLOAT64);

    // Ok I'm convinced.
    const double *M = PyArray_DATA(M_array);
    const double *v = PyArray_DATA(v_array);
    const double *w = PyArray_DATA(w_array);
    
    // Now call CBLAS, or just:
    double sum = 0.;
    for (int i=0; i<nv; i++) {
        double row = 0.;
        for (int j=0; j<nw; j++)
            row += *(M++) * w[j];
        sum += row*v[i];
    }

    return PyFloat_FromDouble(sum);
}


static PyMethodDef helpersMethods[] = {
    {"contract", contract, METH_VARARGS,
     contract__doc},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


PyMODINIT_FUNC
initchelpers(void)
{
    Py_InitModule("chelpers", helpersMethods);
    import_array();
}
