// (c) 2019 Takamitsu Endo
//
// This file is part of SevenDelay.
//
// SevenDelay is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SevenDelay is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SevenDelay.  If not, see <https://www.gnu.org/licenses/>.

#include "pluginterfaces/vst/vsttypes.h"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <cmath>

#include "parameter.hpp"

namespace Steinberg {
namespace SevenDelay {

LogScale<Vst::ParamValue> GlobalParameter::scaleTime(0.0001, maxDelayTime, 0.5, 1.0);
SPolyScale<Vst::ParamValue> GlobalParameter::scaleOffset(-1.0, 1.0, 0.8);
LogScale<Vst::ParamValue> GlobalParameter::scaleLfoAmount(0, 1.0, 0.5, 0.1);
LogScale<Vst::ParamValue> GlobalParameter::scaleLfoFrequency(0.01, 100.0, 0.5, 1.0);
LogScale<Vst::ParamValue> GlobalParameter::scaleLfoShape(0.01, 10.0, 0.5, 1.0);
LinearScale<Vst::ParamValue> GlobalParameter::scaleLfoInitialPhase(0.0, 2.0 * M_PI);
LogScale<Vst::ParamValue> GlobalParameter::scaleSmoothness(0.0, 1.0, 0.3, 0.04);
LogScale<Vst::ParamValue> GlobalParameter::scaleTone(90.0, maxToneFrequency, 0.5, 1000.0);
LogScale<Vst::ParamValue> GlobalParameter::scaleToneMix(0.0, 1.0, 0.9, 0.05);

} // namespace SevenDelay
} // namespace Steinberg