from distutils.core import setup, Extension

modname = 'chelpers'

import os
import glob
import numpy

includes = [numpy.get_include()]
library_dirs = []
libraries = []


sources = ['chelpers.c']

module1 = Extension('chelpers',
                    sources=sources,
                    include_dirs=includes,
                    library_dirs=library_dirs,
                    libraries=libraries,
                    extra_compile_args=['-std=c99'])

setup(name = modname,
      version = '1.0',
      description = modname,
      ext_modules = [module1],
      )
