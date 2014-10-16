/*************************************************************************
 * Dicomifier - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#ifndef _c57f6173_0a11_460c_af8b_4000fb230c70
#define _c57f6173_0a11_460c_af8b_4000fb230c70

#include "translator/SubTag.h"

namespace dicomifier
{
    
namespace translator
{
    
template<DcmEVR VR>
class InPlanePhaseEncodingDirectionDcmField : public SubTag<VR>
{
public:
    typedef InPlanePhaseEncodingDirectionDcmField Self;
    typedef std::shared_ptr<Self> Pointer;
    typedef std::shared_ptr<Self const> ConstPointer;
    
    /// Create pointer to new instance of InPlanePhaseEncodingDirectionDcmField
    static Pointer New();
    
    static Pointer New(Tag::Pointer tag);
    
    virtual ~InPlanePhaseEncodingDirectionDcmField();
                     
    virtual void run(dicomifier::bruker::BrukerDataset* brukerdataset,
                     dicomifier::FrameIndexGenerator const & generator,
                     DcmItem* dataset);
    
    virtual ClassType get_class_type() const 
            { return ECT_InPlanePhaseEncodingDirectionDcmField; }
    
protected:
    InPlanePhaseEncodingDirectionDcmField();
    
    InPlanePhaseEncodingDirectionDcmField(Tag::Pointer tag);

private:
    Tag::Pointer _tag;

};
    
} // namespace dicomifier

} // namespace translator

#include "InPlanePhaseEncodingDirectionDcmField.txx"

#endif // _c57f6173_0a11_460c_af8b_4000fb230c70