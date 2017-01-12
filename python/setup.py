from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

sourcefiles = ["tn93.pyx","../src/tn93.c"]

extensions = [Extension("tn93", sourcefiles)]

setup(
	ext_modules=cythonize(extensions)
)
