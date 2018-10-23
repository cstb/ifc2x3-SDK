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


#include <ifc2x3/IfcConnectionPointGeometry.h>

#include <ifc2x3/IfcPointOrVertexPoint.h>
#include <ifc2x3/IfcPointOrVertexPoint.h>

#include <ifc2x3/CopyOp.h>
#include <ifc2x3/Visitor.h>

#include <Step/SPFData.h>
#include <Step/SPFFunctions.h>



using namespace ifc2x3;

IfcConnectionPointGeometry::IfcConnectionPointGeometry(Step::Id id, Step::SPFData *args) : 
    IfcConnectionGeometry(id, args)
{
    m_PointOnRelatingElement = NULL;
    m_PointOnRelatedElement = NULL;
}

IfcConnectionPointGeometry::~IfcConnectionPointGeometry()
{}

bool IfcConnectionPointGeometry::acceptVisitor(Step::BaseVisitor *visitor)
{
    return static_cast<Visitor *>(visitor)->visitIfcConnectionPointGeometry(this);
}


IfcPointOrVertexPoint *IfcConnectionPointGeometry::getPointOnRelatingElement()
{
    if (Step::BaseObject::inited()) 
    {
        return m_PointOnRelatingElement.get();
    }
    else 
    {
        return NULL;
    }    
}

const IfcPointOrVertexPoint *IfcConnectionPointGeometry::getPointOnRelatingElement() const
{
    return const_cast<IfcConnectionPointGeometry *>(this)->getPointOnRelatingElement();
}

void IfcConnectionPointGeometry::setPointOnRelatingElement(const Step::RefPtr< IfcPointOrVertexPoint > &value)
{
    Step::BaseObject::inited(); // make sure we are inited
    m_PointOnRelatingElement = value;
}

void IfcConnectionPointGeometry::unsetPointOnRelatingElement()
{
    Step::BaseObject::inited(); // make sure we are inited
    m_PointOnRelatingElement = Step::getUnset(getPointOnRelatingElement());
}

bool IfcConnectionPointGeometry::testPointOnRelatingElement() const
{
    Step::BaseObject::inited(); // make sure we are inited
    return Step::isUnset(getPointOnRelatingElement()) == false;
}


IfcPointOrVertexPoint *IfcConnectionPointGeometry::getPointOnRelatedElement()
{
    if (Step::BaseObject::inited()) 
    {
        return m_PointOnRelatedElement.get();
    }
    else 
    {
        return NULL;
    }    
}

const IfcPointOrVertexPoint *IfcConnectionPointGeometry::getPointOnRelatedElement() const
{
    return const_cast<IfcConnectionPointGeometry *>(this)->getPointOnRelatedElement();
}

void IfcConnectionPointGeometry::setPointOnRelatedElement(const Step::RefPtr< IfcPointOrVertexPoint > &value)
{
    Step::BaseObject::inited(); // make sure we are inited
    m_PointOnRelatedElement = value;
}

void IfcConnectionPointGeometry::unsetPointOnRelatedElement()
{
    Step::BaseObject::inited(); // make sure we are inited
    m_PointOnRelatedElement = Step::getUnset(getPointOnRelatedElement());
}

bool IfcConnectionPointGeometry::testPointOnRelatedElement() const
{
    Step::BaseObject::inited(); // make sure we are inited
    return Step::isUnset(getPointOnRelatedElement()) == false;
}

bool IfcConnectionPointGeometry::init()
{
    if (IfcConnectionGeometry::init() == false)
    {
        return false;
    }
    std::string arg;
    arg = m_args->getNext();
    if (arg == "$" || arg == "*")
    {
        m_PointOnRelatingElement = NULL;
    }
    else
    {
        m_PointOnRelatingElement = new IfcPointOrVertexPoint;
        if (arg[0] == '#') {
            m_PointOnRelatingElement->set(m_expressDataSet->get((Step::Id)atol(arg.c_str() + 1)));
        }
        else if (arg[arg.length() - 1] == ')') {
            std::string type1;
            std::string::size_type i1;
            i1 = arg.find('(');
            if (i1 != std::string::npos) {
                type1 = arg.substr(0, i1);
                arg = arg.substr(i1 + 1, arg.length() - i1 - 2);
            }
        }
    }
    arg = m_args->getNext();
    if (arg == "$" || arg == "*")
    {
        m_PointOnRelatedElement = NULL;
    }
    else
    {
        m_PointOnRelatedElement = new IfcPointOrVertexPoint;
        if (arg[0] == '#') {
            m_PointOnRelatedElement->set(m_expressDataSet->get((Step::Id)atol(arg.c_str() + 1)));
        }
        else if (arg[arg.length() - 1] == ')') {
            std::string type1;
            std::string::size_type i1;
            i1 = arg.find('(');
            if (i1 != std::string::npos) {
                type1 = arg.substr(0, i1);
                arg = arg.substr(i1 + 1, arg.length() - i1 - 2);
            }
        }
    }
    return true;
}

void IfcConnectionPointGeometry::copy(const IfcConnectionPointGeometry &obj, const CopyOp &copyop)
{
    IfcConnectionGeometry::copy(obj, copyop);
    setPointOnRelatingElement((IfcPointOrVertexPoint*)copyop(obj.m_PointOnRelatingElement.get()));
    setPointOnRelatedElement((IfcPointOrVertexPoint*)copyop(obj.m_PointOnRelatedElement.get()));
    return;
}

ClassType_child_implementations(IFC2X3_EXPORT, IfcConnectionPointGeometry, IfcConnectionGeometry)
