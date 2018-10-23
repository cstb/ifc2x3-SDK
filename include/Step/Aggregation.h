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

#pragma once


#include <Step/SimpleTypes.h>


namespace Step {

    /*!
     ** \short C++ base class for EXPRESS aggregations
     */
    template<class T, Integer _lo, Integer _hi>
    class Aggregation
    {
    public:
        Aggregation() {}
        virtual ~Aggregation() {}

        Integer lowerBound() const { return _lo;}
        Integer higherBound() const { return _hi;}

        virtual bool isUnset() const = 0;
    };

}
