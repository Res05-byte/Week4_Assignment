#include <Python.h>

// simple square fn
static PyObject* square_num(PyObject* self, PyObject* args)
{
    int x;
    if (!PyArg_ParseTuple(args, "i", &x))  // get int
        return NULL;

    int result = x * x;
    return PyLong_FromLong(result); // return int
}

// method table
static PyMethodDef SquareMethods[] = {
    {"square", square_num, METH_VARARGS, "square a number"},
    {NULL, NULL, 0, NULL}
};

// module
static struct PyModuleDef squaremodule = {
    PyModuleDef_HEAD_INIT,
    "squaremod",   // module name
    NULL,
    -1,
    SquareMethods
};

// init
PyMODINIT_FUNC PyInit_squaremod(void)
{
    return PyModule_Create(&squaremodule);
}