#include <Python.h>
#include <stdlib.h>

static int* arr = NULL;
static int size = 0;

// make array
static PyObject* arr_init(PyObject* self, PyObject* args)
{
    if (!PyArg_ParseTuple(args, "i", &size))
        return NULL;

    arr = (int*)malloc(size * sizeof(int));
    return PyLong_FromLong(1); // ok
}

// set val
static PyObject* arr_set(PyObject* self, PyObject* args)
{
    int idx, val;
    if (!PyArg_ParseTuple(args, "ii", &idx, &val))
        return NULL;

    arr[idx] = val;
    return PyLong_FromLong(1);
}

// get val
static PyObject* arr_get(PyObject* self, PyObject* args)
{
    int idx;
    if (!PyArg_ParseTuple(args, "i", &idx))
        return NULL;

    return PyLong_FromLong(arr[idx]);
}

// free
static PyObject* arr_free(PyObject* self, PyObject* args)
{
    free(arr);
    return PyLong_FromLong(1);
}

// methods
static PyMethodDef ArrMethods[] = {
    {"init", arr_init, METH_VARARGS, "init array"},
    {"set", arr_set, METH_VARARGS, "set val"},
    {"get", arr_get, METH_VARARGS, "get val"},
    {"free", arr_free, METH_NOARGS, "free arr"},
    {NULL, NULL, 0, NULL}
};

// module
static struct PyModuleDef arrmodule = {
    PyModuleDef_HEAD_INIT,
    "intarraymod",
    NULL,
    -1,
    ArrMethods
};

PyMODINIT_FUNC PyInit_intarraymod(void)
{
    return PyModule_Create(&arrmodule);
}