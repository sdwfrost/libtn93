from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

sourcefiles = ["src/tn93module.pyx","src/tn93.c"]

extensions = [Extension("tn93", sourcefiles)]

setup(
	ext_modules=cythonize(extensions)
)

