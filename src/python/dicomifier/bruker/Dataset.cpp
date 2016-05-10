/*************************************************************************
 * Dicomifier - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "bruker/Dataset.h"

void wrap_Dataset()
{
    using namespace boost::python;
    using namespace dicomifier::bruker;
    
    class_<Dataset>("Dataset", init<>())
        .def("load", &Dataset::load)
        .def("has_field", &Dataset::has_field)
        .def(
            "get_field", &Dataset::get_field,
            return_value_policy<copy_const_reference>())
    ;
}
