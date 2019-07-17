#include "Calc.h"

namespace Calc {

	void SwapFloatValue(
		float& value_1,
		float& value_2
	){
		float temp = value_1;
		value_1 = value_2;
		value_2 = temp;
	}

	float PowFloat(float value) {
		return value * value;
	}
}