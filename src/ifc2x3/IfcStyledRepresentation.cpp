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

#include "precompiled.h"

#include <ifc2x3/IfcStyledRepresentation.h>

#include <ifc2x3/CopyOp.h>
#include <ifc2x3/IfcStyleModel.h>
#include <ifc2x3/Visitor.h>
#include <Step/ClassType.h>
#include <Step/logger.h>


#include <string>

using namespace ifc2x3;

IfcStyledRepresentation::IfcStyledRepresentation(Step::Id id, Step::SPFData *args) : IfcStyleModel(id, args) {
}

IfcStyledRepresentation::~IfcStyledRepresentation() {
}

bool IfcStyledRepresentation::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcStyledRepresentation(this);
}

const std::string &IfcStyledRepresentation::type() const {
    return IfcStyledRepresentation::s_type.getName();
}

const Step::ClassType &IfcStyledRepresentation::getClassType() {
    return IfcStyledRepresentation::s_type;
}

const Step::ClassType &IfcStyledRepresentation::getType() const {
    return IfcStyledRepresentation::s_type;
}

bool IfcStyledRepresentation::isOfType(const Step::ClassType &t) const {
    return IfcStyledRepresentation::s_type == t ? true : IfcStyleModel::isOfType(t);
}

bool IfcStyledRepresentation::init() {
    bool status = IfcStyleModel::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcStyledRepresentation::copy(const IfcStyledRepresentation &obj, const CopyOp &copyop) {
    IfcStyleModel::copy(obj, copyop);
    return;
}

IFC2X3_EXPORT Step::ClassType IfcStyledRepresentation::s_type("IfcStyledRepresentation");
