//-*****************************************************************************
//
// Copyright (c) 2014,
//
// All rights reserved.
//
//-*****************************************************************************

#ifndef _Alembic_AbcCoreGit_SpwImpl_h_
#define _Alembic_AbcCoreGit_SpwImpl_h_

#include <Alembic/AbcCoreGit/Foundation.h>
//#include <Alembic/AbcCoreGit/WrittenSampleMap.h>
#include <Alembic/AbcCoreGit/Git.h>

namespace Alembic {
namespace AbcCoreGit {
namespace ALEMBIC_VERSION_NS {

//-*****************************************************************************
// Scalar Property Writer.
class SpwImpl
    : public AbcA::ScalarPropertyWriter
    , public Alembic::Util::enable_shared_from_this<SpwImpl>
{
protected:
    friend class CpwData;

    //-*************************************************************************
    SpwImpl( AbcA::CompoundPropertyWriterPtr iParent,
             GitGroupPtr iGroup,
             PropertyHeaderPtr iHeader,
             size_t iIndex );

    AbcA::ScalarPropertyWriterPtr asScalarPtr();

public:
    virtual ~SpwImpl();

    // ScalarPropertyWriter overrides
    virtual void setSample( const void *iSamp );
    virtual void setFromPreviousSample();
    virtual size_t getNumSamples();
    virtual void setTimeSamplingIndex( Util::uint32_t iIndex );

    // BasePropertyWriter overrides
    virtual const AbcA::PropertyHeader & getHeader() const;
    virtual AbcA::ObjectWriterPtr getObject();
    virtual AbcA::CompoundPropertyWriterPtr getParent();

protected:
    // Previous written array sample identifier!
    //WrittenSampleIDPtr m_previousWrittenSampleID;

private:
    // The parent compound property writer.
    AbcA::CompoundPropertyWriterPtr m_parent;

    // The header which defines this property.
    // And extra data the parent needs to eventually write out
    PropertyHeaderPtr m_header;

    // for accumulating our hierarchical hash
    Util::Digest m_hash;

    GitGroupPtr m_group;

    size_t m_index;
};

} // End namespace ALEMBIC_VERSION_NS

using namespace ALEMBIC_VERSION_NS;

} // End namespace AbcCoreGit
} // End namespace Alembic

#endif