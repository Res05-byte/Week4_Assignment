from distutils.core import setup, Extension

module = Extension("intarraymod", sources=["intarray.c"])

setup(
    name="intarraymod",
    version="1.0",
    ext_modules=[module]
)