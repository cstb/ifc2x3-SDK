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


#include <ifc2x3/IfcCenterLineProfileDef.h>


#include <ifc2x3/CopyOp.h>
#include <ifc2x3/Visitor.h>

#include <Step/SPFData.h>
#include <Step/SPFFunctions.h>



using namespace ifc2x3;

IfcCenterLineProfileDef::IfcCenterLineProfileDef(Step::Id id, Step::SPFData *args) : 
    IfcArbitraryOpenProfileDef(id, args)
{
    m_Thickness = Step::getUnset(m_Thickness);
}

IfcCenterLineProfileDef::~IfcCenterLineProfileDef()
{}

bool IfcCenterLineProfileDef::acceptVisitor(Step::BaseVisitor *visitor)
{
    return static_cast<Visitor *>(visitor)->visitIfcCenterLineProfileDef(this);
}


IfcPositiveLengthMeasure IfcCenterLineProfileDef::getThickness()
{
    if (Step::BaseObject::inited()) 
    {
        return m_Thickness;
    }
    else 
    {
        return Step::getUnset(m_Thickness);
    }    
}

IfcPositiveLengthMeasure IfcCenterLineProfileDef::getThickness() const
{
    return const_cast<IfcCenterLineProfileDef *>(this)->getThickness();
}

void IfcCenterLineProfileDef::setThickness(IfcPositiveLengthMeasure value)
{
    Step::BaseObject::inited(); // make sure we are inited
    m_Thickness = value;
}

void IfcCenterLineProfileDef::unsetThickness()
{
    Step::BaseObject::inited(); // make sure we are inited
    m_Thickness = Step::getUnset(getThickness());
}

bool IfcCenterLineProfileDef::testThickness() const
{
    return Step::isUnset(getThickness()) == false;
}

bool IfcCenterLineProfileDef::init()
{
    if (IfcArbitraryOpenProfileDef::init() == false)
    {
        return false;
    }
    std::string arg;
    arg = m_args->getNext();
    if (arg == "$" || arg == "*")
    {
        m_Thickness = Step::getUnset(m_Thickness);
    }
    else
    {
        m_Thickness = Step::spfToReal(arg)

;
    }
    return true;
}

void IfcCenterLineProfileDef::copy(const IfcCenterLineProfileDef &obj, const CopyOp &copyop)
{
    IfcArbitraryOpenProfileDef::copy(obj, copyop);
    setThickness(obj.m_Thickness);
    return;
}

ClassType_child_implementations(IFC2X3_EXPORT, IfcCenterLineProfileDef, IfcArbitraryOpenProfileDef)
