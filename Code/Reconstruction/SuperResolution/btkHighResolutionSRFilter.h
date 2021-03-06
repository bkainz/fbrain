/*==========================================================================

  © Université de Strasbourg - Centre National de la Recherche Scientifique

  Date: 22/03/2012
  Author(s): Schweitzer Marc (marc.schweitzer@unistra.fr)

  This software is governed by the CeCILL-B license under French law and
  abiding by the rules of distribution of free software.  You can  use,
  modify and/ or redistribute the software under the terms of the CeCILL-B
  license as circulated by CEA, CNRS and INRIA at the following URL
  "http://www.cecill.info".

  As a counterpart to the access to the source code and  rights to copy,
  modify and redistribute granted by the license, users are provided only
  with a limited warranty  and the software's author,  the holder of the
  economic rights,  and the successive licensors  have only  limited
  liability.

  In this respect, the user's attention is drawn to the risks associated
  with loading,  using,  modifying and/or developing or reproducing the
  software by the user in light of its specific status of free software,
  that may mean  that it is complicated to manipulate,  and  that  also
  therefore means  that it is reserved for developers  and  experienced
  professionals having in-depth computer knowledge. Users are therefore
  encouraged to load and test the software's suitability as regards their
  requirements in conditions enabling the security of their systems and/or
  data to be ensured and,  more generally, to use and operate it in the
  same conditions as regards security.

  The fact that you are presently reading this means that you have had
  knowledge of the CeCILL-B license and that you accept its terms.

==========================================================================*/
#ifndef __BTK_HIGHRESOLUTIONSRFILTER_H__
#define __BTK_HIGHRESOLUTIONSRFILTER_H__

/* ITK */
#include "itkImage.h"
#include "itkImageMaskSpatialObject.h"
#include "itkIdentityTransform.h"
#include "itkTransformFactory.h"
#include "itkAffineTransform.h"
#include "itkEuler3DTransform.h"

/* BTK */
#include "btkMacro.h"
#include "btkHighResolutionReconstructionFilter.h"
#include "btkSuperResolutionType.h"
#include "btkSuperResolutionRigidImageFilter.h"
#include "btkSuperResolutionAffineImageFilter.h"
#include "btkNLMTool.h"
#include "btkImageHelper.h"

/* OTHERS */
#include "iostream"

namespace btk
{
/**
 * @class HighResolutionSRFilter
 * @brief The HighResolutionSRFilter class
 * @author Marc Schweitzer
 * @ingroup SuperResolution
 * @warning This class may be useless...
 */
class HighResolutionSRFilter : public HighResolutionReconstructionFilter
{


public:

    typedef btk::HighResolutionReconstructionFilter     SuperClass;

    //typedef btk::SuperResolutionRigidImageFilter< itkImage, itkImage, itkEulerTransform >   Resampler;


    HighResolutionSRFilter();
    ~HighResolutionSRFilter();

    virtual void Update();

    btkSetMacro(Lambda,float);
    btkGetMacro(Lambda,float);

    btkSetMacro(Iter,unsigned int);
    btkGetMacro(Iter, unsigned int);




protected:
    virtual void Initialize();
    virtual void DoAffineReconstruction();
    virtual void DoRigidReconstruction();
private:

   //Resampler::Pointer  m_Resampler;
    NLMTool<float>*   m_NlmTools;

    float               m_Lambda;
    unsigned int        m_Iter;
    bool                m_UseAffineFilter;
    bool                m_UseEulerFilter;
    bool                m_UseSliceBySlice;






};
}


#endif
