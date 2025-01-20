#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "python.h"
#include <memory>
#include <vector>
#include <SenseGlove/Core/HandLayer.hpp>
#include <SenseGlove/Core/HapticGlove.hpp>
#include <SenseGlove/Core/SenseGlove.hpp>
#include <SenseGlove/Core/SenseGloveSensorData.hpp>

namespace py = pybind11;
using namespace SGCore;


std::shared_ptr<SG::SenseGlove> getGlove(bool bRightHanded){
    std::shared_ptr<HapticGlove> out_glove_hg;
    HandLayer::GetGloveInstance(bRightHanded, out_glove_hg);
    std::shared_ptr<SG::SenseGlove> glove = std::dynamic_pointer_cast<SG::SenseGlove>(out_glove_hg);
    return glove;
}


std::vector<double> SGGloveWrapper::getConfig(){
    std::vector<double> out(20, 0);
    if(!_glove){
        return out;
    }
    SG::SenseGloveSensorData out_sensordata;
    bool got_data = _glove->GetSensorData(out_sensordata);
    if(!got_data){
        return out;
    }
    auto angles = out_sensordata.GetSensorAngles();
    int counter = 0;
    for(int i = 0; i < angles.size(); i++){
        for(int j = 0; j < angles[i].size(); j++){
            out[counter] = angles[i][j];
            counter++;
        }
    }
    return out;
}


PYBIND11_MODULE(py_sgdk1, m){
    py::class_<SGGloveWrapper>(m, "SGGloveWrapper")
        .def(py::init<bool>())
        .def("getConfig", &SGGloveWrapper::getConfig);
}
