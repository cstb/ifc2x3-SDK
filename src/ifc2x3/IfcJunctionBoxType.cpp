// IFC SDK : IFC2X3 C++ Early Classes
// Copyright (C) 2009-2018 CSTB   
//   
// For further information please contact
//                                       
//         eveBIM-support@cstb.fr        
//   or                                  
//         CSTB DTI/MIC                  
//         290, route des Lucioles       
//         BP 209                        
//         06904 Sophia Antipolis, France
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


#include <ifc2x3/IfcJunctionBoxType.h>


#include <ifc2x3/CopyOp.h>
#include <ifc2x3/Visitor.h>

#include <Step/SPFData.h>
#include <Step/SPFFunctions.h>



using namespace ifc2x3;

IfcJunctionBoxType::IfcJunctionBoxType(Step::Id id, Step::SPFData *args) : 
    IfcFlowFittingType(id, args)
{
    m_PredefinedType = IfcJunctionBoxTypeEnum_UNSET;
}

IfcJunctionBoxType::~IfcJunctionBoxType()
{}

bool IfcJunctionBoxType::acceptVisitor(Step::BaseVisitor *visitor)
{
    return static_cast<Visitor *>(visitor)->visitIfcJunctionBoxType(this);
}


IfcJunctionBoxTypeEnum IfcJunctionBoxType::getPredefinedType()
{
    if (Step::BaseObject::inited()) 
    {
        return m_PredefinedType;
    }
    else 
    {
        return IfcJunctionBoxTypeEnum_UNSET;
    }    
}

IfcJunctionBoxTypeEnum IfcJunctionBoxType::getPredefinedType() const
{
    return const_cast<IfcJunctionBoxType *>(this)->getPredefinedType();
}

void IfcJunctionBoxType::setPredefinedType(IfcJunctionBoxTypeEnum value)
{
    Step::BaseObject::inited(); // make sure we are inited
    m_PredefinedType = value;
}

void IfcJunctionBoxType::unsetPredefinedType()
{
    Step::BaseObject::inited(); // make sure we are inited
    m_PredefinedType = IfcJunctionBoxTypeEnum_UNSET;
}

bool IfcJunctionBoxType::testPredefinedType() const
{
    Step::BaseObject::inited(); // make sure we are inited
    return Step::isUnset(getPredefinedType()) == false;
}

bool IfcJunctionBoxType::init()
{
    if (IfcFlowFittingType::init() == false)
    {
        return false;
    }
    std::string arg;
    arg = m_args->getNext();
    if (arg == "$" || arg == "*")
    {
        m_PredefinedType = IfcJunctionBoxTypeEnum_UNSET;
    }
    else
    {
        if (arg == ".USERDEFINED.")
        {
            m_PredefinedType = IfcJunctionBoxTypeEnum_USERDEFINED;
        }
        else if (arg == ".NOTDEFINED.")
        {
            m_PredefinedType = IfcJunctionBoxTypeEnum_NOTDEFINED;
        }
    }
    return true;
}

void IfcJunctionBoxType::copy(const IfcJunctionBoxType &obj, const CopyOp &copyop)
{
    IfcFlowFittingType::copy(obj, copyop);
    setPredefinedType(obj.m_PredefinedType);
    return;
}

ClassType_child_implementations(IFC2X3_EXPORT, IfcJunctionBoxType, IfcFlowFittingType)
