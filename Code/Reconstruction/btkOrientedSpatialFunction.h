/*==========================================================================

  © Université de Strasbourg - Centre National de la Recherche Scientifique

  Date: 26/11/2010
  Author(s): Estanislao Oubel (oubel@unistra.fr)

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


#ifndef __btkOrientedSpatialFunction_h
#define __btkOrientedSpatialFunction_h

#include "itkSpatialFunction.h"
#include "itkFixedArray.h"
#include "itkPoint.h"
#include "itkMatrix.h"
#include "itkVector.h"
#include "itkGaussianSpatialFunction.h"
#include "itkFixedArray.h"

namespace btk
{

using namespace itk;

/** \class OrientedSpatialFunction
 * \brief N-dimensional oriented spatial function class
 *
 * This class implements a function oriented in a specific direction. This is
 * used to have the PSF in the correct orientation in world coordinates.
 *
 * \ingroup SpatialFunctions
 */
template <typename TOutput=double,
          unsigned int VImageDimension=3,
          typename TInput=Point<double, VImageDimension> >
class OrientedSpatialFunction
: public SpatialFunction<TOutput, VImageDimension, TInput>
{
public:

  typedef enum {
    BOXCAR=0,
    GAUSSIAN=1,
  } PSF_type;

  /** Standard class typedefs. */
  typedef OrientedSpatialFunction                                 Self;
  typedef SpatialFunction<TOutput, VImageDimension, TInput>       Superclass;
  typedef SmartPointer<Self>                                      Pointer;
  typedef SmartPointer<const Self>                                ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(OrientedSpatialFunction, SpatialFunction);

  /** Input type for the function. */
  typedef typename Superclass::InputType InputType;

  /** Output type for the function. */
  typedef typename Superclass::OutputType OutputType;

  /** Direction type. */
  typedef Matrix<double,VImageDimension,VImageDimension>  DirectionType;

  /** Point type */
  typedef Point<double,VImageDimension>  PointType;

  /** Spacing type */
  typedef Vector<double,VImageDimension>  SpacingType;

  /** Gaussian function type */
  typedef GaussianSpatialFunction< double,
                                   VImageDimension,
                                   PointType> GaussianFunctionType;

  /** Array type */
  typedef FixedArray<double,VImageDimension> ArrayType;


  /** Function value */
  OutputType Evaluate(const TInput& position) const;

  /** Sets spacing. This method changes the standard deviations of the Gaussian
   * function accordingly. */
  void SetSpacing(SpacingType spacing)
  {
    m_Spacing = spacing.GetVnlVector();

    ArrayType sigma;

    sigma[0] = sqrt(m_Spacing[0]*m_Spacing[0]/(8*log(2.0)));
    sigma[1] = sqrt(m_Spacing[1]*m_Spacing[1]/(8*log(2.0)));
    sigma[2] = sqrt(m_Spacing[2]*m_Spacing[2]/(8*log(2.0)));

    m_Gaussian -> SetSigma( sigma );

  }

  /** Sets direction of the PSF. */
  void SetDirection(DirectionType direction)
  {
    m_Direction = direction.GetVnlMatrix();
    m_idir = m_Direction.get_column(0);
    m_jdir = m_Direction.get_column(1);
    m_kdir = m_Direction.get_column(2);
  }

  /** Sets the position of the PSF. */
  void SetCenter(PointType center)
  {
    m_Center = center.GetVnlVector();
  }

  /** Sets the type of PSF (Boxcar, Gaussian). */
  itkSetMacro(PSF, unsigned int);

  /** Gets the type of PSF (Boxcar, Gaussian). */
  itkGetMacro(PSF, unsigned int);


protected:
  OrientedSpatialFunction();
  virtual ~OrientedSpatialFunction();
  void PrintSelf(std::ostream& os, Indent indent) const;

private:
  OrientedSpatialFunction(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  vnl_matrix<double> m_Direction;
  vnl_vector<double> m_Center;
  vnl_vector<double> m_Spacing;

  vnl_vector<double> m_idir;
  vnl_vector<double> m_jdir;
  vnl_vector<double> m_kdir;

  unsigned int m_PSF;

  typename GaussianFunctionType::Pointer m_Gaussian;


};

} // end namespace itk


// Define instantiation macro for this template.
#define ITK_TEMPLATE_OrientedSpatialFunction(_, EXPORT, x, y) namespace itk { \
  _(3(class EXPORT OrientedSpatialFunction< ITK_TEMPLATE_3 x >)) \
  namespace Templates { typedef OrientedSpatialFunction< ITK_TEMPLATE_3 x >\
                                                 OrientedSpatialFunction##y; } \
  }

#if ITK_TEMPLATE_EXPLICIT
# include "Templates/itkOrientedSpatialFunction+-.h"
#endif

#if ITK_TEMPLATE_TXX
# include "btkOrientedSpatialFunction.txx"
#endif

#endif
