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


#include <ifc2x3/IfcRelDefines.h>

#include <ifc2x3/IfcObject.h>
#include <ifc2x3/IfcObject.h>

#include <ifc2x3/CopyOp.h>
#include <ifc2x3/Visitor.h>

#include <Step/SPFData.h>
#include <Step/SPFFunctions.h>



using namespace ifc2x3;

Inverted_IfcRelDefines_RelatedObjects_type::Inverted_IfcRelDefines_RelatedObjects_type()
{

}

void Inverted_IfcRelDefines_RelatedObjects_type::setOwner(IfcRelDefines *owner)
{
    mOwner = owner;
}

void Inverted_IfcRelDefines_RelatedObjects_type::insert(const Step::RefPtr< IfcObject > &value)
#ifdef STEP_CHECK_RANGE
    throw(std::out_of_range)
#endif
{
    IfcObject *inverse = const_cast< IfcObject * > (value.get());
    Set_IfcObject_1_n::insert(value);
    inverse->m_IsDefinedBy.insert(mOwner);
}


Inverted_IfcRelDefines_RelatedObjects_type::size_type Inverted_IfcRelDefines_RelatedObjects_type::erase(const Step::RefPtr< IfcObject > &value)
{
    IfcObject *inverse = const_cast< IfcObject * > (value.get());
    inverse->m_IsDefinedBy.erase(mOwner);
    return Set_IfcObject_1_n::erase(value);
}

void Inverted_IfcRelDefines_RelatedObjects_type::clear()
{
    while (size())
    {
        erase(*begin());
    }
}


IfcRelDefines::IfcRelDefines(Step::Id id, Step::SPFData *args) : 
    IfcRelationship(id, args)
{
    m_RelatedObjects.setUnset(true);
    m_RelatedObjects.setOwner(this);
}

IfcRelDefines::~IfcRelDefines()
{}

bool IfcRelDefines::acceptVisitor(Step::BaseVisitor *visitor)
{
    return static_cast<Visitor *>(visitor)->visitIfcRelDefines(this);
}

Set_IfcObject_1_n &IfcRelDefines::getRelatedObjects()
{
    if (Step::BaseObject::inited())
    {
        return m_RelatedObjects;
    }
    else
    {
        m_RelatedObjects.setUnset(true);
        return m_RelatedObjects;
    }
}

const Set_IfcObject_1_n &IfcRelDefines::getRelatedObjects() const
{
    return const_cast< IfcRelDefines * > (this)->getRelatedObjects();
}

void IfcRelDefines::unsetRelatedObjects()
{
    Step::BaseObject::inited(); // make sure we are inited
    m_RelatedObjects.clear();
    m_RelatedObjects.setUnset(true);
}

bool IfcRelDefines::testRelatedObjects() const
{
    Step::BaseObject::inited(); // make sure we are inited
    return m_RelatedObjects.isUnset() == false;
}

bool IfcRelDefines::init()
{
    if (IfcRelationship::init() == false)
    {
        return false;
    }
    std::string arg;
    arg = m_args->getNext();
    if (arg == "$" || arg == "*")
    {
        m_RelatedObjects.setUnset(true);
    }
    else
    {
        m_RelatedObjects.setUnset(false);
        while (true)
        {
            std::string str1;
            Step::getSubParameter(arg, str1);
            if (!str1.empty())
            {
                m_RelatedObjects.insert(static_cast< IfcObject * > (m_expressDataSet->get(Step::getIdParam(str1)))
);
            }
            else 
            {
                break;
            }
        }
    }
    return true;
}

void IfcRelDefines::copy(const IfcRelDefines &obj, const CopyOp &copyop)
{
    IfcRelationship::copy(obj, copyop);
    Set_IfcObject_1_n::const_iterator it_m_RelatedObjects;
    for (it_m_RelatedObjects = obj.m_RelatedObjects.begin(); it_m_RelatedObjects != obj.m_RelatedObjects.end(); ++it_m_RelatedObjects)
    {
        Step::RefPtr< IfcObject > copyTarget = (IfcObject *) (copyop((*it_m_RelatedObjects).get()));
        m_RelatedObjects.insert(copyTarget);
    }
    
    return;
}

ClassType_child_implementations(IFC2X3_EXPORT, IfcRelDefines, IfcRelationship)
