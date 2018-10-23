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

#include <ifc2x3/IfcPropertySetDefinition.h>

namespace ifc2x3
{


    /**
     * Generated class for the IfcSoundProperties Entity.
     *
     */
    class IFC2X3_EXPORT IfcSoundProperties : public IfcPropertySetDefinition
    {

        // Attributes
        IfcBoolean m_IsAttenuating;
        IfcSoundScaleEnum m_SoundScale;
        List_IfcSoundValue_1_8 m_SoundValues;

        ClassType_definitions()

    public:
        virtual bool acceptVisitor(Step::BaseVisitor *visitor);

        /// Attribute IsAttenuating
        /// @{
        virtual IfcBoolean getIsAttenuating();
        virtual IfcBoolean getIsAttenuating() const;
        virtual void setIsAttenuating(IfcBoolean value);
        virtual void unsetIsAttenuating();
        virtual bool testIsAttenuating() const;
        /// @}

        /// Attribute SoundScale
        /// @{
        virtual IfcSoundScaleEnum getSoundScale();
        virtual IfcSoundScaleEnum getSoundScale() const;
        virtual void setSoundScale(IfcSoundScaleEnum value);
        virtual void unsetSoundScale();
        virtual bool testSoundScale() const;
        /// @}

        /// Attribute SoundValues
        /// @{
        virtual List_IfcSoundValue_1_8 &getSoundValues();
        virtual const List_IfcSoundValue_1_8 &getSoundValues() const;
        virtual void setSoundValues(const List_IfcSoundValue_1_8 &value);
        virtual void unsetSoundValues();
        virtual bool testSoundValues() const;
        /// @}





        friend class ExpressDataSet;

    protected:

        IfcSoundProperties(Step::Id id, Step::SPFData *args);
        virtual ~IfcSoundProperties();

        virtual bool init();

        virtual void copy(const IfcSoundProperties &obj, const CopyOp &copyop);
    };
} // namespace ifc2x3