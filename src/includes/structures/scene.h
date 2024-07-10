#ifndef SCENE_HEADER_FILE_H
#define SCENE_HEADER_FILE_H

#include "structures/object.h"
#include "structures/abstract.h"

class RayTracingCamera{
    public:

    RayTracingCamera();

    float focalLength;
    Vector3D position;
    Vector3D direction;

    int pixelCountX,pixelCountY;


    std::vector<Ray> createStartRays();


    std::string repr();

};

#endif // SCENE_HEADER_FILE_H