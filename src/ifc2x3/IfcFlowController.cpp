// IFC SDK : IFC2X3 C++ Early Classes  
// Copyright (C) 2009 CSTB
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full license is in Licence.txt file included with this 
// distribution or is available at :
//     http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

#ifdef ENABLE_MSVC_PRECOMPILED_HEADER
#include "precompiled.h"
#endif

#include "ifc2x3/IfcFlowController.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcDistributionFlowElement.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>


#include <string>

using namespace ifc2x3;

IfcFlowController::IfcFlowController(Step::Id id, Step::SPFData *args) : IfcDistributionFlowElement(id, args) {
}

IfcFlowController::~IfcFlowController() {
}

bool IfcFlowController::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcFlowController(this);
}

const std::string &IfcFlowController::type() const {
    return IfcFlowController::s_type.getName();
}

const Step::ClassType &IfcFlowController::getClassType() {
    return IfcFlowController::s_type;
}

const Step::ClassType &IfcFlowController::getType() const {
    return IfcFlowController::s_type;
}

bool IfcFlowController::isOfType(const Step::ClassType &t) const {
    return IfcFlowController::s_type == t ? true : IfcDistributionFlowElement::isOfType(t);
}

bool IfcFlowController::init() {
    bool status = IfcDistributionFlowElement::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcFlowController::copy(const IfcFlowController &obj, const CopyOp &copyop) {
    IfcDistributionFlowElement::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcFlowController::s_type("IfcFlowController");
