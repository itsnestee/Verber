/* ------------------------------------------------------------
name: "JpRevTest"
Code generated with Faust 2.50.6 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -cn _JpRevTest -scn ::faust::dsp -es 1 -mcd 16 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___JpRevTest_H__
#define  ___JpRevTest_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _JpRevTest
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static float _JpRevTest_faustpower2_f(float value) {
	return value * value;
}

class _JpRevTest final : public ::faust::dsp {
	
 public:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fVslider0;
	float fConst2;
	float fRec0[2];
	int IOTA0;
	float fVec0[16384];
	FAUSTFLOAT fVslider1;
	float fRec1[2];
	float fConst4;
	FAUSTFLOAT fVslider2;
	float fConst5;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT fVslider4;
	float fConst6;
	FAUSTFLOAT fVslider5;
	float fRec14[2];
	float fRec13[2];
	float fVec1[16384];
	int iConst8;
	float fConst9;
	FAUSTFLOAT fVslider6;
	float fVec2[2048];
	int iConst10;
	float fRec11[2];
	float fConst12;
	float fRec18[2];
	float fRec17[2];
	float fVec3[32768];
	int iConst14;
	float fVec4[16384];
	float fVec5[4096];
	int iConst15;
	float fRec15[2];
	float fConst17;
	float fRec22[2];
	float fRec21[2];
	float fVec6[16384];
	int iConst19;
	float fVec7[4096];
	int iConst20;
	float fRec19[2];
	float fConst22;
	float fRec26[2];
	float fRec25[2];
	float fVec8[32768];
	int iConst24;
	float fVec9[2048];
	int iConst25;
	float fRec23[2];
	float fConst27;
	float fRec30[2];
	float fRec29[2];
	float fVec10[16384];
	int iConst29;
	float fVec11[4096];
	int iConst30;
	float fRec27[2];
	float fConst32;
	float fRec34[2];
	float fRec33[2];
	float fVec12[16384];
	int iConst34;
	float fVec13[2048];
	int iConst35;
	float fRec31[2];
	float fConst37;
	float fRec38[2];
	float fRec37[2];
	float fVec14[32768];
	int iConst39;
	float fVec15[4096];
	int iConst40;
	float fRec35[2];
	float fConst42;
	float fRec42[2];
	float fRec41[2];
	float fVec16[16384];
	int iConst44;
	float fVec17[4096];
	int iConst45;
	float fRec39[2];
	float fRec3[3];
	float fRec4[3];
	float fRec5[3];
	float fRec6[3];
	float fRec7[3];
	float fRec8[3];
	float fRec9[3];
	float fRec10[3];
	FAUSTFLOAT fVslider7;
	FAUSTFLOAT fVslider8;
	float fRec2[3];
	FAUSTFLOAT fVslider9;
	FAUSTFLOAT fVslider10;
	float fRec43[3];
	float fRec45[3];
	float fRec44[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.8");
		m->declare("compile_options", "-lang cpp -rui -cn _JpRevTest -scn ::faust::dsp -es 1 -mcd 16 -uim -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("demos.lib/name", "Faust Demos Library");
		m->declare("demos.lib/version", "0.1");
		m->declare("demos.lib/zita_rev1:author", "Julius O. Smith III");
		m->declare("demos.lib/zita_rev1:licence", "MIT");
		m->declare("filename", "JpRevTest.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/peak_eq_rm:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq_rm:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq_rm:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "JpRevTest");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "0.2");
		m->declare("routes.lib/hadamard:author", "Remy Muller, revised by Romain Michon");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.3");
	}

	static constexpr int getStaticNumInputs() {
		return 2;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 2;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		float fConst3 = std::floor(0.153129f * fConst0 + 0.5f);
		fConst4 = (0.0f - 6.9077554f * fConst3) / fConst0;
		fConst5 = 6.2831855f / fConst0;
		fConst6 = 3.1415927f / fConst0;
		float fConst7 = std::floor(0.020346f * fConst0 + 0.5f);
		iConst8 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst3 - fConst7)));
		fConst9 = 0.001f * fConst0;
		iConst10 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst7 + -1.0f)));
		float fConst11 = std::floor(0.256891f * fConst0 + 0.5f);
		fConst12 = (0.0f - 6.9077554f * fConst11) / fConst0;
		float fConst13 = std::floor(0.027333f * fConst0 + 0.5f);
		iConst14 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst11 - fConst13)));
		iConst15 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst13 + -1.0f)));
		float fConst16 = std::floor(0.192303f * fConst0 + 0.5f);
		fConst17 = (0.0f - 6.9077554f * fConst16) / fConst0;
		float fConst18 = std::floor(0.029291f * fConst0 + 0.5f);
		iConst19 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst16 - fConst18)));
		iConst20 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst18 + -1.0f)));
		float fConst21 = std::floor(0.219991f * fConst0 + 0.5f);
		fConst22 = (0.0f - 6.9077554f * fConst21) / fConst0;
		float fConst23 = std::floor(0.019123f * fConst0 + 0.5f);
		iConst24 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst21 - fConst23)));
		iConst25 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst23 + -1.0f)));
		float fConst26 = std::floor(0.127837f * fConst0 + 0.5f);
		fConst27 = (0.0f - 6.9077554f * fConst26) / fConst0;
		float fConst28 = std::floor(0.031604f * fConst0 + 0.5f);
		iConst29 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst26 - fConst28)));
		iConst30 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst28 + -1.0f)));
		float fConst31 = std::floor(0.125f * fConst0 + 0.5f);
		fConst32 = (0.0f - 6.9077554f * fConst31) / fConst0;
		float fConst33 = std::floor(0.013458f * fConst0 + 0.5f);
		iConst34 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst31 - fConst33)));
		iConst35 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst33 + -1.0f)));
		float fConst36 = std::floor(0.210389f * fConst0 + 0.5f);
		fConst37 = (0.0f - 6.9077554f * fConst36) / fConst0;
		float fConst38 = std::floor(0.024421f * fConst0 + 0.5f);
		iConst39 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst36 - fConst38)));
		iConst40 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst38 + -1.0f)));
		float fConst41 = std::floor(0.174713f * fConst0 + 0.5f);
		fConst42 = (0.0f - 6.9077554f * fConst41) / fConst0;
		float fConst43 = std::floor(0.022904f * fConst0 + 0.5f);
		iConst44 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst41 - fConst43)));
		iConst45 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst43 + -1.0f)));
	}
	
	void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(-2e+01f);
		fVslider1 = FAUSTFLOAT(0.0f);
		fVslider2 = FAUSTFLOAT(2.0f);
		fVslider3 = FAUSTFLOAT(6e+03f);
		fVslider4 = FAUSTFLOAT(3.0f);
		fVslider5 = FAUSTFLOAT(2e+02f);
		fVslider6 = FAUSTFLOAT(6e+01f);
		fVslider7 = FAUSTFLOAT(315.0f);
		fVslider8 = FAUSTFLOAT(0.0f);
		fVslider9 = FAUSTFLOAT(1.5e+03f);
		fVslider10 = FAUSTFLOAT(0.0f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec0[l0] = 0.0f;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 16384; l1 = l1 + 1) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec14[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec13[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 16384; l5 = l5 + 1) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2048; l6 = l6 + 1) {
			fVec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec11[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec18[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec17[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 32768; l10 = l10 + 1) {
			fVec3[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 16384; l11 = l11 + 1) {
			fVec4[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 4096; l12 = l12 + 1) {
			fVec5[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec15[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec22[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec21[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 16384; l16 = l16 + 1) {
			fVec6[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 4096; l17 = l17 + 1) {
			fVec7[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec19[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec26[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec25[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 32768; l21 = l21 + 1) {
			fVec8[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2048; l22 = l22 + 1) {
			fVec9[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec23[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec30[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec29[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 16384; l26 = l26 + 1) {
			fVec10[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 4096; l27 = l27 + 1) {
			fVec11[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec27[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fRec34[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec33[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 16384; l31 = l31 + 1) {
			fVec12[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2048; l32 = l32 + 1) {
			fVec13[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec31[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec38[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec37[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 32768; l36 = l36 + 1) {
			fVec14[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 4096; l37 = l37 + 1) {
			fVec15[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec35[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			fRec42[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec41[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 16384; l41 = l41 + 1) {
			fVec16[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 4096; l42 = l42 + 1) {
			fVec17[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec39[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 3; l44 = l44 + 1) {
			fRec3[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 3; l45 = l45 + 1) {
			fRec4[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 3; l46 = l46 + 1) {
			fRec5[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 3; l47 = l47 + 1) {
			fRec6[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 3; l48 = l48 + 1) {
			fRec7[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 3; l49 = l49 + 1) {
			fRec8[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 3; l50 = l50 + 1) {
			fRec9[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 3; l51 = l51 + 1) {
			fRec10[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 3; l52 = l52 + 1) {
			fRec2[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 3; l53 = l53 + 1) {
			fRec43[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 3; l54 = l54 + 1) {
			fRec45[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 3; l55 = l55 + 1) {
			fRec44[l55] = 0.0f;
		}
	}
	
	void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	_JpRevTest* clone() {
		return new _JpRevTest();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->declare(0, "0", "");
		ui_interface->declare(0, "tooltip", "~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references");
		ui_interface->openHorizontalBox("Zita_Rev1");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("Input");
		ui_interface->declare(&fVslider6, "1", "");
		ui_interface->declare(&fVslider6, "style", "knob");
		ui_interface->declare(&fVslider6, "tooltip", "Delay in ms         before reverberation begins");
		ui_interface->declare(&fVslider6, "unit", "ms");
		ui_interface->addVerticalSlider("In Delay", &fVslider6, FAUSTFLOAT(6e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("Decay Times in Bands (see tooltips)");
		ui_interface->declare(&fVslider5, "1", "");
		ui_interface->declare(&fVslider5, "scale", "log");
		ui_interface->declare(&fVslider5, "style", "knob");
		ui_interface->declare(&fVslider5, "tooltip", "Crossover frequency (Hz) separating low and middle frequencies");
		ui_interface->declare(&fVslider5, "unit", "Hz");
		ui_interface->addVerticalSlider("LF X", &fVslider5, FAUSTFLOAT(2e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider4, "2", "");
		ui_interface->declare(&fVslider4, "scale", "log");
		ui_interface->declare(&fVslider4, "style", "knob");
		ui_interface->declare(&fVslider4, "tooltip", "T60 = time (in seconds) to decay 60dB in low-frequency band");
		ui_interface->declare(&fVslider4, "unit", "s");
		ui_interface->addVerticalSlider("Low RT60", &fVslider4, FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fVslider2, "3", "");
		ui_interface->declare(&fVslider2, "scale", "log");
		ui_interface->declare(&fVslider2, "style", "knob");
		ui_interface->declare(&fVslider2, "tooltip", "T60 = time (in seconds) to decay 60dB in middle band");
		ui_interface->declare(&fVslider2, "unit", "s");
		ui_interface->addVerticalSlider("Mid RT60", &fVslider2, FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fVslider3, "4", "");
		ui_interface->declare(&fVslider3, "scale", "log");
		ui_interface->declare(&fVslider3, "style", "knob");
		ui_interface->declare(&fVslider3, "tooltip", "Frequency (Hz) at which the high-frequency T60 is half the middle-band's T60");
		ui_interface->declare(&fVslider3, "unit", "Hz");
		ui_interface->addVerticalSlider("HF Damping", &fVslider3, FAUSTFLOAT(6e+03f), FAUSTFLOAT(1.5e+03f), FAUSTFLOAT(2.352e+04f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("RM Peaking Equalizer 1");
		ui_interface->declare(&fVslider7, "1", "");
		ui_interface->declare(&fVslider7, "scale", "log");
		ui_interface->declare(&fVslider7, "style", "knob");
		ui_interface->declare(&fVslider7, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fVslider7, "unit", "Hz");
		ui_interface->addVerticalSlider("Eq1 Freq", &fVslider7, FAUSTFLOAT(315.0f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(2.5e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider8, "2", "");
		ui_interface->declare(&fVslider8, "style", "knob");
		ui_interface->declare(&fVslider8, "tooltip", "Peak level         in dB of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fVslider8, "unit", "dB");
		ui_interface->addVerticalSlider("Eq1 Level", &fVslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(-15.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "4", "");
		ui_interface->openHorizontalBox("RM Peaking Equalizer 2");
		ui_interface->declare(&fVslider9, "1", "");
		ui_interface->declare(&fVslider9, "scale", "log");
		ui_interface->declare(&fVslider9, "style", "knob");
		ui_interface->declare(&fVslider9, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fVslider9, "unit", "Hz");
		ui_interface->addVerticalSlider("Eq2 Freq", &fVslider9, FAUSTFLOAT(1.5e+03f), FAUSTFLOAT(1.6e+02f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider10, "2", "");
		ui_interface->declare(&fVslider10, "style", "knob");
		ui_interface->declare(&fVslider10, "tooltip", "Peak level         in dB of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fVslider10, "unit", "dB");
		ui_interface->addVerticalSlider("Eq2 Level", &fVslider10, FAUSTFLOAT(0.0f), FAUSTFLOAT(-15.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("Output");
		ui_interface->declare(&fVslider1, "1", "");
		ui_interface->declare(&fVslider1, "style", "knob");
		ui_interface->declare(&fVslider1, "tooltip", "-1 = dry, 1 = wet");
		ui_interface->addVerticalSlider("Dry/Wet Mix", &fVslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider0, "2", "");
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->declare(&fVslider0, "tooltip", "Output scale         factor");
		ui_interface->declare(&fVslider0, "unit", "dB");
		ui_interface->addVerticalSlider("Level", &fVslider0, FAUSTFLOAT(-2e+01f), FAUSTFLOAT(-7e+01f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst1 * std::pow(1e+01f, 0.05f * std::max<float>(-7e+01f, std::min<float>(4e+01f, float(fVslider0))));
		float fSlow1 = fConst1 * std::max<float>(-1.0f, std::min<float>(1.0f, float(fVslider1)));
		float fSlow2 = std::max<float>(1.0f, std::min<float>(8.0f, float(fVslider2)));
		float fSlow3 = std::exp(fConst4 / fSlow2);
		float fSlow4 = _JpRevTest_faustpower2_f(fSlow3);
		float fSlow5 = std::cos(fConst5 * std::max<float>(1.5e+03f, std::min<float>(2.352e+04f, float(fVslider3))));
		float fSlow6 = 1.0f - fSlow4 * fSlow5;
		float fSlow7 = 1.0f - fSlow4;
		float fSlow8 = std::sqrt(std::max<float>(0.0f, _JpRevTest_faustpower2_f(fSlow6) / _JpRevTest_faustpower2_f(fSlow7) + -1.0f));
		float fSlow9 = fSlow6 / fSlow7;
		float fSlow10 = fSlow3 * (fSlow8 + (1.0f - fSlow9));
		float fSlow11 = std::max<float>(1.0f, std::min<float>(8.0f, float(fVslider4)));
		float fSlow12 = std::exp(fConst4 / fSlow11) / fSlow3 + -1.0f;
		float fSlow13 = 1.0f / std::tan(fConst6 * std::max<float>(5e+01f, std::min<float>(1e+03f, float(fVslider5))));
		float fSlow14 = 1.0f / (fSlow13 + 1.0f);
		float fSlow15 = 1.0f - fSlow13;
		float fSlow16 = fSlow9 - fSlow8;
		int iSlow17 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst9 * std::max<float>(2e+01f, std::min<float>(1e+02f, float(fVslider6))))));
		float fSlow18 = std::exp(fConst12 / fSlow2);
		float fSlow19 = _JpRevTest_faustpower2_f(fSlow18);
		float fSlow20 = 1.0f - fSlow5 * fSlow19;
		float fSlow21 = 1.0f - fSlow19;
		float fSlow22 = std::sqrt(std::max<float>(0.0f, _JpRevTest_faustpower2_f(fSlow20) / _JpRevTest_faustpower2_f(fSlow21) + -1.0f));
		float fSlow23 = fSlow20 / fSlow21;
		float fSlow24 = fSlow18 * (fSlow22 + (1.0f - fSlow23));
		float fSlow25 = std::exp(fConst12 / fSlow11) / fSlow18 + -1.0f;
		float fSlow26 = fSlow23 - fSlow22;
		float fSlow27 = std::exp(fConst17 / fSlow2);
		float fSlow28 = _JpRevTest_faustpower2_f(fSlow27);
		float fSlow29 = 1.0f - fSlow5 * fSlow28;
		float fSlow30 = 1.0f - fSlow28;
		float fSlow31 = std::sqrt(std::max<float>(0.0f, _JpRevTest_faustpower2_f(fSlow29) / _JpRevTest_faustpower2_f(fSlow30) + -1.0f));
		float fSlow32 = fSlow29 / fSlow30;
		float fSlow33 = fSlow27 * (fSlow31 + (1.0f - fSlow32));
		float fSlow34 = std::exp(fConst17 / fSlow11) / fSlow27 + -1.0f;
		float fSlow35 = fSlow32 - fSlow31;
		float fSlow36 = std::exp(fConst22 / fSlow2);
		float fSlow37 = _JpRevTest_faustpower2_f(fSlow36);
		float fSlow38 = 1.0f - fSlow5 * fSlow37;
		float fSlow39 = 1.0f - fSlow37;
		float fSlow40 = std::sqrt(std::max<float>(0.0f, _JpRevTest_faustpower2_f(fSlow38) / _JpRevTest_faustpower2_f(fSlow39) + -1.0f));
		float fSlow41 = fSlow38 / fSlow39;
		float fSlow42 = fSlow36 * (fSlow40 + (1.0f - fSlow41));
		float fSlow43 = std::exp(fConst22 / fSlow11) / fSlow36 + -1.0f;
		float fSlow44 = fSlow41 - fSlow40;
		float fSlow45 = std::exp(fConst27 / fSlow2);
		float fSlow46 = _JpRevTest_faustpower2_f(fSlow45);
		float fSlow47 = 1.0f - fSlow5 * fSlow46;
		float fSlow48 = 1.0f - fSlow46;
		float fSlow49 = std::sqrt(std::max<float>(0.0f, _JpRevTest_faustpower2_f(fSlow47) / _JpRevTest_faustpower2_f(fSlow48) + -1.0f));
		float fSlow50 = fSlow47 / fSlow48;
		float fSlow51 = fSlow45 * (fSlow49 + (1.0f - fSlow50));
		float fSlow52 = std::exp(fConst27 / fSlow11) / fSlow45 + -1.0f;
		float fSlow53 = fSlow50 - fSlow49;
		float fSlow54 = std::exp(fConst32 / fSlow2);
		float fSlow55 = _JpRevTest_faustpower2_f(fSlow54);
		float fSlow56 = 1.0f - fSlow5 * fSlow55;
		float fSlow57 = 1.0f - fSlow55;
		float fSlow58 = std::sqrt(std::max<float>(0.0f, _JpRevTest_faustpower2_f(fSlow56) / _JpRevTest_faustpower2_f(fSlow57) + -1.0f));
		float fSlow59 = fSlow56 / fSlow57;
		float fSlow60 = fSlow54 * (fSlow58 + (1.0f - fSlow59));
		float fSlow61 = std::exp(fConst32 / fSlow11) / fSlow54 + -1.0f;
		float fSlow62 = fSlow59 - fSlow58;
		float fSlow63 = std::exp(fConst37 / fSlow2);
		float fSlow64 = _JpRevTest_faustpower2_f(fSlow63);
		float fSlow65 = 1.0f - fSlow5 * fSlow64;
		float fSlow66 = 1.0f - fSlow64;
		float fSlow67 = std::sqrt(std::max<float>(0.0f, _JpRevTest_faustpower2_f(fSlow65) / _JpRevTest_faustpower2_f(fSlow66) + -1.0f));
		float fSlow68 = fSlow65 / fSlow66;
		float fSlow69 = fSlow63 * (fSlow67 + (1.0f - fSlow68));
		float fSlow70 = std::exp(fConst37 / fSlow11) / fSlow63 + -1.0f;
		float fSlow71 = fSlow68 - fSlow67;
		float fSlow72 = std::exp(fConst42 / fSlow2);
		float fSlow73 = _JpRevTest_faustpower2_f(fSlow72);
		float fSlow74 = 1.0f - fSlow5 * fSlow73;
		float fSlow75 = 1.0f - fSlow73;
		float fSlow76 = std::sqrt(std::max<float>(0.0f, _JpRevTest_faustpower2_f(fSlow74) / _JpRevTest_faustpower2_f(fSlow75) + -1.0f));
		float fSlow77 = fSlow74 / fSlow75;
		float fSlow78 = fSlow72 * (fSlow76 + (1.0f - fSlow77));
		float fSlow79 = std::exp(fConst42 / fSlow11) / fSlow72 + -1.0f;
		float fSlow80 = fSlow77 - fSlow76;
		float fSlow81 = std::max<float>(4e+01f, std::min<float>(2.5e+03f, float(fVslider7)));
		float fSlow82 = std::pow(1e+01f, 0.05f * std::max<float>(-15.0f, std::min<float>(15.0f, float(fVslider8))));
		float fSlow83 = fConst5 * (fSlow81 / std::sqrt(std::max<float>(0.0f, fSlow82)));
		float fSlow84 = (1.0f - fSlow83) / (fSlow83 + 1.0f);
		float fSlow85 = 0.0f - std::cos(fConst5 * fSlow81) * (fSlow84 + 1.0f);
		float fSlow86 = std::max<float>(1.6e+02f, std::min<float>(1e+04f, float(fVslider9)));
		float fSlow87 = std::pow(1e+01f, 0.05f * std::max<float>(-15.0f, std::min<float>(15.0f, float(fVslider10))));
		float fSlow88 = fConst5 * (fSlow86 / std::sqrt(std::max<float>(0.0f, fSlow87)));
		float fSlow89 = (1.0f - fSlow88) / (fSlow88 + 1.0f);
		float fSlow90 = 0.0f - std::cos(fConst5 * fSlow86) * (fSlow89 + 1.0f);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = float(input0[i0]);
			fVec0[IOTA0 & 16383] = fTemp0;
			fRec1[0] = fSlow1 + fConst2 * fRec1[1];
			float fTemp1 = fRec1[0] + 1.0f;
			float fTemp2 = 1.0f - 0.5f * fTemp1;
			fRec14[0] = 0.0f - fSlow14 * (fSlow15 * fRec14[1] - (fRec3[1] + fRec3[2]));
			fRec13[0] = fSlow10 * (fRec3[1] + fSlow12 * fRec14[0]) + fSlow16 * fRec13[1];
			fVec1[IOTA0 & 16383] = 0.35355338f * fRec13[0] + 1e-20f;
			float fTemp3 = 0.3f * fVec0[(IOTA0 - iSlow17) & 16383];
			float fTemp4 = fVec1[(IOTA0 - iConst8) & 16383] + fTemp3 - 0.6f * fRec11[1];
			fVec2[IOTA0 & 2047] = fTemp4;
			fRec11[0] = fVec2[(IOTA0 - iConst10) & 2047];
			float fRec12 = 0.6f * fTemp4;
			fRec18[0] = fSlow14 * (fRec6[1] + fRec6[2] - fSlow15 * fRec18[1]);
			fRec17[0] = fSlow24 * (fRec6[1] + fSlow25 * fRec18[0]) + fSlow26 * fRec17[1];
			fVec3[IOTA0 & 32767] = 0.35355338f * fRec17[0] + 1e-20f;
			float fTemp5 = float(input1[i0]);
			fVec4[IOTA0 & 16383] = fTemp5;
			float fTemp6 = 0.3f * fVec4[(IOTA0 - iSlow17) & 16383];
			float fTemp7 = 0.6f * fRec15[1] + fVec3[(IOTA0 - iConst14) & 32767] - fTemp6;
			fVec5[IOTA0 & 4095] = fTemp7;
			fRec15[0] = fVec5[(IOTA0 - iConst15) & 4095];
			float fRec16 = 0.0f - 0.6f * fTemp7;
			fRec22[0] = 0.0f - fSlow14 * (fSlow15 * fRec22[1] - (fRec8[1] + fRec8[2]));
			fRec21[0] = fSlow33 * (fRec8[1] + fSlow34 * fRec22[0]) + fSlow35 * fRec21[1];
			fVec6[IOTA0 & 16383] = 0.35355338f * fRec21[0] + 1e-20f;
			float fTemp8 = fVec6[(IOTA0 - iConst19) & 16383] + fTemp6 + 0.6f * fRec19[1];
			fVec7[IOTA0 & 4095] = fTemp8;
			fRec19[0] = fVec7[(IOTA0 - iConst20) & 4095];
			float fRec20 = 0.0f - 0.6f * fTemp8;
			fRec26[0] = 0.0f - fSlow14 * (fSlow15 * fRec26[1] - (fRec10[1] + fRec10[2]));
			fRec25[0] = fSlow42 * (fRec10[1] + fSlow43 * fRec26[0]) + fSlow44 * fRec25[1];
			fVec8[IOTA0 & 32767] = 0.35355338f * fRec25[0] + 1e-20f;
			float fTemp9 = 0.6f * fRec23[1] + fVec8[(IOTA0 - iConst24) & 32767] - fTemp6;
			fVec9[IOTA0 & 2047] = fTemp9;
			fRec23[0] = fVec9[(IOTA0 - iConst25) & 2047];
			float fRec24 = 0.0f - 0.6f * fTemp9;
			fRec30[0] = 0.0f - fSlow14 * (fSlow15 * fRec30[1] - (fRec5[1] + fRec5[2]));
			fRec29[0] = fSlow51 * (fRec5[1] + fSlow52 * fRec30[0]) + fSlow53 * fRec29[1];
			fVec10[IOTA0 & 16383] = 0.35355338f * fRec29[0] + 1e-20f;
			float fTemp10 = fVec10[(IOTA0 - iConst29) & 16383] - (fTemp3 + 0.6f * fRec27[1]);
			fVec11[IOTA0 & 4095] = fTemp10;
			fRec27[0] = fVec11[(IOTA0 - iConst30) & 4095];
			float fRec28 = 0.6f * fTemp10;
			fRec34[0] = 0.0f - fSlow14 * (fSlow15 * fRec34[1] - (fRec9[1] + fRec9[2]));
			fRec33[0] = fSlow60 * (fRec9[1] + fSlow61 * fRec34[0]) + fSlow62 * fRec33[1];
			fVec12[IOTA0 & 16383] = 0.35355338f * fRec33[0] + 1e-20f;
			float fTemp11 = fVec12[(IOTA0 - iConst34) & 16383] - (fTemp3 + 0.6f * fRec31[1]);
			fVec13[IOTA0 & 2047] = fTemp11;
			fRec31[0] = fVec13[(IOTA0 - iConst35) & 2047];
			float fRec32 = 0.6f * fTemp11;
			fRec38[0] = 0.0f - fSlow14 * (fSlow15 * fRec38[1] - (fRec4[1] + fRec4[2]));
			fRec37[0] = fSlow69 * (fRec4[1] + fSlow70 * fRec38[0]) + fSlow71 * fRec37[1];
			fVec14[IOTA0 & 32767] = 0.35355338f * fRec37[0] + 1e-20f;
			float fTemp12 = 0.6f * fRec35[1] + fVec14[(IOTA0 - iConst39) & 32767] + fTemp6;
			fVec15[IOTA0 & 4095] = fTemp12;
			fRec35[0] = fVec15[(IOTA0 - iConst40) & 4095];
			float fRec36 = 0.0f - 0.6f * fTemp12;
			fRec42[0] = 0.0f - fSlow14 * (fSlow15 * fRec42[1] - (fRec7[1] + fRec7[2]));
			fRec41[0] = fSlow78 * (fRec7[1] + fSlow79 * fRec42[0]) + fSlow80 * fRec41[1];
			fVec16[IOTA0 & 16383] = 0.35355338f * fRec41[0] + 1e-20f;
			float fTemp13 = fTemp3 + fVec16[(IOTA0 - iConst44) & 16383] - 0.6f * fRec39[1];
			fVec17[IOTA0 & 4095] = fTemp13;
			fRec39[0] = fVec17[(IOTA0 - iConst45) & 4095];
			float fRec40 = 0.6f * fTemp13;
			float fTemp14 = fRec40 + fRec28;
			float fTemp15 = fRec32 + fTemp14;
			fRec3[0] = fRec12 + fRec16 + fRec20 + fRec24 + fRec15[1] + fRec23[1] + fRec27[1] + fRec31[1] + fRec35[1] + fRec19[1] + fRec11[1] + fRec39[1] + fRec36 + fTemp15;
			fRec4[0] = fRec12 + fRec27[1] + fRec31[1] + fRec11[1] + fRec39[1] + fTemp15 - (fRec16 + fRec20 + fRec24 + fRec15[1] + fRec35[1] + fRec36 + fRec19[1] + fRec23[1]);
			float fTemp16 = fRec28 + fRec32;
			fRec5[0] = fRec12 + fRec20 + fRec35[1] + fRec19[1] + fRec11[1] + fRec39[1] + fRec40 + fRec36 - (fRec16 + fRec24 + fRec15[1] + fRec27[1] + fRec31[1] + fTemp16 + fRec23[1]);
			fRec6[0] = fRec12 + fRec16 + fRec24 + fRec15[1] + fRec11[1] + fRec40 + fRec39[1] + fRec23[1] - (fRec20 + fRec27[1] + fRec31[1] + fRec35[1] + fRec19[1] + fRec36 + fTemp16);
			float fTemp17 = fRec40 + fRec32;
			fRec7[0] = fRec12 + fRec16 + fRec15[1] + fRec27[1] + fRec35[1] + fRec11[1] + fRec28 + fRec36 - (fRec20 + fRec24 + fRec23[1] + fRec31[1] + fRec19[1] + fRec39[1] + fTemp17);
			fRec8[0] = fRec12 + fRec20 + fRec24 + fRec23[1] + fRec27[1] + fRec19[1] + fRec28 + fRec11[1] - (fRec16 + fRec15[1] + fRec31[1] + fRec35[1] + fRec39[1] + fRec36 + fTemp17);
			fRec9[0] = fRec12 + fRec24 + fRec23[1] + fRec31[1] + fRec35[1] + fRec11[1] + fRec32 + fRec36 - (fRec16 + fRec20 + fRec15[1] + fRec27[1] + fRec19[1] + fRec39[1] + fTemp14);
			fRec10[0] = fRec12 + fRec16 + fRec20 + fRec15[1] + fRec31[1] + fRec19[1] + fRec32 + fRec11[1] - (fRec24 + fRec23[1] + fRec27[1] + fRec35[1] + fRec39[1] + fRec36 + fTemp14);
			float fTemp18 = 0.37f * (fRec4[0] + fRec5[0]);
			float fTemp19 = fSlow85 * fRec2[1];
			fRec2[0] = fTemp18 - (fTemp19 + fSlow84 * fRec2[2]);
			float fTemp20 = fSlow84 * fRec2[0];
			float fTemp21 = 0.5f * (fRec2[2] + fTemp19 + fTemp18 + fTemp20 + fSlow82 * (fRec2[2] + fTemp19 + fTemp20 - fTemp18));
			float fTemp22 = fSlow90 * fRec43[1];
			fRec43[0] = fTemp21 - (fTemp22 + fSlow89 * fRec43[2]);
			float fTemp23 = fSlow89 * fRec43[0] + fTemp22 + fRec43[2];
			output0[i0] = FAUSTFLOAT(0.5f * fRec0[0] * (fTemp0 * fTemp1 + fTemp2 * (fTemp21 + fTemp23 + fSlow87 * (fTemp23 - fTemp21))));
			float fTemp24 = 0.37f * (fRec4[0] - fRec5[0]);
			float fTemp25 = fSlow85 * fRec45[1];
			fRec45[0] = fTemp24 - (fTemp25 + fSlow84 * fRec45[2]);
			float fTemp26 = fSlow84 * fRec45[0];
			float fTemp27 = 0.5f * (fTemp26 + fRec45[2] + fTemp24 + fTemp25 + fSlow82 * (fTemp26 + fTemp25 + fRec45[2] - fTemp24));
			float fTemp28 = fSlow90 * fRec44[1];
			fRec44[0] = fTemp27 - (fTemp28 + fSlow89 * fRec44[2]);
			float fTemp29 = fSlow89 * fRec44[0];
			output1[i0] = FAUSTFLOAT(0.5f * fRec0[0] * (fTemp5 * fTemp1 + fTemp2 * (fTemp29 + fRec44[2] + fTemp27 + fTemp28 + fSlow87 * (fTemp29 + fTemp28 + fRec44[2] - fTemp27))));
			fRec0[1] = fRec0[0];
			IOTA0 = IOTA0 + 1;
			fRec1[1] = fRec1[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fRec11[1] = fRec11[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec15[1] = fRec15[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec19[1] = fRec19[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec23[1] = fRec23[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec27[1] = fRec27[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec31[1] = fRec31[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec35[1] = fRec35[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec39[1] = fRec39[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "JpRevTest.dsp"
	#define FAUST_CLASS_NAME "_JpRevTest"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -cn _JpRevTest -scn ::faust::dsp -es 1 -mcd 16 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 11
	#define FAUST_PASSIVES 0

	FAUST_ADDVERTICALSLIDER("[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[1] Input/In Delay", fVslider6, 6e+01f, 2e+01f, 1e+02f, 1.0f);
	FAUST_ADDVERTICALSLIDER("[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[2] Decay Times in Bands (see tooltips)/LF X", fVslider5, 2e+02f, 5e+01f, 1e+03f, 1.0f);
	FAUST_ADDVERTICALSLIDER("[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[2] Decay Times in Bands (see tooltips)/Low RT60", fVslider4, 3.0f, 1.0f, 8.0f, 0.1f);
	FAUST_ADDVERTICALSLIDER("[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[2] Decay Times in Bands (see tooltips)/Mid RT60", fVslider2, 2.0f, 1.0f, 8.0f, 0.1f);
	FAUST_ADDVERTICALSLIDER("[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[2] Decay Times in Bands (see tooltips)/HF Damping", fVslider3, 6e+03f, 1.5e+03f, 2.352e+04f, 1.0f);
	FAUST_ADDVERTICALSLIDER("[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[3] RM Peaking Equalizer 1/Eq1 Freq", fVslider7, 315.0f, 4e+01f, 2.5e+03f, 1.0f);
	FAUST_ADDVERTICALSLIDER("[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[3] RM Peaking Equalizer 1/Eq1 Level", fVslider8, 0.0f, -15.0f, 15.0f, 0.1f);
	FAUST_ADDVERTICALSLIDER("[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[4] RM Peaking Equalizer 2/Eq2 Freq", fVslider9, 1.5e+03f, 1.6e+02f, 1e+04f, 1.0f);
	FAUST_ADDVERTICALSLIDER("[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[4] RM Peaking Equalizer 2/Eq2 Level", fVslider10, 0.0f, -15.0f, 15.0f, 0.1f);
	FAUST_ADDVERTICALSLIDER("[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[5] Output/Dry/Wet Mix", fVslider1, 0.0f, -1.0f, 1.0f, 0.01f);
	FAUST_ADDVERTICALSLIDER("[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[5] Output/Level", fVslider0, -2e+01f, -7e+01f, 4e+01f, 0.1f);

	#define FAUST_LIST_ACTIVES(p) \
		p(VERTICALSLIDER, In_Delay, "[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[1] Input/In Delay", fVslider6, 6e+01f, 2e+01f, 1e+02f, 1.0f) \
		p(VERTICALSLIDER, LF_X, "[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[2] Decay Times in Bands (see tooltips)/LF X", fVslider5, 2e+02f, 5e+01f, 1e+03f, 1.0f) \
		p(VERTICALSLIDER, Low_RT60, "[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[2] Decay Times in Bands (see tooltips)/Low RT60", fVslider4, 3.0f, 1.0f, 8.0f, 0.1f) \
		p(VERTICALSLIDER, Mid_RT60, "[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[2] Decay Times in Bands (see tooltips)/Mid RT60", fVslider2, 2.0f, 1.0f, 8.0f, 0.1f) \
		p(VERTICALSLIDER, HF_Damping, "[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[2] Decay Times in Bands (see tooltips)/HF Damping", fVslider3, 6e+03f, 1.5e+03f, 2.352e+04f, 1.0f) \
		p(VERTICALSLIDER, Eq1_Freq, "[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[3] RM Peaking Equalizer 1/Eq1 Freq", fVslider7, 315.0f, 4e+01f, 2.5e+03f, 1.0f) \
		p(VERTICALSLIDER, Eq1_Level, "[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[3] RM Peaking Equalizer 1/Eq1 Level", fVslider8, 0.0f, -15.0f, 15.0f, 0.1f) \
		p(VERTICALSLIDER, Eq2_Freq, "[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[4] RM Peaking Equalizer 2/Eq2 Freq", fVslider9, 1.5e+03f, 1.6e+02f, 1e+04f, 1.0f) \
		p(VERTICALSLIDER, Eq2_Level, "[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[4] RM Peaking Equalizer 2/Eq2 Level", fVslider10, 0.0f, -15.0f, 15.0f, 0.1f) \
		p(VERTICALSLIDER, Dry/Wet_Mix, "[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[5] Output/Dry/Wet Mix", fVslider1, 0.0f, -1.0f, 1.0f, 0.01f) \
		p(VERTICALSLIDER, Level, "[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references]/[5] Output/Level", fVslider0, -2e+01f, -7e+01f, 4e+01f, 0.1f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
