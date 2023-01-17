#pragma once

#include <JuceHeader.h>
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace JPVERBTEST_impl
{
// =========================| Node & Parameter type declarations |=========================

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

using xfader_c0 = parameter::from0To1<core::gain, 
                                      0, 
                                      xfader_c0Range>;

DECLARE_PARAMETER_RANGE_SKEW(xfader_c1Range, 
                             -100., 
                             -4.5, 
                             5.42227);

using xfader_c1 = parameter::from0To1<core::gain, 
                                      0, 
                                      xfader_c1Range>;

using xfader_multimod = parameter::list<xfader_c0, xfader_c1>;

using xfader_t = control::xfader<xfader_multimod, faders::rms>;

using DRY_t = container::chain<parameter::empty, 
                               wrap::fix<2, core::gain>>;

template <int NV>
using WET_t = container::chain<parameter::empty, 
                               wrap::fix<2, core::gain>, 
                               project::JpRevTest<NV>, 
                               core::gain, 
                               core::fix_delay>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, DRY_t>, 
                                 WET_t<NV>>;

namespace JPVERBTEST_t_parameters
{
// Parameter list for JPVERBTEST_impl::JPVERBTEST_t ---------------------------------------

DECLARE_PARAMETER_RANGE_STEP(SpaceRange, 
                             0., 
                             1, 
                             0.01);

template <int NV>
using Space = parameter::from0To1<project::JpRevTest<NV>, 
                                  9, 
                                  SpaceRange>;

DECLARE_PARAMETER_RANGE_STEP(FeedbackRange, 
                             1, 
                             1000., 
                             0.1);

template <int NV>
using Feedback = parameter::from0To1<project::JpRevTest<NV>, 
                                     3, 
                                     FeedbackRange>;

using VerbGate = parameter::from0To1<core::gain, 
                                     0, 
                                     JPVERBTEST_impl::xfader_c0Range>;

DECLARE_PARAMETER_RANGE(DelayTime_InputRange, 
                        0., 
                        1000.);
DECLARE_PARAMETER_RANGE_SKEW(DelayTime_0Range, 
                             0., 
                             1000., 
                             0.30103);

using DelayTime_0 = parameter::from0To1<core::fix_delay, 
                                        0, 
                                        DelayTime_0Range>;

using DelayTime = parameter::chain<DelayTime_InputRange, DelayTime_0>;

using Blend = parameter::plain<JPVERBTEST_impl::xfader_t, 
                               0>;
template <int NV>
using JPVERBTEST_t_plist = parameter::list<Blend, 
                                           Space<NV>, 
                                           Feedback<NV>, 
                                           VerbGate, 
                                           DelayTime>;
}

template <int NV>
using JPVERBTEST_t_ = container::chain<JPVERBTEST_t_parameters::JPVERBTEST_t_plist<NV>, 
                                       wrap::fix<2, xfader_t>, 
                                       split_t<NV>>;

// =============================| Root node initialiser class |=============================

template <int NV> struct instance: public JPVERBTEST_impl::JPVERBTEST_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(JPVERBTEST);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(84)
		{
			0x005B, 0x0000, 0x4200, 0x656C, 0x646E, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x7D3F, 0x00D2, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x7053, 0x6361, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x4600, 0x6565, 0x6264, 0x6361, 0x006B, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x035B, 0x0000, 0x5600, 0x7265, 0x4762, 0x7461, 0x0065, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x045B, 0x0000, 0x4400, 0x6C65, 0x7961, 0x6954, 0x656D, 
            0x0000, 0x0000, 0x0000, 0x7A00, 0x0044, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References ----------------------------------------------------------------
		
		auto& xfader = this->getT(0);                    // JPVERBTEST_impl::xfader_t
		auto& split = this->getT(1);                     // JPVERBTEST_impl::split_t<NV>
		auto& DRY = this->getT(1).getT(0);               // JPVERBTEST_impl::DRY_t
		auto& gain = this->getT(1).getT(0).getT(0);      // core::gain
		auto& WET = this->getT(1).getT(1);               // JPVERBTEST_impl::WET_t<NV>
		auto& Gate = this->getT(1).getT(1).getT(0);      // core::gain
		auto& faust = this->getT(1).getT(1).getT(1);     // project::JpRevTest<NV>
		auto& gainWet = this->getT(1).getT(1).getT(2);   // core::gain
		auto& fix_delay = this->getT(1).getT(1).getT(3); // core::fix_delay
		
		// Parameter Connections ----------------------------------------------------------
		
		this->getParameterT(0).connectT(0, xfader); // Blend -> xfader::Value
		
		this->getParameterT(1).connectT(0, faust); // Space -> faust::DryWetMix
		
		this->getParameterT(2).connectT(0, faust); // Feedback -> faust::MidRT60
		
		this->getParameterT(3).connectT(0, Gate); // VerbGate -> Gate::Gain
		
		this->getParameterT(4).connectT(0, fix_delay); // DelayTime -> fix_delay::DelayTime
		
		// Modulation Connections ---------------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);    // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gainWet); // xfader -> gainWet::Gain
		
		// Default Values -----------------------------------------------------------------
		
		; // xfader::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                           // Gate::Gain is automated
		Gate.setParameterT(1, 20.); // core::gain::Smoothing
		Gate.setParameterT(2, 0.);  // core::gain::ResetValue
		
		faust.setParameterT(0, 20.);   // core::faust::InDelay
		faust.setParameterT(1, 175.);  // core::faust::LFX
		faust.setParameterT(2, 2.1);   // core::faust::LowRT60
		;                              // faust::MidRT60 is automated
		faust.setParameterT(4, 9474.); // core::faust::HFDamping
		faust.setParameterT(5, 315.);  // core::faust::Eq1Freq
		faust.setParameterT(6, 0.);    // core::faust::Eq1Level
		faust.setParameterT(7, 1500.); // core::faust::Eq2Freq
		faust.setParameterT(8, 0.);    // core::faust::Eq2Level
		;                              // faust::DryWetMix is automated
		faust.setParameterT(10, 7.2);  // core::faust::Level
		
		;                              // gainWet::Gain is automated
		gainWet.setParameterT(1, 20.); // core::gain::Smoothing
		gainWet.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                 // fix_delay::DelayTime is automated
		fix_delay.setParameterT(1, 512.); // core::fix_delay::FadeTime
		
		this->setParameterT(0, 0.503212);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ==================================| Public Definition |==================================

namespace project
{
// polyphonic template declaration

template <int NV>
using JPVERBTEST = wrap::node<JPVERBTEST_impl::instance<NV>>;
}


