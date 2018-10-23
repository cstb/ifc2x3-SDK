#pragma once

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


#include <ifc2x3/Export.h>

#include <ifc2x3/IfcSolidModel.h>

namespace ifc2x3
{


    /**
     * Generated class for the IfcSweptDiskSolid Entity.
     *
     */
    class IFC2X3_EXPORT IfcSweptDiskSolid : public IfcSolidModel
    {

        // Attributes
        Step::RefPtr< IfcCurve > m_Directrix;
        IfcPositiveLengthMeasure m_Radius;
        IfcPositiveLengthMeasure m_InnerRadius;
        IfcParameterValue m_StartParam;
        IfcParameterValue m_EndParam;

        ClassType_definitions()

    public:
        virtual bool acceptVisitor(Step::BaseVisitor *visitor);

        /// Attribute Directrix
        /// @{
        virtual IfcCurve *getDirectrix();
        virtual const IfcCurve *getDirectrix() const;
        virtual void setDirectrix(const Step::RefPtr< IfcCurve > &value);
        virtual void unsetDirectrix();
        virtual bool testDirectrix() const;
        /// @}

        /// Attribute Radius
        /// @{
        virtual IfcPositiveLengthMeasure getRadius();
        virtual IfcPositiveLengthMeasure getRadius() const;
        virtual void setRadius(IfcPositiveLengthMeasure value);
        virtual void unsetRadius();
        virtual bool testRadius() const;
        /// @}

        /// Attribute InnerRadius
        /// @{
        virtual IfcPositiveLengthMeasure getInnerRadius();
        virtual IfcPositiveLengthMeasure getInnerRadius() const;
        virtual void setInnerRadius(IfcPositiveLengthMeasure value);
        virtual void unsetInnerRadius();
        virtual bool testInnerRadius() const;
        /// @}

        /// Attribute StartParam
        /// @{
        virtual IfcParameterValue getStartParam();
        virtual IfcParameterValue getStartParam() const;
        virtual void setStartParam(IfcParameterValue value);
        virtual void unsetStartParam();
        virtual bool testStartParam() const;
        /// @}

        /// Attribute EndParam
        /// @{
        virtual IfcParameterValue getEndParam();
        virtual IfcParameterValue getEndParam() const;
        virtual void setEndParam(IfcParameterValue value);
        virtual void unsetEndParam();
        virtual bool testEndParam() const;
        /// @}





        friend class ExpressDataSet;

    protected:

        IfcSweptDiskSolid(Step::Id id, Step::SPFData *args);
        virtual ~IfcSweptDiskSolid();

        virtual bool init();

        virtual void copy(const IfcSweptDiskSolid &obj, const CopyOp &copyop);
    };
} // namespace ifc2x3