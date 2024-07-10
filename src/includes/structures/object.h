#ifndef OBJECT_HEADER_FILE_H
#define OBJECT_HEADER_FILE_H

#include <vector>
#include <string>

#include "structures/abstract.h"


struct Vertex {
    float x, y, z;

    Vertex(float x,float y,float z);
    Vertex();

    std::string repr();
};

class Object{
    public:
    bool intersect(Ray ray);
}

struct Face : public Object {
    std::vector<int> vertexIndices;

    Face(std::vector<int> vertexIndices);
    Face();

    std::string repr();
};

class Mesh : public Object{
    public:
    std::vector<Vertex> vertices;
    std::vector<Face> faces;

    bool load(const std::string& filename);
};

class Sphere : public Object{
    public:
    std::vector<Vector3D> position;
    float radius;

    bool intersect(Ray ray);
}

struct Vector3D{
    float x,y,z;
    Vector3D(float x,float y,float z);
    Vector3D();


    std::string repr();
};

#endif //OBJECT_HEADER_FILE_H