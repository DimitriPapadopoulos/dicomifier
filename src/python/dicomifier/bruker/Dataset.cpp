/*************************************************************************
 * Dicomifier - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#include "Dataset.h"

#include <fstream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

#include <boost/regex.hpp>

#include "dicomifier/bruker/Field.h"
#include "dicomifier/bruker/grammar.h"
#include "dicomifier/Exception.h"

namespace dicomifier
{
    
namespace bruker
{

void
Dataset
::load(std::string const & path)
{
    // Read the file
    std::ifstream stream(path);
    if(stream.fail())
    {
        throw Exception("Could not open file: " + path);
    }
    this->_used_files.push_back(path);
    std::string data(
        (std::istreambuf_iterator<typename std::string::value_type>(stream)),
        (std::istreambuf_iterator<typename std::string::value_type>()));
    stream.close();

    // Join multi-line elements
    data = boost::regex_replace(data, boost::regex(R"(\\?\R(?!##|\$\$))"), "");
    
    // Parse the data
    this->_load(data.begin(), data.end());
}

void
Dataset
::loads(std::string const & data)
{
    // Join multi-line elements
    auto const joined_data = boost::regex_replace(
        data, boost::regex(R"(\\?\R(?!##|\$\$))"), "");
    
    // Parse the data
    this->_load(joined_data.begin(), joined_data.end());
}

std::vector<std::string> const &
Dataset
::get_used_files() const
{
    return this->_used_files;
}

bool
Dataset
::has_field(std::string const & name) const
{
    auto const field_it = this->_fields.find(name);
    return (field_it != this->_fields.end());
}

Field const &
Dataset
::get_field(std::string const & name) const
{
    auto const field_it = this->_fields.find(name);
    if(field_it == this->_fields.end())
    {
        throw Exception("No such field: "+name);
    }
    
    return field_it->second;
}

void
Dataset
::set_field(Field const & field)
{
    this->_fields[field.name] = field;
}

std::size_t
Dataset
::size() const
{
    return this->_fields.size();
}

void
Dataset
::_load(std::string::const_iterator begin, std::string::const_iterator end)
{
    std::vector<Field> fields;
    grammar<std::string::const_iterator> g;
    bool const parsed = boost::spirit::qi::parse(begin, end, g, fields);
    
    if(!parsed)
    {
        throw Exception("Could not parse file");
    }
    
    if(begin != end)
    {
        throw Exception("File was parsed incompletely");
    }

    // Fill the fields map
    for(auto & field: fields)
    {
        if(field.name[0] == '$')
        {
            field.name = field.name.substr(1);
        }
        this->set_field(field);
    }
}

} // namespace bruker

} // namespace dicomifier
