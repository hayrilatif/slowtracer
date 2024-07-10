#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "structures/object.h"
#include "structures/abstract.h"


#include <iostream>
#include <fstream>
#include <sstream>

namespace py=pybind11;




bool Objects::intersect(Ray ray){
    //empty
}

//////////////////////////////////

bool Sphere::intersect(Ray ray){
    
}

///////////////////////////////
bool Mesh::load(const std::string&filename){
    std::ifstream file(filename);
    if(!file.is_open())
    {
        std::cerr<<"Error! : file can not opened!";
        return false;
    }

    std::string line;
    while(getline(file,line))
    {
        std::istringstream lineStream(line);
        std::string type;

        lineStream>>type;
        if(type=="v")
        {
            //vertex info
            Vertex vertex;
            lineStream>>vertex.x>>vertex.y>>vertex.z;
            vertices.push_back(vertex);
        }
        else if(type=="f")
        {
            //facee info
            Face face;
            std::string vertex;
            while (lineStream>>vertex)
            {
                int vertexIndex=std::stoi(vertex);
                face.vertexIndices.push_back(vertexIndex-1);
            }
            faces.push_back(face);
        }
    }
    file.close();
    return true;
}


////////////////////////////

Vertex::Vertex(float x,float y,float z) : x(x), y(y), z(z) {}
Vertex::Vertex() {}

std::string Vertex::repr() {
        std::ostringstream stream;
        stream << "Vertex(" << x << ", " << y << ", " << z << ")";
        return stream.str();
}

///////////////////

Face::Face(std::vector<int>vertexIndices) : vertexIndices(vertexIndices) {}
Face::Face() {}

std::string Face::repr() {
        std::ostringstream stream;
        stream << "Face(";

        auto size=vertexIndices.size();
        for(std::vector<int>::size_type i=0;i<size;i++)
        {
            stream << vertexIndices[i];
            if (i!=size-1)
            {
                stream << ", ";
            }
        }

        stream<<")";

        return stream.str();
}

////////////////////

Vector3D::Vector3D(float x,float y,float z) : x(x), y(y), z(z) {}
Vector3D::Vector3D()
{
    x=0;
    y=0;
    z=0;
}

std::string Vector3D::repr() {
        std::ostringstream stream;
        stream << "Vector3D(" << x << ", " << y << ", " << z << ")";
        return stream.str();
}