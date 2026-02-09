#include <Python.h>

typedef struct TSLanguage TSLanguage;

TSLanguage *tree_sitter_moonbit(void);
TSLanguage *tree_sitter_moonbit_interface(void);
TSLanguage *tree_sitter_moonbit_package(void);

static PyObject* _binding_language(PyObject *Py_UNUSED(self), PyObject *Py_UNUSED(args)) {
    return PyCapsule_New(tree_sitter_moonbit(), "tree_sitter.Language", NULL);
}

static PyObject* _binding_language_interface(PyObject *Py_UNUSED(self), PyObject *Py_UNUSED(args)) {
    return PyCapsule_New(tree_sitter_moonbit_interface(), "tree_sitter.Language", NULL);
}

static PyObject* _binding_language_package(PyObject *Py_UNUSED(self), PyObject *Py_UNUSED(args)) {
    return PyCapsule_New(tree_sitter_moonbit_package(), "tree_sitter.Language", NULL);
}

static struct PyModuleDef_Slot slots[] = {
#ifdef Py_GIL_DISABLED
    {Py_mod_gil, Py_MOD_GIL_NOT_USED},
#endif
    {0, NULL}
};

static PyMethodDef methods[] = {
    {"language", _binding_language, METH_NOARGS,
     "Get the tree-sitter language for this grammar."},
    {"language_interface", _binding_language_interface, METH_NOARGS,
     "Get the tree-sitter language for the MoonBit interface grammar."},
    {"language_package", _binding_language_package, METH_NOARGS,
     "Get the tree-sitter language for the MoonBit package grammar."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "_binding",
    .m_doc = NULL,
    .m_size = 0,
    .m_methods = methods,
    .m_slots = slots,
};

PyMODINIT_FUNC PyInit__binding(void) {
    return PyModuleDef_Init(&module);
}
