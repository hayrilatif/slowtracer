#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "structures/object.h"
#include "structures/scene.h"
#include "structures/abstract.h"

namespace py = pybind11;



PYBIND11_MODULE(slowtracer, m) {
    m.doc() = "Very very slow ray tracer.";

    //////////////////////////////////////////////////////////////////
    auto object_module=m.def_submodule("object","Object structures.");

    py::class_<Vertex>(object_module,"Vertex")
        .def(py::init<float,float,float>())
        .def(py::init<>())
        .def_readwrite("x",&Vertex::x,"X coordinate")
        .def_readwrite("y",&Vertex::y,"Y coordinate")
        .def_readwrite("z",&Vertex::z,"Z coordinate")
        
        .def("__repr__",&Vertex::repr)
        ;

    py::class_<Mesh>(object_module,"Object","Abstract scene object.")
        .def(py::init<>());

    py::class_<Face>(object_module,"Face")
        .def(py::init<std::vector<int>>())
        .def(py::init<>())
        .def_readwrite("vertexIndices",&Face::vertexIndices)
        
        .def("__repr__",&Face::repr)
        ;
    
    py::class_<Mesh>(object_module,"Mesh","Mesh data container.")
        .def(py::init<>())
        .def("load",&Mesh::load,"Loads mesh data from .obj file to container.")
        .def_readonly("vertices",&Mesh::vertices)
        .def_readonly("faces",&Mesh::faces);

    py::class_<Sphere>(object_module,"Sphere","A sphere, nothing more.")
        .def(py::init<>())
        .def_readwrite("position",&Sphere::position)
        .def_readwrite("radius",&Sphere::radius);

    py::class_<Vector3D>(object_module,"Vector3D")
        .def(py::init<float,float,float>())
        .def(py::init<>())
        .def_readwrite("x",&Vector3D::x)
        .def_readwrite("y",&Vector3D::y)
        .def_readwrite("z",&Vector3D::z)
        
        .def("__repr__",&Vector3D::repr)
        ;

    ///////////////////////////////////////////////////////////////////

    auto scene_module=m.def_submodule("scene","Scene structures.");

    py::class_<RayTracingCamera>(scene_module,"RayTracingCamera")
        .def(py::init<>())
        .def_readwrite("focalLength",&RayTracingCamera::focalLength,"Focal length of the camera.")
        .def_readwrite("position",&RayTracingCamera::position,"World position of the camera.")
        .def_readwrite("direction",&RayTracingCamera::direction,"Direction of the camera.")

        .def_readwrite("pixelCountX",&RayTracingCamera::pixelCountX,"Horizontal pixel count.")
        .def_readwrite("pixelCountY",&RayTracingCamera::pixelCountY,"Vertical pixel count.")
        ;


    ////////////////////////////////////////////////////////////////////

    auto abstract_module=m.def_submodule("abstract","Abstract structures.");

    py::class_<Ray>(abstract_module,"Ray")
        .def(py::init<>())
        .def_readwrite("origin",&Ray::origin,"Origin of the ray.")
        .def_readwrite("direction",&Ray::direction,"Direction of the ray.")
        .def_readwrite("t",&Ray::t);
}