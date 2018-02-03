#pragma once

namespace gsynth
{
	// Source for constexpr power functions: https://stackoverflow.com/questions/17719674/c11-fast-constexpr-integer-powers

	template<typename T>
	constexpr T ipow_(T base, unsigned int exp) 
	{
		return exp > 1 ? ipow_(base, (exp >> 1) + (exp & 1)) * ipow_(base, exp >> 1) : base;
	}

	template<typename T>
	constexpr T ipow(T base, unsigned int exp) 
	{
		return exp < 1 ? 1 : ipow_(base, exp);
	}

	template<typename T>
	constexpr T ipow(T base, int exp)
	{
		static_assert(std::is_floating_point<T>::value, "base is required to be of floating point type");
#pragma warning(suppress: 26472)
		return exp < 0 ? rcp(ipow(base, static_cast<unsigned int>(-exp))) : ipow(base, static_cast<unsigned int>(exp));
	}

	template<typename T>
	constexpr T rcp(T x)
	{
		static_assert(std::is_floating_point<T>::value, "x is required to be of floating point type");
		return 1.0 / x;
	}
}