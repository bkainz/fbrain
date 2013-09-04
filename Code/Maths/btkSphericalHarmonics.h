/*==========================================================================

  © Université de Strasbourg - Centre National de la Recherche Scientifique

  Date: 12/02/2010
  Author(s): Julien Pontabry (pontabry@unistra.fr)

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


#ifndef BTK_SPHERICAL_HARMONICS_H
#define BTK_SPHERICAL_HARMONICS_H

// STL includes
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

// Local includes
#include "btkSphericalDirection.h"

#if WIN32
		static const double m_CoefficientOrder0 = 0.282094791773878;
		static const double m_CoefficientOrder2 = 0.630783130505040;
		static const double m_CoefficientOrder4 = 0.846284375321634;
		static const double m_CoefficientOrder6 = 1.01710723628205;
		static const double m_CoefficientOrder8 = 1.16310662292032;
#endif


namespace btk
{

/**
 * @brief Spherical harmonics mathematics implementation
 * @author Julien Pontabry
 * @ingroup Maths
 */
class SphericalHarmonics
{
    public:
        /**
         * @brief Compute SH basis
         * Compute spherical harmonic basis in direction, order and degree given
         * @param u Direction of basis
         * @param l Order of spherical harmonic
         * @param m Degree of spherical harmonic
         * @return Spherical harmonic basis' coefficient
         */
        static double ComputeBasis(btk::SphericalDirection u, unsigned int l, int m);

#ifndef WIN32
    private:
        static const double m_CoefficientOrder0 = 0.282094791773878;
        static const double m_CoefficientOrder2 = 0.630783130505040;
        static const double m_CoefficientOrder4 = 0.846284375321634;
        static const double m_CoefficientOrder6 = 1.01710723628205;
        static const double m_CoefficientOrder8 = 1.16310662292032;
#endif
};

} // namespace btk

#endif // BTK_SPHERICAL_HARMONICS_H

