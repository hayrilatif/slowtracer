from setuptools import setup, Extension
from pybind11.setup_helpers import Pybind11Extension, build_ext

import os

class CustomBuildExt(build_ext):
    def build_extension(self, ext):
        # Override the build directory by modifying the `build_lib` attribute
        original_build_lib = self.build_lib
        self.build_lib = os.path.join(original_build_lib, '/built_package')
        
        # Build the extension
        super().build_extension(ext)
        
        # Reset build_lib to its original value for other extensions
        self.build_lib = original_build_lib

ext_modules = [
    Pybind11Extension(
        "slowtracer",
        ["src/structures/object.cpp","src/structures/scene.cpp","src/structures/abstract.cpp","src/module.cpp"],
        include_dirs=["src/includes", "src/includes/structures/","src/includes/procedures/"]
    ),
]

setup(
    name="slowtracer",
    version="0.1",
    author="hayrilatif",
    description="A very very slow ray-tracing library.",
    ext_modules=ext_modules,
    cmdclass={"cext": CustomBuildExt,
              "bext": build_ext},
    zip_safe=False,
)