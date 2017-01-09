#include <stdlib.h>
#include <stdio.h>

#include "tn93.h"

double computeTN93 (const char * s1, const char * s2,  const unsigned long L, const char matchMode, const long min_overlap) {

  const unsigned char alphabet[] = "ACGTURYSWKMBDHVN?-";
  unsigned long map_char[256];
  for(int i=0;i<=17;i++){
    map_char[alphabet[i]] = i;
  }

  const long   resolutions [][4] = { {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1},
    {0,0,0,1}, // U - 4
    {1,0,1,0}, //RESOLVE_A | RESOLVE_G, // R - 5
    {0,1,0,1}, //RESOLVE_C | RESOLVE_T, // Y - 6
    {0,1,1,0}, //RESOLVE_C | RESOLVE_G, // S - 7
    {1,0,0,1}, //RESOLVE_A | RESOLVE_T, // W - 8
    {0,0,1,1}, //RESOLVE_G | RESOLVE_T, // K - 9
    {1,1,0,0}, //RESOLVE_A | RESOLVE_C, // M - 10
    {0,1,1,1}, // RESOLVE_C | RESOLVE_G | RESOLVE_T, // B - 11
    {1,0,1,1}, //RESOLVE_A | RESOLVE_G | RESOLVE_T, // D - 12
    {1,1,0,1}, //RESOLVE_A | RESOLVE_C | RESOLVE_T, // H - 13
    {1,1,1,0}, // RESOLVE_A | RESOLVE_C | RESOLVE_G, // V - 14
    {1,1,1,1}, // RESOLVE_A | RESOLVE_C | RESOLVE_G | RESOLVE_T , // N - 15
    {1,1,1,1}, //RESOLVE_A | RESOLVE_C | RESOLVE_G | RESOLVE_T , // ? - 16
    {0,0,0,0} // GAP
  };

  const  double   resolutionsCount[] = { 1.f,
    1.f,
    1.f,
    1.f,
    1.f,
    1./2.f, // R
    1./2.f, // Y
    1./2.f, // S
    1./2.f, // S
    1./2.f, // W
    1./2.f, // K
    1./2.f, // M
    1./3.f, // B
    1./3.f, // D
    1./3.f, // H
    1./3.f, // V
    1./4.f, // N
    1./4.f, // ?
    0.f
  };

  char useK2P   = 0;
  unsigned long ambig_count = 0UL;
  long aux1;

  double dist,
  auxd,
  nucFreq[4]		= {0.,0.,0.,0.},
  fY,
  fR,
  K1,
  K2,
  K3,
  AG,
  CT,
  ti,
  tv,
  totalNonGap	= 0.,
  nucF[4],
  pairwiseCounts [4][4];

  for (unsigned long i = 0; i < 4UL; i++)
    for (unsigned long j = 0; j < 4UL; j++)
      pairwiseCounts[i][j] = 0.;

    for (unsigned long p = 0; p < L; p++) {
      unsigned long c1 = map_char[(unsigned char)s1[p]], c2 = map_char[(unsigned char)s2[p]];

      if (c1 < 4UL && c2 < 4UL) {
        pairwiseCounts [c1][c2] += 1.;
      } else { // not both resolved
        if (c1 == GAP || c2 == GAP) {
          if (matchMode != GAPMM) {
            continue;
          } else {
            if (c1 == GAP && c2 == GAP)
              continue;
            else {
              if (c1 == GAP) {
                c1 = N_CHAR;
              } else {
                c2 = N_CHAR;
              }
            }
          }
        }


                if (c1 < 4UL) { // c1 resolved and c2 is not
                  if (matchMode != SKIP) {
                    if (resolutionsCount[c2] > 0.) {
                      if (matchMode == RESOLVE || matchMode == SUBSET)
                        if (resolutions[c2][c1]) {
                          ambig_count ++;
                          pairwiseCounts[c1][c1] += 1.;
                          continue;
                        }

                      if (resolutions[c2][0])
                        pairwiseCounts[c1][0] += resolutionsCount[c2];
                      if (resolutions[c2][1])
                        pairwiseCounts[c1][1] += resolutionsCount[c2];
                      if (resolutions[c2][2])
                        pairwiseCounts[c1][2] += resolutionsCount[c2];
                      if (resolutions[c2][3])
                        pairwiseCounts[c1][3] += resolutionsCount[c2];
                    }
                  }
                }
                else {
                  if (matchMode != SKIP) {
                    if (c2 < 4UL) { // c2 resolved an c1 is not
                      if (resolutionsCount[c1] > 0.) {
                        if (matchMode == RESOLVE || matchMode == SUBSET) {
                          if (resolutions[c1][c2]) {
                            ambig_count ++;
                            pairwiseCounts[c2][c2] += 1.;
                            continue;
                          }
                        }

                        if (resolutions[c1][0])
                          pairwiseCounts[0][c2] += resolutionsCount[c1];
                        if (resolutions[c1][1])
                          pairwiseCounts[1][c2] += resolutionsCount[c1];
                        if (resolutions[c1][2])
                          pairwiseCounts[2][c2] += resolutionsCount[c1];
                        if (resolutions[c1][3])
                          pairwiseCounts[3][c2] += resolutionsCount[c1];
                      }
                    } else {
                      // ambig and ambig
                      double norm = resolutionsCount[c1] * resolutionsCount[c2];
                      //cout << int(c1) << ":" << int(c2) << "/" << norm << endl;
                      if (norm > 0.0) {
                        if (matchMode == RESOLVE || matchMode == SUBSET) {
                          ambig_count ++;
                          long matched_count = 0L,
                          positive_match [4] = {0,0,0,0};
                          for (long i = 0; i < 4L; i ++) {
                            if (resolutions[c1][i] && resolutions[c2][i]) {
                              matched_count ++;
                              positive_match[i] = 1;
                            }
                          }

                          if (matched_count > 0L) {
                            double norm2 = 1./matched_count;

                            for (long i = 0; i < 4L; i ++) {
                              if (positive_match[i]) {
                                pairwiseCounts[i][i] += norm2;
                              }
                            }
                            continue;
                          }
                        }

                        for (long i = 0; i < 4L; i ++) {
                          if (resolutions[c1][i]) {
                            for (long j = 0; j < 4L; j ++) {
                              if (resolutions [c2][j]) {
                                pairwiseCounts[i][j] += norm;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }

      }
    }



  for (unsigned long c1 = 0; c1 < 4; c1++) {
    for (unsigned long c2 = 0; c2 < 4; c2++) {
      double pc = pairwiseCounts[c1][c2];
      totalNonGap   += pc;
      nucFreq [c1]  += pc;
      nucFreq [c2]  += pc;
    }
  }

  if (totalNonGap <= min_overlap) {
    printf("totalNonGap = %f\n",totalNonGap);
    return -1.;
  }

  totalNonGap = 2./(nucFreq[0] + nucFreq[1] + nucFreq[2] + nucFreq[3]);

  auxd = 1./(nucFreq[0] + nucFreq[1] + nucFreq[2] + nucFreq[3]);
  for (aux1 = 0; aux1 < 4; aux1++)
    nucF[aux1] = nucFreq[aux1]*auxd;

  fR = nucF[0]+nucF[2];
  fY = nucF[1]+nucF[3];

  if (nucFreq[0] == 0 || nucFreq[1] == 0 || nucFreq[2] == 0 || nucFreq[3] == 0)
    useK2P = 1;
  else
      {
    K1 = 2.*nucF[0]*nucF[2]/fR;
    K2 = 2.*nucF[1]*nucF[3]/fY;
    K3 = 2.*(fR*fY - nucF[0]*nucF[2]*fY/fR - nucF[1]*nucF[3]*fR/fY);
      }

  AG = (pairwiseCounts[0][2] + pairwiseCounts[2][0])*totalNonGap;
  CT = (pairwiseCounts[1][3] + pairwiseCounts[3][1])*totalNonGap;
  tv = 1.-((pairwiseCounts[0][0] + pairwiseCounts[1][1] + pairwiseCounts[2][2] + pairwiseCounts[3][3])*totalNonGap +
           AG+CT);


  if (useK2P)
      {
    ti = AG+CT;
    AG = 1.-2.*ti-tv;
    CT = 1.-2.*tv;
    if (AG > 0. && CT > 0.)
      dist = -0.5*log(AG)-0.25*log(CT);
    else
      dist = TN93_MAX_DIST;
      }
  else
      {
    AG	= 1.-AG/K1 - 0.5*tv/fR;
    CT	= 1.-CT/K2 - 0.5*tv/fY;
    tv  = 1.-0.5 * tv/fY/fR;
    if (AG > 0. && CT > 0. && tv > 0)
      dist = - K1*log(AG) - K2*log(CT) - K3 * log (tv);
    else
      dist = TN93_MAX_DIST;
      }


  return dist <= 0. ? 0. : dist; // this is to avoid returning -0
}
