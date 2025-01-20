#ifndef SG_PYTHON_BINDINGS_H
#define SG_PYTHON_BINDINGS_H

#include <memory>
#include <vector>
#include <SenseGlove/Core/HandLayer.hpp>
#include <SenseGlove/Core/HapticGlove.hpp>
#include <SenseGlove/Core/SenseGlove.hpp>
#include <SenseGlove/Core/SenseGloveSensorData.hpp>

using namespace SGCore;

std::shared_ptr<SG::SenseGlove> getGlove(bool bRightHanded);

class SGGloveWrapper{
public:
    std::shared_ptr<SG::SenseGlove> _glove;
    SGGloveWrapper(bool bRightHanded):_glove(getGlove(bRightHanded)){};
    std::vector<double> getConfig();
};

#endif // SG_PYTHON_BINDINGS_H