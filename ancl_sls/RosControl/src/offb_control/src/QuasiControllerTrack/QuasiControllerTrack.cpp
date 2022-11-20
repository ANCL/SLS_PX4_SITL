//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: QuasiControllerTrack.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 25-Sep-2022 17:06:46
//

// Include Files
#include "QuasiControllerTrack.h"
#include "mldivide.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Declarations
static double rt_powd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = std::abs(u0);
    d1 = std::abs(u1);
    if (std::isinf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

//
// m=1.6;mp=0.16;L=1;
//
// Arguments    : const double x[16]
//                double t
//                const double Kv2[2]
//                const double Kv6[6]
//                const double M[7]
//                const double TParam[4]
//                double controller_output[4]
// Return Type  : void
//
void QuasiControllerTrack(const double x[16], double t, const double Kv2[2],
  const double Kv6[6], const double M[7], const double TParam[4], double
  controller_output[4])
{
  double yr[20];
  double Ts[16];
  double z[16];
  double Ts_tmp;
  double Ts_tmp_tmp;
  double Ts_tmp_tmp_tmp;
  double Ts_tmp_tmp_tmp_tmp;
  double a_tmp_tmp;
  double a_tmp_tmp_tmp;
  double a_tmp_tmp_tmp_tmp_tmp;
  double ab_Ts_tmp;
  double b_Ts_tmp;
  double b_Ts_tmp_tmp;
  double b_Ts_tmp_tmp_tmp;
  double b_t14_tmp;
  double b_t174_tmp;
  double b_t22_tmp;
  double b_t336_tmp;
  double b_t59_tmp;
  double b_yr_tmp;
  double bb_Ts_tmp;
  double c_Ts_tmp;
  double c_Ts_tmp_tmp;
  double c_Ts_tmp_tmp_tmp;
  double c_t22_tmp;
  double cb_Ts_tmp;
  double d_Ts_tmp;
  double d_Ts_tmp_tmp;
  double d_Ts_tmp_tmp_tmp;
  double db_Ts_tmp;
  double e_Ts_tmp;
  double e_Ts_tmp_tmp;
  double e_Ts_tmp_tmp_tmp;
  double eb_Ts_tmp;
  double f_Ts_tmp;
  double f_Ts_tmp_tmp;
  double f_Ts_tmp_tmp_tmp;
  double fb_Ts_tmp;
  double g_Ts_tmp;
  double g_Ts_tmp_tmp;
  double g_Ts_tmp_tmp_tmp;
  double gb_Ts_tmp;
  double h_Ts_tmp;
  double h_Ts_tmp_tmp;
  double h_Ts_tmp_tmp_tmp;
  double hb_Ts_tmp;
  double i_Ts_tmp;
  double i_Ts_tmp_tmp;
  double i_Ts_tmp_tmp_tmp;
  double ib_Ts_tmp;
  double j_Ts_tmp;
  double j_Ts_tmp_tmp;
  double j_Ts_tmp_tmp_tmp;
  double jb_Ts_tmp;
  double k_Ts_tmp;
  double k_Ts_tmp_tmp;
  double k_Ts_tmp_tmp_tmp;
  double kb_Ts_tmp;
  double l_Ts_tmp;
  double l_Ts_tmp_tmp;
  double l_Ts_tmp_tmp_tmp;
  double lb_Ts_tmp;
  double m_Ts_tmp;
  double m_Ts_tmp_tmp;
  double m_Ts_tmp_tmp_tmp;
  double mb_Ts_tmp;
  double n3;
  double n3p;
  double n3pp;
  double n3ppp;
  double n3pppp;
  double n3pppp_tmp;
  double n_Ts_tmp;
  double n_Ts_tmp_tmp;
  double n_Ts_tmp_tmp_tmp;
  double o_Ts_tmp;
  double o_Ts_tmp_tmp_tmp;
  double p_Ts_tmp;
  double p_Ts_tmp_tmp_tmp;
  double q_Ts_tmp;
  double q_Ts_tmp_tmp_tmp;
  double r_Ts_tmp;
  double s_Ts_tmp;
  double t10;
  double t100;
  double t101;
  double t102;
  double t103;
  double t104;
  double t105;
  double t106;
  double t107;
  double t108;
  double t109;
  double t11;
  double t111;
  double t113;
  double t116;
  double t117;
  double t118;
  double t119;
  double t12;
  double t120;
  double t121;
  double t123;
  double t125_tmp;
  double t126;
  double t127;
  double t128;
  double t129;
  double t13;
  double t130;
  double t131;
  double t132;
  double t133;
  double t133_tmp;
  double t135;
  double t135_tmp;
  double t136;
  double t137;
  double t138;
  double t139;
  double t14;
  double t140;
  double t141;
  double t141_tmp;
  double t142;
  double t143;
  double t144;
  double t145;
  double t146;
  double t147;
  double t147_tmp;
  double t148;
  double t149;
  double t14_tmp;
  double t15;
  double t150;
  double t151;
  double t152;
  double t153;
  double t154;
  double t155;
  double t156;
  double t156_tmp;
  double t157;
  double t158;
  double t159;
  double t16;
  double t160;
  double t160_tmp;
  double t161;
  double t162;
  double t163;
  double t164;
  double t165;
  double t166;
  double t167;
  double t168;
  double t169;
  double t170;
  double t171;
  double t172;
  double t173;
  double t174;
  double t174_tmp;
  double t175;
  double t176;
  double t177;
  double t178;
  double t179;
  double t17_tmp;
  double t18;
  double t180;
  double t181;
  double t182;
  double t183;
  double t184;
  double t186_tmp;
  double t187;
  double t187_tmp;
  double t188;
  double t189;
  double t190;
  double t191;
  double t192;
  double t193;
  double t194;
  double t195;
  double t196;
  double t197;
  double t198;
  double t199;
  double t20;
  double t200;
  double t201;
  double t202;
  double t203;
  double t204;
  double t205;
  double t206;
  double t207;
  double t208;
  double t209;
  double t209_tmp;
  double t21;
  double t210;
  double t211;
  double t212;
  double t212_tmp;
  double t213;
  double t214;
  double t215;
  double t218;
  double t219;
  double t22;
  double t220;
  double t221;
  double t222;
  double t223;
  double t224;
  double t225;
  double t226;
  double t227;
  double t228;
  double t229;
  double t22_tmp;
  double t23;
  double t230;
  double t231;
  double t232;
  double t233;
  double t234;
  double t235;
  double t236;
  double t237;
  double t238;
  double t239;
  double t23_tmp;
  double t24;
  double t240;
  double t241;
  double t242;
  double t243;
  double t244;
  double t245;
  double t246;
  double t247;
  double t248;
  double t249;
  double t25;
  double t250;
  double t251;
  double t252;
  double t252_tmp;
  double t253;
  double t253_tmp;
  double t254;
  double t256;
  double t257;
  double t258;
  double t259;
  double t26;
  double t260;
  double t262;
  double t263;
  double t264;
  double t265;
  double t266;
  double t267;
  double t269;
  double t27;
  double t270;
  double t271;
  double t271_tmp;
  double t272;
  double t273;
  double t274_tmp;
  double t275;
  double t276;
  double t277;
  double t278;
  double t279;
  double t28;
  double t280;
  double t281;
  double t282;
  double t283;
  double t284;
  double t284_tmp;
  double t285;
  double t286;
  double t287;
  double t288;
  double t289;
  double t29;
  double t290;
  double t291;
  double t292;
  double t293;
  double t294;
  double t295;
  double t296;
  double t297;
  double t299;
  double t300;
  double t301;
  double t302;
  double t303_tmp;
  double t304;
  double t305;
  double t306;
  double t306_tmp;
  double t307;
  double t308;
  double t309;
  double t31;
  double t310;
  double t311;
  double t312;
  double t313;
  double t314;
  double t315;
  double t316;
  double t317;
  double t318;
  double t319;
  double t32;
  double t320;
  double t321;
  double t321_tmp;
  double t323;
  double t324;
  double t325;
  double t326;
  double t327;
  double t328;
  double t33;
  double t330;
  double t331;
  double t333;
  double t334;
  double t335;
  double t336_tmp;
  double t337;
  double t339;
  double t34;
  double t340;
  double t342;
  double t343;
  double t344;
  double t345;
  double t345_tmp;
  double t346;
  double t347;
  double t349;
  double t35;
  double t350;
  double t351;
  double t352;
  double t353;
  double t354;
  double t355;
  double t356;
  double t358;
  double t36;
  double t361;
  double t362;
  double t363;
  double t364;
  double t365;
  double t366;
  double t366_tmp;
  double t367;
  double t368;
  double t369;
  double t37;
  double t370;
  double t371;
  double t372;
  double t373;
  double t374;
  double t375;
  double t376;
  double t377;
  double t378;
  double t378_tmp;
  double t379;
  double t38;
  double t380;
  double t381;
  double t382;
  double t383;
  double t385;
  double t386;
  double t387;
  double t387_tmp;
  double t388;
  double t389;
  double t390;
  double t391;
  double t392;
  double t394;
  double t395;
  double t396;
  double t396_tmp;
  double t397;
  double t398;
  double t399;
  double t40;
  double t400;
  double t401;
  double t402;
  double t403;
  double t404;
  double t405;
  double t407;
  double t408;
  double t409;
  double t41;
  double t410;
  double t411;
  double t413;
  double t413_tmp;
  double t416;
  double t417;
  double t418;
  double t419;
  double t42;
  double t420_tmp;
  double t421;
  double t422;
  double t423;
  double t425;
  double t426;
  double t427;
  double t43;
  double t430;
  double t432;
  double t433;
  double t434;
  double t435;
  double t436;
  double t437;
  double t438;
  double t439;
  double t43_tmp;
  double t44;
  double t440;
  double t443;
  double t444;
  double t446_tmp;
  double t448;
  double t449;
  double t45;
  double t450;
  double t452_tmp;
  double t453;
  double t454;
  double t455;
  double t458;
  double t46;
  double t460;
  double t462;
  double t463;
  double t464;
  double t465;
  double t467;
  double t468;
  double t469;
  double t47;
  double t470;
  double t471;
  double t472_tmp;
  double t473;
  double t475_tmp;
  double t476;
  double t477;
  double t478;
  double t47_tmp;
  double t48;
  double t480;
  double t481;
  double t482;
  double t483;
  double t485;
  double t486;
  double t487;
  double t488;
  double t489;
  double t48_tmp;
  double t49;
  double t491;
  double t492;
  double t494;
  double t495;
  double t496;
  double t498_tmp;
  double t499;
  double t50;
  double t500;
  double t502;
  double t503;
  double t504;
  double t505;
  double t506;
  double t507;
  double t508;
  double t509;
  double t51;
  double t510;
  double t511;
  double t512;
  double t513;
  double t514;
  double t515;
  double t516;
  double t517;
  double t52;
  double t520;
  double t521;
  double t523;
  double t526;
  double t528;
  double t53;
  double t532;
  double t534;
  double t537;
  double t538;
  double t539;
  double t53_tmp;
  double t54;
  double t540;
  double t541_tmp;
  double t542;
  double t548;
  double t549;
  double t55;
  double t551;
  double t553_tmp;
  double t554;
  double t556;
  double t557;
  double t558;
  double t558_tmp;
  double t559;
  double t56;
  double t565;
  double t572;
  double t574;
  double t576;
  double t577;
  double t578;
  double t58;
  double t580;
  double t582;
  double t583;
  double t584;
  double t585;
  double t586;
  double t587;
  double t589;
  double t592;
  double t593;
  double t597;
  double t599;
  double t59_tmp;
  double t6;
  double t60;
  double t600;
  double t602;
  double t603;
  double t603_tmp;
  double t604;
  double t608;
  double t60_tmp;
  double t61;
  double t610;
  double t610_tmp;
  double t618;
  double t619;
  double t62;
  double t620;
  double t620_tmp;
  double t622;
  double t623;
  double t623_tmp;
  double t624;
  double t629;
  double t63;
  double t634;
  double t635;
  double t636;
  double t637;
  double t640;
  double t641;
  double t643;
  double t645;
  double t646;
  double t65;
  double t651;
  double t654;
  double t657;
  double t658;
  double t66;
  double t660;
  double t661;
  double t662;
  double t664;
  double t665;
  double t666;
  double t67;
  double t670;
  double t671;
  double t675;
  double t676;
  double t68;
  double t681;
  double t682;
  double t683;
  double t686;
  double t69;
  double t692;
  double t699;
  double t69_tmp;
  double t6_tmp;
  double t70;
  double t701;
  double t704;
  double t705;
  double t706;
  double t707;
  double t708;
  double t709;
  double t71;
  double t710_tmp;
  double t711;
  double t712;
  double t713;
  double t717;
  double t719_tmp;
  double t72;
  double t720;
  double t721;
  double t722;
  double t725;
  double t726;
  double t728_tmp;
  double t72_tmp;
  double t73;
  double t74;
  double t75;
  double t76;
  double t77;
  double t78;
  double t79;
  double t80;
  double t81;
  double t82;
  double t83;
  double t84;
  double t87;
  double t88;
  double t89;
  double t90;
  double t91;
  double t92;
  double t93;
  double t94_tmp;
  double t95_tmp;
  double t96;
  double t97;
  double t98;
  double t99;
  double t_Ts_tmp;
  double u_Ts_tmp;
  double v_Ts_tmp;
  double w_Ts_tmp;
  double x_Ts_tmp;
  double y_Ts_tmp;
  double yr_tmp;
  t65 = 6.2831853071795862 * t / TParam[0];
  yr_tmp = std::sin(t65);
  t27 = std::cos(t65);
  t65 = 12.566370614359172 * t / TParam[0];
  b_yr_tmp = std::sin(t65);
  t65 = std::cos(t65);
  yr[0] = TParam[1] * yr_tmp;
  yr[1] = 2.0 * TParam[1] * 3.1415926535897931 / TParam[0] * t27;
  t6 = TParam[0] * TParam[0];
  yr[2] = -4.0 * TParam[1] * 9.869604401089358 / t6 * yr_tmp;
  t342 = rt_powd_snf(TParam[0], 3.0);
  yr[3] = -8.0 * TParam[1] * 31.006276680299816 / t342 * t27;
  t262 = rt_powd_snf(TParam[0], 4.0);
  yr[4] = 16.0 * TParam[1] * 97.409091034002415 / t262 * yr_tmp;
  t388 = rt_powd_snf(TParam[0], 5.0);
  yr[5] = 32.0 * TParam[1] * 306.01968478528141 / t388 * t27;
  yr[6] = TParam[2] * b_yr_tmp;
  yr[7] = 4.0 * TParam[2] * 3.1415926535897931 / TParam[0] * t65;
  yr[8] = -16.0 * TParam[2] * 9.869604401089358 / t6 * b_yr_tmp;
  yr[9] = -64.0 * TParam[2] * 31.006276680299816 / t342 * t65;
  yr[10] = 256.0 * TParam[2] * 97.409091034002415 / t262 * b_yr_tmp;
  yr[11] = 1024.0 * TParam[2] * 306.01968478528141 / t388 * t65;
  yr[12] = TParam[3] * yr_tmp + -10.0;
  yr[13] = 2.0 * TParam[3] * 3.1415926535897931 / TParam[0] * t27;
  yr[14] = -4.0 * TParam[3] * 9.869604401089358 / t6 * yr_tmp;
  yr[15] = -8.0 * TParam[3] * 31.006276680299816 / t342 * t27;
  yr[16] = 16.0 * TParam[3] * 97.409091034002415 / t262 * yr_tmp;
  yr[17] = 32.0 * TParam[3] * 306.01968478528141 / t388 * t27;
  // yr[18] = 0.02 * t;
  // yr[19] = 0.02;
  yr[18] = 0;
  yr[19] = 0;
  t65 = x[10] - yr[13];
  n3 = (yr[14] - Kv2[1] * t65) - Kv2[0] * (x[2] - yr[12]);
  t6 = n3 - yr[14];
  n3p = (yr[15] - Kv2[1] * t6) - Kv2[0] * t65;
  t65 = n3p - yr[15];
  n3pp = (yr[16] - Kv2[1] * t65) - Kv2[0] * t6;
  t6 = n3pp - yr[16];
  n3ppp = (yr[17] - Kv2[1] * t6) - Kv2[0] * t65;
  n3pppp_tmp = rt_powd_snf(TParam[0], 6.0);
  n3pppp = (-64.0 * TParam[3] * 961.38919357530426 / n3pppp_tmp * yr_tmp - Kv2[1]
            * (n3ppp - yr[17])) - Kv2[0] * t6;
  Ts_tmp_tmp = std::cos(x[4]);
  Ts_tmp_tmp_tmp = std::sin(x[4]);
  b_Ts_tmp_tmp_tmp = std::cos(x[3]);
  c_Ts_tmp_tmp_tmp = std::cos(x[7]);
  d_Ts_tmp_tmp_tmp = std::sin(x[6]);
  e_Ts_tmp_tmp_tmp = std::sin(x[3]);
  f_Ts_tmp_tmp_tmp = std::cos(x[5]);
  g_Ts_tmp_tmp_tmp = std::sin(x[5]);
  h_Ts_tmp_tmp_tmp = std::sin(x[7]);
  i_Ts_tmp_tmp_tmp = std::cos(x[6]);
  t6 = f_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  a_tmp_tmp_tmp = g_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp;
  t725 = i_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp;
  a_tmp_tmp = t725 * f_Ts_tmp_tmp_tmp;
  a_tmp_tmp_tmp_tmp_tmp = g_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp;
  t342 = t6 * c_Ts_tmp_tmp_tmp;
  t262 = t342 + a_tmp_tmp_tmp_tmp_tmp;
  t388 = Ts_tmp_tmp_tmp * t262;
  t27 = -f_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t65 = t27 * h_Ts_tmp_tmp_tmp + a_tmp_tmp_tmp;
  t174 = a_tmp_tmp + t65 * e_Ts_tmp_tmp_tmp;
  t235 = t174 * Ts_tmp_tmp + t388;
  t162 = M[3] - n3;
  t395 = t6 * h_Ts_tmp_tmp_tmp;
  t339 = t395 - a_tmp_tmp_tmp;
  t610 = t339 * e_Ts_tmp_tmp_tmp;
  t222 = (a_tmp_tmp - t610) * Ts_tmp_tmp + t388;
  a_tmp_tmp = Ts_tmp_tmp * b_Ts_tmp_tmp_tmp;
  t252 = (a_tmp_tmp * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp - t610 * Ts_tmp_tmp) +
    t388;
  Ts[0] = x[0];
  Ts[1] = x[8];
  Ts[2] = -t162 * Ts_tmp_tmp_tmp / Ts_tmp_tmp / b_Ts_tmp_tmp_tmp;
  t75 = x[12] * t162;
  Ts_tmp = b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp;
  b_Ts_tmp = Ts_tmp_tmp * Ts_tmp_tmp;
  c_Ts_tmp = e_Ts_tmp_tmp_tmp * x[11];
  Ts[3] = ((n3p * Ts_tmp_tmp * Ts_tmp_tmp_tmp - t75) * b_Ts_tmp_tmp_tmp -
           c_Ts_tmp * Ts_tmp_tmp * Ts_tmp_tmp_tmp * t162) / b_Ts_tmp / Ts_tmp;
  d_Ts_tmp = x[11] * x[12];
  b_Ts_tmp_tmp = x[11] * x[11];
  t321 = t162 * b_Ts_tmp_tmp;
  t344 = t321 + n3pp;
  t220 = rt_powd_snf(b_Ts_tmp_tmp_tmp, 3.0);
  t144 = t321 + n3pp / 2.0;
  t223 = a_tmp_tmp_tmp * x[11];
  c_Ts_tmp_tmp = x[12] * x[12];
  t234 = 0.66666666666666663 * M[3] - 0.66666666666666663 * n3;
  t260 = (t234 * b_Ts_tmp_tmp + t162 * c_Ts_tmp_tmp) + n3pp / 3.0;
  d_Ts_tmp_tmp = M[0] + M[1];
  t142 = rt_powd_snf(Ts_tmp_tmp, 3.0);
  t55 = g_Ts_tmp_tmp_tmp * t344;
  t99 = t55 * h_Ts_tmp_tmp_tmp / 2.0;
  t175 = rt_powd_snf(Ts_tmp_tmp, 4.0);
  t181 = 2.0 * M[0] * Ts_tmp_tmp_tmp * M[2];
  j_Ts_tmp_tmp_tmp = x[12] * h_Ts_tmp_tmp_tmp;
  t183 = j_Ts_tmp_tmp_tmp * t162;
  Ts_tmp_tmp_tmp_tmp = e_Ts_tmp_tmp_tmp * n3p;
  t263 = Ts_tmp_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp;
  t113 = t263 / 2.0;
  t172 = t113 + t183;
  t629 = h_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp;
  t178 = t629 * n3p;
  t179 = x[12] * (M[3] - n3) * c_Ts_tmp_tmp_tmp - t178 / 2.0;
  t203 = 2.0 * c_Ts_tmp_tmp;
  t219 = t203 * f_Ts_tmp_tmp_tmp * M[2];
  t221 = t219 * Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * M[0] * t162;
  e_Ts_tmp = t181 * x[12];
  t120 = b_Ts_tmp_tmp * e_Ts_tmp_tmp_tmp;
  t143 = t120 * t339;
  t15 = t143 * t162;
  k_Ts_tmp_tmp_tmp = 0.66666666666666663 * b_Ts_tmp_tmp;
  t51 = k_Ts_tmp_tmp_tmp * t262;
  t14 = t51 * t162;
  t16 = -2.0 * c_Ts_tmp_tmp;
  t26 = t16 * M[2] * M[0];
  t37 = t26 * t262;
  e_Ts_tmp_tmp = c_Ts_tmp_tmp * M[2];
  f_Ts_tmp_tmp = n3p * c_Ts_tmp_tmp_tmp;
  t56 = j_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp;
  t13 = t56 * t162;
  t199 = f_Ts_tmp_tmp + t13;
  t153 = d_Ts_tmp_tmp * t162;
  t413 = 4.0 * x[12] * x[11] * M[2] * Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * M[0] +
    t153;
  g_Ts_tmp_tmp = h_Ts_tmp_tmp_tmp * x[11];
  t620 = t144 * h_Ts_tmp_tmp_tmp;
  l_Ts_tmp_tmp_tmp = h_Ts_tmp_tmp_tmp * n3p;
  m_Ts_tmp_tmp_tmp = x[12] * e_Ts_tmp_tmp_tmp;
  t623 = m_Ts_tmp_tmp_tmp * t162 * c_Ts_tmp_tmp_tmp;
  t42 = t623 - l_Ts_tmp_tmp_tmp;
  t11 = g_Ts_tmp_tmp * t162;
  f_Ts_tmp = 1.3333333333333333 * x[12] * x[11];
  t636 = e_Ts_tmp_tmp * Ts_tmp_tmp_tmp;
  g_Ts_tmp = g_Ts_tmp_tmp_tmp * t144;
  t537 = 3.0 * M[0] * M[2];
  t523 = t221 * Ts_tmp;
  h_Ts_tmp = i_Ts_tmp_tmp_tmp * n3p;
  i_Ts_tmp = x[11] * i_Ts_tmp_tmp_tmp;
  j_Ts_tmp = f_Ts_tmp_tmp_tmp * Ts_tmp_tmp_tmp;
  Ts[4] = ((((2.0 * M[0] * (((d_Ts_tmp * t339 * t162 * t220 + ((-t344 *
    c_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp / 2.0 + d_Ts_tmp * i_Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp * t162) * f_Ts_tmp_tmp_tmp - t99) * Ts_tmp) - ((t263 + t183)
    * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - g_Ts_tmp_tmp_tmp * (t75 *
    c_Ts_tmp_tmp_tmp - t178)) * x[11] * b_Ts_tmp_tmp_tmp) + b_Ts_tmp_tmp * t262 *
    t162) * M[2] * t175 + t181 * (((((g_Ts_tmp_tmp * d_Ts_tmp_tmp_tmp * n3p +
    t144 * i_Ts_tmp_tmp_tmp) * f_Ts_tmp_tmp_tmp - t223 * n3p) * t220 -
    e_Ts_tmp_tmp_tmp * ((t620 * d_Ts_tmp_tmp_tmp - i_Ts_tmp * n3p) *
                        f_Ts_tmp_tmp_tmp - g_Ts_tmp * c_Ts_tmp_tmp_tmp) * Ts_tmp)
    + ((t42 * d_Ts_tmp_tmp_tmp - 1.5 * x[11] * i_Ts_tmp_tmp_tmp * t162) *
       f_Ts_tmp_tmp_tmp + g_Ts_tmp_tmp_tmp * (n3p * c_Ts_tmp_tmp_tmp +
    j_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * t162)) * x[11] * b_Ts_tmp_tmp_tmp) +
    t15) * t142) + t537 * (((-1.3333333333333333 * ((t11 * d_Ts_tmp_tmp_tmp -
    h_Ts_tmp / 2.0) * f_Ts_tmp_tmp_tmp - t223 * t162) * x[12] * t220 + (((t260 *
    c_Ts_tmp_tmp_tmp - 0.66666666666666663 * x[12] * h_Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp * n3p) * d_Ts_tmp_tmp_tmp - f_Ts_tmp * i_Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp * t162) * f_Ts_tmp_tmp_tmp + g_Ts_tmp_tmp_tmp *
    (0.66666666666666663 * x[12] * c_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * n3p +
     h_Ts_tmp_tmp_tmp * t260)) * Ts_tmp) + 1.3333333333333333 * (t172 *
    d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - g_Ts_tmp_tmp_tmp * t179) * x[11] *
    b_Ts_tmp_tmp_tmp) - t14) * b_Ts_tmp) - b_Ts_tmp_tmp_tmp * ((t523 - e_Ts_tmp *
              (t199 * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - t42 *
               g_Ts_tmp_tmp_tmp) * b_Ts_tmp_tmp_tmp) + t162 * ((c_Ts_tmp_tmp_tmp
    * (4.0 * x[12] * x[11] * M[2] * Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * M[0] +
       t153) * d_Ts_tmp_tmp_tmp + t636 * i_Ts_tmp_tmp_tmp * M[0]) *
              f_Ts_tmp_tmp_tmp + g_Ts_tmp_tmp_tmp * t413 * h_Ts_tmp_tmp_tmp)) *
            Ts_tmp_tmp) + t162 * (t37 * Ts_tmp + j_Ts_tmp * i_Ts_tmp_tmp_tmp *
            d_Ts_tmp_tmp * t162)) / M[0] / t222 / M[2] / t142 / t220;
  t75 = (((M[3] - n3) * (x[11] * x[11]) + n3pp / 2.0) * h_Ts_tmp_tmp_tmp *
         d_Ts_tmp_tmp_tmp - x[11] * std::cos(x[6]) * n3p) * f_Ts_tmp_tmp_tmp -
    g_Ts_tmp_tmp_tmp * ((M[3] - n3) * (x[11] * x[11]) + n3pp / 2.0) *
    c_Ts_tmp_tmp_tmp;
  t622 = x[11] * x[12] * std::cos(x[6]) * std::sin(x[3]) * (M[3] - n3);
  t443 = (((((0.66666666666666663 * M[3] - 0.66666666666666663 * n3) * (x[11] *
              x[11]) + (M[3] - n3) * (x[12] * x[12])) + n3pp / 3.0) *
           c_Ts_tmp_tmp_tmp - 0.66666666666666663 * x[12] * std::sin(x[7]) * std::
           sin(x[3]) * n3p) * d_Ts_tmp_tmp_tmp - 1.3333333333333333 * x[12] * x
          [11] * std::cos(x[6]) * std::sin(x[3]) * (M[3] - n3)) *
    f_Ts_tmp_tmp_tmp + g_Ts_tmp_tmp_tmp * (0.66666666666666663 * x[12] * std::
    cos(x[7]) * std::sin(x[3]) * n3p + h_Ts_tmp_tmp_tmp * (((0.66666666666666663
    * M[3] - 0.66666666666666663 * n3) * (x[11] * x[11]) + (M[3] - n3) * (x[12] *
    x[12])) + n3pp / 3.0));
  t708 = 3.0 * M[2] * M[0];
  t444 = (M[3] - n3) * ((std::cos(x[7]) * (4.0 * x[12] * x[11] * M[2] * std::sin
    (x[4]) * std::sin(x[3]) * M[0] + (M[0] + M[1]) * (M[3] - n3)) * std::sin(x[6])
    + x[12] * x[12] * M[2] * Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * M[0]) *
                        f_Ts_tmp_tmp_tmp + std::sin(x[5]) * (4.0 * x[12] * x[11]
    * M[2] * std::sin(x[4]) * std::sin(x[3]) * M[0] + (M[0] + M[1]) * (M[3] - n3))
                        * std::sin(x[7]));
  t121 = -(M[3] - n3) * b_Ts_tmp_tmp / 2.0 - n3pp / 2.0;
  t263 = t121 * c_Ts_tmp_tmp_tmp;
  t178 = t263 * d_Ts_tmp_tmp_tmp + t622;
  t549 = t178 * f_Ts_tmp_tmp_tmp - t99;
  t576 = x[11] * x[12] * (std::cos(x[5]) * std::sin(x[6]) * std::sin(x[7]) - std::
    sin(x[5]) * std::cos(x[7])) * (M[3] - n3) * rt_powd_snf(std::cos(x[3]), 3.0);
  k_Ts_tmp = x[11] * x[11] * (std::cos(x[5]) * std::sin(x[6]) * std::cos(x[7]) +
    std::sin(x[5]) * std::sin(x[7])) * (M[3] - n3);
  t551 = e_Ts_tmp_tmp_tmp * ((((M[3] - n3) * (x[11] * x[11]) + n3pp / 2.0) *
    h_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp - x[11] * std::cos(x[6]) * n3p) *
    f_Ts_tmp_tmp_tmp - g_Ts_tmp_tmp_tmp * ((M[3] - n3) * (x[11] * x[11]) + n3pp /
    2.0) * c_Ts_tmp_tmp_tmp);
  t578 = ((std::sin(x[7]) * x[11] * std::sin(x[6]) * n3p + ((M[3] - n3) * (x[11]
             * x[11]) + n3pp / 2.0) * i_Ts_tmp_tmp_tmp) * f_Ts_tmp_tmp_tmp - std::
          cos(x[7]) * std::sin(x[5]) * x[11] * n3p) * rt_powd_snf(std::cos(x[3]),
    3.0);
  l_Ts_tmp = (((x[12] * std::sin(x[3]) * (M[3] - n3) * std::cos(x[7]) - std::sin
                (x[7]) * n3p) * std::sin(x[6]) - 1.5 * x[11] * std::cos(x[6]) *
               (M[3] - n3)) * std::cos(x[5]) + std::sin(x[5]) * (n3p * std::cos
    (x[7]) + x[12] * std::sin(x[7]) * std::sin(x[3]) * (M[3] - n3))) * x[11] *
    std::cos(x[3]);
  t675 = std::sin(x[7]) * x[11] * (M[3] - n3) * std::sin(x[6]) - std::cos(x[6]) *
    n3p / 2.0;
  t558 = 1.3333333333333333 * c_Ts_tmp_tmp_tmp;
  t408 = t558 * g_Ts_tmp_tmp_tmp;
  t63 = -1.3333333333333333 * t675 * f_Ts_tmp_tmp_tmp + t408 * x[11] * t162;
  m_Ts_tmp = t63 * x[12] * t220;
  t664 = -x[12] * e_Ts_tmp_tmp_tmp * t162 * c_Ts_tmp_tmp_tmp + l_Ts_tmp_tmp_tmp;
  t671 = (n3p * std::cos(x[7]) + x[12] * std::sin(x[7]) * std::sin(x[3]) * (M[3]
           - n3)) * std::sin(x[6]) * std::cos(x[5]) + t664 * g_Ts_tmp_tmp_tmp;
  t477 = 2.0 * M[0] * std::sin(x[4]) * M[2] * x[12] * t671;
  n_Ts_tmp = t477 * b_Ts_tmp_tmp_tmp;
  o_Ts_tmp = std::cos(x[5]) * std::sin(x[4]) * std::cos(x[6]) * (M[0] + M[1]) *
    (M[3] - n3);
  t382 = std::sin(x[3]) * n3p * std::cos(x[7]) + x[12] * std::sin(x[7]) * (M[3]
    - n3);
  t604 = std::sin(x[5]) * (x[12] * (M[3] - n3) * std::cos(x[7]) - std::sin(x[7])
    * std::sin(x[3]) * n3p);
  t133 = -t382 * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + t604;
  t397 = t133 * x[11] * b_Ts_tmp_tmp_tmp;
  n_Ts_tmp_tmp_tmp = 1.3333333333333333 * g_Ts_tmp_tmp_tmp;
  t705 = 1.3333333333333333 * (std::sin(x[3]) * n3p * std::cos(x[7]) / 2.0 + x
    [12] * std::sin(x[7]) * (M[3] - n3)) * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp -
    n_Ts_tmp_tmp_tmp * t179;
  t253 = t705 * x[11] * b_Ts_tmp_tmp_tmp;
  t706 = -g_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  o_Ts_tmp_tmp_tmp = f_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp;
  t469 = t706 * c_Ts_tmp_tmp_tmp + o_Ts_tmp_tmp_tmp;
  h_Ts_tmp_tmp = c_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp;
  p_Ts_tmp = 1.3333333333333333 * t172;
  t250 = x[12] * (M[3] - n3) * std::cos(x[7]) - std::sin(x[7]) * std::sin(x[3]) *
    n3p;
  q_Ts_tmp = (((0.66666666666666663 * M[3] - 0.66666666666666663 * n3) * (x[11] *
    x[11]) + (M[3] - n3) * (x[12] * x[12])) + n3pp / 3.0) * c_Ts_tmp_tmp_tmp -
    0.66666666666666663 * x[12] * std::sin(x[7]) * std::sin(x[3]) * n3p;
  r_Ts_tmp = t408 * t162;
  s_Ts_tmp = 4.0 * t162;
  t699 = g_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp;
  t701 = -0.66666666666666663 * b_Ts_tmp_tmp - c_Ts_tmp_tmp;
  t597 = t16 * f_Ts_tmp_tmp_tmp * M[2] * Ts_tmp_tmp_tmp;
  t470 = -M[0] - M[1];
  i_Ts_tmp_tmp = i_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp;
  j_Ts_tmp_tmp = c_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp;
  t408 = 2.0 * f_Ts_tmp_tmp_tmp;
  t559 = t408 * d_Ts_tmp_tmp_tmp;
  t161 = t559 * h_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp;
  t721 = rt_powd_snf(b_Ts_tmp_tmp_tmp, 4.0);
  t603 = std::cos(x[6]) * n3p;
  t584 = std::sin(x[3]) * x[11];
  t514 = x[11] * t162;
  t_Ts_tmp = x[11] * x[12] * std::cos(x[6]);
  u_Ts_tmp = std::sin(x[5]) * std::sin(x[7]) * e_Ts_tmp_tmp_tmp;
  v_Ts_tmp = 1.5 * x[11] * std::cos(x[6]);
  w_Ts_tmp = t181 * t671;
  t706 = t706 * h_Ts_tmp_tmp_tmp - h_Ts_tmp_tmp;
  p_Ts_tmp_tmp_tmp = g_Ts_tmp_tmp_tmp * x[12];
  t682 = p_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp;
  x_Ts_tmp = 2.0 * t162;
  k_Ts_tmp_tmp = x[11] * d_Ts_tmp_tmp_tmp;
  y_Ts_tmp = x[11] * std::cos(x[6]);
  t711 = h_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * n3p;
  t366 = std::sin(x[7]) * x[11] * (M[3] - n3) * i_Ts_tmp_tmp_tmp;
  l_Ts_tmp_tmp = d_Ts_tmp_tmp_tmp * n3p;
  t271 = l_Ts_tmp_tmp / 4.0;
  t349 = l_Ts_tmp_tmp_tmp / 2.0;
  q_Ts_tmp_tmp_tmp = 2.0 * g_Ts_tmp_tmp_tmp;
  t176 = q_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t305 = m_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * t162;
  t692 = 2.0 * x[11] * t162;
  m_Ts_tmp_tmp = x[12] * i_Ts_tmp_tmp_tmp;
  t427 = k_Ts_tmp_tmp * t162;
  t150 = ((t578 - t551 * (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp)) + l_Ts_tmp) +
    t15;
  t291 = b_Ts_tmp_tmp_tmp * ((t221 * (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp) -
    n_Ts_tmp) + t444);
  t285 = 3.0 * ((((2.0 * M[0] * (((t576 + t549 * (b_Ts_tmp_tmp_tmp *
    b_Ts_tmp_tmp_tmp)) + t397) + k_Ts_tmp) * M[2] * t175 + t181 * (((t578 - t551
    * (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp)) + l_Ts_tmp) + t15) * t142) + t708 *
                  (((m_Ts_tmp + t443 * (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp)) +
                    t253) - t14) * (Ts_tmp_tmp * Ts_tmp_tmp)) - b_Ts_tmp_tmp_tmp
                 * ((t221 * (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp) - n_Ts_tmp) +
                    t444) * Ts_tmp_tmp) + t162 * (t37 * (b_Ts_tmp_tmp_tmp *
    b_Ts_tmp_tmp_tmp) + o_Ts_tmp)) / M[0] / t235 / M[2];
  t221 = ((((2.0 * M[0] * (((t576 + t549 * (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp))
    + t397) + k_Ts_tmp) * M[2] * t175 + t181 * (((t578 - t551 *
    (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp)) + l_Ts_tmp) + t15) * t142) + t708 *
            (((m_Ts_tmp + t443 * (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp)) + t253)
             - t14) * (Ts_tmp_tmp * Ts_tmp_tmp)) - b_Ts_tmp_tmp_tmp * ((t221 *
             (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp) - n_Ts_tmp) + t444) *
           Ts_tmp_tmp) + t162 * (t37 * (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp) +
           o_Ts_tmp)) / M[0] / (t235 * t235) / M[2] / t142 / t220;
  n_Ts_tmp_tmp = i_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp;
  n_Ts_tmp = c_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp;
  ab_Ts_tmp = f_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp;
  t50 = (n_Ts_tmp_tmp - 2.0) * n_Ts_tmp;
  t411 = t162 * t162;
  bb_Ts_tmp = e_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp;
  cb_Ts_tmp = Ts_tmp_tmp_tmp * Ts_tmp_tmp_tmp;
  t89 = ((((i_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp - 2.0) * (c_Ts_tmp_tmp_tmp *
            c_Ts_tmp_tmp_tmp) - 2.0 * (i_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp)) +
          1.0) * (f_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp) - t161) +
    c_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp;
  t361 = t514 * n_Ts_tmp_tmp;
  t247 = -std::sin(x[7]) * n_Ts_tmp_tmp * n3p;
  t184 = (((n_Ts_tmp_tmp - 2.0) * (c_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp - 0.5) *
           ab_Ts_tmp - t161) + n_Ts_tmp) - 0.5;
  db_Ts_tmp = h_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp;
  t572 = x[13] * i_Ts_tmp_tmp_tmp;
  eb_Ts_tmp = g_Ts_tmp_tmp_tmp * x[11];
  fb_Ts_tmp = c_Ts_tmp_tmp_tmp * x[11];
  gb_Ts_tmp = g_Ts_tmp_tmp_tmp * x[14] + f_Ts_tmp_tmp_tmp * x[15];
  hb_Ts_tmp = f_Ts_tmp_tmp_tmp * x[14] - g_Ts_tmp_tmp_tmp * x[15];
  ib_Ts_tmp = f_Ts_tmp_tmp_tmp * x[11];
  jb_Ts_tmp = x[12] * c_Ts_tmp_tmp_tmp;
  kb_Ts_tmp = x[12] * b_Ts_tmp_tmp_tmp;
  t726 = b_Ts_tmp_tmp * c_Ts_tmp_tmp_tmp;
  lb_Ts_tmp = g_Ts_tmp_tmp_tmp * Ts_tmp_tmp_tmp;
  mb_Ts_tmp = -e_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp;
  Ts[5] = (((((((((x[11] * (((((((2.0 * M[0] * ((((-3.0 * x[12] * x[11] * t339 *
    t162 * Ts_tmp * e_Ts_tmp_tmp_tmp + t_Ts_tmp * t220 * t162 * f_Ts_tmp_tmp_tmp)
    - 2.0 * (((-t162 * (x[11] * x[11]) / 2.0 - n3pp / 2.0) * c_Ts_tmp_tmp_tmp *
    d_Ts_tmp_tmp_tmp + t622) * f_Ts_tmp_tmp_tmp - t99) * b_Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp) + (-b_Ts_tmp_tmp_tmp * n3p * c_Ts_tmp_tmp_tmp *
    d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - a_tmp_tmp_tmp_tmp_tmp *
    b_Ts_tmp_tmp_tmp * n3p) * x[11] * b_Ts_tmp_tmp_tmp) - (-t382 *
    d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + t604) * x[11] * e_Ts_tmp_tmp_tmp) * M
    [2] * t175 + t181 * (((((-3.0 * ((std::sin(x[7]) * x[11] * std::sin(x[6]) *
    n3p + ((M[3] - n3) * (x[11] * x[11]) + n3pp / 2.0) * i_Ts_tmp_tmp_tmp) *
    f_Ts_tmp_tmp_tmp - std::cos(x[7]) * std::sin(x[5]) * x[11] * n3p) * Ts_tmp *
    e_Ts_tmp_tmp_tmp - t220 * t75) + 2.0 * bb_Ts_tmp * t75 * b_Ts_tmp_tmp_tmp) +
    (kb_Ts_tmp * t162 * c_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp +
    t682 * b_Ts_tmp_tmp_tmp * t162) * x[11] * b_Ts_tmp_tmp_tmp) - (((x[12] * std::
    sin(x[3]) * (M[3] - n3) * std::cos(x[7]) - std::sin(x[7]) * n3p) * std::sin
    (x[6]) - 1.5 * x[11] * std::cos(x[6]) * (M[3] - n3)) * std::cos(x[5]) + std::
    sin(x[5]) * (n3p * std::cos(x[7]) + x[12] * std::sin(x[7]) * std::sin(x[3]) *
    (M[3] - n3))) * x[11] * e_Ts_tmp_tmp_tmp) + b_Ts_tmp_tmp * b_Ts_tmp_tmp_tmp *
    t339 * t162) * t142) + t708 * ((((-3.0 * (-1.3333333333333333 * t675 *
    f_Ts_tmp_tmp_tmp + 1.3333333333333333 * c_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp *
    x[11] * t162) * x[12] * Ts_tmp * e_Ts_tmp_tmp_tmp + ((-0.66666666666666663 *
    x[12] * h_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp * n3p * d_Ts_tmp_tmp_tmp -
    1.3333333333333333 * x[12] * x[11] * std::cos(x[6]) * b_Ts_tmp_tmp_tmp *
    t162) * f_Ts_tmp_tmp_tmp + 0.66666666666666663 * g_Ts_tmp_tmp_tmp * x[12] *
    c_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp * n3p) * Ts_tmp) - 2.0 * t443 *
    b_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp) + (0.66666666666666663 *
    b_Ts_tmp_tmp_tmp * n3p * c_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp *
    f_Ts_tmp_tmp_tmp + 0.66666666666666663 * std::sin(x[5]) * h_Ts_tmp_tmp_tmp *
    b_Ts_tmp_tmp_tmp * n3p) * x[11] * b_Ts_tmp_tmp_tmp) - (p_Ts_tmp *
    d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - 1.3333333333333333 * g_Ts_tmp_tmp_tmp *
    t179) * x[11] * e_Ts_tmp_tmp_tmp) * b_Ts_tmp) + e_Ts_tmp_tmp_tmp * ((t523 -
    e_Ts_tmp * ((n3p * std::cos(x[7]) + x[12] * std::sin(x[7]) * std::sin(x[3]) *
                 (M[3] - n3)) * std::sin(x[6]) * std::cos(x[5]) + (-x[12] *
    e_Ts_tmp_tmp_tmp * t162 * c_Ts_tmp_tmp_tmp + l_Ts_tmp_tmp_tmp) *
                g_Ts_tmp_tmp_tmp) * b_Ts_tmp_tmp_tmp) + t444) * Ts_tmp_tmp) -
    b_Ts_tmp_tmp_tmp * (((-4.0 * c_Ts_tmp_tmp * f_Ts_tmp_tmp_tmp * M[2] *
    Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * M[0] * t162 * b_Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp - e_Ts_tmp * (j_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp * t162 *
    d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - x[12] * std::cos(x[3]) * (M[3] - n3) *
    std::cos(x[7]) * g_Ts_tmp_tmp_tmp) * b_Ts_tmp_tmp_tmp) + t477 *
    e_Ts_tmp_tmp_tmp) + t162 * (4.0 * c_Ts_tmp_tmp_tmp * x[12] * x[11] * M[2] *
    Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp * M[0] * d_Ts_tmp_tmp_tmp *
    f_Ts_tmp_tmp_tmp + 4.0 * g_Ts_tmp_tmp_tmp * x[12] * x[11] * M[2] *
    Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp * M[0] * h_Ts_tmp_tmp_tmp)) * Ts_tmp_tmp)
    + s_Ts_tmp * c_Ts_tmp_tmp * M[2] * M[0] * t262 * b_Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp) / M[0] / t235 / M[2] / t142 / t220 - ((((2.0 * M[0] *
    (((t576 + t549 * Ts_tmp) + t397) + k_Ts_tmp) * M[2] * t175 + t181 * (((t578
    - t551 * (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp)) + l_Ts_tmp) + t15) * t142) +
    t708 * (((m_Ts_tmp + t443 * (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp)) + t253) -
            t14) * b_Ts_tmp) - t291 * Ts_tmp_tmp) + t162 * (t37 *
    (b_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp) + o_Ts_tmp)) / M[0] / (t235 * t235) /
    M[2] / b_Ts_tmp / t220 * (mb_Ts_tmp * i_Ts_tmp_tmp_tmp + t65 *
    b_Ts_tmp_tmp_tmp)) + t285 / t142 / t721 * e_Ts_tmp_tmp_tmp) + x[12] *
                   ((((((((-8.0 * M[0] * (((t576 + t549 * (b_Ts_tmp_tmp_tmp *
    b_Ts_tmp_tmp_tmp)) + t397) + k_Ts_tmp) * M[2] * t142 * Ts_tmp_tmp_tmp + 2.0 *
    M[0] * t175 * M[2] * t150) - 6.0 * M[0] * cb_Ts_tmp * M[2] * t150 * b_Ts_tmp)
    - 6.0 * M[2] * M[0] * (((m_Ts_tmp + t443 * (b_Ts_tmp_tmp_tmp *
    b_Ts_tmp_tmp_tmp)) + t253) - t14) * Ts_tmp_tmp * Ts_tmp_tmp_tmp) -
                        b_Ts_tmp_tmp_tmp * ((t219 * Ts_tmp_tmp *
    i_Ts_tmp_tmp_tmp * M[0] * t162 * Ts_tmp - 2.0 * M[0] * Ts_tmp_tmp * M[2] *
    x[12] * t671 * b_Ts_tmp_tmp_tmp) + t162 * ((4.0 * std::cos(x[7]) * x[12] *
    x[11] * M[2] * Ts_tmp_tmp * e_Ts_tmp_tmp_tmp * M[0] * d_Ts_tmp_tmp_tmp +
    e_Ts_tmp_tmp * Ts_tmp_tmp * i_Ts_tmp_tmp_tmp * M[0]) * f_Ts_tmp_tmp_tmp +
    4.0 * std::sin(x[5]) * x[12] * x[11] * M[2] * Ts_tmp_tmp * e_Ts_tmp_tmp_tmp *
    M[0] * h_Ts_tmp_tmp_tmp)) * Ts_tmp_tmp) + t291 * Ts_tmp_tmp_tmp) + t411 *
                      f_Ts_tmp_tmp_tmp * Ts_tmp_tmp * i_Ts_tmp_tmp_tmp *
                      d_Ts_tmp_tmp) / M[0] / t235 / M[2] / t142 / t220 - t221 *
                     (-t174 * Ts_tmp_tmp_tmp + Ts_tmp_tmp * t262)) + t285 / t175
                    / t220 * Ts_tmp_tmp_tmp)) + ((g_Ts_tmp_tmp_tmp *
    d_Ts_tmp_tmp_tmp * x[14] + t6 * x[15]) + t572) / i_Ts_tmp_tmp_tmp * (((((2.0
    * M[0] * (((d_Ts_tmp * t706 * t162 * t220 + (-t178 * g_Ts_tmp_tmp_tmp -
    f_Ts_tmp_tmp_tmp * t344 * h_Ts_tmp_tmp_tmp / 2.0) * Ts_tmp) + ((std::sin(x[3])
    * n3p * std::cos(x[7]) + x[12] * std::sin(x[7]) * (M[3] - n3)) * std::sin(x
    [6]) * g_Ts_tmp_tmp_tmp + f_Ts_tmp_tmp_tmp * t250) * x[11] *
               b_Ts_tmp_tmp_tmp) + b_Ts_tmp_tmp * t469 * t162) * M[2] * t175 +
    t181 * ((((-(std::sin(x[7]) * x[11] * std::sin(x[6]) * n3p + ((M[3] - n3) *
    (x[11] * x[11]) + n3pp / 2.0) * i_Ts_tmp_tmp_tmp) * g_Ts_tmp_tmp_tmp -
               h_Ts_tmp_tmp * x[11] * n3p) * t220 - e_Ts_tmp_tmp_tmp * (-(((M[3]
    - n3) * (x[11] * x[11]) + n3pp / 2.0) * h_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp
    - x[11] * std::cos(x[6]) * n3p) * g_Ts_tmp_tmp_tmp - f_Ts_tmp_tmp_tmp * t144
    * c_Ts_tmp_tmp_tmp) * Ts_tmp) + (-((x[12] * std::sin(x[3]) * (M[3] - n3) *
    std::cos(x[7]) - std::sin(x[7]) * n3p) * std::sin(x[6]) - 1.5 * x[11] * std::
    cos(x[6]) * (M[3] - n3)) * g_Ts_tmp_tmp_tmp + f_Ts_tmp_tmp_tmp * t199) * x
             [11] * b_Ts_tmp_tmp_tmp) + t120 * t706 * t162) * t142) + t708 *
    ((((1.3333333333333333 * t675 * g_Ts_tmp_tmp_tmp + t558 * f_Ts_tmp_tmp_tmp *
        x[11] * t162) * x[12] * t220 + (-(((((0.66666666666666663 * M[3] -
    0.66666666666666663 * n3) * (x[11] * x[11]) + (M[3] - n3) * (x[12] * x[12]))
    + n3pp / 3.0) * c_Ts_tmp_tmp_tmp - 0.66666666666666663 * x[12] * std::sin(x
    [7]) * std::sin(x[3]) * n3p) * d_Ts_tmp_tmp_tmp - 1.3333333333333333 * x[12]
    * x[11] * std::cos(x[6]) * std::sin(x[3]) * (M[3] - n3)) * g_Ts_tmp_tmp_tmp
    + f_Ts_tmp_tmp_tmp * (0.66666666666666663 * x[12] * std::cos(x[7]) * std::
    sin(x[3]) * n3p + h_Ts_tmp_tmp_tmp * (((0.66666666666666663 * M[3] -
    0.66666666666666663 * n3) * (x[11] * x[11]) + (M[3] - n3) * (x[12] * x[12]))
    + n3pp / 3.0))) * Ts_tmp) + (-1.3333333333333333 * t172 * d_Ts_tmp_tmp_tmp *
    g_Ts_tmp_tmp_tmp - 1.3333333333333333 * f_Ts_tmp_tmp_tmp * t179) * x[11] *
      b_Ts_tmp_tmp_tmp) - k_Ts_tmp_tmp_tmp * t469 * t162) * b_Ts_tmp) -
    b_Ts_tmp_tmp_tmp * ((t16 * g_Ts_tmp_tmp_tmp * M[2] * Ts_tmp_tmp_tmp *
    i_Ts_tmp_tmp_tmp * M[0] * t162 * Ts_tmp - e_Ts_tmp * (-t199 *
    d_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp + t664 * f_Ts_tmp_tmp_tmp) *
    b_Ts_tmp_tmp_tmp) + t162 * (-(std::cos(x[7]) * (4.0 * x[12] * x[11] * M[2] *
    std::sin(x[4]) * std::sin(x[3]) * M[0] + (M[0] + M[1]) * (M[3] - n3)) * std::
    sin(x[6]) + x[12] * x[12] * M[2] * Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * M[0])
    * g_Ts_tmp_tmp_tmp + f_Ts_tmp_tmp_tmp * t413 * h_Ts_tmp_tmp_tmp)) *
    Ts_tmp_tmp) + t162 * (t26 * t469 * Ts_tmp - lb_Ts_tmp * i_Ts_tmp_tmp_tmp *
    d_Ts_tmp_tmp * t162)) / M[0] / t235 / M[2] / t142 / t220 - t221 *
    ((-i_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp + (std::sin(x[5]) *
    std::sin(x[6]) * h_Ts_tmp_tmp_tmp + h_Ts_tmp_tmp) * e_Ts_tmp_tmp_tmp) *
     Ts_tmp_tmp + Ts_tmp_tmp_tmp * t469))) + hb_Ts_tmp * (((((2.0 * M[0] *
    (((d_Ts_tmp * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp * t162 *
       t220 + (t263 * i_Ts_tmp_tmp_tmp - d_Ts_tmp * d_Ts_tmp_tmp_tmp *
               e_Ts_tmp_tmp_tmp * t162) * f_Ts_tmp_tmp_tmp * Ts_tmp) - t382 *
      i_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp * x[11] * b_Ts_tmp_tmp_tmp) +
     b_Ts_tmp_tmp * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp *
     t162) * M[2] * t175 + t181 * ((((g_Ts_tmp_tmp * i_Ts_tmp_tmp_tmp * n3p -
    t144 * d_Ts_tmp_tmp_tmp) * f_Ts_tmp_tmp_tmp * t220 - e_Ts_tmp_tmp_tmp *
    (t620 * i_Ts_tmp_tmp_tmp + k_Ts_tmp_tmp * n3p) * f_Ts_tmp_tmp_tmp * Ts_tmp)
    + (t42 * i_Ts_tmp_tmp_tmp + 1.5 * x[11] * d_Ts_tmp_tmp_tmp * t162) *
    f_Ts_tmp_tmp_tmp * x[11] * b_Ts_tmp_tmp_tmp) + t120 * f_Ts_tmp_tmp_tmp *
    i_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp * t162) * t142) + t708 *
    (((-1.3333333333333333 * (t11 * i_Ts_tmp_tmp_tmp + l_Ts_tmp_tmp / 2.0) *
       f_Ts_tmp_tmp_tmp * x[12] * t220 + (q_Ts_tmp * i_Ts_tmp_tmp_tmp + f_Ts_tmp
    * d_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * t162) * f_Ts_tmp_tmp_tmp * Ts_tmp) +
      p_Ts_tmp * i_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp * x[11] * b_Ts_tmp_tmp_tmp)
     - k_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp
     * t162) * b_Ts_tmp) - b_Ts_tmp_tmp_tmp * ((t597 * d_Ts_tmp_tmp_tmp * M[0] *
    t162 * Ts_tmp - e_Ts_tmp * t199 * i_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp *
    b_Ts_tmp_tmp_tmp) + t162 * (std::cos(x[7]) * (4.0 * x[12] * x[11] * M[2] *
    std::sin(x[4]) * std::sin(x[3]) * M[0] + (M[0] + M[1]) * (M[3] - n3)) *
    i_Ts_tmp_tmp_tmp - t636 * d_Ts_tmp_tmp_tmp * M[0]) * f_Ts_tmp_tmp_tmp) *
    Ts_tmp_tmp) + t162 * (t26 * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp *
    c_Ts_tmp_tmp_tmp * Ts_tmp - std::cos(x[5]) * std::sin(x[4]) *
    d_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp * t162)) / M[0] / t235 / M[2] / t142 / t220
    - t221 * ((-d_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp -
               f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp *
               e_Ts_tmp_tmp_tmp) * Ts_tmp_tmp + std::sin(x[4]) * std::cos(x[5]) *
              std::cos(x[6]) * c_Ts_tmp_tmp_tmp))) + gb_Ts_tmp /
                i_Ts_tmp_tmp_tmp * (((((2.0 * M[0] * (((d_Ts_tmp * t262 * t162 *
    t220 + (-t121 * h_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - t55
            * c_Ts_tmp_tmp_tmp / 2.0) * Ts_tmp) + (-t250 * d_Ts_tmp_tmp_tmp *
    f_Ts_tmp_tmp_tmp + g_Ts_tmp_tmp_tmp * (-std::sin(x[3]) * n3p *
    c_Ts_tmp_tmp_tmp - t183)) * x[11] * b_Ts_tmp_tmp_tmp) + b_Ts_tmp_tmp * t65 *
    t162) * M[2] * t175 + t181 * ((((fb_Ts_tmp * d_Ts_tmp_tmp_tmp * n3p *
    f_Ts_tmp_tmp_tmp + a_tmp_tmp_tmp_tmp_tmp * x[11] * n3p) * t220 -
    e_Ts_tmp_tmp_tmp * (t144 * c_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp *
                        f_Ts_tmp_tmp_tmp + g_Ts_tmp * h_Ts_tmp_tmp_tmp) * Ts_tmp)
    + ((-x[12] * h_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * t162 - f_Ts_tmp_tmp) *
       d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + (x[12] * std::sin(x[3]) * (M[3] -
    n3) * std::cos(x[7]) - std::sin(x[7]) * n3p) * std::sin(x[5])) * x[11] *
    b_Ts_tmp_tmp_tmp) + t120 * t262 * t162) * t142) + t708 *
    ((((-1.3333333333333333 * c_Ts_tmp_tmp_tmp * x[11] * t162 * d_Ts_tmp_tmp_tmp
        * f_Ts_tmp_tmp_tmp - n_Ts_tmp_tmp_tmp * x[11] * t162 * h_Ts_tmp_tmp_tmp)
       * x[12] * t220 + ((-h_Ts_tmp_tmp_tmp * t260 - 0.66666666666666663 * x[12]
    * std::cos(x[7]) * std::sin(x[3]) * n3p) * d_Ts_tmp_tmp_tmp *
    f_Ts_tmp_tmp_tmp + g_Ts_tmp_tmp_tmp * q_Ts_tmp) * Ts_tmp) +
      (1.3333333333333333 * t179 * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp -
       n_Ts_tmp_tmp_tmp * (-x[12] * std::sin(x[7]) * t162 - t113)) * x[11] *
      b_Ts_tmp_tmp_tmp) - k_Ts_tmp_tmp_tmp * t65 * t162) * b_Ts_tmp) -
    b_Ts_tmp_tmp_tmp * (-2.0 * M[0] * Ts_tmp_tmp_tmp * M[2] * x[12] * ((x[12] *
    std::sin(x[3]) * (M[3] - n3) * std::cos(x[7]) - std::sin(x[7]) * n3p) * std::
    sin(x[6]) * f_Ts_tmp_tmp_tmp + std::sin(x[5]) * (n3p * std::cos(x[7]) + x[12]
    * std::sin(x[7]) * std::sin(x[3]) * (M[3] - n3))) * b_Ts_tmp_tmp_tmp + t162 *
                        (-std::sin(x[7]) * t413 * d_Ts_tmp_tmp_tmp *
    f_Ts_tmp_tmp_tmp + std::sin(x[5]) * (4.0 * x[12] * x[11] * M[2] * std::sin
    (x[4]) * std::sin(x[3]) * M[0] + (M[0] + M[1]) * (M[3] - n3)) *
    c_Ts_tmp_tmp_tmp)) * Ts_tmp_tmp) - x_Ts_tmp * c_Ts_tmp_tmp * M[2] * M[0] *
    t65 * Ts_tmp) / M[0] / t235 / M[2] / t142 / t220 - t221 * ((t27 *
    c_Ts_tmp_tmp_tmp - a_tmp_tmp_tmp_tmp_tmp) * e_Ts_tmp_tmp_tmp * Ts_tmp_tmp +
    Ts_tmp_tmp_tmp * t65))) + 2.0 * x[12] * x[11] * Ts_tmp_tmp_tmp / t175 *
               (((2.0 * M[0] * (((x[12] * t339 * t162 * t220 +
    ((-c_Ts_tmp_tmp_tmp * x[11] * t162 * d_Ts_tmp_tmp_tmp + m_Ts_tmp_tmp *
      e_Ts_tmp_tmp_tmp * t162) * f_Ts_tmp_tmp_tmp - eb_Ts_tmp * t162 *
     h_Ts_tmp_tmp_tmp) * Ts_tmp) + t133 * b_Ts_tmp_tmp_tmp) + 2.0 * x[11] * t262
    * t162) * M[2] * t175 + t181 * ((((((t711 + 2.0 * x[11] * i_Ts_tmp_tmp_tmp *
    t162) * f_Ts_tmp_tmp_tmp - a_tmp_tmp_tmp * n3p) * t220 - e_Ts_tmp_tmp_tmp *
    ((2.0 * h_Ts_tmp_tmp_tmp * x[11] * t162 * d_Ts_tmp_tmp_tmp - t603) *
     f_Ts_tmp_tmp_tmp - 2.0 * c_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp * x[11] * t162)
    * Ts_tmp) - 1.5 * i_Ts_tmp_tmp_tmp * t162 * f_Ts_tmp_tmp_tmp * x[11] *
    b_Ts_tmp_tmp_tmp) + (((x[12] * std::sin(x[3]) * (M[3] - n3) * std::cos(x[7])
    - std::sin(x[7]) * n3p) * std::sin(x[6]) - 1.5 * x[11] * std::cos(x[6]) *
    (M[3] - n3)) * std::cos(x[5]) + std::sin(x[5]) * (n3p * std::cos(x[7]) + x
    [12] * std::sin(x[7]) * std::sin(x[3]) * (M[3] - n3))) * b_Ts_tmp_tmp_tmp) +
    2.0 * x[11] * e_Ts_tmp_tmp_tmp * t339 * t162) * t142) + t708 *
                 ((((-1.3333333333333333 * h_Ts_tmp_tmp_tmp * t162 *
                     d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + r_Ts_tmp) * x[12] *
                    t220 + ((2.0 * t234 * x[11] * c_Ts_tmp_tmp_tmp *
    d_Ts_tmp_tmp_tmp - 1.3333333333333333 * x[12] * i_Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp * t162) * f_Ts_tmp_tmp_tmp + 2.0 * g_Ts_tmp_tmp_tmp *
    h_Ts_tmp_tmp_tmp * t234 * x[11]) * Ts_tmp) + t705 * b_Ts_tmp_tmp_tmp) -
                  1.3333333333333333 * x[11] * t262 * t162) * b_Ts_tmp) -
                b_Ts_tmp_tmp_tmp * t162 * (4.0 * std::cos(x[7]) * x[12] * M[2] *
    Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * M[0] * d_Ts_tmp_tmp_tmp *
    f_Ts_tmp_tmp_tmp + 4.0 * std::sin(x[5]) * x[12] * M[2] * Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp * M[0] * h_Ts_tmp_tmp_tmp) * Ts_tmp_tmp) / M[0] / t235 / M
               [2] / t220) - b_Ts_tmp_tmp / b_Ts_tmp * Ts_tmp_tmp_tmp * ((((2.0 *
    M[0] * ((x[11] * t339 * t162 * t220 + y_Ts_tmp * e_Ts_tmp_tmp_tmp * t162 *
             f_Ts_tmp_tmp_tmp * Ts_tmp) + (-std::sin(x[7]) * t162 *
    d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + a_tmp_tmp_tmp * t162) * x[11] *
            b_Ts_tmp_tmp_tmp) * M[2] * t175 + t181 * (e_Ts_tmp_tmp_tmp * t162 *
    c_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp +
    a_tmp_tmp_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * t162) * x[11] * b_Ts_tmp_tmp_tmp *
    t142) + t708 * ((t63 * t220 + (((2.0 * x[12] * t162 * c_Ts_tmp_tmp_tmp -
    0.66666666666666663 * h_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * n3p) *
    d_Ts_tmp_tmp_tmp - 1.3333333333333333 * x[11] * i_Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp * t162) * f_Ts_tmp_tmp_tmp + g_Ts_tmp_tmp_tmp *
    (0.66666666666666663 * e_Ts_tmp_tmp_tmp * n3p * c_Ts_tmp_tmp_tmp + 2.0 * x
     [12] * h_Ts_tmp_tmp_tmp * t162)) * Ts_tmp) + (1.3333333333333333 *
    h_Ts_tmp_tmp_tmp * t162 * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - r_Ts_tmp) *
                    x[11] * b_Ts_tmp_tmp_tmp) * b_Ts_tmp) - b_Ts_tmp_tmp_tmp *
    (((4.0 * x[12] * f_Ts_tmp_tmp_tmp * M[2] * Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp
       * M[0] * t162 * Ts_tmp - w_Ts_tmp * b_Ts_tmp_tmp_tmp) - e_Ts_tmp * (t629 *
    t162 * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - std::sin(x[3]) * (M[3] - n3) *
    std::cos(x[7]) * g_Ts_tmp_tmp_tmp) * b_Ts_tmp_tmp_tmp) + t162 * ((4.0 * std::
    cos(x[7]) * x[11] * M[2] * Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * M[0] *
    d_Ts_tmp_tmp_tmp + 2.0 * x[12] * M[2] * Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp *
    M[0]) * f_Ts_tmp_tmp_tmp + 4.0 * std::sin(x[5]) * x[11] * M[2] *
    Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * M[0] * h_Ts_tmp_tmp_tmp)) * Ts_tmp_tmp)
    - s_Ts_tmp * x[12] * M[2] * M[0] * t262 * Ts_tmp) / M[0] / t235 / M[2] /
              t220) + n3p * (((((2.0 * M[0] * (((-x[12] * x[11] * t339 * t220 +
    ((t726 * d_Ts_tmp_tmp_tmp / 2.0 - x[11] * x[12] * std::cos(x[6]) * std::sin
      (x[3])) * f_Ts_tmp_tmp_tmp + t699 * h_Ts_tmp_tmp_tmp / 2.0) * Ts_tmp) +
    (j_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - p_Ts_tmp_tmp_tmp *
     c_Ts_tmp_tmp_tmp) * x[11] * b_Ts_tmp_tmp_tmp) - x[11] * x[11] * (std::cos
    (x[5]) * std::sin(x[6]) * std::cos(x[7]) + std::sin(x[5]) * std::sin(x[7])))
    * M[2] * t175 + t181 * (((-b_Ts_tmp_tmp * i_Ts_tmp_tmp_tmp *
    f_Ts_tmp_tmp_tmp * t220 - e_Ts_tmp_tmp_tmp * (-(x[11] * x[11]) *
    h_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + t699 *
    c_Ts_tmp_tmp_tmp) * Ts_tmp) + ((-x[12] * c_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp
    * d_Ts_tmp_tmp_tmp + v_Ts_tmp) * f_Ts_tmp_tmp_tmp - t682 * e_Ts_tmp_tmp_tmp)
    * x[11] * b_Ts_tmp_tmp_tmp) - t143) * t142) + t708 * ((((1.3333333333333333 *
    std::sin(x[7]) * x[11] * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp -
    n_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp * x[11]) * x[12] * t220 + ((t701 *
    c_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp + 1.3333333333333333 * x[12] * x[11] *
    std::cos(x[6]) * std::sin(x[3])) * f_Ts_tmp_tmp_tmp + a_tmp_tmp_tmp_tmp_tmp *
    t701) * Ts_tmp) + (-1.3333333333333333 * x[12] * h_Ts_tmp_tmp_tmp *
                       d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + n_Ts_tmp_tmp_tmp *
                       x[12] * c_Ts_tmp_tmp_tmp) * x[11] * b_Ts_tmp_tmp_tmp) +
    t51) * b_Ts_tmp) - b_Ts_tmp_tmp_tmp * ((((t597 * i_Ts_tmp_tmp_tmp * M[0] *
    Ts_tmp - e_Ts_tmp * (-x[12] * std::sin(x[7]) * std::sin(x[3]) *
    d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + jb_Ts_tmp * e_Ts_tmp_tmp_tmp *
    g_Ts_tmp_tmp_tmp) * b_Ts_tmp_tmp_tmp) - (std::cos(x[7]) * (4.0 * x[12] * x
    [11] * M[2] * std::sin(x[4]) * std::sin(x[3]) * M[0] + (M[0] + M[1]) * (M[3]
    - n3)) * std::sin(x[6]) + x[12] * x[12] * M[2] * Ts_tmp_tmp_tmp *
    i_Ts_tmp_tmp_tmp * M[0]) * f_Ts_tmp_tmp_tmp) - std::sin(x[5]) * (4.0 * x[12]
    * x[11] * M[2] * std::sin(x[4]) * std::sin(x[3]) * M[0] + (M[0] + M[1]) *
    (M[3] - n3)) * std::sin(x[7])) + t162 * (c_Ts_tmp_tmp_tmp * t470 *
    d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + g_Ts_tmp_tmp_tmp * t470 *
    h_Ts_tmp_tmp_tmp)) * Ts_tmp_tmp) + t203 * M[2] * M[0] * t262 * Ts_tmp) - 2.0
              * f_Ts_tmp_tmp_tmp * Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp *
              d_Ts_tmp_tmp * t162) / M[0] / t235 / M[2] / t142 / t220) + n3pp *
            (((2.0 * M[0] * (-std::sin(x[3]) * c_Ts_tmp_tmp_tmp *
    d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - u_Ts_tmp) * x[11] * b_Ts_tmp_tmp_tmp *
               M[2] * t175 + t181 * (((std::sin(x[7]) * x[11] * std::sin(x[6]) *
    f_Ts_tmp_tmp_tmp - t223) * t220 + t584 * i_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp
    * Ts_tmp) + t65 * x[11] * b_Ts_tmp_tmp_tmp) * t142) + t708 *
              ((0.66666666666666663 * i_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp * x[12]
                * t220 + (-0.66666666666666663 * x[12] * std::sin(x[7]) *
    e_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + 0.66666666666666663
    * x[12] * std::cos(x[7]) * std::sin(x[3]) * g_Ts_tmp_tmp_tmp) * Ts_tmp) +
               (0.66666666666666663 * std::sin(x[3]) * c_Ts_tmp_tmp_tmp *
                d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + 0.66666666666666663 * std::
                sin(x[5]) * std::sin(x[7]) * e_Ts_tmp_tmp_tmp) * x[11] *
               b_Ts_tmp_tmp_tmp) * b_Ts_tmp) + 2.0 * Ts_tmp * M[0] *
             Ts_tmp_tmp_tmp * M[2] * x[12] * t262 * Ts_tmp_tmp) / M[0] / t235 /
            M[2] / t142 / t220) + n3ppp * ((2.0 * M[0] * (-std::cos(x[5]) * std::
              sin(x[6]) * std::cos(x[7]) / 2.0 - a_tmp_tmp_tmp_tmp_tmp / 2.0) *
             Ts_tmp * M[2] * t175 + t181 * (i_Ts_tmp_tmp * t220 / 2.0 -
              e_Ts_tmp_tmp_tmp * (t395 / 2.0 - a_tmp_tmp_tmp / 2.0) * Ts_tmp) *
             t142) + t708 * (t342 / 3.0 + a_tmp_tmp_tmp_tmp_tmp / 3.0) * Ts_tmp *
            b_Ts_tmp) / M[0] / t235 / M[2] / t142 / t220) + (((((-4.0 * x[11] *
    t162 * b_Ts_tmp_tmp_tmp * ((((((j_Ts_tmp_tmp * (n_Ts_tmp_tmp - 2.0) *
    ab_Ts_tmp + t176 * (n_Ts_tmp - 0.5) * f_Ts_tmp_tmp_tmp) + j_Ts_tmp_tmp) *
    Ts_tmp - i_Ts_tmp_tmp * e_Ts_tmp_tmp_tmp * t262 * b_Ts_tmp_tmp_tmp) -
    j_Ts_tmp_tmp * (i_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp - 2.0) *
    (f_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp)) - t176 * (c_Ts_tmp_tmp_tmp *
    c_Ts_tmp_tmp_tmp - 0.5) * f_Ts_tmp_tmp_tmp) - j_Ts_tmp_tmp) * rt_powd_snf
    (Ts_tmp_tmp, 5.0) + t692 * b_Ts_tmp_tmp_tmp * (((-2.0 * f_Ts_tmp_tmp_tmp *
    i_Ts_tmp_tmp_tmp * t339 * t220 + ((((t50 - 2.0 * n_Ts_tmp_tmp) + 1.0) *
    ab_Ts_tmp - t161) + n_Ts_tmp) * e_Ts_tmp_tmp_tmp * Ts_tmp) + t408 *
    i_Ts_tmp_tmp_tmp * t339 * b_Ts_tmp_tmp_tmp) - 2.0 * e_Ts_tmp_tmp_tmp * t184)
    * Ts_tmp_tmp_tmp * t175) + ((((2.0 * t89 * t162 * x[12] * t721 + (((((8.0 *
    h_Ts_tmp_tmp_tmp * x[11] * t162 * n_Ts_tmp_tmp + 2.0 * i_Ts_tmp_tmp_tmp *
    d_Ts_tmp_tmp_tmp * n3p) - 16.0 * h_Ts_tmp_tmp_tmp * x[11] * t162) *
    c_Ts_tmp_tmp_tmp + 4.0 * x[12] * h_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * t162) * ab_Ts_tmp - 4.0 * std::sin(x[5])
    * (((-4.0 * x[11] * d_Ts_tmp_tmp_tmp * t162 * n_Ts_tmp + x[12] * std::cos(x
    [6]) * std::sin(x[3]) * (M[3] - n3) * c_Ts_tmp_tmp_tmp) - db_Ts_tmp * n3p /
        2.0) + 2.0 * x[11] * d_Ts_tmp_tmp_tmp * t162) * f_Ts_tmp_tmp_tmp) + 8.0 *
    c_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp * x[11] * t162) * t220) + ((((((-8.0 *
    x[12] * (n_Ts_tmp_tmp - 2.0) * t162 * n_Ts_tmp - 8.0 * e_Ts_tmp_tmp_tmp *
    ((t247 / 4.0 + t427 * i_Ts_tmp_tmp_tmp) + t349) * c_Ts_tmp_tmp_tmp) - 2.0 *
    x[12] * (n_Ts_tmp_tmp + 4.0) * t162) * ab_Ts_tmp + 16.0 * g_Ts_tmp_tmp_tmp *
    ((n_Ts_tmp * e_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * n3p / 4.0 + x[12] * std::
      sin(x[7]) * std::sin(x[6]) * t162 * c_Ts_tmp_tmp_tmp) - (t366 + t271) *
     e_Ts_tmp_tmp_tmp / 2.0) * f_Ts_tmp_tmp_tmp) - 8.0 * x[12] * t162 * n_Ts_tmp)
    + 2.0 * std::cos(x[7]) * h_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * n3p) + 6.0 *
    x[12] * t162) * Ts_tmp) + (((((-6.0 * h_Ts_tmp_tmp_tmp * x[11] * t162 *
    n_Ts_tmp_tmp + 2.0 * std::cos(x[6]) * std::sin(x[6]) * n3p) + 12.0 *
    h_Ts_tmp_tmp_tmp * x[11] * t162) * c_Ts_tmp_tmp_tmp + 4.0 * x[12] * std::sin
    (x[7]) * std::cos(x[6]) * std::sin(x[3]) * std::sin(x[6]) * (M[3] - n3)) *
    ab_Ts_tmp - 4.0 * std::sin(x[5]) * (((3.0 * x[11] * d_Ts_tmp_tmp_tmp * t162 *
    n_Ts_tmp + x[12] * std::cos(x[6]) * std::sin(x[3]) * (M[3] - n3) * std::cos
    (x[7])) - std::sin(x[7]) * std::cos(x[6]) * n3p / 2.0) - 1.5 * x[11] * std::
    sin(x[6]) * (M[3] - n3)) * f_Ts_tmp_tmp_tmp) - 6.0 * c_Ts_tmp_tmp_tmp *
    h_Ts_tmp_tmp_tmp * x[11] * t162) * b_Ts_tmp_tmp_tmp) - 4.0 *
    f_Ts_tmp_tmp_tmp * x[11] * i_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * t262 * t162)
    * t142) - 8.0 * (((x[12] * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * t262 * t162
                       * t220 + ((((((((n3p * (n_Ts_tmp_tmp - 2.0) * n_Ts_tmp /
    4.0 + t56 * (n_Ts_tmp_tmp - 2.0) * t162 * c_Ts_tmp_tmp_tmp) + n_Ts_tmp_tmp *
    n3p / 4.0) - 0.75 * d_Ts_tmp_tmp_tmp * x[11] * h_Ts_tmp_tmp_tmp * t162 *
    i_Ts_tmp_tmp_tmp) + n3p / 4.0) * ab_Ts_tmp + q_Ts_tmp_tmp_tmp *
    ((m_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * t162 * n_Ts_tmp + (0.375 * x[11] *
    i_Ts_tmp_tmp_tmp * t162 - t711 / 4.0) * c_Ts_tmp_tmp_tmp) - t305 / 2.0) *
    f_Ts_tmp_tmp_tmp) + n_Ts_tmp * n3p / 4.0) + t13 * c_Ts_tmp_tmp_tmp) - n3p /
    4.0) * Ts_tmp) + ((((-x[11] * e_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp - 2.0) * t162
    * n_Ts_tmp / 2.0 + m_Ts_tmp_tmp * d_Ts_tmp_tmp_tmp * t162 * c_Ts_tmp_tmp_tmp
    / 2.0) - 0.75 * e_Ts_tmp_tmp_tmp * ((t361 + std::sin(x[7]) * std::cos(x[6]) *
    d_Ts_tmp_tmp_tmp * n3p / 3.0) + 0.66666666666666663 * x[11] * t162)) *
                       ab_Ts_tmp + g_Ts_tmp_tmp_tmp * (2.0 * (t603 / 4.0 + std::
    sin(x[7]) * x[11] * (M[3] - n3) * std::sin(x[6])) * e_Ts_tmp_tmp_tmp *
    c_Ts_tmp_tmp_tmp + j_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * t162) *
                       f_Ts_tmp_tmp_tmp / 2.0) - t584 * (c_Ts_tmp_tmp_tmp - 1.0)
                      * (c_Ts_tmp_tmp_tmp + 1.0) * t162 / 2.0) *
                      b_Ts_tmp_tmp_tmp) + ib_Ts_tmp * i_Ts_tmp_tmp_tmp * t339 *
                     t162 / 2.0) * Ts_tmp_tmp_tmp * b_Ts_tmp) + ((s_Ts_tmp *
    (((((t50 + 1.5 * n_Ts_tmp_tmp) + 1.0) * ab_Ts_tmp - t161) + n_Ts_tmp) - 1.0)
    * x[12] * Ts_tmp - 6.0 * i_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp / 3.0 + t13) *
    d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - g_Ts_tmp_tmp_tmp * (t623 -
    l_Ts_tmp_tmp_tmp / 3.0)) * f_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp) + 4.0 * std::
    cos(x[5]) * x[11] * std::cos(x[6]) * std::sin(x[3]) * (std::cos(x[5]) * std::
    sin(x[6]) * std::cos(x[7]) + std::sin(x[5]) * std::sin(x[7])) * (M[3] - n3))
    * Ts_tmp_tmp) + 4.0 * x[12] * std::cos(x[5]) * Ts_tmp_tmp_tmp *
    b_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * t262 * t162) / M[0] / M[2] / t721 /
    (t222 * t222) / t175 * ((-M[2] * t142 * b_Ts_tmp_tmp_tmp * M[0] *
    b_Ts_tmp_tmp - M[2] * b_Ts_tmp_tmp_tmp * Ts_tmp_tmp * M[0] * c_Ts_tmp_tmp) +
    t153);
  Ts[6] = x[1];
  Ts[7] = x[9];
  Ts[8] = (M[3] - n3) * std::sin(x[3]) / b_Ts_tmp_tmp_tmp;
  Ts[9] = (-n3p * e_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp + t514) / Ts_tmp;
  t75 = t321 + n3pp / 3.0;
  t344 = 2.0 * b_Ts_tmp_tmp * M[2];
  t144 = 2.0 * x[11] * std::cos(x[6]) * n3p;
  t321 = c_Ts_tmp_tmp * t339;
  t223 = t321 * t162;
  t260 = -2.0 * M[0] * M[2];
  t234 = t344 * Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * M[0];
  t55 = t344 * M[0];
  t99 = t55 * t339 * t142;
  t221 = std::cos(x[5]) * std::cos(x[6]) * std::sin(x[3]) * d_Ts_tmp_tmp * t162;
  e_Ts_tmp = M[0] * M[2];
  t113 = -t142 * M[2] * M[0];
  t15 = t113 * n3pp;
  t14 = 2.0 * std::cos(x[7]) * x[11];
  t37 = 2.0 * std::sin(x[5]) * std::sin(x[7]);
  t178 = t411 * d_Ts_tmp_tmp;
  t413 = t178 * t339;
  t179 = t234 * t262 * b_Ts_tmp;
  t620 = (t99 - t179) + t221;
  f_Ts_tmp = e_Ts_tmp * Ts_tmp_tmp;
  Ts[10] = ((((t15 * t339 * t721 - M[2] * e_Ts_tmp_tmp_tmp * t142 * t220 *
               f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * M[0] * n3pp) + f_Ts_tmp *
              ((((3.0 * t75 * h_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp - t144) *
                 f_Ts_tmp_tmp_tmp - 3.0 * g_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp *
                 t75) * b_Ts_tmp + 2.0 * Ts_tmp_tmp_tmp * ((-std::cos(x[7]) *
    e_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * n3pp / 2.0 + t_Ts_tmp * t162) *
    f_Ts_tmp_tmp_tmp - u_Ts_tmp * n3pp / 2.0) * Ts_tmp_tmp) + t223) * Ts_tmp) +
             (((t260 * ((t250 * d_Ts_tmp_tmp_tmp - v_Ts_tmp * e_Ts_tmp_tmp_tmp *
    t162) * f_Ts_tmp_tmp_tmp + g_Ts_tmp_tmp_tmp * t382) * x[11] * t142 - t181 *
                ((n3p * std::cos(x[7]) + x[12] * std::sin(x[7]) * std::sin(x[3])
                  * (M[3] - n3)) * std::sin(x[6]) * std::cos(x[5]) - (x[12] *
    std::sin(x[3]) * (M[3] - n3) * std::cos(x[7]) - std::sin(x[7]) * n3p) * std::
                 sin(x[5])) * x[11] * b_Ts_tmp) + M[0] * ((x[12] * std::cos(x[6])
    * std::sin(x[3]) + t14 * d_Ts_tmp_tmp_tmp) * f_Ts_tmp_tmp_tmp + t37 * x[11])
               * t162 * M[2] * x[12] * Ts_tmp_tmp) - t413) * b_Ts_tmp_tmp_tmp) -
            t162 * t620) / M[0] / t252 / M[2] / b_Ts_tmp / t220;
  t636 = 2.0 * M[2] * M[0];
  t121 = 3.0 * t162 * b_Ts_tmp_tmp + n3pp;
  t183 = t121 * h_Ts_tmp_tmp_tmp;
  t219 = t183 * d_Ts_tmp_tmp_tmp - t144;
  t144 = t219 * f_Ts_tmp_tmp_tmp - 3.0 * std::sin(x[5]) * std::cos(x[7]) * ((M[3]
    - n3) * (x[11] * x[11]) + n3pp / 3.0);
  g_Ts_tmp = -M[3] + n3;
  t523 = M[0] * M[2] * std::cos(x[4]);
  t622 = (-std::cos(x[7]) * std::sin(x[3]) * std::sin(x[6]) * n3pp / 2.0 + x[11]
          * x[12] * std::cos(x[6]) * (M[3] - n3)) * std::cos(x[5]) - std::sin(x
    [5]) * std::sin(x[7]) * std::sin(x[3]) * n3pp / 2.0;
  t443 = ((x[12] * (M[3] - n3) * std::cos(x[7]) - std::sin(x[7]) * std::sin(x[3])
           * n3p) * std::sin(x[6]) - 1.5 * x[11] * std::cos(x[6]) * std::sin(x[3])
          * (M[3] - n3)) * std::cos(x[5]) + std::sin(x[5]) * (std::sin(x[3]) *
    n3p * std::cos(x[7]) + x[12] * std::sin(x[7]) * (M[3] - n3));
  t708 = 4.0 * x[11] * M[2];
  t444 = 2.0 * std::sin(x[4]) * x[12];
  t549 = 4.0 * x[11] * t162;
  t576 = t711 / 2.0;
  k_Ts_tmp = (std::sin(x[5]) * x[14] + std::cos(x[5]) * x[15]) / std::cos(x[6]);
  t223 += t144 * b_Ts_tmp + 2.0 * std::sin(x[4]) * ((-std::cos(x[7]) * std::sin
    (x[3]) * std::sin(x[6]) * n3pp / 2.0 + x[11] * x[12] * std::cos(x[6]) * (M[3]
    - n3)) * std::cos(x[5]) - std::sin(x[5]) * std::sin(x[7]) * std::sin(x[3]) *
    n3pp / 2.0) * std::cos(x[4]);
  t413 = ((-2.0 * M[0] * M[2] * (((x[12] * (M[3] - n3) * std::cos(x[7]) - std::
              sin(x[7]) * std::sin(x[3]) * n3p) * std::sin(x[6]) - 1.5 * x[11] *
             std::cos(x[6]) * std::sin(x[3]) * (M[3] - n3)) * std::cos(x[5]) +
            std::sin(x[5]) * (std::sin(x[3]) * n3p * std::cos(x[7]) + x[12] *
             std::sin(x[7]) * (M[3] - n3))) * x[11] * rt_powd_snf(std::cos(x[4]),
            3.0) - w_Ts_tmp * x[11] * b_Ts_tmp) + M[0] * ((x[12] * std::cos(x[6])
            * std::sin(x[3]) + 2.0 * std::cos(x[7]) * x[11] * std::sin(x[6])) *
           std::cos(x[5]) + 2.0 * std::sin(x[5]) * std::sin(x[7]) * x[11]) * (M
           [3] - n3) * M[2] * x[12] * std::cos(x[4])) - t413;
  t620 = (((-rt_powd_snf(std::cos(x[4]), 3.0) * M[2] * M[0] * n3pp * (std::cos
             (x[5]) * std::sin(x[6]) * std::sin(x[7]) - std::sin(x[5]) * std::
             cos(x[7])) * rt_powd_snf(std::cos(x[3]), 4.0) - M[2] * std::sin(x[3])
            * rt_powd_snf(std::cos(x[4]), 3.0) * rt_powd_snf(std::cos(x[3]), 3.0)
            * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * M[0] * n3pp) + t523 * t223 *
           Ts_tmp) + t413 * b_Ts_tmp_tmp_tmp) + g_Ts_tmp * t620;
  t551 = t620 / M[0] / (t252 * t252) / M[2] / b_Ts_tmp / t220;
  t578 = (j_Ts_tmp_tmp * (i_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp - 2.0) *
          (f_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp) + t176 * (c_Ts_tmp_tmp_tmp *
           c_Ts_tmp_tmp_tmp - 0.5) * f_Ts_tmp_tmp_tmp) + j_Ts_tmp_tmp;
  l_Ts_tmp = i_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  m_Ts_tmp = x[12] * d_Ts_tmp_tmp_tmp;
  o_Ts_tmp = g_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp;
  p_Ts_tmp = e_Ts_tmp * Ts_tmp_tmp_tmp;
  q_Ts_tmp = g_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp;
  r_Ts_tmp = -std::cos(x[4]) * b_Ts_tmp_tmp_tmp;
  s_Ts_tmp = g_Ts_tmp * e_Ts_tmp_tmp_tmp;
  Ts[11] = (((((((((x[11] * (((((((((4.0 * t142 * M[2] * M[0] * n3pp * t339 *
    t220 * e_Ts_tmp_tmp_tmp - M[2] * t721 * t142 * f_Ts_tmp_tmp_tmp *
    i_Ts_tmp_tmp_tmp * M[0] * n3pp) + 3.0 * M[2] * bb_Ts_tmp * t142 * Ts_tmp *
    f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * M[0] * n3pp) + t636 * b_Ts_tmp *
    Ts_tmp_tmp_tmp * (-std::cos(x[7]) * b_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp *
                      n3pp * f_Ts_tmp_tmp_tmp / 2.0 - std::sin(x[5]) * std::sin
                      (x[7]) * std::cos(x[3]) * n3pp / 2.0) * Ts_tmp) - t636 *
    Ts_tmp_tmp * t223 * b_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp) + ((t260 * ((-std::
    sin(x[7]) * b_Ts_tmp_tmp_tmp * n3p * d_Ts_tmp_tmp_tmp - v_Ts_tmp *
    b_Ts_tmp_tmp_tmp * t162) * f_Ts_tmp_tmp_tmp + q_Ts_tmp * n3p *
    c_Ts_tmp_tmp_tmp) * x[11] * t142 - t181 * (x[12] * std::sin(x[7]) * std::cos
    (x[3]) * (M[3] - n3) * std::sin(x[6]) * std::cos(x[5]) - x[12] * std::cos(x
    [3]) * (M[3] - n3) * std::cos(x[7]) * std::sin(x[5])) * x[11] * b_Ts_tmp) +
    M[0] * c_Ts_tmp_tmp * i_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp
    * t162 * M[2] * Ts_tmp_tmp) * b_Ts_tmp_tmp_tmp) - t413 * e_Ts_tmp_tmp_tmp) +
    g_Ts_tmp * (-2.0 * b_Ts_tmp_tmp * M[2] * Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp *
                M[0] * t262 * b_Ts_tmp + i_Ts_tmp_tmp * b_Ts_tmp_tmp_tmp *
                d_Ts_tmp_tmp * t162)) / M[0] / t252 / M[2] / b_Ts_tmp / t220 -
    t551 * (-Ts_tmp_tmp * e_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp
            - b_Ts_tmp_tmp_tmp * t339 * Ts_tmp_tmp)) + 3.0 * t620 / M[0] / t252 /
    M[2] / b_Ts_tmp / t721 * e_Ts_tmp_tmp_tmp) + x[12] * (((((((3.0 * b_Ts_tmp *
    M[2] * M[0] * n3pp * t339 * t721 * Ts_tmp_tmp_tmp + 3.0 * M[2] *
    e_Ts_tmp_tmp_tmp * b_Ts_tmp * t220 * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp *
    M[0] * n3pp * Ts_tmp_tmp_tmp) - p_Ts_tmp * t223 * Ts_tmp) + t523 * ((-2.0 *
    t144 * Ts_tmp_tmp * Ts_tmp_tmp_tmp + 2.0 * b_Ts_tmp * t622) - 2.0 *
    cb_Ts_tmp * t622) * Ts_tmp) + (((6.0 * M[0] * M[2] * t443 * x[11] * b_Ts_tmp
    * Ts_tmp_tmp_tmp - 2.0 * M[0] * t142 * M[2] * t671 * x[11]) + 4.0 * M[0] *
    cb_Ts_tmp * M[2] * t671 * x[11] * Ts_tmp_tmp) - M[0] * ((x[12] * std::cos(x
    [6]) * std::sin(x[3]) + 2.0 * std::cos(x[7]) * x[11] * std::sin(x[6])) * std::
    cos(x[5]) + 2.0 * std::sin(x[5]) * std::sin(x[7]) * x[11]) * (M[3] - n3) *
    M[2] * x[12] * Ts_tmp_tmp_tmp) * b_Ts_tmp_tmp_tmp) + g_Ts_tmp * ((-6.0 *
    b_Ts_tmp_tmp * M[2] * M[0] * t339 * b_Ts_tmp * Ts_tmp_tmp_tmp - t344 * t142 *
    e_Ts_tmp_tmp_tmp * M[0] * t262) + 4.0 * b_Ts_tmp_tmp * M[2] * cb_Ts_tmp *
    e_Ts_tmp_tmp_tmp * M[0] * t262 * Ts_tmp_tmp)) / M[0] / t252 / M[2] /
    b_Ts_tmp / t220 - t551 * ((-Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp *
    f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp + t610 * Ts_tmp_tmp_tmp) + std::cos(x[4])
    * (std::cos(x[5]) * std::sin(x[6]) * std::cos(x[7]) + std::sin(x[5]) * std::
       sin(x[7])))) + 2.0 * t620 / M[0] / t252 / M[2] / t142 / t220 *
    Ts_tmp_tmp_tmp)) + ((std::sin(x[5]) * std::sin(x[6]) * x[14] + std::cos(x[5])
    * std::sin(x[6]) * x[15]) + x[13] * std::cos(x[6])) / std::cos(x[6]) *
                   (((((t15 * t706 * t721 + M[2] * std::sin(x[3]) * rt_powd_snf
                        (std::cos(x[4]), 3.0) * rt_powd_snf(std::cos(x[3]), 3.0)
                        * g_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * M[0] * n3pp) +
                       t523 * (((-t219 * g_Ts_tmp_tmp_tmp - 3.0 *
    f_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp * t75) * b_Ts_tmp + 2.0 * std::sin(x[4])
    * (-(-std::cos(x[7]) * std::sin(x[3]) * std::sin(x[6]) * n3pp / 2.0 + x[11] *
         x[12] * std::cos(x[6]) * (M[3] - n3)) * g_Ts_tmp_tmp_tmp -
       o_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * n3pp / 2.0) * Ts_tmp_tmp) +
    c_Ts_tmp_tmp * t706 * t162) * Ts_tmp) + (((t260 * (-((x[12] * (M[3] - n3) *
    std::cos(x[7]) - std::sin(x[7]) * std::sin(x[3]) * n3p) * std::sin(x[6]) -
    1.5 * x[11] * std::cos(x[6]) * std::sin(x[3]) * (M[3] - n3)) *
    g_Ts_tmp_tmp_tmp + f_Ts_tmp_tmp_tmp * t382) * x[11] * t142 - t181 * (-(n3p *
    std::cos(x[7]) + x[12] * std::sin(x[7]) * std::sin(x[3]) * (M[3] - n3)) *
    std::sin(x[6]) * std::sin(x[5]) + (-x[12] * std::sin(x[3]) * (M[3] - n3) *
    std::cos(x[7]) + std::sin(x[7]) * n3p) * std::cos(x[5])) * x[11] * b_Ts_tmp)
    + M[0] * (-(x[12] * std::cos(x[6]) * std::sin(x[3]) + 2.0 * std::cos(x[7]) *
                x[11] * std::sin(x[6])) * g_Ts_tmp_tmp_tmp + t408 *
              h_Ts_tmp_tmp_tmp * x[11]) * t162 * M[2] * x[12] * Ts_tmp_tmp) -
    t178 * t706) * b_Ts_tmp_tmp_tmp) + g_Ts_tmp * ((t55 * t706 * t142 - t234 *
    t469 * b_Ts_tmp) - o_Ts_tmp * e_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp * t162)) / M[0]
                    / t252 / M[2] / b_Ts_tmp / t220 - t551 * ((r_Ts_tmp *
    g_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp - e_Ts_tmp_tmp_tmp * t706 * Ts_tmp_tmp)
    + std::sin(x[4]) * (-std::sin(x[5]) * std::sin(x[6]) * std::cos(x[7]) + std::
                        cos(x[5]) * std::sin(x[7]))))) + (std::cos(x[5]) * x[14]
    - std::sin(x[5]) * x[15]) * (((((t15 * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp *
    h_Ts_tmp_tmp_tmp * t721 + M[2] * std::sin(x[3]) * rt_powd_snf(std::cos(x[4]),
    3.0) * rt_powd_snf(std::cos(x[3]), 3.0) * f_Ts_tmp_tmp_tmp *
    d_Ts_tmp_tmp_tmp * M[0] * n3pp) + t523 * (((t183 * i_Ts_tmp_tmp_tmp + 2.0 *
    x[11] * std::sin(x[6]) * n3p) * f_Ts_tmp_tmp_tmp * b_Ts_tmp + 2.0 * std::sin
    (x[4]) * (-std::cos(x[7]) * std::sin(x[3]) * i_Ts_tmp_tmp_tmp * n3pp / 2.0 -
              x[11] * x[12] * std::sin(x[6]) * t162) * f_Ts_tmp_tmp_tmp *
    Ts_tmp_tmp) + c_Ts_tmp_tmp * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp *
    h_Ts_tmp_tmp_tmp * t162) * Ts_tmp) + (((t260 * (t250 * i_Ts_tmp_tmp_tmp +
    1.5 * x[11] * std::sin(x[6]) * e_Ts_tmp_tmp_tmp * t162) * f_Ts_tmp_tmp_tmp *
    x[11] * t142 - t181 * t199 * i_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp * x[11] *
    b_Ts_tmp) + M[0] * (-x[12] * d_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp + t14 *
                        i_Ts_tmp_tmp_tmp) * f_Ts_tmp_tmp_tmp * t162 * M[2] * x
    [12] * Ts_tmp_tmp) - t178 * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp *
    h_Ts_tmp_tmp_tmp) * b_Ts_tmp_tmp_tmp) + g_Ts_tmp * ((t55 * f_Ts_tmp_tmp_tmp *
    i_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp * t142 - t234 * f_Ts_tmp_tmp_tmp *
    i_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp * b_Ts_tmp) - t6 * e_Ts_tmp_tmp_tmp *
    d_Ts_tmp_tmp * t162)) / M[0] / t252 / M[2] / b_Ts_tmp / t220 - t551 * ((-std::
    cos(x[4]) * std::cos(x[3]) * f_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp -
    e_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp *
    Ts_tmp_tmp) + std::sin(x[4]) * std::cos(x[5]) * std::cos(x[6]) * std::cos(x
    [7])))) + k_Ts_tmp * ((((t15 * t262 * t721 + t523 * (((t121 *
    c_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + 3.0 * std::sin(x[5])
    * h_Ts_tmp_tmp_tmp * t75) * b_Ts_tmp + 2.0 * std::sin(x[4]) * (t629 *
    d_Ts_tmp_tmp_tmp * n3pp * f_Ts_tmp_tmp_tmp / 2.0 - a_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp * n3pp / 2.0) * Ts_tmp_tmp) + c_Ts_tmp_tmp * t262 * t162) *
    Ts_tmp) + (((t260 * ((-std::sin(x[3]) * n3p * std::cos(x[7]) - x[12] * std::
    sin(x[7]) * (M[3] - n3)) * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + t604) * x
                 [11] * t142 - t181 * ((x[12] * std::sin(x[3]) * (M[3] - n3) *
    std::cos(x[7]) - std::sin(x[7]) * n3p) * std::sin(x[6]) * std::cos(x[5]) +
    std::sin(x[5]) * (n3p * std::cos(x[7]) + x[12] * std::sin(x[7]) * std::sin
                      (x[3]) * (M[3] - n3))) * x[11] * b_Ts_tmp) + M[0] * (-2.0 *
    h_Ts_tmp_tmp_tmp * x[11] * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp +
    q_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp * x[11]) * t162 * M[2] * x[12] *
                Ts_tmp_tmp) - t178 * t262) * b_Ts_tmp_tmp_tmp) + g_Ts_tmp * (t55
    * t262 * t142 - t234 * t65 * b_Ts_tmp)) / M[0] / t252 / M[2] / b_Ts_tmp /
    t220 - t551 * (-std::sin(x[3]) * t262 * Ts_tmp_tmp + std::sin(x[4]) * (-std::
    cos(x[5]) * std::sin(x[6]) * std::sin(x[7]) + std::sin(x[5]) * std::cos(x[7])))))
                + 2.0 * x[12] * x[11] * std::sin(x[4]) / t142 * ((t523 * (((6.0 *
    h_Ts_tmp_tmp_tmp * x[11] * t162 * d_Ts_tmp_tmp_tmp - 2.0 * std::cos(x[6]) *
    n3p) * f_Ts_tmp_tmp_tmp - 6.0 * std::cos(x[7]) * g_Ts_tmp_tmp_tmp * x[11] *
    t162) * b_Ts_tmp + t444 * i_Ts_tmp_tmp_tmp * t162 * f_Ts_tmp_tmp_tmp *
    Ts_tmp_tmp) * Ts_tmp + (((t537 * i_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * t162 *
    f_Ts_tmp_tmp_tmp * x[11] * t142 - 2.0 * M[0] * M[2] * t443 * t142) -
    w_Ts_tmp * b_Ts_tmp) + M[0] * (t559 * c_Ts_tmp_tmp_tmp + t37) * t162 * M[2] *
    x[12] * Ts_tmp_tmp) * b_Ts_tmp_tmp_tmp) + g_Ts_tmp * (t708 * M[0] * t339 *
    t142 - t708 * Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * M[0] * t262 * b_Ts_tmp)) /
                M[0] / t252 / M[2] / t220) - b_Ts_tmp_tmp / Ts_tmp_tmp *
               Ts_tmp_tmp_tmp * (t523 * (2.0 * std::sin(x[4]) * x[11] *
    i_Ts_tmp_tmp_tmp * t162 * f_Ts_tmp_tmp_tmp * Ts_tmp_tmp + 2.0 * x[12] * t339
    * t162) * Ts_tmp + (((t260 * (t162 * c_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp *
    f_Ts_tmp_tmp_tmp + a_tmp_tmp_tmp_tmp_tmp * t162) * x[11] * t142 - t181 *
    (std::sin(x[7]) * std::sin(x[3]) * (M[3] - n3) * std::sin(x[6]) * std::cos
     (x[5]) - std::sin(x[3]) * (M[3] - n3) * std::cos(x[7]) * std::sin(x[5])) *
    x[11] * b_Ts_tmp) + M[0] * e_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp *
    i_Ts_tmp_tmp_tmp * t162 * M[2] * x[12] * Ts_tmp_tmp) + M[0] * ((x[12] * std::
    cos(x[6]) * std::sin(x[3]) + 2.0 * std::cos(x[7]) * x[11] * std::sin(x[6])) *
    std::cos(x[5]) + 2.0 * std::sin(x[5]) * std::sin(x[7]) * x[11]) * (M[3] - n3)
                        * M[2] * Ts_tmp_tmp) * b_Ts_tmp_tmp_tmp) / M[0] / t252 /
               M[2] / t220) + n3p * (((((t523 * (((-3.0 * b_Ts_tmp_tmp *
    h_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + 3.0 * std::sin(x[5])
    * b_Ts_tmp_tmp * c_Ts_tmp_tmp_tmp) * b_Ts_tmp - t444 * x[11] *
    i_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp * Ts_tmp_tmp) - t321) * Ts_tmp + (((t260
    * ((-x[12] * std::cos(x[7]) * d_Ts_tmp_tmp_tmp + 1.5 * x[11] * std::cos(x[6])
        * std::sin(x[3])) * f_Ts_tmp_tmp_tmp - t682) * x[11] * t142 - t181 *
    (-x[12] * std::sin(x[7]) * std::sin(x[3]) * std::sin(x[6]) * std::cos(x[5])
     + x[12] * std::cos(x[7]) * std::sin(x[3]) * std::sin(x[5])) * x[11] *
    b_Ts_tmp) - M[0] * ((x[12] * std::cos(x[6]) * std::sin(x[3]) + 2.0 * std::
    cos(x[7]) * x[11] * std::sin(x[6])) * std::cos(x[5]) + 2.0 * std::sin(x[5]) *
                        std::sin(x[7]) * x[11]) * M[2] * x[12] * Ts_tmp_tmp) +
    x_Ts_tmp * d_Ts_tmp_tmp * t339) * b_Ts_tmp_tmp_tmp) + t99) - t179) + t221) -
    s_Ts_tmp * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp) / M[0] / t252
              / M[2] / b_Ts_tmp / t220) + n3pp * (-2.0 * M[2] * M[0] * t142 * x
              [11] * i_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp * Ts_tmp + (t260 *
    (-std::sin(x[7]) * e_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp +
     g_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp) * x[11] * t142 -
    t181 * t262 * x[11] * b_Ts_tmp) * b_Ts_tmp_tmp_tmp) / M[0] / t252 / M[2] /
             b_Ts_tmp / t220) + n3ppp * ((t113 * t339 * t721 - M[2] * std::sin
              (x[3]) * rt_powd_snf(std::cos(x[4]), 3.0) * rt_powd_snf(std::cos
    (x[3]), 3.0) * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * M[0]) + t523 * (t339 *
              b_Ts_tmp + 2.0 * std::sin(x[4]) * (-std::sin(x[3]) * std::cos(x[7])
    * std::sin(x[6]) * std::cos(x[5]) / 2.0 - u_Ts_tmp / 2.0) * Ts_tmp_tmp) *
             Ts_tmp) / M[0] / t252 / M[2] / b_Ts_tmp / t220) + (((-8.0 * ((x[11]
    * t89 * t162 * t142 / 4.0 + (((((x[11] * (n_Ts_tmp_tmp - 2.0) * t162 *
    n_Ts_tmp / 2.0 - t361) - std::sin(x[7]) * std::cos(x[6]) * std::sin(x[6]) *
    n3p / 2.0) + t514 / 2.0) * ab_Ts_tmp - a_tmp_tmp_tmp * t675 *
    f_Ts_tmp_tmp_tmp) + n_Ts_tmp * x[11] * t162 / 2.0) * Ts_tmp_tmp) + x[12] *
    std::cos(x[5]) * Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * t339 * t162) *
    Ts_tmp_tmp * t220 + ((((-4.0 * f_Ts_tmp_tmp_tmp * x[11] * i_Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp * t339 * t162 * t175 + 4.0 * std::cos(x[5]) * x[11] *
    Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * t262 * t162 * t142) + ((((-2.0 *
    e_Ts_tmp_tmp_tmp * n3p * (n_Ts_tmp_tmp - 2.0) * n_Ts_tmp - 4.0 * x[12] * std::
    sin(x[7]) * (n_Ts_tmp_tmp - 2.0) * t162 * c_Ts_tmp_tmp_tmp) - 8.0 * std::sin
    (x[3]) * ((-n_Ts_tmp_tmp * n3p / 2.0 + k_Ts_tmp_tmp * h_Ts_tmp_tmp_tmp *
               t162 * i_Ts_tmp_tmp_tmp) + n3p / 4.0)) * ab_Ts_tmp - 8.0 *
    g_Ts_tmp_tmp_tmp * ((m_Ts_tmp * t162 * n_Ts_tmp - (y_Ts_tmp * t162 + t576) *
    e_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp) - x[12] * std::sin(x[6]) * (M[3] - n3) /
                        2.0) * f_Ts_tmp_tmp_tmp) - 4.0 * t172 * c_Ts_tmp_tmp_tmp)
    * b_Ts_tmp) + 4.0 * ((((m_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp - 2.0) * t162 *
    n_Ts_tmp + ((t247 / 2.0 + x[11] * std::sin(x[6]) * (M[3] - n3) * std::cos(x
    [6]) / 2.0) + l_Ts_tmp_tmp_tmp) * c_Ts_tmp_tmp_tmp) - x_Ts_tmp *
    (n_Ts_tmp_tmp - 0.5) * e_Ts_tmp_tmp_tmp * x[12]) * ab_Ts_tmp -
    q_Ts_tmp_tmp_tmp * (((n_Ts_tmp * d_Ts_tmp_tmp_tmp * n3p / 2.0 + t56 *
    d_Ts_tmp_tmp_tmp * t162 * c_Ts_tmp_tmp_tmp) - t366 / 4.0) - t271) *
    f_Ts_tmp_tmp_tmp) + c_Ts_tmp_tmp_tmp * (t623 - t349)) * Ts_tmp_tmp_tmp *
    Ts_tmp_tmp) + x_Ts_tmp * t578 * x[12]) * Ts_tmp) + ((((t549 * t184 * t175 +
    t549 * t578 * e_Ts_tmp_tmp_tmp * Ts_tmp_tmp_tmp * t142) + ((4.0 *
    i_Ts_tmp_tmp_tmp * ((t305 * c_Ts_tmp_tmp_tmp - 2.0 * x[11] * std::cos(x[6]) *
    (M[3] - n3)) - t576) * ab_Ts_tmp + 4.0 * std::sin(x[5]) * i_Ts_tmp_tmp_tmp *
    (f_Ts_tmp_tmp / 2.0 + t13) * f_Ts_tmp_tmp_tmp) + t692) * b_Ts_tmp) + 4.0 *
    (((((t11 * n_Ts_tmp_tmp + l_Ts_tmp * n3p) - 2.0 * std::sin(x[7]) * x[11] *
        (M[3] - n3)) * e_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp / 2.0 + x[12] * std::
       sin(x[7]) * std::cos(x[6]) * d_Ts_tmp_tmp_tmp * t162) * ab_Ts_tmp -
      g_Ts_tmp_tmp_tmp * ((-x[11] * std::sin(x[3]) * d_Ts_tmp_tmp_tmp * t162 *
    n_Ts_tmp + m_Ts_tmp_tmp * t162 * c_Ts_tmp_tmp_tmp) + (-std::sin(x[7]) *
    i_Ts_tmp_tmp_tmp * n3p + t427) * e_Ts_tmp_tmp_tmp / 2.0) * f_Ts_tmp_tmp_tmp)
     + j_Ts_tmp_tmp * x[11] * e_Ts_tmp_tmp_tmp * t162 / 2.0) * Ts_tmp_tmp_tmp *
    Ts_tmp_tmp) - 2.0 * x[12] * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp * t262 * t162) * b_Ts_tmp_tmp_tmp) - 4.0 * (-std::sin(x[3])
    * t339 * Ts_tmp_tmp + t388) * x[11] * i_Ts_tmp_tmp_tmp * t162 *
    f_Ts_tmp_tmp_tmp * Ts_tmp_tmp) / M[0] / M[2] / t721 / t252 / t142 * ((-M[2] *
    rt_powd_snf(std::cos(x[4]), 3.0) * b_Ts_tmp_tmp_tmp * M[0] * (x[11] * x[11])
    - M[2] * std::cos(x[3]) * std::cos(x[4]) * M[0] * (x[12] * x[12])) + (M[0] +
    M[1]) * (M[3] - n3)) / t222;
  Ts[12] = x[2];
  Ts[13] = x[10];
  Ts[14] = x[7];
  Ts[15] = k_Ts_tmp;
  for (int i{0}; i < 14; i++) {
    z[i] = -(yr[i] - Ts[i]);
  }

  double b_t298_tmp;
  double t110;
  double t112;
  double t114;
  double t115;
  double t124;
  double t134;
  double t153_tmp;
  double t177_tmp;
  double t184_tmp;
  double t205_tmp;
  double t216;
  double t217;
  double t255;
  double t275_tmp;
  double t287_tmp;
  double t288_tmp;
  double t298_tmp;
  double t303;
  double t322;
  double t329;
  double t332;
  double t336;
  double t338;
  double t341;
  double t357;
  double t359;
  double t360;
  double t376_tmp;
  double t384;
  double t386_tmp;
  double t38_tmp;
  double t393;
  double t408_tmp;
  double t424;
  double t493;
  double t497;
  double t518;
  double t519;
  double t531;
  double t535;
  double t564;
  double t611;
  double t612;
  double t613;
  double t616;
  double t621;
  double t627;
  double t628;
  double t644;
  double t647;
  double t650;
  double t667;
  double t668;
  double t669;
  double t669_tmp;
  double t672;
  double t674;
  double t680_tmp;
  double t85;
  double t86;
  z[14] = -(yr[18] - x[7]);
  z[15] = -(0.02 - k_Ts_tmp);
  t11 = i_Ts_tmp_tmp_tmp * n_Ts_tmp_tmp;
  t13 = c_Ts_tmp_tmp_tmp * n_Ts_tmp;
  t14 = (n_Ts_tmp_tmp + -4.0) * n_Ts_tmp;
  t15 = t14 + 1.0;
  t16 = 4.0 * n_Ts_tmp_tmp;
  t20 = (n_Ts_tmp_tmp + -1.3333333333333333) * n_Ts_tmp;
  t22 = 2.0 * n_Ts_tmp_tmp;
  t24 = f_Ts_tmp_tmp_tmp * ab_Ts_tmp;
  t25 = d_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp;
  t26 = t13 * g_Ts_tmp_tmp_tmp;
  t27 = t25 * c_Ts_tmp_tmp_tmp;
  t29 = (-3.0 * h_Ts_tmp_tmp * (-t27 + f_Ts_tmp_tmp_tmp * ((t20 + 1.0) - t22) *
          g_Ts_tmp_tmp_tmp) - t26) + t25 * ((t14 + 1.0) - t16) * t24;
  t35 = 3.0 * n_Ts_tmp_tmp;
  t37 = db_Ts_tmp * n3p;
  t38 = t37 * (-t35 + 6.0);
  t41 = 2.5 * n_Ts_tmp;
  t42 = (n_Ts_tmp_tmp + -2.0) * n_Ts_tmp;
  t43_tmp = i_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp;
  t44 = t43_tmp * g_Ts_tmp;
  t46 = h_Ts_tmp * d_Ts_tmp_tmp_tmp;
  t47_tmp = x[11] * g_Ts_tmp;
  t48 = t44 * t25 * x[12];
  t50 = 0.83333333333333337 * n_Ts_tmp_tmp;
  t51 = t46 * 0.5;
  t54 = m_Ts_tmp_tmp_tmp * g_Ts_tmp;
  t55 = t54 * c_Ts_tmp_tmp_tmp;
  t56 = k_Ts_tmp_tmp * g_Ts_tmp;
  t58 = a_tmp_tmp_tmp_tmp_tmp * t47_tmp;
  t61 = n_Ts_tmp_tmp * 0.6;
  t62 = t47_tmp * db_Ts_tmp;
  t63 = t62 * (2.0 - n_Ts_tmp_tmp);
  t65 = (1.0 - i_Ts_tmp_tmp_tmp) * (i_Ts_tmp_tmp_tmp + 1.0);
  t66 = n_Ts_tmp * (i_Ts_tmp_tmp_tmp + -2.0) * (i_Ts_tmp_tmp_tmp + 2.0);
  t67 = 1.5 * l_Ts_tmp_tmp;
  t68 = t56 * i_Ts_tmp_tmp_tmp;
  t69_tmp = x[12] * g_Ts_tmp;
  t70 = t69_tmp * c_Ts_tmp_tmp_tmp;
  t72_tmp = e_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp;
  t73 = t69_tmp * t25;
  t76 = k_Ts_tmp_tmp * (i_Ts_tmp_tmp_tmp + -2.0) * (i_Ts_tmp_tmp_tmp + 2.0);
  t77 = t76 * c_Ts_tmp_tmp_tmp;
  t78 = t43_tmp * x[12];
  t79 = t78 * (n_Ts_tmp_tmp + -2.0);
  t80 = g_Ts_tmp * n_Ts_tmp;
  t81 = 1.5 * n_Ts_tmp_tmp;
  t83 = t47_tmp * (-t81 + 2.0) * h_Ts_tmp_tmp_tmp;
  t86 = n_Ts_tmp * 18.0;
  t87 = 6.0 * n_Ts_tmp;
  t88 = t47_tmp * h_Ts_tmp_tmp_tmp;
  t89 = 0.21428571428571427 * n_Ts_tmp_tmp;
  t90 = t63 + l_Ts_tmp_tmp * (t89 + -0.8571428571428571);
  t91 = n_Ts_tmp * 4.0;
  t92 = n3p * t13;
  t93 = t92 * e_Ts_tmp_tmp_tmp;
  t97 = 1.1666666666666667 * (-t68 + l_Ts_tmp_tmp_tmp * (-0.42857142857142855 *
    n_Ts_tmp_tmp + 0.5714285714285714));
  t98 = t70 * (0.75 - n_Ts_tmp);
  t99 = -t62 + 0.6428571428571429 * l_Ts_tmp_tmp;
  t100 = n_Ts_tmp * 0.5;
  t101 = l_Ts_tmp_tmp_tmp * (-t100 + 0.125);
  t105 = a_tmp_tmp_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp;
  t106 = (c_Ts_tmp_tmp_tmp * ((i_Ts_tmp_tmp_tmp + -2.0) * (n_Ts_tmp + -0.75) *
           d_Ts_tmp_tmp_tmp * (i_Ts_tmp_tmp_tmp + 2.0) * t24 + t105) + 3.0 *
          f_Ts_tmp_tmp_tmp * (a_tmp_tmp_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp + -0.5) *
           (c_Ts_tmp_tmp_tmp + 0.5) * (n_Ts_tmp_tmp + -1.3333333333333333) *
           f_Ts_tmp_tmp_tmp + (n_Ts_tmp + -0.75) * d_Ts_tmp_tmp_tmp *
           c_Ts_tmp_tmp_tmp)) - a_tmp_tmp_tmp_tmp_tmp * 0.25;
  t41 = (b_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp *
            (f_Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp * ((t38 + k_Ts_tmp_tmp *
    (-n_Ts_tmp_tmp * 5.0 + 7.5) * g_Ts_tmp) + t41 * k_Ts_tmp_tmp *
    (i_Ts_tmp_tmp_tmp + -2.0) * (i_Ts_tmp_tmp_tmp + 2.0) * g_Ts_tmp) + t44 *
              ((n_Ts_tmp_tmp + -0.75) * 4.0 - 3.0 * t42) * x[12]) - 6.0 *
             g_Ts_tmp_tmp_tmp * ((t47_tmp * (t50 + -0.41666666666666669) *
    h_Ts_tmp_tmp_tmp - c_Ts_tmp_tmp_tmp * (-c_Ts_tmp_tmp_tmp * (t46 + t47_tmp *
    (-1.25 * n_Ts_tmp_tmp + 1.6666666666666667) * h_Ts_tmp_tmp_tmp) + t48)) -
              t51)) + 3.0 * c_Ts_tmp_tmp_tmp * (t56 * (t41 + -1.6666666666666667)
             - i_Ts_tmp_tmp_tmp * (l_Ts_tmp_tmp_tmp + t55))) + t58 * t41) -
          t69_tmp * t29 * b_Ts_tmp_tmp_tmp) + g_Ts_tmp_tmp_tmp *
         (c_Ts_tmp_tmp_tmp * (-0.3 * t72_tmp * l_Ts_tmp_tmp_tmp + t69_tmp * (0.6
            - n_Ts_tmp)) * 5.0 + 15.0 * ab_Ts_tmp * (e_Ts_tmp_tmp_tmp * (-(-t68
             + l_Ts_tmp_tmp_tmp * (0.3 - t61)) * 0.33333333333333331 +
            0.66666666666666663 * n_Ts_tmp * (-t68 + l_Ts_tmp_tmp_tmp * (-0.45 *
              n_Ts_tmp_tmp + 0.6))) - t70 * (t20 + t65)))) + f_Ts_tmp_tmp_tmp *
    ((ab_Ts_tmp * (5.0 * ((t63 + l_Ts_tmp_tmp * (t61 + -0.9)) * e_Ts_tmp_tmp_tmp
        * c_Ts_tmp_tmp_tmp + t25 * (t65 + t66) * x[12] * g_Ts_tmp) - t67 *
                   e_Ts_tmp_tmp_tmp * (i_Ts_tmp_tmp_tmp + -2.0) *
                   (i_Ts_tmp_tmp_tmp + 2.0) * t13) + t73 * (15.0 * n_Ts_tmp -
       3.0)) + t72_tmp * (5.0 * (l_Ts_tmp_tmp * 0.6 - t62) - 4.5 * l_Ts_tmp_tmp *
      n_Ts_tmp));
  t61 = t47_tmp * 4.0;
  t108 = 0.16666666666666666 * n_Ts_tmp_tmp;
  t109 = t47_tmp * i_Ts_tmp_tmp_tmp;
  t110 = t109 * (2.0 - n_Ts_tmp_tmp);
  t111 = t25 * (t108 + -0.66666666666666663) * n3p;
  t112 = 0.66666666666666663 * n_Ts_tmp_tmp;
  t113 = 1.3333333333333333 * t47_tmp;
  t114 = t113 * t11;
  t115 = 0.25 * n_Ts_tmp_tmp;
  t116 = n3p * (t115 + -0.33333333333333331);
  t117 = t109 * t25;
  t118 = 0.5 * n_Ts_tmp_tmp;
  t119 = 0.5 * n3p;
  t120 = t119 * t25;
  t121 = 0.16666666666666666 * n3p;
  t124 = t47_tmp * t25;
  t65 = t124 * (4.0 - n_Ts_tmp_tmp);
  t126 = h_Ts_tmp * (-t81 + 3.0);
  t127 = t70 * db_Ts_tmp;
  t128 = 2.0 * t127;
  t129 = h_Ts_tmp * t25;
  t130 = t47_tmp * n_Ts_tmp_tmp;
  t131 = t69_tmp * i_Ts_tmp_tmp_tmp;
  t132 = t131 * d_Ts_tmp_tmp_tmp;
  t133 = x[12] * i_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t134 = h_Ts_tmp * 0.5;
  t135 = t69_tmp * db_Ts_tmp;
  t136 = t72_tmp * 0.5;
  t137 = t26 * t47_tmp;
  t140 = n3p * (1.0 - n_Ts_tmp_tmp);
  t141 = t55 * d_Ts_tmp_tmp_tmp;
  t142 = t141 * (i_Ts_tmp_tmp_tmp + -2.0) * (i_Ts_tmp_tmp_tmp + 2.0);
  t143 = 2.6666666666666665 * n_Ts_tmp_tmp;
  t145 = 2.0 * m_Ts_tmp_tmp_tmp;
  t147 = t54 * h_Ts_tmp_tmp_tmp;
  t148 = t147 * (n_Ts_tmp_tmp + -1.3333333333333333);
  t149 = 0.66666666666666663 * t147 * (n_Ts_tmp_tmp + -0.5);
  t150 = 3.0 * n_Ts_tmp;
  t152 = t141 * (-t150 + 2.0);
  t153 = 0.66666666666666663 * t109;
  t155 = 0.75 * n_Ts_tmp_tmp;
  t156 = (t65 + h_Ts_tmp * (-t155 + 1.5)) * n_Ts_tmp;
  t157 = t72_tmp * x[11];
  t158 = t157 * (n_Ts_tmp_tmp + -1.3333333333333333);
  t159 = h_Ts_tmp * 0.25;
  t160 = -t124 - t159;
  t162 = t110 + t25 * (0.2857142857142857 * n_Ts_tmp_tmp - 1.1428571428571428) *
    n3p;
  t163 = t54 * d_Ts_tmp_tmp_tmp;
  t164 = 1.3333333333333333 * m_Ts_tmp_tmp_tmp;
  t165 = i_Ts_tmp_tmp_tmp * (-t124 - 0.32142857142857145 * h_Ts_tmp) +
    0.42857142857142855 * n3p;
  t166 = -t109 + 0.8571428571428571 * t25 * n3p;
  t100 -= 0.375;
  t168 = t25 * (t150 - 0.75);
  t169 = t25 * (i_Ts_tmp_tmp_tmp + -2.0) * (i_Ts_tmp_tmp_tmp + 2.0);
  t102 = a_tmp_tmp_tmp * (n_Ts_tmp + -0.75);
  t102 = (-f_Ts_tmp_tmp_tmp * (-t169 * (c_Ts_tmp_tmp_tmp + -0.5) *
           (c_Ts_tmp_tmp_tmp + 0.5) * ab_Ts_tmp - t168) - t102) - 3.0 * t102 *
    (n_Ts_tmp_tmp + -1.3333333333333333) * ab_Ts_tmp;
  t50 = (b_Ts_tmp_tmp_tmp * (((b_Ts_tmp_tmp_tmp * ((b_Ts_tmp_tmp_tmp *
              (f_Ts_tmp_tmp_tmp * (n_Ts_tmp * (-t109 + t120) + ab_Ts_tmp *
    (((t25 * (0.16666666666666666 - t112) * n3p + t114) + n_Ts_tmp * (t110 +
    t111)) - t109)) - a_tmp_tmp_tmp * (((2.0 * (0.25 - t118) * n3p + 2.0 * t116 *
    n_Ts_tmp) - 2.0 * t117) * ab_Ts_tmp + t121 * n_Ts_tmp)) + f_Ts_tmp_tmp_tmp *
              (f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp * (e_Ts_tmp_tmp_tmp *
    ((1.3333333333333333 * t124 * (0.25 - n_Ts_tmp_tmp) + 1.3333333333333333 *
      h_Ts_tmp * (0.375 - t118)) - n_Ts_tmp * (t126 + t65) * 0.33333333333333331)
    - t128 * (n_Ts_tmp_tmp + -2.0)) + g_Ts_tmp_tmp_tmp * (-0.5 * (t72_tmp * (0.5
    * (t129 + t47_tmp) - t130) - t132) - t80 * (t72_tmp * 0.25 * x[11] *
    (n_Ts_tmp_tmp + -1.3333333333333333) + t133)) * 4.0) + 2.0 *
               c_Ts_tmp_tmp_tmp * (-t136 * (-t124 - t134) - t135))) - t137 *
             0.33333333333333331 * e_Ts_tmp_tmp_tmp) + f_Ts_tmp_tmp_tmp *
            ((((ab_Ts_tmp * ((g_Ts_tmp * (i_Ts_tmp * (-t143 + 2.8333333333333335)
    + t145 * (n_Ts_tmp_tmp + -1.5) * d_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp) -
    0.83333333333333337 * t140 * t25) + n_Ts_tmp * ((-t142 + t109 *
    (2.8333333333333335 * n_Ts_tmp_tmp - 5.666666666666667)) + t25 * (-t50 +
    3.3333333333333335) * n3p)) + n_Ts_tmp * (2.8333333333333335 * t109 - 2.5 *
    t25 * n3p)) + t120) + t152) - t153)) + a_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp *
            (0.83333333333333337 * f_Ts_tmp_tmp - t147) - t119)) + (3.0 *
           ((c_Ts_tmp_tmp_tmp * (3.3333333333333335 * t116 * c_Ts_tmp_tmp_tmp -
              t148) + 0.83333333333333337 * t140) - 1.8888888888888888 * t117) *
           c_Ts_tmp_tmp_tmp + 3.0 * t149) * g_Ts_tmp_tmp_tmp * ab_Ts_tmp) +
         g_Ts_tmp_tmp_tmp * (t113 * t72_tmp * (n_Ts_tmp + -0.5) - ab_Ts_tmp * ((
            -t80 * (t133 + t158) + t132 * 0.5) - t72_tmp * 1.1666666666666667 *
           (0.42857142857142855 * t129 + t47_tmp * (0.8571428571428571 -
             n_Ts_tmp_tmp))) * 4.0)) + f_Ts_tmp_tmp_tmp * ((ab_Ts_tmp * ((-2.0 *
    e_Ts_tmp_tmp_tmp * (t124 * (0.66666666666666663 - n_Ts_tmp_tmp) + h_Ts_tmp *
                        (0.5 - t115)) + 2.0 * t127 * (n_Ts_tmp_tmp + -2.0)) +
    1.3333333333333333 * t156 * e_Ts_tmp_tmp_tmp) + e_Ts_tmp_tmp_tmp *
    ((0.66666666666666663 * t124 + h_Ts_tmp / 2.0) + t91 * t160)) + t128);
  t103 = t11 * n3p;
  t104 = t61 * t25;
  t127 = t47_tmp * (t20 + 1.0);
  t128 = 2.0 * t109;
  t133_tmp = g_Ts_tmp * c_Ts_tmp_tmp;
  t171 = (n3pp / 20.0 + -t133_tmp) - 0.9 * g_Ts_tmp * b_Ts_tmp_tmp;
  t172 = n_Ts_tmp_tmp / 12.0;
  t174 = l_Ts_tmp * t171;
  t175 = l_Ts_tmp_tmp_tmp * x[11];
  t178 = 15.0 * t175;
  t179 = 45.0 * d_Ts_tmp_tmp_tmp;
  t180 = t179 * t171;
  t181 = t109 * (0.75 - n_Ts_tmp_tmp);
  t183 = h_Ts_tmp_tmp_tmp * t171;
  t184 = h_Ts_tmp * k_Ts_tmp_tmp;
  t188 = h_Ts_tmp * 9.0;
  t189 = 4.5 * n3p;
  t190 = t124 * x[14];
  t191 = f_Ts_tmp_tmp * m_Ts_tmp_tmp_tmp;
  t192 = t191 * (n_Ts_tmp_tmp + -1.3333333333333333);
  t194 = x[13] * d_Ts_tmp_tmp_tmp;
  t195 = m_Ts_tmp_tmp_tmp * 36.0;
  t196 = x[14] * i_Ts_tmp_tmp_tmp;
  t197 = t196 * g_Ts_tmp_tmp_tmp;
  t198 = t47_tmp * x[14];
  t199 = t198 * g_Ts_tmp_tmp_tmp;
  t200 = 30.0 * d_Ts_tmp_tmp_tmp * t171;
  t201 = 0.5 * g_Ts_tmp_tmp_tmp;
  t202 = t201 * x[14];
  t203 = -i_Ts_tmp_tmp_tmp * (t197 - t194) + t202;
  t205 = x[14] * d_Ts_tmp_tmp_tmp;
  t206 = t572 * g_Ts_tmp_tmp_tmp + t205;
  t207 = t88 * t206;
  t208 = t66 * k_Ts_tmp_tmp * n3p;
  t210 = n_Ts_tmp_tmp * 22.5;
  t211 = t205 * t69_tmp;
  t212 = 2.0 * t211;
  t213 = t198 * e_Ts_tmp_tmp_tmp;
  t214 = t25 * 24.0;
  t215 = t214 * x[12];
  t216 = 15.0 * n_Ts_tmp_tmp;
  t217 = t216 + -7.5;
  t218 = t175 * e_Ts_tmp_tmp_tmp;
  t219 = t194 * t69_tmp;
  t220 = t131 * x[14];
  t221 = t220 * g_Ts_tmp_tmp_tmp;
  t222 = 2.0 * t69_tmp * a_tmp_tmp_tmp_tmp_tmp * x[14];
  t223 = 15.0 * k_Ts_tmp_tmp;
  t224 = t190 * g_Ts_tmp_tmp_tmp;
  t225 = t224 * e_Ts_tmp_tmp_tmp;
  t226 = 81.0 * x[12];
  t227 = x[13] * e_Ts_tmp_tmp_tmp;
  t228 = t227 * t62;
  t229 = t72_tmp * k_Ts_tmp_tmp * n3p;
  t230 = t88 * 0.5;
  t231 = t69_tmp * t206;
  t232 = t194 * e_Ts_tmp_tmp_tmp;
  t233 = t43_tmp * x[14];
  t226 = ((-0.5 * g_Ts_tmp * (t206 * x[12] + x[11] * (-g_Ts_tmp_tmp_tmp * (t226
              + t232) + t233) * c_Ts_tmp_tmp_tmp) + n_Ts_tmp * (-7.5 *
            a_tmp_tmp_tmp_tmp_tmp * x[11] * e_Ts_tmp_tmp_tmp * n3p + t231)) +
          f_Ts_tmp_tmp_tmp * ((((f_Ts_tmp_tmp_tmp * (((f_Ts_tmp_tmp_tmp * (x[12]
    * ((3.0 * t124 * (17.5 - n_Ts_tmp_tmp) + 3.0 * h_Ts_tmp * (t118 + 4.0)) -
       52.5 * n_Ts_tmp * (t65 + h_Ts_tmp * (-0.22857142857142856 * n_Ts_tmp_tmp
    + 0.45714285714285713))) + t72_tmp * (30.0 * (-db_Ts_tmp * t171 * (2.0 -
    n_Ts_tmp_tmp) + k_Ts_tmp_tmp * (t118 - 0.75) * n3p) - 7.5 * t208)) +
    g_Ts_tmp_tmp_tmp * ((-157.5 * t47_tmp * x[12] * (n_Ts_tmp_tmp +
    -1.3333333333333333) * t13 - t200 * t43_tmp) + t218 * (t216 + -7.5))) +
    c_Ts_tmp_tmp_tmp * ((c_Ts_tmp_tmp_tmp * (-t212 + (60.0 * t174 + t175 *
    (-t210 + 30.0)) * e_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp) + i_Ts_tmp_tmp_tmp *
    (-t215 * g_Ts_tmp_tmp_tmp * n3p + t213)) + t47_tmp * (108.0 * n_Ts_tmp_tmp -
    157.5) * x[12] * g_Ts_tmp_tmp_tmp)) + t211) + n_Ts_tmp * (-t229 * 22.5 -
    157.5 * x[12] * (-t124 - 0.0761904761904762 * h_Ts_tmp))) + c_Ts_tmp_tmp_tmp
             * ((t223 * e_Ts_tmp_tmp_tmp * n3p + db_Ts_tmp * ((30.0 *
    e_Ts_tmp_tmp_tmp * t171 - t219) + t221)) - t222)) + i_Ts_tmp_tmp_tmp *
            ((t225 - 10.5 * x[12] * n3p) + t228)) - t230 * (t226 *
            d_Ts_tmp_tmp_tmp + t227))) - 52.5 * t137 * x[12];
  t234 = n3pp / 16.0;
  t235 = (t234 + -t133_tmp) - 1.1875 * g_Ts_tmp * b_Ts_tmp_tmp;
  t236 = 0.26666666666666666 * n_Ts_tmp_tmp;
  t237 = 6.0 * n_Ts_tmp_tmp;
  t239 = t35 * ((-9.5 * g_Ts_tmp * b_Ts_tmp_tmp - n3pp * 0.25) + -t133_tmp);
  t240 = 72.0 * t235;
  t241 = t235 * 24.0;
  t242 = n3p * 36.0;
  t243 = t147 * x[14];
  t244 = t163 * x[14] * g_Ts_tmp_tmp_tmp;
  t245 = t44 * x[13] * x[12];
  t246 = 0.5 * x[13];
  t247 = l_Ts_tmp_tmp_tmp * m_Ts_tmp_tmp_tmp;
  t248 = t199 * 0.5;
  t250 = t194 * m_Ts_tmp_tmp_tmp;
  t251 = 1.5 * n3pp;
  t249 = (b_Ts_tmp_tmp * -13.5 - t250) * g_Ts_tmp;
  t252 = t44 * x[14] * x[12];
  t253 = 0.5 * h_Ts_tmp_tmp_tmp;
  t256 = n_Ts_tmp_tmp * 0.14285714285714285;
  t257 = h_Ts_tmp * (t256 + -0.2857142857142857);
  t258 = n3pp / 8.0;
  t259 = (1.25 * g_Ts_tmp * b_Ts_tmp_tmp + t258) + -t133_tmp;
  t260 = n_Ts_tmp_tmp / 8.0;
  t263 = 42.0 * n_Ts_tmp;
  t265 = h_Ts_tmp / 21.0;
  t266 = 3.0 * x[12] * n3p;
  t227 *= t118;
  t65 = ((t231 * 0.5 + n_Ts_tmp * (-t231 + 10.5 * a_tmp_tmp_tmp_tmp_tmp * x[11] *
           e_Ts_tmp_tmp_tmp * n3p)) + f_Ts_tmp_tmp_tmp * ((((f_Ts_tmp_tmp_tmp *
             (((f_Ts_tmp_tmp_tmp * (x[12] * ((h_Ts_tmp * (-0.18181818181818182 *
    n_Ts_tmp_tmp + 0.36363636363636365) + t124 * (-2.5454545454545454 -
    n_Ts_tmp_tmp)) * 16.5 + t263 * (t257 + t65)) + t72_tmp * ((-12.0 * db_Ts_tmp
    * t259 * (2.0 - n_Ts_tmp_tmp) + 12.0 * k_Ts_tmp_tmp * (t260 + 2.625) * n3p)
    + 10.5 * t208)) + g_Ts_tmp_tmp_tmp * ((t218 * (t81 + 10.5) + 126.0 * t47_tmp
    * x[12] * (n_Ts_tmp_tmp + -1.3333333333333333) * t13) - 12.0 * t43_tmp *
    t259 * d_Ts_tmp_tmp_tmp)) + c_Ts_tmp_tmp_tmp * ((c_Ts_tmp_tmp_tmp *
    ((l_Ts_tmp * t259 * 24.0 + t175 * (n_Ts_tmp_tmp * 31.5 - 42.0)) *
     e_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp + t212) + i_Ts_tmp_tmp_tmp * (-12.0 *
    t25 * x[12] * g_Ts_tmp_tmp_tmp * n3p - t213 * 0.5)) + t47_tmp * (-67.5 *
    n_Ts_tmp_tmp + 126.0) * x[12] * g_Ts_tmp_tmp_tmp)) - t211) + n_Ts_tmp *
             (t229 * 31.5 + (-126.0 * t124 + 126.0 * t265) * x[12])) +
            c_Ts_tmp_tmp_tmp * ((-db_Ts_tmp * ((-12.0 * t259 * e_Ts_tmp_tmp_tmp
    - t219) + t221) + t222) - 25.5 * k_Ts_tmp_tmp * e_Ts_tmp_tmp_tmp * n3p)) +
           i_Ts_tmp_tmp_tmp * (-t201 * t190 * e_Ts_tmp_tmp_tmp - t266)) + t88 *
          (m_Ts_tmp * 36.0 - t227))) + eb_Ts_tmp * (-4.5 * l_Ts_tmp_tmp_tmp *
    e_Ts_tmp_tmp_tmp + t70 * (t263 - 36.0));
  t201 = n_Ts_tmp_tmp * 0.33333333333333331;
  t212_tmp = g_Ts_tmp * c_Ts_tmp_tmp_tmp;
  t229 = t172 + 0.5;
  t259 = t44 * x[12];
  t263 = t78 * 0.5;
  t269 = k_Ts_tmp_tmp * t13;
  t271 = (n_Ts_tmp_tmp + -2.0) * ab_Ts_tmp;
  t272 = q_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t273 = j_Ts_tmp_tmp * (t271 + 1.0) + t272 * (n_Ts_tmp + -0.5) *
    f_Ts_tmp_tmp_tmp;
  t275 = Ts_tmp * Ts_tmp;
  t276 = b_Ts_tmp_tmp_tmp * t275;
  t277 = b_Ts_tmp_tmp_tmp * Ts_tmp;
  t115 = b_Ts_tmp_tmp_tmp * ((((f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp *
    (c_Ts_tmp_tmp_tmp * (((30.0 * i_Ts_tmp_tmp_tmp * (t175 + t174) - t178 * t11)
    - t180) - 15.0 * t66 * d_Ts_tmp_tmp_tmp * t171) + m_Ts_tmp_tmp_tmp * (-(t181
    + t25 * (t115 - 0.0625) * n3p) * 24.0 + t86 * (t110 + t25 * (t172 +
    -0.33333333333333331) * n3p))) + g_Ts_tmp_tmp_tmp * (n_Ts_tmp * (-45.0 *
    (t183 * (n_Ts_tmp_tmp + -1.3333333333333333) + 0.66666666666666663 * t184) -
    4.5 * t192) + 30.0 * (-0.5 * (-t184 + t183) + t183 * n_Ts_tmp_tmp))) +
    c_Ts_tmp_tmp_tmp * (t190 + m_Ts_tmp_tmp_tmp * (i_Ts_tmp_tmp_tmp * (t124 *
    36.0 + t188) - t189) * g_Ts_tmp_tmp_tmp)) + c_Ts_tmp_tmp_tmp *
    ((c_Ts_tmp_tmp_tmp * ((-0.5 * t109 * ((t194 + t195) - t197) - t199) + t189 *
    m_Ts_tmp_tmp_tmp * t25) - 15.0 * t37 * x[11]) + t200)) + t47_tmp * t203) -
    t180 * t13) * f_Ts_tmp_tmp_tmp + 0.5 * ((-t150 * m_Ts_tmp_tmp_tmp *
    g_Ts_tmp_tmp_tmp * n3p - t105 * 30.0 * t171) - t207) * c_Ts_tmp_tmp_tmp) +
    t226;
  t92 = b_Ts_tmp_tmp_tmp * (((((b_Ts_tmp_tmp_tmp * t115 + f_Ts_tmp_tmp_tmp *
    ((((f_Ts_tmp_tmp_tmp * (((f_Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp *
    ((d_Ts_tmp_tmp_tmp * (-t239 + t240) + t37 * (t237 - 12.0) * x[11]) + t241 *
     t66 * d_Ts_tmp_tmp_tmp) + m_Ts_tmp_tmp_tmp * (-9.0 * (-t109 * (n_Ts_tmp_tmp
    + 5.0) + t25 * (t118 + 1.3333333333333333) * n3p) - n_Ts_tmp * (t110 + t25 *
    (t236 + -1.0666666666666667) * n3p) * 45.0)) + g_Ts_tmp_tmp_tmp * (n_Ts_tmp *
    ((72.0 * (n_Ts_tmp_tmp + -1.3333333333333333) * t235 * h_Ts_tmp_tmp_tmp +
      72.0 * t184 * 0.16666666666666666) + t192 * 36.0) + h_Ts_tmp_tmp_tmp *
    (-t239 + t241))) + c_Ts_tmp_tmp_tmp * (-t190 + m_Ts_tmp_tmp_tmp *
    (i_Ts_tmp_tmp_tmp * (-19.5 * h_Ts_tmp - 90.0 * t124) + t242) *
    g_Ts_tmp_tmp_tmp)) + i_Ts_tmp_tmp_tmp * (-6.0 * k_Ts_tmp_tmp *
    g_Ts_tmp_tmp_tmp * n3p + t243)) + d_Ts_tmp_tmp_tmp * (t240 * t13 + 10.5 *
    t247)) + c_Ts_tmp_tmp_tmp * (((c_Ts_tmp_tmp_tmp * ((0.5 * t109 * ((90.0 *
    m_Ts_tmp_tmp_tmp + t194) - t197) + t199) - t195 * t25 * n3p) +
    i_Ts_tmp_tmp_tmp * ((-t244 + 6.0 * t175) - t245)) + d_Ts_tmp_tmp_tmp *
    ((-3.75 * n3pp - 57.0 * -t133_tmp) + 63.75 * g_Ts_tmp * b_Ts_tmp_tmp)) +
    t246 * t54)) + t109 * ((-t194 - 40.5 * m_Ts_tmp_tmp_tmp) + t197)) - t248)) +
    c_Ts_tmp_tmp_tmp * (-10.5 * m_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp * n3p + t207
                        * 0.5)) - t253 * (g_Ts_tmp_tmp_tmp * ((-t133_tmp * 18.0
    + t249) + t251) + t252)) + 12.0 * t92 * m_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp)
    + t241 * a_tmp_tmp_tmp_tmp_tmp * n_Ts_tmp) + t65;
  t115 = t276 * x[12];
  t65 = b_Ts_tmp_tmp * 9.0;
  t172 = 1.3333333333333333 * n_Ts_tmp_tmp;
  t174 = q_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp;
  t176 = t174 * t25;
  t180 = (ab_Ts_tmp * ((t42 + 1.0) - t172) + n_Ts_tmp) - t176;
  t183 = 7.5 * n_Ts_tmp_tmp;
  t200 = l_Ts_tmp_tmp * (t183 - 30.0);
  t226 = 54.0 * n_Ts_tmp_tmp;
  t240 = t54 * t25;
  t241 = n_Ts_tmp_tmp * 18.0;
  t278 = 0.27777777777777779 * n_Ts_tmp_tmp;
  t279 = t55 * (n_Ts_tmp_tmp + -1.3333333333333333);
  t204 = i_Ts_tmp_tmp_tmp * (t205 * g_Ts_tmp_tmp_tmp + t572);
  t205 = t204 - t246;
  t280 = n_Ts_tmp * d_Ts_tmp_tmp_tmp;
  t281 = t194 * g_Ts_tmp_tmp_tmp - t196;
  t282 = t281 * g_Ts_tmp;
  t284_tmp = d_Ts_tmp_tmp * g_Ts_tmp;
  t285 = 12.0 * m_Ts_tmp_tmp_tmp;
  t286 = t285 * x[11] * M[2] * Ts_tmp_tmp_tmp * M[0] - t284_tmp;
  t287 = (n3pp * 0.03125 - 0.1875 * g_Ts_tmp * b_Ts_tmp_tmp) + -t133_tmp;
  t288 = 0.375 * n_Ts_tmp_tmp;
  t289 = t25 * x[11];
  t290 = t289 * n3p;
  t291 = m_Ts_tmp_tmp_tmp * t37;
  t292 = g_Ts_tmp * d_Ts_tmp_tmp_tmp;
  t293 = t292 * t286;
  t294 = 6.0 * g_Ts_tmp;
  t296 = t290 * (n_Ts_tmp_tmp + 1.0);
  t297 = t78 * l_Ts_tmp_tmp;
  t299 = t54 * x[14];
  t301 = 9.0 * n_Ts_tmp_tmp;
  t302 = eb_Ts_tmp * n3p;
  t303 = t88 * x[14];
  t304 = l_Ts_tmp_tmp * m_Ts_tmp_tmp_tmp;
  t305 = t20 * t302;
  t306_tmp = g_Ts_tmp * h_Ts_tmp_tmp_tmp;
  t307 = t252 * g_Ts_tmp_tmp_tmp;
  t308 = t299 * q_Ts_tmp_tmp_tmp;
  t309 = t56 * x[14];
  t310 = t309 * g_Ts_tmp_tmp_tmp;
  t311 = t109 * x[13];
  t314 = p_Ts_tmp * i_Ts_tmp_tmp_tmp;
  t316 = t290 * 9.0;
  t317 = 27.0 * t80 * d_Ts_tmp_tmp_tmp;
  t318 = 2.0 * n_Ts_tmp;
  t319 = t147 * t206;
  t321 = 9.0 * (-t105 * g_Ts_tmp * t286 + p_Ts_tmp * (-(t302 * 18.0 - t319) *
    0.22222222222222221 + t302 * t91)) * c_Ts_tmp_tmp_tmp;
  t234 = (-0.5625 * g_Ts_tmp * b_Ts_tmp_tmp + t234) + -t133_tmp;
  t322 = 0.1875 * n_Ts_tmp_tmp;
  t323 = h_Ts_tmp * x[11];
  t123 = t25 * (4.0 - n_Ts_tmp_tmp);
  t324 = t284_tmp * e_Ts_tmp_tmp_tmp;
  t325 = 6.0 * p_Ts_tmp;
  t326 = t325 * x[12] * x[11] - t324;
  t327 = db_Ts_tmp * g_Ts_tmp;
  t328 = 2.0 * b_Ts_tmp_tmp;
  t329 = t134 * x[11];
  t330 = t309 * e_Ts_tmp_tmp_tmp;
  t331 = a_tmp_tmp_tmp_tmp_tmp * n3p;
  t332 = t302 * t25;
  t333 = t69_tmp * x[14];
  t334 = t331 * 24.0;
  t335 = t334 * x[12];
  t336 = (n_Ts_tmp_tmp + -1.3333333333333333) * t13;
  t337 = t336 * e_Ts_tmp_tmp_tmp;
  t339 = t58 * x[14];
  t340 = t339 * e_Ts_tmp_tmp_tmp;
  t341 = t73 * x[14];
  t342 = n3p * 9.0;
  t343 = n3pp / 14.0;
  t344 = (-0.6428571428571429 * g_Ts_tmp * b_Ts_tmp_tmp + t343) + -t133_tmp;
  t345_tmp = e_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t346 = l_Ts_tmp_tmp * x[12];
  t347 = l_Ts_tmp_tmp_tmp * x[12];
  t326 = ((f_Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp * (t327 * t326 * (-t241 + 36.0)
             + p_Ts_tmp * l_Ts_tmp_tmp * (t237 - 144.0) * x[12]) + p_Ts_tmp *
            (e_Ts_tmp_tmp_tmp * (-36.0 * ((2.6666666666666665 * t25 * t234 -
    n_Ts_tmp_tmp * (-t25 * ((n3pp * 0.16666666666666666 - t328 * g_Ts_tmp) +
    -t133_tmp) + t323)) - t329) - 96.0 * n_Ts_tmp * (t323 * (-t322 + 0.375) -
    t123 * t234)) - l_Ts_tmp_tmp * t13 * x[12] * (i_Ts_tmp_tmp_tmp + -2.0) *
             (i_Ts_tmp_tmp_tmp + 2.0) * 48.0)) + n_Ts_tmp * (-l_Ts_tmp * 36.0 *
            g_Ts_tmp * t326 * g_Ts_tmp_tmp_tmp + p_Ts_tmp * (4.0 *
             (a_tmp_tmp_tmp_tmp_tmp * 48.0 * x[12] * n3p - t330) - 144.0 * t331 *
             n_Ts_tmp_tmp * x[12]))) + p_Ts_tmp * (((g_Ts_tmp_tmp_tmp * (t237 *
              l_Ts_tmp_tmp_tmp * x[12] + 288.0 * t337 * t234) + 2.0 * t330) -
            2.0 * t335) - c_Ts_tmp_tmp_tmp * (i_Ts_tmp_tmp_tmp * (t332 * 9.0 *
             e_Ts_tmp_tmp_tmp - t333) + (-72.0 * t234 + 39.0 * n_Ts_tmp_tmp *
             ((n3pp / 26.0 + -t133_tmp) - 0.23076923076923078 * g_Ts_tmp *
              b_Ts_tmp_tmp)) * e_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp) * 4.0)) +
    l_Ts_tmp * 18.0 * g_Ts_tmp * t326 * g_Ts_tmp_tmp_tmp;
  t330 = 2.0 * p_Ts_tmp;
  t135 = -t330 * (-g_Ts_tmp_tmp_tmp * (t13 * e_Ts_tmp_tmp_tmp * t234 * 48.0 +
    t347 * 9.0) + c_Ts_tmp_tmp_tmp * ((c_Ts_tmp_tmp_tmp * (-t47_tmp *
    e_Ts_tmp_tmp_tmp * t206 + t335) + g_Ts_tmp_tmp_tmp * (42.0 * t344 *
    e_Ts_tmp_tmp_tmp - t219)) + t220)) + ((f_Ts_tmp_tmp_tmp * t326 +
    c_Ts_tmp_tmp_tmp * (-t327 * 18.0 * (p_Ts_tmp * 0.1111111111111111 * x[11] *
    (t232 + 54.0 * x[12]) - t324) + p_Ts_tmp * (4.0 * (28.5 * l_Ts_tmp_tmp * x
    [12] - t340) + t22 * t340))) + p_Ts_tmp * (n_Ts_tmp * (-144.0 * t346 *
    c_Ts_tmp_tmp_tmp - 288.0 * e_Ts_tmp_tmp_tmp * (t25 * t234 - t323 / 16.0)) -
    4.0 * (-t253 * (t345_tmp * 42.0 * t344 - t69_tmp * x[13]) + i_Ts_tmp_tmp_tmp
           * ((t342 * x[11] * e_Ts_tmp_tmp_tmp - t135 * x[13]) - t341 *
              g_Ts_tmp_tmp_tmp)))) * f_Ts_tmp_tmp_tmp;
  t220 = p_Ts_tmp * m_Ts_tmp_tmp_tmp;
  t234 = 8.0 * t220;
  t326 = t234 * x[11] - t284_tmp;
  t610 = t258 + -t133_tmp;
  t340 = -2.0 * t610;
  t344 = n_Ts_tmp_tmp * 24.0;
  t349 = t301 * t284_tmp;
  t350 = 54.0 * t326;
  t351 = p_Ts_tmp * t291;
  t352 = 18.0 * t326;
  t353 = p_Ts_tmp * t297;
  t354 = t306_tmp * (n_Ts_tmp_tmp + -1.3333333333333333);
  t355 = t285 * l_Ts_tmp_tmp;
  t356 = 12.0 * -t133_tmp;
  t357 = t325 * m_Ts_tmp_tmp_tmp * x[11] - t284_tmp;
  t358 = a_tmp_tmp_tmp_tmp_tmp * g_Ts_tmp;
  t359 = p_Ts_tmp * c_Ts_tmp_tmp_tmp;
  t319 = t359 * (-4.0 * (7.5 * t302 - t319) + t302 * n_Ts_tmp * 30.0);
  t360 = t119 * t11;
  t361 = x[12] * 4.0;
  t362 = t361 * p_Ts_tmp * x[11] - t324;
  t364 = t212_tmp * db_Ts_tmp;
  t365 = t364 * 18.0;
  t366 = t365 * t362;
  t367 = l_Ts_tmp * g_Ts_tmp;
  t368 = h_Ts_tmp * 0.16666666666666666;
  t371 = p_Ts_tmp * t72_tmp;
  t271 = ((t271 * (n_Ts_tmp + -0.5) + n_Ts_tmp) - t176) - 0.5;
  t135 += b_Ts_tmp_tmp_tmp * (-t321 + ((f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp *
    (c_Ts_tmp_tmp_tmp * ((t293 * (-t241 + 27.0) + t291 * (-60.0 * n_Ts_tmp_tmp +
    120.0) * Ts_tmp_tmp_tmp * M[0] * M[2]) + t293 * t66 * 9.0) + ((12.0 *
    i_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp * ((n3pp * 0.5 - t294 * b_Ts_tmp_tmp) +
    -t133_tmp) + 8.0 * t287) + 36.0 * t296) + 96.0 * n_Ts_tmp *
    (i_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp * t287 - 2.0 * t287) + t290 * (t288 - 1.5)))
     * Ts_tmp_tmp_tmp * M[0] * M[2]) + g_Ts_tmp_tmp_tmp * (-(120.0 * t297 * M[2]
    * Ts_tmp_tmp_tmp * M[0] - 27.0 * (n_Ts_tmp_tmp + -1.3333333333333333) * t286
    * h_Ts_tmp_tmp_tmp * g_Ts_tmp) * n_Ts_tmp - t306_tmp * t286 * (t241 - 9.0)))
    + (c_Ts_tmp_tmp_tmp * (-4.0 * (t25 * (o_Ts_tmp * t287 * 48.0 - t299) + t302 *
    (-t301 + 27.0)) - 108.0 * t305) + 2.0 * i_Ts_tmp_tmp_tmp * (t304 * 30.0 *
    g_Ts_tmp_tmp_tmp - t303)) * Ts_tmp_tmp_tmp * M[0] * M[2]) + c_Ts_tmp_tmp_tmp
    * ((t317 * t286 + 2.0 * t314 * ((-t247 * 30.0 + t310) + t311)) - t293 * 18.0))
    + p_Ts_tmp * (-4.0 * ((t316 - t202 * t54) + i_Ts_tmp_tmp_tmp * (((-t133_tmp *
    21.0 + t249) + t251) + t307)) + t318 * ((i_Ts_tmp_tmp_tmp * (((-t133_tmp *
    48.0 - g_Ts_tmp * (t65 + t250)) + t251) + t307) + 54.0 * t290) - t308))) *
    f_Ts_tmp_tmp_tmp);
  t135 = ((b_Ts_tmp_tmp_tmp * t135 + t319) + t358 * (9.0 * t357 - t86 * t326)) +
    ((f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp * ((-t352 * t292
           * t66 + t351 * (-t344 + 48.0)) + t292 * (-t350 + t349)) + p_Ts_tmp *
         (-24.0 * (1.25 * t296 + i_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp * ((-3.75 *
              g_Ts_tmp * b_Ts_tmp_tmp + t258) + -t133_tmp) + t340)) + n_Ts_tmp *
          (t290 * (-0.625 * n_Ts_tmp_tmp + 2.5) + i_Ts_tmp_tmp_tmp *
           (n_Ts_tmp_tmp * t610 + t340)) * 48.0)) + g_Ts_tmp_tmp_tmp * (t306_tmp
         * (-t352 + t349) + (-54.0 * t354 * t326 - 48.0 * t353) * n_Ts_tmp)) +
       p_Ts_tmp * (c_Ts_tmp_tmp_tmp * ((8.0 * t302 * (-3.75 * n_Ts_tmp_tmp +
           11.25) + 8.0 * t25 * (-12.0 * o_Ts_tmp * t610 - t299)) + 90.0 * t305)
                   - 2.0 * i_Ts_tmp_tmp_tmp * (-t355 * g_Ts_tmp_tmp_tmp - t303)))
      + c_Ts_tmp_tmp_tmp * ((-t350 * t80 * d_Ts_tmp_tmp_tmp - 2.0 * t314 *
        ((t311 + 12.0 * t247) + t310)) + t179 * (7.6 * t220 * x[11] - t284_tmp) *
       g_Ts_tmp)) + p_Ts_tmp * (((30.0 * t290 + 2.0 * i_Ts_tmp_tmp_tmp * (((t307
           - g_Ts_tmp * (b_Ts_tmp_tmp * 22.5 + t250)) - t251) - t356)) - 2.0 *
       t308) - t91 * ((t290 * 22.5 + i_Ts_tmp_tmp_tmp * (((-t163 * x[13] - t251)
          + t307) - t356)) - t308))) * f_Ts_tmp_tmp_tmp;
  t179 = p_Ts_tmp * t115 * 4.0 * ((((f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp *
    (c_Ts_tmp_tmp_tmp * ((n_Ts_tmp * t200 + t62 * (t226 - 108.0)) + l_Ts_tmp_tmp
    * (-t216 + 22.5)) + t240 * (12.0 * (i_Ts_tmp_tmp_tmp + -0.5) *
    (i_Ts_tmp_tmp_tmp + 0.5) - 3.0 * t66)) + g_Ts_tmp_tmp_tmp * ((n_Ts_tmp *
    ((108.0 * t68 - 108.0 * l_Ts_tmp_tmp_tmp * (-0.20833333333333334 *
    n_Ts_tmp_tmp + 0.27777777777777779)) + t279 * 9.0) - 54.0 * t68) + 54.0 *
    l_Ts_tmp_tmp_tmp * (-t278 + 0.1388888888888889))) - t212_tmp *
    (m_Ts_tmp_tmp_tmp * (t241 - 9.0) * g_Ts_tmp_tmp_tmp + t196)) +
    c_Ts_tmp_tmp_tmp * (54.0 * t62 - 15.0 * l_Ts_tmp_tmp)) - g_Ts_tmp * t205 *
    h_Ts_tmp_tmp_tmp) + t280 * (-t147 * 9.0 + f_Ts_tmp_tmp * 22.5)) *
    f_Ts_tmp_tmp_tmp + 0.5 * ((t87 * t54 * g_Ts_tmp_tmp_tmp + 15.0 * t105 * n3p)
    - t282) * c_Ts_tmp_tmp_tmp);
  t249 = d_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp;
  t286 = t306_tmp * (t79 * c_Ts_tmp_tmp_tmp - k_Ts_tmp_tmp);
  t287 = h_Ts_tmp * 18.0;
  t293 = t129 * 0.5;
  t296 = 54.0 * m_Ts_tmp_tmp_tmp + t194;
  t297 = q_Ts_tmp_tmp_tmp * x[14];
  t305 = t206 * c_Ts_tmp_tmp_tmp;
  t310 = (n3pp / 34.0 + -t133_tmp) - 0.17647058823529413 * g_Ts_tmp *
    b_Ts_tmp_tmp;
  t311 = t284_tmp * Ts_tmp_tmp_tmp;
  t319 = e_Ts_tmp * m_Ts_tmp_tmp_tmp;
  t321 = t319 * 4.0 * x[11] - t311;
  t326 = n_Ts_tmp_tmp * 36.0;
  t335 = t319 * t25;
  t340 = g_Ts_tmp * t321;
  t349 = ((n3pp * 0.1111111111111111 - 0.88888888888888884 * g_Ts_tmp *
           b_Ts_tmp_tmp) + -t133_tmp) * n_Ts_tmp_tmp;
  t350 = 8.0 * t319 * x[11] - t311;
  t352 = 27.0 * m_Ts_tmp_tmp_tmp;
  t372 = -51.0 * t310;
  t373 = g_Ts_tmp_tmp_tmp * n_Ts_tmp;
  t374 = m_Ts_tmp_tmp_tmp * 18.0;
  t375 = t374 * t25 * n3p;
  t376 = t249 * e_Ts_tmp;
  t377 = 18.0 * g_Ts_tmp;
  t192 = (f_Ts_tmp_tmp_tmp * ((-n3p * 36.0 * (n_Ts_tmp_tmp + 1.0) * t335 +
            g_Ts_tmp * (t350 * 18.0 * t11 + t321 * 9.0 * i_Ts_tmp_tmp_tmp)) +
           c_Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp * (t340 * i_Ts_tmp_tmp_tmp *
             (t301 - 18.0) + t335 * (-t326 + 144.0) * n3p) + e_Ts_tmp * ((54.0 *
              d_Ts_tmp_tmp_tmp * (5.666666666666667 * t310 + t349) + 54.0 * t37 *
              (-0.55555555555555558 * n_Ts_tmp_tmp + 1.1111111111111112) * x[11])
             + 102.0 * t66 * d_Ts_tmp_tmp_tmp * t310))) + c_Ts_tmp_tmp_tmp *
          (-t340 * o_Ts_tmp * t25 * 18.0 + e_Ts_tmp * (4.0 * (t352 *
             g_Ts_tmp_tmp_tmp * n3p - t190) - t195 * n3p * n_Ts_tmp_tmp *
            g_Ts_tmp_tmp_tmp))) + e_Ts_tmp * ((-2.0 * i_Ts_tmp_tmp_tmp * (-t223 *
    g_Ts_tmp_tmp_tmp * n3p - t243) - 2.0 * a_tmp_tmp_tmp_tmp_tmp * (t372 - 27.0 *
    t349)) + t373 * ((306.0 * (n_Ts_tmp_tmp + -1.3333333333333333) * t310 *
                      h_Ts_tmp_tmp_tmp - 60.0 * t184) + 108.0 * t192));
  t195 = 2.0 * e_Ts_tmp;
  t223 = t324 * Ts_tmp_tmp_tmp;
  t243 = 5.666666666666667 * e_Ts_tmp * x[12] * x[11] - t223;
  t295 = 42.0 * n_Ts_tmp_tmp;
  t321 = t25 * (-t241 + 72.0);
  t335 = e_Ts_tmp * h_Ts_tmp * x[12];
  t340 = (-0.44444444444444442 * g_Ts_tmp * b_Ts_tmp_tmp + n3pp *
          0.055555555555555552) + -t133_tmp;
  t349 = 27.0 * l_Ts_tmp * t340;
  t378 = 54.0 * t243;
  t379 = t342 * k_Ts_tmp_tmp * e_Ts_tmp_tmp_tmp;
  t380 = 12.0 * x[12];
  t381 = e_Ts_tmp * i_Ts_tmp_tmp_tmp;
  t382 = e_Ts_tmp * c_Ts_tmp_tmp_tmp;
  t383 = 3.0 * x[11];
  t384 = t383 * t331;
  t385 = a_tmp_tmp_tmp * g_Ts_tmp;
  t76 = (18.0 * (-t385 * t243 * (1.0 - n_Ts_tmp)) + ((((f_Ts_tmp_tmp_tmp *
             ((f_Ts_tmp_tmp_tmp * ((n_Ts_tmp * (t321 * t243 * g_Ts_tmp + t335 *
    (t295 + -84.0)) - 18.0 * (t103 * e_Ts_tmp * x[12] + t25 * (n_Ts_tmp_tmp *
    (6.666666666666667 * e_Ts_tmp * x[12] * x[11] - t223) + t243) * g_Ts_tmp)) +
    e_Ts_tmp * ((12.0 * t93 * t76 + 108.0 * t72_tmp * (-db_Ts_tmp * t340 * (2.0
    - n_Ts_tmp_tmp) + k_Ts_tmp_tmp * (t278 + 0.33333333333333331) * n3p)) +
                h_Ts_tmp * x[12] * 42.0)) + c_Ts_tmp_tmp_tmp * ((t378 * t80 *
    g_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp + -1.3333333333333333) + t195 * (-t25 *
    42.0 * x[12] * g_Ts_tmp_tmp_tmp * n3p - t213) * i_Ts_tmp_tmp_tmp) + (t378 -
    t241 * (4.666666666666667 * e_Ts_tmp * x[12] * x[11] - t223)) *
    g_Ts_tmp_tmp_tmp * g_Ts_tmp)) + e_Ts_tmp * (4.0 * ((t175 * (t183 + 3.0) -
    t349) * e_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp - t211) - 8.0 * n_Ts_tmp *
    ((t175 * (-4.5 * n_Ts_tmp_tmp + 6.0) - t349) * e_Ts_tmp_tmp_tmp *
     g_Ts_tmp_tmp_tmp - t211))) + n_Ts_tmp * (-t378 * t25 * g_Ts_tmp + t335 *
              42.0)) + 2.0 * t381 * ((-t380 * n3p - t225) - t228)) + t382 *
           (-4.0 * ((t379 + db_Ts_tmp * ((-27.0 * t340 * e_Ts_tmp_tmp_tmp - t219)
    + t221)) - t222) + t242 * k_Ts_tmp_tmp * n_Ts_tmp * e_Ts_tmp_tmp_tmp)) +
          t377 * t25 * t243) * f_Ts_tmp_tmp_tmp) + e_Ts_tmp * ((-12.0 * t331 *
    x[11] * e_Ts_tmp_tmp_tmp + 2.0 * t231) + t91 * (t384 * e_Ts_tmp_tmp_tmp -
    t231));
  t213 = 6.666666666666667 * t319 * x[11] - t311;
  t222 = n_Ts_tmp_tmp * (x[12] - t383) * (x[12] + t383);
  t225 = t37 * x[11];
  t228 = 9.0 * g_Ts_tmp;
  t242 = t88 * (n_Ts_tmp_tmp + -1.3333333333333333);
  t243 = 3.0 * b_Ts_tmp_tmp;
  t278 = x[11] * n_Ts_tmp;
  t335 = t27 * g_Ts_tmp;
  t340 = t56 * n_Ts_tmp;
  t349 = t382 * x[11];
  t378_tmp = g_Ts_tmp * i_Ts_tmp_tmp_tmp;
  t76 += b_Ts_tmp_tmp_tmp * (-t195 * (g_Ts_tmp_tmp_tmp * (n_Ts_tmp * (-t191 *
    18.0 + t372 * h_Ts_tmp_tmp_tmp) + h_Ts_tmp_tmp_tmp * ((n3pp / 15.0 +
    -t133_tmp) - 0.4 * g_Ts_tmp * b_Ts_tmp_tmp) * 22.5) + c_Ts_tmp_tmp_tmp *
    (t374 * g_Ts_tmp_tmp_tmp * n3p - t207)) + (((f_Ts_tmp_tmp_tmp * t192 +
    n_Ts_tmp * ((306.0 * t376 * t310 + g_Ts_tmp * (-t22 * e_Ts_tmp * eb_Ts_tmp *
    x[14] + (e_Ts_tmp * 0.22222222222222221 * x[11] * (t374 + t194) - t311) *
    9.0 * i_Ts_tmp_tmp_tmp)) - e_Ts_tmp * 4.0 * (t352 * t25 * n3p - t199))) +
    2.0 * e_Ts_tmp * (((c_Ts_tmp_tmp_tmp * (((-4.5 * n3pp - 124.5 * -t133_tmp) +
    27.0 * g_Ts_tmp * b_Ts_tmp_tmp) * d_Ts_tmp_tmp_tmp + i_Ts_tmp_tmp_tmp *
    ((-t244 - t178) - t245)) + t375) - t199) + t130 * x[14] * g_Ts_tmp_tmp_tmp))
    - t377 * (e_Ts_tmp * 0.1111111111111111 * x[11] * t296 - t311) *
    i_Ts_tmp_tmp_tmp) * f_Ts_tmp_tmp_tmp);
  t76 = e_Ts_tmp * ((t44 * 36.0 * f_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp * t273 + 54.0 *
                     t133_tmp * ((3.0 * a_tmp_tmp_tmp_tmp_tmp * ((t20 +
    0.33333333333333331) - t112) * ab_Ts_tmp + f_Ts_tmp_tmp_tmp * (-t249 *
    (-t150 + 2.0) + t249 * ab_Ts_tmp * ((t14 - t22) + 3.0))) +
    a_tmp_tmp_tmp_tmp_tmp * n_Ts_tmp) * t276) + (2.0 * f_Ts_tmp_tmp_tmp *
    (((f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp * ((n_Ts_tmp * (h_Ts_tmp * (t301 -
    18.0) + t124 * (t226 - 216.0)) + i_Ts_tmp_tmp_tmp * (i_Ts_tmp_tmp_tmp *
    (72.0 * t124 + t287) + t342)) - 54.0 * t286) + t292 * (1.0 - t318) * (54.0 *
    t78 * g_Ts_tmp_tmp_tmp + x[14])) - a_tmp_tmp_tmp * (36.0 * (t47_tmp * (4.5 -
    n_Ts_tmp_tmp) + t293) + 162.0 * t20 * t47_tmp)) - 54.0 * t124) +
      c_Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp * (162.0 * t124 + t188) - t306_tmp *
    (t297 - i_Ts_tmp_tmp_tmp * (t197 - t296)))) - t287) + 2.0 * t212_tmp * (54.0
    * eb_Ts_tmp * (1.0 - n_Ts_tmp) + t305)) * x[12] * t275) + ((b_Ts_tmp_tmp_tmp
    * t76 + g_Ts_tmp_tmp_tmp * (-e_Ts_tmp * t306_tmp * b_Ts_tmp_tmp * (1.0 -
    c_Ts_tmp_tmp_tmp) * (c_Ts_tmp_tmp_tmp + 1.0) * 18.0 + ab_Ts_tmp * (-t335 *
    t213 * i_Ts_tmp_tmp_tmp + e_Ts_tmp * (0.16666666666666666 * (t306_tmp *
    (t243 - t222) - t184 * 4.0) - 1.5 * t278 * (-0.88888888888888884 * t46 -
    t242))) * 36.0)) + f_Ts_tmp_tmp_tmp * ((ab_Ts_tmp * ((18.0 * t80 * (t376 *
    b_Ts_tmp_tmp * (i_Ts_tmp_tmp_tmp + -2.0) * (i_Ts_tmp_tmp_tmp + 2.0) + t213 *
    (n_Ts_tmp_tmp + -2.0) * i_Ts_tmp_tmp_tmp) - t228 * ((n_Ts_tmp_tmp *
    (5.333333333333333 * t319 * x[11] - t311) + 2.0 * t311) - 13.333333333333334
    * t319 * x[11]) * i_Ts_tmp_tmp_tmp) + 6.0 * t382 * (t225 * (t16 - 8.0) +
    t292 * (t65 - t222))) + 54.0 * t349 * ((t37 * 0.44444444444444442 + t340) -
    t56)) + t378_tmp * (-9.0 * t350 + t86 * t213))) * b_Ts_tmp_tmp_tmp;
  t151 = t220 * 4.0 * x[11] - t284_tmp;
  t178 = (n3pp * 0.035714285714285712 - 0.21428571428571427 * g_Ts_tmp *
          b_Ts_tmp_tmp) + -t133_tmp;
  t188 = n_Ts_tmp_tmp * (3.84 * t220 * x[11] - t284_tmp);
  t191 = 27.0 * t151;
  t192 = c_Ts_tmp_tmp * n_Ts_tmp_tmp;
  t213 = t292 * t66;
  t226 = (t65 - t250) * g_Ts_tmp;
  t244 = 3.36 * p_Ts_tmp * x[12] * x[11] - t324;
  t245 = t378_tmp * t25;
  t254 = t212_tmp * t244 * h_Ts_tmp_tmp_tmp;
  t276 = t290 * 4.0;
  t287 = t378_tmp * c_Ts_tmp_tmp;
  t296 = n3p * (1.0 - n_Ts_tmp);
  t310 = p_Ts_tmp * b_Ts_tmp_tmp;
  t350 = t212_tmp * l_Ts_tmp;
  t376 = t284_tmp * i_Ts_tmp_tmp_tmp;
  t16 = e_Ts_tmp * (t377 * t275 * i_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp *
                    Ts_tmp_tmp_tmp * (((ab_Ts_tmp * ((t42 + 1.0) + t16) +
    n_Ts_tmp) - t176) - 3.0) * c_Ts_tmp_tmp + 2.0 * t277 * Ts_tmp_tmp_tmp *
                    (27.0 * (1.0 - c_Ts_tmp_tmp_tmp) * (c_Ts_tmp_tmp_tmp + 1.0) *
                     g_Ts_tmp_tmp_tmp * (-l_Ts_tmp_tmp_tmp * 0.22222222222222221
    - t55) + (((f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp * (-t240 * (36.0 *
    (n_Ts_tmp_tmp + 0.75) + 27.0 * t66) + c_Ts_tmp_tmp_tmp * ((0.8 * n_Ts_tmp *
    t200 + t62 * (-n_Ts_tmp_tmp * 48.0 + 96.0)) + l_Ts_tmp_tmp * (t216 + 18.0)))
    + g_Ts_tmp_tmp_tmp * (n_Ts_tmp * ((96.0 * l_Ts_tmp_tmp_tmp * (t322 + -0.25)
    - 96.0 * t68) + 81.0 * t279) - 48.0 * (l_Ts_tmp_tmp_tmp * (-0.3125 *
    n_Ts_tmp_tmp - 0.125) - t68))) - t212_tmp * (m_Ts_tmp_tmp_tmp * (t241 - 81.0)
    * g_Ts_tmp_tmp_tmp + t196)) + t280 * (f_Ts_tmp_tmp * 18.0 - 81.0 * t147)) +
               c_Ts_tmp_tmp_tmp * (-t62 * 48.0 - l_Ts_tmp_tmp * 18.0)) -
              t306_tmp * (-t352 * d_Ts_tmp_tmp_tmp + t204)) * f_Ts_tmp_tmp_tmp) *
                    x[12]);
  t196 = (-b_Ts_tmp_tmp_tmp * (((-0.48 * t296 * p_Ts_tmp * x[11] *
             e_Ts_tmp_tmp_tmp + ab_Ts_tmp * (-t254 * (n_Ts_tmp_tmp + -2.0) +
              p_Ts_tmp * ((0.48 * x[11] * n3p + 0.24 * t245 * c_Ts_tmp_tmp) +
    0.48 * t42 * n3p * x[11]) * e_Ts_tmp_tmp_tmp)) - t254) + q_Ts_tmp_tmp_tmp *
           (-t292 * (n_Ts_tmp + -0.5) * t244 + 0.12 * t371 * (-t287 - t276)) *
           f_Ts_tmp_tmp_tmp) * 25.0 + 7.0 * g_Ts_tmp * (t310 *
           2.5714285714285716 * (1.0 - c_Ts_tmp_tmp_tmp) * (c_Ts_tmp_tmp_tmp +
            1.0) + f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp * (-(t42 + 1.0) * t310 *
             2.5714285714285716 - t350 * d_Ts_tmp_tmp) + a_tmp_tmp_tmp_tmp_tmp *
            (t359 * 5.1428571428571432 * b_Ts_tmp_tmp * d_Ts_tmp_tmp_tmp - t376))))
    * f_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp;
  t204 = t55 * h_Ts_tmp_tmp_tmp;
  t216 = 2.25 * t319 * x[11];
  t244 = -t311 + t216;
  t254 = 2.0 * a_tmp_tmp_tmp_tmp_tmp;
  t322 = -t25 * f_Ts_tmp_tmp_tmp + a_tmp_tmp_tmp;
  t386_tmp = g_Ts_tmp * g_Ts_tmp;
  t387_tmp = e_Ts_tmp * b_Ts_tmp_tmp_tmp;
  t389 = (t42 + 1.0) * ab_Ts_tmp;
  t390 = ((t389 + -1.0) + n_Ts_tmp) - t176;
  t391 = h_Ts_tmp_tmp * d_Ts_tmp_tmp_tmp + a_tmp_tmp_tmp_tmp_tmp;
  t376 *= f_Ts_tmp_tmp_tmp;
  t76 += Ts_tmp_tmp * ((36.0 * t314 * f_Ts_tmp_tmp_tmp * g_Ts_tmp * (t180 *
    c_Ts_tmp_tmp * Ts_tmp * t275 + b_Ts_tmp_tmp * t271) + ((b_Ts_tmp_tmp_tmp *
    t135 + g_Ts_tmp_tmp_tmp * (-t371 * b_Ts_tmp_tmp * g_Ts_tmp * (1.0 -
    c_Ts_tmp_tmp_tmp) * (c_Ts_tmp_tmp_tmp + 1.0) * 48.0 + ab_Ts_tmp * (-t367 *
    t362 * (n_Ts_tmp + -0.5) + e_Ts_tmp * (t337 * g_Ts_tmp * Ts_tmp_tmp_tmp *
    4.0 * b_Ts_tmp_tmp + t157 * Ts_tmp_tmp_tmp * (-1.1428571428571428 * t129 +
    t47_tmp * (3.4285714285714284 - n_Ts_tmp_tmp)) * 1.1666666666666667)) * 36.0))
    + f_Ts_tmp_tmp_tmp * ((ab_Ts_tmp * (-t366 * (n_Ts_tmp_tmp + -2.0) + p_Ts_tmp
    * ((54.0 * t124 * (-0.88888888888888884 - n_Ts_tmp_tmp) + 54.0 * h_Ts_tmp *
        (-n_Ts_tmp_tmp * 0.22222222222222221 + 0.44444444444444442)) + n_Ts_tmp *
       ((t104 + t360) - i_Ts_tmp_tmp_tmp * (t117 + n3p)) * 48.0) *
    e_Ts_tmp_tmp_tmp * x[11]) + p_Ts_tmp * (-48.0 * (-t124 + t159) + 144.0 *
    n_Ts_tmp * (-t124 + t368)) * e_Ts_tmp_tmp_tmp * x[11]) - t366)) *
                        b_Ts_tmp_tmp_tmp) + t179);
  t16 = ((Ts_tmp_tmp * t76 + Ts_tmp * (t306_tmp * 9.0 * (g_Ts_tmp_tmp_tmp *
            (n_Ts_tmp * t151 - 0.66666666666666663 * t357) - t305 * t220 *
            0.22222222222222221) + ((f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp *
    (c_Ts_tmp_tmp_tmp * ((t213 * 9.0 * t151 + t351 * (n_Ts_tmp_tmp * 30.0 - 60.0))
    + t292 * (t188 * 25.0 + t191)) + t314 * (30.0 * ((-n3pp / 10.0 + g_Ts_tmp *
    (b_Ts_tmp_tmp * 0.6 - t192)) - 2.8 * -t133_tmp) - 84.0 * t42 * t178)) +
    g_Ts_tmp_tmp_tmp * (-25.0 * (t306_tmp * (t151 * -0.36 - t188) + 1.2 * t353)
                        - 27.0 * n_Ts_tmp * (-t354 * t151 - 2.2222222222222223 *
    t353))) - p_Ts_tmp * t27 * 4.0 * (-o_Ts_tmp * 42.0 * t178 - t299)) +
             c_Ts_tmp_tmp_tmp * ((t317 * t151 + t351 * 30.0) - t292 * 24.0 *
              (4.5 * t220 * x[11] - t284_tmp))) + 2.0 * p_Ts_tmp * ((n_Ts_tmp *
              (i_Ts_tmp_tmp_tmp * (((t133_tmp * 42.0 + t226) - t251) + t307) -
               t308) - i_Ts_tmp_tmp_tmp * ((t133_tmp * 22.5 + t226) - t251)) +
             t299 * (1.0 - n_Ts_tmp_tmp) * g_Ts_tmp_tmp_tmp)) * f_Ts_tmp_tmp_tmp))
         + t16) + t196;
  t59_tmp = b_Ts_tmp * b_Ts_tmp;
  t76 = Ts_tmp_tmp * t59_tmp;
  t135_tmp = Ts_tmp_tmp * b_Ts_tmp;
  t38 = (12.0 * t61 * t106 + 12.0 * ((b_Ts_tmp_tmp_tmp * ((b_Ts_tmp_tmp_tmp *
             t41 + g_Ts_tmp_tmp_tmp * (-6.0 * t88 * (n_Ts_tmp +
    -0.083333333333333329) + 12.0 * ab_Ts_tmp * ((-c_Ts_tmp_tmp_tmp *
    (-c_Ts_tmp_tmp_tmp * (t83 + t51) + t48) - t46 * 0.25) + t47_tmp *
    (n_Ts_tmp_tmp * 0.79166666666666663 - 0.5) * h_Ts_tmp_tmp_tmp))) +
            f_Ts_tmp_tmp_tmp * ((ab_Ts_tmp * ((c_Ts_tmp_tmp_tmp * (-t38 + t56 *
    (n_Ts_tmp_tmp * 9.5 - 18.0)) - 6.0 * t80 * (t77 - t79)) - 3.0 * t44 * x[12] *
    (n_Ts_tmp_tmp + -2.0)) + c_Ts_tmp_tmp_tmp * ((12.5 * t56 + 3.0 * t37) - t86 *
    t56)) + t44 * (t87 - 3.0) * x[12])) - g_Ts_tmp_tmp_tmp * (4.0 * (t101 *
             e_Ts_tmp_tmp_tmp + t98) + 12.0 * ab_Ts_tmp * (e_Ts_tmp_tmp_tmp *
             (-0.58333333333333337 * (-t68 + l_Ts_tmp_tmp_tmp *
    (0.2857142857142857 - t89)) + t97 * n_Ts_tmp) + t98 * (n_Ts_tmp_tmp +
              -1.3333333333333333)))) + f_Ts_tmp_tmp_tmp * ((ab_Ts_tmp * (-7.0 *
             t72_tmp * t90 + (2.0 * t93 + t69_tmp * (1.0 - t91) *
              h_Ts_tmp_tmp_tmp) * (i_Ts_tmp_tmp_tmp + 2.0) * (i_Ts_tmp_tmp_tmp +
              -2.0) * d_Ts_tmp_tmp_tmp) + t72_tmp * (t87 * l_Ts_tmp_tmp - 7.0 *
             t99)) + t73 * (-12.0 * n_Ts_tmp + 3.0))) * b_Ts_tmp_tmp_tmp) *
    Ts_tmp_tmp;
  t38_tmp = x[11] * b_Ts_tmp_tmp_tmp;
  t38 = t38_tmp * Ts_tmp_tmp * (t38 + 36.0 * Ts_tmp_tmp_tmp *
    (((b_Ts_tmp_tmp_tmp * t50 - g_Ts_tmp_tmp_tmp * ((1.3333333333333333 *
    f_Ts_tmp_tmp * t100 + 1.3333333333333333 * t147 * (0.25 - n_Ts_tmp)) +
    ab_Ts_tmp * ((1.1666666666666667 * t165 + c_Ts_tmp_tmp_tmp * (2.0 * t116 *
    c_Ts_tmp_tmp_tmp - t148)) * c_Ts_tmp_tmp_tmp + t148 * 0.25) * 4.0)) +
      f_Ts_tmp_tmp_tmp * ((((ab_Ts_tmp * ((g_Ts_tmp * (t164 * d_Ts_tmp_tmp_tmp *
    (i_Ts_tmp_tmp_tmp + -2.0) * (i_Ts_tmp_tmp_tmp + 2.0) * t13 + i_Ts_tmp *
    (n_Ts_tmp_tmp * 1.1666666666666667 - 2.3333333333333335)) - t111) +
    c_Ts_tmp_tmp_tmp * (2.3333333333333335 * t162 * c_Ts_tmp_tmp_tmp - t163 *
                        (i_Ts_tmp_tmp_tmp + -2.0) * (i_Ts_tmp_tmp_tmp + 2.0))) +
    2.3333333333333335 * n_Ts_tmp * t166) - t120) + t109 * 1.1666666666666667) +
    t141 * (t91 - 3.0))) * b_Ts_tmp_tmp_tmp + t113 * t102 * e_Ts_tmp_tmp_tmp));
  t41 = e_Ts_tmp * t76;
  t38 = t41 * (-4.0 * ((t92 * Ts_tmp + b_Ts_tmp_tmp_tmp * (6.0 * t115 * ((3.0 *
    h_Ts_tmp_tmp * (t160 * c_Ts_tmp_tmp_tmp - g_Ts_tmp_tmp_tmp *
                    (i_Ts_tmp_tmp_tmp * (-t120 + t128) - t127) *
                    f_Ts_tmp_tmp_tmp) + t24 * (((i_Ts_tmp_tmp_tmp * (-0.75 * n3p
    + t104 * i_Ts_tmp_tmp_tmp) + t103) - t124) + t156)) + t137) - x[11] *
    ((f_Ts_tmp_tmp_tmp * ((ab_Ts_tmp * (c_Ts_tmp_tmp_tmp * ((-t212_tmp * (t79 +
    t77) + t37 * (0.66666666666666663 - t201)) + t56 * (-t108 - 3.0)) + t44 *
    0.5 * x[12] * (n_Ts_tmp_tmp + -2.0)) + g_Ts_tmp * (-3.0 * t269 + t263)) +
    c_Ts_tmp_tmp_tmp * ((-t37 * 0.33333333333333331 + 2.4166666666666665 * t56)
                        - t259 * c_Ts_tmp_tmp_tmp)) - t58 * (n_Ts_tmp +
    -0.41666666666666669)) - q_Ts_tmp_tmp_tmp * ((-c_Ts_tmp_tmp_tmp *
    (-c_Ts_tmp_tmp_tmp * (t46 * 0.33333333333333331 - t83) + t48) + t88 * t229)
    - t46 * 0.16666666666666666) * ab_Ts_tmp) * 18.0)) + t65 * t44 *
                       f_Ts_tmp_tmp_tmp * t273) + t38);
  t48 = 7.0 * t378_tmp * f_Ts_tmp_tmp_tmp;
  t50 = ((ab_Ts_tmp * ((t42 + 1.0) - t22) + n_Ts_tmp) - t176) * Ts_tmp;
  t61 = t43_tmp * b_Ts_tmp_tmp_tmp;
  t75 = (n_Ts_tmp_tmp + -2.0) * (n_Ts_tmp + -0.5);
  t77 = h_Ts_tmp_tmp * t25;
  t79 = t725 * f_Ts_tmp_tmp_tmp;
  t83 = t77 * g_Ts_tmp_tmp_tmp;
  t77 = ((((b_Ts_tmp * ((((t50 + 1.0) - 2.0 * f_Ts_tmp_tmp_tmp * (t75 *
    f_Ts_tmp_tmp_tmp + t61 * t322)) - 2.0 * n_Ts_tmp) + t77 * 4.0 *
                        g_Ts_tmp_tmp_tmp) + n_Ts_tmp) + t389) - 1.0) - 2.0 * t83)
    - 2.0 * (e_Ts_tmp_tmp_tmp * t273 + t79 * t391) * Ts_tmp_tmp_tmp * Ts_tmp_tmp;
  t85 = t387_tmp * Ts_tmp_tmp;
  t115 = -a_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp + o_Ts_tmp_tmp_tmp;
  t120 = e_Ts_tmp_tmp_tmp * Ts_tmp_tmp_tmp;
  t125_tmp = 1.0 / M[0];
  t141_tmp = 1.0 / M[2];
  t144 = 1.0 / M[4];
  t147_tmp = 1.0 / b_Ts_tmp_tmp_tmp;
  t156_tmp = 1.0 / Ts_tmp_tmp;
  t77 = 1.0 / t77;
  t160_tmp = 1.0 / M[5];
  t92 = 1.0 / (((((b_Ts_tmp * (((n_Ts_tmp * (Ts_tmp + -2.0) + ab_Ts_tmp *
    ((((-2.0 * (n_Ts_tmp_tmp + -0.5) * Ts_tmp + 2.0 * t61 * t25) + t42 * (Ts_tmp
    + -2.0)) + n_Ts_tmp_tmp) - 2.0)) + 1.0) - t174 * (b_Ts_tmp_tmp_tmp * (t25 *
    b_Ts_tmp_tmp_tmp + t43_tmp) - 2.0 * t25)) + n_Ts_tmp) + t389) - 1.0) - 2.0 *
                t83) - 2.0 * Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp * (ab_Ts_tmp *
    (t629 * (n_Ts_tmp_tmp + -2.0) + l_Ts_tmp * b_Ts_tmp_tmp_tmp) + t629) +
    q_Ts_tmp_tmp_tmp * (-0.5 * (-db_Ts_tmp * b_Ts_tmp_tmp_tmp + t345_tmp) + t280
                        * e_Ts_tmp_tmp_tmp) * f_Ts_tmp_tmp_tmp) * Ts_tmp_tmp);
  t163 = t141_tmp * t141_tmp;
  t174_tmp = t156_tmp * t156_tmp;
  t156 = t156_tmp * t174_tmp;
  t176 = t125_tmp * t125_tmp;
  t177 = t147_tmp * t147_tmp;
  t178 = t177 * t177;
  t147 = t147_tmp * t177;
  t177_tmp = b_Ts_tmp_tmp * b_Ts_tmp;
  t177 = (t85 * (t177_tmp + c_Ts_tmp_tmp) + t284_tmp) * g_Ts_tmp;
  t14 = ((t38 + (((Ts_tmp_tmp * t16 + t377 * e_Ts_tmp * ((3.0 * f_Ts_tmp_tmp_tmp
    * (-t249 * (1.0 - n_Ts_tmp) + a_tmp_tmp_tmp_tmp_tmp * ((0.88888888888888884 *
    n_Ts_tmp_tmp + t20) + 0.33333333333333331) * f_Ts_tmp_tmp_tmp) -
    a_tmp_tmp_tmp_tmp_tmp * (1.0 - c_Ts_tmp_tmp_tmp) * (c_Ts_tmp_tmp_tmp + 1.0))
              + t249 * ((t14 + t143) + 3.0) * t24) * c_Ts_tmp_tmp * t277) + t725
                  * (-t387_tmp * x[12] * (((-0.25 * t296 + ab_Ts_tmp * (n3p *
    (t42 + 1.0) * 0.25 - t204 * (n_Ts_tmp_tmp + -2.0))) - t204) + t272 *
              (-l_Ts_tmp_tmp_tmp * 0.25 * c_Ts_tmp_tmp_tmp - t54 * (n_Ts_tmp +
    -0.5)) * f_Ts_tmp_tmp_tmp) * 48.0 - 16.0 * g_Ts_tmp * ((((-t254 * (0.1875 *
    t381 * c_Ts_tmp_tmp + t249 * t244) * f_Ts_tmp_tmp_tmp + 0.8125 * t311) +
    n_Ts_tmp * t244) + ab_Ts_tmp * (((-0.4375 * t311 * n_Ts_tmp_tmp + t42 * t244)
    - t311) + e_Ts_tmp * (2.25 * m_Ts_tmp_tmp_tmp * x[11] - 0.375 * l_Ts_tmp *
    c_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp))) - t216)) * f_Ts_tmp_tmp_tmp) + 7.0 *
                 ab_Ts_tmp * Ts_tmp_tmp_tmp * n_Ts_tmp_tmp * e_Ts_tmp_tmp_tmp *
                 t386_tmp * d_Ts_tmp_tmp * t322) * Ts_tmp_tmp) - t48 * (p_Ts_tmp
          * 2.5714285714285716 * t390 * c_Ts_tmp_tmp * Ts_tmp - t376 * t391)) *
    t176 * t163 * (t174_tmp * t174_tmp) * t178 * t77;
  t16 = t124 + h_Ts_tmp;
  t38 = 2.0 * h_Ts_tmp;
  t77 = h_Ts_tmp * 0.33333333333333331;
  t143 = -t124 - t77;
  t171 = 0.75 * g_Ts_tmp * b_Ts_tmp_tmp;
  t179 = t610 - t171;
  t184 = t25 * t179;
  t188 = -2.0 * t179;
  t196 = t110 + t25 * (n_Ts_tmp_tmp * 0.1111111111111111 - 0.44444444444444442) *
    n3p;
  t216 = 0.33333333333333331 * n3p;
  t222 = t216 * t25;
  t226 = -t109 + t222;
  t244 = t70 * d_Ts_tmp_tmp_tmp;
  t272 = t69_tmp * h_Ts_tmp_tmp_tmp;
  t35 = 4.5 - t35;
  t169 *= t54;
  t65 = k_Ts_tmp_tmp * i_Ts_tmp_tmp_tmp;
  t67 *= n_Ts_tmp;
  t277 = t179 * n_Ts_tmp_tmp;
  t111 *= x[11];
  t305 = t56 * (1.5 - n_Ts_tmp_tmp);
  t308 = t66 * t56;
  t317 = 2.0 * t341;
  t337 = t88 * (n_Ts_tmp_tmp + -0.5);
  t351 = t333 * q_Ts_tmp_tmp_tmp;
  t203 *= 2.0;
  t353 = a_tmp_tmp_tmp * x[11];
  t366 = t25 * t151 * g_Ts_tmp;
  t245 *= t151;
  t377 = 0.375 * g_Ts_tmp * b_Ts_tmp_tmp;
  t381 = t610 - t377;
  t387 = db_Ts_tmp * t381;
  t392 = t220 * n3p;
  t394 = l_Ts_tmp * t381;
  t395 = p_Ts_tmp * t78;
  t396 = 0.66666666666666663 * t46;
  t397 = t37 * 18.0;
  t40 = f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp *
    (c_Ts_tmp_tmp_tmp * (((-36.0 * i_Ts_tmp_tmp_tmp * (-t68 + l_Ts_tmp_tmp_tmp)
    - 54.0 * t56) + l_Ts_tmp_tmp_tmp * 18.0 * t11) - t308 * 18.0) + t259 *
     (-36.0 * (n_Ts_tmp_tmp + -0.75) + 27.0 * t42)) + g_Ts_tmp_tmp_tmp * (-36.0 *
    (0.5 * (t46 + t88) - t88 * n_Ts_tmp_tmp) + 54.0 * n_Ts_tmp * (-t242 + t396)))
    + 2.0 * t335 * (-27.0 * t78 * g_Ts_tmp_tmp_tmp + x[14])) + g_Ts_tmp * (-54.0
    * t269 + t203)) + c_Ts_tmp_tmp_tmp * ((t56 * 36.0 + t397) - t212_tmp * (t297
    - i_Ts_tmp_tmp_tmp * ((t197 + t352) - t194)))) - t212_tmp * h_Ts_tmp_tmp_tmp
    * (t353 * 18.0 + t206);
  t259 = Ts_tmp_tmp_tmp * t273;
  t70 = e_Ts_tmp * (-t259 * t287 * f_Ts_tmp_tmp_tmp + x[11] * ((t24 * ((n_Ts_tmp
    * (-t244 * (i_Ts_tmp_tmp_tmp + -2.0) * (i_Ts_tmp_tmp_tmp + 2.0) - 1.5 *
       e_Ts_tmp_tmp_tmp * t196) + 2.0 * e_Ts_tmp_tmp_tmp * (t181 + t25 * (t201 +
    -0.083333333333333329) * n3p)) + 2.0 * t244 * (n_Ts_tmp_tmp + -1.5)) + t373 *
    (t121 * t72_tmp - t272)) + 3.0 * f_Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp *
    (t69_tmp * (0.66666666666666663 - n_Ts_tmp) * d_Ts_tmp_tmp_tmp - t136 * t226)
    + ((-c_Ts_tmp_tmp_tmp * (-e_Ts_tmp_tmp_tmp * (t143 * i_Ts_tmp_tmp_tmp + t121)
    + t70 * (n_Ts_tmp_tmp + -1.3333333333333333) * h_Ts_tmp_tmp_tmp) + t93 *
        0.16666666666666666 * (n_Ts_tmp_tmp + -1.3333333333333333)) +
       0.66666666666666663 * t69_tmp * h_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp + -0.5))
    * g_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp)) * t76);
  t76 = p_Ts_tmp * x[11];
  t89 = t200 * c_Ts_tmp_tmp_tmp;
  t82 = (f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp * (((-4.0 *
    i_Ts_tmp_tmp_tmp * (-t245 + t392) + n_Ts_tmp * (i_Ts_tmp_tmp_tmp * (t234 *
    n3p - t245) - 4.0 * (t103 * t220 - t366))) - t366) + p_Ts_tmp *
              (c_Ts_tmp_tmp_tmp * (-(-t387 * (2.0 - n_Ts_tmp_tmp) + k_Ts_tmp_tmp
    * (t288 + -0.5625) * n3p) * 10.666666666666666 + 2.0 * t208) +
               5.333333333333333 * t103 * m_Ts_tmp_tmp_tmp)) + c_Ts_tmp_tmp_tmp *
             ((-t314 * 0.44444444444444442 * (-t375 * g_Ts_tmp_tmp_tmp - t198) +
               (-t237 + 3.0) * t151 * g_Ts_tmp_tmp_tmp * g_Ts_tmp) + 3.0 * t80 *
              t151 * (n_Ts_tmp_tmp + -1.3333333333333333) * g_Ts_tmp_tmp_tmp)) +
            p_Ts_tmp * g_Ts_tmp_tmp_tmp * (10.666666666666666 * (t394 + t175 *
              (0.1875 - t288)) - 21.333333333333332 * n_Ts_tmp * (t394 + t175 *
              (-0.28125 * n_Ts_tmp_tmp + 0.375)))) + n_Ts_tmp * (-t395 * 4.0 *
            n3p - 3.0 * t366)) + p_Ts_tmp * (c_Ts_tmp_tmp_tmp *
           (-10.666666666666666 * (0.375 * k_Ts_tmp_tmp * n3p + t387) + t87 *
            k_Ts_tmp_tmp * n3p) + t88 * t205 * 0.44444444444444442)) -
         c_Ts_tmp_tmp_tmp * (-t80 * t151 * g_Ts_tmp_tmp_tmp + p_Ts_tmp * (-2.0 *
           t105 * n3p - t282 * 0.22222222222222221) * x[11])) +
    1.3333333333333333 * t76 * ((t24 * (((c_Ts_tmp_tmp_tmp * (t89 / 5.0 - t169)
    + l_Ts_tmp_tmp * t35) + t62 * (8.0 * n_Ts_tmp_tmp - 16.0)) *
    c_Ts_tmp_tmp_tmp + t240 * 4.0 * (i_Ts_tmp_tmp_tmp + -0.5) *
    (i_Ts_tmp_tmp_tmp + 0.5)) - t373 * (-t55 - 1.5 * l_Ts_tmp_tmp_tmp)) - 3.0 *
    f_Ts_tmp_tmp_tmp * (-c_Ts_tmp_tmp_tmp * ((t67 - d_Ts_tmp_tmp_tmp * (t204 +
    n3p)) + 2.6666666666666665 * t62) + (((g_Ts_tmp * (t145 * c_Ts_tmp_tmp_tmp *
    (n_Ts_tmp_tmp + -0.5) + 2.6666666666666665 * t65) + n_Ts_tmp * ((-t279 +
    l_Ts_tmp_tmp_tmp * (-t81 + 2.0)) - 5.333333333333333 * t68)) +
    l_Ts_tmp_tmp_tmp * n_Ts_tmp_tmp) - l_Ts_tmp_tmp_tmp * 0.5) *
                        g_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp)) * b_Ts_tmp;
  t105 = m_Ts_tmp * t44 * c_Ts_tmp_tmp_tmp;
  t121 = t336 * x[11];
  t136 = t54 * db_Ts_tmp;
  t151 = t610 + t377;
  t175 = 12.0 * n_Ts_tmp_tmp;
  t181 = 1.3333333333333333 * l_Ts_tmp_tmp;
  t205 = m_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp;
  t234 = t151 * 36.0;
  t235 = m_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp;
  t239 = t240 * x[14] * g_Ts_tmp_tmp_tmp;
  t240 = t610 + 1.375 * g_Ts_tmp * b_Ts_tmp_tmp;
  t245 = t54 * x[13];
  t269 = t136 * x[13];
  t282 = t304 * 18.0;
  t151 = 0.5 * (((t373 * 24.0 * t151 + g_Ts_tmp_tmp_tmp * ((-g_Ts_tmp *
    (b_Ts_tmp_tmp * 16.5 + t250) - t251) - t356)) + c_Ts_tmp_tmp_tmp * (-t47_tmp
    * t206 - t331 * t285)) + t252) * c_Ts_tmp_tmp_tmp + ((((f_Ts_tmp_tmp_tmp *
    ((((f_Ts_tmp_tmp_tmp * (((n_Ts_tmp * (t323 * (t183 - 15.0) + t25 * (-t175 +
    48.0) * t151) + t25 * (-12.0 * t151 + t241 * (t610 - 1.9166666666666667 *
    g_Ts_tmp * b_Ts_tmp_tmp))) + t205 * (9.0 * ((n_Ts_tmp_tmp * (-t62 + t181) +
    2.0 * t62) - 2.0 * l_Ts_tmp_tmp) - 6.0 * t66 * l_Ts_tmp_tmp)) - t323 * t217)
        + c_Ts_tmp_tmp_tmp * ((c_Ts_tmp_tmp_tmp * ((-18.0 * t78 *
    g_Ts_tmp_tmp_tmp * (t56 + t37) + t309) + t334 * m_Ts_tmp_tmp_tmp) +
    g_Ts_tmp_tmp_tmp * (t234 - t295 * (t610 - 0.6071428571428571 * g_Ts_tmp *
    b_Ts_tmp_tmp))) + i_Ts_tmp_tmp_tmp * (-t299 - 15.0 * t332))) - t309 * 0.5) +
      t235 * (t68 * 9.0 + l_Ts_tmp_tmp_tmp * (t175 - 6.0))) + t234 * t26 *
     (n_Ts_tmp_tmp + -1.3333333333333333)) - t282 * t13) - t253 * (-12.0 * t240 *
    d_Ts_tmp_tmp_tmp - t245)) + c_Ts_tmp_tmp_tmp * (((c_Ts_tmp_tmp_tmp * (-t25 *
    t234 + 7.5 * t323) + 0.5 * t62 * ((-t197 - t374) + t194)) + t339) + t355)) +
    i_Ts_tmp_tmp_tmp * ((t383 * n3p - t239) - t269)) * f_Ts_tmp_tmp_tmp;
  t175 = p_Ts_tmp * t25;
  t183 = t378_tmp * t362;
  t194 = t381 * d_Ts_tmp_tmp_tmp;
  t197 = 18.0 * x[12];
  t34 = (f_Ts_tmp_tmp_tmp * (((n_Ts_tmp * (t183 * (27.0 * n_Ts_tmp_tmp - 54.0) +
             t175 * (-t344 + 96.0) * x[12] * n3p) + 36.0 * n_Ts_tmp_tmp *
            (-t378_tmp * (t76 * 5.0 * x[12] - t324) + t175 * x[12] * n3p)) +
           p_Ts_tmp * ((t345_tmp * t13 * (i_Ts_tmp_tmp_tmp + -2.0) *
                        (i_Ts_tmp_tmp_tmp + 2.0) * t381 * 48.0 - t215 * n3p) -
                       96.0 * t72_tmp * (t225 * (-t288 + 0.75) - t194 * (1.5 -
              n_Ts_tmp_tmp)))) + 27.0 * t183) + c_Ts_tmp_tmp_tmp * (p_Ts_tmp * (
           -4.0 * (-t197 * g_Ts_tmp_tmp_tmp * n3p - t190 * e_Ts_tmp_tmp_tmp) -
           84.0 * n3p * n_Ts_tmp_tmp * g_Ts_tmp_tmp_tmp * x[12]) - 54.0 *
          o_Ts_tmp * t25 * g_Ts_tmp * t362)) + p_Ts_tmp * (4.0 *
    (i_Ts_tmp_tmp_tmp * (-t379 * g_Ts_tmp_tmp_tmp - t333 * h_Ts_tmp_tmp_tmp) +
     a_tmp_tmp_tmp_tmp_tmp * (-t344 + 12.0) * t381 * e_Ts_tmp_tmp_tmp) + t373 *
    (144.0 * e_Ts_tmp_tmp_tmp * ((n_Ts_tmp_tmp + -1.3333333333333333) * t381 *
    h_Ts_tmp_tmp_tmp + t134 * k_Ts_tmp_tmp) + 72.0 * f_Ts_tmp_tmp *
     (n_Ts_tmp_tmp + -1.3333333333333333) * x[12]));
  t175 = (-0.14285714285714285 * g_Ts_tmp * b_Ts_tmp_tmp + -t133_tmp) + t343;
  t190 = e_Ts_tmp * t145 * x[11] - t311;
  t215 = t327 * t190;
  t217 = e_Ts_tmp * t304;
  t225 = -t215 + t217;
  t234 = t133_tmp * n_Ts_tmp_tmp;
  t241 = e_Ts_tmp * t247;
  t262 = t20 * g_Ts_tmp_tmp_tmp;
  t280 = 1.5 * x[11];
  t287 = (n3pp * 0.14285714285714285 - 0.2857142857142857 * g_Ts_tmp *
          b_Ts_tmp_tmp) + -t133_tmp;
  t66 = -t195 * ((a_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp * 21.0 * t175 - t247 * 9.0)
                  + g_Ts_tmp_tmp_tmp * ((g_Ts_tmp * (t243 - t250) - 10.5 *
    -t133_tmp) - t251)) + t252) * c_Ts_tmp_tmp_tmp + ((f_Ts_tmp_tmp_tmp *
    ((f_Ts_tmp_tmp_tmp * (42.0 * e_Ts_tmp * ((n_Ts_tmp * (-t257 * x[11] - t123 *
    t175) - t323 * 0.14285714285714285) + t25 * (t234 + t175)) +
    c_Ts_tmp_tmp_tmp * (((-n_Ts_tmp_tmp * 36.0 * t225 + t282 * e_Ts_tmp * t66) -
    72.0 * t215) + 54.0 * t217)) + g_Ts_tmp_tmp_tmp * (36.0 * (t241 * 0.5 -
    i_Ts_tmp_tmp_tmp * (t292 * t190 + e_Ts_tmp * t291)) - ((-72.0 * t155 * t241
    - 72.0 * t367 * t190) + 72.0 * t241) * n_Ts_tmp)) - t382 * (4.0 * (31.5 *
    g_Ts_tmp_tmp_tmp * (-n_Ts_tmp_tmp * ((n3pp / 21.0 + -t133_tmp) -
    0.095238095238095233 * g_Ts_tmp * b_Ts_tmp_tmp) + t175) + i_Ts_tmp_tmp_tmp *
    (-3.0 * t332 - t299)) + 126.0 * t262 * t175)) + e_Ts_tmp * (n_Ts_tmp *
    ((-126.0 * t265 * x[11] + 126.0 * t25 * t175) + 54.0 * t304 *
     c_Ts_tmp_tmp_tmp) - 4.0 * (-t253 * (-10.5 * t287 * d_Ts_tmp_tmp_tmp - t245)
    + i_Ts_tmp_tmp_tmp * ((-t280 * n3p - t239) - t269)))) - 36.0 * t225 *
    c_Ts_tmp_tmp_tmp) * f_Ts_tmp_tmp_tmp;
  t155 = t25 * n3p;
  t175 = t41 * x[11];
  t34 = b_Ts_tmp * (Ts_tmp_tmp * (t330 * ((t373 * (t629 * 24.0 * t381 + t380 *
    f_Ts_tmp_tmp) + c_Ts_tmp_tmp_tmp * (-6.0 * x[12] * g_Ts_tmp_tmp_tmp * n3p -
    t207 * e_Ts_tmp_tmp_tmp)) - t272 * t281) + ((f_Ts_tmp_tmp_tmp * t34 +
    n_Ts_tmp * ((144.0 * t194 * t371 + 27.0 * t378_tmp * (-t324 + t76 * (t361 -
    0.07407407407407407 * t232))) + p_Ts_tmp * (4.0 * (-t197 * t25 * n3p - t199 *
    e_Ts_tmp_tmp_tmp) + t297 * t130 * e_Ts_tmp_tmp_tmp))) - 4.0 * p_Ts_tmp *
    (((c_Ts_tmp_tmp_tmp * ((i_Ts_tmp_tmp_tmp * ((-t131 * x[13] - t211 *
    g_Ts_tmp_tmp_tmp) - t218 * 9.0) + t246 * t69_tmp) + t345_tmp * 24.0 * t381)
       - t248 * e_Ts_tmp_tmp_tmp) - t266 * t25) + t109 * ((-4.5 * x[12] - t232)
    + t233 * g_Ts_tmp_tmp_tmp))) * f_Ts_tmp_tmp_tmp) + t66);
  t15 = e_Ts_tmp * (Ts_tmp_tmp * (t135_tmp * t151 * 4.0 - t197 * Ts_tmp_tmp_tmp *
    (((3.0 * t149 + 3.0 * ((c_Ts_tmp_tmp_tmp * (1.3333333333333333 * t116 *
    c_Ts_tmp_tmp_tmp - t148) + i_Ts_tmp_tmp_tmp * (-t124 * 0.44444444444444442 -
    h_Ts_tmp * 0.22222222222222221)) + t216) * c_Ts_tmp_tmp_tmp) *
      g_Ts_tmp_tmp_tmp * ab_Ts_tmp + f_Ts_tmp_tmp_tmp * ((((ab_Ts_tmp *
    ((d_Ts_tmp_tmp_tmp * (2.0 * t55 * (n_Ts_tmp_tmp + -1.5) - l_Ts_tmp_tmp_tmp *
    0.33333333333333331) + t153) + n_Ts_tmp * (((-t142 + n_Ts_tmp_tmp * (-t222 +
    t153)) - 1.3333333333333333 * t109) + 1.3333333333333333 * t155)) + n_Ts_tmp
    * (-t155 + t153)) + t152) - t153) + t222)) + a_tmp_tmp_tmp * (-t296 *
    0.33333333333333331 - t204))) + t294 * ((t25 * t15 * t24 + a_tmp_tmp_tmp *
    (1.0 - n_Ts_tmp)) - 3.0 * f_Ts_tmp_tmp_tmp * (h_Ts_tmp_tmp * ((t20 + 1.0) -
    t112) * g_Ts_tmp_tmp_tmp - t25 * (n_Ts_tmp + -0.33333333333333331))) *
                    c_Ts_tmp_tmp);
  t66 = (-0.5 * g_Ts_tmp * b_Ts_tmp_tmp + -t133_tmp) + t258;
  t108 = -2.0 * t66;
  t112 = t333 * g_Ts_tmp_tmp_tmp;
  t6 = t231 * h_Ts_tmp_tmp_tmp;
  t130 = 3.0 * t302 * e_Ts_tmp_tmp_tmp;
  t13 = f_Ts_tmp_tmp_tmp * (((((f_Ts_tmp_tmp_tmp * (((f_Ts_tmp_tmp_tmp *
    ((c_Ts_tmp_tmp_tmp * (-x[12] * (t37 * (-t236 + 0.53333333333333333) + t56 *
    (-0.8 - n_Ts_tmp_tmp)) * 22.5 - 12.0 * t72_tmp * (t290 * (0.5 - t260) +
    i_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp * t66 + t108))) + 6.0 * e_Ts_tmp_tmp_tmp *
      (t290 * (t81 + 0.25) + i_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp * ((-4.25 *
    g_Ts_tmp * b_Ts_tmp_tmp + t258) + -t133_tmp) + t108))) + 6.0 * t56 * x[12] *
     (i_Ts_tmp_tmp_tmp + -2.0) * (i_Ts_tmp_tmp_tmp + 2.0) * t13) +
    g_Ts_tmp_tmp_tmp * (-n_Ts_tmp * (t189 * t158 + t197 * (-t242 - t396)) + t88 *
                        x[12] * (t210 + 6.0))) + c_Ts_tmp_tmp_tmp * (t317 +
    (t214 * i_Ts_tmp_tmp_tmp * t66 + (-4.5 - t237) * x[11] * n3p) *
    e_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp)) + i_Ts_tmp_tmp_tmp * (-t230 * x[14] *
    e_Ts_tmp_tmp_tmp - 6.0 * t346 * g_Ts_tmp_tmp_tmp)) - t202 * t69_tmp *
    n_Ts_tmp_tmp) + k_Ts_tmp_tmp * (t69_tmp * t13 * 18.0 - 3.0 *
    l_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp)) + c_Ts_tmp_tmp_tmp *
    ((c_Ts_tmp_tmp_tmp * ((t289 * t189 * e_Ts_tmp_tmp_tmp - t351) +
    i_Ts_tmp_tmp_tmp * ((-12.0 * t66 * e_Ts_tmp_tmp_tmp - t219) + t221)) +
      i_Ts_tmp_tmp_tmp * (t202 * t56 * e_Ts_tmp_tmp_tmp + 6.0 * t347)) + t47_tmp
     * (-m_Ts_tmp * 18.0 + t227))) + i_Ts_tmp_tmp_tmp * (6.0 * t240 *
    e_Ts_tmp_tmp_tmp + t219 * 0.5)) + t112) + c_Ts_tmp_tmp_tmp * (t130 - t6);
  t66 = (-1.75 * g_Ts_tmp * b_Ts_tmp_tmp + t258) + -t133_tmp;
  t69 = t78 * n3p;
  t81 = t25 * g_Ts_tmp;
  t108 = d_Ts_tmp_tmp_tmp * (12.0 * o_Ts_tmp * t66 + t299);
  t138 = t76 * t145;
  t142 = -t138 - t284_tmp;
  t145 = t54 * t206;
  t148 = t80 * 18.0;
  t91 = p_Ts_tmp * ((2.0 * t384 - 2.0 * t145) - t91 * (-t280 * t331 - t145));
  t153 = (-t385 * (t142 * 9.0 + t148 * d_Ts_tmp_tmp) + t91) +
    ((((f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp * ((n_Ts_tmp * (t395 * (-t344 +
              48.0) * n3p - t321 * t386_tmp * d_Ts_tmp_tmp) + p_Ts_tmp *
            ((c_Ts_tmp_tmp_tmp * (-48.0 * (-db_Ts_tmp * t66 * (2.0 -
    n_Ts_tmp_tmp) + k_Ts_tmp_tmp * (n_Ts_tmp_tmp * 0.875 - 0.375) * n3p) + 6.0 *
    t208) - t69 * 24.0) + t103 * t285)) + t81 * (t191 * n_Ts_tmp_tmp + t284_tmp *
            18.0)) + c_Ts_tmp_tmp_tmp * (((-54.0 * t262 * d_Ts_tmp_tmp *
             t386_tmp - 54.0 * g_Ts_tmp_tmp_tmp * t386_tmp * d_Ts_tmp_tmp) - 2.0
            * t314 * (-t235 * t214 * n3p - t198)) + (-108.0 * t220 * x[11] +
            63.0 * t284_tmp) * g_Ts_tmp * g_Ts_tmp_tmp_tmp * n_Ts_tmp_tmp)) +
         p_Ts_tmp * (-4.0 * (t331 * (10.5 * n_Ts_tmp_tmp - 1.5) * x[11] - t108)
                     + 8.0 * n_Ts_tmp * (t331 * (2.25 * n_Ts_tmp_tmp - 3.0) * x
           [11] - t108))) + n_Ts_tmp * (-t395 * 24.0 * n3p + 54.0 * t25 *
         t386_tmp * d_Ts_tmp_tmp)) + 2.0 * t314 * ((6.0 * m_Ts_tmp_tmp_tmp * n3p
         + t62 * x[13]) + t224)) + t359 * (4.0 * ((-t254 * t299 - 1.5 *
         k_Ts_tmp_tmp * n3p) + db_Ts_tmp * (((t307 + g_Ts_tmp * (b_Ts_tmp_tmp *
            21.0 - t250)) - t251) - t356)) + t86 * k_Ts_tmp_tmp * n3p)) + t228 *
     t25 * t142) * f_Ts_tmp_tmp_tmp;
  t610 = e_Ts_tmp * x[12];
  t60 = t610 * x[11];
  t66 = -t60 + t223;
  t91 = (n3pp / 12.0 + -t133_tmp) - 0.16666666666666666 * g_Ts_tmp *
    b_Ts_tmp_tmp;
  t103 = 2.6666666666666665 * t60 - t223;
  t108 = t347 * e_Ts_tmp;
  t140 = t76 * t164;
  t142 = t140 - t284_tmp;
  t145 = t81 * t142;
  t6 = ((t153 * Ts_tmp_tmp - t148 * a_tmp_tmp_tmp_tmp_tmp * t66) + e_Ts_tmp *
        (eb_Ts_tmp * (12.0 * t272 - 6.0 * t93) - 2.0 * c_Ts_tmp_tmp_tmp * (-t130
          - t6))) + ((f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp *
    (((-t213 * 18.0 * t66 + 36.0 * i_Ts_tmp_tmp_tmp * (-t367 * t103 + t108)) -
      t108 * 18.0 * t11) - 54.0 * t292 * t66) + e_Ts_tmp * ((-6.0 *
    i_Ts_tmp_tmp_tmp * (-t234 - 6.0 * t91) + 6.0 * t290) + n_Ts_tmp * (t111 +
    i_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp * t91 - 2.0 * t91)) * 36.0) *
    e_Ts_tmp_tmp_tmp) + g_Ts_tmp_tmp_tmp * (36.0 * (-0.5 * (t306_tmp * t66 -
    t610 * t46) - t306_tmp * t103 * n_Ts_tmp_tmp) - (54.0 * t354 * t66 + 54.0 *
    t610 * t396) * n_Ts_tmp)) + t382 * (4.0 * ((-t25 * i_Ts_tmp_tmp_tmp * t91 *
    18.0 - t35 * x[11] * n3p) * e_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp - t341) -
    t302 * t86 * (n_Ts_tmp_tmp + -1.3333333333333333) * e_Ts_tmp_tmp_tmp)) +
                      c_Ts_tmp_tmp_tmp * ((-54.0 * t80 * t66 * d_Ts_tmp_tmp_tmp
    - t610 * t397) - t292 * 36.0 * (0.66666666666666663 * t60 - t223))) - 2.0 *
                     e_Ts_tmp * (((n_Ts_tmp * ((-t316 * e_Ts_tmp_tmp_tmp - t351)
    + i_Ts_tmp_tmp_tmp * ((-t91 * 18.0 * e_Ts_tmp_tmp_tmp - t219) + t221)) + 3.0
    * t290 * e_Ts_tmp_tmp_tmp) - i_Ts_tmp_tmp_tmp * (-10.5 * t287 *
    e_Ts_tmp_tmp_tmp - t219)) + t112 * (1.0 - n_Ts_tmp_tmp))) * f_Ts_tmp_tmp_tmp;
  t6 = ((Ts_tmp_tmp * t6 + g_Ts_tmp_tmp_tmp * (-t212_tmp * ((n_Ts_tmp * t142 -
            t140) + 0.66666666666666663 * t284_tmp) * 9.0 + 27.0 * ab_Ts_tmp *
          (t367 * p_Ts_tmp * c_Ts_tmp_tmp * (-0.88888888888888884 * n_Ts_tmp +
            0.44444444444444442) + c_Ts_tmp_tmp_tmp * ((-t80 * (n_Ts_tmp_tmp +
              -1.3333333333333333) * t142 - t142 * g_Ts_tmp) + i_Ts_tmp_tmp_tmp *
            (-t392 * t25 * 0.44444444444444442 + 0.14814814814814814 * t378_tmp *
             t357))))) + f_Ts_tmp_tmp_tmp * (((ab_Ts_tmp * ((n_Ts_tmp * (t395 *
              (t237 - 12.0) * n3p + t145 * (t301 - 36.0)) + e_Ts_tmp * (-12.0 *
              t364 * (n_Ts_tmp_tmp + -2.0) * Ts_tmp_tmp_tmp * c_Ts_tmp_tmp + 6.0
              * t69 * Ts_tmp_tmp_tmp)) + t81 * (-14.0 * t284_tmp * n_Ts_tmp_tmp
             + t142 * 9.0)) + c_Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp * (t69 * t325
             + 27.0 * t145) - 12.0 * t327 * p_Ts_tmp * c_Ts_tmp_tmp)) - 6.0 *
          t81 * (t138 - t284_tmp)) - 6.0 * t395 * n3p)) * Ts_tmp_tmp;
  t6 = (48.0 * t175 * (Ts_tmp_tmp_tmp * ((-((3.0 * g_Ts_tmp * (0.75 * t205 *
              (n_Ts_tmp_tmp + -1.3333333333333333) + t65 * 0.58333333333333337)
             - 3.0 * n_Ts_tmp * (t279 - t97)) + 3.0 * l_Ts_tmp_tmp_tmp * (t260 +
             -0.16666666666666666)) * g_Ts_tmp_tmp_tmp * ab_Ts_tmp -
           g_Ts_tmp_tmp_tmp * (t55 * (0.75 - n_Ts_tmp) + t101)) +
          f_Ts_tmp_tmp_tmp * ((ab_Ts_tmp * (t169 * 0.25 + (c_Ts_tmp_tmp_tmp *
              (t89 / 15.0 - t169) - 1.75 * t90) * c_Ts_tmp_tmp_tmp) +
            c_Ts_tmp_tmp_tmp * (t67 - 1.75 * t99)) - t168 * t54)) + Ts_tmp_tmp *
                       (((3.0 * t272 * (n_Ts_tmp_tmp + -1.3333333333333333) *
            (0.25 - n_Ts_tmp) + 3.0 * t72_tmp * (t20 * t119 + 1.1666666666666667
             * t165)) * g_Ts_tmp_tmp_tmp * ab_Ts_tmp + g_Ts_tmp_tmp_tmp *
           (t72_tmp * n3p * t100 + t272 * (0.25 - n_Ts_tmp))) + f_Ts_tmp_tmp_tmp
                        * ((ab_Ts_tmp * (e_Ts_tmp_tmp_tmp * (0.875 * (t155 *
    (t256 - 0.5714285714285714) + t110) - 1.75 * t162 * n_Ts_tmp) + t98 *
             (i_Ts_tmp_tmp_tmp + 2.0) * (i_Ts_tmp_tmp_tmp + -2.0) *
             d_Ts_tmp_tmp_tmp) + e_Ts_tmp_tmp_tmp * (0.875 *
             (0.42857142857142855 * t155 - t109) - 1.75 * n_Ts_tmp * t166)) +
           t244 * (2.25 - t150)))) + t6) + e_Ts_tmp * (6.0 * t44 *
    f_Ts_tmp_tmp_tmp * t390 * c_Ts_tmp_tmp + 4.0 * ((-6.0 * t58 * x[12] * (1.0 -
    n_Ts_tmp) - 1.5 * eb_Ts_tmp * t93) + t13) * t59_tmp);
  t11 = -t124 + h_Ts_tmp;
  t13 = 0.66666666666666663 * h_Ts_tmp;
  t21 = p_Ts_tmp * t157;
  t32 = -t124 - t38;
  t35 = 3.3333333333333335 * t319 * x[11] - t311;
  t153 = 6.0 * e_Ts_tmp;
  t44 = t76 * t380;
  t53 = -t324 + t44;
  t42 = 2.0 * t378_tmp * f_Ts_tmp_tmp_tmp * ((((-t254 * (1.5 * p_Ts_tmp *
    t43_tmp * c_Ts_tmp_tmp + t249 * t53) * f_Ts_tmp_tmp_tmp + 3.0 * t324) - t44)
    + n_Ts_tmp * t53) + ab_Ts_tmp * (((-7.0 * t324 * n_Ts_tmp_tmp + t42 * t53) -
    t324) + e_Ts_tmp * (-3.0 * t249 * t43_tmp * Ts_tmp_tmp_tmp * c_Ts_tmp_tmp +
                        t380 * x[11] * Ts_tmp_tmp_tmp))) * Ts_tmp_tmp;
  t11 = 72.0 * e_Ts_tmp * x[11] * (g_Ts_tmp_tmp_tmp * (t47_tmp *
    c_Ts_tmp_tmp_tmp * (n_Ts_tmp + -1.25) * 0.33333333333333331 + 2.0 *
    ab_Ts_tmp * (0.5 * g_Ts_tmp * (t78 * d_Ts_tmp_tmp_tmp + t121) +
                 c_Ts_tmp_tmp_tmp * ((-t129 * 0.33333333333333331 + t47_tmp *
    t229) - t105))) + f_Ts_tmp_tmp_tmp * (((ab_Ts_tmp * ((n_Ts_tmp_tmp *
    (-0.83333333333333337 * t124 - t368) + 0.33333333333333331 * t11) -
    c_Ts_tmp_tmp_tmp * (-c_Ts_tmp_tmp_tmp * ((n_Ts_tmp_tmp * t11 *
    0.33333333333333331 + t113 * t25) - t13) + t136 * (n_Ts_tmp_tmp + -2.0))) +
    0.41666666666666669 * t124) - t368) + c_Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp *
    (-t124 + t77) - t136))) * t59_tmp;
  t44 = t322 * Ts_tmp_tmp;
  t53_tmp = e_Ts_tmp * b_Ts_tmp_tmp;
  t6 += b_Ts_tmp_tmp_tmp * ((72.0 * t175 * (-Ts_tmp_tmp_tmp * (g_Ts_tmp_tmp_tmp *
    (0.66666666666666663 * t88 * n_Ts_tmp * e_Ts_tmp_tmp_tmp - 2.0 * ab_Ts_tmp *
     (-c_Ts_tmp_tmp_tmp * (t73 * i_Ts_tmp_tmp_tmp - t72_tmp * (-t242 + t51)) - (
    -0.66666666666666663 * t337 + t46 / 4.0) * e_Ts_tmp_tmp_tmp)) +
    f_Ts_tmp_tmp_tmp * ((ab_Ts_tmp * (-t75 * t131 + t72_tmp *
    ((1.3333333333333333 * t37 * (-t288 + 0.75) + 1.3333333333333333 * t305) +
     0.66666666666666663 * t308)) - t131 * (n_Ts_tmp + -0.5)) + t72_tmp *
                        ((-1.3333333333333333 * t56 - t37 / 2.0) + t318 * t56)))
    + Ts_tmp_tmp * ((-f_Ts_tmp_tmp_tmp * (((-ab_Ts_tmp * ((i_Ts_tmp_tmp_tmp *
    (i_Ts_tmp_tmp_tmp * (-t159 - 1.0833333333333333 * t124) + t119) + n_Ts_tmp *
    ((-t104 + t360) - i_Ts_tmp_tmp_tmp * (-t117 + n3p))) - t286) + t159) -
    c_Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp * (t134 + 3.0 * t124) - t136)) + t124 *
    0.58333333333333337) - a_tmp_tmp_tmp * t47_tmp * (n_Ts_tmp +
    -0.58333333333333337)) + q_Ts_tmp_tmp_tmp * (g_Ts_tmp * (t263 *
    d_Ts_tmp_tmp_tmp - 1.5 * t121) + c_Ts_tmp_tmp_tmp * ((-t105 - t293) +
    t47_tmp * (1.5416666666666667 * n_Ts_tmp_tmp - 1.5))) * ab_Ts_tmp)) + t34) +
    t15);
  t6 = (((((b_Ts_tmp_tmp_tmp * t6 + 48.0 * t41 * b_Ts_tmp_tmp * g_Ts_tmp *
            (-t102 * Ts_tmp_tmp + t120 * t106)) + b_Ts_tmp * ((Ts_tmp_tmp *
             (f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp * (-o_Ts_tmp * (-t335 * t362
    + t76 * ((-0.66666666666666663 * l_Ts_tmp_tmp + 1.8333333333333333 * t62) +
             t181 * n_Ts_tmp) * e_Ts_tmp_tmp_tmp) * 36.0 + i_Ts_tmp_tmp * (-t75 *
    t362 * g_Ts_tmp + 3.6666666666666665 * t21 * (l_Ts_tmp_tmp_tmp *
    (-0.36363636363636365 * n_Ts_tmp_tmp + 0.72727272727272729) - t68)) * 18.0)
    - 12.0 * t21 * (2.0 * t37 - t56)) + t183 * (9.0 - t86)) + 12.0 * t310 * t358
              * e_Ts_tmp_tmp_tmp) + g_Ts_tmp_tmp_tmp * (t153 * t212_tmp *
              b_Ts_tmp_tmp * (1.0 - c_Ts_tmp_tmp_tmp) * (c_Ts_tmp_tmp_tmp + 1.0)
              + ab_Ts_tmp * (-0.5 * g_Ts_tmp * (t336 * e_Ts_tmp * b_Ts_tmp_tmp -
    l_Ts_tmp * t35) + c_Ts_tmp_tmp_tmp * (e_Ts_tmp * (i_Ts_tmp_tmp_tmp *
    (-t378_tmp * (-t328 + c_Ts_tmp_tmp) - t276) - t243 * g_Ts_tmp) *
    0.16666666666666666 - t350 * t35)) * 36.0)) + f_Ts_tmp_tmp_tmp * ((ab_Ts_tmp
              * (-6.0 * e_Ts_tmp * ((t278 * (n_Ts_tmp_tmp * t32 + t16 * 4.0) -
    2.0 * t323) - t81 * (t192 + b_Ts_tmp_tmp)) - t365 * (n_Ts_tmp_tmp + -2.0) *
                 t35) - 18.0 * c_Ts_tmp_tmp_tmp * (t327 * t35 + t349 * (-t124 -
    t13))) + t153 * x[11] * t32))) + 7.0 * i_Ts_tmp_tmp * t259 * d_Ts_tmp_tmp *
          t386_tmp) + t42) - t11) * b_Ts_tmp_tmp_tmp;
  t13 = t44 * e_Ts_tmp_tmp_tmp + t391 * Ts_tmp_tmp_tmp;
  t6_tmp = 1.0 / i_Ts_tmp_tmp_tmp;
  Ts[0] = -t14;
  Ts[4] = -t177 * (Ts_tmp_tmp * (-Ts_tmp_tmp * (t345_tmp * b_Ts_tmp_tmp_tmp +
    db_Ts_tmp * (1.0 - Ts_tmp)) + t43_tmp * c_Ts_tmp_tmp_tmp * Ts_tmp_tmp_tmp) +
                   db_Ts_tmp) * t125_tmp * t147 * t141_tmp * t144 * t92 * t156;
  Ts[8] = t177 * ((Ts_tmp_tmp * (Ts_tmp_tmp * (g_Ts_tmp_tmp_tmp * (t25 * (1.0 -
    Ts_tmp) - t61) + h_Ts_tmp_tmp * (1.0 - Ts_tmp)) + t120 * t115) -
                   h_Ts_tmp_tmp) - t25 * g_Ts_tmp_tmp_tmp) * t125_tmp * t147 *
    t141_tmp * t160_tmp * t92 * t156;
  Ts[12] = 0.0;
  Ts[1] = -(((Ts_tmp_tmp * t275 * (-9.0 * ((b_Ts_tmp * t82 - 0.22222222222222221
    * e_Ts_tmp * Ts_tmp_tmp * (-b_Ts_tmp * (f_Ts_tmp_tmp_tmp *
    ((f_Ts_tmp_tmp_tmp * ((f_Ts_tmp_tmp_tmp * (e_Ts_tmp_tmp_tmp * (48.0 *
    (i_Ts_tmp_tmp_tmp * (-0.75 * t179 + t277) + t290 * (t118 + -0.125)) -
    n_Ts_tmp * (i_Ts_tmp_tmp_tmp * (t188 + t277) + t111) * 36.0) -
    c_Ts_tmp_tmp_tmp * (18.0 * (t305 + t37 * (2.6666666666666665 - t172)) + t308
                        * 9.0) * x[12]) + c_Ts_tmp_tmp_tmp * ((t317 + (72.0 *
    t184 * i_Ts_tmp_tmp_tmp + (-t326 + 18.0) * x[11] * n3p) * e_Ts_tmp_tmp_tmp *
    g_Ts_tmp_tmp_tmp) + 27.0 * a_tmp_tmp_tmp * x[12] * (-t242 +
    1.7777777777777777 * t46))) + 18.0 * g_Ts_tmp_tmp_tmp * (-x[12] * (-t337 +
    1.3333333333333333 * t46) + t93 * x[11] * (n_Ts_tmp_tmp +
    -1.3333333333333333))) + n_Ts_tmp * ((i_Ts_tmp_tmp_tmp * ((-36.0 * t179 *
    e_Ts_tmp_tmp_tmp - t219) + t221) - t351) - t290 * 18.0 * e_Ts_tmp_tmp_tmp))
     + x[12] * (c_Ts_tmp_tmp_tmp * (-18.0 * (-t56 - 1.3333333333333333 * t37) -
    27.0 * t340) + t203 * g_Ts_tmp)) + c_Ts_tmp_tmp_tmp * (t302 * t87 *
    e_Ts_tmp_tmp_tmp + t272 * (-t353 * 9.0 - t206))) + x[12] * t40)) + 4.0 * t70)
    + t85 * 24.0 * ((Ts_tmp_tmp * (Ts_tmp_tmp * ((t24 * ((i_Ts_tmp_tmp_tmp *
    (-t184 * 4.0 * i_Ts_tmp_tmp_tmp + (t22 - 1.5) * x[11] * n3p) + n_Ts_tmp *
    (t126 * x[11] - t123 * t179)) + t184) - t26 * t179) - 3.0 * h_Ts_tmp_tmp * (
    -c_Ts_tmp_tmp_tmp * (t184 - t329) + ((((t258 - i_Ts_tmp_tmp_tmp * (-t188 *
    i_Ts_tmp_tmp_tmp + t290)) - t133_tmp) + t20 * t179) - t171) *
    g_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp)) + ((-4.5 * a_tmp_tmp_tmp *
    (0.1111111111111111 * n_Ts_tmp * n3p + ((2.0 * (0.16666666666666666 - t201) *
    n3p + 1.3333333333333333 * t116 * n_Ts_tmp) - 2.0 * t117) * ab_Ts_tmp) + 4.5
    * f_Ts_tmp_tmp_tmp * (n_Ts_tmp * t226 + ab_Ts_tmp * (((n_Ts_tmp * t196 -
    t109) + t114) + t25 * (-n_Ts_tmp_tmp * 0.44444444444444442 +
    0.1111111111111111) * n3p))) - 1.5 * t109 * f_Ts_tmp_tmp_tmp * b_Ts_tmp *
    t180) * Ts_tmp_tmp_tmp * x[12]) + 0.75 * t133_tmp * t29) + 0.75 * ((t24 *
    (((n_Ts_tmp_tmp * (t104 + 1.3333333333333333 * h_Ts_tmp) + n_Ts_tmp *
       ((-n_Ts_tmp_tmp * t16 + t104) + t38)) - t124) - h_Ts_tmp) + t137) - 3.0 *
    h_Ts_tmp_tmp * (-t143 * c_Ts_tmp_tmp_tmp + (i_Ts_tmp_tmp_tmp *
    (-0.66666666666666663 * t25 * n3p + t128) - t127) * g_Ts_tmp_tmp_tmp *
                    f_Ts_tmp_tmp_tmp)) * x[11] * t59_tmp)) + t48 *
              ((-5.1428571428571432 * t53_tmp * t135_tmp * (e_Ts_tmp_tmp_tmp *
    t271 * Ts_tmp_tmp + t259) - t376 * (t120 * t391 + t44)) + t53_tmp *
               2.5714285714285716 * t390 * e_Ts_tmp_tmp_tmp * b_Ts_tmp)) + t6) *
            t176 * t163 * t156 * t178 * (1.0 / (((((b_Ts_tmp * (t50 - 2.0 * t271)
    + n_Ts_tmp) + t389) - 1.0) - 2.0 * Ts_tmp_tmp * (t120 * t273 + t79 * t13)) -
              2.0 * t83)));
  t14_tmp = b_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  b_t14_tmp = i_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp;
  Ts[5] = t177 * (Ts_tmp_tmp_tmp * (db_Ts_tmp * e_Ts_tmp_tmp_tmp + t14_tmp) +
                  b_t14_tmp * Ts_tmp_tmp) * t125_tmp * t147 * t141_tmp * t144 *
    t92 * t174_tmp;
  Ts[9] = -t177 * (t115 * Ts_tmp_tmp - Ts_tmp_tmp_tmp * (g_Ts_tmp_tmp_tmp * (t25
    * e_Ts_tmp_tmp_tmp - t725) + h_Ts_tmp_tmp * e_Ts_tmp_tmp_tmp)) * t125_tmp *
    t147 * t141_tmp * t160_tmp * t92 * t174_tmp;
  Ts[13] = 0.0;
  Ts[2] = a_tmp_tmp * (t79 * Ts_tmp_tmp + t13) * (1.0 / d_Ts_tmp_tmp);
  Ts[6] = 0.0;
  Ts[10] = 0.0;
  Ts[14] = 0.0;
  Ts[3] = 0.0;
  Ts[7] = 0.0;
  Ts[11] = -t160_tmp * g_Ts_tmp_tmp_tmp * t6_tmp;
  Ts[15] = -1.0 / M[6] * f_Ts_tmp_tmp_tmp * t6_tmp;
  t10 = o_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t12 = -t10 + a_tmp_tmp_tmp;
  t17_tmp = g_Ts_tmp * b_Ts_tmp_tmp;
  t18 = -n3pp + t17_tmp;
  t20 = m_Ts_tmp_tmp * x[11];
  t21 = t20 * e_Ts_tmp_tmp_tmp;
  t22 = t21 * g_Ts_tmp;
  t23 = t18 / 2.0;
  t24 = t23 * c_Ts_tmp_tmp_tmp;
  t25 = t24 * d_Ts_tmp_tmp_tmp - t22;
  t28 = 2.0 * t25;
  t29 = -t18 * a_tmp_tmp_tmp_tmp_tmp - t28 * f_Ts_tmp_tmp_tmp;
  t31 = h_Ts_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t32 = t31 + a_tmp_tmp_tmp_tmp_tmp;
  t33 = e_Ts_tmp_tmp_tmp * t32;
  t34 = t33 * n3p;
  t35 = b_Ts_tmp_tmp_tmp * t32;
  t36 = t35 * n3p;
  t38 = j_Ts_tmp_tmp_tmp * g_Ts_tmp;
  t40 = f_Ts_tmp_tmp * e_Ts_tmp_tmp_tmp;
  t41 = t40 - t38;
  t43 = t69_tmp * c_Ts_tmp_tmp_tmp;
  t45 = l_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp;
  t46 = t45 + t43;
  t47 = g_Ts_tmp_tmp_tmp * t46;
  t48_tmp = f_Ts_tmp_tmp_tmp * t41;
  eb_Ts_tmp = t48_tmp * d_Ts_tmp_tmp_tmp;
  t49 = eb_Ts_tmp + t47;
  t52 = Ts_tmp * Ts_tmp;
  t53 = b_Ts_tmp_tmp_tmp * Ts_tmp;
  t54 = -Ts_tmp + bb_Ts_tmp;
  t58 = t725 * f_Ts_tmp_tmp_tmp;
  b_t59_tmp = t12 * e_Ts_tmp_tmp_tmp;
  t60 = b_t59_tmp * 6.0;
  t61 = Ts_tmp * 3.0;
  t62 = t69_tmp * b_Ts_tmp_tmp_tmp;
  t63 = t62 * x[11];
  t66 = n3pp / 2.0;
  t67 = t66 - t17_tmp;
  t68 = l_Ts_tmp_tmp_tmp * x[11];
  t69 = t68 * d_Ts_tmp_tmp_tmp;
  t70 = t67 * i_Ts_tmp_tmp_tmp;
  t71 = t69 + t70;
  t72 = f_Ts_tmp_tmp * g_Ts_tmp_tmp_tmp;
  t73 = t72 * x[11];
  t74 = f_Ts_tmp_tmp_tmp * t71 - t73;
  t76 = h_Ts_tmp * x[11];
  t77 = t67 * d_Ts_tmp_tmp_tmp;
  t78 = t77 * h_Ts_tmp_tmp_tmp - t76;
  t79 = a_tmp_tmp_tmp * t67;
  t80 = f_Ts_tmp_tmp_tmp * t78 - t79;
  t81 = t69_tmp * t35;
  t82 = t43 * e_Ts_tmp_tmp_tmp;
  t83 = t82 + l_Ts_tmp_tmp_tmp;
  t85 = 1.5 * x[11];
  t86 = t85 * i_Ts_tmp_tmp_tmp;
  t87 = t86 * g_Ts_tmp;
  t88 = t83 * d_Ts_tmp_tmp_tmp;
  t89 = -t88 + t87;
  t90 = t38 * e_Ts_tmp_tmp_tmp;
  t91 = f_Ts_tmp_tmp - t90;
  p_Ts_tmp = g_Ts_tmp_tmp_tmp * t91;
  t93 = f_Ts_tmp_tmp_tmp * t89 + p_Ts_tmp;
  t94_tmp = t12 * x[11];
  t95_tmp = t94_tmp * g_Ts_tmp;
  t96 = bb_Ts_tmp * 6.0;
  t97 = e_Ts_tmp_tmp_tmp * t80;
  t98 = h_Ts_tmp / 2.0;
  t100 = g_Ts_tmp_tmp * g_Ts_tmp;
  t101 = t100 * d_Ts_tmp_tmp_tmp;
  t102 = -t101 - t98;
  t104 = 1.3333333333333333 * t102;
  t105 = a_tmp_tmp_tmp * 1.3333333333333333 * x[11] * g_Ts_tmp;
  t106 = -t104 * f_Ts_tmp_tmp_tmp - t105;
  t107 = -3.0 * t106;
  t108 = 1.3333333333333333 * x[11];
  t109 = t108 * i_Ts_tmp_tmp_tmp;
  t110 = t109 * g_Ts_tmp;
  t111 = 0.66666666666666663 * l_Ts_tmp_tmp_tmp;
  t112 = t111 * d_Ts_tmp_tmp_tmp - t110;
  t114 = 0.66666666666666663 * t40;
  t115 = b_Ts_tmp_tmp_tmp * t112;
  t116 = -t115 * x[12];
  t413 = 0.66666666666666663 * t72 * b_Ts_tmp_tmp_tmp;
  t118 = t413 * x[12] + t116 * f_Ts_tmp_tmp_tmp;
  t11 = c_Ts_tmp_tmp + k_Ts_tmp_tmp_tmp;
  t123 = n3pp * 0.33333333333333331 - t11 * g_Ts_tmp;
  t124 = -0.66666666666666663 * j_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * n3p + t123
    * c_Ts_tmp_tmp_tmp;
  t22 = 1.3333333333333333 * t22 + t124 * d_Ts_tmp_tmp_tmp;
  t6 = t114 * x[12];
  t123 = t6 + t123 * h_Ts_tmp_tmp_tmp;
  o_Ts_tmp = g_Ts_tmp_tmp_tmp * t123;
  t126 = t22 * f_Ts_tmp_tmp_tmp + o_Ts_tmp;
  t127 = t40 / 2.0;
  t128 = -t127 + t38;
  t129 = 1.3333333333333333 * t128;
  t131 = -t45 / 2.0 - t43;
  t132 = 1.3333333333333333 * t131;
  t133 = t132 * g_Ts_tmp_tmp_tmp;
  t134 = -t129 * d_Ts_tmp_tmp_tmp;
  t135 = -t134 * f_Ts_tmp_tmp_tmp + t133;
  t136 = x[12] * t107;
  t137 = t136 * b_Ts_tmp_tmp_tmp;
  t138 = x[11] * t135;
  t139 = t83 * g_Ts_tmp_tmp_tmp;
  t140 = t91 * d_Ts_tmp_tmp_tmp;
  t141 = t140 * f_Ts_tmp_tmp_tmp + t139;
  t145 = m_Ts_tmp_tmp_tmp * 4.0;
  t146 = t145 * x[11] * M[2];
  t147 = t146 * Ts_tmp_tmp_tmp * M[0];
  t148 = t147 - t284_tmp;
  t149 = c_Ts_tmp_tmp_tmp * t148;
  t151 = e_Ts_tmp_tmp * Ts_tmp_tmp_tmp;
  t65 = M[0] * t151;
  t152 = t65 * i_Ts_tmp_tmp_tmp + t149 * d_Ts_tmp_tmp_tmp;
  t153_tmp = t152 * f_Ts_tmp_tmp_tmp;
  t154 = a_tmp_tmp_tmp_tmp_tmp * t148;
  t155 = m_Ts_tmp_tmp * f_Ts_tmp_tmp_tmp;
  t156 = t155 * g_Ts_tmp;
  t157 = t156 * b_Ts_tmp_tmp_tmp;
  t158 = t141 + t157;
  t159 = Ts_tmp_tmp_tmp * M[0] * M[2];
  t160 = t159 * x[12];
  t161 = t160 * b_Ts_tmp_tmp_tmp;
  t162 = 2.0 * t161 * t158;
  p_Ts_tmp_tmp_tmp = t153_tmp + t154;
  t163 = -g_Ts_tmp * p_Ts_tmp_tmp_tmp - t162;
  t164 = t62 * t12;
  t165 = t160 * t35;
  t166 = t164 * b_Ts_tmp_tmp_tmp;
  t167 = -e_Ts_tmp_tmp_tmp * t141 + t166;
  t342 = -M[0] * e_Ts_tmp_tmp_tmp * t151;
  t168 = -4.0 * g_Ts_tmp * (t342 * t58 + x[11] * t165) - 2.0 * t160 * t167;
  t169 = b_t59_tmp * t69_tmp;
  t170 = t160 * t33;
  t171 = Ts_tmp_tmp_tmp * t164;
  t173 = t378_tmp * f_Ts_tmp_tmp_tmp;
  b_t174_tmp = g_Ts_tmp * t32;
  t177 = Ts_tmp_tmp * t59_tmp;
  t180 = e_Ts_tmp * b_Ts_tmp;
  t182 = t180 * 3.0;
  t184_tmp = b_t59_tmp + t58;
  t186_tmp = Ts_tmp_tmp_tmp * t32;
  t188 = t20 * f_Ts_tmp_tmp_tmp;
  t189 = x[11] * t36;
  t271 = t49 * e_Ts_tmp_tmp_tmp;
  t191 = (-t169 * t61 * x[11] - b_Ts_tmp_tmp_tmp * ((g_Ts_tmp * t188 * Ts_tmp -
            e_Ts_tmp_tmp_tmp * t29) + t189)) + t271 * x[11];
  t80 = (x[11] * (t81 - t95_tmp) + Ts_tmp * t80) * b_Ts_tmp_tmp_tmp;
  t192 = t93 * e_Ts_tmp_tmp_tmp;
  t193 = t97 * 2.0;
  t194 = e_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp;
  t195 = (-t192 * x[11] - t80) + t194 * (-b_Ts_tmp_tmp_tmp * 3.0 * t74 + t193);
  t196 = t118 * Ts_tmp;
  t189 *= 0.66666666666666663;
  t136 = (b_Ts_tmp_tmp_tmp * (-t126 * e_Ts_tmp_tmp_tmp * 2.0 + t189) +
          e_Ts_tmp_tmp_tmp * (t136 * Ts_tmp + t138)) + t196;
  t197 = Ts_tmp_tmp_tmp * t195;
  t198 = e_Ts_tmp * t135_tmp;
  t199 = e_Ts_tmp_tmp_tmp * t163 - b_Ts_tmp_tmp_tmp * t168;
  t200 = Ts_tmp_tmp * t199;
  t201 = t194 * b_t174_tmp * 4.0 * c_Ts_tmp_tmp;
  t202 = (2.0 * t198 * (t191 * Ts_tmp_tmp + t197) + t200) + e_Ts_tmp * (t136 *
    b_Ts_tmp * 3.0 - t201);
  t204 = t43_tmp * f_Ts_tmp_tmp_tmp;
  t205_tmp = b_Ts_tmp_tmp_tmp * t12;
  t205 = t205_tmp - t204;
  t206 = -t29 / 2.0;
  t209 = t63 * 3.0;
  t190 = b_Ts_tmp_tmp_tmp * (t156 * Ts_tmp + t36);
  t210 = -t194 * (t12 * t209 + t206 * 2.0) - x[11] * (t190 - t271);
  t211 = x[11] * t93;
  t212 = b_Ts_tmp_tmp_tmp * t74;
  t80 = (-t211 * e_Ts_tmp_tmp_tmp - t80) + t194 * (-t212 * 3.0 + t193);
  t193 = -x[11] * t135;
  t106 *= b_Ts_tmp_tmp_tmp;
  t213 = t106 * x[12];
  t189 = (-t193 * e_Ts_tmp_tmp_tmp + b_Ts_tmp_tmp_tmp * (-e_Ts_tmp_tmp_tmp *
           (t126 * 2.0 + t213 * 3.0) + t189)) + t196;
  t196 = Ts_tmp_tmp_tmp * t80;
  t200 = (-2.0 * t198 * (t210 * Ts_tmp_tmp + t196) - t200) + e_Ts_tmp *
    (-b_Ts_tmp * t189 * 3.0 + t201);
  t201 = b_t174_tmp * b_Ts_tmp_tmp;
  x_Ts_tmp = t63 * t12;
  t206 = b_Ts_tmp_tmp_tmp * (-x[11] * t49 + b_Ts_tmp_tmp_tmp * (x_Ts_tmp + t206))
    - t201;
  db_Ts_tmp = t17_tmp * b_t59_tmp;
  t211 = b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (-t97 + t212) + t211) +
    db_Ts_tmp;
  t193 = 0.66666666666666663 * t201 + (b_Ts_tmp_tmp_tmp * (t213 + t126) + t193) *
    b_Ts_tmp_tmp_tmp;
  t212 = t173 * Ts_tmp_tmp_tmp;
  t213 = t212 * d_Ts_tmp_tmp;
  t214 = e_Ts_tmp_tmp * 2.0 * M[0];
  t215 = Ts_tmp_tmp_tmp * t211;
  t216 = ((-2.0 * t198 * (t206 * Ts_tmp_tmp + t215) + g_Ts_tmp * (-t214 * t32 *
            Ts_tmp - t213)) + a_tmp_tmp * t163) - t182 * t193;
  t217 = -3.0 * t200;
  t218 = -3.0 * t216;
  t187_tmp = t184_tmp * Ts_tmp_tmp + t186_tmp;
  t187 = 1.0 / t187_tmp;
  t224 = t174_tmp * t174_tmp;
  t225 = t156_tmp * t174_tmp;
  t226 = t147_tmp * t147_tmp;
  t227 = t226 * t226;
  t228 = t147_tmp * t227;
  t229 = t147_tmp * t226;
  t230 = t205 * t218;
  t29 = (t187 * (-t184_tmp * t216 + t205 * (-t202 + t200)) + t156_tmp * ((((M[0]
             * 4.0 * e_Ts_tmp_tmp * b_t174_tmp * t54 + 2.0 * Ts_tmp_tmp *
             (e_Ts_tmp_tmp_tmp * t168 + t180 * (((t63 * (e_Ts_tmp_tmp_tmp * (t60
    + 5.0 * t58) - t61 * t12) - x[11] * (-2.0 * e_Ts_tmp_tmp_tmp * t36 +
    b_Ts_tmp_tmp_tmp * (-t34 - t49))) - t29 * t54) * Ts_tmp_tmp + Ts_tmp_tmp_tmp
    * ((b_Ts_tmp_tmp_tmp * (t96 - t61) * t74 + t97 * (-2.0 * bb_Ts_tmp + 7.0 *
    Ts_tmp)) - x[11] * (e_Ts_tmp_tmp_tmp * (t95_tmp - 2.0 * t81) +
                        b_Ts_tmp_tmp_tmp * (-t33 * t69_tmp + t93)))))) +
            a_tmp_tmp * ((t163 - 4.0 * (t47_tmp * t170 + (-c_Ts_tmp_tmp * t173 *
    t54 * Ts_tmp_tmp_tmp + m_Ts_tmp_tmp_tmp * t171) * M[0] * M[2])) - 2.0 * t161
             * (t169 + t141))) + t182 * ((2.0 * (-t126 * Ts_tmp +
              e_Ts_tmp_tmp_tmp * (-t118 * b_Ts_tmp_tmp_tmp + e_Ts_tmp_tmp_tmp *
    (t126 - t137))) + ((-t118 * e_Ts_tmp_tmp_tmp * 2.0 + b_Ts_tmp_tmp_tmp *
                        ((t112 * m_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - t6 *
    g_Ts_tmp_tmp_tmp) + t137)) + t138) * b_Ts_tmp_tmp_tmp) - 0.66666666666666663
            * x[11] * (e_Ts_tmp_tmp_tmp * 2.0 * t36 + b_Ts_tmp_tmp_tmp * t34)))
          + t218)) + (-t187 * t230 + t217 * t156_tmp) * t147_tmp *
    e_Ts_tmp_tmp_tmp;
  t34 = t229 * t174_tmp;
  t74 = t34 * t187;
  t97 = t74 * t141_tmp * t125_tmp;
  t112 = t216 * t187;
  t118 = t156_tmp * t202;
  t126 = t187 * t125_tmp * t141_tmp;
  t137 = t126 * t174_tmp;
  t138 = t137 * t227 * e_Ts_tmp_tmp_tmp;
  t168 = t187 * t187;
  t231 = t187 * t168;
  t232 = 4.0 * t218 * t174_tmp;
  t233 = t168 * 2.0 * t216;
  t236 = t345_tmp * fb_Ts_tmp;
  t237 = t236 * 4.0;
  t238 = m_Ts_tmp_tmp + t237;
  t240 = t610 * Ts_tmp_tmp;
  t241 = t240 * t238;
  t242 = t241 * f_Ts_tmp_tmp_tmp;
  t243 = t146 * a_tmp_tmp_tmp_tmp_tmp * Ts_tmp_tmp * M[0];
  t239 = t610 * a_tmp_tmp;
  t158 = -g_Ts_tmp * (t242 + t243) - 2.0 * t239 * t158;
  t244 = e_Ts_tmp_tmp * t58 * Ts_tmp_tmp * M[0];
  t245 = t159 * Ts_tmp_tmp;
  t167 = -t199 * Ts_tmp_tmp_tmp + Ts_tmp_tmp * (e_Ts_tmp_tmp_tmp * t158 -
    b_Ts_tmp_tmp_tmp * (-4.0 * g_Ts_tmp * (x[11] * t240 * t35 - e_Ts_tmp_tmp_tmp
    * t244) - 2.0 * t240 * t167));
  t246 = 2.0 * Ts_tmp_tmp;
  t248 = f_Ts_tmp_tmp_tmp * t386_tmp;
  t249 = t248 * i_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp;
  t158 *= b_Ts_tmp_tmp_tmp;
  t250 = 8.0 * t206;
  t251 = ((-6.0 * t245 * (t215 * Ts_tmp_tmp + t193) + Ts_tmp_tmp * (t249 - t158))
          + b_Ts_tmp_tmp_tmp * t163 * Ts_tmp_tmp_tmp) + t198 * (t211 * t246 -
    Ts_tmp_tmp_tmp * t250);
  t252_tmp = Ts_tmp_tmp * t32;
  t253_tmp = t184_tmp * Ts_tmp_tmp_tmp - t252_tmp;
  t254 = t156_tmp * Ts_tmp_tmp_tmp;
  t255 = t112 * t253_tmp;
  t256 = t126 * t225;
  t257 = t256 * t227 * e_Ts_tmp_tmp_tmp;
  t258 = t34 * 2.0;
  t259 = t258 * t216 * t125_tmp * t231 * t141_tmp;
  t264 = t572 + gb_Ts_tmp * d_Ts_tmp_tmp_tmp;
  t265 = a_tmp_tmp_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t266 = t265 + h_Ts_tmp_tmp;
  t267 = t23 * o_Ts_tmp_tmp_tmp;
  t222 = -t25 * g_Ts_tmp_tmp_tmp + t267;
  t269 = a_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t270 = t269 - o_Ts_tmp_tmp_tmp;
  t271_tmp = b_Ts_tmp_tmp_tmp * n3p;
  t272 = t271_tmp * t270;
  t274_tmp = g_Ts_tmp_tmp_tmp * t41;
  t275_tmp = -t274_tmp * d_Ts_tmp_tmp_tmp + f_Ts_tmp_tmp_tmp * t46;
  t276 = m_Ts_tmp_tmp * g_Ts_tmp_tmp_tmp;
  t277 = t276 * g_Ts_tmp;
  t278 = h_Ts_tmp_tmp * x[11];
  t708 = g_Ts_tmp_tmp_tmp * t78 + h_Ts_tmp_tmp * t67;
  t282 = f_Ts_tmp_tmp_tmp * t91;
  t283 = -g_Ts_tmp_tmp_tmp * t89 + t282;
  t284 = x[11] * t266;
  t286 = x[11] * t283;
  t287_tmp = b_Ts_tmp_tmp_tmp * (g_Ts_tmp_tmp_tmp * t71 + t278 * n3p);
  t288_tmp = e_Ts_tmp_tmp_tmp * t708;
  t290 = t271_tmp * h_Ts_tmp_tmp;
  t292 = f_Ts_tmp_tmp_tmp * t123;
  t293 = -t22 * g_Ts_tmp_tmp_tmp + t292;
  t294 = t132 * f_Ts_tmp_tmp_tmp;
  t295 = t129 * d_Ts_tmp_tmp_tmp;
  t296 = t295 * g_Ts_tmp_tmp_tmp - t294;
  t297 = x[11] * t296;
  t298_tmp = t104 * g_Ts_tmp_tmp_tmp - t108 * h_Ts_tmp_tmp * g_Ts_tmp;
  b_t298_tmp = t298_tmp * b_Ts_tmp_tmp_tmp;
  t299 = b_t298_tmp * x[12];
  t300 = 0.66666666666666663 * x[11] * t272;
  t301 = t83 * f_Ts_tmp_tmp_tmp;
  t303 = p_Ts_tmp * d_Ts_tmp_tmp_tmp;
  t304 = t301 - t303;
  w_Ts_tmp = t152 * g_Ts_tmp_tmp_tmp;
  t306 = o_Ts_tmp_tmp_tmp * t148;
  t307 = t277 * b_Ts_tmp_tmp_tmp;
  t308 = t304 - t307;
  t309 = g_Ts_tmp * (-t306 + w_Ts_tmp) - 2.0 * t161 * t308;
  t310 = t62 * t266;
  t311 = t310 * b_Ts_tmp_tmp_tmp;
  t312 = 4.0 * g_Ts_tmp * (t342 * g_Ts_tmp_tmp_tmp * t725 + x[11] * t161 * t270);
  t313 = -t270;
  t314 = t194 * 4.0;
  t315 = t314 * g_Ts_tmp;
  t316 = t315 * c_Ts_tmp_tmp;
  t317 = t316 * -t270;
  t318 = t63 * t266;
  t319 = t17_tmp * -t270;
  t320 = b_Ts_tmp_tmp_tmp * (-x[11] * t275_tmp + b_Ts_tmp_tmp_tmp * (t222 + t318))
    - t319;
  t321_tmp = e_Ts_tmp_tmp_tmp * t266;
  t322 = t321_tmp * t17_tmp;
  t323 = b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (t287_tmp - t288_tmp) - t286) -
    t322;
  t324 = 0.66666666666666663 * t319;
  t325 = (b_Ts_tmp_tmp_tmp * (t299 + t293) + t297) * b_Ts_tmp_tmp_tmp + t324;
  t326 = t378_tmp * g_Ts_tmp_tmp_tmp;
  t327 = t326 * Ts_tmp_tmp_tmp * d_Ts_tmp_tmp;
  t328 = g_Ts_tmp * (-t214 * -t270 * Ts_tmp + t327);
  t329 = Ts_tmp_tmp_tmp * t323;
  t330 = ((-a_tmp_tmp * t309 - 2.0 * t198 * (-t320 * Ts_tmp_tmp + t329)) - t328)
    + t182 * t325;
  t331 = t725 * g_Ts_tmp_tmp_tmp;
  t332 = t321_tmp - t331;
  t333 = Ts_tmp_tmp_tmp * -t270;
  t334 = t332 * Ts_tmp_tmp + t333;
  t335 = t43_tmp * g_Ts_tmp_tmp_tmp;
  t336_tmp = b_Ts_tmp_tmp_tmp * t266;
  b_t336_tmp = t336_tmp + t335;
  t336 = t216 * b_t336_tmp;
  t337 = t112 * t334 + t330;
  t338 = t259 * t334 * t205;
  t340 = t345_tmp * t69_tmp;
  t24 = x[11] * t340 + t24 * i_Ts_tmp_tmp_tmp;
  t341 = t69_tmp * d_Ts_tmp_tmp_tmp;
  t343 = t194 * f_Ts_tmp_tmp_tmp;
  t68 *= i_Ts_tmp_tmp_tmp;
  t345 = l_Ts_tmp_tmp * x[11];
  t70 = t70 * h_Ts_tmp_tmp_tmp + t345;
  t346 = t85 * d_Ts_tmp_tmp_tmp;
  t347 = t346 * g_Ts_tmp;
  t181 = -i_Ts_tmp_tmp_tmp * t83 - t347;
  t350 = x[11] * t181;
  t351 = t725 * x[11];
  t352 = f_Ts_tmp_tmp_tmp * ((t350 * e_Ts_tmp_tmp_tmp + t53 * t70) + t351 *
    (b_Ts_tmp_tmp_tmp * jb_Ts_tmp + g_Ts_tmp_tmp) * g_Ts_tmp);
  t175 = e_Ts_tmp_tmp_tmp * t70;
  t354 = t175 * 2.0;
  t355 = b_Ts_tmp_tmp_tmp * (-t67 * d_Ts_tmp_tmp_tmp + t68);
  t356 = l_Ts_tmp_tmp / 2.0;
  t357 = t100 * i_Ts_tmp_tmp_tmp;
  t358 = -t357 + t356;
  t359 = 1.3333333333333333 * t358;
  t360 = t108 * d_Ts_tmp_tmp_tmp;
  t362 = -t108 * t340 + t124 * i_Ts_tmp_tmp_tmp;
  t363 = -kb_Ts_tmp * t359;
  t364 = f_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp;
  t149 = t65 * d_Ts_tmp_tmp_tmp - t149 * i_Ts_tmp_tmp_tmp;
  t365 = t62 * d_Ts_tmp_tmp_tmp;
  t366_tmp = t91 * i_Ts_tmp_tmp_tmp;
  t367 = -t366_tmp + t365;
  t368 = t161 * f_Ts_tmp_tmp_tmp;
  t369 = g_Ts_tmp * t149;
  t370 = 2.0 * t367 * t368 + t369 * f_Ts_tmp_tmp_tmp;
  t371 = m_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t372 = fb_Ts_tmp * i_Ts_tmp_tmp_tmp;
  t373 = t372 + t371;
  t374 = t38 * Ts_tmp;
  t375 = t159 * t155;
  t376_tmp = g_Ts_tmp * b_Ts_tmp_tmp_tmp;
  t376 = (ib_Ts_tmp * (i_Ts_tmp_tmp_tmp * (e_Ts_tmp_tmp_tmp * t41 - f_Ts_tmp_tmp
            * Ts_tmp) + t341 * t53) + t343 * (t376_tmp * t20 * 3.0 *
           h_Ts_tmp_tmp_tmp - t24 * 2.0)) * Ts_tmp_tmp;
  t377 = Ts_tmp_tmp * (e_Ts_tmp_tmp_tmp * t370 - b_Ts_tmp_tmp_tmp * (-4.0 * t159
    * t373 * f_Ts_tmp_tmp_tmp * t62 + 2.0 * t375 * (e_Ts_tmp_tmp_tmp * t91 +
    t374)));
  t111 = e_Ts_tmp * (-t725 * h_Ts_tmp_tmp * 4.0 * g_Ts_tmp * c_Ts_tmp_tmp *
                     e_Ts_tmp_tmp_tmp + 3.0 * (-f_Ts_tmp_tmp_tmp * (Ts_tmp *
    kb_Ts_tmp * (t111 * i_Ts_tmp_tmp_tmp + g_Ts_tmp * t360) + t43_tmp * -t129 *
    x[11]) + t364 * (e_Ts_tmp_tmp_tmp * (-2.0 * t362 - t363 * 3.0) +
                     0.66666666666666663 * t351 * f_Ts_tmp_tmp)) * b_Ts_tmp);
  t378 = t374 + t41;
  t379 = t378_tmp * b_Ts_tmp_tmp;
  t380 = t379 * c_Ts_tmp_tmp_tmp;
  t223 = -t24 * Ts_tmp;
  t381 = (t223 + t351 * t378) + t380;
  t382 = f_Ts_tmp_tmp_tmp * t381;
  t383 = t379 * e_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp;
  t384 = b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (-t355 + t175) - t350) + t383;
  t385 = f_Ts_tmp_tmp_tmp * t384;
  t363 = b_Ts_tmp_tmp_tmp * (t363 + t362) + -t129 * i_Ts_tmp_tmp_tmp * x[11];
  t386 = 0.66666666666666663 * t379 * h_Ts_tmp_tmp + t364 * t363;
  t387 = t284_tmp * Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t388 = -t214 * i_Ts_tmp_tmp_tmp * Ts_tmp * c_Ts_tmp_tmp_tmp + t387;
  t389 = g_Ts_tmp * t388 * f_Ts_tmp_tmp_tmp + a_tmp_tmp * t370;
  t390 = t382 * Ts_tmp_tmp;
  t391 = Ts_tmp_tmp_tmp * t385;
  t392 = t182 * t386;
  t393 = (-2.0 * t198 * (t391 + t390) - t389) + t392;
  t394 = t43_tmp * h_Ts_tmp_tmp_tmp;
  t396_tmp = t14_tmp + t394;
  t397 = f_Ts_tmp_tmp_tmp * t396_tmp;
  t398 = h_Ts_tmp_tmp * Ts_tmp_tmp_tmp;
  t399 = t397 * Ts_tmp_tmp - t398 * i_Ts_tmp_tmp_tmp;
  t400 = t725 * h_Ts_tmp_tmp_tmp;
  t401 = -t400 + t345_tmp;
  t402 = f_Ts_tmp_tmp_tmp * t401;
  t403 = t216 * t402;
  t404 = -t112 * t399 + t393;
  t405 = t259 * t399 * t205;
  t262 = t18 * t12;
  t408_tmp = t46 * d_Ts_tmp_tmp_tmp;
  t410 = f_Ts_tmp_tmp_tmp * t408_tmp - t274_tmp;
  t411 = b_Ts_tmp_tmp_tmp * t262;
  t65 = -t271_tmp * t12 * x[11];
  t413_tmp = x[11] * t32;
  t416 = t413_tmp * n3p;
  t417 = t67 * t32;
  t418 = t91 * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp;
  t419 = t83 * g_Ts_tmp_tmp_tmp + t418;
  t420_tmp = b_t174_tmp * x[11];
  t421 = (x[11] * (t164 + t420_tmp) + t417 * Ts_tmp) * b_Ts_tmp_tmp_tmp;
  t422 = x[11] * t419;
  t417 *= e_Ts_tmp_tmp_tmp;
  t423 = t417 * 2.0;
  t424 = b_Ts_tmp_tmp_tmp * t416;
  t425 = t413_tmp * g_Ts_tmp;
  t426 = -t123 * d_Ts_tmp_tmp_tmp;
  t427 = t124 * g_Ts_tmp_tmp_tmp + f_Ts_tmp_tmp_tmp * t426;
  t207 = t132 * d_Ts_tmp_tmp_tmp;
  t430 = -t128 * n_Ts_tmp_tmp_tmp + f_Ts_tmp_tmp_tmp * t207;
  t432 = t430 * x[11];
  t407 = 0.66666666666666663 * b_Ts_tmp_tmp_tmp * (kb_Ts_tmp * t36 + t65);
  t433 = f_Ts_tmp_tmp_tmp * t88 - p_Ts_tmp;
  t434 = t148 * t12;
  t435 = t161 * 2.0;
  t436 = -g_Ts_tmp * t434 + t433 * t435;
  t437 = 4.0 * g_Ts_tmp;
  t438 = Ts_tmp_tmp * (e_Ts_tmp_tmp_tmp * t436 - b_Ts_tmp_tmp_tmp * (2.0 * t160 *
    (-e_Ts_tmp_tmp_tmp * t433 + b_Ts_tmp_tmp_tmp * t81) - t437 * t161 * t94_tmp));
  t316 *= t12;
  t439 = t69_tmp * Ts_tmp;
  t440 = t439 * t32;
  t262 = t262 * Ts_tmp / 2.0 + x[11] * (b_Ts_tmp_tmp_tmp * (-t440 + t410) -
    t95_tmp);
  t201 = b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (t417 - t424) + t422) + t201 *
    e_Ts_tmp_tmp_tmp;
  t417 = 0.66666666666666663 * t17_tmp;
  t443 = (1.3333333333333333 * t425 * x[12] * t53 + t417 * t12) +
    b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * t427 + t432);
  t444 = Ts_tmp_tmp_tmp * t201;
  t446_tmp = t133_tmp * t12;
  t448 = (e_Ts_tmp * t443 * 3.0 * Ts_tmp_tmp - b_Ts_tmp_tmp_tmp * t436) *
    Ts_tmp_tmp;
  t234 = t135_tmp * (-t262 * Ts_tmp_tmp + t444) - t446_tmp * Ts_tmp;
  t449 = -2.0 * e_Ts_tmp * t234 + t448;
  t450 = Ts_tmp_tmp_tmp * t12;
  t452_tmp = e_Ts_tmp_tmp_tmp * t252_tmp - t450;
  t453 = t112 * t32;
  t137 *= t226;
  t454 = -t112 * t452_tmp + t449;
  t455 = t259 * t452_tmp * t205;
  t42 = Ts_tmp_tmp * ((-e_Ts_tmp_tmp_tmp * (x[11] * t410 + t411) + t65 *
                       b_Ts_tmp_tmp_tmp) + t413_tmp * t61 * t69_tmp *
                      e_Ts_tmp_tmp_tmp);
  t13 = b_Ts_tmp_tmp_tmp * (-2.0 * t427 - kb_Ts_tmp * t425 * 4.0);
  t422 = (3.0 * t257 * t454 - t137 * (t147_tmp * (t156_tmp * (((t200 * t452_tmp *
    t187 - 2.0 * t198 * (Ts_tmp_tmp_tmp * ((t422 * e_Ts_tmp_tmp_tmp - t421) +
    t194 * (-t424 * 3.0 + t423)) + t42)) - t438) - e_Ts_tmp * (3.0 *
              (e_Ts_tmp_tmp_tmp * (t13 - t432) - t407) * b_Ts_tmp - t316)) +
            t205 * t449 * t187) + t453)) + t455;
  t424 = fb_Ts_tmp * d_Ts_tmp_tmp_tmp;
  t432 = m_Ts_tmp_tmp * e_Ts_tmp_tmp_tmp;
  t65 = -t432 + t424;
  t27 = g_Ts_tmp * t65;
  t458 = a_tmp_tmp_tmp_tmp_tmp * x[11];
  t199 = f_Ts_tmp_tmp_tmp * t27 + t458 * g_Ts_tmp;
  t462 = l_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t463 = 2.0 * x[11];
  t464 = t463 * t378_tmp;
  t465 = -t464 + t462;
  t395 = -f_Ts_tmp_tmp_tmp * t465 + t72;
  t467 = 2.0 * t102;
  t468 = a_tmp_tmp_tmp * g_Ts_tmp * t463 + f_Ts_tmp_tmp_tmp * t467;
  t469 = (t468 * Ts_tmp + t81) * b_Ts_tmp_tmp_tmp;
  t470 = (-f_Ts_tmp_tmp_tmp * t87 + t395 * t61) * e_Ts_tmp_tmp_tmp;
  t471 = 2.0 * b_Ts_tmp_tmp_tmp * (t468 * bb_Ts_tmp + t95_tmp);
  t472_tmp = t12 * g_Ts_tmp;
  t6 = ((b_Ts_tmp_tmp_tmp * (1.3333333333333333 * t157 + t145 * t472_tmp) +
         0.66666666666666663 * t36) + 2.6666666666666665 * e_Ts_tmp_tmp_tmp *
        t199) * b_Ts_tmp_tmp_tmp;
  t475_tmp = g_Ts_tmp * Ts_tmp_tmp;
  t165 = 4.0 * t475_tmp * (e_Ts_tmp_tmp_tmp * t170 - b_Ts_tmp_tmp_tmp * t165);
  t476 = t420_tmp * 2.0;
  t477 = (b_Ts_tmp_tmp_tmp * (t199 + t164) - t49) * b_Ts_tmp_tmp_tmp - t476;
  t478 = t58 * 1.5;
  t395 = t47_tmp * (2.0 * b_t59_tmp + t478) - (b_Ts_tmp_tmp_tmp *
    (e_Ts_tmp_tmp_tmp * t468 + b_Ts_tmp_tmp_tmp * t395) - t93) *
    b_Ts_tmp_tmp_tmp;
  t468 = 1.3333333333333333 * (Ts_tmp * (-kb_Ts_tmp * t472_tmp - t199) +
    t420_tmp) - t135 * b_Ts_tmp_tmp_tmp;
  t473 = Ts_tmp_tmp_tmp * t395;
  t480 = b_Ts_tmp_tmp_tmp * t170;
  t481 = t480 * t437;
  t482 = 2.0 * t198 * (t477 * Ts_tmp_tmp + t473) + Ts_tmp_tmp * (e_Ts_tmp * t468
    * 3.0 * Ts_tmp_tmp + t481);
  t483 = t173 * t53;
  t485 = t47_tmp * t194 * (t204 * 2.0 - t205_tmp * 3.0);
  t486 = t33 * g_Ts_tmp;
  t115 = -t115 * f_Ts_tmp_tmp_tmp + t413;
  t45 = -t43 * 2.0 - 0.66666666666666663 * t45;
  t110 = t110 * e_Ts_tmp_tmp_tmp + t45 * d_Ts_tmp_tmp_tmp;
  t117 = t38 * 2.0;
  t114 -= t117;
  t487 = t110 * f_Ts_tmp_tmp_tmp + t114 * g_Ts_tmp_tmp_tmp;
  t488 = t108 * t472_tmp;
  t489 = -b_t59_tmp * g_Ts_tmp;
  t48 = m_Ts_tmp_tmp * 2.0;
  t237 += t48;
  t491 = t159 * t237;
  t492 = t491 * f_Ts_tmp_tmp_tmp;
  t121 = -(x[12] * t489) + t141;
  t495 = t159 * b_Ts_tmp_tmp_tmp;
  t496 = -2.0 * t121 * t495 - g_Ts_tmp * ((e_Ts_tmp_tmp_tmp * 4.0 * t159 * t458
    + 4.0 * t375 * Ts_tmp) + t492);
  t497 = -t205_tmp * g_Ts_tmp;
  t375 = Ts_tmp_tmp * (e_Ts_tmp_tmp_tmp * t496 - b_Ts_tmp_tmp_tmp * (g_Ts_tmp *
    (-x[11] * 4.0 * t159 * t35 + t194 * 8.0 * t375) + 2.0 * t159 *
    (e_Ts_tmp_tmp_tmp * t121 + b_Ts_tmp_tmp_tmp * (x[12] * t497 - t164))));
  t493 = t35 * g_Ts_tmp * b_Ts_tmp_tmp_tmp;
  t498_tmp = Ts_tmp_tmp_tmp * x[11];
  t499 = t62 * 8.0 * t32 * e_Ts_tmp_tmp_tmp;
  t500 = (t204 - t205_tmp) * b_Ts_tmp_tmp_tmp;
  t502 = t38_tmp * (g_Ts_tmp * t500 + t472_tmp);
  t503 = t488 * b_Ts_tmp_tmp_tmp + Ts_tmp * (t106 + t487);
  t504 = t498_tmp * t486;
  t440 = (-2.0 * t198 * (b_Ts_tmp_tmp_tmp * t504 + t502 * Ts_tmp_tmp) -
          a_tmp_tmp * t496) + e_Ts_tmp * (b_Ts_tmp * t503 * 3.0 + 4.0 * t440);
  t505 = x[11] * (t424 / 2.0 - t432);
  t506 = a_tmp_tmp_tmp_tmp_tmp / 2.0;
  t507 = b_Ts_tmp_tmp * t506 + f_Ts_tmp_tmp_tmp * t505;
  t508 = x[12] * t12;
  t509 = x[11] * (e_Ts_tmp_tmp_tmp * t508 - t155 * t53);
  t510 = 2.0 * t507;
  t511 = kb_Ts_tmp * t94_tmp;
  t512 = b_Ts_tmp_tmp * t12;
  t513 = t371 * c_Ts_tmp_tmp_tmp;
  t514 = t86 - t513;
  t515 = m_Ts_tmp_tmp_tmp * a_tmp_tmp_tmp_tmp_tmp;
  t516 = f_Ts_tmp_tmp_tmp * t514 - t515;
  t517 = (x[11] * (x[12] * t35 - t94_tmp) + Ts_tmp * t512) * b_Ts_tmp_tmp_tmp;
  t518 = x[11] * t516;
  t519 = t58 * 3.0;
  t520 = e_Ts_tmp_tmp_tmp * t512;
  t521 = t194 * (b_Ts_tmp_tmp * t519 + 2.0 * t520);
  t11 = -t11;
  t252 = t11 * c_Ts_tmp_tmp_tmp;
  t21 = 1.3333333333333333 * t21 + t252 * d_Ts_tmp_tmp_tmp;
  t523 = t11 * a_tmp_tmp_tmp_tmp_tmp + t21 * f_Ts_tmp_tmp_tmp;
  t526 = b_t59_tmp * x[12];
  t528 = d_Ts_tmp_tmp * t32;
  t366 = g_Ts_tmp * t528;
  t531 = t155 * b_Ts_tmp_tmp_tmp;
  t532 = t531 - (-t526);
  t349 = 2.0 * t161 * t532;
  t534 = ((t366 - t154) - t153_tmp) - t349;
  t535 = kb_Ts_tmp * t12;
  t537 = -t535 * b_Ts_tmp_tmp_tmp;
  t153 = f_Ts_tmp_tmp_tmp * t65 + t458;
  t538 = b_Ts_tmp_tmp_tmp * (-4.0 * t161 * t153 + 2.0 * t160 *
    (-e_Ts_tmp_tmp_tmp * -t526 + t537));
  t539 = c_Ts_tmp_tmp * t32;
  t314 *= t539;
  t540 = t508 * x[11];
  t541_tmp = b_Ts_tmp_tmp * t32;
  t507 = b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (-t511 - t507) + t540) +
    t541_tmp;
  t520 = b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp * t58 + t520) -
    t518) - b_t59_tmp * b_Ts_tmp_tmp;
  t542 = t94_tmp * x[12];
  t540 = (1.3333333333333333 * b_Ts_tmp_tmp_tmp * (-Ts_tmp * t542 + t540) +
          Ts_tmp * t523) + k_Ts_tmp_tmp_tmp * t32;
  t339 = Ts_tmp_tmp_tmp * t520;
  t427 = e_Ts_tmp * t540 * 3.0 * Ts_tmp_tmp;
  t150 = 2.0 * (e_Ts_tmp * (t135_tmp * (t507 * Ts_tmp_tmp + t339) - t539 *
    Ts_tmp) - t213);
  t291 = Ts_tmp_tmp * (-b_Ts_tmp_tmp_tmp * t534 + t427) - t150;
  t548 = i_Ts_tmp_tmp * t53;
  t549 = b_Ts_tmp_tmp_tmp * t94_tmp;
  t285 = t194 * (-t204 * t463 + t549 * 3.0);
  t551 = x[11] * t33;
  t537 = (0.66666666666666663 * b_Ts_tmp_tmp_tmp * (x[11] * t35 - t537) -
          0.66666666666666663 * t551 * e_Ts_tmp_tmp_tmp) + t194 *
    (1.3333333333333333 * -t526 - 2.0 * t531);
  t50 = t35 * b_Ts_tmp_tmp_tmp;
  t553_tmp = x[11] * Ts_tmp_tmp;
  t145 = t186_tmp * t145 * b_Ts_tmp_tmp_tmp;
  t554 = 3.0 * Ts_tmp_tmp;
  t556 = t204 * x[11];
  t549 = b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (t556 - t549) + t94_tmp);
  t557 = (b_Ts_tmp_tmp_tmp * t532 + t551) * b_Ts_tmp_tmp_tmp;
  t551 *= a_tmp_tmp;
  t558 = Ts_tmp_tmp_tmp * t549;
  t559 = t186_tmp * Ts_tmp;
  t411 = f_Ts_tmp * (Ts_tmp_tmp * (Ts_tmp_tmp * (t558 - t551) + t557) + t559 *
                     x[12]);
  t144 = Ts_tmp / 2.0;
  t361 = Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp;
  t478 = t361 * (e_Ts_tmp_tmp_tmp * (-b_t59_tmp - t478) + t144 * t12) *
    Ts_tmp_tmp;
  t564 = Ts_tmp * t184_tmp;
  t565 = t180 * (t32 * Ts_tmp * (b_Ts_tmp - 1.0) - t564 * Ts_tmp_tmp_tmp *
                 Ts_tmp_tmp);
  t260 = (n_Ts_tmp_tmp - 2.0) * ab_Ts_tmp;
  t574 = j_Ts_tmp_tmp * (t260 + 1.0);
  t342 = g_Ts_tmp_tmp_tmp * (n_Ts_tmp - 0.5);
  t576 = t342 * 2.0 * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp;
  t577 = t574 + t576;
  t578 = t204 * t32;
  t576 = (-b_Ts_tmp_tmp_tmp * (-b_Ts_tmp_tmp_tmp * t577 + t578) - t574) - t576;
  t172 = i_Ts_tmp_tmp * t32;
  t580 = (n_Ts_tmp_tmp - 2.0) * n_Ts_tmp;
  t582 = -2.0 * n_Ts_tmp_tmp + (t580 + 1.0);
  t583 = a_tmp_tmp_tmp * t10;
  t584 = t583 * 2.0;
  t585 = (ab_Ts_tmp * t582 + n_Ts_tmp) - t584;
  t586 = ((t260 * (n_Ts_tmp - 0.5) + -0.5) + n_Ts_tmp) - t584;
  t247 = -2.0 * (t12 * t58 * (-Ts_tmp + 1.0) + e_Ts_tmp_tmp_tmp * t586) + t585 *
    e_Ts_tmp_tmp_tmp * Ts_tmp;
  t589 = i_Ts_tmp_tmp * t12;
  t44 = 2.0 * t585;
  t592 = n_Ts_tmp_tmp * 8.0;
  t593 = h_Ts_tmp * 2.0;
  t178 = t593 * d_Ts_tmp_tmp_tmp;
  t179 = t100 * (16.0 - t592) + t178;
  t183 = t437 * t345_tmp * m_Ts_tmp_tmp;
  t597 = t183 * h_Ts_tmp_tmp_tmp;
  t203 = l_Ts_tmp_tmp_tmp / 2.0;
  t599 = t82 + t203;
  t600 = n_Ts_tmp * 4.0;
  t602 = i_Ts_tmp_tmp_tmp * t599;
  t603_tmp = t47_tmp * d_Ts_tmp_tmp_tmp;
  t603 = t603_tmp * (t600 + -2.0) - t602;
  t604 = (t179 * c_Ts_tmp_tmp_tmp - t597) * f_Ts_tmp_tmp_tmp;
  t119 = 8.0 * c_Ts_tmp_tmp_tmp;
  t65 = f_Ts_tmp_tmp_tmp * (-4.0 * g_Ts_tmp_tmp_tmp * t603 + t604) - t119 * t100;
  t263 = t378_tmp * x[11];
  t608 = t263 * d_Ts_tmp_tmp_tmp;
  t219 = l_Ts_tmp_tmp_tmp * (-n_Ts_tmp_tmp / 4.0 + 0.5) - t608;
  t610 = -l_Ts_tmp_tmp / 8.0 + t357 / 2.0;
  t611 = n_Ts_tmp / 4.0;
  t612 = 16.0 * g_Ts_tmp_tmp_tmp;
  t613 = 2.0 * (n_Ts_tmp_tmp + 4.0);
  t344 = t38 * d_Ts_tmp_tmp_tmp;
  t75 = (n3p * t345_tmp * t611 + e_Ts_tmp_tmp_tmp * t610) - t344 *
    c_Ts_tmp_tmp_tmp;
  t616 = n_Ts_tmp * 8.0;
  t618 = (-8.0 * c_Ts_tmp_tmp_tmp * (e_Ts_tmp_tmp_tmp * t219 - t43 *
           (n_Ts_tmp_tmp - 2.0)) + t613 * t69_tmp) * f_Ts_tmp_tmp_tmp;
  t619 = h_Ts_tmp_tmp_tmp * 2.0;
  t620 = (f_Ts_tmp_tmp_tmp * (t612 * t75 + t618) + t619 * t40) + t69_tmp * (t616
    + -6.0);
  t178 += t100 * (6.0 * n_Ts_tmp_tmp - 12.0);
  t621 = -3.0 * n_Ts_tmp + 1.5;
  t622 = t603_tmp * t621 - t602;
  t597 = (t178 * c_Ts_tmp_tmp_tmp - t597) * f_Ts_tmp_tmp_tmp;
  t623 = f_Ts_tmp_tmp_tmp * (-4.0 * g_Ts_tmp_tmp_tmp * t622 + t597) + t100 * 6.0
    * c_Ts_tmp_tmp_tmp;
  t624 = ib_Ts_tmp * i_Ts_tmp_tmp_tmp;
  t37 = t624 * t32;
  t627 = (n_Ts_tmp_tmp + 1.0) + t580;
  t628 = h_Ts_tmp_tmp_tmp * (0.75 * x[11] * d_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp
    - m_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp - 2.0) * c_Ts_tmp_tmp_tmp);
  t629 = t627 * n3p / 4.0 + t628 * g_Ts_tmp;
  t221 = -t462 / 4.0 - 0.375 * t263;
  t340 = -c_Ts_tmp_tmp_tmp * (d_Ts_tmp_tmp_tmp * t82 - t221) + t340 / 2.0;
  t113 = t90 * c_Ts_tmp_tmp_tmp;
  t56 = ((ab_Ts_tmp * t629 - t113) + n3p * (n_Ts_tmp + -1.0) / 4.0) +
    q_Ts_tmp_tmp_tmp * t340 * f_Ts_tmp_tmp_tmp;
  t634 = n_Ts_tmp / 2.0;
  t635 = t634 * t47_tmp;
  t636 = 0.75 * t462 * 0.33333333333333331 * i_Ts_tmp_tmp_tmp + 0.75 * t47_tmp *
    (-n_Ts_tmp_tmp - 0.66666666666666663);
  t637 = -t101 * 2.0 + t98;
  t640 = h_Ts_tmp_tmp * g_Ts_tmp_tmp_tmp;
  t641 = t47_tmp * (1.0 - c_Ts_tmp_tmp_tmp) * (c_Ts_tmp_tmp_tmp + 1.0);
  t120 = fb_Ts_tmp * e_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp - 2.0);
  t643 = m_Ts_tmp_tmp * d_Ts_tmp_tmp_tmp;
  t644 = c_Ts_tmp_tmp_tmp * (-t643 + t120);
  t645 = t644 * g_Ts_tmp / 2.0 - t636 * e_Ts_tmp_tmp_tmp;
  t646 = m_Ts_tmp_tmp * h_Ts_tmp_tmp_tmp;
  t647 = t646 * g_Ts_tmp;
  t143 = t637 * e_Ts_tmp_tmp_tmp;
  t321 = t143 * c_Ts_tmp_tmp_tmp - t647;
  t650 = (t645 * ab_Ts_tmp + g_Ts_tmp_tmp_tmp * t321 * f_Ts_tmp_tmp_tmp / 2.0) -
    t641 * e_Ts_tmp_tmp_tmp / 2.0;
  t651 = n_Ts_tmp_tmp * 1.5 + (t580 + 1.0);
  t584 = ((ab_Ts_tmp * t651 + n_Ts_tmp) - t584) - 1.0;
  t15 = 0.33333333333333331 * f_Ts_tmp_tmp - t90;
  t51 = -0.33333333333333331 * l_Ts_tmp_tmp_tmp - t82;
  t654 = t15 * d_Ts_tmp_tmp_tmp;
  t220 = -g_Ts_tmp_tmp_tmp * t51 + f_Ts_tmp_tmp_tmp * t654;
  t657 = t186_tmp * t155;
  t658 = t47_tmp * Ts_tmp_tmp_tmp;
  t60 = t658 * t59_tmp * (e_Ts_tmp_tmp_tmp * t247 - b_Ts_tmp_tmp_tmp * (-2.0 *
    (e_Ts_tmp_tmp_tmp * (t194 * t585 - t589) + b_Ts_tmp_tmp_tmp * t586) + Ts_tmp
    * (b_Ts_tmp_tmp_tmp * t585 - i_Ts_tmp_tmp * t60)));
  t660 = c_Ts_tmp_tmp + t177_tmp;
  t661 = a_tmp_tmp * e_Ts_tmp;
  t662 = t660 * t661 + t284_tmp;
  t14 = t413_tmp * t173 * 4.0;
  t664 = (b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (-t44 * t62 + t65) + t620) +
          t623) * b_Ts_tmp_tmp_tmp + t14 * e_Ts_tmp_tmp_tmp;
  t665 = t157 * t32;
  t666 = i_Ts_tmp_tmp * t95_tmp * 4.0;
  t667 = -8.0 * (b_Ts_tmp_tmp_tmp * (t56 - t665) + t650) * b_Ts_tmp_tmp_tmp -
    t666;
  t668 = t413_tmp * t204;
  t669_tmp = x[12] * Ts_tmp;
  t669 = t669_tmp * t584 + t668;
  t670 = t58 * 6.0;
  t671 = -g_Ts_tmp * 4.0 * t669 - t220 * t670;
  t672 = x[11] * t177 * t576 - t657;
  t16 = t376_tmp * t463;
  t674 = (4.0 * t376_tmp * t672 + (Ts_tmp_tmp * (Ts_tmp_tmp_tmp * t667 +
            Ts_tmp_tmp * t664) + t671) * Ts_tmp_tmp) - t16 * t247 *
    Ts_tmp_tmp_tmp * t59_tmp;
  t675 = f_Ts_tmp * e_Ts_tmp_tmp_tmp;
  t676 = t675 * t660;
  t680_tmp = n3ppp * t565 - n3p * t291;
  t681 = t254 * b_Ts_tmp_tmp;
  t682 = t34 * t205;
  t60 = (t682 * t680_tmp + t681 * t205 * t440 * t229) + (-((-4.0 * g_Ts_tmp *
    (-t657 * e_Ts_tmp_tmp_tmp + (e_Ts_tmp_tmp_tmp * t576 - b_Ts_tmp_tmp_tmp *
    (-t194 * 2.0 * t577 + t54 * t172)) * t177 * x[11]) + 2.0 * t60) +
    ((Ts_tmp_tmp * (Ts_tmp_tmp_tmp * (-8.0 * (-e_Ts_tmp_tmp_tmp * t650 +
    b_Ts_tmp_tmp_tmp * ((b_Ts_tmp_tmp_tmp * (-b_Ts_tmp_tmp_tmp * t38 * (t260 +
    1.0) * c_Ts_tmp_tmp_tmp - t365 * f_Ts_tmp_tmp_tmp * (n_Ts_tmp - 0.5) *
    q_Ts_tmp_tmp_tmp) + b_Ts_tmp_tmp_tmp * ((n_Ts_tmp_tmp - 2.0) * t635 - t636) *
    ab_Ts_tmp) + b_Ts_tmp_tmp_tmp * (t637 * t640 - t641) / 2.0)) + t194 * (-24.0
    * t157 * t32 + 16.0 * t56)) + Ts_tmp_tmp * (((4.0 * b_Ts_tmp_tmp_tmp * (-t12
    * t157 * (-Ts_tmp - 1.0) + g_Ts_tmp * (m_Ts_tmp_tmp_tmp * Ts_tmp * t44 + t37))
    - e_Ts_tmp_tmp_tmp * t623) + Ts_tmp * ((-8.0 * ab_Ts_tmp * t219 + 2.0 *
    l_Ts_tmp_tmp_tmp) * b_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp + t612 *
    b_Ts_tmp_tmp_tmp * (l_Ts_tmp_tmp * t611 + t610) * f_Ts_tmp_tmp_tmp)) - t194 *
    (b_Ts_tmp_tmp_tmp * 3.0 * t65 + 2.0 * t620))) - 6.0 * i_Ts_tmp_tmp *
      (-e_Ts_tmp_tmp_tmp * t220 + t166)) + t376_tmp * (m_Ts_tmp_tmp_tmp * 8.0 *
    t584 - 4.0 * t37)) * Ts_tmp_tmp) * t662 + t674 * t676) * t227 * t224;
  t166 = t34 * b_Ts_tmp_tmp * Ts_tmp_tmp_tmp;
  t209_tmp = Ts_tmp * (-t116 * g_Ts_tmp_tmp_tmp + 0.66666666666666663 * t290 *
                       x[12]);
  t253 = b_Ts_tmp_tmp_tmp * (t708 * Ts_tmp + x[11] * (g_Ts_tmp * t284 + t62 *
    t270));
  t209 = t264 * ((3.0 * t257 * t337 + t97 * (t187 * ((t200 * t156_tmp * t334 -
    t205 * t330) + t336) + t156_tmp * ((2.0 * t198 * (Ts_tmp_tmp_tmp * ((t253 -
    t286 * e_Ts_tmp_tmp_tmp) + t194 * (-2.0 * t288_tmp + t287_tmp * 3.0)) +
    Ts_tmp_tmp * (-t194 * (t209 * t266 + 2.0 * t222) + x[11] * (e_Ts_tmp_tmp_tmp
    * t275_tmp + b_Ts_tmp_tmp_tmp * (t277 * Ts_tmp + t272)))) + Ts_tmp_tmp *
    (e_Ts_tmp_tmp_tmp * t309 - b_Ts_tmp_tmp_tmp * (-2.0 * t160 *
    (-e_Ts_tmp_tmp_tmp * t304 + t311) + t312))) + e_Ts_tmp * (3.0 *
    ((b_Ts_tmp_tmp_tmp * (-e_Ts_tmp_tmp_tmp * (2.0 * t293 + t299 * 3.0) - t300)
      + t209_tmp) - t297 * e_Ts_tmp_tmp_tmp) * b_Ts_tmp - t317)))) - t338) +
    gb_Ts_tmp * t422;
  t408 = f_Ts_tmp * (t554 * t537 - t145);
  t60_tmp = e_Ts_tmp * (3.0 * (t194 * (-2.0 * t523 + kb_Ts_tmp * 4.0 * t94_tmp)
    - 1.3333333333333333 * t509) * b_Ts_tmp - t314);
  t60 = (t168 * t60 + t187 * (-t166 * ((-2.0 * t198 * (-Ts_tmp_tmp * (x[11] *
              (e_Ts_tmp_tmp_tmp * t472_tmp - t483) + t485) + t498_tmp *
             (-e_Ts_tmp_tmp_tmp * t486 + t493)) + t375) + e_Ts_tmp * (3.0 *
            (t115 * Ts_tmp + e_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (-3.0 * t106
    - 2.0 * t487) - t488)) * b_Ts_tmp - t499)) + (n3p * ((2.0 * t198 *
             (Ts_tmp_tmp_tmp * ((-e_Ts_tmp_tmp_tmp * t518 - t517) + t521) +
              Ts_tmp_tmp * (-t194 * (t511 * 3.0 + t510) + t509)) + Ts_tmp_tmp *
             (t534 * e_Ts_tmp_tmp_tmp - t538)) + t60_tmp) + n3pp * (2.0 * t198 *
            (Ts_tmp_tmp_tmp * (-x[11] * (b_t59_tmp - t548) + t285) + t553_tmp *
             (e_Ts_tmp_tmp_tmp * t33 - t50)) + t408)) * t229 * t225)) * t141_tmp
    * t125_tmp;
  t106 = x[12] * t482;
  t222 = t106 * t254 * x[11];
  t281 = n3pp * t411;
  t286 = t662 * t674;
  t287 = t286 * t156_tmp * t147_tmp * t168;
  t288 = t187 * (-t281 - t222) + t287;
  t293 = t254 * x[12];
  t297 = t293 * x[11];
  t142 = t182 * (t135 * e_Ts_tmp_tmp_tmp + t6);
  t55 = 2.0 * t199 + t164 * 3.0;
  t93 = t97 * (t205 * t288 + t156_tmp * (n3ppp * t180 * (t194 * t32 * (b_Ts_tmp
    - 1.0) + t478) + t297 * ((2.0 * t198 * (Ts_tmp_tmp_tmp * (((-t93 *
    e_Ts_tmp_tmp_tmp - t469) + t470) + t471) + Ts_tmp_tmp * ((-t194 * t55 + t271)
    - t190)) - t165) + t142)));
  t208 = b_Ts_tmp_tmp * Ts_tmp_tmp_tmp;
  t286 *= 4.0;
  t146 = t146 * o_Ts_tmp_tmp_tmp * Ts_tmp_tmp * M[0];
  t299 = g_Ts_tmp_tmp_tmp * t386_tmp * i_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp;
  t460 = Ts_tmp_tmp * -t270;
  t509 = t256 * t229;
  t511 = t126 * t224 * t229;
  t518 = t511 * Ts_tmp_tmp_tmp;
  t231 = 2.0 * t216 * t125_tmp * t231 * t141_tmp * t225 * t229;
  t572 = t231 * t334;
  t436 = b_Ts_tmp_tmp_tmp * (-t436 * Ts_tmp_tmp_tmp + Ts_tmp_tmp * (-x[11] *
    t240 * t437 * b_t59_tmp + t239 * 2.0 * t433));
  t201 *= t246;
  t443 = 6.0 * t245 * (t444 * Ts_tmp_tmp - t443);
  t610_tmp = t186_tmp * e_Ts_tmp_tmp_tmp;
  t620_tmp = t12 * Ts_tmp_tmp;
  t623_tmp = t610_tmp + t620_tmp;
  t37 = t216 * t623_tmp;
  t56 = t231 * t452_tmp;
  t637 = t47_tmp * b_Ts_tmp_tmp_tmp * t247;
  t641 = cb_Ts_tmp * 8.0;
  t650 = t177_tmp * 3.0;
  t657 = t495 * (c_Ts_tmp_tmp + t650);
  t532 *= 2.0 * t239;
  t683 = t173 * d_Ts_tmp_tmp;
  t507 = t159 * 8.0 * t507 * t135_tmp;
  t520 = 2.0 * Ts_tmp_tmp * (-t198 * t520 + t683);
  t540 = 6.0 * t245 * (-t339 * Ts_tmp_tmp + t540);
  t237 = (-6.0 * t245 * (-t504 * a_tmp_tmp + t503) - b_Ts_tmp_tmp_tmp * (-t496 *
           Ts_tmp_tmp_tmp + Ts_tmp_tmp * (-2.0 * t121 * t661 - g_Ts_tmp * ((4.0 *
              t155 * Ts_tmp * f_Ts_tmp + 4.0 * t458 * t675) + t237 *
             f_Ts_tmp_tmp_tmp * f_Ts_tmp)))) + t198 * (-t463 * a_tmp_tmp * t486
    + 8.0 * t502 * Ts_tmp_tmp_tmp);
  t494 = -cb_Ts_tmp + b_Ts_tmp;
  t496 = 2.0 * e_Ts_tmp * (t494 * t32 * Ts_tmp * x[12] + t59_tmp * t549) + t245 *
    (-4.0 * t557 + Ts_tmp_tmp * (t551 * 8.0 - t558 * 6.0));
  t502 = b_Ts_tmp * 4.0;
  t503 = f_Ts_tmp * (t564 * Ts_tmp_tmp * (-3.0 * cb_Ts_tmp + b_Ts_tmp) +
                     t186_tmp * (t502 - 2.0) * Ts_tmp);
  t504 = fb_Ts_tmp * t43_tmp;
  t339 = t504 * 4.0;
  t248 = Ts_tmp_tmp * (b_Ts_tmp_tmp_tmp * (t239 * 2.0 * t367 * f_Ts_tmp_tmp_tmp
    - g_Ts_tmp * t240 * (t339 - m_Ts_tmp) * f_Ts_tmp_tmp_tmp) + t248 *
                       d_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp) - b_Ts_tmp_tmp_tmp *
    t370 * Ts_tmp_tmp_tmp;
  t370 = 8.0 * t382 * Ts_tmp_tmp_tmp;
  t557 = cb_Ts_tmp - b_Ts_tmp;
  t558_tmp = t187 * t253_tmp;
  t564 = t558_tmp * t218 + 3.0 * t251;
  t675 = t682 * t216;
  t26 = t251 * t187 * t205;
  t136 = (2.0 * t675 * t125_tmp * t168 * t141_tmp * (t558_tmp + t254) + 3.0 *
          t518 * (t218 * t147_tmp * e_Ts_tmp_tmp_tmp + t202)) + t97 * ((t156_tmp
    * (((t558_tmp * t202 - 6.0 * t245 * (t197 * Ts_tmp_tmp + t136)) + t167) +
       t198 * (-8.0 * t191 * Ts_tmp_tmp_tmp + t246 * t195)) + t156_tmp * t564 *
    t147_tmp * e_Ts_tmp_tmp_tmp) - t26);
  t195 = t246 * t395;
  t170 = 4.0 * t376_tmp * (t240 * t33 * Ts_tmp_tmp - t170 * Ts_tmp_tmp_tmp);
  t197 = t166 * t440;
  t121 = t251 * t334;
  t444 = -g_Ts_tmp * (-t241 * g_Ts_tmp_tmp_tmp + t146);
  t174 = t251 * t452_tmp;
  t262 = t198 * (8.0 * t262 * Ts_tmp_tmp_tmp + t201);
  t708 = t572 * t253_tmp;
  t308 = gb_Ts_tmp * ((3.0 * t518 * t454 + t509 * (((t187 * ((t174 + t253_tmp *
    t449) + t37) - t436) - t262) + t443)) - t56 * t253_tmp) + t264 * ((3.0 *
    t518 * t337 + t509 * ((((t187 * ((-t216 * (t332 * Ts_tmp_tmp_tmp - t460) -
    t121) + t330 * t253_tmp) - 6.0 * t245 * (-t329 * Ts_tmp_tmp + t325)) -
    Ts_tmp_tmp * (b_Ts_tmp_tmp_tmp * (t444 - 2.0 * t239 * t308) + t299)) +
    b_Ts_tmp_tmp_tmp * t309 * Ts_tmp_tmp_tmp) - t198 * (8.0 * t320 *
    Ts_tmp_tmp_tmp + t246 * t323))) + t708);
  t99 = t281 + t222;
  t287 = t187 * t99 - t287;
  t_Ts_tmp = t397 * Ts_tmp_tmp_tmp + h_Ts_tmp_tmp * Ts_tmp_tmp *
    i_Ts_tmp_tmp_tmp;
  u_Ts_tmp = t251 * t399;
  t222 = t468 + t473 * Ts_tmp_tmp;
  t65 = t251 * t253_tmp;
  v_Ts_tmp = t231 * t399 * t253_tmp;
  t106 = ((((((2.0 * (t509 * (x[11] * (Ts_tmp_tmp_tmp * (-t498_tmp * t440 + x[12]
    * ((-6.0 * t245 * t222 + t170) + t198 * (-8.0 * t477 * Ts_tmp_tmp_tmp + t195))
    * t156_tmp) + t106) + t287 * t253_tmp)) - 3.0 * t518 * t680_tmp) + x[11] *
              t136) + x[12] * ((3.0 * t518 * (t251 - t255) + t509 * (((((((t187 *
    ((-t216 * (t184_tmp * Ts_tmp_tmp + t186_tmp) + t65) + t65) + t218) + 6.0 *
    e_Ts_tmp * t193 * t557) - t249 * Ts_tmp_tmp_tmp) - a_tmp_tmp * ((-g_Ts_tmp *
    (-t160 * t238 * f_Ts_tmp_tmp_tmp - t147 * a_tmp_tmp_tmp_tmp_tmp) + t162) -
    t163)) + t158 * 2.0 * Ts_tmp_tmp_tmp) + e_Ts_tmp * (((12.0 * Ts_tmp_tmp_tmp *
    cb_Ts_tmp * t211 * Ts_tmp_tmp + 24.0 * cb_Ts_tmp * t206 * b_Ts_tmp) - t250 *
    t59_tmp) - 20.0 * t215 * t135_tmp)) + t254 * t564)) + t509 * (-t233 *
    t253_tmp * t253_tmp + t232 * cb_Ts_tmp))) + hb_Ts_tmp * ((3.0 * t518 * t404
              - t509 * (((t187 * ((-t216 * t_Ts_tmp - u_Ts_tmp) - t393 *
    t253_tmp) - 6.0 * t245 * (t391 * Ts_tmp_tmp - t386)) + t248) - t198 * (-t246
    * t385 + t370))) - v_Ts_tmp)) + t6_tmp * t308) + (t168 * ((-t253_tmp *
             t680_tmp * t229 * t225 - t197 * t253_tmp) + (-t662 * (((-2.0 *
    Ts_tmp_tmp * (t59_tmp * t637 + cb_Ts_tmp * t667) + Ts_tmp_tmp * (((-20.0 *
    b_Ts_tmp_tmp_tmp * t135_tmp * t576 * t658 + b_Ts_tmp * t637 * t641) - t554 *
    Ts_tmp_tmp_tmp * t664) - 4.0 * t665)) + t135_tmp * t667) - Ts_tmp_tmp_tmp *
              t671) + t674 * t657) * t227 * t224) + t187 * ((-b_Ts_tmp_tmp *
             t440 * t229 * t156_tmp - t166 * t237) + ((n3p *
              (((-b_Ts_tmp_tmp_tmp * (-t534 * Ts_tmp_tmp_tmp + Ts_tmp_tmp *
    ((-t241 * f_Ts_tmp_tmp_tmp - t243) - t532)) - t540) + t520) + t507) + n3pp *
              t496) + n3ppp * t503) * t229 * t225)) * t141_tmp * t125_tmp) +
    t518 * (t156_tmp * (t106 * t498_tmp * 8.0 - t286 * t187 * t147_tmp) + t281 *
            6.0);
  t28 = -o_Ts_tmp_tmp_tmp * t18 + t28 * g_Ts_tmp_tmp_tmp;
  t158 = g_Ts_tmp_tmp_tmp * t89 - t282;
  t193 = t22 * g_Ts_tmp_tmp_tmp - t292;
  t206 = t134 * g_Ts_tmp_tmp_tmp + t294;
  t215 = -t140 * g_Ts_tmp_tmp_tmp + t301;
  t238 = t215 - t307;
  t152 = g_Ts_tmp * (w_Ts_tmp - t306) - 2.0 * t161 * t238;
  t249 = b_Ts_tmp_tmp_tmp * (-x[11] * t275_tmp + b_Ts_tmp_tmp_tmp * (-t28 / 2.0
    + t318)) - t319;
  t235 = t158 * x[11];
  t250 = b_Ts_tmp_tmp_tmp * (t235 + b_Ts_tmp_tmp_tmp * (t287_tmp - t288_tmp)) -
    t322;
  t395 = x[11] * t206;
  t273 = -(t395 + b_Ts_tmp_tmp_tmp * (-kb_Ts_tmp * t298_tmp + t193)) *
    b_Ts_tmp_tmp_tmp + t324;
  t279 = Ts_tmp_tmp_tmp * t250;
  t280 = ((a_tmp_tmp * t152 + 2.0 * t198 * (-t249 * Ts_tmp_tmp + t279)) + t328)
    - t182 * t273;
  t289 = t218 * t334 * t187 + 3.0 * t280;
  t146 = -t509 * (((((t187 * ((-t216 * (-t332 * Ts_tmp_tmp_tmp + t460) + t121) +
    t253_tmp * t280) - 6.0 * t245 * (t279 * Ts_tmp_tmp - t273)) + Ts_tmp_tmp *
                     (b_Ts_tmp_tmp_tmp * (t444 - 2.0 * t239 * t238) + t299)) -
                    b_Ts_tmp_tmp_tmp * t152 * Ts_tmp_tmp_tmp) + t198 * (8.0 *
    t249 * Ts_tmp_tmp_tmp + t246 * t250)) + t254 * t289) + t708;
  t238 = d_Ts_tmp_tmp_tmp * hb_Ts_tmp;
  t239 = t509 * t337;
  t273 = t295 * f_Ts_tmp_tmp_tmp;
  t279 = t417 * t32;
  t292 = t418 + t139;
  t294 = -t509 * t404;
  t299 = 0.66666666666666663 * t379 * a_tmp_tmp_tmp;
  t307 = t161 * g_Ts_tmp_tmp_tmp;
  t308 = -g_Ts_tmp * g_Ts_tmp_tmp_tmp * t388;
  t309 = t216 * (a_tmp_tmp_tmp * Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp -
                 g_Ts_tmp_tmp_tmp * t396_tmp * Ts_tmp_tmp);
  t318 = t572 * t399;
  t320 = -t509 * ((((t187 * ((t280 * t399 + t334 * t393) + t309) - 2.0 * t198 *
                     (g_Ts_tmp_tmp_tmp * t381 * Ts_tmp_tmp + g_Ts_tmp_tmp_tmp *
                      t384 * Ts_tmp_tmp_tmp)) + a_tmp_tmp * (-2.0 * t307 * t367
    - t369 * g_Ts_tmp_tmp_tmp)) + t308) - t182 * (-q_Ts_tmp * t363 - t299)) +
    t318;
  t322 = -t509 * t454;
  t323 = t439 * -t270;
  t324 = t47_tmp * t266;
  t325 = t144 * t18 * t266;
  t328 = 1.3333333333333333 * f_Ts_tmp_tmp_tmp * t128;
  t329 = b_Ts_tmp_tmp_tmp * (-t124 * f_Ts_tmp_tmp_tmp + t426 * g_Ts_tmp_tmp_tmp);
  t332 = 1.3333333333333333 * t47_tmp * t270 * x[12] * t53;
  t337 = t417 * t266;
  t88 = t88 * g_Ts_tmp_tmp_tmp + t282;
  t250 = g_Ts_tmp * t148;
  t363 = t250 * t266;
  t303_tmp = e_Ts_tmp_tmp_tmp * t270;
  t303 = Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (-x[11] * (-t83 * f_Ts_tmp_tmp_tmp
    + t303) + b_Ts_tmp_tmp_tmp * (n3p * x[11] * b_Ts_tmp_tmp_tmp * t270 -
    t303_tmp * t67)) + t319 * e_Ts_tmp_tmp_tmp);
  t444 = t133_tmp * t266;
  t319 = t444 * Ts_tmp;
  t367 = Ts_tmp_tmp_tmp * t266;
  t369 = t216 * (-t270 * e_Ts_tmp_tmp_tmp * Ts_tmp_tmp - t367);
  t379 = t572 * t452_tmp;
  t381 = -t509 * ((t187 * ((t280 * t452_tmp + t334 * t449) + t369) + 2.0 *
                   e_Ts_tmp * (t135_tmp * (-Ts_tmp_tmp * (-x[11] *
    (b_Ts_tmp_tmp_tmp * ((t408_tmp * g_Ts_tmp_tmp_tmp + t323) + t48_tmp) + t324)
    + t325) + t303) - t319)) - Ts_tmp_tmp * (-b_Ts_tmp_tmp_tmp * (-t435 * t88 -
    t363) + f_Ts_tmp * ((b_Ts_tmp_tmp_tmp * (x[11] * (-t207 * g_Ts_tmp_tmp_tmp -
    t328) - t329) - t332) + t337) * 3.0)) + t379;
  t384 = t47_tmp * o_Ts_tmp_tmp_tmp;
  t385 = t463 * -t270 * g_Ts_tmp;
  t391 = t278 * 2.0;
  t409 = t47_tmp * (t321_tmp * 2.0 - t331 * 1.5);
  t418 = g_Ts_tmp * t266;
  t397 = -g_Ts_tmp_tmp_tmp * t27;
  t422 = t397 + t384;
  t426 = 1.3333333333333333 * (Ts_tmp * (kb_Ts_tmp * t418 + t422) - t47_tmp *
    -t270);
  t207 = t437 * b_Ts_tmp_tmp_tmp;
  t454 = -t207 * t159 * m_Ts_tmp_tmp_tmp * t270;
  t534 = g_Ts_tmp * t270;
  t564 = f_Ts_tmp_tmp_tmp * t114;
  t572 = t108 * t418 * b_Ts_tmp_tmp_tmp;
  t637 = t321_tmp * g_Ts_tmp;
  t667 = x[12] * t637;
  t682 = t323 * 4.0;
  y_Ts_tmp = Ts_tmp_tmp * t38_tmp;
  t418 = 2.0 * t198 * (y_Ts_tmp * (t376_tmp * b_t336_tmp - t418) + t498_tmp *
                       t534 * e_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp);
  t27 = o_Ts_tmp_tmp_tmp / 2.0;
  t686 = x[12] * t266;
  t121 = t686 * x[11];
  t537 = b_Ts_tmp_tmp * t266;
  t692 = (-e_Ts_tmp_tmp_tmp * t537 + t331 * b_Ts_tmp_tmp) * b_Ts_tmp_tmp_tmp;
  t184 = t321_tmp * b_Ts_tmp_tmp;
  t523 = m_Ts_tmp_tmp_tmp * t266;
  t699 = c_Ts_tmp_tmp * Ts_tmp;
  t388 = t699 * -t270;
  t382 = -t523 + t276 * b_Ts_tmp_tmp_tmp;
  t701 = a_tmp_tmp * x[11];
  t162 = f_Ts_tmp * (Ts_tmp_tmp * (Ts_tmp_tmp * (t361 * (-x[11] * t266 +
    b_Ts_tmp_tmp_tmp * (t335 * x[11] + b_Ts_tmp_tmp_tmp * t284)) - t701 *
    t303_tmp) + (x[11] * t303_tmp + b_Ts_tmp_tmp_tmp * t382) * b_Ts_tmp_tmp_tmp)
                     - t333 * t669_tmp);
  t241 = t331 - t321_tmp;
  t6 = t180 * (Ts_tmp_tmp_tmp * Ts_tmp * t241 * Ts_tmp_tmp + (b_Ts_tmp - 1.0) *
               -t270 * Ts_tmp);
  t704 = g_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp - ab_Ts_tmp;
  t705 = t704 * (n_Ts_tmp - 0.5) * d_Ts_tmp_tmp_tmp;
  t706 = a_tmp_tmp_tmp * o_Ts_tmp_tmp_tmp * (n_Ts_tmp_tmp - 2.0);
  t707 = t705 + t706;
  t710_tmp = g_Ts_tmp_tmp_tmp * t32 - f_Ts_tmp_tmp_tmp * -t270;
  t711 = t725 * e_Ts_tmp_tmp_tmp;
  t712 = j_Ts_tmp_tmp * t704 * d_Ts_tmp_tmp_tmp;
  t582 = -t582 * f_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp + t712;
  t713 = -t342 * (n_Ts_tmp_tmp - 2.0) * f_Ts_tmp_tmp_tmp + t712;
  t65 = g_Ts_tmp_tmp_tmp * t12;
  t717 = 4.0 * e_Ts_tmp_tmp_tmp;
  t709 = t43_tmp * x[11];
  t719_tmp = t65 - f_Ts_tmp_tmp_tmp * t266;
  t720 = m_Ts_tmp_tmp * g_Ts_tmp;
  t51 *= f_Ts_tmp_tmp_tmp;
  t721 = t439 * 8.0;
  t722 = Ts_tmp_tmp_tmp * t710_tmp;
  t340 = (t334 * t680_tmp * t229 * t225 + t197 * t334) - t662 * ((4.0 * t376_tmp
    * (t722 * m_Ts_tmp_tmp + x[11] * (2.0 * ((-Ts_tmp * t707 + t705) + t706) +
    t711 * t710_tmp) * t177) + (((Ts_tmp_tmp * (Ts_tmp_tmp_tmp * ((4.0 * t263 *
    t719_tmp - 8.0 * b_Ts_tmp_tmp_tmp * ((t720 * Ts_tmp * t710_tmp - t321 * t704
    / 2.0) - q_Ts_tmp_tmp_tmp * t645 * f_Ts_tmp_tmp_tmp)) + 16.0 * (t629 *
    f_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp + t340 * t704) * Ts_tmp) + Ts_tmp_tmp *
    (-4.0 * g_Ts_tmp * (t582 * x[12] * t52 + t709 * t710_tmp) + ((4.0 * t622 *
    t704 + b_Ts_tmp_tmp_tmp * ((b_Ts_tmp_tmp_tmp * (4.0 * t603 * t704 - t604 *
    q_Ts_tmp_tmp_tmp) - 16.0 * t75 * t704) - t618 * q_Ts_tmp_tmp_tmp)) - t597 *
    q_Ts_tmp_tmp_tmp) * b_Ts_tmp_tmp_tmp)) + e_Ts_tmp_tmp_tmp * 4.0 * t263 *
    t710_tmp) + 6.0 * t725 * (g_Ts_tmp_tmp_tmp * t220 + f_Ts_tmp_tmp_tmp * (t654
    * g_Ts_tmp_tmp_tmp + t51))) - t721 * (-t651 * f_Ts_tmp_tmp_tmp *
    g_Ts_tmp_tmp_tmp + t712)) * Ts_tmp_tmp) - t16 * (2.0 * b_Ts_tmp_tmp_tmp *
    ((i_Ts_tmp_tmp * (Ts_tmp - 1.0) * t266 + t65 * i_Ts_tmp_tmp_tmp * (-Ts_tmp +
    1.0)) + t194 * t582) - t717 * t713) * Ts_tmp_tmp_tmp * t59_tmp) * t227 *
    t224;
  t551 = Ts_tmp_tmp * t184_tmp;
  t23_tmp = t551 + t186_tmp;
  t23 = ((t239 * t238 + gb_Ts_tmp * t381) + t264 * (-t509 * ((((t187 * (t216 *
    t23_tmp + t334 * (t330 - t280)) + 2.0 * t198 * (Ts_tmp_tmp_tmp *
    (b_Ts_tmp_tmp_tmp * (x[11] * (f_Ts_tmp_tmp_tmp * t89 + p_Ts_tmp) +
    b_Ts_tmp_tmp_tmp * (e_Ts_tmp_tmp_tmp * (-f_Ts_tmp_tmp_tmp * t78 + t79) -
                        b_Ts_tmp_tmp_tmp * (-f_Ts_tmp_tmp_tmp * t71 + t73))) +
     db_Ts_tmp) + Ts_tmp_tmp * (b_Ts_tmp_tmp_tmp * (-x[11] * (t47 + eb_Ts_tmp) +
    b_Ts_tmp_tmp_tmp * ((x_Ts_tmp + a_tmp_tmp_tmp_tmp_tmp * t23) + t25 *
                        f_Ts_tmp_tmp_tmp)) - t17_tmp * t32))) + g_Ts_tmp * (t214
              * t32 * Ts_tmp + t213)) + a_tmp_tmp * (g_Ts_tmp * p_Ts_tmp_tmp_tmp
             + 2.0 * t161 * (t292 + t157))) - t182 * ((x[11] * (t273 + t133) +
             b_Ts_tmp_tmp_tmp * ((-t22 * f_Ts_tmp_tmp_tmp - o_Ts_tmp) +
              kb_Ts_tmp * (t104 * f_Ts_tmp_tmp_tmp + t105))) * b_Ts_tmp_tmp_tmp
            - t279)) - t231 * (t334 * t334))) - hb_Ts_tmp * t322;
  x_Ts_tmp = g_Ts_tmp_tmp_tmp * t514 + m_Ts_tmp_tmp_tmp * o_Ts_tmp_tmp_tmp;
  p_Ts_tmp_tmp_tmp = Ts_tmp_tmp * (b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp *
    ((-g_Ts_tmp_tmp_tmp * t505 + t27 * b_Ts_tmp_tmp) + kb_Ts_tmp * t284) - t121)
    - b_Ts_tmp_tmp * -t270);
  t514 = Ts_tmp_tmp * (f_Ts_tmp * ((Ts_tmp * (-t21 * g_Ts_tmp_tmp_tmp +
    o_Ts_tmp_tmp_tmp * t11) + k_Ts_tmp_tmp_tmp * -t270) + 1.3333333333333333 *
    b_Ts_tmp_tmp_tmp * (-t669_tmp * t284 + t121)) * 3.0 - b_Ts_tmp_tmp_tmp * (((
    -g_Ts_tmp * d_Ts_tmp_tmp * t270 + 2.0 * t161 * t382) + w_Ts_tmp) - t306));
  w_Ts_tmp = g_Ts_tmp * ((g_Ts_tmp_tmp_tmp * t491 - t159 * o_Ts_tmp_tmp_tmp *
    4.0 * x[11] * e_Ts_tmp_tmp_tmp) + t276 * t159 * Ts_tmp * 4.0);
  t47 = (t168 * t340 + t187 * (-t166 * ((e_Ts_tmp * (b_Ts_tmp * (Ts_tmp *
              ((-t110 * g_Ts_tmp_tmp_tmp + b_t298_tmp) + t564) + t572) * 3.0 +
             t682) - a_tmp_tmp * (w_Ts_tmp - 2.0 * t495 * (t215 + t667))) + t418)
          + (n3p * (2.0 * (e_Ts_tmp * (t135_tmp * (Ts_tmp_tmp_tmp *
    (b_Ts_tmp_tmp_tmp * (-x[11] * x_Ts_tmp + t692) + t184) + p_Ts_tmp_tmp_tmp) +
              t388) - t327) + t514) - n3ppp * t6) * t229 * t225)) * t141_tmp *
    t125_tmp;
  t597 = b_Ts_tmp_tmp_tmp * (e_Ts_tmp_tmp_tmp * (-g_Ts_tmp_tmp_tmp * t467 + t391
    * g_Ts_tmp) + b_Ts_tmp_tmp_tmp * (g_Ts_tmp_tmp_tmp * t465 + h_Ts_tmp_tmp *
    n3p));
  t63 = t509 * ((n3pp * t162 + t287 * t334) - t297 * (2.0 * t198 *
    (Ts_tmp_tmp_tmp * (-(t597 + t158) * b_Ts_tmp_tmp_tmp + t409) + Ts_tmp_tmp *
     ((b_Ts_tmp_tmp_tmp * ((t397 + t310) + t384) - t275_tmp) * b_Ts_tmp_tmp_tmp
      - t385)) + Ts_tmp_tmp * (f_Ts_tmp * (-b_Ts_tmp_tmp_tmp * t206 - t426) *
    3.0 + t454)));
  t68 += -t77;
  t382 = b_Ts_tmp_tmp_tmp * t68;
  t73 = f_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (-t382 + t175)
    - t350) + t383);
  t77 = Ts_tmp_tmp_tmp * t73;
  t79 = (2.0 * t198 * (t77 + t390) + t389) - t392;
  t92 = t218 * t399 * t187 - 3.0 * t79;
  t105 = -x[13] * d_Ts_tmp_tmp_tmp + gb_Ts_tmp * i_Ts_tmp_tmp_tmp;
  t22_tmp = g_Ts_tmp * f_Ts_tmp_tmp_tmp;
  b_t22_tmp = Ts_tmp_tmp * f_Ts_tmp_tmp_tmp;
  c_t22_tmp = -t725 + t345_tmp * h_Ts_tmp_tmp_tmp;
  t22 = t509 * ((((t187 * (-t216 * (-Ts_tmp_tmp * f_Ts_tmp_tmp_tmp * c_t22_tmp +
    t31 * Ts_tmp_tmp_tmp) + t399 * (t393 - t79)) + 2.0 * t198 * (j_Ts_tmp *
    (b_Ts_tmp_tmp_tmp * (-x[11] * t89 + b_Ts_tmp_tmp_tmp * (e_Ts_tmp_tmp_tmp *
    t78 - b_Ts_tmp_tmp_tmp * (t67 * i_Ts_tmp_tmp_tmp + t69))) + t345_tmp *
     t17_tmp * h_Ts_tmp_tmp_tmp) + b_t22_tmp * ((t17_tmp * d_Ts_tmp_tmp_tmp *
    c_Ts_tmp_tmp_tmp + t38_tmp * t378 * d_Ts_tmp_tmp_tmp) - t25 * Ts_tmp))) -
                  t22_tmp * (t214 * d_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp * Ts_tmp
    + t378_tmp * Ts_tmp_tmp_tmp * d_Ts_tmp_tmp)) - a_tmp_tmp * (2.0 * t368 *
    (t376_tmp * m_Ts_tmp_tmp + t140) + t153_tmp * g_Ts_tmp)) + t182 * (-t364 *
    (b_Ts_tmp_tmp_tmp * (-kb_Ts_tmp * t104 + t22) + t134 * x[11]) - t417 * t31))
    - t231 * (t399 * t399);
  t25 = -t267 * i_Ts_tmp_tmp_tmp * Ts_tmp - t624 * (b_Ts_tmp_tmp_tmp * (t43 *
    Ts_tmp - t46) - t100);
  t78 = t173 * x[11];
  t104 = Ts_tmp_tmp_tmp * i_Ts_tmp_tmp * (b_Ts_tmp_tmp_tmp * (x[11] * t91 +
    b_Ts_tmp_tmp_tmp * (-t38_tmp * f_Ts_tmp_tmp + t72_tmp * t67)) + t72_tmp *
    t17_tmp);
  t161 = (-b_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp * (t306_tmp * t148 + t435 * t83) +
          f_Ts_tmp * (t78 * (jb_Ts_tmp * 1.3333333333333333 * t53 -
            0.66666666666666663 * g_Ts_tmp_tmp) + t58 * (x[11] * t132 - t123 *
            b_Ts_tmp_tmp_tmp)) * 3.0) * Ts_tmp_tmp;
  t213 = Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp;
  t214 = i_Ts_tmp_tmp * (t72_tmp * Ts_tmp_tmp + t213);
  t267 = t216 * t214;
  t340 = t56 * t399;
  t350 = g_Ts_tmp * t373;
  t353 = t391 * t378_tmp;
  t368 = l_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp;
  t373 = t463 * d_Ts_tmp_tmp_tmp * g_Ts_tmp;
  t381 = t368 + t373;
  t384 = ib_Ts_tmp * g_Ts_tmp;
  t84 = Ts_tmp_tmp_tmp * (-t364 * (b_Ts_tmp_tmp_tmp * (e_Ts_tmp_tmp_tmp * 2.0 *
    t358 - b_Ts_tmp_tmp_tmp * t381) - t181) - t384 * (t394 * 2.0 + t14_tmp * 1.5));
  t315 = t398 * t315 * m_Ts_tmp_tmp;
  t389 = (Ts_tmp - 1.0) * i_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp - t194 *
    d_Ts_tmp_tmp_tmp;
  t390 = f_Ts_tmp_tmp_tmp * Ts_tmp;
  t391 = t159 * t58;
  t91 = (-2.0 * t198 * (t711 * t278 * Ts_tmp_tmp_tmp * g_Ts_tmp + ib_Ts_tmp *
                        t389 * Ts_tmp_tmp * t376_tmp) - a_tmp_tmp * (-2.0 * t391
          * (t91 - t90) + t22_tmp * (t160 * 4.0 * d_Ts_tmp_tmp_tmp * Ts_tmp -
           t159 * (-m_Ts_tmp * 2.0 + t339)))) + e_Ts_tmp * (t437 * h_Ts_tmp_tmp *
    m_Ts_tmp_tmp * Ts_tmp + b_Ts_tmp * (-t108 * t725 * o_Ts_tmp_tmp_tmp *
    g_Ts_tmp + t390 * ((-t345_tmp * t108 * g_Ts_tmp - b_Ts_tmp_tmp_tmp * t359) +
                       t45 * i_Ts_tmp_tmp_tmp)) * 3.0);
  t108 = t372 / 2.0;
  t398 = t432 * c_Ts_tmp_tmp_tmp;
  t151 = 2.0 * t364 * t151 * M[0] * t396_tmp;
  t360 = f_Ts_tmp * (-1.3333333333333333 * b_Ts_tmp_tmp_tmp * t20 * (-Ts_tmp +
    1.0) * o_Ts_tmp_tmp_tmp + f_Ts_tmp_tmp_tmp * (Ts_tmp * (-t360 *
    m_Ts_tmp_tmp_tmp + t252 * i_Ts_tmp_tmp_tmp) + k_Ts_tmp_tmp_tmp *
    c_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp)) * 3.0;
  t65 = Ts_tmp_tmp_tmp * ib_Ts_tmp;
  t346 = 2.0 * (t387 * f_Ts_tmp_tmp_tmp + e_Ts_tmp * (t135_tmp * (t65 *
    (-b_Ts_tmp_tmp_tmp * ((k_Ts_tmp_tmp * Ts_tmp - t346) - t398) + t43_tmp *
     g_Ts_tmp_tmp * (-Ts_tmp + 1.0)) + b_t22_tmp * ((-Ts_tmp * x[11] * (t108 +
    t371) + t20 * h_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp * (Ts_tmp - 1.0)) + t726 *
    i_Ts_tmp_tmp_tmp)) - t699 * h_Ts_tmp_tmp * i_Ts_tmp_tmp_tmp));
  t387 = f_Ts_tmp * (Ts_tmp_tmp * (t65 * b_Ts_tmp_tmp_tmp * t389 * Ts_tmp_tmp -
    t364 * (t669_tmp * d_Ts_tmp_tmp_tmp + t43_tmp * (j_Ts_tmp_tmp_tmp *
    b_Ts_tmp_tmp_tmp - fb_Ts_tmp))) + h_Ts_tmp_tmp * (-t351 * e_Ts_tmp_tmp_tmp *
    t135_tmp + m_Ts_tmp_tmp * Ts_tmp_tmp_tmp * Ts_tmp));
  t389 = t180 * (h_Ts_tmp_tmp * (b_Ts_tmp - 1.0) * i_Ts_tmp_tmp_tmp * Ts_tmp +
                 Ts_tmp_tmp_tmp * t390 * t396_tmp * Ts_tmp_tmp);
  t396 = i_Ts_tmp_tmp * (t10 * c_Ts_tmp_tmp_tmp - t342);
  t252 = h_Ts_tmp_tmp * n_Ts_tmp_tmp;
  t339 = d_Ts_tmp_tmp_tmp * t32;
  t69 = t339 - t252;
  t587 = 2.0 * n_Ts_tmp;
  t604 = a_tmp_tmp_tmp_tmp_tmp * 2.0;
  t75 = t604 * i_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp;
  t618 = f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp * (4.0 - t587) * l_Ts_tmp - t75);
  t622 = a_tmp_tmp_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp;
  t629 = d_Ts_tmp_tmp_tmp * (n_Ts_tmp - 0.5);
  t645 = i_Ts_tmp_tmp * (t629 * f_Ts_tmp_tmp_tmp + t622);
  t321 = d_Ts_tmp_tmp_tmp * t12;
  t651 = -(d_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp) + n_Ts_tmp_tmp;
  t654 = n3p * t651;
  t705 = 2.0 * t654;
  t706 = -4.0 * t90 * t651;
  t708 = d_Ts_tmp_tmp_tmp * t599;
  t711 = 4.0 * g_Ts_tmp_tmp_tmp;
  t712 = t47_tmp * t651;
  t89 = t462 / 2.0;
  t392 = h_Ts_tmp * d_Ts_tmp_tmp_tmp;
  t725 = t100 * t651;
  t726 = l_Ts_tmp_tmp_tmp * t651;
  t728_tmp = t321 + o_Ts_tmp_tmp_tmp * n_Ts_tmp_tmp;
  t65 = -t339 + t252;
  t356 = 4.0 * t384 * t728_tmp + 8.0 * b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp *
    (t62 * f_Ts_tmp_tmp_tmp * t65 - f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp *
    ((0.75 * t725 - t392 * (n_Ts_tmp + 1.0) / 2.0) + j_Ts_tmp_tmp * t48 *
     t345_tmp * g_Ts_tmp) + q_Ts_tmp_tmp_tmp * (t432 * g_Ts_tmp / 2.0 -
    c_Ts_tmp_tmp_tmp * ((t398 * g_Ts_tmp + t368 / 4.0) - 0.375 * t47_tmp *
                        d_Ts_tmp_tmp_tmp)))) - f_Ts_tmp_tmp_tmp *
    (f_Ts_tmp_tmp_tmp * (-e_Ts_tmp_tmp_tmp * ((0.25 * t726 + 0.75 * t464 *
    d_Ts_tmp_tmp_tmp) + t608 * n_Ts_tmp) - t43 * t651 / 2.0) + g_Ts_tmp_tmp_tmp *
     (t72_tmp * (-t357 * 2.0 - t356) + t344) / 2.0));
  t464 = Ts_tmp_tmp_tmp * t69;
  t356 = (t399 * t680_tmp * t229 * t225 + t197 * t399) + t662 * ((4.0 * t376_tmp
    * (t464 * x[12] * f_Ts_tmp_tmp_tmp + x[11] * (2.0 * (-t396 * Ts_tmp + t396)
    + t343 * t69) * t177) + ((Ts_tmp_tmp * (Ts_tmp_tmp_tmp * t356 + Ts_tmp_tmp *
    (-4.0 * t384 * e_Ts_tmp_tmp_tmp * t69 - (b_Ts_tmp_tmp_tmp *
    (b_Ts_tmp_tmp_tmp * (t62 * 2.0 * t618 - f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp
    * (c_Ts_tmp_tmp_tmp * (t101 * 16.0 * i_Ts_tmp_tmp_tmp + t705) + t706) - t711
    * (t263 * (t600 + -2.0) + t708))) - f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp *
    (t643 * (-n_Ts_tmp * 16.0 - 4.0) * g_Ts_tmp - t119 * e_Ts_tmp_tmp_tmp * (t89
    * i_Ts_tmp_tmp_tmp - t712)) + t612 * ((t611 * h_Ts_tmp * e_Ts_tmp_tmp_tmp +
    e_Ts_tmp_tmp_tmp * (-h_Ts_tmp / 8.0 - t101 / 2.0)) - t720 * j_Ts_tmp_tmp)))
    - f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp * (-12.0 * t101 *
    i_Ts_tmp_tmp_tmp + t705) + t706) - t711 * (t263 * t621 + t708))) *
     b_Ts_tmp_tmp_tmp)) - 4.0 * g_Ts_tmp * (ib_Ts_tmp * e_Ts_tmp_tmp_tmp * t65 +
    t669_tmp * f_Ts_tmp_tmp_tmp * (-f_Ts_tmp_tmp_tmp * l_Ts_tmp * (t587 + 3.0) -
    t75))) + 6.0 * t364 * (-n_Ts_tmp_tmp * t15 * f_Ts_tmp_tmp_tmp +
    d_Ts_tmp_tmp_tmp * t220)) * Ts_tmp_tmp) - t16 * (e_Ts_tmp_tmp_tmp * (4.0 *
    t645 + Ts_tmp * t618) - 2.0 * t364 * (o_Ts_tmp_tmp_tmp * (Ts_tmp - 1.0) *
    n_Ts_tmp_tmp + t321 * (Ts_tmp - 1.0))) * Ts_tmp_tmp_tmp * t59_tmp) * t227 *
    t224;
  t220 = 2.0 * e_Ts_tmp * (t135_tmp * (-t25 * Ts_tmp_tmp + t104) + t699 *
    t378_tmp * o_Ts_tmp_tmp_tmp);
  t397 = f_Ts_tmp * (t554 * (1.3333333333333333 * f_Ts_tmp_tmp_tmp * (-t350 *
    Ts_tmp + t378_tmp * (j_Ts_tmp_tmp_tmp * t53 + fb_Ts_tmp)) + t58 * -t129) +
                     t315);
  t342 = -b_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp * (t149 + t378_tmp *
    c_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp) + t151) + t360;
  t22 = ((((2.0 * t509 * ((n3pp * t387 + t287 * t399) + t297 * (2.0 * t198 *
              (Ts_tmp_tmp * (-t364 * (-b_Ts_tmp_tmp_tmp * t350 + t378 *
    i_Ts_tmp_tmp_tmp) - t353) + t84) + t397)) + x[11] * (t97 * ((t187 * ((t118 *
    t399 + t205 * t79) + t403) + t156_tmp * ((2.0 * t198 * (Ts_tmp_tmp_tmp *
    (-t352 + t343 * (-t382 * 3.0 + t354)) + t376) + t111) + t377)) + t156_tmp *
              t92 * t147_tmp * e_Ts_tmp_tmp_tmp) + t405)) + x[12] * (t509 *
            ((((t187 * ((t216 * t_Ts_tmp + u_Ts_tmp) - t253_tmp * t79) - 6.0 *
                t245 * (-t77 * Ts_tmp_tmp + t386)) - t248) + t198 * (-t246 * t73
    + t370)) + t254 * t92) - v_Ts_tmp)) + hb_Ts_tmp * t22) - t6_tmp * (((-t105 *
            t239 - gb_Ts_tmp * (t509 * ((t187 * ((t399 * t449 - t452_tmp * t79)
    - t267) - t220) + t161) - t340)) - t264 * (t509 * ((((t187 * ((t330 * t399 +
    t334 * t79) - t309) + 2.0 * t198 * (lb_Ts_tmp * (b_Ts_tmp_tmp_tmp * (-x[11] *
    t181 + b_Ts_tmp_tmp_tmp * (t175 - t382)) + t383) + Ts_tmp_tmp *
    g_Ts_tmp_tmp_tmp * ((t223 + t380) + t351 * (t374 + t41)))) - a_tmp_tmp *
    (2.0 * t307 * (t366_tmp - t365) - g_Ts_tmp * t149 * g_Ts_tmp_tmp_tmp)) -
              t308) + t182 * (q_Ts_tmp * (b_Ts_tmp_tmp_tmp * (kb_Ts_tmp * t359 -
    t362) + t129 * i_Ts_tmp_tmp_tmp * x[11]) - t299)) + t318)) + (-t239 * t264 +
           gb_Ts_tmp * t322) * t6_tmp * d_Ts_tmp_tmp_tmp)) - (t168 * t356 + t187
    * (t166 * t91 + (-n3p * (Ts_tmp_tmp * t342 - t346) + n3ppp * t389) * t229 *
       t225)) * t141_tmp * t125_tmp;
  t24 = 2.0 * e_Ts_tmp * t234 - t448;
  t68 = t218 * t452_tmp * t187 - 3.0 * t24;
  t70 = e_Ts_tmp_tmp_tmp * t156_tmp;
  t73 = t139 * d_Ts_tmp_tmp_tmp + t282;
  t77 = t439 * t12;
  t92 = b_t59_tmp * Ts_tmp_tmp;
  t344 = t92 + t186_tmp;
  t18 = -t231 * (t452_tmp * t452_tmp) + t509 * ((t187 * (-t216 * t344 + t452_tmp
    * (t449 - t24)) + 2.0 * e_Ts_tmp * (t135_tmp * (Ts_tmp_tmp_tmp *
    (b_Ts_tmp_tmp_tmp * (x[11] * (t301 * d_Ts_tmp_tmp_tmp - p_Ts_tmp) +
    b_Ts_tmp_tmp_tmp * (t271_tmp * t94_tmp - b_t59_tmp * t67)) - db_Ts_tmp) +
    Ts_tmp_tmp * (-t144 * t18 * t32 + x[11] * (b_Ts_tmp_tmp_tmp *
    ((g_Ts_tmp_tmp_tmp * t46 + eb_Ts_tmp) - t77) + t47_tmp * t32))) - t133_tmp *
    t32 * Ts_tmp)) + Ts_tmp_tmp * (-b_Ts_tmp_tmp_tmp * (t250 * t32 + t435 * t419)
    + f_Ts_tmp * ((-1.3333333333333333 * -t95_tmp * x[12] * t53 +
                   b_Ts_tmp_tmp_tmp * (x[11] * (n_Ts_tmp_tmp_tmp * t131 + t273)
    + b_Ts_tmp_tmp_tmp * (-t124 * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp - o_Ts_tmp)))
                  - t279) * 3.0));
  t67 = t62 * t32;
  t124 = t425 * Ts_tmp;
  t708 = -b_t174_tmp * Ts_tmp + b_t174_tmp;
  t45 = (2.0 * t198 * (y_Ts_tmp * t708 + t498_tmp * t489 * b_Ts_tmp_tmp_tmp) -
         a_tmp_tmp * (2.0 * t495 * (x[12] * t486 + t433) - t437 * t159 *
                      b_t59_tmp * x[11])) + e_Ts_tmp * (t77 * 4.0 + b_Ts_tmp * (
    -1.3333333333333333 * b_Ts_tmp_tmp_tmp * (t420_tmp - t124) + Ts_tmp * (-t114
    * d_Ts_tmp_tmp_tmp * f_Ts_tmp_tmp_tmp + g_Ts_tmp_tmp_tmp * t45)) * 3.0);
  t77 = x[12] * t32;
  t114 = t669_tmp * t32;
  t231 = t33 * x[12];
  t77 = 2.0 * e_Ts_tmp * (t135_tmp * (Ts_tmp_tmp_tmp * (e_Ts_tmp_tmp_tmp *
    (t541_tmp * Ts_tmp - t541_tmp) + t38_tmp * -t526) + Ts_tmp_tmp * (x[11] *
    (b_Ts_tmp_tmp_tmp * (-t114 + t77) - t94_tmp) + t144 * t512)) + t699 * t12) +
    Ts_tmp_tmp * (-b_Ts_tmp_tmp_tmp * ((t472_tmp * d_Ts_tmp_tmp + t435 * t231) -
    t434) + f_Ts_tmp * ((t12 * t11 * Ts_tmp - 1.3333333333333333 *
    b_Ts_tmp_tmp_tmp * (x[11] * t77 - t669_tmp * t413_tmp)) + k_Ts_tmp_tmp_tmp *
                        t12) * 3.0);
  t121 = f_Ts_tmp * (Ts_tmp_tmp * (Ts_tmp_tmp * (t361 * (t413_tmp - t413_tmp *
    Ts_tmp) + t701 * b_t59_tmp) - b_Ts_tmp_tmp_tmp * (x[11] * b_t59_tmp -
    b_Ts_tmp_tmp_tmp * t231)) - t450 * t669_tmp);
  t248 = t180 * Ts_tmp;
  t249 = t248 * (Ts_tmp_tmp * t623_tmp - t12);
  t250 = h_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp;
  t321 = -n_Ts_tmp + t250;
  t279 = t260 * t321;
  t282 = t583 * 4.0;
  t75 = n_Ts_tmp - t250;
  t287 = (t75 - t279) - t282;
  t299 = -f_Ts_tmp_tmp_tmp * t321 * g_Ts_tmp_tmp_tmp * d_Ts_tmp_tmp_tmp + t574;
  t301 = -n_Ts_tmp_tmp / 2.0 + 1.0;
  t302 = fb_Ts_tmp * g_Ts_tmp * t301;
  t307 = t183 * c_Ts_tmp_tmp_tmp;
  t308 = f_Ts_tmp_tmp / 2.0;
  t309 = t308 * i_Ts_tmp_tmp_tmp;
  t318 = t47_tmp * t321;
  t351 = -t462 + t263;
  t356 = t38 * c_Ts_tmp_tmp_tmp;
  t362 = t69_tmp * e_Ts_tmp_tmp_tmp;
  t365 = t113 * 2.0;
  t370 = t720 * c_Ts_tmp_tmp_tmp;
  t252 = f_Ts_tmp_tmp * t301 * c_Ts_tmp_tmp_tmp;
  t177 = t662 * ((4.0 * t376_tmp * (-t450 * t155 + x[11] * (((((-b_t59_tmp * t58
    + t287 * Ts_tmp) + t250) + t279) + t282) - n_Ts_tmp) * t177) + ((Ts_tmp_tmp *
    (Ts_tmp_tmp_tmp * (8.0 * (((b_Ts_tmp_tmp_tmp * ((((t157 * t12 - ab_Ts_tmp *
    (t362 * (n_Ts_tmp_tmp - 2.0) * t321 + c_Ts_tmp_tmp_tmp * (-t203 *
    (n_Ts_tmp_tmp - 2.0) + 0.75 * t608))) - t362 * t321) - q_Ts_tmp_tmp_tmp *
    (d_Ts_tmp_tmp_tmp * (-t611 * n3p + t365) - t221 * h_Ts_tmp_tmp_tmp) *
    f_Ts_tmp_tmp_tmp) + t308 * h_Ts_tmp_tmp_tmp) - (-l_Ts_tmp * t40 / 4.0 +
    t306_tmp * (t643 / 2.0 - t120)) * ab_Ts_tmp) - t100 * e_Ts_tmp_tmp_tmp *
    ((1.0 - c_Ts_tmp_tmp_tmp) - (c_Ts_tmp_tmp_tmp + 1.0)) / 2.0) -
    g_Ts_tmp_tmp_tmp * ((-t463 * t345_tmp * g_Ts_tmp * n_Ts_tmp - t143 *
    h_Ts_tmp_tmp_tmp) - t370) * f_Ts_tmp_tmp_tmp / 2.0) * b_Ts_tmp_tmp_tmp + t14)
     + Ts_tmp_tmp * (4.0 * g_Ts_tmp * (t299 * x[12] * t52 + t94_tmp * t204) +
                     ((b_Ts_tmp_tmp_tmp * (((b_Ts_tmp_tmp_tmp * (8.0 * t318 +
    f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp * ((t302 * 16.0 * c_Ts_tmp_tmp_tmp -
    t179 * h_Ts_tmp_tmp_tmp) - t307) - t711 * (t306_tmp * (-t424 * 8.0 + t432) -
    t309))) - 2.0 * Ts_tmp_tmp_tmp_tmp * t321) + ab_Ts_tmp * (-8.0 *
    e_Ts_tmp_tmp_tmp * (t252 / 2.0 - t219 * h_Ts_tmp_tmp_tmp) - t38 * 16.0 *
    (n_Ts_tmp_tmp - 2.0) * c_Ts_tmp_tmp_tmp)) + 16.0 * (g_Ts_tmp_tmp_tmp *
    (t72_tmp * t351 / 2.0 + t341 * t321) * f_Ts_tmp_tmp_tmp - t356)) - t318 *
                       6.0) + f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp * ((-12.0 *
    t302 * c_Ts_tmp_tmp_tmp - t178 * h_Ts_tmp_tmp_tmp) - t307) - t711 *
    (t306_tmp * (t424 * 6.0 + t432) - t309))) * b_Ts_tmp_tmp_tmp)) + t721 * t299)
    + i_Ts_tmp_tmp * (-t94_tmp * t437 * e_Ts_tmp_tmp_tmp - b_Ts_tmp_tmp_tmp *
                      (g_Ts_tmp_tmp_tmp * t15 + t51 * d_Ts_tmp_tmp_tmp) * 6.0)) *
                  Ts_tmp_tmp) - t16 * (-2.0 * b_Ts_tmp_tmp_tmp * (t194 * t299 +
    t172 * (Ts_tmp - 1.0)) + t717 * t299) * Ts_tmp_tmp_tmp * t59_tmp) * t227 *
    t224;
  t18 = gb_Ts_tmp * t18 + t264 * (t509 * ((t187 * ((t24 * t334 + t330 * t452_tmp)
    - t369) - 2.0 * e_Ts_tmp * (t135_tmp * (-Ts_tmp_tmp * (-x[11] *
    (b_Ts_tmp_tmp_tmp * ((g_Ts_tmp_tmp_tmp * t408_tmp + t323) + t48_tmp) + t324)
    + t325) + t303) - t319)) + Ts_tmp_tmp * (-b_Ts_tmp_tmp_tmp * (-t435 * t73 -
    t363) + f_Ts_tmp * ((b_Ts_tmp_tmp_tmp * (x[11] * (-t132 * d_Ts_tmp_tmp_tmp *
    g_Ts_tmp_tmp_tmp - t328) - t329) - t332) + t337) * 3.0)) + t379);
  t413 = (-t95_tmp * 2.0 - (b_Ts_tmp_tmp_tmp * (t67 + -t95_tmp) - t410) *
          b_Ts_tmp_tmp_tmp) * Ts_tmp_tmp + Ts_tmp_tmp_tmp * (2.0 *
    e_Ts_tmp_tmp_tmp * (-t420_tmp + t124) + b_Ts_tmp_tmp_tmp * (n3p * t32 *
    Ts_tmp - t419));
  t620 = Ts_tmp_tmp * (f_Ts_tmp * (1.3333333333333333 * (Ts_tmp * (kb_Ts_tmp *
    b_t174_tmp + -t95_tmp) + t95_tmp) + b_Ts_tmp_tmp_tmp * t430) * 3.0 + t207 *
                       t160 * b_t59_tmp);
  t18 = ((((-2.0 * (t509 * ((n3pp * t121 + t288 * t452_tmp) - t297 * (2.0 * t198
    * t413 + t620))) + x[11] * (-t137 * (t147_tmp * ((t156_tmp * (((-t202 *
    t452_tmp * t187 - 2.0 * t198 * (Ts_tmp_tmp_tmp * ((x[11] * t419 *
    e_Ts_tmp_tmp_tmp - t421) + t194 * (-3.0 * t416 * b_Ts_tmp_tmp_tmp + t423)) +
    t42)) - t438) - e_Ts_tmp * (3.0 * (e_Ts_tmp_tmp_tmp * (-t430 * x[11] + t13)
    - t407) * b_Ts_tmp - t316)) - t70 * t68 * t147_tmp) - t205 * t24 * t187) +
              t453) + t455)) + x[12] * (-t56 * t253_tmp + t509 * ((((t187 *
    ((-t24 * t253_tmp + t174) + t37) - t262) - t436) + t443) + t254 * t68))) +
          hb_Ts_tmp * (t509 * ((t187 * ((-t24 * t399 + t393 * t452_tmp) - t267)
             - t220) + t161) - t340)) + t6_tmp * t18) + (t168 * ((-t452_tmp *
    t680_tmp * t229 * t225 - t197 * t452_tmp) - t177) + t187 * ((n3p * t77 -
    n3ppp * t249) * t229 * t225 - t166 * t45)) * t141_tmp * t125_tmp;
  t25 = -(b_Ts_tmp_tmp_tmp * (-t199 - t164) + t49) * b_Ts_tmp_tmp_tmp - t476;
  t48 = -2.0 * t198 * (t25 * Ts_tmp_tmp + t473) + Ts_tmp_tmp * (-f_Ts_tmp * t468
    * 3.0 - t481);
  t68 = -3.0 * t48;
  t48 *= t187;
  t104 = Ts_tmp_tmp_tmp * t486;
  t339 = -t204 + t205_tmp;
  t132 = 4.0 * Ts_tmp_tmp * (t376_tmp * t159 * t33 + f_Ts_tmp * b_Ts_tmp_tmp_tmp
    * (t58 * e_Ts_tmp_tmp_tmp * g_Ts_tmp + t472_tmp * (-Ts_tmp + 1.0))) - 2.0 *
    t198 * (r_Ts_tmp * (t376_tmp * t339 - t472_tmp) + t104 * b_Ts_tmp_tmp_tmp);
  t134 = Ts_tmp * t94_tmp - t94_tmp;
  t65 = (b_Ts_tmp_tmp_tmp * (t153 + t535) - t508) * b_Ts_tmp_tmp_tmp;
  t137 = 4.0 * Ts_tmp_tmp * (t480 - f_Ts_tmp * (t65 - t413_tmp)) + 2.0 * t198 *
    (Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (t86 * f_Ts_tmp_tmp_tmp + t516) - 2.0 *
                       (t134 * e_Ts_tmp_tmp_tmp + t624 * t53)) + Ts_tmp_tmp *
     (t65 - t413_tmp * 2.0));
  t177 = t180 * ((b_Ts_tmp - 1.0) * t33 * b_Ts_tmp_tmp_tmp + Ts_tmp_tmp_tmp *
                 (b_Ts_tmp_tmp_tmp * t339 - t12) * b_Ts_tmp_tmp_tmp * Ts_tmp_tmp);
  t197 = t306_tmp * t301;
  t201 = -t629 * g_Ts_tmp;
  t267 = t173 * t33;
  t273 = t173 * t12;
  t279 = e_Ts_tmp_tmp_tmp / 2.0;
  t65 = gb_Ts_tmp * t509;
  t610 = t264 * t509;
  t123 = (t168 * (t662 * ((-4.0 * t475_tmp * (-b_Ts_tmp_tmp_tmp * t576 * t59_tmp
              + t578) + b_Ts_tmp * (Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (-8.0 *
    (-f_Ts_tmp_tmp_tmp * (-f_Ts_tmp_tmp_tmp * e_Ts_tmp_tmp_tmp * (-0.75 *
    g_Ts_tmp * (-n_Ts_tmp_tmp - 0.66666666666666663) + t634 * (n_Ts_tmp_tmp -
    2.0) * g_Ts_tmp) + t622 * t345_tmp * g_Ts_tmp) - t279 * (1.0 -
    c_Ts_tmp_tmp_tmp) * (c_Ts_tmp_tmp_tmp + 1.0) * g_Ts_tmp) + t273 * 6.0 *
    b_Ts_tmp_tmp_tmp) - t273 * 4.0) + Ts_tmp_tmp * ((b_Ts_tmp_tmp_tmp * ((Ts_tmp
    * (c_Ts_tmp_tmp_tmp * (t197 * ab_Ts_tmp * 16.0 - t306_tmp * 8.0) + t711 *
       4.0 * t201 * f_Ts_tmp_tmp_tmp) + c_Ts_tmp_tmp_tmp * (-12.0 * t197 *
    ab_Ts_tmp + t306_tmp * 6.0)) - t711 * 3.0 * t201 * f_Ts_tmp_tmp_tmp) + 8.0 *
    t267 * Ts_tmp) + t717 * t173 * t32))) - t376_tmp * 2.0 * t247 *
            Ts_tmp_tmp_tmp * t59_tmp) * t227 * t224 - t675) + t187 * (t225 *
           (t229 * (-n3p * t137 - t202) - e_Ts_tmp_tmp_tmp * t218 * t227) + t166
           * t132)) * t141_tmp * t125_tmp;
  t139 = x[12] * Ts_tmp_tmp_tmp;
  t148 = t254 * x[11];
  t202 = t674 * t187;
  t275 = t229 * t156_tmp;
  t220 = hb_Ts_tmp * t509;
  t176 = x[11] * t97;
  t305 = x[12] * t509;
  t24 = ((((-2.0 * t275 * t187 * (t202 * x[11] + ((n3pp * t177 * t174_tmp - t139
    * (x[11] * (2.0 * t198 * (Ts_tmp_tmp_tmp * (-2.0 * (e_Ts_tmp_tmp_tmp *
    (t472_tmp * Ts_tmp - t472_tmp) + t483) + t519 * g_Ts_tmp) + Ts_tmp_tmp *
    (b_t174_tmp * Ts_tmp - b_t174_tmp * 2.0)) + t180 * 4.0 * t708) + t482) *
    t225) + t148 * t440) * t141_tmp * t125_tmp) + t176 * (t156_tmp *
             (((e_Ts_tmp_tmp_tmp * t68 * t147_tmp + 2.0 * t198 * (Ts_tmp_tmp_tmp
    * (((-t192 - t469) + t470) + t471) + Ts_tmp_tmp * ((t271 - t190) - t194 *
    t55))) - t165) + t142) + t48 * t205)) - t305 * ((((t48 * t253_tmp + 6.0 *
    t245 * t222) - t170) - t198 * (-8.0 * t25 * Ts_tmp_tmp_tmp + t195)) - t254 *
            t68)) - t220 * ((-2.0 * t198 * (Ts_tmp_tmp * (t364 *
              (b_Ts_tmp_tmp_tmp * t350 + i_Ts_tmp_tmp_tmp * (-t374 - t41)) -
              t353) + t84) - t397) + t48 * t399)) - t6_tmp * (t65 * ((-2.0 *
            t198 * t413 - t620) + t48 * t452_tmp) - t610 * ((2.0 * t198 *
            (Ts_tmp_tmp_tmp * (-(t597 - t283) * b_Ts_tmp_tmp_tmp + t409) +
             Ts_tmp_tmp * ((b_Ts_tmp_tmp_tmp * (t422 + t310) - t275_tmp) *
              b_Ts_tmp_tmp_tmp - t385)) + Ts_tmp_tmp * (t454 + f_Ts_tmp *
             (b_Ts_tmp_tmp_tmp * t296 - t426) * 3.0)) + t48 * t334))) - t123;
  t25 = 3.0 * t440;
  t48 = -t440 * t187;
  t68 = b_t174_tmp * 4.0;
  t79 = 6.0 * b_Ts_tmp;
  t84 = 2.0 * t495 * (-b_t59_tmp * x[12] + -t526);
  t123 = 4.0 * t159 * (t458 * e_Ts_tmp_tmp_tmp + t155 * Ts_tmp);
  t103 = e_Ts_tmp * (b_Ts_tmp * (-1.3333333333333333 * b_Ts_tmp_tmp_tmp * t134 +
    Ts_tmp * (f_Ts_tmp_tmp_tmp * (-jb_Ts_tmp * 2.0 * d_Ts_tmp_tmp_tmp + t109 *
    e_Ts_tmp_tmp_tmp) - t604 * x[12])) * 3.0 + t114 * 4.0);
  t109 = 2.0 * t198 * (y_Ts_tmp * (t500 + t12) + t498_tmp * t33 *
                       b_Ts_tmp_tmp_tmp);
  t271 = Ts_tmp_tmp * Ts_tmp;
  t114 = f_Ts_tmp * (t271 * t184_tmp + t559);
  t130 = -t173 * b_t59_tmp;
  t135 = t345_tmp * g_Ts_tmp;
  t165 = -t135 * (n_Ts_tmp - 0.5);
  t170 = t173 * t32;
  t68 = (t168 * (-t216 * t253_tmp * t229 * t225 - t662 * ((Ts_tmp_tmp *
            (Ts_tmp_tmp_tmp * (8.0 * Ts_tmp * ((t574 * e_Ts_tmp_tmp_tmp *
    g_Ts_tmp - q_Ts_tmp_tmp_tmp * t165 * f_Ts_tmp_tmp_tmp) + b_t174_tmp * t58) +
              4.0 * t170 * b_Ts_tmp_tmp_tmp) + Ts_tmp_tmp * (-4.0 * t130 *
              b_Ts_tmp_tmp_tmp * (Ts_tmp + 1.0) - Ts_tmp * ((-g_Ts_tmp *
    (c_Ts_tmp_tmp_tmp * (-t612 * t10 + t119) - 6.0) - ab_Ts_tmp * g_Ts_tmp *
    (t616 * (n_Ts_tmp_tmp - 2.0) + t613)) + t44 * g_Ts_tmp * Ts_tmp))) +
            b_Ts_tmp_tmp_tmp * (i_Ts_tmp_tmp * 6.0 * t489 - t207 * t584)) *
           Ts_tmp_tmp - t68 * t58 * Ts_tmp_tmp_tmp) * t227 * t224) + t187 *
         ((Ts_tmp_tmp_tmp * t218 * t229 * t224 - t166 * b_Ts_tmp_tmp_tmp *
           (-Ts_tmp_tmp * (4.0 * t495 * (-t58 * g_Ts_tmp + t489) - t173 * t159 *
             2.0) + e_Ts_tmp * (-t79 * b_t174_tmp + t68) * b_Ts_tmp_tmp_tmp)) +
          (n3p * ((-a_tmp_tmp * ((-t491 * f_Ts_tmp_tmp_tmp - t123) + t84) + t103)
                  - t109) + t251) * t229 * t225)) * t141_tmp * t125_tmp;
  t166 = t229 * t225;
  t182 = -t239 * d_Ts_tmp_tmp_tmp + t322;
  t190 = g_Ts_tmp_tmp_tmp * t6_tmp;
  t191 = f_Ts_tmp_tmp_tmp * t6_tmp;
  t153 = ((-t153_tmp + t366) - t154) - t349;
  t154 = Ts_tmp_tmp * (b_Ts_tmp_tmp_tmp * t153 - t427) + t150;
  t192 = -3.0 * t154;
  t154 *= t187;
  t195 = g_Ts_tmp_tmp * t301;
  t207 = t646 * t345_tmp * 4.0;
  t282 = jb_Ts_tmp * (n_Ts_tmp_tmp - 2.0);
  t283 = t709 * d_Ts_tmp_tmp_tmp;
  t288 = jb_Ts_tmp * d_Ts_tmp_tmp_tmp;
  t296 = t236 * 2.0;
  t74 = t208 * t74 * ((-a_tmp_tmp * ((-t492 - t123) + t84) + t103) - t109);
  t21 = t65 * (t154 * t452_tmp - t77) - t610 * ((2.0 * (e_Ts_tmp * (t135_tmp * (
    -Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp * (x[11] * x_Ts_tmp - t692) - t184) +
    p_Ts_tmp_tmp_tmp) + t388) - t327) + t514) + t154 * t334);
  t74 = (t74 + (d_Ts_tmp_tmp * t674 + t662 * ((4.0 * b_Ts_tmp_tmp_tmp * t672 +
            ((-4.0 * t669 + t670 * -t526) + Ts_tmp_tmp * (Ts_tmp_tmp_tmp * (8.0 *
    (((b_Ts_tmp_tmp_tmp * (((t72_tmp * j_Ts_tmp_tmp_tmp - ab_Ts_tmp * t628) -
    q_Ts_tmp_tmp_tmp * (-t371 * (n_Ts_tmp - 0.5) - 0.375 * t372) *
    f_Ts_tmp_tmp_tmp) + t531 * t32) - (t644 / 2.0 - 0.75 * e_Ts_tmp_tmp_tmp * x
    [11] * (-n_Ts_tmp_tmp - 0.66666666666666663)) * ab_Ts_tmp) + c_Ts_tmp * (1.0
    - c_Ts_tmp_tmp_tmp) * (c_Ts_tmp_tmp_tmp + 1.0) / 2.0) +
     a_tmp_tmp_tmp_tmp_tmp * (t296 + m_Ts_tmp_tmp) * f_Ts_tmp_tmp_tmp / 2.0) *
    b_Ts_tmp_tmp_tmp - i_Ts_tmp_tmp * t94_tmp * 4.0) + Ts_tmp_tmp *
              (-((b_Ts_tmp_tmp_tmp * ((b_Ts_tmp_tmp_tmp * ((-f_Ts_tmp_tmp_tmp *
    (f_Ts_tmp_tmp_tmp * (t195 * 16.0 * c_Ts_tmp_tmp_tmp - t207) - t711 *
     (k_Ts_tmp_tmp * (t600 + -2.0) - t398)) + t119 * g_Ts_tmp_tmp) + kb_Ts_tmp *
    t44) - x[12] * (t616 + -6.0)) - f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp * (8.0 *
    c_Ts_tmp_tmp_tmp * (t283 + t282) + t613 * x[12]) + t612 * h_Ts_tmp_tmp_tmp *
    (t709 / 2.0 - t288))) - f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp * (-12.0 * t195
    * c_Ts_tmp_tmp_tmp - t207) - t711 * (k_Ts_tmp_tmp * t621 - t398))) -
                 g_Ts_tmp_tmp * 6.0 * c_Ts_tmp_tmp_tmp) * b_Ts_tmp_tmp_tmp +
               t668 * 4.0))) * Ts_tmp_tmp) - t463 * b_Ts_tmp_tmp_tmp * t247 *
           Ts_tmp_tmp_tmp * t59_tmp)) * t227 * t224 * t168) * t141_tmp *
    t125_tmp;
  t77 = 2.0 * t411;
  t84 = t254 * 6.0;
  t109 = t411 * t187;
  t123 = h_Ts_tmp_tmp_tmp * t301;
  t109 = (((2.0 * ((t220 * (t109 * t399 + t387) + t6_tmp * (t65 * (t109 *
    t452_tmp - t121) - t610 * (t109 * t334 + t162))) - t208 * t97 * t114) + t176
            * (t156_tmp * ((e_Ts_tmp_tmp_tmp * t411 * t147_tmp * 6.0 + 2.0 *
    t198 * (Ts_tmp_tmp_tmp * (-x[11] * (-t548 + b_t59_tmp) + t285) - t553_tmp *
            (-e_Ts_tmp_tmp_tmp * t33 + t50))) + t408) - t77 * t187 * t205)) +
           t305 * (t411 * (t558_tmp * 2.0 + t84) + t496)) - t509 * (-t291 +
           (b_Ts_tmp * (t361 * (-2.0 * i_Ts_tmp_tmp * b_t59_tmp - 8.0 *
              (((ab_Ts_tmp * t627 / 4.0 + n_Ts_tmp / 4.0) - 0.25) - t583 / 2.0) *
              b_Ts_tmp_tmp_tmp) + Ts_tmp_tmp * (2.0 * i_Ts_tmp_tmp * t32 *
              b_Ts_tmp_tmp_tmp * (Ts_tmp + 1.0) + Ts_tmp * (t612 * t345_tmp *
    (t611 + -0.125) * f_Ts_tmp_tmp_tmp + t72_tmp * (-ab_Ts_tmp * t123 * 8.0 /
    2.0 + t619)))) - t246 * t58 * t32) * t147_tmp * t187 * t156_tmp * t662)) -
    t511 * t498_tmp * 4.0 * x[12] * t177;
  t121 = t32 * b_Ts_tmp;
  t134 = t565 * t187;
  t77 = (((t176 * (t156_tmp * (2.0 * t180 * (t194 * (t121 - t32) + t478) -
             e_Ts_tmp_tmp_tmp * t565 * t147_tmp * 3.0) + t134 * t205) + x[12] *
           (-t509 * (t558_tmp * t565 - t503) - t518 * 3.0 * t565)) - t220 *
          (t134 * t399 + t389)) - t6_tmp * (t65 * (t134 * t452_tmp + t249) -
          t610 * (t134 * t334 - t6))) + t77 * t509;
  t103 = 1.0 / M[6];
  t145 = x[15] * (M[4] - M[6]);
  t692 = M[4] - M[5];
  t177 = x[14] * t692;
  t182 = t177 * (t191 * t182 - t294 * g_Ts_tmp_tmp_tmp) * t103 - t145 * (t190 *
    t182 + t294 * f_Ts_tmp_tmp_tmp) * t160_tmp;
  t207 = t498_tmp * Ts_tmp_tmp;
  t25 = t207 * (((((-2.0 * t166 * t187 * (t202 * x[12] + (-n3pp * t114 - t148 *
    (t132 * x[12] + t482)) * t141_tmp * t125_tmp) + t176 * (t156_tmp *
    (((e_Ts_tmp_tmp_tmp * t25 * t147_tmp + 2.0 * t198 * (t498_tmp *
    (e_Ts_tmp_tmp_tmp * t486 - t493) + Ts_tmp_tmp * (-x[11] * (-e_Ts_tmp_tmp_tmp
    * t472_tmp + t483) + t485))) + t375) + e_Ts_tmp * (3.0 * (-e_Ts_tmp_tmp_tmp *
    (b_Ts_tmp_tmp_tmp * t487 * 2.0 + t488) + Ts_tmp * (t107 * e_Ts_tmp_tmp_tmp +
    t115)) * b_Ts_tmp - t499)) + t48 * t205)) - t305 * ((-t254 * t25 + t48 *
    t253_tmp) - t237)) - t220 * (t48 * t399 - t91)) + t6_tmp * (-gb_Ts_tmp *
    t509 * (t48 * t452_tmp - t45) + t610 * (((e_Ts_tmp * (b_Ts_tmp * (Ts_tmp *
    ((-t110 * g_Ts_tmp_tmp_tmp + b_t298_tmp) + t564) + t572) * 3.0 + t682) -
    a_tmp_tmp * (w_Ts_tmp - 2.0 * t495 * (t304 + t667))) + t418) + t48 * t334)))
                + t68);
  t25 = ((((((((2.0 * t93 + 6.0 * t257 * t99) - 3.0 * t138 * (t156_tmp *
    t680_tmp + t208 * t440)) + x[11] * ((t97 * t29 + 3.0 * t138 * (t112 * t205 +
    t118)) + t126 * t156_tmp * t229 * (-(t205 * t205) * t233 + t226 * t232 *
    bb_Ts_tmp))) + x[12] * ((3.0 * t257 * ((t218 * t254 + t251) - t255) + t97 *
    (t156_tmp * ((((t187 * (-t200 * t253_tmp - Ts_tmp_tmp_tmp * (t205 * t216 +
    t230)) - 6.0 * t245 * (t196 * Ts_tmp_tmp + t189)) + t167) + t198 * (-8.0 *
    t210 * Ts_tmp_tmp_tmp + t246 * t80)) + t254 * t217) - t26)) + t259 *
              t253_tmp * t205)) + hb_Ts_tmp * ((3.0 * t257 * t404 + t97 * (t187 *
    ((-t200 * t156_tmp * t399 - t205 * t393) + t403) + t156_tmp * ((2.0 * t198 *
    (Ts_tmp_tmp_tmp * (t343 * (-t355 * 3.0 + t354) - t352) + t376) + t377) +
    t111))) + t405)) + t209 * t6_tmp) + t60) - t286 * t125_tmp * t141_tmp * t228
         * t168 * t224 * e_Ts_tmp_tmp_tmp) - t25;
  t18 = gb_Ts_tmp * t18 + t264 * ((((((-2.0 * t63 + x[11] * (-t97 * ((t187 *
    ((t118 * t334 - t205 * t280) - t336) - t156_tmp * ((2.0 * t198 *
    (Ts_tmp_tmp_tmp * ((t253 + t235 * e_Ts_tmp_tmp_tmp) + t194 * (-t288_tmp *
    2.0 + t287_tmp * 3.0)) + Ts_tmp_tmp * ((b_Ts_tmp_tmp_tmp * ((t20 *
    g_Ts_tmp_tmp_tmp * g_Ts_tmp * Ts_tmp + x[11] * t272) + e_Ts_tmp_tmp_tmp *
    t28) + x[11] * t275_tmp * e_Ts_tmp_tmp_tmp) - t284 * t61 * t69_tmp *
    e_Ts_tmp_tmp_tmp)) + Ts_tmp_tmp * (e_Ts_tmp_tmp_tmp * t152 -
    b_Ts_tmp_tmp_tmp * (2.0 * t160 * (e_Ts_tmp_tmp_tmp * t215 - t311) + t312)))
    + e_Ts_tmp * (3.0 * ((b_Ts_tmp_tmp_tmp * (t193 * e_Ts_tmp_tmp_tmp * 2.0 -
    t300) + e_Ts_tmp_tmp_tmp * (-t669_tmp * 3.0 * t298_tmp + t395)) + t209_tmp) *
                  b_Ts_tmp - t317))) + t289 * t156_tmp * t147_tmp *
    e_Ts_tmp_tmp_tmp) - t338)) + x[12] * t146) + hb_Ts_tmp * t320) + t6_tmp *
    t23) + gb_Ts_tmp * t294) + t47);
  t23 = x[14] * x[15];
  t28 = t23 * (M[5] - M[6]) / M[4];
  t29 = t293 * t463;
  t610 = 0.0;
  t60 = t66 * t345_tmp * c_Ts_tmp_tmp_tmp + t20 * g_Ts_tmp;
  u_Ts_tmp = g_Ts_tmp_tmp_tmp * t60 - t27 * e_Ts_tmp_tmp_tmp * n3pp;
  t80 = t462 - t87;
  t91 = b_Ts_tmp_tmp_tmp * t80;
  t93 = Ts_tmp_tmp_tmp * t310;
  t97 = t180 * x[11];
  t71 = -t87 * e_Ts_tmp_tmp_tmp + t408_tmp;
  t87 = g_Ts_tmp_tmp_tmp * t71 + t48_tmp;
  t107 = -t424 * 2.0 - t432;
  t701 = t107 * g_Ts_tmp_tmp_tmp + t463 * o_Ts_tmp_tmp_tmp;
  t111 = t284_tmp * t266;
  y_Ts_tmp = t240 * t701;
  t711 = Ts_tmp_tmp_tmp * t304 + t87 * Ts_tmp_tmp;
  t116 = -2.0 * t97 * t711 + g_Ts_tmp * (-y_Ts_tmp + t111);
  t118 = t326 * d_Ts_tmp_tmp;
  t119 = t177_tmp * t159 * 2.0;
  t132 = t180 * b_Ts_tmp_tmp_tmp;
  t138 = t376_tmp * (-t119 * -t270 + t118);
  t147 = t661 * e_Ts_tmp_tmp_tmp;
  t152 = t266 * Ts_tmp_tmp;
  t158 = t180 * b_Ts_tmp_tmp;
  t118 *= e_Ts_tmp_tmp_tmp;
  t184 = Ts_tmp_tmp * t339;
  t189 = t35 * n3pp;
  t196 = t506 * e_Ts_tmp_tmp_tmp * n3pp;
  t200 = -t60 * f_Ts_tmp_tmp_tmp - t196;
  t72 = t72 * b_Ts_tmp_tmp_tmp - f_Ts_tmp_tmp_tmp * t91;
  t171 += Ts_tmp_tmp * t72;
  t206 = -t171 * 2.0 * t97 - t244 * g_Ts_tmp;
  t209 = -f_Ts_tmp_tmp_tmp * t71 + t274_tmp;
  t210 = t458 * 2.0;
  t211 = -t107 * f_Ts_tmp_tmp_tmp + t210;
  t699 = t284_tmp * t12;
  t217 = t240 * t211;
  t230 = Ts_tmp_tmp_tmp * t141;
  t636 = t230 + t209 * Ts_tmp_tmp;
  t232 = -2.0 * t97 * t636 + g_Ts_tmp * (t699 - t217);
  t233 = t119 * t32 + t683;
  t126 = t271 * i_Ts_tmp_tmp;
  t237 = Ts_tmp_tmp_tmp * t189;
  t204 = t205_tmp * 4.0 - t204 * 3.0;
  t251 = -Ts_tmp_tmp * t241 + t333;
  x_Ts_tmp = t620_tmp + t610_tmp;
  t257 = t683 * e_Ts_tmp_tmp_tmp;
  t259 = 2.0 * t158 * x_Ts_tmp;
  t280 = t34 * t125_tmp;
  t307 = -b_t59_tmp * n3pp;
  t49 *= Ts_tmp_tmp;
  t310 = Ts_tmp_tmp_tmp * t433;
  t311 = t69_tmp * t94_tmp;
  t247 = t386_tmp * d_Ts_tmp_tmp;
  t312 = 2.0 * f_Ts_tmp * (-t311 + t553_tmp * (t310 + t49)) - t247 * t32;
  t314 = t159 * b_Ts_tmp;
  t315 = -t314 * t205_tmp * n3pp * Ts_tmp;
  t316 = t717 * t198;
  t317 = t316 * n3pp * t32 * t53;
  t319 = 2.0 * g_Ts_tmp;
  t328 = t12 * c_Ts_tmp_tmp + Ts_tmp_tmp * (-t188 * Ts_tmp_tmp_tmp * 2.0 + t554 *
    t512);
  t329 = t498_tmp * t246;
  t86 = t86 * e_Ts_tmp_tmp_tmp - t288;
  t330 = a_tmp_tmp_tmp_tmp_tmp * x[12] - t86 * f_Ts_tmp_tmp_tmp;
  p_Ts_tmp_tmp_tmp = Ts_tmp_tmp_tmp * -t526 + t330 * Ts_tmp_tmp;
  t216 = 2.0 * (t97 * p_Ts_tmp_tmp_tmp + t699) - t217;
  t337 = f_Ts_tmp * (t329 * -t535 + t58 * (-t650 - c_Ts_tmp_tmp)) *
    b_Ts_tmp_tmp_tmp;
  v_Ts_tmp = t216 + t661 * t328;
  t340 = -2.0 * (e_Ts_tmp * (t12 * t135_tmp + t610_tmp * b_Ts_tmp) *
                 b_Ts_tmp_tmp + t257) + b_Ts_tmp_tmp_tmp * v_Ts_tmp;
  t343 = t462 * i_Ts_tmp_tmp_tmp;
  t350 = t156 * Ts_tmp_tmp_tmp;
  t352 = t463 * t585;
  t354 = 8.0 * (t102 * i_Ts_tmp_tmp_tmp + n3p / 4.0);
  t355 = -t465 / 2.0;
  t361 = 2.0 * (n_Ts_tmp_tmp - 0.5);
  t363 = t361 - t580;
  t356 = (t356 * 4.0 * (n_Ts_tmp_tmp - 2.0) - t587 * Ts_tmp_tmp_tmp_tmp *
          (n_Ts_tmp_tmp - 2.0)) - t354 * e_Ts_tmp_tmp_tmp;
  t369 = t355 * e_Ts_tmp_tmp_tmp;
  t374 = c_Ts_tmp_tmp_tmp * (-t43 * d_Ts_tmp_tmp_tmp + t369) + t341 / 2.0;
  t128 *= 4.0;
  t375 = 8.0 * g_Ts_tmp_tmp_tmp;
  t376 = (-t375 * t374 * f_Ts_tmp_tmp_tmp + t128 * c_Ts_tmp_tmp_tmp) + t356 *
    ab_Ts_tmp;
  t378 = t603_tmp + t368;
  t44 = -t378 * i_Ts_tmp_tmp_tmp / 2.0 + l_Ts_tmp_tmp_tmp;
  t82 = -c_Ts_tmp_tmp_tmp * (t82 * (n_Ts_tmp_tmp - 2.0) - t44) + t361 * t362;
  t361 = l_Ts_tmp_tmp - t357;
  t90 = t308 - t90;
  t308 = d_Ts_tmp_tmp_tmp * t90;
  t379 = -t361 / 4.0 + t308 * c_Ts_tmp_tmp_tmp;
  t380 = 4.0 * (ab_Ts_tmp * t82 - t599 * c_Ts_tmp_tmp_tmp) - t375 * t379 *
    f_Ts_tmp_tmp_tmp;
  t383 = t78 * t135_tmp;
  t385 = t69_tmp * 2.0;
  t386 = (-4.0 * t383 * t344 + Ts_tmp_tmp * (t376 * Ts_tmp_tmp + t380 *
           Ts_tmp_tmp_tmp)) - t385 * t577;
  t361 = i_Ts_tmp_tmp_tmp * t361 / 2.0 + t100;
  t387 = t100 * 2.0;
  t388 = t463 * i_Ts_tmp_tmp_tmp - t513;
  t389 = g_Ts_tmp * t388 - t89;
  t398 = t463 * g_Ts_tmp;
  t597 = g_Ts_tmp_tmp_tmp * t90 + t389 * f_Ts_tmp_tmp_tmp;
  t403 = 4.0 * i_Ts_tmp_tmp * t597 - t398;
  t404 = c_Ts_tmp_tmp_tmp * (t236 - m_Ts_tmp_tmp);
  t405 = t404 * g_Ts_tmp - t279 * t378;
  t262 = (t72_tmp * t361 - t306_tmp * t643) * f_Ts_tmp_tmp_tmp;
  t407 = -4.0 * f_Ts_tmp_tmp_tmp * (g_Ts_tmp_tmp_tmp * t405 - t262) - t387 *
    t72_tmp;
  t408 = t577 * e_Ts_tmp_tmp_tmp;
  t409 = t408 * Ts_tmp_tmp_tmp + t586 * Ts_tmp_tmp;
  t411 = t47_tmp * t135_tmp;
  t470 = t156 * 2.0;
  t413 = (-4.0 * t411 * t409 + Ts_tmp_tmp * (t403 * Ts_tmp_tmp + t407 *
           Ts_tmp_tmp_tmp)) + t470 * e_Ts_tmp_tmp_tmp * t32;
  t559 = t553_tmp * t173 * 4.0;
  t417 = -t624 * Ts_tmp_tmp_tmp * Ts_tmp_tmp + t508;
  t418 = g_Ts_tmp * t417;
  t421 = t155 * e_Ts_tmp_tmp_tmp;
  t422 = t211 + t421;
  t423 = t475_tmp * e_Ts_tmp;
  t129 = b_t174_tmp * Ts_tmp_tmp;
  t603 = Ts_tmp_tmp_tmp * t489 + t129;
  t426 = 2.0 * t97 * t603 - t423 * t422;
  t427 = t661 * t418;
  t157 = 2.0 * f_Ts_tmp * (t207 * t497 - t157) * b_Ts_tmp_tmp_tmp;
  t584 = b_t59_tmp * Ts_tmp_tmp + t186_tmp;
  t430 = t97 * t584;
  t316 = -2.0 * (t38_tmp * t198 * t205_tmp - e_Ts_tmp_tmp_tmp * t430) + t316 *
    t58 * x[11];
  t161 = t198 * t58;
  t430 = b_Ts_tmp_tmp_tmp * (t161 * x[11] + t430);
  t434 = Ts_tmp_tmp * (t33 * Ts_tmp_tmp_tmp + t620_tmp);
  t435 = f_Ts_tmp * Ts_tmp;
  t436 = t435 * (t500 * b_Ts_tmp + t434);
  t438 = b_Ts_tmp * b_Ts_tmp_tmp_tmp;
  t66 = -t66 * t43_tmp * c_Ts_tmp_tmp_tmp + t341 * x[11];
  t440 = ib_Ts_tmp * t180;
  t46 = -t135 * t85 - t46 * i_Ts_tmp_tmp_tmp;
  t135 = t372 * 2.0 - t371;
  t372 = t378_tmp * d_Ts_tmp_tmp * h_Ts_tmp_tmp_tmp;
  t65 = t240 * t135;
  t133 = t65 + t372;
  t706 = Ts_tmp_tmp * t46;
  t397 = t706 + t366_tmp * Ts_tmp_tmp_tmp;
  t448 = -2.0 * t440 * t397 - t22_tmp * t133;
  t449 = t284_tmp * d_Ts_tmp_tmp_tmp;
  t453 = Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp;
  t454 = t453 * i_Ts_tmp_tmp_tmp;
  t347 = b_Ts_tmp_tmp_tmp * ((-2.0 * t440 * (r_Ts_tmp * (t368 + t347) - t647 *
    Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp) + t22_tmp * a_tmp_tmp * e_Ts_tmp_tmp * M
    [0] * d_Ts_tmp_tmp_tmp) + t390 * t180 * n3pp * (a_tmp_tmp * d_Ts_tmp_tmp_tmp
    - t454));
  t119 = g_Ts_tmp * t364 * (-t119 * i_Ts_tmp_tmp_tmp * c_Ts_tmp_tmp_tmp + t449);
  t368 = t345_tmp * 3.0;
  t364 *= b_Ts_tmp;
  t390 = t364 * n3pp;
  t469 = t72_tmp * Ts_tmp_tmp_tmp;
  t27 = Ts_tmp_tmp * h_Ts_tmp_tmp_tmp;
  t458 = t27 - t469;
  t604 = t158 * i_Ts_tmp_tmp;
  t682 = 2.0 * t604 * t458;
  t462 = t284_tmp * t345_tmp;
  t465 = t462 * f_Ts_tmp_tmp_tmp;
  t454 = t396_tmp * Ts_tmp_tmp - t454;
  t467 = f_Ts_tmp_tmp_tmp * t454;
  t6 = t200 * t557;
  t478 = t79 * Ts_tmp_tmp_tmp;
  t480 = 4.0 * cb_Ts_tmp;
  t72 = e_Ts_tmp * (x[11] * ((-t164 * 2.0 * t135_tmp + t480 * t164 * Ts_tmp_tmp)
    + t478 * t72) + t133_tmp * t58 * Ts_tmp_tmp_tmp);
  t164 = t135_tmp * t141;
  t481 = t69_tmp * t211;
  t482 = e_Ts_tmp * (x[11] * ((t480 * t141 * Ts_tmp_tmp - t164 * 2.0) + t478 *
    t209) + t481 * Ts_tmp_tmp_tmp);
  t620 = -(2.0 * b_Ts_tmp) + t480;
  t485 = g_Ts_tmp * t541_tmp * t661 * t620;
  t487 = 9.0 * bb_Ts_tmp;
  t488 = 12.0 * b_t59_tmp * b_Ts_tmp_tmp_tmp;
  t48 = t620_tmp * 6.0 * Ts_tmp_tmp_tmp;
  t491 = t620 * t32;
  t492 = f_Ts_tmp * b_Ts_tmp_tmp;
  t623 = g_Ts_tmp * t492;
  t496 = t623 * (t491 * e_Ts_tmp_tmp_tmp + t48);
  t497 = t314 * n3pp;
  t499 = t497 * t53;
  t500 = 3.0 * t499 * t339;
  t503 = -t184_tmp * Ts_tmp_tmp_tmp + t252_tmp;
  t511 = t33 * n3pp;
  t171 = (-t171 * t180 * 2.0 - t519 * t47_tmp * t198) * b_Ts_tmp_tmp_tmp;
  t218 = t97 * x_Ts_tmp;
  w_Ts_tmp = e_Ts_tmp_tmp_tmp * (-t426 - t427 * 4.0);
  t514 = e_Ts_tmp_tmp_tmp * t216;
  t_Ts_tmp = t328 * e_Ts_tmp_tmp_tmp + t186_tmp * b_Ts_tmp_tmp * Ts_tmp_tmp;
  t162 = 3.0 * t499 * b_t336_tmp;
  t311 = 2.0 * e_Ts_tmp * (t135_tmp * t433 * x[11] + t311 * Ts_tmp_tmp_tmp) -
    t245 * x[11] * (t310 * 4.0 + t49 * 6.0);
  t52 *= t497 * 3.0 * t32;
  t250 = b_t59_tmp * Ts_tmp_tmp_tmp;
  t433 = e_Ts_tmp * Ts_tmp;
  t211 = e_Ts_tmp * (x[11] * ((-t526 * 2.0 * t135_tmp - t480 * -t526 *
    Ts_tmp_tmp) - t478 * t330) + t139 * t211);
  t328 *= Ts_tmp_tmp_tmp;
  t330 = t492 * (t620 * t32 * e_Ts_tmp_tmp_tmp + t48);
  t483 = 8.0 * Ts_tmp_tmp_tmp;
  t721 = e_Ts_tmp_tmp_tmp * t482;
  t164 = 2.0 * e_Ts_tmp * (t186_tmp * t69_tmp - t164) + t245 * (Ts_tmp_tmp *
    (9.0 * e_Ts_tmp_tmp_tmp * t78 + t209 * 6.0) + t230 * 4.0);
  t245 = t225 * t187;
  t60 *= f_Ts_tmp_tmp_tmp;
  t209_tmp = -t158 * 2.0;
  t136 = t275_tmp * Ts_tmp_tmp;
  t278 = t278 * 6.0 * g_Ts_tmp;
  t277 = t277 * 2.0 * Ts_tmp_tmp_tmp;
  t295 = t69_tmp * -t270;
  t664 = t437 * t97;
  t276 *= e_Ts_tmp_tmp_tmp;
  t20 = t661 * (c_Ts_tmp_tmp * t266 + Ts_tmp_tmp * (q_Ts_tmp_tmp_tmp * t20 *
    Ts_tmp_tmp_tmp + t554 * t537));
  t558 = t321_tmp * Ts_tmp_tmp + t333;
  t306 = t437 * x[11];
  t89 = 2.0 * (t97 * (Ts_tmp_tmp * (g_Ts_tmp_tmp_tmp * t86 + o_Ts_tmp_tmp_tmp *
    x[12]) - Ts_tmp_tmp_tmp * t523) + t111);
  t671 = t661 * Ts_tmp_tmp;
  t705 = (-2.0 * f_Ts_tmp_tmp_tmp * (e_Ts_tmp * (t135_tmp * (-m_Ts_tmp_tmp *
             c_Ts_tmp_tmp_tmp - t345_tmp * t85) - t213 * t432 * b_Ts_tmp) * x[11]
           + t372) - t65 * f_Ts_tmp_tmp_tmp) + t661 * f_Ts_tmp_tmp_tmp *
    ((-c_Ts_tmp_tmp * i_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp - t650 *
      h_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp) + t329 * m_Ts_tmp);
  t477 = b_Ts_tmp_tmp_tmp * ((-2.0 * f_Ts_tmp * f_Ts_tmp_tmp_tmp * (Ts_tmp_tmp *
    t397 + t370) + t368 * t384 * t198) + t661 * b_t22_tmp * ((l_Ts_tmp_tmp * 2.0
    - t357 * 6.0) * Ts_tmp_tmp + t341 * 2.0 * Ts_tmp_tmp_tmp));
  t63 = t435 * (Ts_tmp_tmp * (t250 - t252_tmp) + t121 * Ts_tmp);
  t382 = 0.0;
  for (int i{0}; i < 6; i++) {
    t65 = Kv6[i];
    t610 += t65 * z[i];
    t382 += t65 * z[i + 6];
  }

  t18 = ((((((((((n3p * (((((-2.0 * t509 * (n3p * (-i_Ts_tmp_tmp *
    Ts_tmp_tmp_tmp * d_Ts_tmp_tmp + a_tmp_tmp * t528) - t297 * t137) + t176 *
    (t156_tmp * (((e_Ts_tmp_tmp_tmp * t192 * t147_tmp + 2.0 * t198 *
                   (Ts_tmp_tmp_tmp * ((-x[11] * t516 * e_Ts_tmp_tmp_tmp - t517)
    + t521) + Ts_tmp_tmp * ((-e_Ts_tmp_tmp_tmp * (-t508 * x[11] +
    b_Ts_tmp_tmp_tmp * t510) - t188 * t53) - t526 * t61 * x[11]))) - Ts_tmp_tmp *
                  (-e_Ts_tmp_tmp_tmp * t153 + t538)) + t60_tmp) + t154 * t205))
    - t305 * (((((t154 * t253_tmp + b_Ts_tmp_tmp_tmp * (-t153 * Ts_tmp_tmp_tmp +
    Ts_tmp_tmp * ((-t242 - t243) - t532))) + t540) - t520) - t507) - t254 * t192))
    - t220 * ((-Ts_tmp_tmp * t342 + t346) + t154 * t399)) - t6_tmp * t21) - t74)
                  + n3pp * t109) + n3ppp * t77) + x[11] * t25) + t106 * x[12]) +
              hb_Ts_tmp * t22) + x[13] * t182) + t6_tmp * t18) - (-64.0 *
            TParam[1] * 961.38919357530426 / n3pppp_tmp * yr_tmp - t610)) - t28 *
          t239) - t509 * n3pppp * t565) + t29 * t24;
  t21 = b_Ts_tmp_tmp_tmp * n3pp;
  t22 = -t17_tmp * 3.0 + n3pp;
  t24 = t22 * h_Ts_tmp_tmp_tmp;
  t25 = -t24 * d_Ts_tmp_tmp_tmp + t76 * 2.0;
  t45 = 0.33333333333333331 * t22;
  t549 = t25 * g_Ts_tmp_tmp_tmp - h_Ts_tmp_tmp * 3.0 * t45;
  t76 = t246 * Ts_tmp_tmp_tmp;
  t444 += b_Ts_tmp * t549 + t76 * u_Ts_tmp;
  t137 = t132 * (t271 * g_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp_tmp * n3pp + t21 * t270 *
                 Ts_tmp_tmp_tmp);
  t21 *= b_Ts_tmp;
  t146 = t21 * (t336_tmp * 4.0 + t335 * 3.0);
  t153 = t333 * e_Ts_tmp_tmp_tmp;
  t154 = t153 + t152;
  t160 = 2.0 * t158 * t154;
  t163 = t21 * b_t336_tmp;
  t167 = g_Ts_tmp * (-t160 + t118);
  t182 = b_Ts_tmp_tmp_tmp * (t661 * (t444 + t163) + t116) + t167;
  t192 = a_tmp_tmp_tmp * 3.0 * t45;
  t193 = -t25 * f_Ts_tmp_tmp_tmp - t192;
  t202 = (t446_tmp + b_Ts_tmp * t193) + t76 * t200;
  t239 = b_Ts_tmp_tmp_tmp * (-t206 + t132 * (t126 * n3pp + t237));
  t242 = -g_Ts_tmp * b_Ts_tmp_tmp_tmp * t233;
  t243 = t21 * t204;
  t244 = 2.0 * t202;
  t249 = ((e_Ts_tmp_tmp_tmp * t232 + t239) - t242) + t147 * (t244 + t243);
  t222 = g_Ts_tmp * (-t259 - t257) + b_Ts_tmp_tmp_tmp * (t232 + t661 * (t21 *
    t339 + t202));
  t270 = 1.0 / t23_tmp;
  t272 = t222 * Ts_tmp_tmp * b_t336_tmp;
  t281 = t280 * t270 * t141_tmp;
  t285 = t222 * t270;
  t286 = t285 * t251;
  t289 = t182 - t286;
  t291 = t125_tmp * t270 * t141_tmp;
  t293 = t291 * t174_tmp;
  t294 = t293 * t227 * e_Ts_tmp_tmp_tmp;
  t576 = t270 * t270;
  t300 = t258 * t222 * t125_tmp * t270 * t576 * t141_tmp;
  t301 = t300 * t251;
  t305 = t301 * t184;
  t31 = a_tmp_tmp_tmp_tmp_tmp * 3.0 * t45 + t31 * t22;
  t309 = Ts_tmp_tmp * (t307 * Ts_tmp_tmp_tmp + t31 * Ts_tmp_tmp) - b_t174_tmp *
    c_Ts_tmp_tmp;
  t675 = 2.0 * b_Ts_tmp_tmp_tmp * (f_Ts_tmp * (t450 * t17_tmp * Ts_tmp_tmp +
    e_Ts_tmp_tmp_tmp * t309) - t97 * (t36 * Ts_tmp_tmp + Ts_tmp_tmp_tmp * t81));
  t36 = -b_t59_tmp * Ts_tmp_tmp_tmp + t252_tmp;
  t81 = t158 * t36;
  t320 = b_Ts_tmp_tmp_tmp * (t661 * (-n3pp * t121 * Ts_tmp + t309) + t312) +
    t319 * t81;
  t323 = t285 * t32;
  t324 = t291 * t226 * t156_tmp;
  t325 = t285 * t452_tmp + t320;
  t327 = t300 * t452_tmp;
  t346 = f_Ts_tmp_tmp_tmp * ((-t47_tmp * (t580 + 1.0) / 2.0 - t343 / 2.0) +
    t47_tmp * n_Ts_tmp_tmp);
  t349 = -t635 - f_Ts_tmp_tmp_tmp * (a_tmp_tmp_tmp * t102 - t346);
  t353 = -8.0 * (t350 * t12 + t349 * Ts_tmp_tmp) + t352 * g_Ts_tmp * t135_tmp;
  t416 = (b_Ts_tmp_tmp_tmp * (a_tmp_tmp * t353 + t386) + t413) *
    b_Ts_tmp_tmp_tmp + t559 * t344;
  t126 = -t248 * (t35 * Ts_tmp_tmp_tmp + t126) + t147 * (-t438 * t204 + 2.0 *
    t434);
  t24 = t24 * i_Ts_tmp_tmp_tmp + t345 * 2.0;
  t204 = t378_tmp * c_Ts_tmp_tmp * h_Ts_tmp_tmp_tmp;
  t248 = b_Ts_tmp * t24 - t204;
  t345 = t76 * t66;
  t439 = f_Ts_tmp_tmp_tmp * t248 + t345 * f_Ts_tmp_tmp_tmp;
  t455 = t147 * (-2.0 * t439 + t390 * (t400 * 4.0 - t368));
  t395 = g_Ts_tmp * (t465 + t682) + b_Ts_tmp_tmp_tmp * (t448 + t661 * (t390 *
    t401 + t439));
  t468 = -t222 * t402 * Ts_tmp_tmp;
  t708 = t395 + t285 * t467;
  t471 = t300 * t467 * t184;
  t473 = -2.0 * t193;
  t476 = t473 * Ts_tmp_tmp * Ts_tmp_tmp_tmp - 2.0 * t6;
  t486 = t202 * Ts_tmp_tmp_tmp - t476 * Ts_tmp_tmp;
  t578 = (-b_Ts_tmp_tmp_tmp * (t387_tmp * t486 - t482) + t496) - t500;
  t505 = t222 * Ts_tmp_tmp_tmp * t339;
  t506 = t285 * t503;
  t507 = t270 * t503;
  t509 = t507 - t254;
  t280 = t280 * t222 * t576 * t141_tmp;
  t510 = t285 * 6.0 * t125_tmp * t141_tmp;
  t239 = ((-e_Ts_tmp_tmp_tmp * t232 - t239) + t242) + t147 * (-t244 - t243);
  t242 = 2.0 * t222 * t125_tmp * t576 * t141_tmp;
  t50 = (3.0 * (t281 * (t239 * t147_tmp * e_Ts_tmp_tmp_tmp + t222) - t242 *
                t174_tmp * t227 * t184 * e_Ts_tmp_tmp_tmp) - t281 * (((((((t270 *
    (-t551 * t222 + t184 * (-t249 + t239)) - t202 * 2.0 * t54 * f_Ts_tmp) - 4.0 *
    t132 * (-t620_tmp * n3pp * t53 + t237 * e_Ts_tmp_tmp_tmp)) - s_Ts_tmp * t233)
             + 2.0 * e_Ts_tmp_tmp_tmp * t206) - b_Ts_tmp_tmp_tmp * (((2.0 * t97 *
    (t169 * Ts_tmp_tmp_tmp + Ts_tmp_tmp * (mb_Ts_tmp * t80 + t40 *
    g_Ts_tmp_tmp_tmp)) + t173 * e_Ts_tmp_tmp * M[0] * e_Ts_tmp_tmp_tmp *
    Ts_tmp_tmp) - t232) + t495 * b_Ts_tmp * t511)) - t198 * t194 * n3pp *
           (i_Ts_tmp_tmp * (Ts_tmp * 10.0 - t96) + t488)) + 3.0 * t249 *
          t147_tmp * e_Ts_tmp_tmp_tmp)) + t281 * t222 * (2.0 * t576 * (t184 *
    t184) + 12.0 * t226 * bb_Ts_tmp);
  t54 = b_Ts_tmp_tmp_tmp * (2.0 * t427 + t426);
  t80 = -t101 * 6.0 - t593;
  t132 = t350 * 2.0;
  t551 = f_Ts_tmp_tmp_tmp * t80 + t47_tmp * a_tmp_tmp_tmp * 6.0;
  t149 = Ts_tmp_tmp * t551;
  t150 = Ts_tmp_tmp * (t149 - t132);
  t169 = -2.0 * f_Ts_tmp * (Ts_tmp_tmp * t636 + t69_tmp * t32) - t78 * t198 *
    3.0 * e_Ts_tmp_tmp_tmp;
  t206 = t420_tmp * 4.0 * Ts_tmp_tmp_tmp * Ts_tmp_tmp;
  t232 = t437 * t218;
  t233 = b_Ts_tmp_tmp_tmp * (t661 * t150 + t169) - t232;
  t243 = n3p * t340;
  t244 = n3ppp * t436;
  t121 = t244 - t243;
  t35 = (t662 * t184 * t416 * t187 * t576 + t187 * (-t662 * ((b_Ts_tmp_tmp_tmp *
            (Ts_tmp_tmp * (-t194 * t353 * 3.0 + t666 * Ts_tmp_tmp) - 2.0 * t386 *
             e_Ts_tmp_tmp_tmp) - e_Ts_tmp_tmp_tmp * t413) + b_Ts_tmp_tmp_tmp *
           (((b_Ts_tmp_tmp_tmp * (Ts_tmp_tmp * (Ts_tmp_tmp_tmp * (-4.0 * (-t363 *
    ab_Ts_tmp * t62 + t62 * n_Ts_tmp) + q_Ts_tmp * t43 * t10 * 8.0) + Ts_tmp_tmp
    * ((-ab_Ts_tmp * b_Ts_tmp_tmp_tmp * (t587 * n3p * (n_Ts_tmp_tmp - 2.0) +
    t354) - t640 * 8.0 * t355 * b_Ts_tmp_tmp_tmp) - t587 * t271_tmp)) - t95_tmp *
    t58 * 4.0 * t59_tmp) - 4.0 * b_Ts_tmp * (t658 * a_tmp_tmp * t577 + t156 *
    t35)) + (-4.0 * f_Ts_tmp_tmp_tmp * (q_Ts_tmp * (-t378 / 2.0 + t603_tmp *
    n_Ts_tmp) - h_Ts_tmp_tmp * t361 * b_Ts_tmp_tmp_tmp) - t387 *
             c_Ts_tmp_tmp_tmp * b_Ts_tmp_tmp_tmp) * Ts_tmp_tmp_tmp * Ts_tmp_tmp)
            + t665 * 2.0)) + t676 * t416) * t270) * t227 * t225;
  t523 = b_Ts_tmp_tmp_tmp * ((-2.0 * t97 * (Ts_tmp_tmp * (g_Ts_tmp_tmp_tmp * t91
    + t290) + t93) + t475_tmp * t331 * e_Ts_tmp_tmp * M[0]) + t137);
  t43 = gb_Ts_tmp * ((3.0 * t294 * t325 - t324 * (((((e_Ts_tmp_tmp_tmp * t312 +
    t270 * (t184 * t320 + t249 * t452_tmp)) + t675) - t315) - t317) * t147_tmp *
    t156_tmp - t323)) - t327 * t184) + t264 * ((3.0 * t294 * t289 - t281 *
    ((((t270 * ((t182 * t184 - t249 * t251) + t272) - t147 * (-2.0 * t444 - t146))
       + t116 * e_Ts_tmp_tmp_tmp) - t523) - t138)) + t305);
  t35 = ((t174_tmp * (t229 * (t270 * ((n3p * ((-2.0 * b_Ts_tmp_tmp_tmp *
    (f_Ts_tmp * t_Ts_tmp + t683) - t514) + t337) + t316 * n3pp) + n3ppp * t126)
            + t184 * t121 * t576) + t416 * t227 * t270 * t662 * t168 * t205) +
          t275 * (t208 * t184 * t54 * t576 - t208 * (w_Ts_tmp + t157) * t270)) +
         t35) * t141_tmp * t125_tmp;
  t62 = n3pp * t430;
  t443 = t62 * t270;
  t116 = t208 * t54;
  t168 = t623 * (t620 * t313 * e_Ts_tmp_tmp_tmp + t152 * 6.0 * Ts_tmp_tmp_tmp);
  t176 = t246 * e_Ts_tmp;
  t193 = t193 * Ts_tmp_tmp * Ts_tmp_tmp_tmp + t6;
  t246 = ((b_Ts_tmp_tmp_tmp * (t495 * t202 - t482) - t496) + t176 * t193 *
          Ts_tmp) + t500;
  t271 = t222 * (Ts_tmp_tmp_tmp * t241 + t460);
  t354 = t503 * t576;
  t355 = t254 * t270;
  t377 = (-t355 + t354) * t222;
  t378 = t377 * t251;
  t307 *= t557;
  t309 *= Ts_tmp_tmp_tmp;
  t386 = t623 * (-t186_tmp * 6.0 * Ts_tmp_tmp + b_t59_tmp * t620);
  t387 = t222 * x_Ts_tmp;
  t355 -= t354;
  t65 = 12.0 * cb_Ts_tmp;
  t427 = t553_tmp * e_Ts_tmp;
  t418 = b_Ts_tmp_tmp_tmp * (t159 * g_Ts_tmp * t422 + t427 * (-t129 * 6.0 *
    Ts_tmp_tmp_tmp - t620 * t489)) - 2.0 * t433 * (-t557 * Ts_tmp_tmp * t78 +
    t418 * Ts_tmp_tmp_tmp);
  t188 = -6.0 * t512 * Ts_tmp_tmp * Ts_tmp_tmp_tmp + t188 * 2.0 * t557;
  t622 = b_Ts_tmp_tmp_tmp * (t427 * (t250 * 6.0 * Ts_tmp_tmp + t491) + t314 *
    t670 * x[11]);
  t434 *= Ts_tmp_tmp_tmp;
  t366 = ((-3.0 * t499 * t402 + t623 * i_Ts_tmp_tmp * (-t27 * 6.0 *
            Ts_tmp_tmp_tmp + t72_tmp * t620)) - b_Ts_tmp_tmp_tmp * (-e_Ts_tmp *
           f_Ts_tmp_tmp_tmp * (x[11] * ((-t366_tmp * 2.0 * t135_tmp + t480 *
              t366_tmp * Ts_tmp_tmp) + t478 * t46) + t69_tmp * t135 *
            Ts_tmp_tmp_tmp) + t495 * t439)) + t176 * f_Ts_tmp_tmp_tmp * (-t24 *
    Ts_tmp_tmp * Ts_tmp_tmp_tmp + t494 * t66) * Ts_tmp;
  t402 = Ts_tmp_tmp * c_Ts_tmp_tmp_tmp;
  t394 = t222 * f_Ts_tmp_tmp_tmp * (t396_tmp * Ts_tmp_tmp_tmp + t402 *
    i_Ts_tmp_tmp_tmp);
  t491 = b_Ts_tmp * 14.0 - t480;
  t492 = -t65 + t79;
  t496 = t285 * t125_tmp * t141_tmp * t174_tmp * t227 * e_Ts_tmp_tmp_tmp;
  t84 = (2.0 * t281 * (t377 * t184 + t254 * t239) + t281 * ((((((t270 * ((t184 *
    t246 - t239 * t503) + t505) + 2.0 * t495 * (e_Ts_tmp_tmp_tmp * t202 + t237 *
    a_tmp_tmp)) - t721) - b_Ts_tmp_tmp_tmp * (t198 * t189 * b_Ts_tmp_tmp_tmp -
              t72)) + t485) + t661 * (((-t487 * t58 * Ts_tmp_tmp *
              Ts_tmp_tmp_tmp + 12.0 * t92 * Ts_tmp_tmp_tmp * Ts_tmp) + t554 *
             t548 * Ts_tmp_tmp_tmp) * n3pp + t717 * t193)) - 3.0 * t246 *
          t147_tmp * e_Ts_tmp_tmp_tmp)) + t496 * (-t507 * 3.0 + t84);
  t92 = t156 * t557;
  t230 = g_Ts_tmp * t427 * (12.0 * t620_tmp * Ts_tmp_tmp_tmp + (t641 - t502) *
    t32 * e_Ts_tmp_tmp_tmp);
  t237 = b_Ts_tmp_tmp * t54;
  t537 = t320 * t503;
  t610 = t69_tmp * t701 * Ts_tmp_tmp_tmp;
  t48 = -gb_Ts_tmp * (2.0 * t281 * (t355 * t452_tmp * t222 + t254 * t320) - t281
                      * (((t270 * ((t246 * t452_tmp + t537) + t387) -
    b_Ts_tmp_tmp_tmp * (t311 + t387_tmp * (Ts_tmp_tmp * (-t76 * t31 - t307) -
    t309))) - t386) - t52)) - t264 * (2.0 * t281 * (t254 * t182 + t378) - t281 *
    ((((t270 * ((t182 * t503 - t246 * t251) + t271) + b_Ts_tmp_tmp_tmp *
        (-e_Ts_tmp * (x[11] * ((-t304 * 2.0 * t135_tmp + t480 * t304 *
    Ts_tmp_tmp) + t478 * t87) + t610) + t495 * t444)) - t168) + t176 * (t549 *
    Ts_tmp_tmp * Ts_tmp_tmp_tmp + t557 * u_Ts_tmp) * Ts_tmp) + t162));
  t636 = t433 * ((t76 * t12 + t33 * t557) * Ts_tmp_tmp + t434) + -3.0 * t314 *
    t53 * t339;
  t68 = (t227 * (-t354 * t245 * t416 * t662 + t245 * (t416 * (t558_tmp * t662 -
            t657) + t662 * (-4.0 * t78 * (t344 * Ts_tmp_tmp_tmp - Ts_tmp_tmp * (
              -t250 + t252_tmp)) + ((b_Ts_tmp_tmp_tmp * ((b_Ts_tmp_tmp_tmp *
    (-t353 * Ts_tmp_tmp_tmp + Ts_tmp_tmp * (-8.0 * (t620_tmp * t156 - t349 *
    Ts_tmp_tmp_tmp) - t79 * t658 * t585)) - t380 * t557) + Ts_tmp_tmp * (-2.0 *
    t376 * Ts_tmp_tmp_tmp + t78 * ((-t32 * 4.0 * t135_tmp + t250 * 16.0 *
    b_Ts_tmp) + t65 * t252_tmp))) - t407 * t557) + Ts_tmp_tmp * (-2.0 * t403 *
              Ts_tmp_tmp_tmp + t47_tmp * ((Ts_tmp_tmp_tmp * t586 * 16.0 *
    b_Ts_tmp - t717 * t577 * t135_tmp) + t65 * t408 * Ts_tmp_tmp))) *
            b_Ts_tmp_tmp_tmp)) * t270) + t229 * (t270 * (t156_tmp * (t156_tmp *
            (((-n3p * (b_Ts_tmp_tmp_tmp * (t387_tmp * (t188 * Ts_tmp_tmp - t328)
    + t211) + t330) - t622 * n3pp) - n3ppp * t636) + t237 * cb_Ts_tmp) + t208 *
            t418) + t237) + t354 * t156_tmp * (-t156_tmp * t121 - t116))) *
    t141_tmp * t125_tmp;
  t77 = t281 * ((t443 * t503 + t254 * ((d_Ts_tmp * (((-t507 * t233 -
    b_Ts_tmp_tmp_tmp * (t495 * t150 - t164)) + t230) - t176 * (t149 *
    Ts_tmp_tmp_tmp - t92) * Ts_tmp) + t243) - t244)) + d_Ts_tmp * t233);
  t79 = t662 * t416 * t187;
  t87 = t498_tmp * x[12];
  t149 = t291 * t166;
  t176 = t149 * Ts_tmp_tmp_tmp;
  t11 = 2.0 * t281 * (t254 * t395 + t355 * t467 * t222);
  t48 = (((((2.0 * t77 + t84 * x[11]) + x[12] * ((-2.0 * (-t281 * (t222 * (t576 *
    (t503 * t503) + 1.0) + t254 * t578) + t242 * t166 * t503 * Ts_tmp_tmp_tmp) +
              t281 * ((((((t270 * (t23_tmp * t222 + t503 * (-t578 + t246)) + 6.0
    * f_Ts_tmp * n3pp * t53 * cb_Ts_tmp * t339) - 3.0 * t198 * n3pp * t53 * t339)
    + g_Ts_tmp * t53_tmp * (t620_tmp * t492 + t610_tmp * t491)) -
                        b_Ts_tmp_tmp_tmp * (-e_Ts_tmp * ((t498_tmp * t491 * t141
    + t553_tmp * t492 * t209) + t481 * Ts_tmp_tmp) + t387_tmp * (t476 *
    Ts_tmp_tmp_tmp + Ts_tmp_tmp * ((t483 * t200 * Ts_tmp_tmp + t473 * t557) +
    t202)))) + t159 * 2.0 * t193 * Ts_tmp) - t254 * 2.0 * t246)) + t510 * t224 *
             t229 * cb_Ts_tmp)) + hb_Ts_tmp * (t11 - t281 * (t270 * ((t246 *
    t467 + t395 * t503) + t394) - t366))) - t6_tmp * t48) - t68) + t176 *
    (t156_tmp * (-t79 * t147_tmp * 3.0 + t87 * t233 * 6.0) - t62 * 4.0);
  t74 = -g_Ts_tmp_tmp_tmp * t71 - t48_tmp;
  t109 = t74 * Ts_tmp_tmp;
  t141 = Ts_tmp_tmp_tmp * t215;
  t151 = -2.0 * t97 * (t109 - t141) - g_Ts_tmp * (-y_Ts_tmp + t111);
  t159 = b_Ts_tmp_tmp_tmp * (-t151 + t661 * (t444 + t163)) + t167;
  t163 = -t281 * t289;
  t166 = t158 * t623_tmp;
  t167 = t281 * t708;
  t193 = t97 * g_Ts_tmp_tmp_tmp;
  t200 = g_Ts_tmp * g_Ts_tmp_tmp_tmp;
  t202 = q_Ts_tmp * b_Ts_tmp * n3pp * t401;
  t209 = g_Ts_tmp * (t209_tmp * g_Ts_tmp_tmp_tmp * t458 * i_Ts_tmp_tmp_tmp -
                     t462 * g_Ts_tmp_tmp_tmp);
  t224 = t222 * g_Ts_tmp_tmp_tmp * t454;
  t237 = t301 * t467;
  t241 = t281 * t325;
  t242 = t69_tmp * t284;
  t246 = t247 * t313;
  t253 = b_Ts_tmp * n3pp;
  t45 = t661 * ((t253 * t313 * Ts_tmp + Ts_tmp_tmp * (Ts_tmp_tmp_tmp * t321_tmp *
    n3pp - Ts_tmp_tmp * (o_Ts_tmp_tmp_tmp * 3.0 * t45 - t269 * t22))) + t133_tmp
                * t313);
  t269 = t319 * t158 * (-t367 * e_Ts_tmp_tmp_tmp + t460);
  t284 = t222 * (t460 * e_Ts_tmp_tmp_tmp - t367);
  t289 = t301 * t452_tmp;
  t301 = c_Ts_tmp * t326 * t198 * 3.0;
  t154 *= t664;
  t304 = t661 * 2.0;
  t326 = b_Ts_tmp_tmp_tmp * (-t97 * t558 + t331 * t198 * x[11]);
  t152 = t435 * (t438 * b_t336_tmp + Ts_tmp_tmp * (t303_tmp * Ts_tmp_tmp_tmp -
    t152));
  t331 = t187 * t662;
  t82 = (-t79 * t251 * t576 + t331 * ((4.0 * t553_tmp * t378_tmp *
           (-g_Ts_tmp_tmp_tmp * t344 + f_Ts_tmp_tmp_tmp * t558) +
           (((b_Ts_tmp_tmp_tmp * ((4.0 * g_Ts_tmp * (x[12] * t707 + t135_tmp *
    i_Ts_tmp_tmp_tmp * x[11] * (t719_tmp * Ts_tmp_tmp * e_Ts_tmp_tmp_tmp + t722))
    + Ts_tmp_tmp * (Ts_tmp_tmp * (8.0 * t374 * t704 - q_Ts_tmp_tmp_tmp * t356 *
    f_Ts_tmp_tmp_tmp) - t483 * (t82 * f_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp - t379
    * t704))) + a_tmp_tmp * (8.0 * (-Ts_tmp_tmp * (c_Ts_tmp_tmp_tmp * t102 *
    t704 - t346 * q_Ts_tmp_tmp_tmp) + t720 * Ts_tmp_tmp_tmp * t719_tmp) + t306 *
    t582 * t135_tmp)) - 8.0 * t411 * (-t707 * e_Ts_tmp_tmp_tmp * Ts_tmp_tmp_tmp
    + Ts_tmp_tmp * t713)) - 2.0 * t432 * g_Ts_tmp * t710_tmp) + Ts_tmp_tmp *
            (Ts_tmp_tmp_tmp * (4.0 * t405 * t704 - t262 * t375) + Ts_tmp_tmp * (
              -4.0 * i_Ts_tmp_tmp_tmp * t704 * t90 - t375 * i_Ts_tmp_tmp * t389)))
           * b_Ts_tmp_tmp_tmp) - t334 * t416 * t187) * t270) * t227 * t225;
  t42 = t251 * t320;
  t21 = ((t163 * t238 - gb_Ts_tmp * (-t281 * ((t270 * ((-t159 * t452_tmp + t42)
              - t284) + b_Ts_tmp_tmp_tmp * ((t45 - 2.0 * f_Ts_tmp * (t553_tmp *
    (-Ts_tmp_tmp_tmp * t88 + t136) - t242)) + t246)) - t269) - t289)) - t264 * (
          -t281 * ((t270 * (t251 * (t182 + t159) - t222 * t187_tmp) - g_Ts_tmp *
                    (t166 * 2.0 + t257)) - b_Ts_tmp_tmp_tmp * ((-2.0 * t97 *
             (-t292 * Ts_tmp_tmp_tmp + Ts_tmp_tmp * (f_Ts_tmp_tmp_tmp * t71 -
    t274_tmp)) - g_Ts_tmp * (t699 + t240 * (t107 * f_Ts_tmp_tmp_tmp - t210))) +
            t661 * (((b_Ts_tmp * (t25 * f_Ts_tmp_tmp_tmp + t192) - t446_tmp) +
                     t76 * (t60 + t196)) - t21 * t205))) + t300 * (t251 * t251)))
    - hb_Ts_tmp * t241;
  t623 = (t423 * (-t701 + t276) + 2.0 * t97 * (-t534 * Ts_tmp_tmp - t637 *
           Ts_tmp_tmp_tmp)) + t304 * g_Ts_tmp * (t207 * i_Ts_tmp_tmp_tmp *
    g_Ts_tmp_tmp_tmp + t686);
  t82 = ((t82 + t275 * (-t116 * t251 * t576 + t208 * b_Ts_tmp_tmp_tmp * t623 *
                        t270)) + t34 * (t270 * (-n3p * (2.0 * (t53_tmp * (-t153 *
              b_Ts_tmp - t135_tmp * t266) + t118) + b_Ts_tmp_tmp_tmp * ((t89 -
              y_Ts_tmp) + t20)) - n3ppp * t152) - t251 * t121 * t576)) *
    t141_tmp * t125_tmp;
  t84 = t430 * t270;
  t620 = t84 * t251 + t326;
  t413 = t671 * (Ts_tmp_tmp * (-g_Ts_tmp_tmp_tmp * t80 + t278) + t277);
  t109 = t281 * (n3pp * t620 + t297 * ((-t251 * t233 * t270 + b_Ts_tmp_tmp_tmp *
    ((-2.0 * f_Ts_tmp * (Ts_tmp_tmp * (t141 - t109) + t295) + t301) + t413)) -
    t154));
  t65 = t251 * t395;
  t21 = (((((2.0 * t109 + x[11] * ((3.0 * t294 * (t159 - t286) + t305) - t281 *
              ((((t270 * ((t159 * t184 + t239 * t251) + t272) - e_Ts_tmp_tmp_tmp
                  * t151) - t523) - t138) - t147 * (-2.0 * t444 - t146)))) + x
            [12] * (2.0 * t281 * (t254 * t159 + t378) - t281 * (((t270 * ((t159 *
    t503 + t251 * t578) + t271) + b_Ts_tmp_tmp_tmp * (-e_Ts_tmp * (x[11] *
    ((-t215 * 2.0 * t135_tmp + t480 * t215 * Ts_tmp_tmp) - t478 * t74) + t610) +
    t387_tmp * (Ts_tmp_tmp_tmp * t444 - Ts_tmp_tmp * (-2.0 * t549 * Ts_tmp_tmp *
    Ts_tmp_tmp_tmp - 2.0 * t557 * u_Ts_tmp)))) - t168) + t162))) - gb_Ts_tmp *
           t167) + hb_Ts_tmp * (-t281 * ((t270 * ((-t159 * t467 + t65) + t224) -
             b_Ts_tmp_tmp_tmp * ((t193 * 2.0 * t397 + t200 * t133) + t661 *
              ((-g_Ts_tmp_tmp_tmp * t248 - t345 * g_Ts_tmp_tmp_tmp) - t202))) -
            t209) - t237)) - t6_tmp * t21) - t82;
  t47 = t213 * e_Ts_tmp_tmp_tmp + t402;
  t41 = -b_Ts_tmp_tmp_tmp * ((t661 * (t253 * h_Ts_tmp_tmp * i_Ts_tmp_tmp_tmp *
    Ts_tmp - i_Ts_tmp_tmp * (Ts_tmp_tmp * (t213 * n3pp * e_Ts_tmp_tmp_tmp + t402
    * t22) - t133_tmp * c_Ts_tmp_tmp_tmp)) - 2.0 * t624 * f_Ts_tmp * (Ts_tmp_tmp
    * (t41 * Ts_tmp_tmp + Ts_tmp_tmp_tmp * t83) + t38)) + t247 * h_Ts_tmp_tmp *
    i_Ts_tmp_tmp_tmp) + t319 * t604 * t47;
  t91 = t624 * t180;
  t93 = t437 * t91 * t458;
  t47 = b_Ts_tmp_tmp_tmp * ((t180 * 2.0 * t47 * t78 + t423 * f_Ts_tmp_tmp_tmp *
    (-t135 + t371)) - t304 * t22_tmp * (-t207 * d_Ts_tmp_tmp_tmp + t646));
  t106 = t27 * e_Ts_tmp_tmp_tmp - t453;
  t91 = b_Ts_tmp_tmp_tmp * (t14_tmp * ib_Ts_tmp * t198 + t91 * t106);
  t109 = t435 * (-i_Ts_tmp_tmp * Ts_tmp_tmp * t458 + t364 * (-t345_tmp + t400));
  t220 = t281 * (t270 * ((t320 * t467 + t452_tmp * t395) + t214 * t222) + t41) +
    t327 * t467;
  t24 = ((t105 * t163 - gb_Ts_tmp * t220) - t264 * (t281 * ((t270 * ((t182 *
              t467 - t65) - t224) + b_Ts_tmp_tmp_tmp * ((2.0 * t193 * (t366_tmp *
    Ts_tmp_tmp_tmp + t706) + t200 * (t240 * t135 + t372)) + t661 *
             ((g_Ts_tmp_tmp_tmp * (-b_Ts_tmp * t24 + t204) - t76 * t66 *
               g_Ts_tmp_tmp_tmp) - t202))) + t209) - t237)) + (t163 * t264 -
    t241 * gb_Ts_tmp) * t6_tmp * d_Ts_tmp_tmp_tmp;
  t199 = t84 * t467 - t91;
  t610 = 3.0 * t294 * t708;
  t11 = ((((-2.0 * t281 * (n3pp * t199 + t297 * ((-t467 * t233 * t270 - t477) -
              t93)) + x[11] * ((t610 - t471) + t281 * ((((-e_Ts_tmp_tmp_tmp *
    t448 + t270 * ((-t184 * t395 + t239 * t467) + t468)) + t119) + t347) + t455)))
           + x[12] * (t11 + t281 * (t270 * ((-t395 * t503 + t467 * t578) - t394)
             + t366))) + hb_Ts_tmp * (t281 * ((t270 * (-t222 * f_Ts_tmp_tmp_tmp *
              (Ts_tmp_tmp * c_t22_tmp - t453 * d_Ts_tmp_tmp_tmp) + 2.0 * t467 *
              t395) + g_Ts_tmp * (t209_tmp * f_Ts_tmp_tmp_tmp * t458 *
              d_Ts_tmp_tmp_tmp + t257)) + b_Ts_tmp_tmp_tmp * ((2.0 * t440 *
              (t140 * Ts_tmp_tmp_tmp - Ts_tmp_tmp * t71) + t22_tmp * (-t240 *
    t107 + t449 * h_Ts_tmp_tmp_tmp)) + t661 * ((f_Ts_tmp_tmp_tmp * (t133_tmp *
    d_Ts_tmp_tmp_tmp * h_Ts_tmp_tmp_tmp + b_Ts_tmp * t25) + t60 * t76) + t390 *
              (t14_tmp * h_Ts_tmp_tmp_tmp + t43_tmp)))) + t300 * (t467 * t467)))
         - t6_tmp * t24) - (((t79 * t467 * t576 + t331 * ((-4.0 * t475_tmp *
    ib_Ts_tmp * (t106 * i_Ts_tmp_tmp_tmp * i_Ts_tmp_tmp + t344 *
                 d_Ts_tmp_tmp_tmp) + (((b_Ts_tmp_tmp_tmp * ((4.0 * g_Ts_tmp *
    (x[12] * t396 + ib_Ts_tmp * t135_tmp * (t728_tmp * Ts_tmp_tmp *
    e_Ts_tmp_tmp_tmp + t464)) + Ts_tmp_tmp * (j_Ts_tmp * (4.0 *
    (c_Ts_tmp_tmp_tmp * (-t712 / 2.0 + t343) - t720 * t345_tmp * (4.0 - t587)) *
    f_Ts_tmp_tmp_tmp - t375 * ((-h_Ts_tmp / 4.0 - t101 / 4.0) + b_t14_tmp * t90))
    + b_t22_tmp * (f_Ts_tmp_tmp_tmp * (-8.0 * (e_Ts_tmp_tmp_tmp * (t392 - t725)
    + t643 * j_Ts_tmp_tmp * g_Ts_tmp) + t600 * t345_tmp * h_Ts_tmp) - t375 *
                   (c_Ts_tmp_tmp_tmp * (-e_Ts_tmp_tmp_tmp * t381 / 2.0 - t370) +
                    t720 / 2.0)))) + a_tmp_tmp * (8.0 * (b_t22_tmp *
    (-f_Ts_tmp_tmp_tmp * (-t726 / 2.0 + t608 * (n_Ts_tmp - 2.0)) + a_tmp_tmp_tmp
     * t358) + t69_tmp * f_Ts_tmp_tmp_tmp * Ts_tmp_tmp_tmp * t728_tmp) + t398 *
    t618 * t135_tmp)) - 4.0 * Ts_tmp_tmp * (j_Ts_tmp * (g_Ts_tmp_tmp_tmp *
    (t212_tmp * (t504 + m_Ts_tmp) - t279 * t351) - f_Ts_tmp_tmp_tmp * (-t38 *
    t651 + t72_tmp * (t654 / 2.0 + t101 * i_Ts_tmp_tmp_tmp))) + b_t22_tmp *
    (d_Ts_tmp_tmp_tmp * t597 - i_Ts_tmp_tmp * (-t602 - t373)))) + 8.0 * t411 *
    (t396 * e_Ts_tmp_tmp_tmp * Ts_tmp_tmp_tmp + t645 * Ts_tmp_tmp)) - 2.0 * t362
    * f_Ts_tmp_tmp_tmp * t69) * b_Ts_tmp_tmp_tmp) + t399 * t416 * t187) * t270) *
    t227 * t225 + t275 * (t116 * t467 * t576 + t208 * t47 * t270)) + t34 * (t270
    * (-n3p * (2.0 * f_Ts_tmp_tmp_tmp * (t53_tmp * (-t469 * b_Ts_tmp + t135_tmp *
    h_Ts_tmp_tmp_tmp) * i_Ts_tmp_tmp_tmp + t462) + b_Ts_tmp_tmp_tmp * t705) +
       n3ppp * t109) + t467 * t121 * t576)) * t141_tmp * t125_tmp;
  t24 = t270 * 2.0 * t184;
  t25 = t280 * t452_tmp;
  t36 = b_Ts_tmp_tmp_tmp * (-2.0 * f_Ts_tmp * (Ts_tmp_tmp * (-t310 - t49) +
    t69_tmp * t12) - t198 * t425 * 6.0 * b_Ts_tmp_tmp_tmp) + t664 * t36;
  t46 = b_Ts_tmp_tmp_tmp * (f_Ts_tmp * (-t94_tmp * g_Ts_tmp + t553_tmp *
    (t472_tmp * Ts_tmp_tmp + t104)) - t67 * f_Ts_tmp);
  t49 = 2.0 * (-b_Ts_tmp_tmp_tmp * (f_Ts_tmp * (t542 - t553_tmp * (t231 *
    Ts_tmp_tmp_tmp + t508 * Ts_tmp_tmp)) + b_t174_tmp * d_Ts_tmp_tmp) + t81) +
    t435 * (-3.0 * t541_tmp * b_Ts_tmp - t539);
  t10 = gb_Ts_tmp * (t281 * ((t270 * (t222 * (b_t59_tmp * Ts_tmp_tmp + t186_tmp)
    + 2.0 * t452_tmp * t320) - b_Ts_tmp_tmp_tmp * ((t661 * ((t253 * t12 * Ts_tmp
    + Ts_tmp_tmp * (-t511 * Ts_tmp_tmp_tmp - Ts_tmp_tmp * (-t10 * t22 + t192)))
    + t446_tmp) - 2.0 * f_Ts_tmp * (t69_tmp * t413_tmp + t553_tmp * (-t410 *
    Ts_tmp_tmp + t419 * Ts_tmp_tmp_tmp))) + t247 * t12)) + t319 * t166) + t300 *
                     (t452_tmp * t452_tmp)) + t264 * (t281 * ((t270 * ((t182 *
    t452_tmp - t42) + t284) - b_Ts_tmp_tmp_tmp * ((t45 - 2.0 * f_Ts_tmp *
    (t553_tmp * (-Ts_tmp_tmp_tmp * t73 + t136) - t242)) + t246)) + t269) - t289);
  t162 = ((-t681 * t452_tmp * t54 * t229 * t576 + (-t79 * t452_tmp * t576 - t331
            * (((((b_Ts_tmp_tmp_tmp * (((4.0 * t383 * t452_tmp + Ts_tmp_tmp *
    (Ts_tmp_tmp_tmp * (4.0 * ((ab_Ts_tmp * ((t252 + t365 * (n_Ts_tmp_tmp - 2.0))
    - t44 * h_Ts_tmp_tmp_tmp) + t599 * h_Ts_tmp_tmp_tmp) - t90 *
    c_Ts_tmp_tmp_tmp) - t375 * (-d_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp *
    h_Ts_tmp_tmp_tmp + t362 * t75) + fb_Ts_tmp * t378_tmp / 4.0) *
                       f_Ts_tmp_tmp_tmp) + Ts_tmp_tmp * (((-t128 *
    h_Ts_tmp_tmp_tmp + ab_Ts_tmp * (-4.0 * (n_Ts_tmp_tmp - 2.0) * (-t40 *
    h_Ts_tmp_tmp_tmp + t69_tmp * t321) + t236 * t378_tmp * 8.0)) -
    c_Ts_tmp_tmp_tmp * 4.0 * t131) - t375 * (d_Ts_tmp_tmp_tmp * (t117 *
    c_Ts_tmp_tmp_tmp - Ts_tmp_tmp_tmp_tmp * t634) - t369 * h_Ts_tmp_tmp_tmp) *
    f_Ts_tmp_tmp_tmp))) - t385 * t287) + a_tmp_tmp * (8.0 * (-Ts_tmp_tmp * (x[11]
    * (t22_tmp * d_Ts_tmp_tmp_tmp * g_Ts_tmp_tmp_tmp * n_Ts_tmp + j_Ts_tmp_tmp *
       g_Ts_tmp) + f_Ts_tmp_tmp_tmp * (h_Ts_tmp_tmp * (t100 * (n_Ts_tmp_tmp -
    2.0) - t98 * d_Ts_tmp_tmp_tmp) + a_tmp_tmp_tmp_tmp_tmp * t102)) + t186_tmp *
    t156) - t306 * t299 * t135_tmp)) - 4.0 * b_Ts_tmp * (-i_Ts_tmp_tmp *
    (-g_Ts_tmp_tmp_tmp * t599 - t308 * f_Ts_tmp_tmp_tmp) + t498_tmp * t475_tmp *
    t287 * e_Ts_tmp_tmp_tmp)) + Ts_tmp_tmp * (Ts_tmp_tmp_tmp * (e_Ts_tmp_tmp_tmp
    * 2.0 * t318 - 4.0 * f_Ts_tmp_tmp_tmp * (g_Ts_tmp_tmp_tmp * (-t127 *
    i_Ts_tmp_tmp_tmp + t306_tmp * (-t296 + m_Ts_tmp_tmp)) + f_Ts_tmp_tmp_tmp *
    (e_Ts_tmp_tmp_tmp * (-t302 * c_Ts_tmp_tmp_tmp + t361 * h_Ts_tmp_tmp_tmp) +
     t212_tmp * t643))) + t411 * t299 * 8.0)) + t470 * b_t59_tmp) *
                b_Ts_tmp_tmp_tmp - t559 * t452_tmp) + t452_tmp * t416 * t187) *
            t270) * t227 * t225) + t34 * (t270 * (n3p * t49 - n3ppp * t63) -
           t452_tmp * t121 * t576)) * t141_tmp * t125_tmp;
  t22 = t84 * t147_tmp * t452_tmp;
  t34 = Ts_tmp_tmp * (t551 * Ts_tmp_tmp - t132);
  t153 = -b_Ts_tmp_tmp_tmp * (t661 * t34 + t169) + t232;
  t40 = t153 * t270;
  t42 = t173 * e_Ts_tmp_tmp_tmp;
  t44 = b_Ts_tmp_tmp_tmp * (-f_Ts_tmp * (-g_Ts_tmp * t32 + Ts_tmp_tmp * t603) +
    t391 * b_Ts_tmp * g_Ts_tmp);
  t45 = -4.0 * t218 + b_Ts_tmp_tmp_tmp * ((2.0 * f_Ts_tmp * (-x[12] * t32 +
    Ts_tmp_tmp * p_Ts_tmp_tmp_tmp) - t556 * t198 * 3.0) + t671 * (-t155 * 2.0 *
    Ts_tmp_tmp_tmp + 6.0 * Ts_tmp_tmp * t94_tmp));
  t60 = b_Ts_tmp_tmp_tmp * (t180 * t584 + t161);
  t66 = t270 * t229;
  t71 = -t54 * t270;
  t73 = b_Ts_tmp_tmp_tmp * ((2.0 * t97 * (t252_tmp - t250) - f_Ts_tmp * t422) +
    t304 * t417);
  t76 = t149 * t87 * 4.0;
  t79 = t163 * d_Ts_tmp_tmp_tmp - t241;
  t81 = (-b_Ts_tmp_tmp_tmp * v_Ts_tmp + t257 * 2.0) + t259;
  t84 = t81 * t270;
  t388 = t245 * (d_Ts_tmp_tmp * t416 + t662 * ((((b_Ts_tmp_tmp_tmp * (((-4.0 *
    t135_tmp * t344 * t624 + Ts_tmp_tmp * (Ts_tmp_tmp_tmp * (4.0 * (ab_Ts_tmp *
    (-t108 * d_Ts_tmp_tmp_tmp + m_Ts_tmp_tmp_tmp * t363) - m_Ts_tmp_tmp_tmp *
    n_Ts_tmp) - t375 * h_Ts_tmp_tmp_tmp * (i_Ts_tmp / 4.0 - t513) *
    f_Ts_tmp_tmp_tmp) + Ts_tmp_tmp * (f_Ts_tmp_tmp_tmp * (o_Ts_tmp_tmp_tmp *
    (t282 * 4.0 + t283 * 8.0) - t375 * (c_Ts_tmp_tmp_tmp * (t709 - t288) +
    m_Ts_tmp / 2.0)) + j_Ts_tmp_tmp_tmp * 4.0 * c_Ts_tmp_tmp_tmp))) - 2.0 * t577
    * x[12]) + a_tmp_tmp * (-8.0 * (Ts_tmp_tmp * (f_Ts_tmp_tmp_tmp *
    (f_Ts_tmp_tmp_tmp * (x[11] * n_Ts_tmp_tmp - x[11] * (t580 + 1.0) / 2.0) +
     t265 * fb_Ts_tmp) - t634 * x[11]) + t155 * Ts_tmp_tmp_tmp * t12) + t352 *
    t135_tmp)) - x[11] * 4.0 * t135_tmp * t409) + Ts_tmp_tmp * (Ts_tmp_tmp_tmp *
    (-4.0 * f_Ts_tmp_tmp_tmp * (g_Ts_tmp_tmp_tmp * (t404 - t345_tmp * x[11] /
    2.0) + f_Ts_tmp_tmp_tmp * (-t72_tmp * t195 + t643 * h_Ts_tmp_tmp_tmp)) -
     t72_tmp * g_Ts_tmp_tmp * 2.0) + Ts_tmp_tmp * (-4.0 * i_Ts_tmp_tmp * (-t388 *
    f_Ts_tmp_tmp_tmp + t515) - t463))) + t421 * 2.0 * t32) * b_Ts_tmp_tmp_tmp +
    t624 * 4.0 * t344 * Ts_tmp_tmp)) * t270 * t227;
  t27 = hb_Ts_tmp * t281;
  t65 = t264 * t281;
  t174 = x[11] * t281;
  t235 = x[12] * t281;
  t262 = t22 + t97 * (-t33 * Ts_tmp_tmp + t450);
  t12 = t436 * t270;
  t12 = (((x[11] * (t281 * (t12 * t184 + t126) - t294 * 3.0 * t436) + x[12] *
           (t281 * (t636 + t507 * t436) - t176 * 2.0 * t436)) - t27 * (t12 *
           t467 + t109)) + t6_tmp * (-gb_Ts_tmp * t281 * (t12 * t452_tmp + t63)
          + t65 * (t12 * t251 + t152))) - t291 * t258 * t430;
  t342 = gb_Ts_tmp * t281;
  t6 = e_Ts_tmp_tmp_tmp * t169;
  t10 = -t21 * t264 - gb_Ts_tmp * (((((2.0 * t324 * ((-t208 * t46 * t147_tmp +
    t87 * t174_tmp * t147_tmp * (t452_tmp * t233 * t270 + t36)) - n3pp *
    t156_tmp * t262) + x[11] * (t324 * (t156_tmp * (t147_tmp *
    ((((-e_Ts_tmp_tmp_tmp * t312 + t270 * (-t184 * t320 + t239 * t452_tmp)) -
       t675) + t315) + t317) + e_Ts_tmp_tmp_tmp * 3.0 * t320 * t226) + t323) +
    t25 * (t147_tmp * 3.0 * e_Ts_tmp_tmp_tmp - t24))) + x[12] * (-2.0 * t25 *
    t509 - t281 * ((((t270 * ((t537 - t452_tmp * t578) + t387) +
                      b_Ts_tmp_tmp_tmp * (-t311 + t387_tmp * (-Ts_tmp_tmp *
    (-2.0 * t31 * Ts_tmp_tmp * Ts_tmp_tmp_tmp - t307) + t309))) - t386) - t52) -
                   t254 * 2.0 * t320))) + hb_Ts_tmp * t220) + t6_tmp * t10) +
    t162);
  t162 = t692 - M[6];
  controller_output[0] = t18;
  controller_output[1] = ((((((((((n3p * (((((-2.0 * t281 * (-n3p * d_Ts_tmp_tmp
    * t339 - t297 * t45) + t174 * (((((-3.0 * t81 * t147_tmp * e_Ts_tmp_tmp_tmp
    - t284_tmp * t58 * 2.0) - t514) - 2.0 * t661 * t_Ts_tmp) + t337) + t84 *
    t184)) + t235 * (((t507 * t81 - b_Ts_tmp_tmp_tmp * (t387_tmp * (-t188 *
    Ts_tmp_tmp + t328) - t211)) + t330) - t254 * 2.0 * t81)) - t27 *
    (((-b_Ts_tmp_tmp_tmp * t705 - t465 * 2.0) - t682) + t84 * t467)) - t6_tmp *
    (t342 * (t84 * t452_tmp - t49) - t65 * (((b_Ts_tmp_tmp_tmp * ((t89 -
    y_Ts_tmp) + t20) + t118 * 2.0) - t160) + t84 * t251))) - (t66 * t681 * t73 +
    t388) * t141_tmp * t125_tmp) + n3pp * ((((-2.0 * (t27 * t199 + t6_tmp *
    (gb_Ts_tmp * t293 * t226 * t262 - t65 * t620)) + t174 * (t430 *
    (-e_Ts_tmp_tmp_tmp * t147_tmp * 6.0 + t24) + t316)) + t235 * (t430 * (-t254 *
    4.0 + 2.0 * t507) + t622)) + t281 * (t340 - t331 * (b_Ts_tmp_tmp_tmp *
    (Ts_tmp_tmp * (Ts_tmp_tmp_tmp * (c_Ts_tmp_tmp_tmp * (ab_Ts_tmp * t123 * 4.0
    - t619) - t375 * d_Ts_tmp_tmp_tmp * (t634 - 0.25) * f_Ts_tmp_tmp_tmp) +
                   Ts_tmp_tmp * ((-ab_Ts_tmp * e_Ts_tmp_tmp_tmp * (-8.0 *
    (n_Ts_tmp_tmp - 0.5) / 2.0 + t587 * (n_Ts_tmp_tmp - 2.0)) + t717 * t583) -
    t587 * e_Ts_tmp_tmp_tmp)) - t438 * t589 * 4.0) - 2.0 * Ts_tmp_tmp * (-t33 *
    i_Ts_tmp_tmp * Ts_tmp_tmp_tmp - t589 * Ts_tmp_tmp)) * b_Ts_tmp_tmp_tmp *
    t147_tmp * t156_tmp)) - t60 * t76)) + n3ppp * t12) - x[11] * (((((((((-2.0 *
    t281 * (t443 * t184 + t297 * (((-t184 * t233 * t270 - t6) + t171) - t661 *
    (2.0 * t150 * e_Ts_tmp_tmp_tmp + t206))) + 6.0 * t294 * (-t297 * t233 + t62))
    + 3.0 * t291 * t70 * t227 * (t156_tmp * t121 + t116)) - x[11] * t50) - x[12]
    * (((2.0 * t280 * t184 * t509 + 3.0 * t294 * (t578 - t506)) + t281 *
        ((((((t270 * ((-t184 * t578 + t249 * t503) + t505) + 2.0 * t194 *
    e_Ts_tmp * t486) - t721) - b_Ts_tmp_tmp_tmp * (-t72 + t661 * (-t189 * t557 -
    t189 * cb_Ts_tmp))) + t485) + t314 * Ts_tmp * n3pp * (i_Ts_tmp_tmp * (-t487
    + t61) + t488)) - t254 * 2.0 * t249)) + t510 * t225 * t227 * Ts_tmp_tmp_tmp *
       e_Ts_tmp_tmp_tmp)) - hb_Ts_tmp * ((t610 - t281 * ((((e_Ts_tmp_tmp_tmp *
    t448 + t270 * ((t184 * t395 + t249 * t467) - t468)) - t119) - t347) - t455))
    - t471)) - t6_tmp * t43) - t35) + t717 * t256 * t416 * t228 * t270 * t662) +
    t207 * ((((((-2.0 * t275 * t270 * (t416 * t156_tmp * x[12] * t187 + (t17_tmp
    * t339 * t661 + t174_tmp * (-x[11] * t233 - t222)) * t141_tmp * t125_tmp *
    Ts_tmp_tmp_tmp) + t174 * (((3.0 * t54 * t147_tmp * e_Ts_tmp_tmp_tmp +
    w_Ts_tmp) + t157) + t71 * t184)) + t235 * ((t254 * 2.0 * t54 + t507 * -t54)
    + t418)) + t27 * (-t71 * t467 + t47)) + t6_tmp * (t342 * (2.0 * t46 - t71 *
    t452_tmp) + t65 * (b_Ts_tmp_tmp_tmp * t623 + t71 * t251))) + t281 * (((n3p *
    t73 + t578) - t506) - t331 * (b_Ts_tmp_tmp_tmp * ((b_Ts_tmp_tmp_tmp *
    (Ts_tmp_tmp * (Ts_tmp_tmp_tmp * (4.0 * (t363 * ab_Ts_tmp * s_Ts_tmp -
    s_Ts_tmp * n_Ts_tmp) + s_Ts_tmp * t583 * 8.0) + Ts_tmp_tmp * (g_Ts_tmp * 4.0
    * t574 - t375 * t201 * f_Ts_tmp_tmp_tmp)) - t319 * t577) - 4.0 * Ts_tmp_tmp *
    (t267 * Ts_tmp_tmp - t273 * Ts_tmp_tmp_tmp)) + t42 * 2.0 * t32) - t620_tmp *
    t212 * 8.0 * t53) * t147_tmp * t156_tmp)) - t76 * t44))) + t11 * hb_Ts_tmp)
    + x[12] * t48) - x[13] * (-t177 * (t167 * g_Ts_tmp_tmp_tmp + t191 * t79) *
    t103 + t145 * (-t167 * f_Ts_tmp_tmp_tmp + t190 * t79) * t160_tmp)) - t6_tmp *
    t10) - (-4096.0 * TParam[2] * 961.38919357530426 / n3pppp_tmp * b_yr_tmp -
            t382)) + t28 * t163) - t281 * n3pppp * t436) + t29 * ((((((-2.0 *
    t66 * (t416 * x[11] * t187 + ((n3pp * t60 * t174_tmp + t148 * (-t44 * x[11]
    + t54)) - t139 * (x[11] * (6.0 * t198 * b_Ts_tmp_tmp_tmp * (b_Ts_tmp_tmp_tmp
    * t472_tmp - t42) - t437 * t180 * x_Ts_tmp) + t233) * t225) * t141_tmp *
           t125_tmp) + t174 * ((((-3.0 * t153 * t147_tmp * e_Ts_tmp_tmp_tmp - t6)
    + t171) - t661 * (t34 * 2.0 * e_Ts_tmp_tmp_tmp + t206)) + t40 * t184)) -
    t235 * (((t254 * 2.0 * t153 + b_Ts_tmp_tmp_tmp * (-t164 + t387_tmp * (t34 *
    Ts_tmp_tmp_tmp - Ts_tmp_tmp * (-t551 * 2.0 * Ts_tmp_tmp * Ts_tmp_tmp_tmp +
    2.0 * t92)))) - t230) - t507 * t153)) + t27 * ((t477 + t93) - t40 * t467)) +
    t6_tmp * (t342 * (-t40 * t452_tmp + t36) + t65 * ((b_Ts_tmp_tmp_tmp * ((-2.0
    * f_Ts_tmp * (Ts_tmp_tmp * t711 + t295) + t301) + t413) - t154) + t40 * t251)))
    + t281 * (((n3p * t45 - t285 * t184) + t239) - t331 * (((b_Ts_tmp_tmp_tmp *
    ((-4.0 * t173 * t135_tmp * t344 + Ts_tmp_tmp * (t130 * 8.0 * Ts_tmp_tmp -
    t170 * Ts_tmp_tmp_tmp * 2.0)) + a_tmp_tmp * Ts_tmp_tmp * (-8.0 *
    (f_Ts_tmp_tmp_tmp * (f_Ts_tmp_tmp_tmp * (((g_Ts_tmp * n_Ts_tmp_tmp - t580 *
    g_Ts_tmp / 2.0) + M[3] / 2.0) - n3 / 2.0) + t212_tmp * t265) - t634 *
     g_Ts_tmp) + t319 * t585 * b_Ts_tmp)) - g_Ts_tmp * 4.0 * t135_tmp * t409) +
    Ts_tmp_tmp * (Ts_tmp_tmp_tmp * (4.0 * f_Ts_tmp_tmp_tmp * (h_Ts_tmp_tmp *
    t197 * e_Ts_tmp_tmp_tmp + t165 * g_Ts_tmp_tmp_tmp) - t319 * j_Ts_tmp_tmp *
    e_Ts_tmp_tmp_tmp) + t475_tmp * (t592 * ab_Ts_tmp - 2.0))) * b_Ts_tmp_tmp_tmp
    + t173 * 4.0 * t344 * Ts_tmp_tmp) * t147_tmp * t156_tmp)) + t496 * 3.0);
  controller_output[2] = -(-(-a_tmp_tmp * e_Ts_tmp * t660 + M[3] * d_Ts_tmp_tmp)
    * (1.0 / d_Ts_tmp_tmp) + n3);
  controller_output[3] = (-i_Ts_tmp_tmp_tmp * (M[5] * x[13] * x[14] * t162 *
    f_Ts_tmp_tmp_tmp - g_Ts_tmp_tmp_tmp * M[6] * x[13] * x[15] * t162) - 2.0 *
    d_Ts_tmp_tmp_tmp * M[5] * M[6] * ((-g_Ts_tmp_tmp_tmp * (x[14] * x[14] - x[15]
    * x[15]) * f_Ts_tmp_tmp_tmp + t23) - t23 * 2.0 * ab_Ts_tmp)) * (t6_tmp *
    t6_tmp) * t160_tmp * t103 - (0.0 - (Kv2[0] * z[14] + Kv2[1] * -(0.02 -
    k_Ts_tmp)));
  coder::mldivide(Ts, controller_output);
}

//
// File trailer for QuasiControllerTrack.cpp
//
// [EOF]
//
