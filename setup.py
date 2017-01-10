from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

sourcefiles = ["src/_tn93.pyx","src/tn93.c"]

extensions = [Extension("_tn93", sourcefiles)]

setup(
	ext_modules=cythonize(extensions)
)

