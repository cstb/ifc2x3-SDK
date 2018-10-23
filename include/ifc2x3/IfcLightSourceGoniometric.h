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

#include <ifc2x3/IfcLightSource.h>

namespace ifc2x3
{


    /**
     * Generated class for the IfcLightSourceGoniometric Entity.
     *
     */
    class IFC2X3_EXPORT IfcLightSourceGoniometric : public IfcLightSource
    {

        // Attributes
        Step::RefPtr< IfcAxis2Placement3D > m_Position;
        Step::RefPtr< IfcColourRgb > m_ColourAppearance;
        IfcThermodynamicTemperatureMeasure m_ColourTemperature;
        IfcLuminousFluxMeasure m_LuminousFlux;
        IfcLightEmissionSourceEnum m_LightEmissionSource;
        Step::RefPtr< IfcLightDistributionDataSourceSelect > m_LightDistributionDataSource;

        ClassType_definitions()

    public:
        virtual bool acceptVisitor(Step::BaseVisitor *visitor);

        /// Attribute Position
        /// @{
        virtual IfcAxis2Placement3D *getPosition();
        virtual const IfcAxis2Placement3D *getPosition() const;
        virtual void setPosition(const Step::RefPtr< IfcAxis2Placement3D > &value);
        virtual void unsetPosition();
        virtual bool testPosition() const;
        /// @}

        /// Attribute ColourAppearance
        /// @{
        virtual IfcColourRgb *getColourAppearance();
        virtual const IfcColourRgb *getColourAppearance() const;
        virtual void setColourAppearance(const Step::RefPtr< IfcColourRgb > &value);
        virtual void unsetColourAppearance();
        virtual bool testColourAppearance() const;
        /// @}

        /// Attribute ColourTemperature
        /// @{
        virtual IfcThermodynamicTemperatureMeasure getColourTemperature();
        virtual IfcThermodynamicTemperatureMeasure getColourTemperature() const;
        virtual void setColourTemperature(IfcThermodynamicTemperatureMeasure value);
        virtual void unsetColourTemperature();
        virtual bool testColourTemperature() const;
        /// @}

        /// Attribute LuminousFlux
        /// @{
        virtual IfcLuminousFluxMeasure getLuminousFlux();
        virtual IfcLuminousFluxMeasure getLuminousFlux() const;
        virtual void setLuminousFlux(IfcLuminousFluxMeasure value);
        virtual void unsetLuminousFlux();
        virtual bool testLuminousFlux() const;
        /// @}

        /// Attribute LightEmissionSource
        /// @{
        virtual IfcLightEmissionSourceEnum getLightEmissionSource();
        virtual IfcLightEmissionSourceEnum getLightEmissionSource() const;
        virtual void setLightEmissionSource(IfcLightEmissionSourceEnum value);
        virtual void unsetLightEmissionSource();
        virtual bool testLightEmissionSource() const;
        /// @}

        /// Attribute LightDistributionDataSource
        /// @{
        virtual IfcLightDistributionDataSourceSelect *getLightDistributionDataSource();
        virtual const IfcLightDistributionDataSourceSelect *getLightDistributionDataSource() const;
        virtual void setLightDistributionDataSource(const Step::RefPtr< IfcLightDistributionDataSourceSelect > &value);
        virtual void unsetLightDistributionDataSource();
        virtual bool testLightDistributionDataSource() const;
        /// @}





        friend class ExpressDataSet;

    protected:

        IfcLightSourceGoniometric(Step::Id id, Step::SPFData *args);
        virtual ~IfcLightSourceGoniometric();

        virtual bool init();

        virtual void copy(const IfcLightSourceGoniometric &obj, const CopyOp &copyop);
    };
} // namespace ifc2x3