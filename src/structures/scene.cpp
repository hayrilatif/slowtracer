#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "structures/scene.h"
#include "structures/object.h"
#include "structures/abstracts.h"

namespace py=pybind11;

RayTracingCamera::RayTracingCamera(){
    pixelCountX=100;
    pixelCountY=50;
    focalLength=1.0f;
}

std::vector<Ray> RayTracingCamera::createStartRays(){
    std::vector<Ray> rays;
    
    for(int x=0; x<pixelCountX;x++){
        for(int y=0; y<pixelCountY;y++){
            
        }   
    }
}