#-*- coding: utf-8 -*-
import os
import sys
from setuptools import setup, Extension


sys.path.append('./src')
#sys.path.append('./test')

version = file('VERSION').read().strip()

# get sources
sources = ['_liburg.c']
for tpl in os.walk('liburg/src/c'):
    for filename in tpl[2]:
        if '.c' in filename and \
                'win' not in filename and \
                'serial_ctrl_lin.c' not in filename:
            sources.append(os.path.join(tpl[0], filename))

liburg_ext = Extension('_liburg',
                       include_dirs=['liburg/include/c',
                                     'liburg/src/c/connection',
                                     'liburg/src/c/system',
                                     'liburg/src/c/urg'],
                       sources=sources)

setup(name='pyliburg',
      version=version,
      description="python library to access Hokuyo URG laser range scanners",
      long_description=file('liburg/README').read(),
      classifiers=[],
      keywords=('hardware, sensors, URG'),
      author='Takahiro Kamatani',
      author_email='tk@buhii.org',
      url='https://github.com/buhii/pyliburg',
      license='LGPL',
      package_dir={'': 'src'},
      packages=['pyliburg'],
      ext_modules=[liburg_ext],
      #install_requires=["numpy","PIL"],
      #test_suite='test_ccv.suite'
      )
