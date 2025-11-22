from setuptools import setup, Extension
import pybind11

ext = Extension(
    "concatmod",
    ["concat.cpp"],
    include_dirs=[pybind11.get_include()]
)

setup(
    name="concatmod",
    version="1.0",
    ext_modules=[ext]
)