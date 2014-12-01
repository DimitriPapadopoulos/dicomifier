/*************************************************************************
 * Dicomifier - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#ifndef _3550df6e_bf18_4ba4_be31_b937ef24bb94
#define _3550df6e_bf18_4ba4_be31_b937ef24bb94

#include "translator/fields/dicom/InStackPositionNumberDcmField.h"
#include "translator/TranslationCreatorBase.h"

namespace dicomifier
{
    
namespace translator
{

namespace factory
{
    
class InStackPositionNumberDcmFieldCreator : public TranslationCreatorBase
{
public:
    typedef InStackPositionNumberDcmFieldCreator Self;
    typedef std::shared_ptr<Self> Pointer;
    typedef std::shared_ptr<Self const> ConstPointer;
    
    static Pointer New() { return Pointer(new Self()); }
    
    virtual ~InStackPositionNumberDcmFieldCreator();

    virtual Tag::Pointer Create(boost::property_tree::ptree::value_type & value,
                                DcmDataset* dataset,
                                DcmEVR evr);

    static std::string get_class_name() { return "InStackPositionNumberDcmField"; }
    
protected:
    InStackPositionNumberDcmFieldCreator();

private:
    InStackPositionNumberDcmFieldCreator(Self const & other); // Purposely not implemented
    Self const & operator=(Self const & other); // Purposely not implemented

    struct TranslatorInStackPositionNumberDcmFieldCreator
    {
        mutable dicomifier::translator::Tag::Pointer instackpositionnumber;
        template<DcmEVR VR> void run() const;
    };

};

} // namespace factory
    
} // namespace translator
    
} // namespace dicomifier

#endif // _3550df6e_bf18_4ba4_be31_b937ef24bb94