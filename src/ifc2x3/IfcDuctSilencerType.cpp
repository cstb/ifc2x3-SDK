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


#include <ifc2x3/IfcDuctSilencerType.h>


#include <ifc2x3/CopyOp.h>
#include <ifc2x3/Visitor.h>

#include <Step/SPFData.h>
#include <Step/SPFFunctions.h>



using namespace ifc2x3;

IfcDuctSilencerType::IfcDuctSilencerType(Step::Id id, Step::SPFData *args) : 
    IfcFlowTreatmentDeviceType(id, args)
{
    m_PredefinedType = IfcDuctSilencerTypeEnum_UNSET;
}

IfcDuctSilencerType::~IfcDuctSilencerType()
{}

bool IfcDuctSilencerType::acceptVisitor(Step::BaseVisitor *visitor)
{
    return static_cast<Visitor *>(visitor)->visitIfcDuctSilencerType(this);
}


IfcDuctSilencerTypeEnum IfcDuctSilencerType::getPredefinedType()
{
    if (Step::BaseObject::inited()) 
    {
        return m_PredefinedType;
    }
    else 
    {
        return IfcDuctSilencerTypeEnum_UNSET;
    }    
}

IfcDuctSilencerTypeEnum IfcDuctSilencerType::getPredefinedType() const
{
    return const_cast<IfcDuctSilencerType *>(this)->getPredefinedType();
}

void IfcDuctSilencerType::setPredefinedType(IfcDuctSilencerTypeEnum value)
{
    Step::BaseObject::inited(); // make sure we are inited
    m_PredefinedType = value;
}

void IfcDuctSilencerType::unsetPredefinedType()
{
    Step::BaseObject::inited(); // make sure we are inited
    m_PredefinedType = IfcDuctSilencerTypeEnum_UNSET;
}

bool IfcDuctSilencerType::testPredefinedType() const
{
    Step::BaseObject::inited(); // make sure we are inited
    return Step::isUnset(getPredefinedType()) == false;
}

bool IfcDuctSilencerType::init()
{
    if (IfcFlowTreatmentDeviceType::init() == false)
    {
        return false;
    }
    std::string arg;
    arg = m_args->getNext();
    if (arg == "$" || arg == "*")
    {
        m_PredefinedType = IfcDuctSilencerTypeEnum_UNSET;
    }
    else
    {
        if (arg == ".FLATOVAL.")
        {
            m_PredefinedType = IfcDuctSilencerTypeEnum_FLATOVAL;
        }
        else if (arg == ".RECTANGULAR.")
        {
            m_PredefinedType = IfcDuctSilencerTypeEnum_RECTANGULAR;
        }
        else if (arg == ".ROUND.")
        {
            m_PredefinedType = IfcDuctSilencerTypeEnum_ROUND;
        }
        else if (arg == ".USERDEFINED.")
        {
            m_PredefinedType = IfcDuctSilencerTypeEnum_USERDEFINED;
        }
        else if (arg == ".NOTDEFINED.")
        {
            m_PredefinedType = IfcDuctSilencerTypeEnum_NOTDEFINED;
        }
    }
    return true;
}

void IfcDuctSilencerType::copy(const IfcDuctSilencerType &obj, const CopyOp &copyop)
{
    IfcFlowTreatmentDeviceType::copy(obj, copyop);
    setPredefinedType(obj.m_PredefinedType);
    return;
}

ClassType_child_implementations(IFC2X3_EXPORT, IfcDuctSilencerType, IfcFlowTreatmentDeviceType)
