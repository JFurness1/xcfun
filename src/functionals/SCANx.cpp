#include "SCAN_like_eps.hpp"
#include "constants.hpp"
#include "functional.hpp"

template <class num> static num SCANX(const densvars<num> & d) {
  num Fx_a;
  num Fx_b;
  Fx_a = SCAN_eps::get_SCAN_Fx(2.0 * d.a, 4.0 * d.gaa, 2.0 * d.taua, 0, 0, 0);
  num epsxunif_a = SCAN_eps::fx_unif(2 * d.a);
  Fx_b = SCAN_eps::get_SCAN_Fx(2.0 * d.b, 4.0 * d.gbb, 2.0 * d.taub, 0, 0, 0);
  num epsxunif_b = SCAN_eps::fx_unif(2 * d.b);

  return 0.5 * (Fx_a * epsxunif_a + Fx_b * epsxunif_b);
}

FUNCTIONAL(XC_SCANX) = {
    "SCAN exchange functional",
    "SCAN exchange functional.\n"
    "Strongly constrained and appropriately normed functional\n"
    "J. Sun, A. Ruzsinszky, and J. P. Perdew, Phys. Rev. Lett. 115, 036402 (2015)."
    "Implemented by James Furness (@JFurness1)\n",
    XC_DENSITY | XC_GRADIENT | XC_KINETIC,
    ENERGY_FUNCTION(SCANX) XC_A_B_GAA_GAB_GBB_TAUA_TAUB,
    XC_PARTIAL_DERIVATIVES,
    1,
    1e-11,
    {0.217, 0.0632, 0.191, 0.0535, 0.015, 0.267, 0.0328},
    {-1.62177290711e-01,
     -8.67282272330e-01,
     -5.58386982606e-01,
     -4.08961346066e-02,
     0.00000000000e+00,
     -9.83984390668e-02,
     6.55853126427e-02,
     5.18444044761e-02}};
