from setuptools import setup, Extension

module = Extension("squaremod", sources=["square.c"])

setup(
    name="squaremod",
    version="1.0",
    ext_modules=[module]
)